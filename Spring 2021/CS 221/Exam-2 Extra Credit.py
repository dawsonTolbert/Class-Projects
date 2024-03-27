#Dawson Tolbert
#CS 221

def Parity(string):
    #your code goes here
    length = len(string)
    count = string.count("1")
    if length <= 16:
        if count % 2 == 0:
            return "even"
        else:
            return "odd"
    else:
        return "Too long"

    #your code ends here

print(Parity("010101"))
print(Parity(""))
print(Parity("11110000"))
print(Parity("10101010101010101"))
