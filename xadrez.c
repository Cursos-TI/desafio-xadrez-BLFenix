#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int selecionarPeca()
{
    int numPeca;
    do
    {
        printf("\nAnalise a lista abaixo:");
        printf("\n1 - Bispo:");
        printf("\n2 - Torre:");
        printf("\n3 - Rainha:");

        printf("Digite a peça que deseja mover:");
        scanf(" %d", &numPeca);

        if (numPeca != 1 && numPeca != 2 && numPeca != 3)
        {
            printf("Por favor, selecione a peça de 1 a 3");
            continue;
        }

    } while (numPeca != 1 && numPeca != 2 && numPeca != 3);

    return numPeca;
}

int main()
{
    const char direita = 'direita';
    const char esquerda = 'esquerda';
    const char cima = 'cima';
    const char baixo = 'baixo';
    int numPeca = selecionarPeca();

    switch (numPeca)
    {
    case 1: // Bispo

        break;
    case 2: // Torre

        break;
    case 3: // Rainha

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
