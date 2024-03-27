#Dawson Tolbert
#Guided Exercise 8
# Sources: N/A

import random

def sixSidedDie():
    return random.randint(1,6)

def twentySidedDie():
    return random.randint(1,20)

def anyDie(num):
    return random.randint(1,num)

def sentinelExample():
    userInput = input("Please enter a command: ")
    while userInput != "quit" and userInput != "exit":
        print("That's not a valid command!")
        userInput = input("Please enter a command: ")
    print("Goodbye")
#If I type "help" it says "That's not a valid command!" and asks to enter a command
#I have to type "quit" to get the loop to stop

def stopNegative():
    userInput = int(input("Please enter a number: "))
    while userInput >= 0:
        userInput = int(input("Please enter a number: "))

def badPassword():
    userInput = input("Please enter a password: ")
    while userInput != "Programming":
        print("Password Incorrect")
        userInput = input("Please enter a password: ")

def getValidInput(text, low, high):
    value = int(input(text))
    while value < low or value > high:
        print("Sorry, not valid, try again!")
        value = int(input(text))
    return value

userInput = getValidInput("Hey there, enter a number!", 5, 10)

def guessingGame():
    randNum = random.randint(1,100)
    userInput = int(input("Guess a number between 1 and 100: "))
    attemptCount = 1
    while userInput != randNum:
        if userInput < randNum:
            print("Too low!")
        else:
            print("Too high!")
        attemptCount = attemptCount + 1
        userInput = int(input("Guess again: "))
    print("Congratulations! It took you " + str(attemptCount) + " tries to guess the number")
        