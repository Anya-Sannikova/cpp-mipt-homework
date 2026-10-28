#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynarray.h"

// Error checked malloc
void* ecmalloc(size_t n)
{
    void* p = malloc(n);
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    return p;
}

void clean(Dynarray* pd)
{
    for (size_t i = 0; i < pd->size; ++i)
        pd->data[i] = 0;
}

void init(Dynarray* pd, size_t initial_size) 
{
    pd->size = initial_size;
    pd->capacity = initial_size;
    if (pd->size == 0)
        pd->data = NULL;
    else
        pd->data = (int*)ecmalloc(pd->capacity * sizeof(int));
    clean(pd);
}

void reserve(Dynarray* pd, size_t new_capacity)
{
    if (new_capacity <= pd->capacity)
        return;

    int* new_data = (int*)ecmalloc(new_capacity * sizeof(int));

    for (size_t i = 0; i < pd->size; ++i)
    {
        new_data[i] = pd->data[i];
    }

    free(pd->data);
    pd->data = new_data;
    pd->capacity = new_capacity;
}


void push_back(Dynarray* pd, int x) 
{
    static const double growth_factor = 2;
    if (pd->size == pd->capacity) 
    {
        size_t new_capacity = (size_t)(growth_factor * pd->capacity);
        
        if (new_capacity <= pd->size)
            new_capacity = pd->size + 1;

        reserve(pd, new_capacity);
    }
    pd->data[pd->size] = x;
    pd->size += 1;
}


int get(const Dynarray* pd, size_t index) 
{
    assert(index < pd->size);
    return pd->data[index];
}


void set(Dynarray* pd, size_t index, int value) 
{
    assert(index < pd->size);
    pd->data[index] = value;
}


void print(const Dynarray* pd) 
{
    printf("dynarray: ");
    for (size_t i = 0; i < pd->size; ++i) 
        printf("%i ", pd->data[i]);

    printf("\n");
}


void destroy(Dynarray* pd) 
{
    free(pd->data);
    pd->data = NULL;
}


// ==================== Homework ====================

// Удаляет последний элемент и возвращает его. Вместимость не меняется.
int pop_back(Dynarray* pd)
{
    if (pd->size == 0)
    {
        fprintf(stderr, "pop_back: array is empty.\n");
        exit(1);
    }
    pd->size -= 1;
    return pd->data[pd->size];
}


// Меняет размер массива. При увеличении новые элементы равны нулю.
void resize(Dynarray* pd, size_t new_size)
{
    if (new_size > pd->capacity)
    {
        // Растим в 2 раза, как в push_back, чтобы resize был быстрым в среднем
        size_t new_capacity = 2 * pd->capacity;
        if (new_capacity < new_size)
            new_capacity = new_size;

        reserve(pd, new_capacity);
    }

    // Нули ставим явно: за пределами size могут лежать старые значения
    for (size_t i = pd->size; i < new_size; ++i)
        pd->data[i] = 0;

    pd->size = new_size;
}


// Делает вместимость равной размеру.
void shrink_to_fit(Dynarray* pd)
{
    if (pd->capacity == pd->size)
        return;

    if (pd->size == 0)
    {
        free(pd->data);
        pd->data = NULL;
        pd->capacity = 0;
        return;
    }

    int* new_data = (int*)ecmalloc(pd->size * sizeof(int));

    for (size_t i = 0; i < pd->size; ++i)
    {
        new_data[i] = pd->data[i];
    }

    free(pd->data);
    pd->data = new_data;
    pd->capacity = pd->size;
}


// Поверхностная копия: копируется только структура (data, size, capacity).
// Оба объекта указывают на одну и ту же память в куче.
Dynarray shallow_copy(Dynarray* pd)
{
    return *pd;
}


// Глубокая копия: копируется структура и все элементы в куче.
Dynarray deep_copy(const Dynarray* pd)
{
    Dynarray copy;
    copy.size = pd->size;
    copy.capacity = pd->capacity;

    if (copy.capacity == 0)
        copy.data = NULL;
    else
        copy.data = (int*)ecmalloc(copy.capacity * sizeof(int));

    for (size_t i = 0; i < pd->size; ++i)
    {
        copy.data[i] = pd->data[i];
    }

    return copy;
}
