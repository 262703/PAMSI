#include "list.hpp"
#include "matrix.hpp"

#include <chrono>
#include <iomanip>

void MatrixBellmanFord(Matrix GraphMatrix, std::fstream& File);
void ListBellmanFord(List GraphList, std::fstream& File);
void OnMyWay(int* PayToGo, int Edg, int* Way, std::fstream& File);