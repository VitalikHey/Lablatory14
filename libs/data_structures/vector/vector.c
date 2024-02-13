#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

void shrinkToFit(vector *v) {
    int *new_data = (int *) realloc(v->data, v->size * sizeof(int));
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return (v->size == 0);
}

bool isFull(vector *v) {
    return (v->size == v->capacity);
}

int getVectorValue(vector *v, size_t i) {
    return (v->data[i]);
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        reserve(v, 1);
    } else if (v->capacity == v->size) {
        reserve(v, v->capacity * 2);
    }
    v->data[v->size] = x;
    v->size++;
}

void test_pushBack_emptyVector() {
    vector vector1 = createVector(0);

    pushBack(&vector1, 3);

    assert(vector1.data[0] == 3);
    assert(vector1.size == 1);
}

void test_pushBack_fullVector() {
    vector vector1 = createVector(1);

    pushBack(&vector1, 2);
    pushBack(&vector1, 4);

    assert(vector1.data[1] == 4);
    assert(vector1.size == 2);
}

void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "Error, vector is empty!");
        exit(1);
    }

    v->size--;

    if (v->size < v->capacity / 2) {
        reserve(v, v->capacity / 2);
    }
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

int *atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[index] is not exists");
        exit(1);
    } else{
        return &(v->data[index]);
    }
}

int* back(vector *v) {
    return &(v->data[v->size - 1]);
}

int* front(vector *v) {
    return &(v->data[0]);
}

void test_atVector_notEmptyVector() {
    vector vector1 = createVector(2);

    pushBack(&vector1, 1);
    pushBack(&vector1, 2);

    int first_element = *atVector(&vector1, 0);
    int second_element = *atVector(&vector1, 1);


    assert(first_element == 1);
    assert(second_element == 2);
}

void test_atVector_requestToLastElement() {
    vector vector1 = createVector(2);

    pushBack(&vector1, 1);
    pushBack(&vector1, 2);

    int last_element = *atVector(&vector1, 1);


    assert(last_element == 2);
}

void test_back_oneElementInVector() {
    vector vector1 = createVector(2);

    pushBack(&vector1, 1);
    pushBack(&vector1, 2);

    int last_element = *back(&vector1);


    assert(last_element == 2);
}

void test_front_oneElementInVector(){
    vector vector1 = createVector(2);

    pushBack(&vector1, 1);
    pushBack(&vector1, 2);

    int first_element = *back(&vector1);


    assert(first_element == 1);
};