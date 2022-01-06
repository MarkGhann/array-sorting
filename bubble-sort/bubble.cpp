#include "../MyArray.h"

void MyArray::BubbleSort() {
    for(size_t i = 0; i < this->curr; i++) {
        for(size_t j = 0; j < this->curr - 1; j++) {
            if (this->arr[j] > this->arr[j+1]) {
                this->Replace(j, j+1);
            }
        }
    }
}