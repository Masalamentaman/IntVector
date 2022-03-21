#include <malloc.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity) {
    IntVector *array;

    array = (IntVector *)malloc(sizeof(IntVector));
    if (array == NULL)
        return NULL;

    array->size = 0;
    array->capacity = initial_capacity;
    array->pointer = (int *)malloc(initial_capacity * sizeof(int));
    if (array->pointer == NULL) {
        free(array);
        return NULL;
    }

    return array;
}

IntVector *int_vector_copy(const IntVector *v) {
    IntVector *array;
    
    array = (IntVector *)malloc(sizeof(IntVector));
    if (array == NULL)
        return NULL;

    array->pointer = (int *)malloc(v->capacity * sizeof(int));
    if (array->pointer == NULL) {
        free(array);
        return NULL;
    }

    *array = *v;

    return array;
}

void int_vector_free(IntVector *v) {
    free(v->pointer);
    free(v);
}

int int_vector_get_item(const IntVector *v, size_t index) {
    if (index >= v->size || index < 0) {
        return 0;
    }

    return v->pointer[index];
}

void int_vector_set_item(IntVector *v, size_t index, int item) {
    v->pointer[index] = item;
    
    if (index < v->capacity)
        v->size++;
}

size_t int_vector_get_size(const IntVector *v) {
    return v->size;
}

size_t int_vector_get_capacity(const IntVector *v) {
    return v->capacity;
}

int int_vector_push_back(IntVector *v, int item) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        int *reserve = realloc(v->pointer, v->capacity * sizeof(int));
        if (reserve == NULL)
            return -1;

        v->pointer = reserve;
        int_vector_set_item(v, v->size, item);
    }
    else {
        int_vector_set_item(v, v->size, item);
    }
    
    return 0;
}

void int_vector_pop_back(IntVector *v) {
    if (v->size <= 0)
        return;
    else {
        v->pointer[v->size - 1] = 0;
        v->size--;
    }
}

int int_vector_shrink_to_fit(IntVector *v) {
    if (v->capacity == v->size)
        return 0;
    else {
        v->capacity = v->size;
        int *reserve = realloc(v->pointer, v->capacity * sizeof(int));
        if (reserve == NULL)
            return -1;

        v->pointer = reserve;
    }

    if (v->capacity != v->size || v->pointer == NULL)
        return -1;
    else
        return 0;
}

int int_vector_resize(IntVector *v, size_t new_size) {
    int test;
    if (new_size > v->size) {
        if (new_size > v->capacity) {
            v->capacity = new_size;
            int *reserve = realloc(v->pointer, v->capacity * sizeof(int));
            if (reserve == NULL)
                return -1;

        v->pointer = reserve;
        }
        
        int temp = v->size;
        for (int i = temp; i < new_size; i++) {
            v->pointer[i] = 0;
            v->size++;
        }
        return 0;
    }
    else if (new_size < v->size) {
        v->size = new_size;
        test = int_vector_shrink_to_fit(v);
        if (test == -1)
            return -1;
        else 
            return 0;
    }

    return -1;
}

int int_vector_reserve(IntVector *v, size_t new_capacity) {
    if (new_capacity <= v->capacity)
        return 0;
    else {
        v->capacity = new_capacity;
        int *reserve = realloc(v->pointer, v->capacity * sizeof(int));
        if (reserve == NULL)
            return -1;

        v->pointer = reserve;

        return 0;
    }
}