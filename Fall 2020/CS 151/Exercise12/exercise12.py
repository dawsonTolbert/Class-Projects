class Date:
    def __init__(self,month,day,year):
        self.month = month
        self.day = day
        self.year = year
    def dash(self):
        print(str(self.month), "-", str(self.day), "-", str(self.year))
    def slash(self):
        print(str(self.month), "/", str(self.day), "/", str(self.year))
    def comma(self):
        if self.month == 1:
            self.month = "January"
        elif self.month == 2:
            self.month = "February"
        elif self.month == 3:
            self.month = "March"
        elif self.month == 4:
            self.month = "April"
        elif self.month == 5:
            self.month = "May"
        elif self.month == 6:
            self.month = "June"
        elif self.month == 7:
            self.month = "July"
        elif self.month == 8:
            self.month = "August"
        elif self.month == 9:
            self.month = "Spetember"
        elif self.month == 10:
            self.month = "October"
        elif self.month == 11:
            self.month = "November"
        else:
            self.month = "December"
        print(self.month + ",", str(self.day) + ",", str(self.year))

class Point:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def increaseX(self):
        self.x = self.x + 1
    def increaseY(self):
        self.y = self.y + 1
    def decreaseX(self):
        self.x = self.x - 1
    def decreaseY(self):
        self.y = self.y - 1
    def toString(self):
        return "(" + str(self.x) + "," + str(self.y) + ")"

class Turtle:
    def __init__(self):
        self.location = Point(0,0)
    def up(self):
        self.location.decreaseY()
    def down(self):
        self.location.increaseY()
    def right(self):
        self.location.increaseX()
    def left(self):
        self.location.decreaseX()
    def toString(self):
        return self.location.toString()

craig = Turtle()
craig.down()
craig.right()
craig.right()
craig.right()
craig.down()
craig.left()
craig.down()
craig.right()
craig.right()
craig.down()
craig.down()
craig.right()
print("craig at " + craig.toString())