// SolucionSumaArreglosParalela2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>

#define N 800
#define chunk 80
#define mostrar 15

void imprimirArreglo(float* aR);

int main()
{
    std::cout << "Sumando nuestros Arreglos en Paralelo!\n";
    float a[N], b[N], c[N];
    int i;
    int num = 1;

    for (i = 0; i < N; i++)
    {
        a[i] = num * 10;
        b[i] = (num + 2) * 1.6;
        num = num + 1;
    }

    int pedazos = chunk;

    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)

    for (i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
    }

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo A: " <<std::endl;
    imprimirArreglo(a);
    std::cout << "\n";
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo B: " << std::endl;
    imprimirArreglo(b);
    std::cout << "\n";
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo C: " << std::endl;
    imprimirArreglo(c);
    std::cout << "\n";
}

void imprimirArreglo(float* aR)
{
    for (int x = 0; x < mostrar; x++)
        if(x == (mostrar - 1))
            std::cout << aR[x];
        else
            std::cout << aR[x] << " - ";
    std::cout << std::endl;
}
