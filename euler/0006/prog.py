#!/usr/bin/env python


sq = 0
s = 0
for i in range(1, 100 + 1):
    s += i
    sq += i * i

print(s * s - sq)
