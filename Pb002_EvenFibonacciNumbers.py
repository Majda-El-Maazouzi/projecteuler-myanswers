def evenFibonacciNumbers(number):
    mySum = 2
    fib1 = 1
    fib2 = 2
    fib = 0
    
    while (fib < number):
        fib = fib1 + fib2
        
        if(fib%2==0 and fib < number):
            mySum = mySum + fib
        
        fib1 = fib2
        fib2 = fib
            
    return mySum

def printProblemStatement ():
    print ("Problem 2:")
    print ('Even Fibonacci Numbers')
    print('=================================')
    print('Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:\n1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...\nBy considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.\n')


def main():
    printProblemStatement()
    print('The solution')
    print('=============')
    print ('The sum is: %d' % evenFibonacciNumbers(4000000))

main()