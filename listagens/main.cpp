#include <iostream>
#include "CSimuladorESPPerformance.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
    CSimuladorESPPerformance simulador;
    char continuar{'s'};
    do
    {
        simulador.AlturaElevacao();
        simulador.PlotarResultado();
        std::cout << "\n\n\aContinuar? (s)(n): ";
        std::cin >> continuar;
    }while(continuar == 's' or continuar == 'S');
    return 0;
}
