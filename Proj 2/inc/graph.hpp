#pragma once

#include <iostream>
#include <fstream>

class Graph {
    protected:
        int Verticles, Edges, StartPoint;
        double Density;
    public:
    const int& getVerticales() const {return Verticles;}
    const int& getEdges() const {return Edges;}
    const int& getStartPoint() const {return StartPoint;}
    Graph() {};
    virtual ~Graph() {};
    virtual void GraphPrint() const = 0;
    virtual void ReadFile() = 0;
    virtual void RandomGraph(int Edg, double Dens) = 0;
};