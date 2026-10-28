# Ejercicio 3: Analisis y Comportamiento del Codigo

## Descripcion del Comportamiento
Este programa demuestra el uso de **Plantillas de Clases con Parametros Tipo No-Tipo** y **Valores por Defecto en Plantillas**.

1. **Parametros por defecto:**
   - La plantilla define T = char (tipo por defecto) y N = 8 (tamano de arreglo por defecto).

2. **Instanciaciones:**
   - objInt: Crea un arreglo interno de 5 enteros (int bloque[5]). Asigna 10 a la posicion 0.
   - objFloat: Crea un arreglo interno de 5 flotantes/dobles (double bloque[5]). Asigna 3.1 a la posicion 2.
   - obj: Al instanciarse como Comun1 <>, toma los parametros por defecto (char y tamano 8). 

3. **Acceso a elementos no inicializados:**
   - Se consulta obj.get(4), la cual accede a una posicion del arreglo bloque que no ha sido inicializada explicitamente, por lo que imprimira un valor basura o nulo.

## Salida del Programa
10
3.1
[Valor basura o vacio]
