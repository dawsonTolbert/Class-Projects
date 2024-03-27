#Dawson Tolbert
#Guided Exercise 6
#Sources: N/A

print(6 > 5) #True
print(42 < 40) #False
print(42 >= 42) #True
print(1 != 2) #True
print(1 == 1) #True
print("x" in "example") #True
print("z" in "example") #False
print(42 in [1, 2, 3, 4]) #False
print(42 not in [1, 2, 3, 4]) #True

userInput = int(input("What is the answer to life, the universe, and everything?"))
if userInput == 42:
    print("Good job! Now to find the question...")

print("Goodbye")
#If I type 42 then it prints the "Good job" and "Goodbye" statements.
#If I type something other than 42 it only prints "Goodbye"

userInput = int(input("Strings and Lists start at this position:"))
if userInput == 0:
    print("Good job!")
else:
    print("Sorry, that's wrong.")
#If I type in 0 it prints "Good job!")
#If I type in something else I get "Sorry, that's wrong.")

userInput = int(input("Enter a number: "))
if userInput < 5:
    print("Less than 5")
if userInput >= 5:
    print("Greater than or equal to 5")
else:
    print("Less than 5")
#If I type 4 then it prints "Less than 5" twice

userInput = int(input("Enter a number: "))
if userInput < 10:
    print("Less than ten")
elif userInput > 10:
    print("Greater than ten")
else:
    print("Equal to ten")
#If I type 10 it prints "Equal to ten"
#If I type 1 it prints "Less than 10"
#If I type 100 it prints "Greater than 10"

age = int(input ("Please enter your age:"))
height = float(input("Please enter your height in inches: "))
if age > 3 and height > 44:
    print("You can ride Space Mountain!")
else:
    print("Sorry, you can't ride Space Mountain!")
#If I type my age as under 3 or my height as under 44
#then it prints "Sorry, you can't ride Space Mountain!"

day = input("Enter a day: ")
if day == "Tuesday" or day == "Thursday":
    print("Attend CS 151")
else:
    print("Do programming homework!")
#To get "Attend CS 151" I need to type either Tuesday or Thursday

