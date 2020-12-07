import scipy
from scipy.integrate import quad

def f(x):
    return x * (1 - x * x)

# quad() is a function that calculate definite integrals.
# It returns an evaluated value of the integral and estimated absolute error.
# https://docs.scipy.org/doc/scipy/reference/generated/scipy.integrate.quad.html
I = quad(f, 0, 1)

# The output contains the value of the definite integral and the estimated precision
print(I)