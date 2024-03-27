#Dawson Tolbert
#Mini Project 5
#Sources: N/A

#The following function calculates the percentage the person got on the quiz
#using numQuestions and numCorrect parameters
#Returns a grade letter based on the percentage
def gradeLetter(numQuestions, numCorrect):
    try:
        numCorrect / numQuestions
    except TypeError:
        print("One parameter isn't a number")
    except ZeroDivisionError:
        print("Cannot divide by zero")
    else:
        grade = numCorrect / numQuestions * 100
        if grade > 100:
            print("Grade cannot be higher than 100!")
        elif 97 <= grade <= 100:
            return "A+"
        elif 93 <= grade < 97:
            return "A"
        elif 90 <= grade < 93:
            return "A-"
        elif 87 <= grade < 90:
            return "B+"
        elif 83 <= grade < 87:
            return "B"
        elif 80 <= grade < 83:
            return "B-"
        elif 77 <= grade < 80:
            return "C+"
        elif 73 <= grade < 77:
            return "C"
        elif 70 <= grade < 73:
            return "C-"
        elif 67 <= grade < 70:
            return "D+"
        elif 63 <= grade < 67:
            return "D"
        elif 60 <= grade < 63:
            return "D-"
        elif 0 <= grade < 60:
            return "F"
        else:
            print("Grade cannot be lower than zero!")

#The following returns a certain message based on the letterGrade parameter
def message(letterGrade):
    try:
        "x" + letterGrade
    except TypeError:
        print("Parameter must be a string")
    else:
        if letterGrade == "A+":
            return "Fantastic!!!"
        elif letterGrade == "A" or letterGrade == "A-":
            return "Excellent!"
        elif letterGrade == "B+":
            return "Great!"
        elif letterGrade == "B" or letterGrade == "B-" or letterGrade == "C+":
            return "Good job!"
        elif letterGrade == "C" or letterGrade == "C-":
            return "Almost there! Ask some questions and you'll knock it out of the" + \
                   " park next time!"
        elif letterGrade == "D+" or letterGrade == "D" or \
             letterGrade == "D-" or letterGrade == "F":
            return "This assignment didn't reflect your best work. You can do better!"
        else:
            print("letterGrade parameter has no valid input!")

#The following makes sure to get an integer input
def getInt(message):
    while True:
        try:
            userInput = int(input(message))
        except ValueError:
            print("Invalid input, try again")
        else:
            return userInput

#The following asks for an output file and opens it,
#Asks how many questions the quiz will have,
#Uses a loop to ask the user to enter a question, enter the first choice, second, third,
#fourth, enter the number correct choice, writes the results to the output file in a
#comma separated format, and writes "\n" after each question,
#And Closes the output file & thanks the user
def makeQuiz():
    outputFileName = input("Enter an output file: ")
    outputFile = open(outputFileName, "w", encoding="utf-8")
    questionNum = getInt("Enter the number of questions the quiz will have: ")
    sequence = 0
    while questionNum < 1:
        print("You must enter an integer greater than 0")
        questionNum = getInt("Enter the number of questions the quiz will have: ")
    while int(questionNum) > 0:
        sequence = sequence + 1
        print("Question number " + str(sequence) + ": ")
        questionNum = int(questionNum) - 1
        question = input("Enter the question: ")
        choice1 = input("Enter the first choice: ")
        choice2 = input("Enter the second choice: ")
        choice3 = input("Enter the third choice: ")
        choice4 = input("Enter the fourth choice: ")
        correctChoice = input("Enter the number of the correct choice: ")
        outputFile.write(question + ",")
        outputFile.write(choice1 + "," + choice2 + "," + choice3 + "," + choice4 + ",")
        outputFile.write(correctChoice)
        outputFile.write("\n")
    outputFile.close()
    print("Thank you for using my program!")

#The following asks the user for a quiz file,
#Creates variables to hold total num of questions and num user got correct,
#For each question, it asks the user the question, lists the choices, asks their answer,
#tells user if they're right or wrong,
#Closes the file, displays how many questions user got correct, prints grade letter,
#prints a message for that grade letter
def takeQuiz():
    inputFileName = input("Enter a Quiz file: ")
    inputFile = open(inputFileName, "r", encoding="utf-8")
    questionNum = 0
    questionsCorrect = 0
    for line in inputFile:
        questionNum = questionNum + 1
        questionList = line.split(",")
        print(questionList[0])
        print("1. " + questionList[1])
        print("2. " + questionList[2])
        print("3. " + questionList[3])
        print("4. " + questionList[4])
        userInput = getInt("What is your choice? ")
        while userInput < 1 or userInput > 4:
            print("You must enter an integer between 1 and 4")
            userInput = getInt("What is your choice? ")
        if userInput == int(questionList[5]):
            print("Correct!")
            questionsCorrect = questionsCorrect + 1
        else:
            print("Incorrect! The answer was " + questionList[5])
    inputFile.close()
    print("You got " + str(questionsCorrect) + " questions correct")
    print(questionNum)
    letterGrade = gradeLetter(questionNum, questionsCorrect)
    print(message(letterGrade))

#The following will print a menu,
#Ask the user for their choice,
#Call makeQuiz() if user picks Make a Quiz, call takeQuiz() for Take a Quiz, and say Goodbye
#if the user picks exit
def menu():
    print("a. Make a Quiz \nb. Take a Quiz \nc. Exit ")
    userInput = input("Choose an option: ")
    while userInput.upper() != "C":
        if userInput.upper() == "A":
            makeQuiz()
            print("a. Make a Quiz \nb. Take a Quiz \nc. Exit ")
            userInput = input("Choose an option: ")
        elif userInput.upper() == "B":
            takeQuiz()
            print("a. Make a Quiz \nb. Take a Quiz \nc. Exit ")
            userInput = input("Choose an option: ")
        else:
            print("You must enter an option a b or c!")
            userInput = input("Choose an option: ")
    print("Goodbye")

def gradeLetterTest():
    assert gradeLetter(100,59) == "F"
    assert gradeLetter(100,99) == "A+"

def messageTest():
    assert message("A+") == "Fantastic!!!"
    assert message("F") == "This assignment didn't reflect your best work. You can do better!"