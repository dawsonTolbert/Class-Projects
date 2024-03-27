#Dawson Tolbert
#Guided Exercise 13
#Sources: N/A

"""
Make it use easygui instead of the shell
Look for the comments that tell you where to change things
"""
import random
from easygui import * 

"""
compChoice returns a string containing one of rock, paper, or scissors
There's no user input or output so nothing needs to change
"""
def compChoice():
    #1 is rock, 2 is paper, 3 is scissors
    compNum = random.randint(1,3)
    
    if compNum == 1:
        return "rock"
    elif compNum == 2:
        return "paper"
    elif compNum == 3:
        return "scissors"
    else:
        return "error"

"""
userChoice - this function needs changed
           - you can use enterbox and leave the error checking
           - or you can use buttonbox or choice box to avoid errors
"""
def userChoice():
    choice = enterbox("Enter R, P, or S: ","Choice").lower() 
    while choice != "r" and choice != "p" and choice != "s":
        print("Invalid Choice!")
        choice = input("Enter R, P, or S: ").lower()
    
    if choice == "r":
        return "rock"
    elif choice == "p":
        return "paper"
    elif choice == "s":
        return "scissors"
    else:
        return "error"
    
    return choice

"""
userQuit - this function needs changed
         - similar comments to userChoice()
"""
def userQuit():
    choice = enterbox("Do you want to quit, yes or no: ","Y/N").lower()
    
    while choice != "yes" and choice != "no":
        print("The choice must be yes or no!")
        choice = enterbox("Do you want to quit, yes or no: ","Y/N").lower()
    
    return choice

"""
determineResult - this function needs changed
                - all print statements should become msgbox
"""
def determineResult(computer, user):
    if computer == user:
        msgbox("It's a tie!")
        return "tie"
    elif computer == "rock" and user == "scissors":
        msgbox("Rock crushes scissors, you lose!")
        return "lose"
    elif computer == "rock" and user == "paper":
        msgbox("Paper covers rock, you win!")
        return "win"
    elif computer == "scissors" and user == "rock":
        msgbox("Rock crushes scissors, you win!")
        return "win"
    elif computer == "paper" and user == "rock":
        msgbox("Paper covers rock, you lose!")
        return "lose"
    elif computer == "paper" and user == "scissors":
        msgbox("Scissors cuts paper, you win!")
        return "win"
    elif computer == "scissors" and user == "paper":
        msgbox("Scissors cuts paper, you lose!")
        return "lose"
    else:
        return "unknown"

"""
RPSRound - this function needs changed
         - the print statement needs to be msgbox
"""
def RPSRound():
    computer = compChoice()
    user = userChoice()
    
    msgbox("The computer picked " + computer.title())
    
    result = determineResult(computer, user)
    
    return result

"""
RPS - this function needs changed
    - You can replace the "Something weird" line with msgbox
    - Try to see if you can display the wins, losses, and ties
       in a textbox (Hint: you need a big string, so think str()
       and concatenation)
"""
def RPS():
    wins = 0
    losses = 0
    ties = 0
    
    quitChoice = ""
    while quitChoice != "yes":
    
        result = RPSRound()
        
        if result == "win":
            wins = wins + 1
        elif result == "lose":
            losses = losses + 1
        elif result == "tie":
            ties = ties + 1
        else:
            msgbox("Something weird happened!")
        
        quitChoice = userQuit()
    
    msgbox("Wins: " + str(wins) + "\nLosses: " + str(losses) + "\nTies: " + str(ties))