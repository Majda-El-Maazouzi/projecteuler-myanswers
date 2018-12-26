def generateTheNthPrime(number):
    primes = []
    primes.append(2)
    is_prime = True
    prime = 1
    
    i = 3
    while (len(primes) < number):
        is_prime = True
        for prime in primes:
            if(i % prime == 0):
                is_prime = False
                break;
        if(is_prime == True):
            print("Prime Added: %d" % i)
            primes.append(i)
        i = i+1
    
    prime = primes[len(primes)-1]
    return prime

def printProblemStatement():
    print("Problem 7:")
    print("10001st Prime")
    print("=================================")
    print("By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.\nWhat is the 10 001st prime number?\n");


def main():
    printProblemStatement()
    print("The solution:")
    print("=============")
    print("\nThe 10001st prime is: %d" % generateTheNthPrime(10001))


main()