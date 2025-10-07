# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

# Nombres de archivos
SRC = vector_ops.c main.c
OBJ = vector_ops.o main.o
HEADER = vector_ops.h

# Nombres de bibliotecas y ejecutables
LIB_STATIC = libvector.a
LIB_SHARED = libvector.so
EXEC_STATIC = main_static
EXEC_SHARED = main_shared
EXEC_DYNAMIC = main_dynamic

# Objetivo por defecto
all: static shared

# Biblioteca estática
static: $(LIB_STATIC) $(EXEC_STATIC)

$(LIB_STATIC): vector_ops.o
	ar rcs $@ $^

$(EXEC_STATIC): main.o $(LIB_STATIC)
	$(CC) -o $@ main.o -L. -lvector $(LDFLAGS)

# Biblioteca compartida
shared: $(LIB_SHARED) $(EXEC_SHARED)

$(LIB_SHARED): vector_ops.o
	$(CC) -shared -o $@ $^ $(LDFLAGS)

$(EXEC_SHARED): main.o $(LIB_SHARED)
	$(CC) -o $@ main.o -L. -lvector $(LDFLAGS)

# Objetos
vector_ops.o: vector_ops.c $(HEADER)
	$(CC) $(CFLAGS) -c -fPIC $< -o $@

main.o: main.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(OBJ) $(LIB_STATIC) $(LIB_SHARED) $(EXEC_STATIC) $(EXEC_SHARED) $(EXEC_DYNAMIC)

# Instalación de biblioteca compartida (requiere permisos)
install: $(LIB_SHARED)
	sudo cp $(LIB_SHARED) /usr/local/lib/
	sudo ldconfig

# Desinstalar
uninstall:
	sudo rm -f /usr/local/lib/$(LIB_SHARED)
	sudo ldconfig

.PHONY: all static shared clean install uninstall