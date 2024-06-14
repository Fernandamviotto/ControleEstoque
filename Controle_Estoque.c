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
#include <string.h>

// Dados produto
typedef struct
{
    int cd_produto;
    char nm_produto[50];
    char und_produto[03];
    char dt_validade[11];
    float qtd_produto;
    float vl_CustoMedio;
    float vl_total;
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
    system("color 0C");
    gotoxy(01, 01);
    printf("+--------------------------------------------------------------------------------------------------+");
    gotoxy(01, 02);
    printf("| UNICV");
    gotoxy(81, 02);
    printf("Estrutura de Dados |");
    gotoxy(01, 03);
    printf("|");
    gotoxy(100, 03);
    printf("|");
    gotoxy(38, 02);
    printf("CONTROLE DE ESTOQUE");
    gotoxy(84, 03);
    printf("Fernanda Viotto |");
    gotoxy(01, 04);
    printf("+--------------------------------------------------------------------------------------------------+");
    for (t = 5; t < 30; t++)
    {
        gotoxy(01, t);
        printf("|");
        gotoxy(100, t);
        printf("|");
    }

    gotoxy(01, 28);
    printf("+--------------------------------------------------------------------------------------------------+");
    gotoxy(02, 29);
    printf("MSG.:");
    gotoxy(01, 30);
    printf("+--------------------------------------------------------------------------------------------------+");
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
    gotoxy(12, 9);
    printf("1 - Descricao do Produto.:");
    gotoxy(12, 11);
    printf("2 - Unidade de Medida....:");
    gotoxy(12, 13);
    printf("3 - Data de Validade.....:");
    gotoxy(12, 15);
    printf("+-------------------------------------------------------------------+");
    gotoxy(12, 16);
    printf("|                    SALDO DO ESTOQUE DO PRODUTO                    |");
    gotoxy(12, 17);
    printf("+-------------------------------------------------------------------+");
    gotoxy(12, 18);
    printf("+---------------------+----------------------+----------------------+");
    gotoxy(12, 19);
    printf("|     Quantidade      |     Custo Medio      |      Valor Total     |");
    gotoxy(12, 20);
    printf("+---------------------+----------------------+----------------------+");
    gotoxy(12, 21);
    printf("|                     |                      |                      |");
    gotoxy(12, 22);
    printf("+---------------------+----------------------+----------------------+");
}

// Funções MENU PRODUTO

// Le o nome do produto
// é um char de ponteiro
char *le_nm_produto()
{
    // ele retorna o valor digitado
    char *nm_produto;
    nm_produto = malloc(sizeof(char) * 50);
    do
    {
        gotoxy(37, 8);
        printf("                         ");
        gotoxy(37, 8);
        fgets(nm_produto, 50, stdin);

        // O srtlen verifica o tamanho do campo, servido para validar o valor digitado
        if ((strlen(nm_produto) == 1) && (strcmp(nm_produto, "0") == -1))
        {
            gotoxy(07, 23);
            printf("Nome do Produto e Obrigatorio");
            getch();
            gotoxy(07, 23);
            printf("                                                  ");
        }
    } while ((strlen(nm_produto) == 1) && (strcmp(nm_produto, "0") == -1));
    return nm_produto;
}

// é um char de ponteiro
//  Le a Unidade de Medida do Produto
char *le_und_produto()
{
    char *und_produto;
    und_produto = malloc(sizeof(char) * 3);
    do
    {
        gotoxy(37, 10);
        printf("                         ");
        gotoxy(37, 10);
        fgets(und_produto, 4, stdin);

        if ((strlen(und_produto) == 1) && (strcmp(und_produto, "0") == -1))
        {
            gotoxy(07, 23);
            printf("Unidade de Medida e Obrigatoria");
            getch();
            gotoxy(07, 23);
            printf("                                                  ");
        }
    } while ((strlen(und_produto) == 1) && (strcmp(und_produto, "0") == -1));
    return und_produto;
}

// é um char de ponteiro
//  Le a Data de Validade
char *le_dt_validade()
{
    char *dt_validade;
    dt_validade = malloc(sizeof(char) * 11);
    do
    {
        gotoxy(37, 12);
        printf("                         ");
        gotoxy(37, 12);
        fgets(dt_validade, 11, stdin);

        if ((strlen(dt_validade) == 1) && (strcmp(dt_validade, "0") == 0))
        {
            gotoxy(07, 23);
            printf("Data de Validade e Obrigatoria");
            getch();
            gotoxy(07, 23);
            printf("                                                  ");
        }
    } while ((strlen(dt_validade) == 1) && (strcmp(dt_validade, "0") == -1));
    return dt_validade;
}

// Função para pesquisar se o elemento tem na leitura
TipoApontador pesquisa(TipoLista *L, int codigo)
{
    TipoApontador aux;
    aux = L->Primeiro;
    // irá percorer a lista do primeiro até o final
    while (aux != NULL)
    {
        // caso encontre ele para o processo e devolve o aux para a função
        if (aux->conteudo.cd_produto == codigo)
        {
            break;
        }
        // se percorer a lista e não encontrar devolve o NULL para a função
        aux = aux->proximo;
    }
    return aux;
}

// Função Leitura de Produto
void leitura(reg_produto *reg_prod)
{
    // o strcpy pega o valor dos le... e coloca nos reg_prod
    // le o nome do produto
    strcpy(reg_prod->nm_produto, le_nm_produto());
    // le a unidade de medida do produto
    strcpy(reg_prod->und_produto, le_und_produto());
    // le a data de validade do produto
    strcpy(reg_prod->dt_validade, le_dt_validade());
}

//  cadastrar produto no inicio da lista
void cadastrarInicio(TipoLista *L)
{
    // tem a mesma estrutura do tipoItem
    TipoApontador P;
    TipoApontador aux1;
    reg_produto reg_prod;
    // para validar a resposta do salvar
    int resp;

    do
    {
        tela();
        telaProduto();
        gotoxy(30, 03);
        printf("CADASTRAR PRODUTO NO INICIO");
        gotoxy(40, 07); // arrumar o cursor
        // Ler o código do produto
        scanf("%d", &reg_prod.cd_produto);
        getchar();
        // chama a função para validar se este código já existe
        aux1 = pesquisa(L, reg_prod.cd_produto);
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
    leitura(&reg_prod); // Incluir a tela de leitura

    reg_prod.qtd_produto = 0;
    reg_prod.vl_CustoMedio = 0;
    reg_prod.vl_total = 0;

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
        gotoxy(40, 07); // arrumar o cursor
        scanf("%d", &reg_prod.cd_produto);
        getchar();
        aux1 = pesquisa(L, reg_prod.cd_produto);
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
    leitura(&reg_prod); // Incluir a tela de leitura

    reg_prod.qtd_produto = 0;
    reg_prod.vl_CustoMedio = 0;
    reg_prod.vl_total = 0;

    gotoxy(07, 29);
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
        aux1 = pesquisa(L, reg_prod.cd_produto);
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
    leitura(&reg_prod); // Incluir a tela de leitura

    reg_prod.qtd_produto = 0;
    reg_prod.vl_CustoMedio = 0;
    reg_prod.vl_total = 0;

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

// alterar Produto
void alterarProduto(TipoLista *L)
{

    TipoApontador aux1;
    reg_produto reg_prod;
    int resp;

    do
    {
        telaProduto();
        gotoxy(33, 03);
        printf("ALTERAR PRODUTO");
        gotoxy(37, 06);
        scanf("%d", &reg_prod.cd_produto);
        getchar();
        aux1 = pesquisa(L, reg_prod.cd_produto);
        // caso volte nulo
        if (aux1 == NULL)
        {
            gotoxy(30, 03);
            printf("               ");
            gotoxy(30, 03);
            printf("Codigo nao Cadsatrado");
            getch();
            gotoxy(30, 03);
            printf("               ");
        }
    } while (aux1 == NULL);

    reg_prod = aux1->conteudo;
    gotoxy(37, 8);
    printf("%s", aux1->conteudo.nm_produto);
    gotoxy(37, 10);
    printf("%s", aux1->conteudo.und_produto);
    gotoxy(37, 12);
    printf("%s", aux1->conteudo.dt_validade);
    gotoxy(14, 21);
    printf("%.2f", aux1->conteudo.qtd_produto);
    gotoxy(30, 21);
    printf("%.2f", aux1->conteudo.vl_CustoMedio);
    gotoxy(45, 21);
    printf("%.2f", aux1->conteudo.vl_total);

    do
    {
        gotoxy(07, 29);
        printf("                                            ");
        gotoxy(07, 29);
        printf("Qual campo desejar alterar (0 Sendo o fim)? ");
        scanf("%d", &resp);
        switch (resp)
        {
        case 1:
        {
            strcpy(reg_prod.nm_produto, le_nm_produto());
            break;
        }

        case 2:
        {
            strcpy(reg_prod.und_produto, le_und_produto());
            break;
        }

        case 3:
        {
            strcpy(reg_prod.dt_validade, le_dt_validade());
            break;
        }
        default:
        {
            gotoxy(07, 29);
            printf("                                            ");
            gotoxy(07, 29);
            printf("Opcao Invalida. Tente uma opcao que seja valida");
            getch();
            break;
        }
        }
    } while (resp != 0);

    gotoxy(07, 29);
    printf("Deseja gravar os dados (1-SIM; 2-NAO)..:");
    scanf("%d", &resp);
    if (resp == 1)
    {
        // coloca os dados de aux no conteudo do produto
        aux1->conteudo = reg_prod;
    }
}

// funções remover
// remover produto no inicio da lista
void removerInicio(TipoLista *L)
{
    TipoApontador P;
    int resp;
    if (L->Primeiro == NULL)
    {
        gotoxy(30, 03);
        printf("LISTA DE PRODUTOS VAZIA");
        getch();
    }
    else
    {
        P = L->Primeiro;
        L->Primeiro = L->Primeiro->proximo;
        free(P);
    }
}

// remover produto no final da lista
void removerFinal(TipoLista *L)
{
    TipoApontador P;
    TipoApontador aux1;
    int resp;
    if (L->Primeiro == NULL)
    {
        gotoxy(30, 03);
        printf("LISTA DE PRODUTOS VAZIA");
        getch();
    }
    else
    {
        P = L->Primeiro;
        if (P->proximo == NULL)
        {
            L->Primeiro = NULL;
            free(P);
        }
        else
        {
            while (P->proximo != NULL)
            {
                aux1 = P;
                P = P->proximo;
            }
            aux1->proximo = NULL;
            L->Ultimo = aux1;
            free(P);
        }
    }
}

// remover produto em uma posicao da lista
void removerPosicao(TipoLista *L)
{
    TipoApontador P;
    TipoApontador aux1;
    int resp;
    int posicao;
    if (L->Primeiro == NULL)
    {
        gotoxy(30, 03);
        printf("LISTA DE PRODUTOS VAZIA");
        getch();
    }
    else
    {
        gotoxy(30, 03);
        printf("Informe a posicao..:");
        scanf("%d", &posicao);
        if (posicao == 1)
        {
            P = L->Primeiro;
            L->Primeiro = L->Primeiro->proximo;
            free(P);
        }
        else
        {
            P = L->Primeiro;
            for (int i = 1; i < posicao; i++)
            {
                aux1 = P;
                P = P->proximo;
            }
            aux1->proximo = P->proximo;
            free(P);
        }
    }
}

// função consultar em lista
void consultarTodos(TipoLista *L)
{
    TipoApontador p;
    reg_produto reg_prod;
    int lin;
    tela();
    gotoxy(30, 03);
    printf("CONSULTA DE PRODUTOS");
    lin = 7;
    gotoxy(02, 05);
    printf("ID  Desc. Produto               UND  Data Valid.    QTD    Vl.Unit     Vl. Total");
    gotoxy(02, 06);
    printf("--  --------------------------- ---- -------------- ----- ----------- ----------");
    p = L->Primeiro;
    if (p == NULL)
    {
        gotoxy(07, 23);
        printf("LISTA DE PRODUTOS VAZIA");
        getch();
    }
    else
    {
        while (p != NULL)
        {
            gotoxy(02, lin);
            printf("%d", reg_prod.cd_produto);
            gotoxy(05, lin);
            printf("%s", reg_prod.nm_produto);
            gotoxy(36, lin);
            printf("%s", reg_prod.und_produto);
            gotoxy(40, lin);
            printf("%s", reg_prod.dt_validade);
            gotoxy(53, lin);
            printf("%6.2f", reg_prod.qtd_produto);
            gotoxy(63, lin);
            printf("%6.2f", reg_prod.vl_CustoMedio);
            gotoxy(73, lin);
            printf("%6.2f", reg_prod.vl_total);
            p = p->proximo;
            lin++;
            if (lin > 20)
            {
                lin = 7;
                gotoxy(25, 23);
                printf("CONSULTA DE PRODUTOS");
                gotoxy(02, 05);
                printf("ID  Desc. Produto               UND  Data Valid.    QTD    Vl.Unit     Vl. Total");
                gotoxy(02, 06);
                printf("--  --------------------------- ---- -------------- ----- ----------- ----------");
            }
        }
        gotoxy(07, 23);
        printf("Pressione uma tecla para continuar...");
        getch();
    }
}

// funções menu consultar
// consultar ficharia do produto geral usando a funcao void telaProduto()

// consultar em Ordem de Codigo
void consultarOrdemCodigo(TipoLista *L)
{
    TipoApontador p;
    reg_produto reg_prod;
    int lin;
    tela();
    gotoxy(30, 03);
    printf("CONSULTA DE PRODUTOS");
    lin = 7;
    gotoxy(02, 05);
    printf("ID  Desc. Produto               UND  Data Valid.    QTD    Vl.Unit     Vl. Total");
    gotoxy(02, 06);
    printf("--  --------------------------- ---- -------------- ----- ----------- ----------");
    p = L->Primeiro;
    if (p == NULL)
    {
        gotoxy(07, 23);
        printf("LISTA DE PRODUTOS VAZIA");
        getch();
    }
    else
    {
        while (p != NULL)
        {
            gotoxy(02, lin);
            printf("%d", reg_prod.cd_produto);
            gotoxy(05, lin);
            printf("%s", reg_prod.nm_produto);
            gotoxy(36, lin);
            printf("%s", reg_prod.und_produto);
            gotoxy(40, lin);
            printf("%s", reg_prod.dt_validade);
            gotoxy(53, lin);
            printf("%6.2f", reg_prod.qtd_produto);
            gotoxy(63, lin);
            printf("%6.2f", reg_prod.vl_CustoMedio);
            gotoxy(73, lin);
            printf("%6.2f", reg_prod.vl_total);
            p = p->proximo;
            lin++;
            if (lin > 20)
            {
                lin = 7;
                gotoxy(25, 23);
                printf("CONSULTA DE PRODUTOS");
                gotoxy(02, 05);
                printf("ID  Desc. Produto               UND  Data Valid.    QTD    Vl.Unit     Vl. Total");
                gotoxy(02, 06);
                printf("--  --------------------------- ---- -------------- ----- ----------- ----------");
            }
        }
        gotoxy(07, 29);
        printf("Pressione uma tecla para continuar...");
        getch();
    }
}

// consultar em Ordem Alfabetica
// utilizando a função de ordenação
void consultarAlfabetica(TipoLista *L)
{
    TipoApontador p;
    reg_produto reg_prod;
    int lin;
    tela();
    gotoxy(30, 03);
    printf("CONSULTA DE PRODUTOS");
    lin = 7;
    gotoxy(02, 05);
    printf("ID  Desc. Produto               UND  Data Valid.    QTD    Vl.Unit     Vl. Total");
    gotoxy(02, 06);
    printf("--  --------------------------- ---- -------------- ----- ----------- ----------");
    p = L->Primeiro;
    if (p == NULL)
    {
        gotoxy(07, 23);
        printf("LISTA DE PRODUTOS VAZIA");
        getch();
    }
    else
    {
        while (p != NULL)
        {
            gotoxy(02, lin);
            printf("%d", reg_prod.cd_produto);
            gotoxy(05, lin);
            printf("%s", reg_prod.nm_produto);
            gotoxy(36, lin);
            printf("%s", reg_prod.und_produto);
            gotoxy(40, lin);
            printf("%s", reg_prod.dt_validade);
            gotoxy(53, lin);
            printf("%6.2f", reg_prod.qtd_produto);
            gotoxy(63, lin);
            printf("%6.2f", reg_prod.vl_CustoMedio);
            gotoxy(73, lin);
            printf("%6.2f", reg_prod.vl_total);
            p = p->proximo;
            lin++;
            if (lin > 20)
            {
                lin = 7;
                gotoxy(25, 23);
                printf("CONSULTA DE PRODUTOS");
                gotoxy(02, 05);
                printf("ID  Desc. Produto               UND  Data Valid.    QTD    Vl.Unit     Vl. Total");
                gotoxy(02, 06);
                printf("--  --------------------------- ---- -------------- ----- ----------- ----------");
            }
        }
        gotoxy(07, 23);
        printf("Pressione uma tecla para continuar...");
        getch();
    }
}

// consultar o Codigo Especifico

// Menu Movimentacao de Estoque
// calculo de custo medio do valor unitario de cada produto

// cadastrar movimentacao de estoque
/*void cadastrarMov(TipoLista *L)
{
    TipoApontador P;
    TipoApontador aux1;
    reg_movimentacao reg_mov;
    int resp;

    TelaMov();
    gotoxy(30,03);
    printf("CADASTRAR MOVIMENTAVAO");

    do
    {
        gotoxy(37, 06);
        printf("             ");
        gotoxy(37, 06);
        printf("%d", &reg_mov.cd_prod_mov);
        getchar();
        aux1 = pesquisa(L, reg_mov.cd_prod_mov);
        if(aux1 == NULL)

    }
   }*/

// Lista Movimentacao de Estoque
void ConsultaMov(TipoLista *L)
{
    int resp;
    int aux1;
    reg_movimentacao reg_mov;

    do
    {
        tela();
        gotoxy(30, 03);
        printf("CONSULTAR MOVIMENTACAO");
        gotoxy(01, 05);
        printf("| Produto.: XX - XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX               |");
        gotoxy(01, 06);
        printf("+--------------------------------------------------------------------------------------------+");
        gotoxy(01, 07);
        printf("|  Data         Tip     Quant     Vl.Unit    Vl. Total     Qtd Est   Custo Med     Vl.Total");
        gotoxy(02, 8);
        printf("|----------  ------- ---------- ----------- ------------ ---------- -----------  ----------- |");
        scanf("%d", &reg_mov.cd_prod_mov);
        aux1 = 0;
    } while (aux1 != 0);

    gotoxy(07, 23);
    printf("Deseja gravar os dados (1 - SIM; 2 - NÃO)..: ");
    scanf("%d", &resp);
}

// SUBMENU
// Menu Consultar Produto
void menu_consultar(TipoLista *L)
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
            // incluir função
            break;

        case 2:
            consultarOrdemCodigo(L);
            break;
        case 3:
            consultarAlfabetica(L);
            break;
        case 4:
            // incluir função
            break;
        case 5:
            // incluir função
            break;

        default:
            break;
        }
    } while (opc < 6);
}

// MENUS
// Menu Produto
void MenuProduto(TipoLista *L)
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

        case 4:
            removerInicio(L);
            break;

        case 5:
            removerFinal(L);
            break;

        case 6:
            removerPosicao(L);
            break;

        case 7:
            menu_consultar(L);
            break;

        case 8:
            alterarProduto(L);
            break;

        default:
            break;
        }
    } while (opc < 10);
}

// Menu Movimentacao Estoque
void MovEstoque(TipoLista *L)
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
            // cadastro movi
            break;

        case 2:
            ConsultaMov(L);
            break;

        default:
            break;
        }
    } while (opc < 4);
}

// MENU PRINCIPAL
int main()
{

    // home();
    // getch();
    int opc;
    TipoLista L;
    // TipoLista_mov M;
    //  para iniciar a cabeça deve estar fazia

    // LISTA DE PRODUTO
    L.Primeiro = NULL;
    L.Ultimo = NULL;
    /*// LISTA DE MOVIMENTACAO
    M.Primeiro_mov = NULL;
    M.Ultimo_mov = NULL;*/

    setlocale(LC_ALL, "portuguese-brazilian");
    // fica dentro de um Do While para o usuario escolher dentre as opções
    do
    {
        tela();
        gotoxy(42, 03);
        printf("MENU PRINCIPAL");
        gotoxy(20, 10);
        printf("1 - Menu Cadastro de Produto");
        gotoxy(20, 15);
        printf("2 - Menu Movimentacao de Estoque");
        gotoxy(20, 20);
        printf("3 - Finalizar o Programa");
        gotoxy(8, 29);
        printf("Digite sua opcao..:");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            MenuProduto(&L);
            break;

        case 2:
            MovEstoque(&L);
            break;

        default:
            break;
        }
        // somente o principal chama as funções usando o "&", pois a variavel que esrá lá é comum e não um ponteiro.

    } while (opc < 4);
    // gravar(&L);
    return 0;
}