#include <stdio.h>

int multiplesOf3And5(int number){
	int sum = 0;
	int i = 0;
	
	for(i=1;i<1000;i++){
		if(i%3==0 || i%5==0){
			//printf("%d -- %d\n",i,sum);
			sum = sum+i;
		}
	}
	return sum;
}

void printProblemStatement (){
	printf("Problem 1: \n");
	printf("Multiples of 3 and 5\n");
	printf("=================================\n");
	printf("If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.\nFind the sum of all the multiples of 3 or 5 below 1000.\n\n");
}


int main (void){

	printProblemStatement();
	
	printf("Solution\n");
	printf("=========\n");
	printf("The sum is: %d\n\n", multiplesOf3And5(1000));
	
	return 0;
}
