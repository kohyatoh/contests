#!/usr/bin/env python
import sys

for line in sys.stdin:
    s = ""
    for c in line:
        d = ord(c) - ord('a')
        if d >= 0 and d < 26:
            s += chr(ord('a') + (d + 10) % 26)
        else:
            s += c
    print s
