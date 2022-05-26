#include "BF.hpp"

void MatrixBellmanFord(Matrix GraphMatrix, std::fstream& File)
{
    int MaxInt = 2147483647;
    int *PayToGo, *Way;
    int Start = GraphMatrix.getStartPoint();
    int Edg = GraphMatrix.getEdges();
    PayToGo = new int [Edg];
    Way = new int [Edg];
    for (int i = 0; i < Edg; i++)
    {
        Way[i] = -1;
        PayToGo[i] = MaxInt;
    }
    PayToGo[Start] = 0;
    for (int i = 1; i < Edg; i++)
    {
        for (int j = 0; j < Edg; j++)
        {
            for (int z = 0; z < Edg; z++)
            {
                if (PayToGo[j] != MaxInt && (GraphMatrix(z, j) != 0 || GraphMatrix(z, j) != 99) && PayToGo[z] > PayToGo[j] + GraphMatrix(z, j))
                {
                    PayToGo[z] = PayToGo[j] + GraphMatrix(z, j);
                    Way[z] = j;
                }
            }
        }
    }
    OnMyWay(PayToGo, Edg, Way, File);
}

void ListBellmanFord(List GraphList, std::fstream& File)
{
    OneList* neighb;
    int MaxInt = 2147483647;
    int *PayToGo, *Way;
    int Start = GraphList.getStartPoint();
    int Edg = GraphList.getEdges();
    PayToGo = new int [Edg];
    Way = new int [Edg];
    for (int i = 0; i < Edg; i++)
    {
        Way[i] = -1;
        PayToGo[i] = MaxInt;
    }
    PayToGo[Start] = 0;
    for (int i = 1; i < Edg; i++)
    {
        for (int j = 0; j < Edg; j++)
        {
            for (neighb = GraphList[j]; neighb; neighb = neighb->Next)
            {
                if (PayToGo[j] != MaxInt && PayToGo[neighb->Neighbor] > PayToGo[j] + neighb->Weight)
                {
                    PayToGo[neighb->Neighbor] = PayToGo[j] + neighb->Weight;
                    Way[neighb->Neighbor] = j;
                }
            }
        }
    }
    OnMyWay(PayToGo, Edg, Way, File);
}

void OnMyWay(int* PayToGo, int Edg, int* Way, std::fstream& File)
{
    int* ListShow = new int [Edg];
    int n = 0;
    int m;

    for (int i = 0; i < Edg; i++)
    {
        File << i << ": ";
        for (m = i; m != -1 && n < Edg; m = Way[m]) ListShow[n++] = m;
        while(n) File << ListShow[--n] << " ";
        if (PayToGo[i] == 2147483647) File << "No way!" << std::endl;
        else File << "$" << PayToGo[i] << std::endl;
    }
    delete []ListShow;
}