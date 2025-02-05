#include <stdio.h>
#include <string.h>

#define ID_BISPO 1
#define ID_TORRE 2
#define ID_RAINHA 3
#define ID_CAVALO 4

void mensagemLimiteMenu(int varLimite, int minLimite, int maxLimite)
{
    if (varLimite < minLimite || varLimite > maxLimite)
    {
        printf("\n\nPor favor, respeite os limites estabelecidos! (MIN: %d, MAX: %d)\n\n", minLimite, maxLimite);
    }
}

int receberDirMovPeca(int minLimite, int maxLimite)
{
    int movPeca;

    do
    {
        printf("\n\nGostaria de movimentar a peça para qual direção? ");
        scanf(" %d", &movPeca);

        mensagemLimiteMenu(movPeca, minLimite, maxLimite);

    } while (movPeca < minLimite || movPeca > maxLimite);

    return movPeca;
}

int selecionarPeca()
{
    int numPeca;

    printf("\nAnalise a lista abaixo:");
    printf("\n%d - Bispo:", ID_BISPO);
    printf("\n%d - Torre:", ID_TORRE);
    printf("\n%d - Rainha:", ID_RAINHA);
    printf("\n%d - Cavalo:", ID_CAVALO);

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

void mostrarMenuMov(int numPeca)
{
    if (numPeca == ID_BISPO || numPeca == ID_RAINHA || numPeca == ID_CAVALO)
    {
        printf("\n\nMenu de movimento da Peça:\n");
        printf("\n1 - Direita/cima:");
        printf("\n2 - Direita/baixo:");
        printf("\n3 - Esquerda/cima:");
        printf("\n4 - Esquerda/baixo:");
    }

    if (numPeca == ID_TORRE || numPeca == ID_RAINHA)
    {
        (numPeca == ID_TORRE) ? printf("\n\nMenu de movimento da Peça:\n") : 0;
        printf("\n5 - Direita:");
        printf("\n6 - Esquerda:");
        printf("\n7 - Cima:");
        printf("\n8 - Baixo:");
    }
}

// Mostra a direção do movimento para as peças que se mexem na diagonal

void diagonalMovPeca(int movPeca, int numPeca, char direcaoHoriz[], char direcaoVerti[], int quantMovPeca)
{

    char nomePeca[9] = "";

    switch (numPeca)
    {
    case ID_BISPO:
        strcpy(nomePeca, "o bispo");
        break;
    case ID_CAVALO:
        strcpy(nomePeca, "o cavalo");
        break;
    case ID_RAINHA:
        strcpy(nomePeca, "a rainha");
        break;

    default:
        break;
    }

    switch (movPeca)
    {
    case 1:
        printf("\nMovimentando %s %d casas para a diagonal direita/cima\n", nomePeca, quantMovPeca);
        strcpy(direcaoHoriz, "direita");
        strcpy(direcaoVerti, "cima");
        break;
    case 2:
        printf("\nMovimentando %s %d casas para a diagonal direita/baixo\n", nomePeca, quantMovPeca);
        strcpy(direcaoHoriz, "direita");
        strcpy(direcaoVerti, "baixo");
        break;
    case 3:
        printf("\nMovimentando %s %d casas para a diagonal esquerda/cima\n", nomePeca, quantMovPeca);
        strcpy(direcaoHoriz, "esquerda");
        strcpy(direcaoVerti, "cima");
        break;
    case 4:
        printf("\nMovimentando %s %d casas para a diagonal esquerda/baixo\n", nomePeca, quantMovPeca);
        strcpy(direcaoHoriz, "esquerda");
        strcpy(direcaoVerti, "baixo");
        break;

    default:
        break;
    }
}

// Mostra a direção do movimento para as peças que se mexem em linha reta

void retilineoMovPeca(int movPeca, int numPeca, char direcaoMov[], int quantMovPeca)
{

    char nomePeca[9] = "";

    switch (numPeca)
    {
    case ID_TORRE:
        strcpy(nomePeca, "a torre");
        break;
    case ID_RAINHA:
        strcpy(nomePeca, "a rainha");
        break;

    default:
        break;
    }

    switch (movPeca)
    {
    case 5: // direita
        printf("\nMovimentando %s %d casas para a direita\n", nomePeca, quantMovPeca);
        strcpy(direcaoMov, "direita");
        break;
    case 6: // esquerda
        printf("\nMovimentando %s %d casas para a esquerda\n", nomePeca, quantMovPeca);
        strcpy(direcaoMov, "esquerda");
        break;
    case 7: // cima
        printf("\nMovimentando %s %d casas para cima\n", nomePeca, quantMovPeca);
        strcpy(direcaoMov, "cima");
        break;
    case 8: // baixo
        printf("\nMovimentando %s %d casas para baixo\n", nomePeca, quantMovPeca);
        strcpy(direcaoMov, "baixo");
        break;

    default:
        break;
    }
}

void direcaoMovPeca(int numPeca, char direcaoHoriz[], char direcaoVerti[], char direcaoMov[], int *quantMovPeca)
{
    int movPeca = 0;

    switch (numPeca)
    {
    case ID_BISPO:
    case ID_CAVALO: // Peças que se movimentam na diagonal

        mostrarMenuMov(numPeca);

        movPeca = receberDirMovPeca(1, 4);

        *quantMovPeca = quantidadeMovPeca();

        diagonalMovPeca(movPeca, numPeca, direcaoHoriz, direcaoVerti, *quantMovPeca);

        break;
    case ID_TORRE: // Peça que se movimenta na horizontal e vertical

        mostrarMenuMov(numPeca);

        movPeca = receberDirMovPeca(5, 8);

        *quantMovPeca = quantidadeMovPeca();

        retilineoMovPeca(movPeca, numPeca, direcaoMov, *quantMovPeca);

        break;
    case ID_RAINHA: // Peça que se movimenta em todas as direções

        mostrarMenuMov(numPeca);

        movPeca = receberDirMovPeca(1, 8);

        *quantMovPeca = quantidadeMovPeca();

        if (movPeca >= 1 && movPeca <= 4)
        {
            diagonalMovPeca(movPeca, numPeca, direcaoHoriz, direcaoVerti, *quantMovPeca);
        }
        else if (movPeca >= 5 && movPeca <= 8)
        {
            retilineoMovPeca(movPeca, numPeca, direcaoMov, *quantMovPeca);
        }

        break;

    default:
        printf("\n\nERRO NA COLETA DA DIREÇÃO DE MOVIMENTO DA PEÇA\n\n");
        break;
    }
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

void movimentaTorre(int quantMovPeca, char direcaoMov[])
{
    if (quantMovPeca > 0)
    {
        (quantMovPeca == 1) ? printf(" %s. \n", direcaoMov) : printf(" %s, \n", direcaoMov);

        quantMovPeca--;
        movimentaTorre(quantMovPeca, direcaoMov);
    }
}

void movimentaRainha(int quantMovPeca, char direcaoMov[], char direcaoHoriz[], char direcaoVerti[])
{
    if (quantMovPeca > 0)
    {
        if (strcmp(direcaoMov, "") == 0)
        {
            printf(" %s, ", direcaoHoriz);
            printf(" %s.\n", direcaoVerti);
        }
        else
        {
            (quantMovPeca == 1) ? printf(" %s. \n", direcaoMov) : printf(" %s, \n", direcaoMov);
        }

        quantMovPeca--;
        movimentaRainha(quantMovPeca, direcaoMov, direcaoHoriz, direcaoVerti);
    }
}

void movimentaCavalo()
{
}

int main()
{
    // Selecionando a peça a ser movimentada:

    const int numPeca = selecionarPeca();
    int quantMovPeca;
    char direcaoHoriz[9] = "", direcaoVerti[6] = "", direcaoMov[9] = "";

    switch (numPeca)
    {
    case ID_BISPO:
        direcaoMovPeca(numPeca, direcaoHoriz, direcaoVerti, direcaoMov, &quantMovPeca);

        movimentaBispo(quantMovPeca, direcaoHoriz, direcaoVerti);
        break;
    case ID_TORRE:
        direcaoMovPeca(numPeca, direcaoHoriz, direcaoVerti, direcaoMov, &quantMovPeca);

        movimentaTorre(quantMovPeca, direcaoMov);
        break;
    case ID_RAINHA:
        direcaoMovPeca(numPeca, direcaoHoriz, direcaoVerti, direcaoMov, &quantMovPeca);

        movimentaRainha(quantMovPeca, direcaoMov, direcaoHoriz, direcaoVerti);
        break;
    case ID_CAVALO:
        movimentaCavalo();
        break;

    default:
        printf("\n\nERRO NO CÓDIGO!\n\n");
        break;
    }

    printf("\n\nVeja suas opções: \n");
    printf("\n\n1 - Reiniciar movimentação \n");
    printf("\n\n2 - Finalizar código\n");

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
