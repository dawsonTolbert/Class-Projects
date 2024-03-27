#Dawson Tolbert
#Guided Exercise 5
#Sources:N/A

def phone():
    print("Ring Ring")
    
def voiceMail():
    print("You have reached the voice mail of NAME HERE. " + \
          "At the tone, please record your message.")
    
def noAnswer():
    phone()
    phone()
    phone()
    phone()
    voiceMail()

def happyBirthday(name):
    print("Happy Birthday to you \n" + \
          "Happy Birthday to you \n" + \
          "Happy Birthday dear", name, "\n" + \
          "Happy Birthday to you")
    
def introduction(name1, name2):
    print("Hello", name1 + ", have you met", name2 + "?")

def cube(num):
    return num * num * num

def getFloat():
    userInput = float(input("Please enter a float: "))
    return userInput

def lbsToKg(lbs):
    return lbs * 0.453592
