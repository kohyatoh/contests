%   Copyright (c) 2012, Kohsuke Yatoh
%   All rights reserved.
%
%   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
%
%   Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
%   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
%
%   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

% music data
music_a("-3:4:,-2:4:,-1:4:,0:4:b,-1:4:,-2:4:,-3:4:,:4:,-1:4:,0:4:b,1:4:,2:4:,1:4:,0:4:b,-1:4:,:4:").
music_b("3:4:,2:4:,1:4:,0:4:b,1:4:,2:4:,3:4:,:4:,1:4:,0:4:b,-1:4:,-2:4:,-1:4:,0:4:b,1:4:,:4:").
music_c("3:4:,2:4:,1:4:,0:4:,1:4:,2:4:,3:4:,:4:,1:8:,0:4.:,-1:4:,-2:4:,:8:,-1:4.:,0:8:,1:8:").
music_d("-6:8:,-6:8:,-6:8:,-4:8:,-2:8:,-2:8:,-2:8:,:8:,-5:8:,-5:8:,-5:8:,-3:8:,-2:8:,-2:8:,-2:8:,:8:,:8:,-2:8:,-2:8:,-1:8:b,-1:8:,-1:8:,-1:8:,-1:8:b,-2:4:,0:4:,1:4:,:4:").
music_e("-6:8.:,-7:16:,-6:8:,-5:8:,-4:8:,-4:8:,-4:4:,-3:8.:,-4:16:,-5:8:,-6:8:,-5:4:,:4:,-3:8:,-5:4:,-5:8:,-4:8:,-4:8:,-3:8:,-3:8:,-4:8:,-4:8:,-5:8:,-5:8:,-6:4:,:4:").
music_f("-6:2:,-5:4:,-6:8:,-5:8:,-4:4:,-2:4:,-4:4:,:4:,-5:4:,-5:4:,-6:4:,-5:4:,-4:2.:,:4:").
music_g("-2:8.:,-1:16:,-2:8.:,-1:16:,-2:4:,-4:4:,-4:8.:,-3:16:,-4:8.:,-3:16:,-4:4:,-6:4:,-4:8:,:8:,-6:8.:,-5:16:,-4:8:,:8:,-6:8.:,-5:16:,-4:8.:,-4:16:,-2:8.:,-2:16:,-5:8.:,-4:16:,-5:4:").

% basic note length
note_length(1).
note_length(2).
note_length(4).
note_length(8).
note_length(16).
note_length(32).

% pitch to note conversion table (example: 4 -> 2:*:s)
pitch_to_note(0, 0, "").
pitch_to_note(1, 1, "").
pitch_to_note(2, 1, "s").
pitch_to_note(3, 2, "").
pitch_to_note(4, 2, "s").
pitch_to_note(5, 3, "").
pitch_to_note(6, 4, "").
pitch_to_note(7, 4, "s").
pitch_to_note(8, 5, "").
pitch_to_note(9, 5, "s").
pitch_to_note(10, 6, "").
pitch_to_note(11, 6, "s").

% parsing
notes([N|X]) --> note(N), ",", notes(X).
notes([X]) --> note(X).

note([H,L]) --> pitch(P), ":", len(L), ":", accidental(M), {H is P+M}.
note([-,L]) --> ":", len(L), ":".

% add bias to make pitch positive
pitch(X) --> num(H), {fix_pitch(H+70, X)}.
fix_pitch(X, Y) :- fix_pitch_sub(X mod 7, Z), Y is Z + floor(X/7)*12.
fix_pitch_sub(X, Y) :- at(X, [0,1,3,5,6,8,10], Y). 

len(L) --> digits(X), {name(N, X), L is 1 / N}.
len(L) --> digits(X), ".", {name(N, X), L is 1 / N + 0.5 / N}.

accidental(X) --> "", {X is 0}.
accidental(X) --> "s", {X is 1}.
accidental(X) --> "x", {X is 2}.
accidental(X) --> "b", {X is -1}.
accidental(X) --> "d", {X is -2}.

num(X) --> digits(S), {name(X, S)}.
num(X) --> "-", digits(S), {name(Y, S), X is -Y}.

digits([C], [C|I], I) :- is_digit(C).
digits([C|R], [C|I], O) :- is_digit(C), digits(R, I, O).
is_digit(C) --> member(C, "0123456789").

% utilty, list 'at' function
at(I, [_|Y], X) :- at(I-1, Y, X).
at(I, [X|_], X) :- I =:= 0.

% feature value
% use floor('sum of absolute differences of neiboring pitches' / 2)
feature_value(XS, V) :-
    pitches(XS, PS),
    differences(PS, S),
    V is floor(S / 2).
differences([], 0).
differences([P], 0).
differences([P,Q|PS], S) :- differences([Q|PS], T), abs(P-Q, D), S is T + D.

% notes to pitches, removing 'rest' notes
pitches([], []).
pitches([[-,_]|XS], PS) :- pitches(XS, PS).
pitches([[P,_]|XS], [P|PS]) :- number(P), pitches(XS, PS).

% composer, generate a melody of mountain.
compose(P, V, MIN_L, MAX_L, XS) :-
    compose_pitches(P, V, TS, []),
    length(TS, K),
    note_length(L),
    MIN_L < K / L,
    K / L =< MAX_L,
    zip(TS, L, XS).
compose_pitches(P, 0, [P,P|XS], XS).
compose_pitches(P, V, [P|XS], YS) :-
    W is V - 1,
    K is P + 1,
    compose_pitches(K, W, XS, [P|YS]).
zip([], _, []).
zip([X|XS], L, [[X,L]|YS]) :- zip(XS, L, YS).

% encoder, encode notes to string (not to atom)
encode([], []).
encode([[P,L]|XS], [[H,L,M]|YS]) :-
    P_ is P mod 12,
    pitch_to_note(P_, K, M),
    H is K + floor(P/12)*7 - 70, % subtract bias
    encode(XS, YS).
map_tostring([], "").
map_tostring([X|XS], [S|YS]) :-
    tostring(X, S),
    map_tostring(XS, YS).
tostring([H,L,M], S) :-
    name(H, S1),
    name(L, S2),
    append(":", M, S3),
    append(S2, S3, S4),
    append(":", S4, S5),
    append(S1, S5, S).
sep([], _, XS, XS).
sep([S], _, RS, XS) :- append(S, XS, RS).
sep([S,T|SS], C, RS, XS) :-
    sep([T|SS], C, R, XS),
    append(C, R, RR),
    append(S, RR, RS).

% main program (questions)
feature_a(X) :- music_a(Z), notes(N, Z, []), feature_value(N, X).
feature_b(X) :- music_b(Z), notes(N, Z, []), feature_value(N, X).
feature_c(X) :- music_c(Z), notes(N, Z, []), feature_value(N, X).
feature_d(X) :- music_d(Z), notes(N, Z, []), feature_value(N, X).
feature_e(X) :- music_e(Z), notes(N, Z, []), feature_value(N, X).
feature_f(X) :- music_f(Z), notes(N, Z, []), feature_value(N, X).
feature_g(X) :- music_g(Z), notes(N, Z, []), feature_value(N, X).
a_alike_b :- feature_a(X), feature_b(X).
a_alike_c :- feature_a(X), feature_c(X).
b_alike_d :- feature_b(X), feature_d(X).
b_alike_e :- feature_b(X), feature_e(X).
b_alike_f :- feature_b(X), feature_f(X).
alike_g(S) :-
    feature_g(V), % the feature value of G
    pitch(P, "-2", []), % "-2"'s pitch
    compose(P, V, 3, 4, M), % compose melody
    feature_value(M, V), % check feture value
    encode(M, XS), % encode melody to notes
    map_tostring(XS, SS), sep(SS, ",", S, []). % notes to string
