#include <stdio.h>
#include <stdlib.h>

int binary_search(int search, int n, int* vector)
{
    int begin, end, i;
    begin = 0;
    end = n - 1;
    i = (begin + end) / 2;
    while (begin <= end) {
        if (vector[i] < search) {
            begin = i + 1;
        } else if (vector[i] == search) {
            return i;
        } else {
            end = i - 1;
        }
        i = (begin + end)/2;
    }
    return -1;
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
    int index = binary_search(value, vector_size, vector);
    printf("%d", index);
    free(vector);
    return EXIT_SUCCESS;
}
