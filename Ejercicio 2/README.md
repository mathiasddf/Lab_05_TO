# Ejercicio 2: Analisis y Comportamiento del Codigo

## Descripcion del Comportamiento
Este programa demuestra el uso de **Especializacion de Plantillas (Template Specialization)** en C++.

1. **Clase plantilla generica `Contendor<T>`:** 
   - Diseñada para manejar cualquier tipo de dato generico.
   - Posee el metodo `add()`, el cual pre-incrementa (`++elemento`) y retorna el valor actualizado.

2. **Especializacion para `char` (`Contendor<char>`):**
   - Sobrescribe la implementacion predeterminada especificamente para el tipo de dato `char`.
   - Reemplaza el metodo `add()` por `uppercase()`, el cual verifica si el caracter es una letra minuscula ('a' - 'z') y la convierte a mayuscula mediante aritmetica de caracteres (`elemento += 'A' - 'a'`).

## Salida del Programa
```text
6
T
