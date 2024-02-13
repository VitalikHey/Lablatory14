#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main (){
    test();

    vector vector1 = createVector(2);

    pushBack(&vector1, 1);
    pushBack(&vector1, 2);

    int a = *atVector(&vector1, 0);

    printf("%d", a);

    return 0;
};