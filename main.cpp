#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;

#include <omp.h>
#include <iostream>

#define N 200
#define chunk 10
#define mostrar 10

void imprimeArreglo(float* d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo! \n";
    float a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++)
    {
        a[i] = i * 30;
        a[i] = (i + 3) * 13.7;
    }
    int pedazos = chunk;

    #pragma omp parallel for \
        shared(a, b, c, pedazos) private(i) \
        schedule(static, pedazos)

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a:" << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b:" << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c:" << std::endl;
    imprimeArreglo(c);

}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}





//std::cout << "Verificando la ejecucion de las directivas OMP!\n";

// # ifdef _OPENMP

// std::cout << "OMP disponible y funcionando\n");
// # endif




//std::cout << "Regiones paralelas\n";
//int hilos, tid;
//
//#pragma omp parallel private(tid)
//{
//    tid = omp_get_thread_num();
//    std::cout << "Trabajando en el thread: " << tid << std::endl;
//    if (tid == 0)
//    {
//        hilos = omp_get_num_threads();
//        std::cout << "Numero de threads es: " << hilos << std::endl;
//    }
//
//}