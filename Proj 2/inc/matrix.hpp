#pragma once

#include "graph.hpp"

#include <memory>


class Matrix: public Graph {
    protected:
    int** matr;
    public:
    void GraphPrint() const override;
    void ReadFile() override;
    void RandomGraph(int Edg, double Dens) override;
    int operator ()(int i, int j) {return matr[i][j];};
};