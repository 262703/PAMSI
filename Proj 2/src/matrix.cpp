#include "matrix.hpp"


void Matrix::ReadFile()
{
    std::ifstream file("Input.txt");
    if (!file.is_open())
    {
        throw "Error! No input!";
    }
    file >> Verticles >> Edges >> StartPoint;
    matr = new int*[Edges];
    int v1, v2, weight;
    for (int i = 0; i < Edges; ++i)
    {
        matr[i] = new int [Edges];
    }
    for (int v = 0; v < Edges; ++v)
    {
        for (int b = 0; b < Edges; ++b)
        {
            matr[v][b] = 0;
            matr[b][v] = 0;
        }
    }
    for (int v = 0; v < Verticles; ++v)
    {
        file >> v1 >> v2 >> weight;
        matr[v1][v2] = weight;
    }
}

void Matrix::GraphPrint() const 
{
    std::cout << "Matrix:\n";
    for (int c = 0; c < Edges; c++)
    {
        for (int v = 0; v < Edges; v++)
        {
            std::cout << matr[c][v] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::RandomGraph(int Edg, double Dens)
{
    Edges = Edg;
    Density = Dens;
    StartPoint = rand() % Edges;
    int Max_Vert = Edges * (Edges - 1);
    Verticles = Density * Max_Vert;
    int Il_Vert = 0;
    matr = new int*[Edges];
    for (int i = 0; i < Edges; i++)
    {
        matr[i] = new int [Edges];
    }
    for (int i = 0; i < Edges; i++)
    {
        for (int j = 0; j < Edges; j++)
        {
            matr[i][j] = 99;
        }
    }
    for (int i = 0; i < Edges; i++)
    {
        matr[i][i] = 0;
    }
    if (Density == 1)
    {
        for (int i = 0; i < Edges; i++)
        {
            for (int j = 0; j < Edges; j++)
            {
                if (i != j)
                {
                    int waga = 0;
                    while (waga == 0)
                    {
                        waga = rand() % 10 + 1;
                    }
                    matr[i][j] = waga;
                }
            }
        }
    }
    else
    {
        while (Il_Vert != Verticles)
        {
            int RandomEdgeFirst = rand() % Edges;
            int RandomEdgeSecond = rand() % Edges;
            while (RandomEdgeSecond == RandomEdgeFirst)
            {
                RandomEdgeSecond = rand() % Edges;
            }
            int waga = 0;
            while (waga == 0)
            {
                waga = rand() % 10 +1;
            }
            if (matr[RandomEdgeFirst][RandomEdgeSecond] == 0 || matr[RandomEdgeFirst][RandomEdgeSecond] == 99)
            {
                matr[RandomEdgeFirst][RandomEdgeSecond] = waga;
                Il_Vert++;
            }
        }
    }
}