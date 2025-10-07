# Respuesta a la CP1

## Preguntas teóricas:

### 1. Defina con sus palabras, ¿qué son las bibliotecas?

Las bibliotecas (o librerías) son colecciones de código precompilado que contienen funciones, procedimientos y datos que pueden ser utilizados por múltiples programas. Permiten la reutilización de código, modularización y facilitan el mantenimiento del software.

### 2. ¿Qué diferencias existen entre una biblioteca estática y una compartida?

| **Biblioteca Estática** | **Biblioteca Compartida/Dinámica** |
|-------------------------|-------------------------------------|
| Se enlaza en tiempo de compilación | Se enlaza en tiempo de ejecución |
| El código se copia directamente en el ejecutable | El ejecutable contiene referencias a la biblioteca |
| Resulta en ejecutables más grandes | Ejecutables más pequeños |
| No hay dependencias externas en tiempo de ejecución | Requiere que la biblioteca esté disponible en el sistema |
| Actualizaciones requieren recompilar el programa | Actualizaciones automáticas al actualizar la biblioteca |
| Mejor rendimiento (sin overhead de enlace dinámico) | Ligera penalización de rendimiento |

## Preguntas prácticas:

### 2. Para el problema definido en el ejercicio 1, indique las secuencias de comandos necesarias para construir:

#### a) Una biblioteca estática.

```bash
# Compilar los archivos objeto
gcc -c vector_ops.c -o vector_ops.o

# Crear biblioteca estática
ar rcs libvector.a vector_ops.o

# Compilar programa principal enlazando con biblioteca estática
gcc main.c -L. -lvector -o main_static -lm

# Ejecutar
./main_static
``` 
#### b) Una biblioteca compartida (enlace dinámico).
``` bash
# Compilar para biblioteca compartida (Position Independent Code)
gcc -c -fPIC vector_ops.c -o vector_ops.o

# Crear biblioteca compartida
gcc -shared -o libvector.so vector_ops.o -lm

# Compilar programa principal enlazando con biblioteca compartida
gcc main.c -L. -lvector -o main_shared -lm

# Configurar LD_LIBRARY_PATH para encontrar la biblioteca
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

# Ejecutar
./main_shared
```

### 3. Elabore un archivo Makefile que le permita automatizar el proceso de creación de las bibliotecas y los ejecutables.
``` bash
# Compilar todo
make all

# Compilar solo versión estática
make static

# Compilar solo versión compartida
make shared

# Ejecutar programas
./main_static
./main_shared

# Compilar y ejecutar versión con carga dinámica
gcc main_dynamic.c -o main_dynamic -ldl
./main_dynamic

# Limpiar archivos generados
make clean
```

### 4. Estudie una alternativa de implementación para el problema definido en 1 que emplee el método de creación de bibliotecas compartidas basadas en el proceso de carga dinámica. Auxíliese del artículo propuesto en la conferencia.
``` bash
# Compilar programa con carga dinámica
gcc main_dynamic.c -o main_dynamic -ldl

# Asegurarse de que libvector.so está en el directorio actual
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

# Ejecutar
./main_dynamic
``` 
