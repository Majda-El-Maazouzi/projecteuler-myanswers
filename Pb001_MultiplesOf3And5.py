def multiplesOf3And5(number):
    i = 0
    mySum = 0
    for i in range (1,number):
        if i%3 == 0 or i%5 == 0:
            mySum = mySum + i
    
    return mySum

def printProblemStatement():
    print('Problem 1: ')
    print('Multiples of 3 and 5')
    print('=================================')
    print('If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.\nFind the sum of all the multiples of 3 or 5 below 1000.\n')

def main():
    printProblemStatement()
    print("Solution")
    print("=========")
    print('The sum is: %d' % multiplesOf3And5(1000) )

main()