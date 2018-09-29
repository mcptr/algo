#!/usr/bin/env python


def display(data):
    grid = data["grid"]
    for i in range(0, data["rows"]):
        print(" ".join(["%2d" % _ for _ in grid[i]]))


def find_product(grid, r, c, dr, dc, path_len):
    product = 1
    for i in range(path_len):
        print(grid[r + dr * i][c + dc * i], end=" ")
        product *= grid[r + dr * i][c + dc * i]
    print("")
    return product


def find_max_product(data, path_len=4):
    grid = data["grid"]
    rows = data["rows"]
    cols = data["cols"]

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
    data = dict(
        rows=0,
        cols=0,
        grid=[]
    )
    with open(filename, "r") as f:
        for line in f.readlines():
            data["grid"].append(list(map(int, line.strip().split())))

    data["rows"] = len(data["grid"])
    data["cols"] = len(data["grid"][0]) if data["rows"] else 0

    display(data)
    return find_max_product(data)


if __name__ == "__main__":
    import sys
    print(solve(sys.argv[1] if len(sys.argv) > 1 else "grid.txt"))
