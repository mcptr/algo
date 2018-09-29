#!/usr/bin/env python


def display(grid, rows, cols):
    print("".center(cols * 3 - 1, "-"))
    for i in range(0, rows):
        print(" ".join(["%2d" % _ for _ in grid[i]]))
    print("".center(cols * 3 - 1, "-"))
    print("Size: %d x %d" % (rows, cols))
    print("".center(cols * 3 - 1, "="))


def find_product(grid, r, c, dr, dc, path_len):
    product = 1
    for i in range(path_len):
        product *= grid[r + dr * i][c + dc * i]
    return product


def find_max_product(grid, rows, cols, path_len=4):
    max_product = 0

    for r in range(0, rows):
        for c in range(0, cols):
            if c <= cols - path_len: # right
                max_product = max(max_product, find_product(grid, r, c, 0, 1, path_len))
            if r <= rows - path_len: # down
                max_product = max(max_product, find_product(grid, r, c, 1, 0, path_len))
                if c <= cols - path_len: # diagonal down right
                    max_product = max(max_product, find_product(grid, r, c, 1, 1, path_len))
                if c >= path_len - 1: # diagonal down left
                    max_product = max(max_product, find_product(grid, r, c, 1, -1, path_len))

    return max_product


def solve(filename):
    grid = []
    with open(filename, "r") as f:
        for line in f.readlines():
            grid.append(list(map(int, line.strip().split())))

    rows = len(grid)
    cols = len(grid[0]) if rows else 0

    display(grid, rows, cols)
    return find_max_product(grid, rows, cols, 4)


if __name__ == "__main__":
    import sys
    print(solve(sys.argv[1] if len(sys.argv) > 1 else "grid.txt"))
