c   q02float.f
c
c   Copyright (C) 1996, 1997, 1998, 1999, 2000, 2004, 2007 Gerard Jungman, Brian Gough
c   Copyright (C) 2012, Kohsuke Yatoh
c
c   This program is free software: you can redistribute it and/or modify
c   it under the terms of the GNU General Public License as published by
c   the Free Software Foundation, either version 3 of the License, or
c   (at your option) any later version.
c
c   This program is distributed in the hope that it will be useful,
c   but WITHOUT ANY WARRANTY; without even the implied warranty of
c   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
c   GNU General Public License for more details.
c
c   You should have received a copy of the GNU General Public License
c   along with this program.  If not, see <http://www.gnu.org/licenses/>.

c   Original source is from GNU Scientific Library <http://www.gnu.org/software/gsl/>.
c   Used algorithms and constants from gsl-1.15, especially from
c      - specfunc/gamma.c (lngamma_lanczos())
c      - gsl_math.h

      program q02float
        double precision a
        double precision mygamma
        read *, a
        write (*,100) mygamma(a+1)
100     format (F14.6)
      stop
      end

c     Gamma function by Lanczos approximation
      double precision function mygamma(x)
        double precision x, r, s, pi, ag
        double precision c(9)
        data c / 0.99999999999980993227684700473478d0,
     +           676.520368121885098567009190444019d0,
     +           -1259.13921672240287047156078755283d0,
     +           771.3234287776530788486528258894d0,
     +           -176.61502916214059906584551354d0,
     +           12.507343278686904814458936853d0,
     +           -0.13857109526572011689554707d0,
     +           9.984369578019570859563d-6,
     +           1.50563273514931155834d-7 /
        pi = atan2(0.0d0, -1.0d0)
        r = 1
c       Lanczos approximation can be applied to the range x>0, not to x<=0.
c       We use the formula {gamma(x) = gamma(x+1) / x} to overcome this
c       limitation.
        do while (x .LE. 0)
            r = r / x
            x = x + 1
        enddo
        x = x - 1
        ag = c(1)
        do 1000 k = 1, 8
            ag = ag + c(k+1) / (x+k)
1000    continue
        s = sqrt(2*pi) * (x+7.5d0)**(x+0.5d0) * dexp(-x-7.5d0) * ag
        mygamma = r * s
      return
      end
