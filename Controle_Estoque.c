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

void home()
{
    int h;
    system("cls");
    system("color 0B");
    gotoxy(01, 01);
    printf("+--------------------------------------------------------------------------------------------------+");
    gotoxy(01, 03);
    printf("|");
    gotoxy(100, 03);
    printf("|");
    gotoxy(38, 04);
    printf("CONTROLE  DE  ESTOQUE  LOJA");
    gotoxy(41, 24);
    printf("FRUTAS  &  VERDURAS");
    gotoxy(44, 27);
    printf("BOX  07  MGA-PR");

    gotoxy(02, 8);
    printf("                                FFFFFFFFFFF                  LLLLL");
    gotoxy(02, 9);
    printf("                                FFFFFFFFFFF                  LLLLL");
    gotoxy(02, 10);
    printf("                                FFFF                         LLLLL");
    gotoxy(02, 11);
    printf("                                FFFF                         LLLLL");
    gotoxy(02, 12);
    printf("                                FFFF                         LLLLL");
    gotoxy(02, 13);
    printf("                                FFFFFFFF       &&&&&&&&      LLLLL");
    gotoxy(02, 14);
    printf("                                FFFFFFFF       &&&&&&&&      LLLLL");
    gotoxy(02, 15);
    printf("                                FFFF           &&&           LLLLL");
    gotoxy(02, 16);
    printf("                                FFFF           &&&&&         LLLLL");
    gotoxy(02, 17);
    printf("                                FFFF           &&&&&         LLLLL");
    gotoxy(02, 18);
    printf("                                FFFF           &&&           LLLLL");
    gotoxy(02, 19);
    printf("                                FFFF           &&&&&&&&      LLLLLLLLLLLLLLLL");
    gotoxy(02, 20);
    printf("                                FFFF           &&&&&&&&      LLLLLLLLLLLLLLLL");

    for (h = 2; h < 30; h++)
    {
        gotoxy(01, h);
        printf("|");
        gotoxy(100, h);
        printf("|");
    }
    gotoxy(01, 30);
    printf("+--------------------------------------------------------------------------------------------------+");
}

// Mostra a Tela Padrao
void tela()
{

    int t;
    system("cls");
    system("color 0C");
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
    gotoxy(38, 02);
    printf("CONTROLE DE ESTOQUE");
    gotoxy(78, 03);
    printf("Fernanda Viotto |");
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

void telaProduto()
{
    tela();
    gotoxy(12, 07);
    printf("Codigo do Produto........:");
    gotoxy(12, 8);
    printf("1 - Descricao do Produto.:");
    gotoxy(12, 9);
    printf("2 - Unidade de Medida....:");
    gotoxy(12, 10);
    printf("3 - Data de Validade.....:");
}

// Funções MENU PRODUTO
// alterar

/*void alterarProduto(TipoLista *L)
{
}*/

//  cadastrar produto no inicio da lista
void cadastrarInicio(TipoLista *L)
{
    TipoApontador P;
    TipoApontador aux1;
    int resp;
    reg_produto reg_prod;

    do
    {
        tela();
        gotoxy(30, 03);
        printf("CADASTRAR PRODUTO NO INICIO");
        // chamar tela do meio
        telaProduto();
        gotoxy(12, 07); // arrumar o cursor
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
    // Leitura(&reg_prod); Incluir a tela de leitura

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
            P->proximo = L->Primeiro;
            L->Primeiro = P;
        }
    }
}

// função pesquisar
/*TipoApontador pesquisa(TipoLista *L, int codigo)
{
    TipoApontador aux;
    aux = L->Primeiro;
    // while(aux)
}*/

// cadastrar produtono final da lista
void cadastrarFinal(TipoLista *L)
{
    TipoApontador P;
    TipoApontador aux1;
    int resp;
    reg_produto reg_prod;

    do
    {
        tela();
        gotoxy(30, 03);
        printf("CADASTRAR PRODUTO NO FIM");
        // chamar tela do meio
        telaProduto();
        gotoxy(37, 06); // arrumar o cursor
        scanf("%d", &reg_prod.cd_produto);
        getchar();
        // aux1 = pesquisa(L, reg_prod.cd_produto);
        if (aux1 != NULL)
        {
            gotoxy(37, 06);
            printf("               ");
            gotoxy(37, 06);
            printf("Codigo ja Cadsatrado");
            getch();
            gotoxy(30, 03);
            printf("               ");
        }
    } while (aux1 != NULL);
    // Le os dados do produto
    // Leitura(&reg_prod); Incluir a tela de leitura

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

// cadastrar produto em uma posicao da lista
void cadastrarPosicao(TipoLista *L)
{
    TipoApontador P;
    TipoApontador aux1;
    int resp;
    reg_produto reg_prod;
    int posicao;

    do
    {
        tela();
        gotoxy(30, 03);
        printf("CADASTRAR PRODUTO EM UMA POSICAO");
        // chamar tela do meio
        telaProduto();
        gotoxy(12, 07); // arrumar o cursor
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
    // Leitura(&reg_prod); Incluir a tela de leitura

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
            gotoxy(30, 03);
            printf("Informe a posicao..:");
            scanf("%d", &posicao);
            if (posicao == 1)
            {
                P->proximo = L->Primeiro;
                L->Primeiro = P;
            }
            else
            {
                aux1 = L->Primeiro;
                for (int i = 1; i < posicao - 1; i++)
                {
                    aux1 = aux1->proximo;
                }
                P->proximo = aux1->proximo;
                aux1->proximo = P;
            }
        }
    }
}

// funções menu consultar
// consultar ficharia do produto geral
void consultarGeral(TipoLista *L)
{
    TipoApontador aux1;
    aux1 = L->Primeiro;
    while (aux1 != NULL)
    {
        printf("Codigo do Produto..:%d\n", aux1->conteudo.cd_produto);
        printf("Nome do Produto....:%s\n", aux1->conteudo.nm_produto);
        printf("Unidade............:%c\n", aux1->conteudo.und_produto);
        printf("Data de Validade...:%s\n", aux1->conteudo.dt_validade);
        printf("Quantidade.........:%.2f\n", aux1->conteudo.qtd_produto);
        printf("Valor..............:%.2f\n", aux1->conteudo.vl_produto);
        printf("Valor Total........:%.2f\n", aux1->conteudo.qtd_produto * aux1->conteudo.vl_produto);
        aux1 = aux1->proximo;
    }
}

// consultar em Ordem de Codigo
void consultarCodigo(TipoLista *L)
{
    TipoApontador aux1;
    TipoApontador aux2;
    reg_produto reg_prod;
    aux1 = L->Primeiro;
    while (aux1 != NULL)
    {
        aux2 = aux1->proximo;
        while (aux2 != NULL)
        {
            if (aux1->conteudo.cd_produto > aux2->conteudo.cd_produto)
            {
                reg_prod = aux1->conteudo;
                aux1->conteudo = aux2->conteudo;
                aux2->conteudo = reg_prod;
            }
            aux2 = aux2->proximo;
        }
        aux1 = aux1->proximo;
    }
    consultarGeral(L);
}

// consultar em Ordem Alfabetica
void consultarAlfabetica(TipoLista *L)
{
    TipoApontador aux1;
    TipoApontador aux2;
    reg_produto reg_prod;
    aux1 = L->Primeiro;
    while (aux1 != NULL)
    {
        aux2 = aux1->proximo;
        while (aux2 != NULL)
        {
            if (strcmp(aux1->conteudo.nm_produto, aux2->conteudo.nm_produto) > 0)
            {
                reg_prod = aux1->conteudo;
                aux1->conteudo = aux2->conteudo;
                aux2->conteudo = reg_prod;
            }
            aux2 = aux2->proximo;
        }
        aux1 = aux1->proximo;
    }
    consultarGeral(L);
}

// consultar o Codigo Especifico
void consultarEspecifico(TipoLista *L)
{
    TipoApontador aux1;
    int cd_produto;
    aux1 = L->Primeiro;
    gotoxy(30, 03);
    printf("Informe o Codigo do Produto..:");
    scanf("%d", &cd_produto);
    while (aux1 != NULL)
    {
        if (aux1->conteudo.cd_produto == cd_produto)
        {
            printf("Codigo do Produto..:%d\n", aux1->conteudo.cd_produto);
            printf("Nome do Produto....:%s\n", aux1->conteudo.nm_produto);
            printf("Unidade............:%c\n", aux1->conteudo.und_produto);
            printf("Data de Validade...:%s\n", aux1->conteudo.dt_validade);
            printf("Quantidade.........:%.2f\n", aux1->conteudo.qtd_produto);
            printf("Valor..............:%.2f\n", aux1->conteudo.vl_produto);
            printf("Valor Total........:%.2f\n", aux1->conteudo.qtd_produto * aux1->conteudo.vl_produto);
        }
        aux1 = aux1->proximo;
    }
}

// Menu Movimentacao de Estoque
// calculo de custo medio do valor unitario de cada produto

// cadastrar movimentacao de estoque
/*void cadastrarMov(TipoLista_mov *M)
{
    TipoApontador P;
    TipoApontador aux1;
    reg_produto reg_prod;
    reg_movimentacao reg_mov;
    TipoApontador_mov M;
    int resp;

    do
    {
        tela();
        gotoxy(30, 03);
        printf("CADASTRAR MOVIMENTACAO");
    } while ()
    {
    }
}*/

// Lista Movimentacao de Estoque
/*void listaMov(TipoLista_mov *M)
{
    TipoApontador_mov aux1;
    aux1 = M->Primeiro_mov;
    while (aux1 != NULL)
    {
        printf("Data da Movimentacao..:%s\n", aux1->conteudo_mov.dt_mov);
        printf("Tipo de Movimentacao..:%c\n", aux1->conteudo_mov.tp_mov);
        printf("Quantidade............:%.2f\n", aux1->conteudo_mov.qt_mov);
        printf("Valor unitario........:%.2f\n", aux1->conteudo_mov.vl_unit_mov);
        printf("Valor Total...........:%.2f\n", aux1->conteudo_mov.vl_total_mov);
        printf("Quantidade em estoque.:%.2f\n", aux1->conteudo_mov.qt_mov);
        printf("Valor em estoque......:%.2f\n", aux1->conteudo_mov.vl_total_mov);
        printf("Custo Medio...........:%.2f\n", aux1->conteudo_mov.vl_total_mov / aux1->conteudo_mov.qt_mov);
        aux1 = aux1->proximo_mov;
    }
}*/

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
            cadastrarFinal(L);
            break;

        case 2:
            cadastrarInicio(L);
            break;

        case 3:
            cadastrarPosicao(L);
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

void MovEstoque(TipoApontador_mov *M)
{
    int opc;
    do
    {
        tela();
        gotoxy(30, 03);
        printf("MENU MOVIMENTACAO DE ESTOQUE");
        gotoxy(20, 7);
        printf("1 - Cadastra Movimentavao de Estoque");
        gotoxy(20, 8);
        printf("2 - Lista Movimentacao de Estoque");
        gotoxy(20, 11);
        printf("3 - Retornar Menu Principal");
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

    home();
    getch();
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