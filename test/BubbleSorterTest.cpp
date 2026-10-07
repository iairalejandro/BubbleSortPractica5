#include <gtest/gtest.h>
#include <vector>
#include "BubbleSorter.h"

class BubbleSorterTest : public ::testing::Test {
protected:
    BubbleSorter* sorter;

    void SetUp() override {
        sorter = new BubbleSorter();
    }

    void TearDown() override {
        delete sorter;
    }
};

// CP1 - Camino C3: 1-2-9
TEST_F(BubbleSorterTest, CP1_C1_UnSoloElemento) {

    std::vector<int> vet = {5};
    std::vector<int> esperado = {5};
    sorter->bubbleSort(vet);

    EXPECT_EQ(esperado, vet);
}

// CP2 - Camino C3: 1-2-3-4-5-7-4-8-2-9
TEST_F(BubbleSorterTest, CP2_C2_YaOrdenadoSinIntercambio) {
    std::vector<int> vet = {1, 2};
    std::vector<int> esperado = {1, 2};

    sorter->bubbleSort(vet);

    EXPECT_EQ(esperado, vet);
}

// CP3 - Camino C3: 1-2-3-4-5-6-7-4-8-2-9 (un intercambio)
TEST_F(BubbleSorterTest, CP3_C3_UnIntercambio) {

    std::vector<int> vet = {2, 1};
    std::vector<int> esperado = {1, 2};
    sorter->bubbleSort(vet);

    EXPECT_EQ(esperado, vet);
}

// CP4 - Camino C4: pasa por la decisión interna con y sin intercambio
// y repite el for externo
TEST_F(BubbleSorterTest, CP4_C4_VariasIteracionesMixtas) {
    std::vector<int> vet = {2, 3, 1};
    std::vector<int> esperado = {1, 2, 3};

    sorter->bubbleSort(vet);

    EXPECT_EQ(esperado, vet);
}
