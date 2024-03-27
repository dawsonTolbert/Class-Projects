#Dawson Tolbert
#Mini Project 1

print("My name is Dawson and I am going to be a great programmer!")
userName = input("Please enter your name: ")

print("Hello,", userName, "!")

userNameLower = userName.lower()
nameLength = len(userName)
aCount = userNameLower.count("a")
eCount = userNameLower.count("e")
iCount = userNameLower.count("i")
oCount = userNameLower.count("o")
uCount = userNameLower.count("u")
vowelCount = aCount + eCount + iCount + oCount + uCount
consonantCount = nameLength - vowelCount

print(userName, "is", nameLength, "letters long, has", end=" ")
print(vowelCount, "vowels,", "and", consonantCount, "consonants.")

userAge = int(input("Enter your age: "))

print("You were", userAge - 5, "years old 5 years ago.")
print("You will be", userAge + 5, "years old in 5 years.")
blank1 = input("Please enter a plural noun: ")
blank2 = input("Please enter any word: ")
blank3 = input("Please enter a genre of music: ")
blank4 = input("Please enter an adjective: ")
blank5 = input("Please enter a car name: ")
blank6 = input("Please enter a verb: ")

print(userName, "owns 3", blank1, "and loves taking them on walks to the park.",
      userName, "likes to listen to music when they go to the park.", userName + 
      "'s favorite type of music is", blank2, blank3 + 
      ".", userName + "'s favorite song is called '" + blank4.capitalize(), blank5.capitalize() +
      "' by The", blank6.capitalize() + "s.")