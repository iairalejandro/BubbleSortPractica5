#include "BubbleSorter.h"

void BubbleSorter::bubbleSort(std::vector<int>& vet) const {
    int i, j, aux;                                   
    for (i = static_cast<int>(vet.size()); i >= 2; i--) {
        for (j = 1; j <= i - 1; j++) { 
            if (vet[j - 1] > vet[j]) {
                aux = vet[j - 1];
                vet[j - 1] = vet[j];
                vet[j] = aux;
            }
        }
    }
}
