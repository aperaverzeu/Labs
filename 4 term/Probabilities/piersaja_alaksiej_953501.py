from random import random

import matplotlib.pyplot as plt
import numpy as np

from ipywidgets import interact

mX = 2
sigmaX = 3 * np.sqrt(3)
y0 = 2

# (a+b)/2 = mX, (b-a)/sqrt(12) = sigmaX
a = -7
b = 11

def fi(x):
    return np.arctan(x)

def ksi(y):
    return np.tan(y)

def get_x():
    return random() * (b - a) + a

def get_y():
    return fi(get_x())

def var_series(get_var_series, n) -> list:
    """
    :param get_var_series: func return random value
    :param n: number of elements
    :return: variation series
    """

    l = []

    for i in range(n):
        l.append(get_var_series())

    l.sort()
    return l

def plot_empirical_distribution_func(variation_series: list):
    y = []
    n = len(variation_series)
    for i in range(n):
        y.append(i / n)
    plt.step(variation_series, y)

def func(n):
    plot_empirical_distribution_func(var_series(get_y, 100))
    plt.show()