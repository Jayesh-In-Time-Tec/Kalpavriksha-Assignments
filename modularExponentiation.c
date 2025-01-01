#include <stdio.h>

int modular_exponentiation(int base_value, int exponent_value, int modular_value) {
    int result = 1;
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
    int base_value, exponent_value, modular_value;

    printf("Enter the base value: ");
    scanf("%d", &base_value);

    printf("Enter the exponent value: ");
    scanf("%d", &exponent_value);

    printf("Enter the modular value: ");
    scanf("%d", &modular_value);

    if (modular_value <= 1) {
        printf("Modulus should be a greater than 1.\n");
        return 1;
    }

    int result = modular_exponentiation(base_value, exponent_value, modular_value); 
    printf("Result of (%d ^ %d) %% %d : %d", base_value, exponent_value, modular_value, result);

    return 0;
}