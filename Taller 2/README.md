
# Taller 2 - Templates & Manipulación de Strings

En este taller es obligatorio el uso de estructuras y funciones. Debe usar headers para evitar que el código se vea muy extenso, y ***no puede usar `cin` o `cout` en ninguna parte del código que no sea el archivo `main.cpp`.***

A continuación se va a encontrar una serie de problemas, cada uno de estos problemas tendra un archivo cpp que deberá completar. Los problemas a solucionar son los siguientes: 

## Enunciado

### 0. Templates (1.0)

Dentro de los archivos para hacer el taller, va a encontrar un archivo llamado [List.h, dentro de la carpeta libs](https://github.com/clase-programacion-avanzada/CPP-Workshop-1/blob/main/libs/List.h). 

La primera tarea, antes de iniciar con el taller va a ser modificar la estructua, agregando un template que permita tener listas de cualquier tipo. En este caso, la función `operator=` y la función `toString()` no deben ser modificadas. Sin esta modificación el código no funcionará.
  
### 1. Palíndromos (2.0)

Existen frases que se leen de izquierda a derecha de la misma forma que de derecha a izquierda; se conoce como palíndromas. Por ejemplo, la palabra `reconocer` es palíndroma. Así mismo, la frase `anita lava la tina` también lo es. Sin embargo, para que esto funcione, hay que eliminar los espacios que se encuentran dentro de la frase.

1. Desarrolle una [función](https://github.com/clase-programacion-avanzada/CPP-Workshop-1/blob/main/punto1/palindromes.cpp#L34) que reciba una cadena de caracteres (es decir un String), que [elimine los espacios](https://blog.devgenius.io/regex-replace-in-c-replace-the-match-of-a-string-using-regex-replace-c204c6b6f256) que contiene la cadena y que retorne la cadena sin ningún espacio. 

2. Desarrolle una [función](https://github.com/clase-programacion-avanzada/CPP-Workshop-1/blob/main/punto1/palindromes.cpp#L42) que reciba una frase cualquiera (que puede o no contener espacios) y que retorne verdadero si la frase es palíndroma o falso si no lo es.
   
3. Desarrolle una [función](https://github.com/clase-programacion-avanzada/CPP-Workshop-1/blob/main/punto1/palindromes.cpp#L52) que reciba una lista con strings. Debe retornar la cantidad de strings de esa lista que son palíndromos. 

**Todas estas funciones se deben desarrollar en el archivo palindromos.cpp El programa le indicará si su respuesta es válida o no. No cambie los nombres de las funciones, esto puede ocasionar que no se haga la verificación correctamente.**

### 2. Función de encriptación (1.0)

Una empresa requiere un programa que encripte los datos de entrada que se reciben. Para esto se ha destinado una función que se encarga de encriptar y desencriptar. El funcionamiento es bastante simple ([recuerde que un caracter también es un número](https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html)):

| Original   | a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z |
|------------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Traducción | z | y | x | w | v | u | t | s | r | q | p | o | n | m | l | k | j | i | h | g | f | e | d | c | b | a |


| Original   | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
|------------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Traducción | Z | Y | X | W | V | U | T | S | R | Q | P | O | N | M | L | K | J | I | H | G | F | E | D | C | B | A |

Arriba encontrará las tablas de traducción, estas tablas se usan para encriptar o desencriptar el mensaje. 
Por ejemplo, si tenemos el mensaje `Hola Mundo!`, la encriptación se logrará cambiando cada una de las letras por el valor traducido, los demás caracteres se mantendrán iguales.

| Original   | H | o | l | a |   | M | u | n | d | o | ! |
|------------|---|---|---|---|---|---|---|---|---|---|---|
| Traducción | S | l | o | z |   | N | f | N | w | l | ! |

Si se fija, al hacer el mismo proceso con la traducción obtenemos el mensaje original:

| Original   | S | l | o | z |   | N | f | N | w | l | ! |
|------------|---|---|---|---|---|---|---|---|---|---|---|
| Traducción | H | o | l | a |   | M | u | n | d | o | ! |

**Esta función se deben desarrollar en el archivo [encryption.cpp](https://github.com/clase-programacion-avanzada/CPP-Workshop-1/blob/main/punto2/encryption.cpp#L25) El programa le indicará si su respuesta es válida o no. No cambie los nombres de las funciones, esto puede ocasionar que no se haga la verificación correctamente.**

### 3. Separación por tokens (2.0):

En su carrera va a ser bastante común que se encuentre con archivos separados por comas, denominados archivos csv (comma-sepparated values); se utilizan para guardar datos en forma tabular (es decir, como una tabla). Veamos cómo se verían tres elementos de un archivo csv:

```csv
nombre;edad;nota
Carlos;18;2.5
Juan;28;3.0
Arnoldo;20;4.3
```

En estos archivos, la primera linea, que contiene los headers, es opcional. Aunque el nombre pueda llevar a confusiones, no es necesario que el delimitador entre un dato y otro sea una coma `(',')`, de hecho, en este ejemplo está separado por otro caracter `(';')`. Cada uno de los valores que se encuentran entre los delimitadores se denomina *token*.

Tendrá que desarrollar una función que reciba un string con una línea de uno de estos archivos y el delimitador. Lo que debe retornar esta función es una Lista de strings `LineList` que contenga los tokens de la línea ingresada. Por ejemplo:

Si el parámetro de entrada es ```carlos;18;2.5```, el resultado será una lista donde el primer elemento es `carlos`, el segundo `18` y el tercero `2.5`. 

```cpp
List: ["Carlos", "18", "2.5"]
```

Fíjese que los números `18` y `2.5` en realidad son strings.

La función debe permitir separar strings sin importar cuántos tokens tenga (puede que le sirva leer sobre [stringstream](https://akh1l.hashnode.dev/stringstream-and-getline-in-cpp) y [getline](https://akh1l.hashnode.dev/stringstream-and-getline-in-cpp)).

**Esta función se deben desarrollar en el archivo [splittokens.cpp](https://github.com/clase-programacion-avanzada/CPP-Workshop-1/blob/main/punto3/splittokens.cpp#L23) El programa le indicará si su respuesta es válida o no. No cambie los nombres de las funciones, esto puede ocasionar que no se haga la verificación correctamente.**

## Recursos en línea

- [Why strtok() should be deprecated](https://stackoverflow.com/questions/44336831/why-should-strtok-be-deprecated) [Artículo]
- [Why should strtok() generally be avoided?](https://benpfaff.org/writings/clc/strtok.html) [Artículo]
- [Templates in c++ with examples](https://www.geeksforgeeks.org/templates-cpp/) [Artículo]
- [C++ Strings](https://www.geeksforgeeks.org/c-string-class-and-its-applications/) [Artículo]
- [Plantillas (c++)](https://learn.microsoft.com/es-es/cpp/cpp/templates-cpp?view=msvc-170) [Artículo]
- [Strings in C++](https://www.geeksforgeeks.org/strings-in-cpp/) [Artículo]
- [How to split a string in C++, java and python](https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java//) [Artículo]
- [What are C++ FUNCTION TEMPLATES? 🍪](https://www.youtube.com/watch?v=spZd2rNtze8) [Video]
- [STL Templates in C++ - Generic Functions and Classes (beginner-friendly)](https://www.youtube.com/watch?v=-Svq5IYPWbc) [Video]