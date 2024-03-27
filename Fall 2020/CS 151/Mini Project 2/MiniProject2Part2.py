#Dawson Tolbert
#Mini Project 2
#Sources: N/A

#Part 2
inputFileName = input("Please enter an input file: ")
outputFileName = input("Please enter an output file: ")

inputFile = open(inputFileName, "r", encoding="utf-8")
outputFile = open(outputFileName, "w", encoding="utf-8")

header = inputFile.readline()
outputFile.write(header)
outputFile.write("\n")

for line in inputFile:
    wordType = line.find("(")
    wordReplacement = line[int(wordType):]
    newWord = input("Please enter a " + wordReplacement)
    wordFill = line.replace("*", newWord)
    wordFillStop = wordFill.find("(")
    newSentence = wordFill[:int(wordFillStop)]
    outputFile.write(newSentence)
    outputFile.write("\n")
    
inputFile.close()
outputFile.close()

outputFile = open(outputFileName, "r", encoding="utf-8")
outputFileRead = outputFile.read()
print(outputFileRead)
outputFile.close()