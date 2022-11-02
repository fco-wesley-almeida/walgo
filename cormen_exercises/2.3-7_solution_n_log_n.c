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

int qsort_comp(const void *a, const void *b) {
   return ( *(int*)a - *(int*)b );
}

int binary_search(int search, int n, int* vector)
{
    int begin = 0;
    int end = n - 1;
    int i = (begin + end) / 2;
    while (begin <= end) {
        if (vector[i] < search) {
            begin = i + 1;
        } else if (vector[i] == search) {
            return i;
        } else {
            end = i - 1;
        }
        i = (begin + end) / 2;
    }
    return -1;
}

int sum_exists(int value, int vector_size, int* vector)
{
    qsort(vector, vector_size, sizeof(int), qsort_comp);
    for (int i = 0; i < vector_size; i++) {
        int missing_value = value - vector[i];
        int bs_index = binary_search(missing_value, vector_size, vector);
        if (bs_index >= 0 && bs_index != i) {
            return 1;
        }
    }
    return 0;
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
    int vector_size = argc - 2;
    int* vector = vector_from_stdin(argc, argv);
    int value = atoi(argv[1]);
    int index = sum_exists(value, vector_size, vector);
    printf("%d\n", index);
    free(vector);
    return EXIT_SUCCESS;
}
