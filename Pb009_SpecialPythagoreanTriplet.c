#include <stdio.h>
#include <math.h>

int specialPythagorenTriplet(){
	int product = 1;
	int a = 1;
	int b = 1;
	int sum = 0;
	float c_squared = 1;
	int c = 1;
	float c_float = 1;
	
	for(a=1 ; a<=997 ; a++){
		for(b=a+1; b<=1000-a-1; b++){
			c_squared = pow(a,2)+pow(b,2);
			c = (int)sqrt(c_squared);
			c_float = sqrt(c_squared);
			if(c - c_float == 0){
				//printf("\t%d^2 + %d^2 = %d^2\n",a,b,c);
				sum = a+b+c;
				if(sum == 1000){
					printf("a=%d, b=%d, c=%d\n",a,b,c);
					product = a*b*c;
					a=997;
				}
			}
		}
	}
	
	return product;
}

void printProblemStatement(){
	printf("Problem 9:\n");
	printf("Special Pythagorean triplet\n");
	printf("=================================\n");
	printf("A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,\na^2 + b^2 = c^2\nFor example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.\n");
	printf("There exists exactly one Pythagorean triplet for which a + b + c = 1000.\nFind the product abc.\n\n");
}

int main(void){
	printProblemStatement();
	printf("Solution\n");
	printf("=========\n");
	printf("The product abc is: %d\n", specialPythagorenTriplet());
	
	return 0;
}
