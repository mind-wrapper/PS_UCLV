#include "vector_ops.h"

// a) Creación del vector
Vector *create_vector(int size)
{
    if (size <= 0)
    {
        printf("Error: Tamaño debe ser positivo\n");
        return NULL;
    }

    Vector *v = (Vector *)malloc(sizeof(Vector));
    if (v == NULL)
    {
        printf("Error: Memoria insuficiente\n");
        return NULL;
    }

    v->size = size;
    v->data = (double *)malloc(size * sizeof(double));
    if (v->data == NULL)
    {
        printf("Error: Memoria insuficiente\n");
        free(v);
        return NULL;
    }

    return v;
}

// b) Inicialización con valores aleatorios
void init_vector_random(Vector *v)
{
    if (v == NULL || v->data == NULL)
        return;

    srand(time(NULL));
    for (int i = 0; i < v->size; i++)
    {
        v->data[i] = (double)rand() / RAND_MAX * 100.0; // Valores entre 0 y 100
    }
}

// b) Inicialización con mismo valor
void init_vector_value(Vector *v, double value)
{
    if (v == NULL || v->data == NULL)
        return;

    for (int i = 0; i < v->size; i++)
    {
        v->data[i] = value;
    }
}

// c) Recuperar elemento por posición
double get_element(Vector *v, int position)
{
    if (v == NULL || v->data == NULL)
    {
        printf("Error: Vector no inicializado\n");
        return 0.0;
    }

    if (position < 0 || position >= v->size)
    {
        printf("Error: Posición fuera de rango\n");
        return 0.0;
    }

    return v->data[position];
}

// d) Sumar dos vectores
Vector *add_vectors(Vector *a, Vector *b)
{
    if (a == NULL || b == NULL || a->size != b->size)
    {
        printf("Error: Vectores incompatibles para suma\n");
        return NULL;
    }

    Vector *result = create_vector(a->size);
    if (result == NULL)
        return NULL;

    for (int i = 0; i < a->size; i++)
    {
        result->data[i] = a->data[i] + b->data[i];
    }

    return result;
}

// e) Restar dos vectores
Vector *subtract_vectors(Vector *a, Vector *b)
{
    if (a == NULL || b == NULL || a->size != b->size)
    {
        printf("Error: Vectores incompatibles para resta\n");
        return NULL;
    }

    Vector *result = create_vector(a->size);
    if (result == NULL)
        return NULL;

    for (int i = 0; i < a->size; i++)
    {
        result->data[i] = a->data[i] - b->data[i];
    }

    return result;
}

// f) Norma de un vector
double vector_norm(Vector *v)
{
    if (v == NULL || v->data == NULL)
    {
        printf("Error: Vector no inicializado\n");
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < v->size; i++)
    {
        sum += v->data[i] * v->data[i];
    }

    return sqrt(sum);
}

// g) Media de los elementos
double vector_mean(Vector *v)
{
    if (v == NULL || v->data == NULL || v->size == 0)
    {
        printf("Error: Vector no inicializado o vacío\n");
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < v->size; i++)
    {
        sum += v->data[i];
    }

    return sum / v->size;
}

// h) Mostrar vector
void print_vector(Vector *v)
{
    if (v == NULL || v->data == NULL)
    {
        printf("Vector no inicializado\n");
        return;
    }

    printf("[");
    for (int i = 0; i < v->size; i++)
    {
        printf("%.2f", v->data[i]);
        if (i < v->size - 1)
            printf(", ");
    }
    printf("]\n");
}

// Liberar memoria
void free_vector(Vector *v)
{
    if (v != NULL)
    {
        if (v->data != NULL)
        {
            free(v->data);
        }
        free(v);
    }
}