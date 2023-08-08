import numpy as np
import matplotlib.pyplot as plt
import sympy as sp


Xs = [
    [[11, -5, -5], [-3, 5, 3], [1, 1, -4]],
    [[11, 3, 3, 3], [3, -10, -1, -4], [1, -1, -4, 1], [-2, -2, -2, 9]],
    [[5, 2, -1], [5, 10, -1], [3, 2, 9]],
    [[1, 0, 1], [2, 0, 2], [-3, -3, 0]],
    [[-10, 1, -2, 6], [-2, 18, -6, 6], [1, 3, -5, 0], [0, 0, -4, 9]]
]
Ys = [[10, 12, 3], [1, 2, 3, 5], [1, 4, 5], [5, 5, 5], [6, 7, 7, 18]]
X_3 = [0.0, 1.0204081632653061, 2.0408163265306123, 3.0612244897959187, 4.081632653061225, 5.1020408163265305, 6.122448979591837, 7.142857142857143, 8.16326530612245, 9.183673469387756, 10.204081632653061, 11.224489795918368, 12.244897959183675, 13.26530612244898, 14.285714285714286, 15.306122448979592, 16.3265306122449, 17.346938775510203, 18.367346938775512, 19.387755102040817, 20.408163265306122, 21.42857142857143, 22.448979591836736, 23.46938775510204, 24.48979591836735, 25.510204081632654, 26.53061224489796, 27.551020408163264, 28.571428571428573, 29.591836734693878, 30.612244897959183, 31.63265306122449, 32.6530612244898, 33.673469387755105, 34.69387755102041, 35.714285714285715, 36.734693877551024, 37.755102040816325, 38.775510204081634, 39.79591836734694, 40.816326530612244, 41.83673469387755, 42.85714285714286, 43.87755102040816, 44.89795918367347, 45.91836734693878, 46.93877551020408, 47.95918367346939,
       48.9795918367347, 50.0, 51.02040816326531, 52.04081632653061, 53.06122448979592, 54.08163265306123, 55.10204081632653, 56.12244897959184, 57.142857142857146, 58.16326530612245, 59.183673469387756, 60.204081632653065, 61.224489795918366, 62.244897959183675, 63.26530612244898, 64.28571428571429, 65.3061224489796, 66.3265306122449, 67.34693877551021, 68.36734693877551, 69.38775510204081, 70.40816326530613, 71.42857142857143, 72.44897959183673, 73.46938775510205, 74.48979591836735, 75.51020408163265, 76.53061224489797, 77.55102040816327, 78.57142857142857, 79.59183673469389, 80.61224489795919, 81.63265306122449, 82.6530612244898, 83.6734693877551, 84.6938775510204, 85.71428571428572, 86.73469387755102, 87.75510204081633, 88.77551020408164, 89.79591836734694, 90.81632653061224, 91.83673469387756, 92.85714285714286, 93.87755102040816, 94.89795918367348, 95.91836734693878, 96.93877551020408, 97.9591836734694, 98.9795918367347, 100.0]
Y_3 = [2.5, 3.55933621307185, 4.167412839663745, 5.4870429722510465, 11.142581417725042, 7.86148658509595, 8.401972333006611, 9.828467992887417, 31.307057919750108, 14.487456356941825, 22.83319024035356, 16.400329097580506, 21.479034784206526, 19.985882140432505, 20.641090566349014, 37.77579586787783, 123.8863753193097, 41.333316478014936, 33.062505624041606, 46.35459313128166, 58.55815336573507, 61.261072664917435, 46.82432197717539, 48.21441358359897, 182.12067628517886, 39.13249458832681, 31.583087596792414, 75.52415810170419, 66.61047739001538, 51.0430965557856, 68.85237329741663, 76.76403952069636, 231.26487535807007, 100.29746838907609, 87.06014111146378, 90.84702129315832, 40.110883802399634, 46.94383929303173, 102.89860145731792, 61.968940434607546, 275.7836188531819, 81.72897168265717, 126.118835003378, 99.09772282551512, 50.647759281016334, 94.15195434765812, 104.92396451650399, 94.84934261790684, 194.65028586201996, 78.2667123528214,
       103.61878662128069, 153.15477636422182, 147.92798294510132, 123.04102628923025, 106.81695335647566, 117.30947892491095, 216.63314041658765, 86.90563312921432, 124.97528489360292, 133.75961920461032, 155.14889047967364, 83.5041208350217, 189.70133039750226, 92.96066205804652, 355.4721804696095, 195.32902713953325, 199.05661898973221, 88.79516734635648, 193.5448921901416, 97.80723503682843, 110.001847510363, 204.6384599076647, 277.1647078716958, 107.66417975691705, 201.3472744993193, 172.5237857707939, 220.6940440988812, 194.45510831830995, 180.93229922697998, 118.82298788840303, 256.78361102914084, 139.58042767421273, 163.39374150736262, 150.325059539888, 172.209777077264, 134.01352766339596, 187.70564794009925, 150.9738004458431, 596.8564687997193, 222.81575803765577, 230.88151547263456, 191.36747694040469, 282.41831583842986, 204.51294576497344, 112.69991840587676, 107.92028976277088, 623.1850452707149, 156.3375556275594, 274.4347728556563]


print()
print('=============================== Question 1 ===============================')
print()


def check_diagonally_dominant(x):
    x = np.array(x)
    diagonal = np.diag(np.abs(x))
    sum_without_diag = np.sum(np.abs(x), axis=1) - diagonal
    if np.all(diagonal > sum_without_diag):
        return True
    return False


def gauss_seidel(x, y, max_iter, threshold):
    x = np.array(x)
    y = np.array(y)
    diagonal = np.diag(x)
    x = -x
    np.fill_diagonal(x, 0)
    initial = np.zeros(x.shape[1])
    for i in range(max_iter):
        result = np.array(initial)
        for j, row in enumerate(x):
            result[j] = (y[j] + np.dot(row, result)) / diagonal[j]
        print(f'iter:  {i} {result}')
        distance = np.sqrt(np.dot(result - initial, result - initial))
        if np.abs(distance) < threshold:
            print('covergent')
            return
        initial = result
    print('not convergent')
    return


for i, (arrayX, arrayY) in enumerate(zip(Xs, Ys)):
    print(f'A: {arrayX} y:{arrayY}')
    if check_diagonally_dominant(arrayX):
        gauss_seidel(arrayX, arrayY, 20, 0.044)
    else:
        print('not diagonally dominant')
    print()


print('=============================== Question 2 ===============================')
print()


a = [[11, 5, 3], [3, 7, 9], [5, 5, 10]]


def normalize(x):
    fac = abs(x).max()
    x_n = x / x.max()
    return fac, x_n


def power_method(matrix):
    lambda_1 = 0
    v = np.array([1, 1, 1])
    matrix = np.array(matrix)
    for i in range(12):
        v = np.dot(matrix, v)
        lambda_1, v = normalize(v)
    print('Eigenvalue :', lambda_1)
    print('Eigenvector:', v)
    return


def inverse_power_method(matrix):
    lambda_1 = 0
    v = np.array([1, 1, 1])
    matrix = np.array(matrix)
    for i in range(12):
        v = np.dot(np.linalg.inv(matrix), v)
        lambda_1, v = normalize(v)
    print('Eigenvalue :', lambda_1)
    print('Eigenvector:', v)
    return


print('Power Method')
power_method(a)
print()
print('Inverse Method')
inverse_power_method(a)


print()
print('=============================== Question 3 ===============================')
print()


m = 2.4604672316648633
c = 1.852571637762729
X = np.array(X_3)
Y = np.array(Y_3)
Y_pred = m * X + c
plt.figure(figsize=(12, 8))
plt.title('Least Square Regression Plot Result')
plt.xlabel('x')
plt.ylabel('y')
plt.plot(X, Y, 'b.')
plt.plot(X, Y_pred, 'r-')
plt.legend(['x y coordinates', 'Least Square Regression'])
plt.show()
print('Done')


print()
print('=============================== Question 4 ===============================')
print()


x = sp.symbols('x')


def f1(x): return 4*x**3 + 2


df1 = sp.diff(f1(x), x)
df1 = sp.lambdify(x, df1, 'numpy')


def newton_raphson(f, df, x0, max=30, tolerance=0.044):
    if max == 0:
        print('with current iteration, the root is not found')
        return
    if np.abs(f(x0)) < tolerance:
        print()
        print(f'The root of the equation is: {x0:.8f}')
        return
    else:
        x0 = x0 - (f(x0) / df(x0))
        print(f'Iteration-{30-max+1}, new root = {x0:.6f}')
        newton_raphson(f, df, x0, max-1, tolerance)
    return


newton_raphson(f1, df1, 3)


print()
print('=============================== Question 5 ===============================')
print()


x = sp.symbols('x')
coordinates = [[1, 5], [-3, 5], [-4, 3], [-2, 3], [6, -8]]


def f2(x): return x**3 - 3*x**2 - 10*x + 24


def bisection(f, a, b, tolerance):
    if np.sign(f(a)) == np.sign(f(b)):
        print(f'a = {a} and b = {b} not bound a root')
        return False
    m = (a + b) / 2
    if np.abs(f(m)) < tolerance:
        print(f'root of the function = {m:.11f}', end=' ')
        return True
    elif np.sign(f(a)) == np.sign(f(m)):
        return bisection(f, m, b, tolerance)
    elif np.sign(f(b)) == np.sign(f(m)):
        return bisection(f, a, m, tolerance)


for i, el in enumerate(coordinates):
    result = bisection(f2, el[0], el[1], 0.044)
    if result:
        print(f'with coordinates of x1 = {el[0]} and x2 = {el[1]}')


print()
print('=============================== Question 6 ===============================')
print()


x = sp.symbols('x')
min = 1
max = 4
n = 23
x_arr = np.linspace(min, max, n)
box_width = (max - min) / (n - 1)


def f3(x): return x**3 + 2*x**2 - x - 2


x_left = x_arr[1::]
y_left = f3(x_left)
left_riemann = box_width * np.sum(np.abs(y_left))
print(f'Left Riemann : {left_riemann}')
x_right = x_arr[:-1]
y_right = f3(x_right)
right_riemann = box_width * np.sum(np.abs(y_right))
print(f'Right Riemann: {right_riemann}')
x_mid = (x_left + x_right) / 2
y_mid = f3(x_mid)
mid_riemann = box_width * np.sum(np.abs(y_mid))
print(f'Mid Riemann  : {mid_riemann}')
trapezoid = box_width * np.sum((np.abs(y_left) + np.abs(y_right)) / 2)
print(f'Trapezoid    : {trapezoid}')
