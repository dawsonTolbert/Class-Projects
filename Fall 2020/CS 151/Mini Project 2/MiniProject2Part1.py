#Dawson Tolbert
#Mini Project 2
#Sources: N/A

#Part 1
censusFileName = input("Please enter a census file: ")
outputFileName = input("Please enter an output file: ")

censusFile = open(censusFileName, "r", encoding="utf-8")
outputFile = open(outputFileName, "w", encoding="utf-8")
header = censusFile.readline()

for line in censusFile:
    stateList = line.split(",")
    state = stateList[0]
    statePop = int(stateList[1])
    totalBirths = int(stateList[2]) + int(stateList[3]) + int(stateList[4]) + \
                  int(stateList[5]) + int(stateList[6]) + int(stateList[7]) + \
                  int(stateList[8]) + int(stateList[9])
    totalDeaths = int(stateList[10]) + int(stateList[11]) + int(stateList[12]) + \
                  int(stateList[13]) + int(stateList[14]) + int(stateList[15]) + \
                  int(stateList[16]) + int(stateList[17])
    avgBirths = (totalBirths / 8)
    avgDeaths = (totalDeaths / 8)
    yearlyIncrease = (avgBirths - avgDeaths)
    estPop18 = (totalBirths + yearlyIncrease)
    estPop19 = (estPop18 + yearlyIncrease)
    estPop20 = (estPop19 + yearlyIncrease)
    popDiff = (statePop - estPop20)
    outputFile.write(state)
    outputFile.write(" ")
    outputFile.write(str(estPop18))
    outputFile.write(" ")
    outputFile.write(str(estPop19))
    outputFile.write(" ")
    outputFile.write(str(estPop20))
    outputFile.write(" ")
    outputFile.write(str(popDiff))
    outputFile.write("\n")
    
censusFile.close()
outputFile.close()