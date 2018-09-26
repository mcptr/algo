#!/usr/bin/env python

# Inspired by:
# http://code.jasonbhill.com/python/project-euler-problem-5/

import sys


def factorize(n):
    factors = []
    while n % 2 == 0:
        factors.append(2)
        n /= 2
    f = 3
    while n != 1:
        while n % f == 0:
            factors.append(f)
            n /= f
        f += 2
    return factors


def merge_factors(factors, new_factors):
    if not factors:
        factors.extend(new_factors)
        return
    uniq = set(new_factors)
    for f in uniq:
        diff = new_factors.count(f) - factors.count(f)
        factors.extend([f * diff] if diff > 0 else [])


def solution(n):
    factors = []
    for i in range(1, n + 1): merge_factors(factors, factorize(i))
    print(factors);
    product = 1
    for f in factors: product *= f
    return product


if __name__ == "__main__":
    n = int(sys.argv[1]) if len(sys.argv) > 1 else 20

    import time

    start = time.perf_counter()
    product = solution(n)
    elapsed = (time.perf_counter() - start)
    print("{}, {:.12f}".format(product, elapsed))
