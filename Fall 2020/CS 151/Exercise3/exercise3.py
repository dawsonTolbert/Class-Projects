#Dawson Tolbert
#Guided Exercise 3
#Sources: N/A

userName = input("Please enter your name: ")
print(userName, "is going to be a great programmer!")

inputFileName = input("Please enter an input file name: ")
inputFile = open(inputFileName, "r", encoding="utf-8")
inputFileRead = (inputFile.read())
chapterCount = inputFileRead.count("Chapter")
dorothyCount = inputFileRead.count("Dorothy")
totoCount = inputFileRead.count("Toto")
ozCount = inputFileRead.count("Oz")
wizardCount = inputFileRead.count("Wizard")
magicCount = inputFileRead.count("Magic")
periodCount = inputFileRead.count(".")
questionCount = inputFileRead.count("?")
exclamationCount = inputFileRead.count("!")
sentenceCount = (periodCount + questionCount + exclamationCount)
wordCount = inputFileRead.count(" ") + 1
inputFile.close()
#I get an error saying "FileNotFoundError: [Errno 2] No such file or directory"
#if I enter a file name that does not exist.

outputFileName = input("Please enter an output file name: ")
outputFile = open(outputFileName, "w", encoding="utf-8")
outputFile.write("Hello ")
outputFile.write(userName)
outputFile.write("There are ")
outputFile.write(str(chapterCount))
outputFile.write(" chapters in the input file. \nDorothy is said ")
outputFile.write(str(dorothyCount))
outputFile.write(" times. \nToto is said ")
outputFile.write(str(totoCount))
outputFile.write(" times. \nOz is said ")
outputFile.write(str(ozCount))
outputFile.write(" times. \nWizard is said ")
outputFile.write(str(wizardCount))
outputFile.write(" times. \nMagic is said ")
outputFile.write(str(magicCount))
outputFile.write(" times. \n")
outputFile.write("There are ")
outputFile.write(str(sentenceCount))
outputFile.write(" sentences in the input file. \n")
outputFile.write("There are ")
outputFile.write(str(wordCount))
outputFile.write(" words in the input file. \n")

girlName = input("Please enter a girl's name: ")
inputFileReplacement = inputFileRead.replace("Dorothy", girlName)
outputFile.write(inputFileReplacement)
outputFile.close()