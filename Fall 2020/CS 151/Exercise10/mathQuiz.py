#Dawson Tolbert
#Guided Exercise 10
#Sources: N/A

"""
This program works, but is breakable.
You are not re-writing the whole logic of the program.
You are trying to error-proof it as best you can.
The end goal is for quiz() to be able to run without any red error messages.
Not every problem is fixed with Exceptions. Some can be fixed with if
statements and loops. But some do need Exceptions.
I left hints for you in comments.
"""


import random

"""
getInt: What happens when the user enters text instead of a number?
        Use an exception and a loop to make sure you return a valid input
        Don't worry about people entering a float
        Hint: there's a version of this for you in the exercise text
"""
def getInt(message):
    while True:
        try:
            userInput = int(input(message))
        except ValueError:
            print("Invalid input, try again")
        else:
            return userInput
#Using text instead of a number gives a ValueError

"""
numBetween: What happens when the small number is bigger than the large number?
            Can it be fixed here, or do you have to take care of it in generateQuestions()?
            Hint: You can't ask for user input here
"""
def numBetween(small,large):
    try:
        large / small
        random.randint(small,large)
    except ValueError:
        print("Small number is bigger than large number")
    except TypeError:
        print("One parameter isn't a number")
    else:
        return random.randint(small,large)
#When the small number is bigger, it gives a ValueError
#This can't be fixed here since I can't ask for user input

"""
correctAnswer: What happens either of num1 and num2 aren't numbers?
               What happens if there isn't a valid operation?
               One of these could cause an exception, but you should
               raise an exception for the other.
               
"""
def correctAnswer(num1,num2,operation):
    try:
        num1 - num2
    except TypeError:
        print("One num parameter is not a number")
    else:
        if operation == "+":
            return num1 + num2
        elif operation == "-":
            return num1 - num2
        elif operation == "*":
            return num1 * num2
        else:
            print("Invalid operation '" + operation + "'")
#If num1 or 2 aren't numbers then it returns a TypeError or the string if using "*"
#If there is an invalid operation, nothing happens

"""
outputQuestion, correctMessage, and incorrectMessage are output methods
there's not much to error check here
"""
def outputQuestion(num1,num2,operation):
    try:
        str(num1) + operation + str(num2)
    except TypeError:
        print("operation must be a string")
    else:
        return str(num1) + operation + str(num2)

def correctMessage(answer):
    return "You got it! The answer was " + str(answer)

def incorrectMessage(answer):
    return "Oops! The answer was " + str(answer)

"""
generateQuestions:  Take some time and see how many ways you can break this
                    Then think about it in two ways:
                    1. What can you fix or raise in the function itself?
                    2. Where do the parameters come from (hint: quiz),
                    and what can you change there to prevent crashes?
"""
def generateQuestion(small,large,operation):
    num1 = numBetween(small,large)
    num2 = numBetween(small,large)
    calculatedAnswer = correctAnswer(num1,num2,operation)
    print(outputQuestion(num1,num2,operation))
    userAnswer = getInt("Enter your answer: ")
    if userAnswer == calculatedAnswer:
          print(correctMessage(calculatedAnswer))
          return True
    else:
          print(incorrectMessage(calculatedAnswer))
          return False

"""
quiz: If you worked on the functions above, some of the potential problems
      with quiz() will be fixed. But quiz() sends information to several
      of those functions. You should work to make sure that information
      is valid. 
"""
def quiz():
    print("Welcome to the Math Quiz!")
    
    runQuiz = True
    while runQuiz == True:
        print("1. Practice Addition")
        print("2. Practice Subtraction")
        print("3. Practice Multiplication")
        print("4. Exit the program")

        menuChoice = getInt("What is your choice: ")

        if menuChoice < 1 or menuChoice > 4:
            print("Invalid choice!")
        elif menuChoice == 4:
            print("Goodbye, thanks for learning!")
            runQuiz = False
        else:
            numQuestions = getInt("How many questions do you want?")  #can you prevent this from being negative?
            while numQuestions < 1:
                print("Number must be a positive integer")
                numQuestions = getInt("How many questions do you want?")
            small = getInt("What's the smallest number you want to use?") 
            large = getInt("What's the biggest number you want to use?") #can you check to see if small < large?
            while small > large:
                print("Your smallest number is greater than your biggest.")
                small = getInt("What's the smallest number you want to use?") 
                large = getInt("What's the biggest number you want to use?")
            correct = 0
            for item in range(0,numQuestions):
                result = False
                if menuChoice == 1:
                    result = generateQuestion(small,large,"+")
                elif menuChoice == 2:
                    result = generateQuestion(small,large,"-")
                elif menuChoice == 3:
                    result = generateQuestion(small,large,"*")
                if result == True:
                    correct = correct + 1
            print("You got", correct, "problems correct")
            print("You missed", numQuestions - correct, "problems")

            #Can you make sure this code only accepts Y and N?
            #Right now it accepts anything other than N as play again.
            playAgain = input("Do you want to play again (Y/N): ")
            while playAgain.upper() != "N" and playAgain.upper() != "Y":
                print("You must enter Y or N")
                playAgain = input("Do you want to play again (Y/N): ")
            if playAgain.upper() == "N":
                print("Goodbye, thanks for learning!")
                runQuiz = False