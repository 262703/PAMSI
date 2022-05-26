#pragma once

#include "graph.hpp"

#include <memory>
struct OneList
{
    int Neighbor, Weight;
    OneList* Next;
};
class List: public Graph {
    protected:
    OneList** GraphList;
    public:
    void GraphPrint() const override;
    void ReadFile() override;
    void RandomGraph(int Edg, double Dens) override;
    List(): Graph(){};
    bool IfEdge(int EdgeFirst, int EdgeSecond) const;
    OneList* operator [](int i) {return GraphList[i];};
};

