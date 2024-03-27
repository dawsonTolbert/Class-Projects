#Dawson Tolbert
#Guided Exercise 4
#Sources: N/A

inputFileName = input("Enter a filename containing discGolf data: ")
outputFileName = input("Enter an output file: ")

inputFile = open(inputFileName, "r", encoding="utf-8")
outputFile = open(outputFileName, "w", encoding="utf-8")
header = inputFile.readline()
par = int(inputFile.readline())
line3 = inputFile.readline()

for line in inputFile:
    playerList = line.split(",")
    player = playerList[0]
    total = (int(playerList[1])) + (int(playerList[2])) + (int(playerList[3])) + \
            (int(playerList[4])) + (int(playerList[5])) + (int(playerList[6])) + \
            (int(playerList[7])) + (int(playerList[8])) + (int(playerList[9]))
    difference = total - par
    playerData = player, str(total), str(difference)
    outputFile.write(player)
    outputFile.write(" ")
    outputFile.write(str(total))
    outputFile.write(" ")
    outputFile.write(str(difference))
    outputFile.write("\n")

inputFile.close()
outputFile.close()