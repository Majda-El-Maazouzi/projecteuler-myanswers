#include <stdio.h>

int evenFibonacciNumbers(int number) {
	int sum = 2;
	int i = 0;
	int fib = 0;
	int fib1 = 1;
	int fib2 = 2;
	
	while (fib < number) {
		
		fib = fib1 + fib2;
		if (fib%2 == 0 && fib < number){
			sum = sum + fib;
		}
		//printf ("--- fib: %d\n", fib);
		fib1 = fib2;
		fib2 = fib;
	}
	
	return sum;
}

void printProblemStatement(){
	printf("Problem 2: \n");
	printf("Even Fibonacci Numbers\n");
	printf("=================================\n");
	printf("Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:\n1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...\nBy considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.\n\n");
}

int main (void){
	printProblemStatement();
	printf("Solution:\n");
	printf("=========\n");
	printf("The sum is: %d \n\n",evenFibonacciNumbers(4000000));
	return 0;
}