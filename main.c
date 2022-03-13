#include <stdio.h>
#include "IntVector.h"

void skip_line(void) {
    printf("\n");
}

void print_name_func(char *str) {
    printf("%s\n", str);
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    skip_line();
}

void sc_vector(IntVector *v) {
    v->size = 0;
    int_vector_set_item(v, 0, 3);
    int_vector_set_item(v, 1, 1);
    int_vector_set_item(v, 2, 4);
    int_vector_set_item(v, 3, 1);
    int_vector_set_item(v, 4, 5);
}

int main() {
    IntVector *v;
    IntVector *v_copy;

    /* int_vector_new */
    v = int_vector_new(5);

    print_name_func("int_vector_new");
    printf("pointer: %p\n", v->pointer);
    printf("size: %d\n", v->size);
    printf("capacity: %d\n", v->capacity);

    skip_line();

    /* int_vector_copy */
    v_copy = int_vector_copy(v);

    print_name_func("int_vector_copy");
    printf("pointer: %p\n", v_copy->pointer);
    printf("size: %d\n", v_copy->size);
    printf("capacity: %d\n", v_copy->capacity);

    skip_line();

    /* int_vector_free */
    int_vector_free(v_copy);

    print_name_func("int_vector_free");
    printf("pointer: %p\n", v_copy->pointer);
    printf("size: %d\n", v_copy->size);
    printf("capacity: %d\n", v_copy->capacity);

    skip_line();

    /* int_vector_get_item */

    print_name_func("int_vector_get_item");
    printf("index value: %d\n", int_vector_get_item(v, 3));
    printf("pointer: %p\n", v->pointer);
    printf("size: %d\n", v->size);
    printf("capacity: %d\n", v->capacity);

    skip_line();

    /* int_vector_set_item */
    int test_index1 = 3;
    int_vector_set_item(v, test_index1, 10);

    print_name_func("int_vector_set_item");
    printf("index value: %d\n", v->pointer[test_index1]);
    printf("pointer: %p\n", v->pointer);
    printf("size: %d\n", v->size);
    printf("capacity: %d\n", v->capacity);

    skip_line();

    /* int_vector_get_size */

    print_name_func("int_vector_get_size");
    printf("size Vector: %ld\n", int_vector_get_size(v));

    skip_line();

    /* int_vector_get_capacity */

    print_name_func("int_vector_get_capacity");
    printf("capacity Vector: %ld\n", int_vector_get_capacity(v));

    skip_line();

    /* int_vector_push_back */
    sc_vector(v);

    print_name_func("int_vector_push_back");
    printf("!! array before conversion: !!\n");
    print_array(v->pointer, v->size);
    printf("pointer: %p\n", v->pointer);
    printf("size: %d\n", v->size);
    printf("capacity: %d\n", v->capacity);
    
    printf("test push back: %d\n", int_vector_push_back(v, 9));

    printf("!! array after conversion: !!\n");
    print_array(v->pointer, v->size);
    printf("pointer: %p\n", v->pointer);
    printf("size: %d\n", v->size);
    printf("capacity: %d\n", v->capacity);

    skip_line();

    /* int_vector_pop_back */

    print_name_func("int_vector_pop_back");
    printf("!! array before conversion: !!\n");
    print_array(v->pointer, v->size);
    printf("pointer: %p\n", v->pointer);
    printf("size: %d\n", v->size);
    printf("capacity: %d\n", v->capacity);
    
    int_vector_pop_back(v);

    printf("!! array after conversion: !!\n");
    print_array(v->pointer, v->size);
    printf("pointer: %p\n", v->pointer);
    printf("size: %d\n", v->size);
    printf("capacity: %d\n", v->capacity);

    skip_line();

    /* int_vector_shrink_to_fit */

    print_name_func("int_vector_shrink_to_fit");
    printf("!! array before conversion: !!\n");
    print_array(v->pointer, v->capacity);
    print_array(v->pointer, v->size);
    printf("pointer: %p\n", v->pointer);
    printf("size: %d\n", v->size);
    printf("capacity: %d\n", v->capacity);
    
    printf("test vector shrink to fit: %d\n", int_vector_shrink_to_fit(v));

    printf("!! array after conversion: !!\n");
    print_array(v->pointer, v->capacity);
    print_array(v->pointer, v->size);
    printf("pointer: %p\n", v->pointer);
    printf("size: %d\n", v->size);
    printf("capacity: %d\n", v->capacity);

    skip_line();

    /* int_vector_resize */

    print_name_func("int_vector_resize");
    printf("!! array before conversion: !!\n");
    print_array(v->pointer, v->size);
    printf("pointer: %p\n", v->pointer);
    printf("size: %d\n", v->size);
    printf("capacity: %d\n", v->capacity);
    
    printf("test vector resize: %d\n", int_vector_resize(v, 10));

    printf("!! array after conversion: !!\n");
    print_array(v->pointer, v->size);
    printf("pointer: %p\n", v->pointer);
    printf("size: %d\n", v->size);
    printf("capacity: %d\n", v->capacity);

    skip_line();

    /* int_vector_reserve */

    print_name_func("int_vector_reserve");
    printf("!! array before conversion: !!\n");
    print_array(v->pointer, v->size);
    printf("pointer: %p\n", v->pointer);
    printf("size: %d\n", v->size);
    printf("capacity: %d\n", v->capacity);
    
    printf("test vector reserve: %d\n", int_vector_reserve(v, 20));

    printf("!! array after conversion: !!\n");
    print_array(v->pointer, v->size);
    printf("pointer: %p\n", v->pointer);
    printf("size: %d\n", v->size);
    printf("capacity: %d\n", v->capacity);
}