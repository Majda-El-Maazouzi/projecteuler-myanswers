def smallestMultiple (number):
    smallest_multiple = 1
    all_prime_factors = [[]]
    prime_factors = [[]]
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
    
    all_prime_factors = getAllFactorsPowers(number, primes)
    prime_factors = getBiggestFactorsPowers(all_prime_factors)
    
    for row in prime_factors:
        print("%d^%d" % (row[0], row[1]))
        smallest_multiple = smallest_multiple * pow (row[0],row[1])  
    
    return smallest_multiple

def getAllFactorsPowers (number, primes):
    all_prime_factors = []
    
    for i in range (2, number + 1):
        j = 0
        power = 0
        temp_number = i
        while (j < len(primes)):
            if(temp_number == 1):
                all_prime_factors.append([primes[j],power])
                break
            if(temp_number % primes[j] == 0):
                temp_number = temp_number/primes[j]
                power = power + 1
            else:
                if (power != 0):
                    all_prime_factors.append([primes[j],power])
                power = 0
                j = j+1
       
    return all_prime_factors

def getBiggestFactorsPowers (all_prime_factors):
    prime_factors = []

    i = 0
    while (i< len(all_prime_factors)):
        biggest_power = 1
        
        j = i
        if (all_prime_factors[i][0] != 0):
            while (j< len(all_prime_factors)):
            
                if (all_prime_factors[i][0] == all_prime_factors[j][0]):
                    if(biggest_power < all_prime_factors[j][1]):
                        biggest_power = all_prime_factors[j][1]
                    if(i != j):
                        all_prime_factors[j][0] = 0
                
                j = j+1
        
            prime_factors.append([all_prime_factors[i][0], biggest_power])
            
        i = i+1
        
    return prime_factors

def printProblemStatement ():
    print("Problem 5:")
    print("Smallest Multiple")
    print("=================================")
    print("2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.\nWhat is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n")

def main ():
    printProblemStatement()
    print("The solution:")
    print("=============")
    print("The smallest multiple is: %d" % smallestMultiple(20))

main()