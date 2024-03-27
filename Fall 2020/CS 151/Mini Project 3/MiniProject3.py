#Dawson Tolbert
#Mini Project 2
#Sources: N/A

print("Hello! Please answer the following questions to recieve your" \
      + " placement for student housing priority.")

creditHours = int(input("Enter the number of credit hours you have completed: "))
concordSeniority = input("Is this your first year at Concord? ")

if concordSeniority.lower() == "yes":
    year = 0
else:
    year = int(input("Enter the number year this is for you at Concord")) * 5

age = int(input("Enter your age: "))
if age >= 23:
    age = 5
else:
    age = 0
    
offCampCred = input("Do you have a full-time, off-campus credit program? ")
if offCampCred.lower() == "yes":
    offCampCred = 5
else:
    offCampCred = 0

disability = input("Do you have a disability? ")
if disability.lower() == "yes":
    disability = 20
else:
    disability = 0

acProbation = input("Have you been on academic probation? ")
if acProbation.lower() == "yes":
    acProbation = 5
else:
    acProbation = 0

suspension = input("Have you had academic suspension? ")
if suspension.lower() == "yes":
    suspension = 10
else:
    suspension = 0

disProbation = input("Have you been on disciplinary probation? ")
if disProbation.lower() == "yes":
    disProbation = 15
else:
    disProbation = 0

total = (creditHours + year + age + offCampCred + disability \
         - acProbation - suspension - disProbation ) / 10
print("You have received " + str(total) + " points out of 14 possible points.")