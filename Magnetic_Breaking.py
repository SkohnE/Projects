import numpy as np
import matplotlib.pyplot as plt
from tqdm import tqdm_notebook

g = 9.81
m = 100
mu = 1e8
mu_0 = 4*np.pi*1e-7
a = 0.08
R = 9e-5

k = (9*(mu*mu_0)**2*a**4)/(4*R)

def p(x):
    return x**2/(np.sqrt(x**2+a**2))**5
def f(t, x, y):
    return y
def j(t, x, y):
    return -g-(k/m)*p(x)*y

t_0 = 0
t_f = 6
x_0 = 20
y_0 = 20

h = 0.01
N = (t_f-t_0)/h
t = np.linspace(t_0,t_f,int(N))

all_xs = []
all_ys = []

x_n = x_0
y_n = y_0
    
for i in tqdm_notebook(t):
    all_xs.append(x_n)
    all_ys.append(y_n)
    
    kx_1 = f(i, x_n, y_n)
    ky_1 = j(i, x_n, y_n)
    kx_2 = f(i +(1/2)*h, x_n + (1/2)*h*kx_1, y_n + (1/2)*h*ky_1)
    ky_2 = j(i +(1/2)*h, x_n + (1/2)*h*kx_1, y_n + (1/2)*h*ky_1)
    kx_3 = f(i +(1/2)*h, x_n + (1/2)*h*kx_2, y_n + (1/2)*h*ky_2)
    ky_3 = j(i +(1/2)*h, x_n + (1/2)*h*kx_2, y_n + (1/2)*h*ky_2)
    kx_4 = f(i + h, x_n + h * kx_3, y_n + h*ky_3)
    ky_4 = j(i + h, x_n + h * kx_3, y_n + h*ky_3)
    
    x_n = x_n + (h/6) * (kx_1 + 2*kx_2 + 2*kx_3 + kx_4)
    y_n = y_n + (h/6) * (ky_1 + 2*ky_2 + 2*ky_3 + ky_4)

new_x = np.array(all_xs)
new_y = np.array(all_ys)

F_z = -k*p(new_x)*new_y


plt.figure(figsize=(12,4))

plt.subplot(1,2,1)
plt.plot(t,all_xs)
plt.title("Altura de Dipolo con Frenado Magnético")
plt.xlabel("Tiempo [s]")
plt.ylabel("Altura [m]")

plt.subplot(1,2,2)
plt.plot(t,all_ys)
plt.title("Velocidad de Dipolo con Frenado Magnético")
plt.xlabel("Tiempo [s]")
plt.ylabel("Velocidad [m/s]")

plt.subplot(1,1,1)
plt.plot(t,F_z)
plt.title("Fuerza de Dipolo con Frenado Magnético")
plt.xlabel("Tiempo [s]")
plt.ylabel("Fuerza [N]")
