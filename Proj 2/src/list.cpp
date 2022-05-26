#include "list.hpp"

void List::ReadFile()
{
    int** graf;
    int v1, v2, waga;
    OneList* tab_list;
    std::ifstream file("Input.txt");
    if (!file.is_open())
    {
        throw "Error! No input!";
    }
    file >> Verticles >> Edges >> StartPoint;
    graf = new int*[Verticles];
    for (int i = 0; i < Verticles; i++)
    {
        graf[i] = new int[3];
        file >> graf[i][0] >> graf[i][1] >> graf[i][2];
    }
    GraphList = new OneList*[Edges];
    for (int i = 0; i < Edges; i++)
    {
        GraphList[i] = NULL;
    }
    for (int i = 0; i < Verticles; i++)
    {
        v1 = graf[i][0];
        v2 = graf[i][1];
        waga = graf[i][2];
        tab_list = new OneList;
        tab_list->Neighbor = v2;
        tab_list->Weight = waga;
        tab_list->Next = GraphList[v1];
        GraphList[v1] = tab_list;
    }
}

void List::GraphPrint() const
{
    std::cout << "List:\n";
    OneList* ListShow;
    for (int i = 0; i < Edges; i++)
    {
        std::cout << i;
        ListShow = GraphList[i];
        while(ListShow)
        { 
        std::cout << " > [" << ListShow->Neighbor << " = " << ListShow->Weight << "]";
        ListShow = ListShow->Next;
        }
        std::cout << std::endl;
    }
}

void List::RandomGraph(int Edg, double Dens)
{
    Edges = Edg;
    Density = Dens;
    StartPoint = rand() % Edges;
    int Max_Vert = Edges * (Edges - 1);
    Verticles = Density * Max_Vert;
    int Il_Vert = 0;
    GraphList = new OneList* [Edges];
    OneList * tab_list;
    for (int i = 0; i < Edges; i++)
    {
        GraphList[i] = NULL;
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
                    tab_list = new OneList;
                    tab_list->Neighbor = j;
                    tab_list->Weight = waga;
                    tab_list->Next = GraphList[i];
                    GraphList[i] = tab_list;
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
            OneList* tab_list;
            tab_list = new OneList;
            if (!IfEdge(RandomEdgeFirst, RandomEdgeSecond))
            {
                tab_list->Neighbor = RandomEdgeSecond;
                tab_list->Weight = waga;
                tab_list->Next = GraphList[RandomEdgeFirst];
                GraphList[RandomEdgeFirst] = tab_list;
                Il_Vert++;
            }
        }
    }
}

bool List::IfEdge(int EdgeFirst, int EdgeSecond) const
{
    OneList * tab_list;
    tab_list = GraphList[EdgeFirst];
    while (tab_list)
    {
        if (tab_list->Neighbor == EdgeSecond) return true;
        else tab_list = tab_list->Next;
    }
    return false;
}