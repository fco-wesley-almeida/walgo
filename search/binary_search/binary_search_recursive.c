#include <stdio.h>
#include <stdlib.h>

int binary_search(int value, int begin, int end, int* vector)
{
    int i = (begin + end) / 2;
    if (begin > end) {
        return -1;
    }
    if (vector[i] == value) {
        return i;
    }
    if (vector[i] > value) {
        return binary_search(value, begin, i - 1, vector);
    }
    if (vector[i] < value) {
        return binary_search(value, i + 1, end, vector);
    }
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
    int index = binary_search(value, 0, vector_size - 1, vector);
    printf("%d", index);
    free(vector);
    return EXIT_SUCCESS;
}
