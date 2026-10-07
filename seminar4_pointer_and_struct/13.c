#include <stdio.h>
#include <string.h>

struct game
{
    char title[100];
    double avg_score;
};
typedef struct game Game;

int main()
{
    int n;
    scanf("%d", &n)

    Game games[100];
    char temp;

    for (int i = 0; i < n; i++) {
        scanf("%c", &temp);
        scanf("%[^:]", games[i].title);
        scanf("%c", &temp);

        int k;
        scanf("%d", &k);
        int sum = 0;
        for (int j = 0; j < k; j++) {
            int score = 0;
            scanf("%d", &score);
            sum += score;
        }
        games[i].avg_score = (double)sum / k;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (games[j].avg_score < games[j + 1].avg_score) {
                Game temp_game = games[j];
                games[j] = games[j + 1];
                games[j + 1] = temp_game;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s, %.3f\n", games[i].title, games[i].avg_score);
    }

    return 0;
}