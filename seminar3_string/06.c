#include <stdio.h>

int is_palindrom(const char str[])
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    int l = 0;
    int r = len - 1;
    while (l < r) {
        if (str[l] != str[r]) {
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}

int main()
{
    char str[100];
    scanf("%s", str);
    if (is_palindrom(str)) {
        printf("Yes\n"); 
    } else {
        printf("No\n");
    }
    return 0;
}