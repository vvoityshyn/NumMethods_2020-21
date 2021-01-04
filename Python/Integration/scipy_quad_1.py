import scipy
import math
from scipy.integrate import quad


def f(x):
    return x * math.exp(-x)

# quad() is a function that calculate definite integrals.
# It returns an evaluated value of the integral and estimated absolute error.
# https://docs.scipy.org/doc/scipy/reference/generated/scipy.integrate.quad.html
I = quad(f,  0, math.log(2))

# The output contains the value of the definite integral and the estimated precision
print("Definite integral approximation: ", I)

#The right answer
r = 0.5 * math.log(math.exp(1) / 2)
print("The right answer: ", r)

# The difference between the right answer and the approximation
i = I[0]
d = math.fabs(i - r)
print("Absolute vale of the difference: ", d)
