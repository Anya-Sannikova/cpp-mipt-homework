#include <stdio.h>
#include "list.h"

int main()
{
    List a = init(0);

    for (int i = 0; i < 5; ++i)
        push_back(&a, 10 * (i + 1));
    for (int i = 0; i < 5; ++i)
        push_front(&a, 100 * (i + 1));
    print(&a);                          // Напечатает 500 400 300 200 100 10 20 30 40 50

    printf("%i\n", pop_front(&a));      // Напечатает 500
    printf("%i\n", pop_back(&a));       // Напечатает 50
    print(&a);                          // Напечатает 400 300 200 100 10 20 30 40

    Node* p = a.head;                   // p -> 400
    advance(&p, 3);                     // p -> 100
    p = erase(&a, p);                   // ИСПРАВЛЕНО: было erase(a, p), нужен адрес &a. p -> 10
    print(&a);                          // Напечатает 400 300 200 10 20 30 40

    List b = init(0);
    for (int i = 0; i < 3; ++i)
        push_back(&b, 1000 * (i + 1));  // ИСПРАВЛЕНО: было push_back(&a, ...), заполняем список b
    splice(&a, p, &b);                  // вставляем b в a перед узлом 10

    print(&a);                          // Напечатает 400 300 200 1000 2000 3000 10 20 30 40
    print(&b);                          // Ничего не напечатает (пустая строка)

    // ---- дополнительные проверки ----
    printf("size a = %zu, size b = %zu\n", a.size, b.size);       // 10 и 0

    Node* q = a.head;
    advance(&q, 100);                   // дальше конца - NULL
    printf("advance(100) -> %s\n", q == NULL ? "NULL" : "не NULL");

    q = a.tail;
    q = erase(&a, q);                   // удаление хвоста возвращает NULL
    printf("erase(tail) -> %s, tail = %i\n", q == NULL ? "NULL" : "не NULL", a.tail->value);

    q = erase(&a, a.head);              // удаление головы
    printf("после erase(head): head = %i, size = %zu\n", a.head->value, a.size);

    List c = init(3);                   // 0 0 0
    splice(&c, NULL, &a);               // p == NULL - вставка в конец
    print(&c);
    splice(&a, a.head, &c);             // a пуст (head == NULL): вставка в пустой список
    print(&a);

    destroy(&a); destroy(&b); destroy(&c);
    return 0;
}
