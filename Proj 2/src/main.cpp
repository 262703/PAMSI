#include "BF.hpp"

int main()
{
    Matrix GraphMatrix;
    List GraphList;
    std::fstream Exit;
    Exit.open("Result.txt", std::ios_base::app);
    int Edg[5] = {6, 50, 100, 500, 1000};
    double Dens[4] = {0.25, 0.5, 0.75, 1};
    auto AllTimeM = 0, AllTimeL = 0;
    std::fstream File;
    File.open("Way.txt", std::ios_base::app);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int z = 0; z < 1; z++)
            {
                File << "Matrix " << Edg[i] << " edges and " << Dens[j] * 100 << " % density:" << std::endl;
                GraphMatrix.RandomGraph(Edg[i], Dens[j]);
                auto beginM = std::chrono::steady_clock::now();
                MatrixBellmanFord(GraphMatrix, File);
                auto endM = std::chrono::steady_clock::now();
                auto timeM = std::chrono::duration<double, std::micro>(endM - beginM).count();
                AllTimeM += timeM;

                File << "List " << Edg[i] << " edges and " << Dens[j] * 100 << " % density:" << std::endl;
                GraphList.RandomGraph(Edg[i], Dens[j]);
                auto beginL = std::chrono::steady_clock::now();
                ListBellmanFord(GraphList, File);
                auto endL = std::chrono::steady_clock::now();
                auto timeL = std::chrono::duration<double, std::micro>(endL - beginL).count();
                AllTimeL += timeL;
            }
            Exit << Edg[i] << " " << Dens[j] << std::endl;
            Exit << "Matrix: " << AllTimeM / 1 << " us" << std::endl;
            Exit << "List: " << AllTimeL / 1 << " us" << std::endl;
            AllTimeL = 0; AllTimeM = 0;
        }
    }
    File.close();
    Exit.close();
    //test of read, write time and way, print
    std::fstream Fil;
    Fil.open("WayTest.txt", std::ios_base::app);
    GraphMatrix.ReadFile();
    GraphList.ReadFile();
    GraphMatrix.GraphPrint();
    GraphList.GraphPrint();
    auto beginM = std::chrono::steady_clock::now();
    MatrixBellmanFord(GraphMatrix, Fil);
    auto endM = std::chrono::steady_clock::now();
    auto timeM = std::chrono::duration<double, std::micro>(endM - beginM).count();
    auto beginL = std::chrono::steady_clock::now();
    ListBellmanFord(GraphList, Fil);
    auto endL = std::chrono::steady_clock::now();
    auto timeL = std::chrono::duration<double, std::micro>(endL - beginL).count();
    std::cout << "Matrix " << GraphMatrix.getVerticales() << " " << GraphMatrix.getEdges() << " " << GraphMatrix.getStartPoint() << std::endl;
    std::cout << timeM << " us" << std::endl;
    std::cout << "List " << GraphList.getVerticales() << " " << GraphList.getEdges() << " " << GraphList.getStartPoint() << std::endl;
    std::cout << timeL << " us" << std::endl;
    Fil.close();
}