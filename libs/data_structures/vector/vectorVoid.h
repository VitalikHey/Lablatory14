#ifndef LABLATORY14_VECTORVOID_H
#define LABLATORY14_VECTORVOID_H

#include <limits.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
// например, если вектор хранит int -
// то поле baseTypeSize = sizeof(int)
// если вектор хранит float -
// то поле baseTypeSize = sizeof(float)
} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

void clearV(vectorVoid *v);

void shrinkToFitV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);

bool isEmptyV(vectorVoid *v);

bool isFullV(vectorVoid *v);

int getVectorValueV(vectorVoid *v, size_t i);

void pushBackV(vectorVoid *v, int x);

void popBackV(vectorVoid *v);

int* atVectorV(vectorVoid *v, size_t index);

int* backV(vectorVoid *v);

int* frontV(vectorVoid *v);


#endif //LABLATORY14_VECTORVOID_H
