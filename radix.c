#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compute_lengths(char **input, long input_size, int *lengths) {
    int max_len = 0;

    for (long i=0; i<input_size; i++) {
        lengths[i] = strlen(input[i]);
        if(lengths[i] > max_len) {
            max_len = lengths[i];
        }
    }

    return max_len;
}

int char_to_index(char character) {
    int index;
    if(character > 96) {
        index = character - 97 + 1;
    } else {
        index = character - 65 + 1;
    }
    return index;
}

char** counting_position_sort(char **input, long input_size, int *lengths, int position) {

    const int counts_size = 26 * 2 + 1;
    int *counts = malloc(counts_size * sizeof(int));
    if(counts == NULL) {
        fprintf(stderr, "Allocation error!\n");
        exit(-1);
    }
    for (long i=0; i<counts_size; i++) {
        counts[i] = 0;
    }

    // counting
    char curr_char;
    int index;
    for (long i=0; i<input_size; i++) {
        if(position >= lengths[i]) {
            counts[0]++;
        } else {
            curr_char = input[i][position];
            index = char_to_index(curr_char);
            counts[index]++;
        }
    }

    // compute first positions for each key
    int total = 0;
    for (long i=0; i<counts_size; i++) {
        int old_count = counts[i];
        counts[i] = total;
        total += old_count;
    }

    char **output = malloc(input_size * sizeof(char*));
    if(output == NULL) {
        fprintf(stderr, "Allocation error!\n");
        exit(-1);
    }

    // computing element positions
    for (long i=0; i<input_size; i++) {
        if(position >= lengths[i]) {
            output[counts[0]] = input[i];
            counts[0]++;
        } else {
            index = char_to_index(input[i][position]);
            output[counts[index]] = input[i];
            counts[index]++;
        }
    }

    // copying positions to 'input' table
    for(long i=0; i<input_size; i++) {
        input[i] = output[i];
    }

    compute_lengths(input, input_size, lengths);

    free(counts);

    return output;
}

void radix(char **input, long input_size) {
    int *lengths;
    int max_length;

    lengths = malloc(input_size * sizeof(int));
    if(lengths == NULL) {
        fprintf(stderr, "Allocation error!\n");
        exit(-1);
    }

    max_length = compute_lengths(input, input_size, lengths);

    for(int position=max_length-1; position>=0; position--) {
        counting_position_sort(input, input_size, lengths, position);
    }

    free(lengths);
}

void print(char **input, long input_size) {
    for (long i=0; i<input_size; i++) {
        printf("%s\n", input[i]);
    }
}

int main() {

    char* input[] = {"wala", "ala" , "lula", "luba", "luda" ,"Loda", "lala", "Lalaa", "srala", "bocian", "dziabag"};
    long n = sizeof(input) / sizeof(char*);

    printf("INPUT:\n");
    print(input, n);

    radix(input, n);

    printf("\nOUTPUT:\n");
    print(input, n);

    return 0;
}