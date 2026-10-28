#include <stdio.h>

int main()
{
#ifdef DOG              // препроцессор оставит только одну из веток; вторая вообще не попадёт в компиляцию
    printf("Dog!\n");
#else
    printf("No dog!\n");
#endif
}
