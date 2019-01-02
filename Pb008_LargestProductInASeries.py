def largestProductInASeries(number):
    product = 1
    temp_product = 1
    adjacent_digits = []
    i = 1
    j = 1
    longnumber = "73167176531330624919225119674426574742355349194934"
    longnumber = longnumber +  "96983520312774506326239578318016984801869478851843"
    longnumber = longnumber +  "85861560789112949495459501737958331952853208805511"
    longnumber = longnumber +  "12540698747158523863050715693290963295227443043557"
    longnumber = longnumber +  "66896648950445244523161731856403098711121722383113"
    longnumber = longnumber +  "62229893423380308135336276614282806444486645238749"
    longnumber = longnumber +  "30358907296290491560440772390713810515859307960866"
    longnumber = longnumber +  "70172427121883998797908792274921901699720888093776"
    longnumber = longnumber +  "65727333001053367881220235421809751254540594752243"
    longnumber = longnumber +  "52584907711670556013604839586446706324415722155397"
    longnumber = longnumber +  "53697817977846174064955149290862569321978468622482"
    longnumber = longnumber +  "83972241375657056057490261407972968652414535100474"
    longnumber = longnumber +  "82166370484403199890008895243450658541227588666881"
    longnumber = longnumber +  "16427171479924442928230863465674813919123162824586"
    longnumber = longnumber +  "17866458359124566529476545682848912883142607690042"
    longnumber = longnumber +  "24219022671055626321111109370544217506941658960408"
    longnumber = longnumber +  "07198403850962455444362981230987879927244284909188"
    longnumber = longnumber +  "84580156166097919133875499200524063689912560717606"
    longnumber = longnumber +  "05886116467109405077541002256983155200055935729725"
    longnumber = longnumber +  "71636269561882670428252483600823257530420752963450"
    
    for i in range(0, len(longnumber)-number+1):
        adjacent_digits = []
        temp_product = 1
        
        for j in range(0, number):
            adjacent_digits.append(longnumber[i+j])
            temp_product = temp_product * int(longnumber[i+j])
            
        if(temp_product>product):
            printAdjacentDigits(adjacent_digits)
            product = temp_product
            print(" = %d" % product)
            
    return product

def printAdjacentDigits(*adjacent_digits):
    print("%c" % adjacent_digits[0][0], end ="")
    for j in range(1, len(adjacent_digits[0])):
        print("*%c" % adjacent_digits[0][j], end ="")

def printProblemStatement():
    print("Problem 8:")
    print("Largest product in a series")
    print("=================================")
    print("The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.");
    print("73167176531330624919225119674426574742355349194934")
    print("96983520312774506326239578318016984801869478851843")
    print("85861560789112949495459501737958331952853208805511")
    print("12540698747158523863050715693290963295227443043557")
    print("66896648950445244523161731856403098711121722383113")
    print("62229893423380308135336276614282806444486645238749")
    print("30358907296290491560440772390713810515859307960866")
    print("70172427121883998797908792274921901699720888093776")
    print("65727333001053367881220235421809751254540594752243")
    print("52584907711670556013604839586446706324415722155397")
    print("53697817977846174064955149290862569321978468622482")
    print("83972241375657056057490261407972968652414535100474")
    print("82166370484403199890008895243450658541227588666881")
    print("16427171479924442928230863465674813919123162824586")
    print("17866458359124566529476545682848912883142607690042")
    print("24219022671055626321111109370544217506941658960408")
    print("07198403850962455444362981230987879927244284909188")
    print("84580156166097919133875499200524063689912560717606")
    print("05886116467109405077541002256983155200055935729725")
    print("71636269561882670428252483600823257530420752963450")
    print("Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?\n")


def main():
    printProblemStatement()
    print("The solution:")
    print("=============")
    print("\nThe largest product in the series is: %d" % largestProductInASeries(13))

main()