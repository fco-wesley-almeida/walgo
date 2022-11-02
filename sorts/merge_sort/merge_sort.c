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

void merge(int* v, int begin, int middle, int end)
{
    int i, j, begin_1, begin_2, *w;

    i = begin;
    begin_1 = begin;
    begin_2 = middle + 1;
    w = (int*) malloc((end + 1) * sizeof(int));

    while (begin_1 <= middle && begin_2 <= end)
    {
        w[i++] = v[begin_1] <= v[begin_2] ? v[begin_1++] : v[begin_2++];  
    }

    for(j = begin_1; j <= middle; j++) {
        w[i++] = v[j];
    }
        
    for(j = begin_2; j <= end; j++) {
        w[i++] = v[j];
    }
        
    for(i=begin; i <= end; i++) {
        v[i] = w[i];
    }
}

void merge_sort(int *v, int begin, int end) // Begin = 0 e end = len(v)-1
{   
    if (begin < end)
    {
        int middle = (begin + end) / 2;
        merge_sort(v, begin, middle);
        merge_sort(v, middle + 1, end);
        merge(v, begin, middle, end);
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
    merge_sort(vector, 0, vector_size - 1);
    print_vector(vector_size, vector);
    free(vector);
    return EXIT_SUCCESS;
}
