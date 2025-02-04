#include <stdio.h>
#include <string.h>

void mensagemLimiteMenu(int varLimite, int minLimite, int maxLimite)
{
    if (varLimite < minLimite || varLimite > maxLimite)
    {
        printf("\n\nPor favor, respeite os limites estabelecidos! (MIN: %d, MAX: %d)\n\n", minLimite, maxLimite);
    }
}

int selecionarPeca()
{
    int numPeca;

    printf("\nAnalise a lista abaixo:");
    printf("\n1 - Bispo:");
    printf("\n2 - Torre:");
    printf("\n3 - Rainha:");
    printf("\n4 - Cavalo:");

    do
    {

        printf("\nDigite a peça que deseja mover: ");
        scanf(" %d", &numPeca);

        mensagemLimiteMenu(numPeca, 1, 4);

    } while (numPeca < 1 || numPeca > 4);

    return (numPeca);
}

int quantidadeMovPeca()
{
    int quantMovPeca = 0;
    do
    {
        printf("\nQuantas casas deseja movimentar a peça? (Max 8) ");
        scanf(" %d", &quantMovPeca);

        mensagemLimiteMenu(quantMovPeca, 1, 8);

    } while (quantMovPeca < 1 || quantMovPeca > 8);

    return (quantMovPeca);
}

int direcaoMovPeca(int numPeca, char direcaoHoriz[], char direcaoVerti[], int *quantMovPeca)
{
    int movPeca = 0;
    char nomePeca[9] = "";

    switch (numPeca)
    {
    case 1:
    case 4: // Peças que se movimentam na diagonal (1 - Bispo; 4 - Cavalo)
        printf("\n\nMenu de movimento da Peça:\n");
        printf("\n1 - Direita/cima:");
        printf("\n2 - Direita/baixo:");
        printf("\n3 - Esquerda/cima:");
        printf("\n4 - Esquerda/baixo:");

        do
        {
            printf("\n\nGostaria de movimentar a peça para qual direção? ");
            scanf(" %d", &movPeca);

            mensagemLimiteMenu(movPeca, 1, 4);

        } while (movPeca < 1 || movPeca > 4);

        *quantMovPeca = quantidadeMovPeca();
        strcpy(nomePeca, (numPeca == 1) ? "o bispo" : "o cavalo");

        switch (movPeca)
        {
        case 1:
            printf("\nMovimentando %s %d casas para a diagonal direita/cima\n", nomePeca, *quantMovPeca);
            strcpy(direcaoHoriz, "direita");
            strcpy(direcaoVerti, "cima");
            break;
        case 2:
            printf("\nMovimentando %s %d casas para a diagonal direita/baixo\n", nomePeca, *quantMovPeca);
            strcpy(direcaoHoriz, "direita");
            strcpy(direcaoVerti, "baixo");
            break;
        case 3:
            printf("\nMovimentando %s %d casas para a diagonal esquerda/cima\n", nomePeca, *quantMovPeca);
            strcpy(direcaoHoriz, "esquerda");
            strcpy(direcaoVerti, "cima");
            break;
        case 4:
            printf("\nMovimentando %s %d casas para a diagonal esquerda/baixo\n", nomePeca, *quantMovPeca);
            strcpy(direcaoHoriz, "esquerda");
            strcpy(direcaoVerti, "baixo");
            break;

        default:
            break;
        }

        return (movPeca);
        break;
    case 2: // Peça que se movimenta na horizontal e vertical (2 - Torre)
        printf("\n\nMenu de movimento da Peça:\n");
        printf("\n1 - Direita:");
        printf("\n2 - Esquerda:");
        printf("\n3 - Cima:");
        printf("\n4 - Baixo:");

        do
        {
            printf("\n\nGostaria de movimentar a peça para qual direção? ");
            scanf(" %d", &movPeca);

            mensagemLimiteMenu(movPeca, 1, 4);

        } while (movPeca < 1 || movPeca > 4);

        return (movPeca);
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

        do
        {
            printf("\n\nGostaria de movimentar a peça para qual direção? ");
            scanf(" %d", &movPeca);

            mensagemLimiteMenu(movPeca, 1, 4);

        } while (movPeca < 1 || movPeca > 4);

        return (movPeca);
        break;

    default:
        break;
    }

    printf("\n\nERRO NA COLETA DA DIREÇÃO DE MOVIMENTO DA PEÇA\n\n");
    return 0;
}

void movimentaBispo(int quantMovPeca, char direcaoHoriz[], char direcaoVerti[])
{
    if (quantMovPeca > 0)
    {
        printf(" %s, ", direcaoHoriz);
        printf(" %s.\n", direcaoVerti);
        quantMovPeca--;
        movimentaBispo(quantMovPeca, direcaoHoriz, direcaoVerti);
    }
}

void movimentaTorre()
{
}

void movimentaRainha()
{
}

void movimentaCavalo()
{
}

int main()
{
    // Selecionando a peça a ser movimentada:

    const int numPeca = selecionarPeca();
    int quantMovPeca;
    char direcaoHoriz[9] = "", direcaoVerti[6] = "";

    switch (numPeca)
    {
    case 1: // Bispo
        direcaoMovPeca(numPeca, direcaoHoriz, direcaoVerti, &quantMovPeca);

        movimentaBispo(quantMovPeca, direcaoHoriz, direcaoVerti);
        break;
    case 2: // Torre
        movimentaTorre();
        break;
    case 3: // Rainha
        movimentaRainha();
        break;
    case 4: // Cavalo
        movimentaCavalo();
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
