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
    
    v = 1 2 3 4 5 6 7 8 9
    value = 11
    value = 12
    sol = 5 6
*/

struct subarray cross_subarray_sum(int *v, int value, int left, int middle, int right)
{
    printf("cross_subarray_sum: left=%d,middle=%d,right=%d\n", left, middle, right);
    struct subarray subarray;
    int sum = v[middle];
    int left_index = middle;
    int right_index = middle;
    subarray.left = -1;
    subarray.right = -1;
    if (left == right) {
        if (v[left] == value) {
            subarray.left = left;
            subarray.right = right;
            subarray.sum = value;
        }
        return subarray;
    }
    if (v[middle] == value) {
        subarray.left = middle;
        subarray.right = middle;
        subarray.sum = value;
        return subarray;
    }
    for (int i = 0; left_index >= left && right_index <= right; i++)
    {
        printf("right: i = %d, left_index=%d, left=%d, right_index=%d, right=%d\n", i, left_index, left, right_index, right);
        if (i % 2) {
            left_index--;
            sum += v[left_index];
        } else {
            right_index++;
            sum += v[right_index];
        }
        if (sum == value) {
            subarray.left = left_index;
            subarray.right = right_index;
            subarray.sum = sum;
            break;
        }
    }
    left_index = middle;
    right_index = middle;
    sum = 0;
    for (int i = 0; left_index >= left && right_index <= right; i++)
    {
        printf("left: i = %d, left_index=%d, left=%d, right_index=%d, right=%d\n", i, left_index, left, right_index, right);
        if (i % 2) {
            right_index++;
            sum += v[right_index];
        } else {
            left_index--;
            sum += v[left_index];
        }
        if (sum == value) {
            subarray.left = left_index;
            subarray.right = right_index;
            subarray.sum = sum;
            break;
        }
    }
    return subarray;
}

struct subarray max_subarray_sum(int *v, int value, int left, int right)
{
    struct subarray subarray;
    subarray.left = -1;
    subarray.right = -1;
    subarray.sum = 0;
    printf("left=%d,right=%d\n", left,right);
    _print_vector(v, left, right);
    printf("\n");
    if (left == right) {
        if (v[left] == value) {
            subarray.left = left;
            subarray.right = left;
            subarray.sum = v[left];
        }
        return subarray;
    } else {
        int middle = (left + right) / 2;
        struct subarray subarray_left = max_subarray_sum(v, value, left, middle);
        if (subarray_left.left != -1) {
            return subarray_left;
        }
        struct subarray subarray_right = max_subarray_sum(v, value, middle + 1, right);
        if (subarray_right.left != -1) {
            return subarray_left;
        }
        struct subarray subarray_cross = cross_subarray_sum(v, value, left, middle, right);
        if (subarray_right.left != -1) {
            return subarray_cross;
        }
        return subarray;
    }
    // struct subarray s;
    // int sum = 0;
    // int left = 0;
    // int right = n - 1;
    // s.left = -1;
    // s.right = -1;
    // s.sum = INT_MIN;
    // for (int i = 0; i < n; i++) {
    //     sum = 0;
    //     for (int j = i; j < n; j++) {
    //         sum += v[j];
    //         if (sum == value) {
    //             s.left = i;
    //             s.right = j;
    //             s.sum = sum;
    //             return s;
    //         }
    //     }
    // }
    // return s;
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
    struct subarray subarr = max_subarray_sum(vector, value, 0, vector_size - 1);
    if (subarr.left >= 0 && subarr.right >= 0) {
        _print_vector(vector, subarr.left, subarr.right);
    }
    free(vector);
    return EXIT_SUCCESS;
}
