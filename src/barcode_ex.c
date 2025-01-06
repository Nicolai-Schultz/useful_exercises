#include <stdio.h>
#include <stdlib.h>

#define BARCODE_DIGITS 12
// Write a program that prompts the user to enter the 12 digits of
// a barcode seperated by spaces.
// the program should store the digits in an integer array
/// FREE AFTER USE!
int* enter_barcode() {
    int *barcode = (int*)malloc(sizeof(int)*BARCODE_DIGITS);
    printf("Enter %d digits each followed by a space: ", BARCODE_DIGITS);
    for(int i = 0; i < BARCODE_DIGITS; i++) {
        scanf("%d", &barcode[i]);
    }
    return barcode;
}

int calculate_sum_of_odd_digits(int* barcode) {
    int sum_of_odd_digits = 0;
    for(int i = 0; i < BARCODE_DIGITS; i++) {
        //  Finding odd number positions
        if(i % 2 == 0) {
            printf("%d ", barcode[i]);
            sum_of_odd_digits += barcode[i];
        }
    }
    printf("Step a) %d \n", (sum_of_odd_digits*3));
    return (sum_of_odd_digits*3);
}

int calculate_sum_of_even_digits(int* barcode, int sum_of_odd_digits) {
    int sum_of_even_digits = 0;
    for(int i = 0; i < BARCODE_DIGITS; i++) {
        //  Finding odd number positions
        if(i % 2 != 0) {
            printf("%d ", barcode[i]);
            sum_of_even_digits += barcode[i];
        }
    }
    printf("Step b) %d \n", (sum_of_even_digits + sum_of_odd_digits));
    return sum_of_even_digits+sum_of_odd_digits;
}

int check_digit(int sum_of_even_digits) {
    if(sum_of_even_digits % 10 == 0) {
        return sum_of_even_digits % 10;
    } else {
        return 10 - (sum_of_even_digits % 10);
    }
}

void match_digit(int sum_of_even_digits, int* barcode) {
    if(check_digit(sum_of_even_digits) == (*barcode % 10)) {
        printf("Validated.");
    } else {
        printf("Error in barcode");
    }
}

int main(void) {
    int *barcode = enter_barcode();
    if(barcode == NULL) {
        exit(-1);
    }
    match_digit(check_digit(calculate_sum_of_even_digits(barcode, calculate_sum_of_odd_digits(barcode))), barcode);
    free(barcode);

    return 0;
}