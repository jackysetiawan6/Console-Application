import numpy as np
import matplotlib.pyplot as plt
import sympy as sp


mX = [
    [[10, 2, -6], [-1, 4, 2], [2, 3, 6]],
    [[-5, 2, -8], [4, -3, -9], [-8, -10, 9]],
    [[10, -5, 3, 0], [3, -9, 2, -2], [-8, 0, 17, -4], [3, -3, -8, -15]],
]
mY = [[17, -4, -12], [13, -7, -2], [9, 10, -10, -18]]
lx = [1, 5, 7, 2, 3, 9, 10, 4, 6, 8]
ly = [34, 51, 80, 25, 90, 76, 100, 11, 45, 62]


print()
print('=============================== Question 1 ===============================')
print()


def isDiagonallyDominant(x):
    x = np.array(x)
    nondiag_array = x[~np.eye(x.shape[0], dtype=bool)].reshape(x.shape[0], -1)
    for i in range(len(x)):
        print(f'Diagonal {i + 1} = {abs(x[i][i])}')
        nondiag_sum = sum([abs(x) for x in nondiag_array[i]])
        print('Total of not diagonal value =',
              ' + '.join(f'|{x}|' for x in nondiag_array[i]), '=', nondiag_sum)
        if abs(x[i][i]) > nondiag_sum:
            print(f'{abs(x[i][i])} > {nondiag_sum}')
        else:
            print(f'Because {abs(x[i][i])} < {nondiag_sum},', end=' ')
            print('The equation is not Diagonally Dominant!')
            return
        if i == len(x) - 1:
            print('This equation is Diagonally Dominant!')


for i, x in enumerate(mX):
    print(f'Equation {i + 1} Array X')
    isDiagonallyDominant(x)
    print()


print('=============================== Question 2 ===============================')
print()


def checkDiagonallyDominant(x):
    x = np.array(x)
    diagonal = np.diag(np.abs(x))
    sumWithoutDiag = np.sum(np.abs(x), axis=1) - diagonal
    if np.all(diagonal > sumWithoutDiag):
        return True
    return False


def gaussSeidel(x, y, max, tolerance):
    x = np.array(x)
    y = np.array(y)
    diagonal = np.diag(x)
    x = -x
    np.fill_diagonal(x, 0)
    xBefore = np.zeros(x.shape[1])
    for i in range(x.shape[0]):
        row = [f'({x[i, j]}X{j + 1})' for j in range(x.shape[1]) if i != j]
        print(f"X{i} = ({y[i]} + {' + '.join(row)} ) / {diagonal[i]}")
    for i in range(max):
        xAfter = np.array(xBefore)
        for j, row in enumerate(x):
            xAfter[j] = (y[j] + np.dot(row, xAfter)) / diagonal[j]
        print(f'Iteration: {i + 1}|  ', end='')
        for j in range(len(xAfter)):
            print(f'X{j + 1} = {xAfter[j]:.8f}', end='')
            print(j == len(xAfter) - 1 and '\n' or ', ', end='')
        distance = np.sqrt(np.dot(xAfter - xBefore, xAfter - xBefore))
        if i == max - 1:
            print()
            if distance < tolerance:
                print('Converged!\nResult:')
                for j in range(len(xAfter)):
                    print(f'X{j + 1} = {xAfter[j]:.8f}')
            else:
                print('Not Converged! Need more iteration!')
            return True
        xBefore = xAfter
    return False


for i, (x, y) in enumerate(zip(mX, mY)):
    print('Equation', i + 1)
    if checkDiagonallyDominant(x):
        print('This equation is Diagonally Dominant!')
        gaussSeidel(x, y, 5, 0.01456)
    else:
        print('Not Diagonally Dominant!')
    print()


print('=============================== Question 3 ===============================')
print()


lx = np.array(lx)
ly = np.array(ly)
A = np.array(np.vstack([lx, np.ones(len(lx))]).T)
Y = ly[:, np.newaxis]
inversed = np.linalg.inv(np.dot(A.T, A))
beta = np.dot(np.dot(inversed, A.T), Y)
regression = beta[0] * lx + beta[1]
plt.figure(figsize=(12, 8))
plt.title('The Best Least Square Regression')
plt.xlabel('X')
plt.ylabel('Y')
plt.plot(lx, ly, 'go')
plt.plot(lx, regression, 'b-')
plt.legend(['(x, y) Point', 'Least Square Regression'])
plt.show()
print('Done')


print()
print('=============================== Question 4 ===============================')
print()


x = sp.Symbol('x')


def f1(x): return 7*x**4 - 3*x**2 + x


def f2(x): return 8*x**6 + 5*x**4 - 2


df1 = sp.diff(f1(x), x)
df1 = sp.lambdify(x, df1, 'numpy')
df2 = sp.diff(f2(x), x)
df2 = sp.lambdify(x, df2, 'numpy')


def newtonRaphson(f, df, x0, tolerance=0.006541, max=5):
    if max == 0:
        print('With current iteration, the root is not found')
        return False
    if np.abs(f(x0)) < tolerance:
        print(f'The Root: {x0:.15f}')
        return True
    else:
        xNew = x0 - f(x0) / df(x0)
        print(f'Iteration {5 - max + 1}, root: {xNew:.15f}')
        return newtonRaphson(f, df, xNew, tolerance, max - 1)


print(f'Equation 1:')
print('f(x) = 7x^4 - 3x^2 + x')
print("f'(x)=28x ^ 3 - 6x + 1")
newtonRaphson(f1, df1, 1)
print()
print(f'Equation 2:')
print('f(x) = 8x^6 + 5x^4 - 2')
print("f'(x)=48x ^ 5 + 20x ^ 3")
newtonRaphson(f2, df2, 1)


print()
print('=============================== Question 5 ===============================')
print()


def f(x): return 3*x**4 - 7*x**2 + 5


lower = -4
upper = 3
n = 30
boxWidth = (upper - lower) / (n - 1)
x = np.linspace(lower, upper, n)
xLeft = x[:-1]
yLeft = f(xLeft)
leftRiemann = boxWidth * np.sum(np.abs(yLeft))
print('Left Riemann Sum  = %.10f' % leftRiemann)
xRight = x[1:]
yRight = f(xRight)
rightRiemann = boxWidth * np.sum(np.abs(yRight))
print('Right Riemann Sum = %.10f' % rightRiemann)
xMid = (xLeft + xRight) / 2
yMid = f(xMid)
midRiemann = boxWidth * np.sum(np.abs(yMid))
print('Mid Riemann Sum   = %.10f' % midRiemann)
print()
trapezoid = boxWidth * np.sum(np.abs(yLeft + yRight) / 2)
print('Trapezoid Sum     = %.10f' % trapezoid)
