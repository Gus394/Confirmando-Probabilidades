#include <iostream> // Trabalho feito por Gustavo Coelho e João Vitor Custódio na disciplina de Algoritmos e Programação II
#include <time.h>

// Cabeçalho
int menu();

void leitura(int& lados, int& repet);
void leitura(int& dados, int& lados, int& repet);

void contar(int lados, int repet, float contador[]);
void contar(int dados, int lados, int repet, float contador[]);

void escrever(int dados, int lados, int repet, float contador[]);

void monty_hall();

int main()
{
    srand(time(NULL));

    int dados = 1;
    int lados = 0;
    int repet = 0; // Número de repetições de rolagens
    
    float contador[100] = { 0 }; // Um contador que corresponde ao número de vezes que cada lado ou combinação caiu (máximo de 100 lados)

    switch (menu())
    {
    
    case 1:
        
        leitura(lados, repet);
        std::cout << "\n";
        contar(lados, repet, contador);
        escrever(dados, lados, repet, contador);
        break;
    
    case 2:

        leitura(dados, lados, repet);
        std::cout << "\n";
        contar(dados, lados, repet, contador);
        escrever(dados, lados, repet, contador);
        break;

    case 3:

        monty_hall();
        break;
    
    default:
        
        std::cout << "Valor inexistente.\n";
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu() {
    
    std::cout << "1. Rolar um dado\n"
        << "2. Rolar mais de um dado\n"
        << "3. Avaliar o problema de Monty Hall (DESAFIO)\n\n";

    int escolha = 0;
    std::cin >> escolha;
    return escolha;
}

void leitura(int& lados, int& repet) {
    
    do {
        std::cout << "Digite a quantidade de lados do dado (entre 1 e 100): ";
        std::cin >> lados;

    } while (lados < 1 || lados > 100); // O programa não continuará até ser digitado um valor válido

    do {
        std::cout << "Digite a quantidade de repet. (maior que 0): ";
        std::cin >> repet;

    } while (repet <= 0);
}

void leitura(int& dados, int& lados, int& repet) { // Leitura para quando for mais de um dado

    do {
        std::cout << "Digite a quantidade de lados dos dados (entre 1 e 50): "; // 50 porque 2 * 50 = 100 (máximo)
        std::cin >> lados;

    } while (lados < 1 || lados > 50);
    
    do {
        std::cout << "Digite a quantidade de dados (maior que 1 E o produto com a quantidade de lados menor ou igual a 100): ";
        std::cin >> dados;

    } while (dados <= 1 || dados * lados > 100);

    do {
        std::cout << "Digite a quantidade de repet. (maior que 0): ";
        std::cin >> repet;

    } while (repet <= 0);
}

void contar(int lados, int repet, float contador[]) { // Rola um dado e conta quantas vezes determinado lado caiu
    
    int valor = 0;
    
    for (int i = 0; i < repet; i++) {
        
        valor = rand() % lados;
        contador[valor]++; // Considere o valor '0' correspondente ao lado '1' do dado, and so on
    }
}

void contar(int dados, int lados, int repet, float contador[]) { // No caso de rolar mais de um dado

    int valor = 0;
    int valor_total = 0;

    for (int i = 0; i < repet; i++) {
        for (int i = 0; i < dados; i++) {
            
            valor = rand() % lados + 1; // Aqui o valor mínimo não pode ser 0, pois é somado em seguida (por isso o +1)
            valor_total += valor;
        }
        contador[valor_total - 1]++;
        valor_total = 0;
    }
}

void escrever(int dados, int lados, int repet, float contador[]) { // Escreve o resultado das funções 'contar'
    
    for (int i = 0; i < lados * dados; i++) {                      // <- Este laço exibe a quantidade; o laço abaixo, a porcentagem
        std::cout << i + 1 << ": " << contador[i] << "\t";
    }
    
    std::cout << "\n\nDistrib.:\n\n";
    std::cout.precision(3); // Limita a quantidade de digitos para não exibir muitas casas depois da vírgula
    
    for (int i = 0; i < lados * dados; i++) {
        std::cout << i + 1 << " = " << contador[i] / repet * 100 << "%\n";
    }
}

void monty_hall() {

    int porta_certa = 0, porta_escolhida = 0, porta_errada = 0, primeira_porta = 0, numPartidas = 0;
    float acertos = 0, taxa_de_vit = 0;
    char resposta = 's';

    for (;;) { // Para simular, preencha o 'for' e remova os couts, cins e pausas. Também altere o valor da variável 'resposta'

        porta_certa = rand() % 3 + 1;
        porta_escolhida = rand() % 3 + 1;
        primeira_porta = porta_escolhida;

        do {
            porta_errada = rand() % 3 + 1;

        } while (porta_errada == porta_certa || porta_errada == porta_escolhida);

        system("CLS");

        std::cout << "Controles: digite 's' para trocar, 'n' para continuar e 'x' para sair do programa.\n\n";
        std::cout << "Escolheu a porta " << porta_escolhida << ". Sendo a porta " << porta_errada << " errada, trocar para a outra porta? (s/n)"
            << "\tTaxa de acerto: " << taxa_de_vit << "%\n\n";
        std::cin >> resposta;

        if (resposta == 'x') {
            return;
        }

        if (resposta == 's') {
            do {
                porta_escolhida = rand() % 3 + 1;

            } while (porta_escolhida == primeira_porta || porta_escolhida == porta_errada);
            std::cout << "\nTrocou de porta e...\n";
        }

        if (porta_escolhida == porta_certa) {
            std::cout << "\nGanhou!\n\n";
            acertos++;
        }
        else {
            std::cout << "\nPerdeu.\n\n";
        }

        numPartidas++;
        taxa_de_vit = acertos / numPartidas * 100;

        system("pause");
    }
}