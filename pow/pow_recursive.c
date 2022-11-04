#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>

int _pow(int n, int expo)
{
    if (expo < 0) {
        return INT_MIN;
    }
    if (expo == 0) {
        return 1;
    }
    if (expo == 1) {
        return n;
    }
    if (n == 1 || n == 0) {
        return n;
    }
    return n * _pow(n, expo - 1);
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
            v[n] = -atoi(number_str);
            free(number_str);
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
    int result = _pow(vector[0], vector[1]);
    printf("%d\n", result);
    free(vector);
    return EXIT_SUCCESS;
}
