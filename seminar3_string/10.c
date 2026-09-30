#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%i", &n);
    int x = 0, y = 0;
    char dir[20];
    int d;
    for (int i = 0; i < n; ++i) {
        scanf("%s %i", dir, &d);
        if (strcmp(dir, "North") == 0) {
            y += d;
        } else if (strcmp(dir, "South") == 0) {
            y -= d;
        } else if (strcmp(dir, "East") == 0) {
            x += d;
        } else if (strcmp(dir, "West") == 0) {
            x -= d;
        }
    }
    printf("%i %i", x, y);
    return 0;
}