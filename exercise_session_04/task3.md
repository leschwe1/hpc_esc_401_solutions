- factor command:
	- takes int(s) (one or more) --> outputs factorization with prime numbers
	- factor 20 --> 20:  2 2 5
	- factor 31 --> 31: 31

- how to use it: 
	- if number is a prime, the return is exactly one number with the same value as the original number!

- use of wc:
	- wc counts the number of words: here the number of numbers returned
	

- piping: 
	- pipe output of factor to wc --> counts the number of factors --> check if 2  or more (= prime or composite)
	- add awk behind to make the correct output!

- time use: 
	- time isprime XX

	- output:
	- [eiger][lschweis@eiger-ln004 measured]$ time ./isprime 4230283
	- 4230283 is prime

	- real    0m0.012s
	- user    0m0.005s
	- sys     0m0.009s
	- [eiger][lschweis@eiger-ln004 measured]$ time ./isprime 4572862171001
	- 4572862171001 is prime

	- real    0m0.012s
	- user    0m0.007s
	- sys     0m0.007s
  

