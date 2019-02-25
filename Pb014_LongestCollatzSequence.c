#include <stdio.h>

int longestCollatzSequence(int limit){
	int number = 1;
	int i = 1;
	unsigned int temp_i = 1;
	int chain_length = 1;
	int longest_chain = 0;
	int starting_number = 1;
	
	while(i<=limit){
		if(temp_i== 1){
			if(chain_length>longest_chain){
				longest_chain = chain_length;
				starting_number = i;
				//printf("length of the longest chain = %d\n",longest_chain);
				//printf("starting_number = %d\n\n",starting_number);
			}
			i++;
			temp_i = i;
			chain_length = 1;
		}else if(temp_i % 2 == 0){
			temp_i = temp_i/2;
			chain_length++;
		}else{
			temp_i = 3*temp_i + 1;
			chain_length++;
		}
	}
	
	printf("length of the longest chain = %d\n",longest_chain);
	return starting_number;
}

void printProblemStatement(){
	printf("Problem 14:\n");
	printf("Longest Collatz sequence\n");
	printf("=================================\n");
    printf("The following iterative sequence is defined for the set of positive integers:\n");
    printf("n -> n/2 (n is even)\nn -> 3n + 1 (n is odd)\n\n");
    printf("Using the rule above and starting with 13, we generate the following sequence:\n13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1\n");
    printf("It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. \nAlthough it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.\n\n");
	printf("Which starting number, under one million, produces the longest chain?\n\n");

	printf("NOTE: Once the chain starts the terms are allowed to go above one million.\n\n");
}

int main(void){
	printProblemStatement();
	printf("Solution\n");
	printf("=========\n");
	printf("The number that produces the longest chain is: %d\n", longestCollatzSequence(1000000));
	return 0;
}
