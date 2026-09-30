#include <stdio.h>

int is_digit(char c) {
    return c >= 48 && c <= 57;
}

int is_valid_integer(const char* str)
{
    int i = 0;
    if (str[i] == '-' || str[i] == '+') {
        i++;
    }
    while (str[i] != '\0') {
        if (!is_digit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

long long str_to_ll(const char* str)
{
    long long num = 0;
    int sign = 1;
    int i = 0;
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        num = num * 10 + (str[i] - 48);
        i++;
    }
    return num * sign;
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("Error: Wrong number of arguments!");
        return 0;
    }

    char op;
    char num1[100], num2[100];
    int parsed = sscanf(argv[1], " %s %c %s", num1, &op, num2);
    if (parsed != 3) {
        printf("Error: Wrong format!");
        return 0;
    }

    if (!is_valid_integer(num1) || !is_valid_integer(num2)) {
        printf("Error: Operands should be integers!\n");
        return 0;
    }

    long long a = str_to_ll(num1);
    long long b = str_to_ll(num2);

    if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%') {
        printf("Error: Invalid operator!");
        return 0;
    }

    if ((op == '/' || op == '%') && b == 0) {
        printf("Error: Division by zero!");
        return 0;
    }

    if (op == '+') {
        printf("%lld", a + b);
    } else if (op == '-') {
        printf("%lld", a - b);
    } else if (op == '*') {
        printf("%lld", a * b);
    } else if (op == '/') {
        printf("%lld", a / b);
    } else if (op == '%') {
        printf("%lld", a % b);
    }

    return 0;
}