def sumSquareDifference(number):
    difference = 0
    sum_squares = 0
    square_sum = 0
    
    sum_squares = sumSquares(number)
    square_sum = squareSum(number)
    
    difference =  square_sum - sum_squares
    
    return difference

def sumSquares(number):
    my_sum = 0
    
    for i in range (1, number+1):
        my_sum = my_sum + pow(i, 2)
    
    return my_sum

def squareSum(number):
    my_square = 0
    
    for i in range (1, number+1):
        my_square = my_square + i
        
    my_square = pow(my_square, 2)
    
    return my_square

def printProblemStatement():
    print("Problem 6:")
    print("Sum Square Difference")
    print("=================================")
    print("The sum of the squares of the first ten natural numbers is,\n1^2 + 2^2 + ... + 10^2 = 385");
    print("The square of the sum of the first ten natural numbers is,\n(1 + 2 + ... + 10)^2 = 55^2 = 3025");
    print("Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.");
    print("Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n");


def main():
    printProblemStatement()
    print("The solution:")
    print("=============")
    print("The sum square difference is: %d" % sumSquareDifference(100))

main()