#include <stdio.h>

#define Max_Input 4294967296

int is_digit(char character) {
    return character >= '0' && character <= '9';
}

long long take_valid_int_input(char *input_message, int min_value) {
    char input_array[100];
    int is_valid;
    long long value = 0;

    while (1) {
        printf("%s", input_message);
        scanf("%s", input_array);

        is_valid = 1;
        for (int i = 0; input_array[i] != '\0'; i++) {
            if (!is_digit(input_array[i])) {
                is_valid = 0;
                break;
            }
        }

        if (is_valid) {
            value = 0;
            for (int i = 0; input_array[i] != '\0'; i++) {
                value = value * 10 + (input_array[i] - '0');
                if (value > Max_Input) {
                    is_valid = 0;
                    break;
                }
            }
            if (value < min_value || value > Max_Input) {
                is_valid = 0;
            }
        }

        if (!is_valid) {
            printf("Invalid input! Please enter a valid positive integer between %d and %lld.\n", min_value, Max_Input);
        } else {
            break;
        }
    }

    return value;
}

long long modular_exponentiation(long long base_value, long long exponent_value, long long modular_value) {
    long long result = 1;
    base_value = base_value % modular_value;

    while (exponent_value > 0) {
        if (exponent_value % 2 == 1) {
            result = (result * base_value) % modular_value;
        }
        exponent_value = exponent_value / 2;
        base_value = (base_value * base_value) % modular_value;
    }

    return result;
}

int main() {
    long long base_value = take_valid_int_input("Enter the base value (a positive integer): ", 1);
    long long exponent_value = take_valid_int_input("Enter the exponent value (a positive integer): ", 1);
    long long modular_value = take_valid_int_input("Enter the modular value (a positive integer greater than 1): ", 2);

    long long result = modular_exponentiation(base_value, exponent_value, modular_value);
    printf("Result of (%lld ^ %lld) %% %lld : %lld\n", base_value, exponent_value, modular_value, result);

    return 0;
}
