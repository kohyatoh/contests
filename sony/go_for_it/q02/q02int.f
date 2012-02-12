c   Copyright (c) 2012, Kohsuke Yatoh
c   All rights reserved.
c
c   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
c
c   Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
c   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
c
c   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
      program q02int
        integer a, myfactorial
        read *, a
        if (0 .LE. a .and. a .LE. 10) then
            write (*,*) myfactorial(a)
        else
            write (*,*) "Input must be an integer between 0 and 10."
        endif
      stop
      end

c   calculate factorial by simple loop.
      integer function myfactorial(n)
        integer n, i
        myfactorial = 1
        do 1000 i = 1, n
            myfactorial = myfactorial * i
1000    continue
      return
      end
