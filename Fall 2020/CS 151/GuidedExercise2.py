#Dawson Tolbert
#Guided Exercise 2

#Input allows us to provide some text to tell the user what they
#need to type in and then pauses to wait for the user to type in something
#The end=” “ syntax tells the print statement that you don’t want
#to go to the next line yet, but you want to print a space instead
userName = input("Enter your name: ")
print("Hello,", userName, "!")
nameLength = len(userName)
aCount = userName.count("a")
eCount = userName.count("e")
iCount = userName.count("i")
oCount = userName.count("o")
uCount = userName.count("u")
vowelCount = aCount + eCount + iCount + oCount + uCount
print(userName, "is", nameLength, "letters long, has", end=" ")
print(aCount, "a's,", eCount, "e's,", iCount, "i's,", oCount, "o's,", uCount, "u's", end=" ")
print("and has", vowelCount, "vowels.")

intNumber = float(input("Enter an integer number: "))
print(intNumber + 1)
#If I enter 42.5 to this prompt when it's using int(), I get an error message:
#"ValueError: invalid literal for int() with base 10: '42.5'"
#When I use float instead of int, it does not give me an error for entering 42.5
#and it returns a "43.0" if I enter 42
#I think float() means to return a decimal number
print("Thank you for using my program :)")