#include "algor.h"

template<typename Tab>
Tab *New_Tab(int n)
{
    return new Tab[n];
}

template<typename Tab>
void kill(Tab *Tablica)
{
    delete [] Tablica;
}

template<typename Tab>
void print(Tab *Tablica, int n)
{
    for (int i = 0; i < n; i++)
    std::cout << Tablica[i] << " ";
    std::cout << std::endl;
}

template<typename Tab>
void random(Tab *Tablica_do_sort, int n)
{
    for (int i = 0; i < n ; i++)
    Tablica_do_sort[i] = rand() % 10000 + 1;
}

template<typename TAB>
void sort_begin(TAB *Tablica_do_sort, int n, double Procent)
{
    if (Procent == -100)
    {
        std::sort(Tablica_do_sort, Tablica_do_sort + n, std::greater());
        return;
    }
    std::sort(Tablica_do_sort, Tablica_do_sort + (int)(n * Procent / 100));
}

template<typename TAB>
void check(TAB *Tablica_do_sort, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (Tablica_do_sort[i] > Tablica_do_sort[i+1])
        {
            std::cout << "Nieprawidlowe sortowanie!!!" << std::endl;
            exit(1);
        }
    }
}


int main()
{
    int ilosc_elementow[5] = {10000, 50000, 100000, 500000, 1000000};
    double Procent_sortowania[9] = {0, 25, 50, 75, 95, 99, 99.7, -100, 100};
    std::cout << "Mergesort" << std::endl;
    for (double procent : Procent_sortowania)
    {
        if (procent == -100)
            std::cout << "Reverse sortowania" << std::endl;
        else
            std::cout << procent << "% sortowana" << std::endl;

        for (int n : ilosc_elementow)
        {
            //double all_time = 0;
            std::cout << n << " elementow - ";
            //for (int i = 1; i <= 100; i++)
            //{
                TYPE *Tablica_do_sort = New_Tab<TYPE>(n);
                TYPE *Pomoc_tablica = New_Tab<TYPE>(n);
                random<TYPE>(Tablica_do_sort, n);
                sort_begin<TYPE>(Tablica_do_sort, n, procent);
                auto begin = std::chrono::steady_clock::now();
                mergesort(Tablica_do_sort, Pomoc_tablica, 0, n - 1);
                auto end = std::chrono::steady_clock::now();
                check(Tablica_do_sort, n);
                auto time = std::chrono::duration<double, std::milli>(end - begin).count();
                //all_time += time;
                kill(Tablica_do_sort);
                kill(Pomoc_tablica);
            //}
            std::cout << time << " ms" << std::endl;
        }
    }

    std::cout << "Quicksort" << std::endl;
    for (double procent : Procent_sortowania)
    {
        if (procent == -100)
            std::cout << "Reverse sortowania" << std::endl;
        else
            std::cout << procent << "% sortowana" << std::endl;

        for (int n : ilosc_elementow)
        {
            //double all_time = 0;
            std::cout << n << " elementow - ";
            //for (int i = 1; i <= 100; i++)
            //{
                TYPE *Tablica_do_sort = New_Tab<TYPE>(n);
                random<TYPE>(Tablica_do_sort, n);
                sort_begin<TYPE>(Tablica_do_sort, n, procent);
                auto begin = std::chrono::steady_clock::now();
                quicksort(Tablica_do_sort, 0, n - 1);
                auto end = std::chrono::steady_clock::now();
                check(Tablica_do_sort, n);
                auto time = std::chrono::duration<double, std::milli>(end - begin).count();
                //all_time += time;
                kill(Tablica_do_sort);
            //}
            std::cout << time << " ms" << std::endl;
        }
    }

    std::cout << "Introsort" << std::endl;
    for (double procent : Procent_sortowania)
    {
        if (procent == -100)
            std::cout << "Reverse sortowania" << std::endl;
        else
            std::cout << procent << "% sortowana" << std::endl;

        for (int n : ilosc_elementow)
        {
            //double all_time = 0;
            std::cout << n << " elementow - ";
            //for (int i = 1; i <= 100; i++)
            //{
                TYPE *Tablica_do_sort = New_Tab<TYPE>(n);
                random<TYPE>(Tablica_do_sort, n);
                sort_begin<TYPE>(Tablica_do_sort, n, procent);
                auto begin = std::chrono::steady_clock::now();
                introsort(Tablica_do_sort, 0, n - 1);
                auto end = std::chrono::steady_clock::now();
                check(Tablica_do_sort, n);
                auto time = std::chrono::duration<double, std::milli>(end - begin).count();
                //all_time += time;
                kill(Tablica_do_sort);
            //}
            std::cout << time << " ms" << std::endl;
        }
    }
    std::cout << "Program done!!!" << std::endl;
}
