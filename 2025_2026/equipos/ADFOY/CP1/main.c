#include "vector_ops.h"

int main()
{
    const int VECTOR_SIZE = 5;

    printf("=== OPERACIONES CON VECTORES ===\n\n");

    // Crear vectores
    Vector *v1 = create_vector(VECTOR_SIZE);
    Vector *v2 = create_vector(VECTOR_SIZE);

    if (v1 == NULL || v2 == NULL)
    {
        printf("Error creando vectores\n");
        return 1;
    }

    // Inicializar vectores
    printf("1. INICIALIZACIÓN DE VECTORES:\n");
    init_vector_random(v1);
    printf("Vector 1 (aleatorio): ");
    print_vector(v1);

    init_vector_value(v2, 3.5);
    printf("Vector 2 (valor constante 3.5): ");
    print_vector(v2);

    // Operaciones
    printf("\n2. OPERACIONES:\n");

    // Suma
    Vector *suma = add_vectors(v1, v2);
    if (suma != NULL)
    {
        printf("Suma (v1 + v2): ");
        print_vector(suma);
        free_vector(suma);
    }

    // Resta
    Vector *resta = subtract_vectors(v1, v2);
    if (resta != NULL)
    {
        printf("Resta (v1 - v2): ");
        print_vector(resta);
        free_vector(resta);
    }

    // Norma y media
    printf("\n3. PROPIEDADES:\n");
    printf("Norma de v1: %.4f\n", vector_norm(v1));
    printf("Media de v1: %.4f\n", vector_mean(v1));
    printf("Norma de v2: %.4f\n", vector_norm(v2));
    printf("Media de v2: %.4f\n", vector_mean(v2));

    // Acceso a elementos
    printf("\n4. ACCESO A ELEMENTOS:\n");
    printf("Elemento en posición 2 de v1: %.2f\n", get_element(v1, 2));
    printf("Elemento en posición 2 de v2: %.2f\n", get_element(v2, 2));

    // Liberar memoria
    free_vector(v1);
    free_vector(v2);

    printf("\n=== PROGRAMA FINALIZADO ===\n");

    return 0;
}