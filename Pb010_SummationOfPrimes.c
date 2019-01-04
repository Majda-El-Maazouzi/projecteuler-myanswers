#include <stdio.h>
#include <math.h>

long long summationOfPrimes(long long number){
	long long primes[200000];
	int is_prime = 1;
	long long i = 3;
	int j = 0;
	int primes_length = 1;
	long long latest_prime = 1;
	long long sum = 2;
	primes[0] = 2;
	
	while(latest_prime <= number){
		//printf("i: %d\n", i);
		j=0;
		is_prime = 1;
		while(j < primes_length && primes[j] <= sqrt(i)){
			//printf("\tj: %d\n", primes[j]);
			if(i%primes[j] == 0){
				is_prime = 0;
				j = primes_length;
			}
			j++;
		}
		if(is_prime==1){
			latest_prime = i;
			if(i<=number){
				//printf("\tThe prime that was added: %I64u\n", i);
				primes[primes_length] = i;
				sum = sum + primes[primes_length];
				primes_length++;
			}
			//printf("Primes lenght: %d", primes_length);
		}
		i++;
	}
		
	return sum;
}

void printProblemStatement(){
	printf("Problem 10:\n");
	printf("Summation of primes\n");
	printf("=================================\n");
	printf("The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.\nFind the sum of all the primes below two million.\n\n");
}

int main(void){
	printProblemStatement();
	printf("Solution\n");
	printf("=========\n");
	printf("The sum of all the primes below two million is: %I64u\n", summationOfPrimes(2000000));
	
	return 0;
}
