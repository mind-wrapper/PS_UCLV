#ifndef VECTOR_OPS_H
#define VECTOR_OPS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Estructura para representar un vector
typedef struct
{
    double *data;
    int size;
} Vector;

// Prototipos de funciones
Vector *create_vector(int size);
void init_vector_random(Vector *v);
void init_vector_value(Vector *v, double value);
double get_element(Vector *v, int position);
Vector *add_vectors(Vector *a, Vector *b);
Vector *subtract_vectors(Vector *a, Vector *b);
double vector_norm(Vector *v);
double vector_mean(Vector *v);
void print_vector(Vector *v);
void free_vector(Vector *v);

#endif