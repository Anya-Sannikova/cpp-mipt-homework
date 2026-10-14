#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(const Book* b) {
    printf("Book: %s, Pages: %i, Price: %.1f\n", b->title, b->pages, b->price);
}

int main() {
    Book a = {"Don Quixote", 1000, 750.0f};
    Book** p = (Book**)malloc(sizeof(Book*));
    *p = &a;
    print_book(*p);
    free(p);
    return 0;
}