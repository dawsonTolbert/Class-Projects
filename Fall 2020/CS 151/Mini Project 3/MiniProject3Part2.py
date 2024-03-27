#Dawson Tolbert
#Mini Project 2
#Sources: N/A

def getChoice():
    return input("Enter your choice: ")

def invalidInput():
    print("Sorry, invalid input! You trip and can no longer move. Game over!")

def location(x):
    if x == "a1":
        a1()
    elif x == "a2":
        a2()
    elif x == "a3":
        a3()
    elif x == "b1":
        b1()
    elif x == "b2":
        b2()
    elif x == "b3":
        b3()
    elif x == "b4":
        b4()
    elif x == "c1":
        c1()
    elif x == "c2":
        c2()
    elif x == "c3":
        c3()
    else:
        print("You've hit a wall!")
        if x == "walla1":
            a1()
        elif x == "walla2":
            a2()
        elif x == "walla3":
            a3()
        elif x == "wallb1":
            b1()
        elif x == "wallc1":
            c1()
        elif x == "wallc2":
            c2()
        elif x == "wallc3":
            c3()
        else:
            print("Broke it :/")

def direction(N,W,S,E):
    print("Choose a direction to travel (N/W/S/E)")
    choice = getChoice()
    if choice.upper() == "N":
        location(N)
    elif choice.upper() == "W":
        location(W)
    elif choice.upper() == "S":
        location(S)
    elif choice.upper() == "E":
        location(E)
    else:
        invalidInput()

#Starting scenario
def start():
    print("You wake up in a cold, dark ROOM")
    print("You look out the windows to see the silhouette of a densely packed" + \
          " forest surrounding you entirely")
    room()

def room():
    print("There's a pile of wood with a matchbox in the middle of the ROOM")
    print("Press 1 to light a fire")
    print("Press 2 to leave the ROOM")
    choice = int(getChoice())
    if choice == 1:
        lightFire()
    elif choice == 2:
        leave()
    else:
        invalidInput()

def lightFire():
    print("You strike a match and light a fire")
    print("The ROOM lights up and you begin to feel warm")
    roomFire()

def roomFire():
    print("Press 1 to stay in the ROOM")
    print("Press 2 to leave")
    choice = int(getChoice())
    if choice == 1:
        stayFire()
    elif choice == 2:
        leaveFire()
    else:
        invalidInput()

def stayFire():
    print("You stay in the ROOM with the fire")
    print("You know you shouldn't stay long")
    roomFire()

def leave():
    print("You decide to leave the ROOM")
    print("Forest surrounds you on all sides")
    print("It is too dark for you to see")
    outside()

def outside():
    print("Press 1 to return to the room")
    print("Press 2 to stay outside")
    choice = int(getChoice())
    if choice == 1:
        print("You return to the ROOM")
        room()
    elif choice == 2:
        print("You stay outside")
        print("It's dark and cold")
        outside()
    else:
        invalidInput()
    

def leaveFire():
    print("You decide to leave the ROOM in the woods with a torch in hand")
    print("Forest surrounds you on all sides")
    direction("a2","b1","c2","b3")
    
def forest():
    print("You travel deeper into the forest")
    print("You come across nothing of interest")

#Grid Locations
def a1():
    def caveStay():
        stay = input("Stay in the CAVE? ")
        if stay.upper() == "YES":
            print("You stay in the CAVE")
            print("It's cold and wet")
            caveStay()
        else:
            print("You leave the CAVE")
            direction("walla1","walla1","b1","a2")
    print("You come across a large, dark CAVE")
    cave = input("Enter the CAVE? ")
    if cave.upper() == "YES":
        print("You enter the dark CAVE")
        print("It's cold and wet")
        caveStay()
    else:
        direction("walla1","walla1","b1","a2")

def a2():
    def cabinStay():
        stay = input("Stay in the CABIN? ")
        if stay.upper() == "YES":
            print("You stay in the CABIN")
            print("You feel warm and safe")
            cabinStay()
        else:
            print("You leave the CABIN")
            direction("walla2","a1","b2","a3")
    print("You find an old CABIN")
    print("It looks as if nobdy's used it in years")
    cabin = input("Enter the CABIN? ")
    if cabin.upper() == "YES":
        print("You enter the CABIN")
        print("It's surprisingly cozy inside")
        cabinStay()
    else:
        direction("walla2","a1","b2","a3")

def a3():
    forest()
    direction("walla3","a2","b3","walla3")

def b1():
    forest()
    direction("a1","wallb1","c1","b2")

def b2():
    def roomStay():
        stay = input("Stay in the ROOM? ")
        if stay.upper() == "YES":
            print("You stay in the ROOM")
            print("You feel warm")
            roomStay()
        else:
            print("You leave the ROOM")
            direction("a2","b1","c2","b3")
    print("You're back at the building you started in")
    print("The fire is still lit inside")
    room = input("Enter the ROOM? ")
    if room.upper() == "YES":
        print("You enter the ROOM")
        print("It's warm inside, but you know you shouldn't stay long")
        roomStay()
    else:
        direction("a2","b1","c2","b3")

def b3():
    print("You see an opening through the trees to the EAST")
    direction("a3","b2","c3","b4")

def b4():
    print("You exit the forest onto an old road")
    print("Soon after, you see a car and flag it down")
    print("You've made your way out of the forest")
    print("Thanks for playing!")

def c1():
    forest()
    direction("b1","wallc1","wallc1","c2")

def c2():
    forest()
    direction("b2","c1","wallc2","c3")

def c3():
    print("You come across a WELL")
    wish = input("Make a wish? ")
    if wish.upper() == "YES":
        print("You toss a coin into the WELL and make a wish")
        direction("b3","c2","wallc3","wallc3")
    else:
        direction("b3","c2","wallc3","wallc3")

#Run
start()