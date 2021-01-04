from numpy import *
from scipy.integrate import trapz
import matplotlib.pyplot as plt

def f(x):
    return x * math.exp(-x)

a = 0
b = math.log(2)
n = 300
h = (b - a) / n

x = arange(a, b + h, h)
#print(x)

y = []
for xi in x:
    y.append(f(xi))

#print(y)

I = trapz(y, x = x)
print(I)

#The right answer
r = 0.5 * math.log(math.exp(1) / 2)
print("The right answer: ", r)

# The difference between the right answer and the approximation
d = math.fabs(I - r)
print("Absolute vale of the difference: ", d)

# setting the axes at the centre
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
ax.spines['left'].set_position('center')
ax.spines['bottom'].set_position('zero')
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')

plt.plot(x,y, 'r')
plt.show()