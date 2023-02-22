#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>

void print_vector(int vector_size, int* vector)
{
    for (int i = 0; i < vector_size; i++)  {
        printf("%d", vector[i]);
        if (i != vector_size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void _print_vector(int* v, int left, int right)
{
    for (int i = left; i <= right; i++) {
        printf("%d", v[i]);
        if (i != right) {
            printf(" ");
        }
    }
    printf("\n");
}


struct subarray {
    int left;
    int right;
    int sum;
};

/*
    v = 1 2 3 4 5 6 7 8
    value = 11
    sol = 5 6
*/

struct subarray max_subarray_sum(int *v, int n, int value)
{
    struct subarray s;
    int sum = 0;
    int left = 0;
    int right = n - 1;
    s.left = -1;
    s.right = -1;
    s.sum = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += v[j];
            if (sum == value) {
                s.left = i;
                s.right = j;
                s.sum = sum;
                return s;
            }
        }
    }
    return s;
}

int *vector_from_stdin(int argc, char** argv)
{
    int *v = (int *) malloc(sizeof(int) * argc - 2);
    int n = 0;
    for (int i = 1; i < argc - 1; i++) {
        if (argv[i][0] == '-') {
            int q_digits = strlen(argv[i + 1]);
            char* number_str = (char *) malloc(sizeof(char) * q_digits);
            for(int j = 1; argv[i + 1][j] != '\0'; j++) {
                number_str[j - 1] = argv[i + 1][j];
            }
            v[n++] = atoi(argv[i + 1]);
        } else {
            v[n++] = atoi(argv[i + 1]);
        }
    }
    return v;
}

int main(int argc, char** argv)
{
    int vector_size = argc - 2;
    int* vector = vector_from_stdin(argc, argv);
    int value = atoi(argv[1]);
    struct subarray subarr = max_subarray_sum(vector, vector_size, value);
    if (subarr.left >= 0 && subarr.right >= 0)  {
        _print_vector(vector,subarr.left, subarr.right);
    }
    free(vector);
    return EXIT_SUCCESS;
}
