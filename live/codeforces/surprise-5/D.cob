       IDENTIFICATION DIVISION.
       PROGRAM-ID. SOLUTION.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 Y        PIC 9(10)   VALUE ZEROES.
       01 M        PIC 9(10)   VALUE ZEROES.
       01 D        PIC 9(10)   VALUE ZEROES.
       01 T        PIC S9(10)   VALUE ZEROES.
       01 R        PIC 9(10)   VALUE ZEROES.
       01 I        PIC 9(10)   VALUE ZEROES.
       01 F        PIC 9(10)   VALUE ZEROES.
       01 S        PIC 9(10)   VALUE ZEROES.
       01 P        PIC 9(10)   VALUE ZEROES.
       01 Yx       PIC 9(4)   VALUE ZEROES.
       01 Mx       PIC 9(2)   VALUE ZEROES.
       01 Dx       PIC 9(2)   VALUE ZEROES.
       01 MT.
        03 MO       PIC S9(10)   OCCURS 12 VALUE ZEROES.
       01 STR      PIC X(10).
       01 BUF      PIC X(10).
       01 DAT      PIC X(30).

       PROCEDURE DIVISION.
         ACCEPT BUF
         MOVE 31 TO MO(1)
         MOVE 28 TO MO(2)
         MOVE 31 TO MO(3)
         MOVE 30 TO MO(4)
         MOVE 31 TO MO(5)
         MOVE 30 TO MO(6)
         MOVE 31 TO MO(7)
         MOVE 31 TO MO(8)
         MOVE 30 TO MO(9)
         MOVE 31 TO MO(10)
         MOVE 30 TO MO(11)
         MOVE 31 TO MO(12)
         MOVE BUF(1:2) TO D
         MOVE BUF(4:2) TO M
         MOVE BUF(7:4) TO Y
         ACCEPT BUF
         MOVE BUF TO T
         COMPUTE T = T + (Y - 1) * 365
         COMPUTE T = T + (Y - 1) / 4
         COMPUTE T = T + D - 1
         COMPUTE M = M - 1
         COMPUTE I = 0
         DIVIDE Y BY 4 GIVING Y REMAINDER R
         PERFORM UNTIL I >= M
            COMPUTE I = I + 1
            COMPUTE T = T + MO(I)
            IF I = 2 AND R = 0 THEN
                COMPUTE T = T + 1
            END-IF
         END-PERFORM
         COMPUTE F = 0
         COMPUTE Y = 1950
         PERFORM UNTIL F = 1
            COMPUTE Y = Y + 1
            COMPUTE R = Y * 365 + Y / 4
            IF R > T THEN
                COMPUTE R = (Y - 1) * 365 + (Y - 1) / 4
                COMPUTE T = T - R
                COMPUTE F = 1
            END-IF
         END-PERFORM
         COMPUTE F = 0
         COMPUTE M = 0
         COMPUTE R = 0
         COMPUTE P = 0
         DIVIDE Y BY 4 GIVING S REMAINDER R
         COMPUTE S = 0
         PERFORM UNTIL F = 1
            COMPUTE M = M + 1
            COMPUTE P = S
            COMPUTE S = S + MO(M)
            IF M = 2 AND R = 0 THEN
                COMPUTE S = S + 1
            END-IF
            IF S > T THEN
                COMPUTE T = T - P + 1
                COMPUTE F = 1
            END-IF
         END-PERFORM
         MOVE Y TO Yx
         MOVE M TO Mx
         MOVE T TO Dx
         DISPLAY Dx "." Mx "." Yx
         STOP RUN.
