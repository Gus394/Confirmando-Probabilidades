#include <iostream> // Trabalho feito por Gustavo Coelho e João Vitor Custódio na disciplina de Algoritmos e Programação II
#include <time.h>

int const num_lados = 6; // Não fizemos a leitura do número de lados pois não é permitida a alocação dinâmica do vetor

// Cabeçalho
int menu();
void leitura(int &numRepet);
void contar(int numRepet, float lados[]);
void escreva(int numRepet, float lados[]);

int main()
{
    srand(time(NULL));

    float lados[num_lados] = { 0 };
    int numRepet = 0;

    switch (menu())
    {
    
    case 1:
        
        leitura(numRepet);
        contar(numRepet, lados);
        escreva(numRepet, lados);
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu() {
    
    std::cout << "1. Rolar um dado\n"
        << "2. Rolar mais de um dado\n"
        << "3. Avaliar o problema de Monty Hall (DESAFIO)\n\n";

    int escolha = 0;
    std::cin >> escolha;
    return escolha;
}

void leitura(int &numRepet) {
    
    std::cout << "Digite a quantidade de repet: ";
    std::cin >> numRepet;
    return;
}

void contar(int numRepet, float lados[]) {
    
    int valor = 0;
    for (int i = 0; i < numRepet; i++) {
        
        valor = rand() % num_lados + 1;
        lados[valor - 1] ++;
    }
    return;
}

void escreva(int numRepet, float lados[]) {
    
    for (int i = 0; i < num_lados; i++) {
        std::cout << i + 1 << ": " << lados[i] << "\t";
    }
    
    std::cout << "\n\nDistrib.:\n\n";
    std::cout.precision(3);
    
    for (int i = 0; i < num_lados; i++) {
        std::cout << i + 1 << " = " << lados[i] / numRepet * 100 << "%\n";
    }
    return;
}