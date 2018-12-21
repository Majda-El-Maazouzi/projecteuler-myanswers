#include <stdio.h>
#include <math.h>

int sumSquareDifference(int number){
	int difference = 0;
	int sum_squares = 0;
	int square_sum = 0;
	
	//return sum of squares
	sum_squares = sumSquares(number);
	
	//return square of sum
	square_sum = squareSum(number);
	
	difference = square_sum - sum_squares;
	
	return difference;
}

int sumSquares(int number){
	int sum = 0;
	int i = 0;
	
	for (i=1 ; i<=number; i++){
		sum = sum + pow(i,2);
	}
	
	return sum;
}

int squareSum(int number){
	int square = 0;
	int i = 0;
	
	for (i=1; i<=number; i++){
		square = square + i;
	}
	
	square = pow(square,2);
	
	return square;
}

void printProblemStatement() {
	printf("Problem 6:\n");
	printf("Sum Square Difference\n");
	printf("=================================\n");
	printf("The sum of the squares of the first ten natural numbers is,\n1^2 + 2^2 + ... + 10^2 = 385\n");
	printf("The square of the sum of the first ten natural numbers is,\n(1 + 2 + ... + 10)^2 = 55^2 = 3025\n");
	printf("Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.\n");
	printf("Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n\n");
}

int main (void){
	printProblemStatement();
	printf("Solution\n");
	printf("=========\n");
	printf("The Sum Square Difference is: %d\n", sumSquareDifference(100));
	return 0;
}
