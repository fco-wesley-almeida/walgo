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

struct subarray find_max_crossing_subarray(int *v, int left, int middle, int right)
{
    struct subarray max_crossing_subarray;
    int sum;
    int left_sum = INT_MIN;
    sum = 0;
    for (int i = middle; i >= left; i--) {
        sum += v[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_crossing_subarray.left = i;
        }
    }
    int right_sum = INT_MIN;
    sum = 0;
    for (int i = middle + 1; i <= right; i++) {
        sum += v[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_crossing_subarray.right = i;
        }
    }
    max_crossing_subarray.sum = right_sum + left_sum;
    return max_crossing_subarray;
}

struct subarray max_subarray_sum(int *v, int left, int right)
{
    struct subarray subarr;
    struct subarray subarr_left;
    struct subarray subarr_right;
    struct subarray subarr_cross;
    if (left == right) {
        subarr.left = left;
        subarr.right = right;
        subarr.sum = v[left];
        return subarr;
    }
    int middle = (left + right) / 2;
    subarr_left = max_subarray_sum(v,left,middle);
    subarr_right = max_subarray_sum(v,middle + 1, right);
    subarr_cross = find_max_crossing_subarray(v, left, middle, right);
    if (subarr_left.sum >= subarr_right.sum && subarr_left.sum >= subarr_cross.sum) {
        subarr = subarr_left;
    } else if(subarr_right.sum >= subarr_left.sum &&  subarr_right.sum >= subarr_cross.sum) {
        subarr = subarr_right;
    } else {
        subarr = subarr_cross;
    }
    return subarr;
}

int *vector_from_stdin(int argc, char** argv)
{
    int vector_size = argc - 1;
    int *vector = (int *) malloc((argc - 1) * sizeof(int));
    for (int i = 0; i < vector_size; i++)  {
        if (argv[i + 1][0] == '-') {
            int q_digits = strlen(argv[i + 1]);
            char* number_str = (char *) malloc(sizeof(char) * q_digits);
            for (int j = 1; argv[i + 1][j] != '\0'; j++) {
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
    struct subarray value = max_subarray_sum(vector, 0, vector_size - 1);
    _print_vector(vector,value.left, value.right);
    free(vector);
    return EXIT_SUCCESS;
}
