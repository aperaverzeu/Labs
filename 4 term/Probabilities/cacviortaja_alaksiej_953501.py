from random import random
import matplotlib.pyplot as plt
import numpy as np
from scipy import stats

from ipywidgets import interact_manual, fixed

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

def get_point_M(variation_series: list) -> float:
    return sum(variation_series) / len(variation_series)

def get_point_D(variation_series: list) -> float:
    m = get_point_M(variation_series)
    s = 0
    for el in variation_series:
        s = s + ((el - m) ** 2)
    return s / (len(variation_series) - 1)

def print_point_M_D(n):
    ser = var_series(get_y, n)
    m = get_point_M(ser)
    d = get_point_D(ser)
    return m, d

# print('MC і Д')
# interact_manual(print_point_M_D, n=(2, 1000))

# count it on da paper
true_M = (
    ((11 * np.arctan(11)) / 18) -
    ((7 * np.arctan(7)) / 18) -
    ((np.log(122)) / 36) +
    (np.log(50) / 36)
)

true_D = 1.588380221 - (true_M ** 2)

def print_dif(n):
    m, d = print_point_M_D(n)
    return abs(true_M - m), abs(true_D - d)

print('2')
interact_manual(print_dif, n=(2, 1000))

def get_interval_M_know_D(variation_series: list, alpha):
    X = get_point_M(variation_series)
    delta = stats.norm.ppf(1 - (alpha/2)) * np.sqrt(true_D / len(variation_series))
    return X - delta, X + delta

def get_interval_M_unknow_D(variation_series: list, alpha):
    X = get_point_M(variation_series)
    delta = stats.t(df=len(variation_series)-1).ppf(1 - (alpha/2)) * np.sqrt(get_point_D(variation_series) / len(variation_series))
    return X - delta, X + delta

# print('3')
# interact_manual(get_interval_M_know_D, variation_series=fixed(var_series(get_y, 100)), alpha=(0.0, 1.0, 0.01))
# interact_manual(get_interval_M_unknow_D, variation_series=fixed(var_series(get_y, 100)), alpha=(0.0, 1.0, 0.01))

def get_interval_D_know_M(variation_series: list, alpha):
    n = len(variation_series)
    s = 0
    for el in variation_series:
        s = s + ((el - true_M) ** 2)
    return s / (stats.chi2.ppf(1 - (alpha / 2), df=n)), s / (stats.chi2.ppf(alpha / 2, df=n))

def get_interval_D_unknow_M(variation_series: list, alpha):
    k = len(variation_series) - 1
    S2 = get_point_D(variation_series)
    return k * S2 / (stats.chi2.ppf(1 - (alpha / 2), df=k)), k * S2 / (stats.chi2.ppf(alpha / 2, df=k))

# print('5')
# interact_manual(get_interval_D_know_M, variation_series=fixed(var_series(get_y, 100)), alpha=(0.0, 1.0))
# interact_manual(get_interval_D_unknow_M, variation_series=fixed(var_series(get_y, 100)), alpha=(0.0, 1.0))

def func(n):
    ser = var_series(get_y, n)
    x = [0.01*i for i in range(0, 101)]
    s1 = [get_interval_M_know_D(ser, i) for i in x]
    s2 = [get_interval_M_unknow_D(ser, i) for i in x]

    s1d = [s[0] for s in s1]
    s1u = [s[1] for s in s1]
    s2d = [s[0] for s in s2]
    s2u = [s[1] for s in s2]

    # plt.ylim(0.27, 0.37)
    plt.plot(x, s1d, 'cyan', linewidth=2)
    plt.plot(x, s1u, 'y', linewidth=2)

    plt.plot(x, s2d, 'r--')
    plt.plot(x, s2u, 'g--')

    plt.plot([0, 1], [true_M, true_M], '--')
    plt.plot([0, 1], [get_point_M(ser), get_point_M(ser)], '--')

    plt.show()

# print('Графікі 1')
# interact_manual(func, n=(2, 10000))

def func_D(n):
    ser = var_series(get_y, n)
    x = [0.01*i for i in range(0, 101)]
    s1 = [get_interval_D_know_M(ser, i) for i in x]
    s2 = [get_interval_D_unknow_M(ser, i) for i in x]

    s1d = [s[0] for s in s1]
    s1u = [s[1] for s in s1]
    s2d = [s[0] for s in s2]
    s2u = [s[1] for s in s2]

    # plt.ylim(0.27, 0.37)
    plt.plot(x[1:], s1d[1:], 'cyan', linewidth=2)
    plt.plot(x, s1u, 'y', linewidth=2)

    plt.plot(x[1:], s2d[1:], 'r--')
    plt.plot(x, s2u, 'g--')

    plt.plot([0, 1], [true_D, true_D], 'yellow--')
    # plt.plot([0, 1], [get_point_D(ser), get_point_D(ser)], '--')

    plt.show()

# print('Графікі 2')
# interact_manual(func_D, n=(2, 10000))


def plot_interval_know_M_N(probability):
    n = [i for i in range(5, 500)]
    l = []
    for k in n:
        samples = []
        for _ in range(1):
            ser = var_series(get_y, k)
            d, u = get_interval_M_know_D(ser, 1 - probability)
            samples.append(abs(u - d))
        l.append(sum(samples) / len(samples))
    plt.plot(n, l)
    plt.show()

def plot_interval_unknow_M_N(probability):
    n = [i for i in range(5, 500)]
    l = []
    for k in n:
        samples = []
        for _ in range(1):
            ser = var_series(get_y, k)
            d, u = get_interval_M_unknow_D(ser, 1 - probability)
            samples.append(abs(u - d))
        l.append(sum(samples) / len(samples))
    plt.plot(n, l)
    plt.show()

def plot_interval_know_D_N(probability):
    n = [i for i in range(5, 500)]
    l = []
    for k in n:
        samples = []
        for _ in range(1):
            ser = var_series(get_y, k)
            d, u = get_interval_D_know_M(ser, 1 - probability)
            samples.append(abs(u - d))
        l.append(sum(samples) / len(samples))
    plt.plot(n, l)
    plt.show()

def plot_interval_unknow_D_N(probability):
    n = [i for i in range(5, 500)]
    l = []
    for k in n:
        samples = []
        for _ in range(1):
            ser = var_series(get_y, k)
            d, u = get_interval_D_unknow_M(ser, 1 - probability)
            samples.append(abs(u - d))
        l.append(sum(samples) / len(samples))
    plt.plot(n, l)
    plt.show()

# print('Графікі 3')
# interact_manual(plot_interval_know_M_N, probability=(0.0, 1.0, 0.01))
# interact_manual(plot_interval_unknow_M_N, probability=(0.0, 1.0, 0.01))
# interact_manual(plot_interval_know_D_N, probability=(0.0, 1.0, 0.01))
# interact_manual(plot_interval_unknow_D_N, probability=(0.0, 1.0, 0.01))
