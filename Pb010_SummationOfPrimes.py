import math

def summationOfPrimes(number):
    sum_primes = 0
    #latest_prime = 1
    i = 3
    is_prime = True
    primes = []
    primes.append(2)
    sum_primes = sum_primes + primes[0]
    
    while(i <= number):
        is_prime = True
        for prime in primes:
            if(i%prime == 0):
                is_prime = False
                break
            if(prime>=math.sqrt(i)):
                break
        
        if(is_prime == True):
            #print("Prime Added: %d" % i)
            primes.append(i)
            sum_primes = sum_primes + i
            #latest_prime = i
        
        i = i+1
    return sum_primes

def printProblemStatement():
    print("Problem 10:")
    print("Summation of primes")
    print("=================================")
    print("The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.\nFind the sum of all the primes below two million.\n")


def main():
    printProblemStatement()
    print("The solution:")
    print("=============")
    print("\nThe  sum of all the primes below two million is: %d" % summationOfPrimes(2000000))

main()