#include <stdio.h>
#include <stdlib.h>

int find_index(int value, int vector_size, int* vector)
{
    if (vector[vector_size - 1] == value || vector_size == 0) {
        return vector_size - 1;
    }
    return find_index(value, vector_size - 1, vector);
}

int* vector_from_stdin(int argc, char** argv)
{
    int vector_size = argc - 2;
    int* vector = (int*) malloc((argc - 1) * sizeof(int));
    for (int i = 0; i < vector_size; i++) {
        vector[i] = atoi(argv[i + 2]);
    }
    return vector;
}

int main(int argc, char** argv)
{
    int vector_size = argc - 1;
    int* vector = vector_from_stdin(argc, argv);
    int value = atoi(argv[1]);
    int index = find_index(value, vector_size, vector);
    printf("%d\n", index);
    free(vector);
    return EXIT_SUCCESS;
}
