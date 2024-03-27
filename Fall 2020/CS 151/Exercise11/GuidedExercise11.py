#Dawson Tolbert
#Guided Exercise 11
#Sources: N/A

import string

def removePunctuation(text):
    text = text.strip()
    return text.rstrip(string.punctuation)

#FIX
def getCorrectWords():
    words = set()
    file = open("correctWords.txt", "r", encoding="utf-8")
    for line in file:
        words.add(line.strip())
    file.close()
    return words

def spellCheck():
    correctWords = getCorrectWords()
    fileName = input("Enter a file name: ")
    file = open(fileName, "r", encoding="utf-8")
    for line in file:
        fileList = line.split(" ")
        for word in fileList:
            if removePunctuation(word.lower()) not in correctWords:
                print(removePunctuation(word))
            else:
                pass

def characterCount():
    userInput = input("Enter a string: ")
    string = userInput.lower()
    empty = {}
    for letter in string:
        if letter in empty:
            empty[letter] = empty[letter] + 1
        else:
            empty[letter] = 1
    for item in empty:
        print(item, empty[item])