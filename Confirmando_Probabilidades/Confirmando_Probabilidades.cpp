#include <iostream> // Trabalho feito por Gustavo Coelho e João Vitor Custódio na disciplina de Algoritmos e Programação II
#include <time.h>

int const num_lados = 5; // Não fizemos a leitura do número de lados pois não é permitida a alocação dinâmica do vetor

void leitura(int &numRepet);
void contar(int numRepet, int lados[]);
int menu();

int main()
{
    srand(time(NULL));

    int lados[num_lados] = { 0 };
    int numRepet = 0;

    switch (menu())
    {
    
    case 1:
        
        leitura(numRepet);
        contar(numRepet, lados);
        break;
    
    case 2:
        
        std::cout << "deu 2";
        break;
    
    case 3:
        
        std::cout << "deu 3";
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

void contar(int numRepet, int lados[]) {
    
    for (int i = 0; i < numRepet; i++) {
        
        int valor = rand() % num_lados + 1;
        lados[valor - 1] ++;
    }
    return;
}