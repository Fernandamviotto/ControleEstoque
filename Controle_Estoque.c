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

typedef struct
{
    int cd_produto;
    char nm_produto[50];
    char dt_cadastro[19];
    int qtd_produto;
    double vl_produto;
} produto;

typedef struct TipoItem *TipoApontador;

typedef struct TipoItem
{
    produto conteudo;
    TipoApontador proximo;
} TipoItem;

typedef struct
{
    TipoApontador Primeiro;
    TipoApontador Ultimo;
} TipoLista;

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
    printf("| Fernanda");
    gotoxy(75, 02);
    printf("Estrutura de Dados |");
    gotoxy(01, 03);
    printf("|");
    gotoxy(94, 03);
    printf("|");
    gotoxy(40, 02);
    printf("  UNICV");
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
        gotoxy(20, 10);
        printf("4 - Remover Cliente no Final da Lista");
        gotoxy(20, 11);
        printf("5 - Remover Cliente na Posicao da Lista");
        gotoxy(20, 12);
        printf("6 - Remover Cliente no Inicio da Lista");
        gotoxy(20, 13);
        printf("7 - Consultar todos os Clientes");
        gotoxy(20, 14);
        printf("8 - Alterar dados do Cliente");
        gotoxy(20, 15);
        printf("9 - Finalizar Programa");
        gotoxy(8, 23);
        printf("Digite sua opcao..:");
        scanf("%d", &opc);
    } while (opc < 9);
    return 0;
}