def vowelOrConsonant(letter):
    if letter == "a" or letter == "e" or letter == "i" or \
       letter == "o" or letter == "u":
        print("vowel")
    else:
        print("consonant")

def faceOnMoney(num):
    if num == 1:
        print("George Washington")
    elif num == 2:
        print("Thomas Jefferson")
    elif num == 5:
        print("Abraham Lincoln")
    elif num == 10:
        print("Alexander Hamilton")
    elif num == 20:
        print("Andrew Jackson")
    elif num == 50:
        print("Ulysses S. Grant")
    elif num == 100:
        print("Benjamin Franklin")
    else:
        print("invalid")

def saffirsimpson(mph):
    if mph > 157:
        print("Category 5")
    elif mph > 130:
        print("Category 4")
    elif mph > 111:
        print("Category 3")
    elif mph > 96:
        print("Category 2")
    elif mph > 74:
        print("Category 1")
    elif mph > 39:
        print("Tropical Storm")
    else:
        print("Tropical Depression")
