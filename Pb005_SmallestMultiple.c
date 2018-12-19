#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** getAllFactorsPowers(int number, int primes[], int primes_length, int* allpowers_length);
int** getBiggestFactorsPowers(int** primes, int allfactors_length, int* biggestpowers_length);

int smallestMultiple(int number){
	int primes [50] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	int i = 0;
	int primes_length = 25;
	int** all_prime_factors;
	int** prime_factors;
	int allpowers_length=0;
	int biggestpowers_length=0;
	int smallest_multiple = 1;
	
	//Get all the prime factors and their powers
	all_prime_factors = getAllFactorsPowers (number, primes,  primes_length, &allpowers_length);
	
	//Get each prime factor and its biggest power
	prime_factors = getBiggestFactorsPowers(all_prime_factors, allpowers_length, &biggestpowers_length);
	
	//Multiply each prime factor with its power => Result!
	for(i = 0; i<biggestpowers_length; i++){
		printf("%d^%d\n", prime_factors[i][0], prime_factors[i][1]);
		smallest_multiple = smallest_multiple * pow(prime_factors[i][0], prime_factors[i][1]);
	}
	
	return smallest_multiple;
}

int** getAllFactorsPowers(int number, int primes[], int primes_length, int* allpowers_length) {
	int i = 0;
	int j = 0;
	int count = 0;
	int power = 0;
	int** all_prime_factors;
	int temp_number = 0;
	
	//Get all the prime factors and their powers
	all_prime_factors = (int**)malloc(sizeof(int*)*50);
	for (i=2; i<=number; i++){
		temp_number = i;
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
				
	}
	
	*allpowers_length = count;
	return all_prime_factors;
}

int** getBiggestFactorsPowers(int** primes, int allfactors_length, int* biggestpowers_length){
	int i=0;
	int j;
	int count = 0;
	int **arr=(int **)malloc(sizeof(int *)*50);
	
	arr[0]=(int *)malloc(sizeof(int)*5);
	arr[0][0] = primes[0][0];
	arr[0][1] = primes[0][1];
	for (i=0; i<allfactors_length; i++){
		
		if(primes[i][0] != 0){
			arr[count]=(int *)malloc(sizeof(int)*5);
			arr[count][0] = primes[i][0];
			arr[count][1] = primes[i][1];
			
			for (j=0; j<allfactors_length; j++){
				if(arr[count][0] == primes[j][0]){
					if(arr[count][1]< primes [j][1]){
						arr[count][1] = primes[j][1];
					}
					primes[j][0] = 0;
				}
			}
			count++;	
		}
	}
	
	*biggestpowers_length = count;
	return arr;
}

void printProblemStatement(){
	printf("Problem 5:\n");
	printf("Smallest Multiple\n");
	printf("=================================\n");
	printf("2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.\nWhat is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n\n");
}
	
int main (void) {
	printProblemStatement();
	printf("Solution\n");
	printf("=========\n");
	printf("The smallest multiple is: %d\n", smallestMultiple(20));
	return 0;
}
