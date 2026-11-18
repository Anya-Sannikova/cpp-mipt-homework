
#include <stdio.h>
#include <string.h>

int main()
{
    unsigned char a[16] = { 0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0};
    // 1. Шестнадцатеричная запись
    for (int i = 0; i < 16; i++) {
        printf("%02X ", a[i]);
    }
    printf("\n");
    // 2. Десятичная запись
    for (int i = 0; i < 16; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    // 3. ASCII-символ
    for (int i = 0; i < 16; i++) {
        char symbol = '.';
        if (a[i] >= 32 && a[i] <= 126) {
            symbol = a[i];
        }
        printf("Index: %02d   Hex: 0x%02X   ASCII: %c\n", i, a[i], symbol);
    }
    // 4. Изменяем байт с индексом 5
    a[5] = 0xE5;

    // 5. Копируем первые 7 байт на 3 позиции вправо
    memmove(a + 3, a, 7);

    // 6. Копируем последние 5 байт в начало
    memcpy(a, a + 11, 5);

    // 7. Зануляем байты с индексами от 5 до 10
    memset(a + 5, 0, 6);
    return 0;
}
