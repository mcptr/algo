#!/usr/bin/env python

import time


def gen():
    "Gregory-Leibniz: 4/1 - 4/3 + 4/5 - 4/7 + 4/9 ..."

    total_diff = 0
    diffs = 0

    pi = 4 / 1
    i = 3

    loop = 0
    while True :
        last = pi = (pi - (4 / i))
        pi += (4 / (i + 2))
        diff = pi - last
        total_diff += diff
        diffs += 1
        i += 4
        loop += 1
        yield "%012d: %1.32f %1.32f %3.32f %1.32f" % (
            loop, pi, diff, total_diff, total_diff / diffs)


if __name__ == "__main__":
    for r in gen():
        print(r)
