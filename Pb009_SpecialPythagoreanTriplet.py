import math

def specialPythagoreanTriplet():
    product = 1
    a = 1
    b = 1
    c = 1
    c_squared = 1.0
    specialsum = 0
    found = False
    
    for a in range(1, 998):
        
        for b in range(a+1, 1000-a):
            c_squared = pow(a,2) + pow(b,2)
            c = math.sqrt(c_squared)
            
            if(c == int(c)):
                #print("Perfect square found: %f\n" % c)
                specialsum = a + b+ c
                if(specialsum == 1000):
                    print("a=%d, b=%d, c=%d" %(a,b,c))
                    product = a*b*c
                    found = True
            
            if(found == True):
                break
        
        if(found == True):
                break
    
    return product

def printProblemStatement():
    print("Problem 9:")
    print("Special Pythagorean triplet")
    print("=================================")
    print("A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,\na^2 + b^2 = c^2\nFor example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.");
    print("There exists exactly one Pythagorean triplet for which a + b + c = 1000.\nFind the product abc.\n")

def main():
    printProblemStatement()
    print("The solution:")
    print("=============")
    print("\nThe product abc is: %d" % specialPythagoreanTriplet())

main()