#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/test.h"
#include "libs/data_structures/vector/vectorVoid.h"

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

    vectorVoid vector_void1;

    vector_void1.data = NULL;
    vector_void1.size = 0;
    vector_void1.capacity = 0;
    vector_void1.baseTypeSize = sizeof (void);

    return 0;
};