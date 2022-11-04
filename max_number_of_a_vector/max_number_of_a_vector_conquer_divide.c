#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>

int max_element(int *v, int left, int right)
{
    if (left == right) {
        return v[left];
    } else {
        int middle = (left + right) / 2;
        int max_left = max_element(v, left, middle);
        int max_right = max_element(v, middle + 1, right);
        return max_left >= max_right ? max_left : max_right;
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
    int n = argc - 1;
    int* v = vector_from_stdin(argc, argv);
    int sum = max_element(v, 0, n - 1);
    printf("%d\n", sum);
    free(v);
    return EXIT_SUCCESS;
}
