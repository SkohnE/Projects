#Santiago Kohn Espinosa - A01029109#

import random
from os import system, name
from time import sleep

#Creación del tablero cubierto y las raespestas.
tablero = [['[?]','[?]','[?]','[?]','[?]','[?]'],['[?]','[?]','[?]','[?]','[?]','[?]'],['[?]','[?]','[?]','[?]','[?]','[?]'],['[?]','[?]','[?]','[?]','[?]','[?]'],['[?]','[?]','[?]','[?]','[?]','[?]'],['[?]','[?]','[?]','[?]','[?]','[?]']]
sig = '[?]'
R = [1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18]

# Revoelve las respuestas y asignarlas a cada coordenada del tablero.
random.shuffle(R)
Respuestas = []
for i in range(0, len(R), 6):
    Respuestas.append(R[i:i+6])

# Letras para asignar coordenadas por letras.
letras = ['A','B','C','D','E','F']

# Variables para asignar turno y puntucación a cada jugador.
jugador = 0
puntuacion1 = 0
puntuacion2 = 0

# Reseteo de la terminal para el reseteo de tablero.
def clear():
    if name == 'nt':
        _ = system('cls')
    else:
        _ = system('clear')

# Impresión del tablero.   
def Tablero():
    for j in range (6):
        print('\t',j,end='')
    print('\n')
    for fil in range (len(tablero)):
        print(letras[fil],end='\t')
        for col in tablero[fil]:
            print (col,end='\t')
        print('\n')

# Turno de cada jugador.    
def turno():
    while True:
        print('\nCoordenada 1')
        h = input('Ingresea el numero de la coordenada: ')
        k = input('Ingrese la letra de la coordenada: ')
        print('Coordenada 2')
        h2 = input('Ingresea el numero de la coordenada: ')
        k2 = input('Ingrese la letra de la coordenada: ')
        if len(h)!=1 or len(k)!=1 or len(h2)!=1 or len(k2)!=1:
            print('Ingresó más de un digito en alguna casilla, intentelo de nuevo.')
        else:
            if (h==h2 and k==k2):
                print('\nEstá eligiendo la misma casilla, intentelo de nuevo.')
            elif not(47<int(ord(h))<54 and 47<int(ord(h2))<54 and 64<int(ord(k))<71 and 65<=int(ord(k2))<=70): # numeros y letras en codigo ASCII.
                print('\nAlgún dato esta fuera del rango, intentelo de nuevo.')
            else:
                fil = letras.index(k)
                fil2 = letras.index(k2)
                col = int(h)
                col2 = int(h2)
                if tablero[fil][col]==Respuestas[fil][col] or tablero[fil2][col2]==Respuestas[fil2][col2]:  
                    print('\nAlguna cordenada ya está abierta, intentelo de nuevo.')  
                else:
                    break
    tablero[fil].pop(col),tablero[fil].insert(col,Respuestas[fil][col])
    tablero[fil2].pop(col2),tablero[fil2].insert(col2,Respuestas[fil2][col2])
    Tablero()
    if Respuestas[fil][col] == Respuestas[fil2][col2]:
        print('Correcto')
        return 1
    else:
        tablero[fil].pop(col),tablero[fil].insert(col,sig)
        tablero[fil2].pop(col2),tablero[fil2].insert(col2,sig)
        print('Incorrecto')
        return 0

# Asignación de turnos y puntuación. 
while tablero != Respuestas:
    jugador += 1
    Tablero()
    if jugador % 2 != 0:
        print('Turno del jugador 1')
        p = turno()
        puntuacion1 += int(p)
        jugador += int(p) 
        print('Jugador 1 tiene:',puntuacion1,'puntos')
    else:
        print('Turno del jugador 2')
        p = turno()
        puntuacion2 += p
        jugador += p 
        print('Jugador 2 tiene:',puntuacion2,'puntos')
    Continuar = input('¿Quieres seguir jugando? Responde "no" si no quieres continuar: ')
    print()
    if Continuar == 'no':
        break
    print('Memoriza el tablero sera borrado en 5 segundos')
    sleep(5)
    clear()
    
# Resultados.
print('Fin del juego')
if puntuacion1 > puntuacion2:
    print('El ganador es el jugador1 con: ',puntuacion1)
elif puntuacion1 < puntuacion2:
    print('El ganador es el jugador2 con: ',puntuacion2)
else:
    print('Empataron jugador1 con:',puntuacion1,'y jugador2 con:',puntuacion2)