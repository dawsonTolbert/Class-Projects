#Dawson Tolbert
#Guided Exercise 9
#Sources: N/A

"""
This program is broken.
When working, it should process a payroll input file
and output the results to another file

When ran on debugInput.txt, it should have the following lines in the output file:
bruce,wayne,40,Regular,350.0
selina,kyle,56,Overtime,640.0
"""

def getFileName(inOrOut):
    if inOrOut == "in":
        return input("What is the input file name?")
    elif inOrOut == "out":
        return input("What is the output file name?")
    else:
        return "Error"

def processLine(line):
    employeeInfo = line.split(",")
    last = employeeInfo[0]
    first = employeeInfo[1]
    payRate = float(employeeInfo[2])
    totalHours = processDays(employeeInfo[3:10])
    overTime = determineOverTime(totalHours)
    pay = determinePay(overTime, totalHours, payRate)
    return formatOutput(first,last,totalHours,overTime,pay)
    
def processDays(days):
    total = 0
    for day in days:
        total = total + int(day)
    return total

def determineOverTime(total):
    if total <= 40:
        return False
    else:
        return True

def determinePay(overTime,total,payrate):
    if overTime == False:
        return total * payrate
    else:
        return (40 * payrate) + ((total - 40) * (1.5 * payrate))

def formatOutput(first,last,totalHours,overTime,pay):
    output = first + "," + last + ","
    output = output + str(totalHours) + ","
    if overTime == True:
        output = output + "Overtime" + ","
    elif overTime == False:
        output = output + "Regular" + ","
    else:
        output = output + "ERROR" + ","
    output = output + str(pay)
    return output
    
inputFileName = getFileName("in")
outputFileName = getFileName("out")
inputFile = open(inputFileName,"r", encoding="utf-8")
outputFile = open(outputFileName,"w", encoding="utf-8")
inputFile.readline()
for line in inputFile:
    result = processLine(line)
    outputFile.write(result)
    outputFile.write("\n")
inputFile.close()
outputFile.close()

def getFileNameTest():
    assert getFileName("in") == input("What is the input file name?")
    assert getFileName("out") == input("What is the output file name?")
def processLineTest():
    assert processLine("wayne,bruce,8.75,8,8,8,0,8,8,0") == \
           "bruce,wayne,40,Regular,350.0"
    assert processLine("kyle,selina,10.00,8,8,8,8,8,8,8") == \
           "selina,kyle,56,Overtime,640.0"
def processDaysTest():
    line = ["wayne","bruce",8.75,8,8,8,0,8,8,0]
    assert processDays(line[3:10]) == 40
def determineOverTimeTest():
    assert determineOverTime(40) == False
    assert determineOverTime(60) == True
    assert determineOverTime(0) == False
def determinePayTest():
    assert determinePay(False,2,2) == 4
    assert determinePay(True,2,2) == (40 * 2) + ((2 - 40) * (1.5 * 2))
def formatOutputTest():
    assert formatOutput("bruce","wayne",40,False,350.0) == "bruce,wayne,40,Regular,350.0"
    assert formatOutput("selina","kyle",56,True,640.0)== "selina,kyle,56,Overtime,640.0"