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

        if (numPeca == ID_CAVALO)
        {
            printf("\n5 - Cima/direita:");
            printf("\n6 - Baixo/direita:");
            printf("\n7 - Cima/esquerda:");
            printf("\n8 - Baixo/esquerda:");
        }
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

void mostrarMovDiag(int numPeca, int quantMovPeca, char nomePeca[], char textMovPeca[])
{
    if (numPeca == ID_CAVALO)
    {
        printf("\nMovimentando %s para a diagonal %s:\n", nomePeca, textMovPeca);
    }
    else
    {
        printf("\nMovimentando %s %d casas para a diagonal %s:\n", nomePeca, quantMovPeca, textMovPeca);
    }
}

void diagonalMovPeca(int movPeca, int numPeca, char direcaoHoriz[], char direcaoVerti[], int quantMovPeca)
{

    char nomePeca[9] = "";
    char textMovPeca[15] = "";

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
    case 5: // Para auxiliar a coleta do movimento do cavalo
    case 1:
        strcpy(textMovPeca, ((movPeca == 1) ? "direita/cima" : "cima/direita"));

        mostrarMovDiag(numPeca, quantMovPeca, nomePeca, textMovPeca);

        strcpy(direcaoHoriz, "direita");
        strcpy(direcaoVerti, "cima");
        break;
    case 6: // Para auxiliar a coleta do movimento do cavalo
    case 2:
        strcpy(textMovPeca, ((movPeca == 2) ? "direita/baixo" : "baixo/direita"));

        mostrarMovDiag(numPeca, quantMovPeca, nomePeca, textMovPeca);

        strcpy(direcaoHoriz, "direita");
        strcpy(direcaoVerti, "baixo");
        break;
    case 7: // Para auxiliar a coleta do movimento do cavalo
    case 3:
        strcpy(textMovPeca, ((movPeca == 3) ? "esquerda/cima" : "cima/esquerda"));

        mostrarMovDiag(numPeca, quantMovPeca, nomePeca, textMovPeca);

        strcpy(direcaoHoriz, "esquerda");
        strcpy(direcaoVerti, "cima");
        break;
    case 8: // Para auxiliar a coleta do movimento do cavalo
    case 4:
        strcpy(textMovPeca, ((movPeca == 4) ? "esquerda/baixo" : "baixo/esquerda"));

        mostrarMovDiag(numPeca, quantMovPeca, nomePeca, textMovPeca);

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

void direcaoMovPeca(int numPeca, char direcaoHoriz[], char direcaoVerti[], char direcaoMov[], int *quantMovPeca, int *movPeca)
{
    switch (numPeca)
    {
    case ID_BISPO:
    case ID_CAVALO: // Peças que se movimentam na diagonal

        mostrarMenuMov(numPeca);

        *movPeca = (numPeca == ID_BISPO) ? receberDirMovPeca(1, 4) : receberDirMovPeca(1, 8);

        *quantMovPeca = (numPeca == ID_BISPO) ? quantidadeMovPeca() : 0;

        diagonalMovPeca(*movPeca, numPeca, direcaoHoriz, direcaoVerti, *quantMovPeca);
        break;
    case ID_TORRE: // Peça que se movimenta na horizontal e vertical

        mostrarMenuMov(numPeca);

        *movPeca = receberDirMovPeca(5, 8);

        *quantMovPeca = quantidadeMovPeca();

        retilineoMovPeca(*movPeca, numPeca, direcaoMov, *quantMovPeca);
        break;
    case ID_RAINHA: // Peça que se movimenta em todas as direções

        mostrarMenuMov(numPeca);

        *movPeca = receberDirMovPeca(1, 8);

        *quantMovPeca = quantidadeMovPeca();

        if (*movPeca >= 1 && *movPeca <= 4)
        {
            diagonalMovPeca(*movPeca, numPeca, direcaoHoriz, direcaoVerti, *quantMovPeca);
        }
        else if (*movPeca >= 5 && *movPeca <= 8)
        {
            retilineoMovPeca(*movPeca, numPeca, direcaoMov, *quantMovPeca);
        }
        break;

    default:
        printf("\n\nERRO NA COLETA DA DIREÇÃO DE MOVIMENTO DA PEÇA\n\n");
        break;
    }
}

void movimentaBispo(int quantMovPeca, char direcaoHoriz[], char direcaoVerti[])
{
    printf("\n");

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
    printf("\n");

    if (quantMovPeca > 0)
    {
        (quantMovPeca == 1) ? printf(" %s. \n", direcaoMov) : printf(" %s, \n", direcaoMov);
        quantMovPeca--;
        movimentaTorre(quantMovPeca, direcaoMov);
    }
}

void movimentaRainha(int quantMovPeca, char direcaoMov[], char direcaoHoriz[], char direcaoVerti[])
{
    printf("\n");

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

void movimentaCavalo(int movePeca, char direcaoHoriz[], char direcaoVerti[])
{
    printf("\n");
    for (int i = 0, j = 3; i < 3 && j > 0; i++, j--)
    {
        if (movePeca >= 1 && movePeca <= 4)
        {
            printf("%s, ", direcaoHoriz);
            (j == 1) ? printf("%s. \n", direcaoVerti) : 0;
        }
        else if (movePeca >= 5 && movePeca <= 8)
        {
            printf("%s, ", direcaoVerti);
            (j == 1) ? printf("%s. \n", direcaoHoriz) : 0;
        }
    }
}

int main()
{
    int opcMenu = 1;

    do
    {

        // Selecionando a peça a ser movimentada:

        const int numPeca = selecionarPeca();

        int quantMovPeca, movPeca;
        char direcaoHoriz[9] = "", direcaoVerti[6] = "", direcaoMov[9] = "";

        switch (numPeca)
        {
        case ID_BISPO:
            direcaoMovPeca(numPeca, direcaoHoriz, direcaoVerti, direcaoMov, &quantMovPeca, &movPeca);

            movimentaBispo(quantMovPeca, direcaoHoriz, direcaoVerti);
            break;
        case ID_TORRE:
            direcaoMovPeca(numPeca, direcaoHoriz, direcaoVerti, direcaoMov, &quantMovPeca, &movPeca);

            movimentaTorre(quantMovPeca, direcaoMov);
            break;
        case ID_RAINHA:
            direcaoMovPeca(numPeca, direcaoHoriz, direcaoVerti, direcaoMov, &quantMovPeca, &movPeca);

            movimentaRainha(quantMovPeca, direcaoMov, direcaoHoriz, direcaoVerti);
            break;
        case ID_CAVALO:
            direcaoMovPeca(numPeca, direcaoHoriz, direcaoVerti, direcaoMov, &quantMovPeca, &movPeca);

            movimentaCavalo(movPeca, direcaoHoriz, direcaoVerti);
            break;

        default:
            printf("\n\nERRO NO CÓDIGO!\n\n");
            break;
        }

        printf("\n\nVeja suas opções: \n");
        printf("\n1 - Reiniciar movimentação");
        printf("\n2 - Finalizar código");

        do
        {
            printf("\n\nO que deseja fazer? ");
            scanf(" %d", &opcMenu);

            mensagemLimiteMenu(opcMenu, 1, 2);
        } while (opcMenu < 1 || opcMenu > 2);

    } while (opcMenu == 1);

    return 0;
}
