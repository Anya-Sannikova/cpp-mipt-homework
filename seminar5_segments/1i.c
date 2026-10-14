#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
    char* title;
    int pages;
    float price;
};
typedef struct book Book;

struct library
{
    Book* books;
    int number_of_books;
};
typedef struct library Library;

void print_book(const Book* b) {
    if (b && b->title) {
        printf("Book: %s, Pages: %i, Price: %.1f\n", b->title, b->pages, b->price);
    }
}

void library_create(Library* lib, int n) {
    lib->number_of_books = n;
    lib->books = (Book*)malloc(sizeof(Book) * n);
    for (int i = 0; i < n; ++i) {
        lib->books[i].title = NULL;
        lib->books[i].pages = 0;
        lib->books[i].price = 0.0f;
    }
}

void library_set(Library lib, int index, const char* title, int pages, float price) {
    if (index >= 0 && index < lib.number_of_books) {
        if (lib.books[index].title != NULL) {
            free(lib.books[index].title);
        }
        lib.books[index].title = (char*)malloc(sizeof(char) * (strlen(title) + 1));
        strcpy(lib.books[index].title, title);
        lib.books[index].pages = pages;
        lib.books[index].price = price;
    }
}

Book* library_get(Library lib, int index) {
    if (index >= 0 && index < lib.number_of_books) {
        return &lib.books[index];
    }
    return NULL;
}

void library_print(Library lib) {
    for (int i = 0; i < lib.number_of_books; ++i) {
        print_book(&lib.books[i]);
    }
}

void library_destroy(Library* lib) {
    if (lib->books != NULL) {
        for (int i = 0; i < lib->number_of_books; ++i) {
            if (lib->books[i].title != NULL) {
                free(lib->books[i].title);
            }
        }
        free(lib->books);
        lib->books = NULL;
    }
    lib->number_of_books = 0;
}

int main() {
    Library a;
    library_create(&a, 3);
    library_set(a, 0, "Don Quixote", 1000, 750.0f);
    library_set(a, 1, "Oblomov", 400, 250.0f);
    library_set(a, 2, "The Odyssey", 500, 500.0f);
    library_print(a);
    print_book(library_get(a, 1));
    library_destroy(&a);
    return 0;
}