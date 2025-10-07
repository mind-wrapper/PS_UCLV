#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <math.h>

// Definición de tipos de función
typedef struct
{
    double *data;
    int size;
} Vector;

typedef Vector *(*create_vector_t)(int);
typedef void (*init_vector_random_t)(Vector *);
typedef void (*init_vector_value_t)(Vector *, double);
typedef Vector *(*add_vectors_t)(Vector *, Vector *);
typedef Vector *(*subtract_vectors_t)(Vector *, Vector *);
typedef double (*vector_norm_t)(Vector *);
typedef double (*vector_mean_t)(Vector *);
typedef void (*print_vector_t)(Vector *);
typedef void (*free_vector_t)(Vector *);

int main()
{
    void *handle;
    char *error;

    printf("=== CARGA DINÁMICA DE BIBLIOTECA ===\n\n");

    // Cargar biblioteca compartida
    handle = dlopen("./libvector.so", RTLD_LAZY);
    if (!handle)
    {
        fprintf(stderr, "Error cargando biblioteca: %s\n", dlerror());
        return 1;
    }

    // Cargar símbolos
    create_vector_t create_vector = (create_vector_t)dlsym(handle, "create_vector");
    init_vector_random_t init_vector_random = (init_vector_random_t)dlsym(handle, "init_vector_random");
    init_vector_value_t init_vector_value = (init_vector_value_t)dlsym(handle, "init_vector_value");
    add_vectors_t add_vectors = (add_vectors_t)dlsym(handle, "add_vectors");
    subtract_vectors_t subtract_vectors = (subtract_vectors_t)dlsym(handle, "subtract_vectors");
    vector_norm_t vector_norm = (vector_norm_t)dlsym(handle, "vector_norm");
    vector_mean_t vector_mean = (vector_mean_t)dlsym(handle, "vector_mean");
    print_vector_t print_vector = (print_vector_t)dlsym(handle, "print_vector");
    free_vector_t free_vector = (free_vector_t)dlsym(handle, "free_vector");

    if ((error = dlerror()) != NULL)
    {
        fprintf(stderr, "Error cargando símbolos: %s\n", error);
        dlclose(handle);
        return 1;
    }

    // Usar las funciones cargadas dinámicamente
    const int VECTOR_SIZE = 4;

    Vector *v1 = create_vector(VECTOR_SIZE);
    Vector *v2 = create_vector(VECTOR_SIZE);

    if (v1 == NULL || v2 == NULL)
    {
        printf("Error creando vectores\n");
        dlclose(handle);
        return 1;
    }

    printf("Vectores creados dinámicamente:\n");
    init_vector_random(v1);
    printf("Vector 1: ");
    print_vector(v1);

    init_vector_value(v2, 2.0);
    printf("Vector 2: ");
    print_vector(v2);

    // Operaciones
    Vector *sum = add_vectors(v1, v2);
    if (sum != NULL)
    {
        printf("Suma: ");
        print_vector(sum);
        free_vector(sum);
    }

    printf("Norma de v1: %.4f\n", vector_norm(v1));
    printf("Media de v1: %.4f\n", vector_mean(v1));

    // Liberar recursos
    free_vector(v1);
    free_vector(v2);

    // Cerrar biblioteca
    dlclose(handle);

    printf("\n=== CARGA DINÁMICA FINALIZADA ===\n");

    return 0;
}