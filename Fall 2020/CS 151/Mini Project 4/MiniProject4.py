#Dawson Tolbert
#MiniProject 4
#Sources: N/A

import random

def rpsInput():
    userChoice = int(input("Enter 1 for Rock, 2 for Paper, or 3 for Scissors"))
    while userChoice < 1 or userChoice > 3:
        print("Error")
        userChoice = int(input("Enter 1 for Rock, 2 for Paper, or 3 for Scissors"))
    return userChoice

def rpsPlay():
    win=0
    loss=0
    tie=0
    play=1
    while play == 1:
        compChoice = random.randint(1,3)
        userChoice = rpsInput()
        if compChoice == 1:
            if userChoice == 1:
                print("Tie")
                tie = tie + 1
            elif userChoice == 2:
                print("Paper beats Rock, you win!")
                win = win + 1
            else:
                print("Rock beats scissors, you lose!")
                loss = loss + 1
        elif compChoice == 2:
            if userChoice == 1:
                print("Paper beats Rock, you lose!")
                loss = loss + 1
            elif userChoice == 2:
                print("Tie")
                tie = tie + 1
            else:
                print("Scissors beats paper, you win!")
                win = win + 1
        else:
            if userChoice == 1:
                print("Rock beats Scissors, you win!")
                win = win + 1
            elif userChoice == 2:
                print("Scissors beats paper, you lose!")
                loss = loss + 1
            else:
                print("Tie")
                tie = tie + 1
        play = int(input("Do you want to play again? 1 for yes 2 for no"))
    print("You had " + str(loss) + " losses, " + str(tie) + 
          " ties, and " + str(win) + " wins.")

#Part 2
def pigPlay():
    player1Score = 0
    player2Score = 0
    while player1Score < 100 and player2Score < 100:
        print("Player 1: " + str(player1Score) +
              "\nPlayer 2: " + str(player2Score))
        player1Turn = pigTurn("Player 1")
        player1Score = player1Score + player1Turn
        player2Turn = pigTurn("Player 2")
        player2Score = player2Score + player2Turn
    if player1Score or player2Score > 100:
        if player1Score >= 100:
            print("Player 1 wins")
        else:
            print("Player 2 wins")
    else:
        pass

def pigTurn(player):
    print(player + " turn")
    dice = random.randint(1,6)
    score = 0
    while dice != 1:
        print("Dice rolls: " + str(dice))
        score = score + dice
        userInput = input("ROLL or HOLD?")
        if userInput.lower() == "roll":
            dice = random.randint(1,6)
        elif userInput.lower() == "hold":
            return score
        else:
            print("Invalid input!")
            return 0
    return 0