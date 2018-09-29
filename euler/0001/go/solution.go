package main

import "fmt"

func calculate_sum(n int) uint64 {
	var sum uint64 = 0

	for ; n > 0; n-- {
		if n % 3 == 0 || n % 5 == 0 {
			sum = sum + uint64(n)
		}
	}
	return sum;
}

func main() {
	fmt.Println(calculate_sum(1000))
}
