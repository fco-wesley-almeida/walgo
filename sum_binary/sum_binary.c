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

int* vector_from_stdin(int argc, char** argv)
{
    int vector_size = argc - 1;
    int* vector = (int*) malloc((argc - 1) * sizeof(int));
    for (int i = 0; i < vector_size; i++) {
        vector[i] = atoi(argv[i + 1]);
    }
    return vector;
}

int get_nbits(int vector_size, int* vector)
{
    if (vector_size == 0) {
        return -1;
    }
    int nbits = vector[0];
    if ((nbits * 2 + 1) < vector_size) {
        return -1;
    }
    return nbits;
}

int* first_bin(int nbits, int args_size, int* args)
{
    int* number = (int*) malloc(nbits * sizeof(int));
    for(int i = 0; i < nbits + 1; i++) {
        number[i] = !!args[i + 1];
    }
    return number;
}


int* second_bin(int nbits, int args_size, int* args)
{
    int* number = (int*) malloc(nbits * sizeof(int));
    for(int i = nbits + 1; i < args_size; i++) {
        number[i - (nbits + 1)] = !!args[i];
    }
    return number;
}

int* binary_sum(int nbits, int* bin1, int* bin2)
{
    int* result = (int*) malloc((nbits + 1) * sizeof(int));
    int carry = 0;
    for (int i = nbits - 1; i >= 0; i--) {
        int sum = bin1[i] + bin2[i] + carry;
        result[i + 1] = sum % 2 == 1;
        carry = sum > 1;
    }
    result[0] = carry;
    return result;
}

int main(int argc, char** argv)
{
    int args_size = argc - 1;
    int* args = vector_from_stdin(argc, argv);
    int nbits = get_nbits(args_size, args);
    if (nbits == -1) {
        return EXIT_FAILURE;
    }
    int* bin1 = first_bin(nbits, args_size, args);
    int* bin2 = second_bin(nbits, args_size, args);
    int* sum = binary_sum(nbits, bin1, bin2);
    print_vector(nbits + 1, sum);
    free(args);
    free(bin1);
    free(bin2);
    free(sum);
    return EXIT_SUCCESS;
}
