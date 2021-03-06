#include <stdio.h>
#include <stdlib.h>

int highlyDivisibleTriangularNumber(int number);
int getNumberOfDivisors(int** factors, int allpowers_length);
int** getPrimeFactors(int number, int primes[], int primes_length, int* allpowers_length);

int highlyDivisibleTriangularNumber(int number){
	int triangular_number = 0;
	int limit_reached = 0;
	int toadd = 1;
	int i = 0;
	int divisors = 0;
	
	int** prime_factors;
	int primes [50] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	int primes_length = 25;
	int allpowers_length=0;
	
	while(limit_reached == 0){
		//Find the triangular number
		triangular_number += toadd;
		
		//Find the prime factors of that triangular number
		prime_factors = getPrimeFactors (triangular_number, primes,  primes_length, &allpowers_length);
		
		//Find the number of divisors from those prime factors
		divisors = getNumberOfDivisors(prime_factors, allpowers_length);
		
		if(divisors >= number){
			limit_reached= 1;
			for(i = 0; i<allpowers_length; i++){
				printf("%d^%d\n", prime_factors[i][0], prime_factors[i][1]);
			}
			printf("Number of Divisors = %d\n\n", divisors);
		}

		toadd++;
	}
	
	return triangular_number;
}

int** getPrimeFactors(int number, int primes[], int primes_length, int* allpowers_length) {
	int** all_prime_factors;
	int j = 0;
	int count = 0;
	int power = 0;
	int temp_number = 0;
	
	all_prime_factors = (int**)malloc(sizeof(int*)*50);
	
	temp_number = number;
	power = 0;
	j=0;
	while(j<primes_length){
		if(temp_number == 1){
			all_prime_factors[count] = (int*)malloc(sizeof(int)*5);
			all_prime_factors[count][0]= primes[j];
			all_prime_factors[count][1]= power;
			j = primes_length;
			count++;
		}else if(temp_number % primes[j] == 0){
			temp_number = temp_number/primes[j];
			power++;
		}else{
			if(power != 0){
				all_prime_factors[count] = (int*)malloc(sizeof(int)*5);
				all_prime_factors[count][0]= primes[j];
				all_prime_factors[count][1]= power;
				power = 0;
				count++;
			}
			j++;
		}
	}
	
	*allpowers_length = count;
	return all_prime_factors;
}

int getNumberOfDivisors(int** factors, int allpowers_length){
	int i = 0;
	int divisors = 1;
	
	for(i = 0; i<allpowers_length; i++){
		divisors*= factors[i][1]+1;
	}
	
	return divisors;
}

void printProblemStatement(){
	printf("Problem 12:\n");
	printf("Highly divisible triangular number\n");
	printf("=================================\n");
	printf("The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:\n");
	printf("1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...\n");
	printf("Let us list the factors of the first seven triangle numbers:\n");
	printf("\t 1: 1\n\t 3: 1,3\n\t 6: 1,2,3,6\n\t10: 1,2,5,10\n\t15: 1,3,5,15\n\t21: 1,3,7,21\n\t28: 1,2,4,7,14,28\n");
	printf("We can see that 28 is the first triangle number to have over five divisors.\n");
	printf("What is the value of the first triangle number to have over five hundred divisors?\n\n");
}

int main(void){
	printProblemStatement();
	printf("Solution\n");
	printf("=========\n");
	printf("The triangular number is: %d\n", highlyDivisibleTriangularNumber(500));
	
	return 0;
}
