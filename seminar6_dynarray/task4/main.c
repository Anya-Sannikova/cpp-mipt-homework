#include <stdio.h>

int main()
{
#ifndef COUNT                       // COUNT не передали через -DCOUNT=...
    printf("No count!\n");
#elif COUNT > 100                   // ветка выбирается ещё на этапе препроцессора
    printf("Count is too large!\n");
#elif defined(REVERSE)              // defined(X) - проверка, определён ли макрос
    for (int i = COUNT; i >= 1; --i)
        printf("%i ", i);
    printf("\n");
#else
    for (int i = 1; i <= COUNT; ++i)
        printf("%i ", i);
    printf("\n");
#endif
}
