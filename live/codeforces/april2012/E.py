#!/usr/bin/env python

name = "INTERCAL"
#name = "hello"

def tos(cur):
    s = ""
    while cur > 0:
        s += chr(ord('0') + cur%2)
        cur /= 2
    return s

#print tos(234)

pre = 0
for i in name:
    cur = ord(i)
    s = ""
    for k in range(8):
        s += chr(ord('0') + cur%2)
        cur /= 2
#    print s
    for c in s:
        cur = cur * 2
        if c == '1': cur += 1
    print (pre - cur + 256) % 256
#    pre = (pre - cur + 256) % 256
    pre = cur
