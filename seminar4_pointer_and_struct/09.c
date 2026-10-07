#include <stdio.h>
#include <string.h>

void used_chars(const char* str, char* used)
{
    int count[26] = {0};
    int i = 0;
    while (str[i] != '\0') {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            count[c - 'A'] = 1;
        } else if (c >= 'a' && c <= 'z') {
            count[c - 'a'] = 1;
        }
        i++;
    }

    int idx = 0;
    for (int j = 0; j < 26; j++) {
        if (count[j]) {
            used[idx] = 'a' + j;
            idx++;
        }
    }
    used[idx] = '\0';
}

int main()
{
    char s[50] = "Sapere Aude";
    char u[30];
    used_chars(s, u);
    printf("%s\n", u);
    strcpy(s, "123!$ ");
    used_chars(s, u);
    printf("%s\n", u);
    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u);
    return 0;
}