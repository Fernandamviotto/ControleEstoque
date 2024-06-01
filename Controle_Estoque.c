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
    int qtd_produto;
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

// Função de coordenadas para tela padrao
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tela()
{
    int t;
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
    printf("SISTEMA DE CONTROLE DE ESTOQUE");
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

int main()
{

    TipoLista L;
    L.Primeiro = NULL;
    L.Ultimo = NULL;
    int opc;
    setlocale(LC_ALL, "portuguese-brazilian");
    do
    {
        tela();
        gotoxy(30, 03);
        printf("MENU PRINCIPAL");
        gotoxy(20, 7);
        printf("1 - Cadastar Cliente no Final da Lista");
        gotoxy(20, 8);
        printf("2 - Cadastar Cliente no Inicio da Lista");
        gotoxy(20, 9);
        printf("3 - Cadastar Cliente em uma posição da Lista");
        printf("Digite sua opcao..:");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
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
            printf("5 - Remover Produto no Inicio da Lista");
            gotoxy(20, 12);
            printf("6 - Remover Produto em uma posicao da Lista");
            gotoxy(20, 13);
            printf("7 - Consultar todos Produtos");
            gotoxy(20, 14);
            printf("8 - Alterar dados do Produtos");
            gotoxy(20, 15);
            printf("9 - Retornar ao Menu Principal");
            printf("Digite sua opcao..:");
            scanf("%d", &opc);
            break;

        case 2:
            gotoxy(30, 03);
            printf("MENU MOVIMENTACAO DE ESTOQUE");
            gotoxy(20, 7);
            printf("1 - Cadastar Movimentacao de Estoque");
            gotoxy(20, 8);
            printf("2 - Lista Movimentacao de Estoque");
            gotoxy(20, 9);
            printf("3 - Retornar ao Menu Principal");
            break;

        default:
            break;
        }

    } while (opc < 4);
    return 0;
}