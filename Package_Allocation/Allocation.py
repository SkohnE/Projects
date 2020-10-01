# coding=UTF-8
import pandas as pd
import numpy as np
from tqdm import tqdm
import openpyxl
# import time - Activar si se necesita fecha de hoy.
import re
# librería xlrd para windows
# Tener el archivo cerrado
archivo_excel = "zonas.xlsx" # Nombre del archivo de excel donde están las zonas.

# Crea los Data Frames.
df_zonas = pd.read_excel(archivo_excel, sheet_name = 'Zonas')

while True:
    archivo_paquetes = input("Nombre del archivo csv: ")
    try:
        df_paquetes = pd.read_csv(archivo_paquetes)
        break
    except:
        print("Archivo incorrecto. Asegurse que el archivo esté en la carpeta.")
        
print ("Reading...")     
# Latitud y Longitud de las zonas.
xZonas = np.array(df_zonas['X'])
yZonas = np.array(df_zonas['Y'])
r = 6378.1 # Radio de la tierra.

rutas = list()
distancias = list()

# calculos de distancia. obtienes el indice del mínimo.
for i in tqdm(range(len(df_paquetes.index))):
    deltaX = df_paquetes['latitude'][i] - xZonas
    deltaY = df_paquetes['longitude'][i] - yZonas
    
    # formula de distancia geográfica.
    distancia = 2*r*np.arcsin(np.sqrt(np.sin(deltaX/2*np.pi/180)**2+np.cos(xZonas*np.pi/180)*np.cos(df_paquetes['latitude'][i]*np.pi/180)*np.sin(deltaY/2*np.pi/180)**2))*10
    ruta = df_zonas['Zona'][np.where(distancia == distancia.min())[0]].to_string(index = False)

    rutas.append(ruta)
    distancias.append(distancia.min())

print("Writing...")

# Agregas Rutas y distancias al Data Frame de los paquetes.
df_paquetes ['Ruta'] = rutas
df_paquetes ['KM'] = distancias

# Ordena el data Frame por nombre de ruta o por nombre de ruta y distancia.
# df_paquetes = df_paquetes.sort_values(by=['Ruta'])
# df_paquetes = df_paquetes.sort_values(by=['Ruta', 'KM'])

# Nombre de la hoja de calculo, Paquete mes-dia-año del dia en que se corra.
# nombre = "Paquetes " + time.strftime("%m-%d-%y",time.localtime(time.time()))

# Nombre de la hoja de calculo, Paquete + fecha del archivo csv.
nombre = "Paquetes " + re.findall('-+(\d.+)\.+', archivo_paquetes)[0]
# Escribe los paquetes en una nueva hoja de excel.
with pd.ExcelWriter(archivo_excel, engine = 'openpyxl', mode = 'a') as writer:
    df_paquetes.to_excel(writer, sheet_name = nombre, index = False)

print("Done")
