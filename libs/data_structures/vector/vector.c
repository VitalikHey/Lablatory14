#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

vector createVector(size_t n) {
    vector v1;
    v1.data = (int *) malloc(n * sizeof(int));
    v1.size = 0; // Инициализируем размер нулем - так как вектор пока пустой
    v1.capacity = n; // Устанавливаем вместимость вектора равной n

    if (v1.data == NULL) {
        fprintf(stderr, "Failed to allocate memory for the vector\n");
        exit(1);
    }
    return v1;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity > v->capacity) {
        int *newData = (int *) realloc(v->data, newCapacity * sizeof(int));
        if (newData == NULL) {
            fprintf(stderr, "Failed to reallocate memory for the vector\n");
            exit(1);
        }
        v->data = newData;
        v->capacity = newCapacity;
    } else if (newCapacity == 0) {
        v->data = NULL;
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

//void shrinkToFit(vector *v) {
//    if (v->size > v->capacity) {
//        int* new_data = (int *) realloc(v->data, v->size * sizeof (int));
//        if (new_data == NULL) {
//            fprintf(stderr, "bad realloc");
//            exit(1);
//        }
//        v->data = new_data;
//        v->capacity = v->size;
//    }
//}

void shrinkToFit (vector *v) {
    int* new_data = (int *) realloc(v->data, v->size * sizeof (int));
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}