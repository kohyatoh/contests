/*
Copyright (c) 2012, Kohsuke Yatoh
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
  * returns the time of the day in 24 hours,
  * provided that you born on y/m/d and live until y+n/m/d.
  */
function time_of_life(y, m, d, n, day) {
    var a = new Date(y, m-1, d),
        b = new Date(y+n, m-1, d),
        c = new Date(day),
        frac = (c-a) / (b-a),
        insec = 24*60*60 * frac,
        hours = Math.floor(insec/60/60),
        minites = Math.floor((insec-60*60*hours)/60),
        seconds = Math.floor(insec-60*60*hours-60*minites),
        error = "";
    if (isNaN(y) || isNaN(m) || isNaN(d) || isNaN(n)) {
        hours = minites = seconds = 0;
        error = "Please specify your birthday and lifespan correctly.";
    }
    else if (frac < 0) {
        hours = minites = seconds = 0;
        error = "You're not born.";
    }
    return { hours: hours,
             minites: minites,
             seconds: seconds,
             error:error };
}

console.log("Birth day is 1990/7/29, n = 80");
console.log(time_of_life(1990, 7, 29, 80, new Date()));
console.log("Birth day is 1990/7/29, n = 200");
console.log(time_of_life(1990, 7, 29, 200, new Date()));
