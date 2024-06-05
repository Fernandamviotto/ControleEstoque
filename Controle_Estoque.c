/*
Autor.....: Fernanda Viotto
Data......: 28/05/2024
Objetivo..: Desenvolver um controle de estoque usando lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

// Dados produto
typedef struct
{
    int cd_produto;
    char nm_produto[50];
    char und_produto;
    char dt_validade[11];
    float qtd_produto;
    double vl_produto;
} reg_produto;

typedef struct TipoItem *TipoApontador;

typedef struct TipoItem
{
    reg_produto conteudo;
    TipoApontador proximo;
} TipoItem;

typedef struct
{
    TipoApontador Primeiro;
    TipoApontador Ultimo;
} TipoLista;

// Dados movimentação estoque
typedef struct
{
    char dt_mov[11];
    int cd_prod_mov;
    char tp_mov;
    float qt_mov;
    float vl_unit_mov;
    float vl_total_mov;
} reg_movimentacao;

typedef struct TipoItem_mov *TipoApontador_mov;

typedef struct TipoItem_mov
{
    TipoApontador_mov anterior_mov;
    reg_movimentacao conteudo_mov;
    TipoApontador proximo_mov;
} TipoItem_mov;

typedef struct
{
    TipoApontador_mov Primeiro_mov;
    TipoApontador_mov Ultimo_mov;
} TipoLista_mov;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Mostra a Tela Padrao
void tela()
{

    int t;
    system("cls");
    system("color 2E");
    gotoxy(01, 01);
    printf("+--------------------------------------------------------------------------------------------+");
    gotoxy(01, 02);
    printf("| UNICV");
    gotoxy(75, 02);
    printf("Estrutura de Dados |");
    gotoxy(01, 03);
    printf("|");
    gotoxy(94, 03);
    printf("|");
    gotoxy(40, 02);
    printf("CONTROLE DE ESTOQUE");
    gotoxy(01, 04);
    printf("+--------------------------------------------------------------------------------------------+");
    for (t = 5; t < 24; t++)
    {
        gotoxy(01, t);
        printf("|");
        gotoxy(94, t);
        printf("|");
    }

    gotoxy(01, 22);
    printf("+--------------------------------------------------------------------------------------------+");
    gotoxy(02, 23);
    printf("MSG.:");
    gotoxy(01, 24);
    printf("+--------------------------------------------------------------------------------------------+");
}

// Tela de movimentacao
void TelaMov()
{
    tela();
    gotoxy(12, 6);
    printf("Codigo do Produto.....:");
    gotoxy(12, 8);
    printf("Data da Movimentacao..:");
    gotoxy(12, 10);
    printf("Tipo de Movimentacao..:");
    gotoxy(12, 12);
    printf("Quantidade............:");
    gotoxy(12, 14);
    printf("Valor unitario........:");
    gotoxy(12, 16);
    printf("Valor Total...........:");
    gotoxy(12, 18);
    printf("+---------------------+----------------------+----------------------+");
    gotoxy(12, 19);
    printf("|     Quantidade      |     Custo Médio      |      Valor Total     |");
    gotoxy(12, 20);
    printf("+---------------------+----------------------+----------------------+");
    gotoxy(12, 21);
    printf("|                     |                      |                      |");
    gotoxy(12, 22);
    printf("+---------------------+----------------------+----------------------+");
}

void cadastrarFinal(TipoLista *L)
{
    TipoApontador P;
    TipoApontador aux1;
    int resp;
    reg_produto reg_prod;
    gotoxy(30, 03);
    printf("CADASTRAR PRODUTO NO FIM");
    do
    {
        gotoxy(30, 03);
        printf("               ");
        gotoxy(30, 03);
        scanf("%d", &reg_prod.cd_produto);
        getchar();
        // aux1 = pesquisa(L, reg_prod.cd_produto);
        if (aux1 != NULL)
        {
            gotoxy(30, 03);
            printf("               ");
            gotoxy(30, 03);
            printf("Codigo ja Cadsatrado");
            getch();
            gotoxy(30, 03);
            printf("               ");
        }
    } while (aux1 != NULL);
    // Le os dados do produto
    // Leitura(&reg_prod);

    gotoxy(30, 03);
    printf("Deseja gravar os dados (1-Sim; 2-NAO)..:");
    scanf("%d", &resp);
    if (resp == 1)
    {
        P = (TipoApontador)malloc(sizeof(TipoItem));
        // move os valores lidos para os ponteiros
        P->conteudo = reg_prod;
        if (L->Primeiro == NULL)
        {
            L->Primeiro = P;
            L->Primeiro->proximo = NULL;
            L->Ultimo = L->Primeiro;
        }
        else
        {
            L->Ultimo->proximo = P;
            L->Ultimo = L->Ultimo->proximo;
            L->Ultimo->proximo = NULL;
        }
    }
}

int MenuProduto(TipoLista *L)
{

    int opc;
    do
    {
        tela();
        gotoxy(30, 03);
        printf("MENU PRODUTO");
        gotoxy(20, 7);
        printf("1 - Cadastar Produto no Final da Lista");
        gotoxy(20, 8);
        printf("2 - Cadastar Produto no Inicio da Lista");
        gotoxy(20, 9);
        printf("3 - Cadastar Produto em uma posicao da Lista");
        gotoxy(20, 10);
        printf("4 - Remover Produto no Final da Lista");
        gotoxy(20, 11);
        printf("5 - Remover Produto na posicao da Lista");
        gotoxy(20, 12);
        printf("6 - Remover Produto no Inicio da Lista");
        gotoxy(20, 13);
        printf("7 - Consultar todos os Produtos");
        gotoxy(20, 14);
        printf("8 - Alterar dados do Produto");
        gotoxy(20, 15);
        printf("9 - Retornar ao Menu Principal");
        gotoxy(8, 23);
        printf("Digite sua opcao..:");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            // incluir menu a de cadastro
            break;

        case 7:
            // incluir o menu de consulta
            break;

        default:
            break;
        }
    } while (opc < 9);
}

void MenuConsultar(TipoLista *L)
{

    int opc;
    do
    {
        tela();
        gotoxy(30, 03);
        printf("CONSULTAR PRODUTO");
        gotoxy(20, 7);
        printf("1 - Consultar Fichario do Produto Geral");
        gotoxy(20, 8);
        printf("2 - Consultar em Ordem de Codigo");
        gotoxy(20, 9);
        printf("3 - Consultar em Ordem Alfabetica");
        gotoxy(20, 10);
        printf("4 - Consultar o Codigo Especifico");
        gotoxy(20, 11);
        printf("5 - Retornar Menu Principal");
        gotoxy(8, 23);
        printf("Digite sua opcao..:");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            // incluir consultar todos
            break;

        default:
            break;
        }
    } while (opc < 6);
}

int main()
{

    int opc;
    TipoLista L;
    TipoLista_mov M;
    // para iniciar a cabeça deve estar fazia
    // LISTA DE PRODUTO
    L.Primeiro = NULL;
    L.Ultimo = NULL;
    // LISTA DE MOVIMENTACAO
    M.Primeiro_mov = NULL;
    M.Ultimo_mov = NULL;

    setlocale(LC_ALL, "portuguese-brazilian");
    // fica dentro de um Do While para o usuario escolher dentre as opções
    do
    {
        tela();
        gotoxy(40, 03);
        printf("MENU PRINCIPAL");
        gotoxy(20, 7);
        printf("1 - Menu Cadastro de Produto");
        gotoxy(20, 10);
        printf("2 - Menu Movimentacao de Estoque");
        gotoxy(20, 13);
        printf("3 - Finalizar o Programa");
        gotoxy(8, 23);
        printf("Digite sua opcao..:");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            MenuProduto(&L);
            break;

        case 2:
            MenuConsultar(&L);
            break;

        default:
            break;
        }

    } while (opc < 4);
    return 0;
}