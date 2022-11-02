#include <stdio.h>
#include <stdlib.h>
 
void print_vector(int vector_size, int* vector)
{
    for (int i = 0; i < vector_size; i++) 
    {
        printf("%d", vector[i]);
        if (i != vector_size - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void xor_swap(int* a, int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void sort(int vector_size, int* vector)
{
    for (int i = 1; i < vector_size; i++)
    {
        int pivot = vector[i];
        for (int j = i - 1; j >= 0 && pivot >= vector[j]; j--)
        {
            xor_swap(&vector[j], &vector[j+1]);
        }
    }
}

int* vector_from_stdin(int argc, char** argv)
{
    int vector_size = argc - 1;
    int* vector = (int*) malloc((argc - 1) * sizeof(int));
    for (int i = 0; i < vector_size; i++) {
        vector[i] = atoi(argv[i + 1]);
    }
    return vector;
}

int main(int argc, char** argv)
{
    int vector_size = argc - 1;
    int* vector = vector_from_stdin(argc, argv);
    sort(vector_size, vector);
    print_vector(vector_size, vector);
    free(vector);
    return EXIT_SUCCESS;
}
