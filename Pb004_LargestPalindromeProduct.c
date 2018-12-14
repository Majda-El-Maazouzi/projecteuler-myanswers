#include <stdio.h>
#include <math.h>

long largestPalindromeProduct(int small, int big) {
	
	int i = big;
	int j = 0;
	long largestPalindrome = 1;
	int isPlalidrome = 0;
	
	for(i=big; i>=small; i--) {
		for(j=i; j<=big; j++) {
			if((i*j)>largestPalindrome) {
				isPlalidrome = isAPalindrome(i*j);
				if(isPlalidrome == 1) {
					largestPalindrome = i*j;
					printf("%d * %d = %d \n", i, j, i*j); 
				}
			}
		}
	}
	
	return largestPalindrome;
}

int isAPalindrome(long number) {
	int digits = 0;
	long digits_arr[50];
	int temp_digit = 0;
	int i = 0;
	int found = 1;
	int j;
	long temp_number = number;
	long power_10;
		
	do {
		temp_number = temp_number/10;
		digits++;
	} while (temp_number > 0);
	
	temp_digit = number;
	while (i < digits){
		power_10 = pow(10,digits-i-1);
		digits_arr[i] = temp_digit/power_10;
		temp_digit = temp_digit - (digits_arr[i] * power_10);
		i++;
	}
		
	j=digits-1;
	i=0;
	while ( i<=j & found==1){
		if(digits_arr[i] != digits_arr[j]){
			found = 0;
		}
		i++;
		j--;
	}
	
	return found;
}

void printProblemStatement() {
	printf("Problem 4: \n");
	printf("Largest Palindrome Product\n");
	printf("=================================\n");
	printf("A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.\nFind the largest palindrome made from the product of two 3-digit numbers.\n\n");
}

int main (void) {
	printProblemStatement();
	printf("Solution\n");
	printf("=========\n");
	
	printf("The largest plaindrome product is: %ld\n",largestPalindromeProduct(101,999));
	return 0;
}
