#include<stdio.h>
#include <stdlib.h>

int largestProductInAgrid(){
	int product = 1;
	int product_row = 1;
	int product_column = 1;
	int product_diagonal_r = 1;
	int product_diagonal_l = 1;
	int i = 0;
	int j = 0;
	
	int grid[20][20] = {
		{8, 02, 22, 97, 38, 15, 00, 40, 00, 75, 04, 05, 07, 78, 52, 12, 50, 77, 91, 8},
		{49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 04, 56, 62, 00},
		{81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 03, 49, 13, 36, 65},
		{52, 70, 95, 23, 04, 60, 11, 42, 69, 24, 68, 56, 01, 32, 56, 71, 37, 02, 36, 91},
		{22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
		{24, 47, 32, 60, 99, 03, 45, 02, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
		{32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
		{67, 26, 20, 68, 02, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
		{24, 55, 58, 05, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
		{21, 36, 23, 9, 75, 00, 76, 44, 20, 45, 35, 14, 00, 61, 33, 97, 34, 31, 33, 95},
		{78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 03, 80, 04, 62, 16, 14, 9, 53, 56, 92},
		{16, 39, 05, 42, 96, 35, 31, 47, 55, 58, 88, 24, 00, 17, 54, 24, 36, 29, 85, 57},
		{86, 56, 00, 48, 35, 71, 89, 07, 05, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
		{19, 80, 81, 68, 05, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 04, 89, 55, 40},
		{04, 52, 8, 83, 97, 35, 99, 16, 07, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
		{88, 36, 68, 87, 57, 62, 20, 72, 03, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
		{04, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
		{20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 04, 36, 16},
		{20, 73, 35, 29, 78, 31, 90, 01, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 05, 54},
		{01, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 01, 89, 19, 67, 48}
	};
	
	product_row = largestProductInARow(grid);
	product_column = largestProductInAColumn(grid);
	product_diagonal_r = largestProductInADiagonalRight(grid);
	product_diagonal_l = largestProductInADiagonalLeft(grid);
	
	if(product_row> product){
		product = product_row;
	}
	if(product_column> product){
		product = product_column;
	}
	if(product_diagonal_r> product){
		product = product_diagonal_r;
	}
	if(product_diagonal_l> product){
		product = product_diagonal_l;
	}
	
	return product;
}

void printAdjacentNumbers(int numbers[4], int product){
	int i = 0;
	
	printf("%d",numbers[0]);
	for(i=1 ; i<4 ; i++){
		printf("*%d",numbers[i]);
	}
	printf(" =% d\n",product);
}

int largestProductInARow(int grid[20][20]){
	int largest_product = 1;
	int product = 1;
	int i = 0;
	int j = 0;
	int temp_j = 0;
	int adjacent_numbers[4];
	
	for(i=0 ; i<20; i++){
		//printf("Row %d:\n\t", i);
		product = 1;
		for(j=0; j<20-3; j++ ){
			//printf("j: %2d", grid[i][j]);
			product = 1;
			for( temp_j = 0; temp_j < 4; temp_j++){
				product = product*grid[i][j+temp_j];
				adjacent_numbers[temp_j] = grid[i][j+temp_j];
			}
			if(product> largest_product){
				largest_product = product;
				printAdjacentNumbers(adjacent_numbers, largest_product);
			}
		}
		//printf("\n");
	}
	printf("\n");
	return largest_product;
}

int largestProductInAColumn(int grid[20][20]){
	int largest_product = 1;
	int product = 1;
	int i = 0;
	int j = 0;
	int temp_j = 0;
	int adjacent_numbers[4];
	
	for(i=0 ; i<20; i++){
		//printf("Column %d:\n\t", i);
		for(j=0 ; j<20-3 ; j++){
			//printf("%2d ", grid[j][i]);
			product = 1;
			for( temp_j = 0; temp_j < 4; temp_j++){
				product = product*grid[j+temp_j][i];
				adjacent_numbers[temp_j] = grid[j+temp_j][i];
			}
			if(product> largest_product){
				largest_product = product;
				printAdjacentNumbers(adjacent_numbers, largest_product);
			}
		}
		//printf("\n");
	}
	printf("\n");
	return largest_product;
}

int largestProductInADiagonalRight(int grid[20][20]){
	int largest_product = 1;
	int product = 1;
	int i = 0;
	int j = 0;
	int temp_j = 0;
	int adjacent_numbers[4];
	
	//Lower Half of Matrix
	for(i=0 ; i<20; i++){
		//printf("Diagonal %d:\n\t", i);
		for(j=0 ; j<20-i-3 ; j++){
			//printf("\n%2d \n",grid[j+i][j]);
			product = 1;
			for( temp_j = 0; temp_j < 4; temp_j++){
				product = product*grid[j+temp_j+i][j+temp_j];
				adjacent_numbers[temp_j] = grid[j+temp_j+i][j+temp_j];
			}
			if(product> largest_product){
				largest_product = product;
				printAdjacentNumbers(adjacent_numbers, largest_product);
			}
		}
		//printf("\n");
	}
	
	//Upper Half of Matrix
	for(i=0 ; i<20; i++){
		//printf("Diagonal %d:\n\t", i);
		for(j=0 ; j<20-i-3 ; j++){
			//printf("%2d ",grid[j][j+i]);
			product = 1;
			for( temp_j = 0; temp_j < 4; temp_j++){
				product = product*grid[j+temp_j][j+temp_j+i];
				adjacent_numbers[temp_j] = grid[j+temp_j][j+temp_j+i];
			}
			if(product> largest_product){
				largest_product = product;
				printAdjacentNumbers(adjacent_numbers, largest_product);
			}
		}
		//printf("\n");
	}
	printf("\n");
	return largest_product;
}

int largestProductInADiagonalLeft(int grid[20][20]){
	int largest_product = 1;
	int product = 1;
	int i = 0;
	int j = 0;
	int temp_j = 0;
	int adjacent_numbers[4];
	
	//Lower Half of Matrix
	for(i=0 ; i<20; i++){
		//printf("Diagonal %d:\n\t", i);
		//for(j=20-1-3 ; j>=i ; j--){
		for(j=0 ; j<20-i-3 ; j++){
			//printf("%2d ",grid[20-1-j+i][j]);
			product = 1;
			for( temp_j = 0; temp_j < 4; temp_j++){
				product = product*grid[20-1-j-temp_j-i][j+temp_j];
				adjacent_numbers[temp_j] = grid[20-1-j-temp_j-i][j+temp_j];
			}
			if(product> largest_product){
				largest_product = product;
				printAdjacentNumbers(adjacent_numbers, largest_product);
			}
		}
		//printf("\n");
	}
	
	//Upper Half of Matrix
	for(i=0 ; i<20; i++){
		//printf("Diagonal %d:\n\t", i);
		for(j=0 ; j<20-i-3 ; j++){
			//printf("[%d,%d] - %2d ",j, 20-1-j-i, grid[j][20-1-j-i]);
			product = 1;
			for( temp_j = 0; temp_j < 4; temp_j++){
				product = product*grid[j+temp_j][20-1-j-temp_j-i];
				adjacent_numbers[temp_j] = grid[j+temp_j][20-1-j-temp_j-i];
			}
			if(product> largest_product){
				largest_product = product;
				printAdjacentNumbers(adjacent_numbers, largest_product);
			}
		}
		//printf("\n");
	}
	printf("\n");
	return largest_product;
}

void printProblemStatement(){
	printf("Problem 11:\n");
	printf("Largest product in a grid\n");
	printf("=================================\n");
	printf("In the 20*20 grid below, four numbers along a diagonal line have been marked in red.\n");
	printf("08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08\n");
	printf("49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00\n");
	printf("81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65\n");
	printf("52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91\n");
	printf("22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80\n");
	printf("24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50\n");
	printf("32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70\n");
	printf("67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21\n");
	printf("24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72\n");
	printf("21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95\n");
	printf("78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92\n");
	printf("16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57\n");
	printf("86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58\n");
	printf("19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40\n");
	printf("04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66\n");
	printf("88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69\n");
	printf("04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36\n");
	printf("20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16\n");
	printf("20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54\n");
	printf("01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48\n");
	printf("The product of these numbers is 26 × 63 × 78 × 14 = 1788696.\n");
	printf("What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20*20 grid?\n\n");
}

int main(void){
	printProblemStatement();
	printf("Solution\n");
	printf("=========\n");
	printf("The product is: %d\n", largestProductInAgrid());
	
	return 0;
}
