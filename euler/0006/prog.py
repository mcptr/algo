#!/usr/bin/env python


# Regular version

sq = 0
s = 0
for i in range(1, 100 + 1):
    s += i
    sq += i * i

print(s * s - sq)

# LisPy version
(s, sq) = map(sum, zip(*[(_, _ * _) for _ in range(1, 100 + 1)] ))
print(s * s - sq)

# Perl Golf version.
print([(k * k - v) for k,v in [list(map(sum, zip(*[(_, _ * _) for _ in range(1, 100 + 1)] )))]][0])
