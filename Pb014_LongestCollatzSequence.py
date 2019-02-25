#warning: The algorithm takes 36 seconds before reaching the result
def longestCollatzSequence(limit):
    i = 1
    temp_i = 1
    longest_chain = 1
    chain_lenght = 1
    starting_number = 1
    
    while(i<=limit):
        if(temp_i == 1):
            if(chain_lenght > longest_chain):
                longest_chain = chain_lenght
                starting_number = i
            i += 1
            temp_i = i
            chain_lenght = 1
        else:
            if(temp_i % 2 == 0):
                temp_i = int(temp_i/2)
                chain_lenght += 1
            else:
                temp_i = 3*temp_i +1
                chain_lenght += 1
    
    print("The length of the longest chain: %d" % longest_chain)
        
    return starting_number

def printProblemStatement():
    print("Problem 14:")
    print("Large sum")
    print("==================================")
    print("The following iterative sequence is defined for the set of positive integers:")
    print("n -> n/2 (n is even)\nn -> 3n + 1 (n is odd)\n")
    print("Using the rule above and starting with 13, we generate the following sequence:\n13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1")
    print("It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. \nAlthough it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.\n")
    print("Which starting number, under one million, produces the longest chain?\n")
    print("NOTE: Once the chain starts the terms are allowed to go above one million.\n")

def main():
    printProblemStatement()
    print("The solution:")
    print("=============")
    print("#warning: The algorithm takes 36 seconds before reaching the result")
    print("\nThe number that produces the longest chain is: %d" % longestCollatzSequence(1000000))

main()