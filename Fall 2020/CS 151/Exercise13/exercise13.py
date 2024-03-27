#Dawson Tolbert
#Guided Exercise 13
#Sources: N/A

import matplotlib.pyplot as plt

months = ["January","February","March","April","May","June","July","August","September",\
          "October","November","December"]
avgHighTemps = [40,43,62,63,70,77,80,79,73,63,53,43]
avgLowTemps = [21,22,29,38,47,55,59,58,51,39,30,24]

plt.xlabel("Months")
plt.ylabel("Temperatures")
plt.title("Average Temps in Princeton, WV")
plt.scatter(months,avgHighTemps,label="high")
plt.scatter(months,avgLowTemps,label="low")
plt.legend()
plt.show()