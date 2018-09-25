TODO:

- Problem 0007: Check the performance of generating nth prime using sieve of Eratosthenes.
	Asymptote:

	```
	>>> n * (math.log(n) + math.log(math.log(n)))
	114319.21107907654
	```



DONE:

* Problem 0004: Try counting downwards (999, 998...). That should speed it up, we're looking for the largest, so the first one
  will be the solution.
  
* Actually time the is_palindrome_naive and is_palindrome, the naive (array) version seems faster somehow.
