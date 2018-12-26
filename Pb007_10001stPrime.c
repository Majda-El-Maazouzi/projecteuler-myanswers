#include <stdio.h>

int generateTheNthPrimes(int number){
	int prime = 1;
	int primes[20000];
	int is_prime = 1;
	int i = 3;
	int j = 0;
	int primes_length = 1;
	primes[0] = 2;
	
	while (primes_length <number){
		j=0;
		is_prime = 1;
		while (j<primes_length){
			if (i% primes[j] == 0){
				is_prime = 0;
			}
			j++;
		}
		if(is_prime == 1){
			printf("\tThe prime that was added: %d\n", i);
			primes[primes_length] = i;
			primes_length++;
		}
		i++;
		
	}
		
	prime = primes[primes_length-1];
	return prime;
}

void printProblemStatement(){
	printf("Problem 5:\n");
	printf("10001st Prime\n");
	printf("=================================\n");
	printf("By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.\nWhat is the 10 001st prime number?\n\n");
}

int main (void){
	printProblemStatement();
	printf("Solution\n");
	printf("=========\n");
	printf("The 10001st Prime is: %d\n", generateTheNthPrimes(10001));
	return 0;
}
