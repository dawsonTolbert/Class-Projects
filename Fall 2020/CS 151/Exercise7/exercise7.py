#Dawson Tolbert
#Guided Exercise 7
#Sources: N/A

counter = 1
while counter < 11:
    print(counter)
    counter = counter + 1
print("Goodbye")
#This prints 0, then 1, then goodbye

def whileName(name):
    num = 0
    while num < 10:
        print(name)

def forName(name):
    for item in range(0,10):
        print(name)

def evens():
    num = input("Enter a number: ")
    for item in range(1, int(num)):
        if item % 2 == 0:
            print(item)
        else:
            pass

def countDown(num):
    while num > 0:
        print(num)
        num = num - 1
    print("BLAST OFF!!!")

def whileBottles(num):
    while num > 0:
        if num > 1:
            print(str(num) + " bottles of beer on the wall, " + str(num) + " bottles of beer," \
                  "take it down,pass it around")
            num = num - 1
            print(str(num) + " bottles of beer on the wall.")
        else:
            print(str(num) + " bottle of beer on the wall, " + str(num) + " bottles of beer," \
                  "take it down,pass it around")
            num = num - 1
    print("no more bottles of beer on the wall!")

def whileBadger(num):
    numMod = 1
    while numMod <= num:
        if numMod % 3 == 0 and numMod % 5 == 0:
            print("SNAKE!!!!")
        elif numMod % 3 == 0:
            print("Badger")
        elif numMod % 5 == 0:
            print("Mushroom")
        else:
            print(str(numMod))
        numMod = numMod + 1

def forBadgers(num):
    numMod = 1
    for item in range(0,num):
        if numMod % 3 == 0 and numMod % 5 == 0:
            print("SNAKE!!!!")
        elif numMod % 3 == 0:
            print("Badger")
        elif numMod % 5 == 0:
            print("Mushroom")
        else:
            print(str(numMod))
        numMod = numMod + 1