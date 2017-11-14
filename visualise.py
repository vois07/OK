import sys
import Tkinter
import numpy as np
import matplotlib.patches as mpatch
import matplotlib.pyplot as plt

n = int(sys.argv[1])
m = int(sys.argv[2])
f = open('wyniki/solution' + str(n) + '_' + str(m))
lines = f.readlines()

cmax = int(lines[-1])
lines = lines[2:-1]

plt.figure(figsize=(300,m))
ax = plt.gca()

rectangles = {}
for line in lines:
	line = line.split()
	rectangles.update({str(line[2]) : mpatch.Rectangle((int(line[1]), int(line[0])), int(line[4]), 1, facecolor='blue',edgecolor='black')})

for r in rectangles:
    ax.add_artist(rectangles[r])
    rx, ry = rectangles[r].get_xy()
    cx = rx + rectangles[r].get_width()/2.0
    cy = ry + rectangles[r].get_height()/2.0
    ax.annotate(r, (cx, cy), color='w', 
                fontsize=10, ha='center', va='center')



plt.yticks(range(m+1))
plt.xlabel('CZAS')
plt.ylabel('PROCESORY')
plt.tick_params(axis='both',direction='out', top=True,right=True)
plt.xlim(0,cmax)
plt.ylim(0,m)
plt.show()
#plt.savefig('myplot.pdf')


