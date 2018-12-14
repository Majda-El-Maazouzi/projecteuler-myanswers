def largestPalindromeProduct (small, big):
    largestPalindrome = 1
    
    i=big
    while (i>=small):
        j=i
        while(j<=big):
            if(largestPalindrome <= (i*j) and isAPlindrome(i*j)):
                print("%d * %d = %d" % (i,j, i*j))
                largestPalindrome = (i*j)
            j = j+1
        i = i-1
        
    return largestPalindrome

def isAPlindrome(number):
    temp_number = number
    digits = 0
    i = 0
    j = 0
    digits_arr = []
    temp_digit = 0
    
    #get Number of digits
    while (temp_number >= 1):
        temp_number = temp_number / 10
        digits = digits + 1

    #get seperate digits
    temp_digit = number
    i = 0
    while (i<digits):
        power_10 = pow (10,digits-i-1)
        digits_arr.append(int(temp_digit / power_10))
        temp_digit = temp_digit - int(temp_digit / power_10) * power_10
        #print ("digits_arr[i]: %d" % digits_arr[i])
        i = i+1
    
    #see if digits are similar
    i = 0
    j = digits-1
    while (i<=j):
        if(digits_arr[i] != digits_arr[j]):
            return False
        i = i+1
        j = j-1
    
    return True

def printProblemStatement():
    print ("Problem 4:")
    print ('Largest Plindrome Product')
    print ('=================================')
    print ("A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.\nFind the largest palindrome made from the product of two 3-digit numbers.\n")

def main():
    printProblemStatement()
    print("The solution:")
    print("=============")
    print("The largest palindrome product is: %d" % largestPalindromeProduct(101,999))

main()