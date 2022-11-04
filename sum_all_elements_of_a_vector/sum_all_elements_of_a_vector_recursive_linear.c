#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>

int sum_vector_rec(int *v, int n)
{
    if (n == -1) {
        return 0;
    } else {
        return v[n] + sum_vector_rec(v, n - 1);
    }
}

int *vector_from_stdin(int argc, char** argv)
{
    int *v = (int *) malloc(sizeof(int) * argc - 1);
    int n = 0;
    for (int i = 0; i < argc - 1; i++) {
        if (argv[i][0] == '-') {
            int q_digits = strlen(argv[i + 1]);
            char* number_str = (char *) malloc(sizeof(char) * q_digits);
            for(int j = 1; argv[i + 1][j] != '\0'; j++) {
                number_str[j - 1] = argv[i + 1][j];
            }
            v[n] = atoi(argv[i + 1]);
        } else {
            v[n] = atoi(argv[i + 1]);
        }
        n++;
    }
    return v;
}

int main(int argc, char** argv)
{
    int vector_size = argc - 1;
    int* vector = vector_from_stdin(argc, argv);
    int sum = sum_vector_rec(vector, vector_size);
    printf("%d\n", sum);
    free(vector);
    return EXIT_SUCCESS;
}
