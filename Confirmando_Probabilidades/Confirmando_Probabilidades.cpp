#include <iostream> // Trabalho feito por Gustavo Coelho e João Vitor Custódio na disciplina de Algoritmos e Programação II
#include <time.h>

// Cabeçalho
int menu();
void leitura(int& numLados, int& numRepet);
void contar(int numLados, int numRepet, float contador[]);
void escrever(int numLados, int numRepet, float contador[]);

int main()
{
    srand(time(NULL));

    int numLados = 0; // Número de lados do dado
    int numRepet = 0; // Número de repetições de rolagens
    float contador[100] = { 0 }; // Um contador que corresponde ao número de vezes que cada lado do dado caiu (máximo de 100 lados)

    switch (menu())
    {
    
    case 1:
        
        leitura(numLados, numRepet);
        std::cout << std::endl;
        contar(numLados, numRepet, contador);
        escrever(numLados, numRepet, contador);
        break;
    
    case 2:
        
        std::cout << "em obras";
        break;
    
    case 3:
        
        std::cout << "em obras";
        break;
    
    default:
        
        std::cout << "Valor inexistente.\n";
        break;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu() {
    
    std::cout << "1. Rolar um dado\n"
        << "2. Rolar mais de um dado\n"
        << "3. Avaliar o problema de Monty Hall (DESAFIO)\n\n";

    int escolha = 0;
    std::cin >> escolha;
    return escolha;
}

void leitura(int& numLados, int& numRepet) {
    
    std::cout << "Digite a quantidade de lados do dado (entre 1 e 100): ";
    std::cin >> numLados;
    std::cout << "Digite a quantidade de repet.: ";
    std::cin >> numRepet;
    return;
}

void contar(int numLados, int numRepet, float contador[]) {
    
    int valor = 0;
    for (int i = 0; i < numRepet; i++) {
        
        valor = rand() % numLados + 1;
        contador[valor - 1] ++;
    }
    return;
}

void escrever(int numLados, int numRepet, float contador[]) {
    
    for (int i = 0; i < numLados; i++) {
        std::cout << i + 1 << ": " << contador[i] << "\t";
    }
    
    std::cout << "\n\nDistrib.:\n\n";
    std::cout.precision(3);
    
    for (int i = 0; i < numLados; i++) {
        std::cout << i + 1 << " = " << contador[i] / numRepet * 100 << "%\n";
    }
    return;
}