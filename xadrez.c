#include <stdio.h>

int selecionarPeca()
{
    int numPeca;
    do
    {
        printf("\nAnalise a lista abaixo:");
        printf("\n1 - Bispo:");
        printf("\n2 - Torre:");
        printf("\n3 - Rainha:");
        printf("\n4 - Cavalo:");

        printf("\nDigite a peça que deseja mover: ");
        scanf(" %d \n", &numPeca);

        if (numPeca < 1 || numPeca > 4)
        {
            printf("\n\nPor favor, selecione a peça de 1 a 3\n\n");
            continue;
        }

    } while (numPeca != 1 && numPeca != 2 && numPeca != 3);

    return numPeca;
}

int direcaoMovPeca(int numPeca)
{
    int movPeca = 0;

    switch (numPeca)
    {
    case 1:
    case 4: // Peças que se movimentam na diagonal (1 - Bispo; 4 - Cavalo)
        printf("\n\nMenu de movimento da Peça:\n");
        printf("\n1 - Direita/cima:");
        printf("\n2 - Direita/baixo:");
        printf("\n3 - Esquerda/cima:");
        printf("\n4 - Esquerda/baixo:");

        printf("\n\nGostaria de movimentar a peça para qual direção?\n");
        scanf(" %d", &movPeca);
        return movPeca;
        break;
    case 2: // Peça que se movimenta na horizontal e vertical (2 - Torre)
        printf("\n\nMenu de movimento da Peça:\n");
        printf("\n1 - Direita:");
        printf("\n2 - Esquerda:");
        printf("\n3 - Cima:");
        printf("\n4 - Baixo:");

        printf("\n\nGostaria de movimentar a peça para qual direção?\n");
        scanf(" %d", &movPeca);
        return movPeca;
        break;
    case 3: // Peça que se movimenta em todas as direções (3 - Rainha)
        printf("\n\nMenu de movimento da Peça:\n");
        printf("\n1 - Direita/cima:");
        printf("\n2 - Direita/baixo:");
        printf("\n3 - Esquerda/cima:");
        printf("\n4 - Esquerda/baixo:");
        printf("\n5 - Direita:");
        printf("\n6 - Esquerda:");
        printf("\n7 - Cima:");
        printf("\n8 - Baixo:");

        printf("\n\nGostaria de movimentar a peça para qual direção?\n");
        scanf(" %d", &movPeca);
        return movPeca;
        break;

    default:
        break;
    }
}

int quantidadeMovPeca()
{
    int quantMovPeca = 0;

    print("Quantas casas deseja movimentar a peça? (Max 8)");
    scanf(" %d", &quantMovPeca);
}

void movimentaBispo(int numPeca)
{
    int movPeca = direcaoMovPeca(numPeca);
    int quantCasas = quantidadeMovPeca();

    switch (movPeca)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;

    default:
        break;
    }

    printf("\nMovimentando o bispo 5 casas na diagonal direita/cima:\n\n");
}

void movimentaTorre(int numPeca)
{
}

void movimentaRainha(int numPeca)
{
}

void movimentaCavalo(int numPeca)
{
}

int main()
{
    // const char direita = 'direita';
    // const char esquerda = 'esquerda';
    // const char cima = 'cima';
    // const char baixo = 'baixo';

    // Selecionando a peça a ser movimentada:

    const int numPeca = selecionarPeca();

    switch (numPeca)
    {
    case 1: // Bispo
        movimentaBispo(numPeca);
        break;
    case 2: // Torre
        movimentaTorre(numPeca);
        break;
    case 3: // Rainha
        movimentaRainha(numPeca);
        break;
    case 4: // Cavalo
        movimentaCavalo(numPeca);
        break;

    default:
        printf("\n\nERRO NO CÓDIGO!\n\n");
        break;
    }

    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    return 0;
}
