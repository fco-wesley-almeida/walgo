#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>

struct sub_arr {
    int size;
    int *vector;
    int sum;
};

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

struct sub_arr max_subarray(int n, int *v)
{
    int max_sum = INT_MIN;
    int max_index_start;
    int max_index_end;
    for (int i = 0; i < n; i++) 
    {   
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += v[j];
            if (sum > max_sum) {
                max_sum = sum;
                max_index_start = i;
                max_index_end = j;
            }
        }
    }
    int *w = (int *) malloc(sizeof(int) * (max_index_end - max_index_start + 1));
    int j = 0;
    for (int i = max_index_start; i < max_index_end + 1; i++) {
        w[j++] = v[i];
    }
    struct sub_arr q;
    q.size = max_index_end - max_index_start + 1;
    q.vector = w;
    q.sum = max_sum;
    return q;
}

int *vector_from_stdin(int argc, char** argv)
{
    int vector_size = argc - 1;
    int *vector = (int *) malloc((argc - 1) * sizeof(int));
    for (int i = 0; i < vector_size; i++) 
    {
        if (argv[i + 1][0] == '-')
        {
            int q_digits = strlen(argv[i + 1]);
            char* number_str = (char *) malloc(sizeof(char) * q_digits);
            for (int j = 1; argv[i + 1][j] != '\0'; j++) 
            {
                number_str[j - 1] = argv[i + 1][j];
            }
            vector[i] = -atoi(number_str);
            free(number_str);
        } else {
            vector[i] = atoi(argv[i + 1]);
        }
    }
    return vector;
}

int main(int argc, char** argv)
{
    int vector_size = argc - 1;
    int* vector = vector_from_stdin(argc, argv);
    struct sub_arr result = max_subarray(vector_size, vector);
    print_vector(result.size, result.vector);
    free(result.vector);
    free(vector);
    return EXIT_SUCCESS;
}
