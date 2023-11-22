#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "graph.h"

using namespace std;
//---------------------------------------------------------------------------
void vInsVrt(Grafo &grafo)
{
int item1;

    do
    {
        cout << "Digite o elemento do vértice que será inserido: ";
        cin >> item1;

        grafo.inserevertice(item1);
    }
    while( grafo.estacheio() != true );

    grafo.imprimirvertices();
}
//---------------------------------------------------------------------------
void vIRArst(Grafo &grafo)
{
char c;
int item1, item2, peso;

    printf("\n\nTecle I(INSERIR) ou R(REMOVER) uma aresta: ");
    scanf("%c", &c);

    if( c == 'i' || c == 'I')
    {
        cout << "Digite o vértice de saida: ";
        cin >> item1;
        cout << "Digite o vértice de entrada: ";
        cin >> item2;
        cout << "Digite o peso desta aresta: ";
        cin >> peso;

        grafo.inserearesta(item1, item2, peso);
    }
    else if( c == 'r' || c == 'R')
    {
        cout << "Digite o vértice de saida: ";
        cin >> item1;
        cout << "Digite o vértice de entrada: ";
        cin >> item2;

        grafo.deletearesta(item1, item2);
    }
    else
        cout << "OPCÃO INVÁLIDA!\n";
}
//---------------------------------------------------------------------------
int main()
{
int b, numberV, item1, valor;

    setlocale(LC_ALL,"Portuguese_Brazil");

    printf("\n------------------ GRAFOS ------------------\n\n");

    printf("\nDigite o número máximo de vértices do grafo: ");
    scanf("%d", &numberV);

    Grafo GRAPHS(numberV);

    printf("\nGrafo criado com sucesso!");

    do
    {
            printf("\n\n**** MENU DO PROGRAMA - GRAFOS ****\n\n"
                   " 1 - INSERIR VÉRTICE\n"
                   " 2 - INSERIR OU REMOVER ARESTAS\n"
                   " 3 - CONSULTAR O GRAU DE UM VÉRTICE\n"
                   " 4 - CONSULTAR O GRAU DO GRAFO\n"
                   " 5 - CONSULTAR OS VIZINHOS DE UM VÉRTICE\n"
                   " 7 - VERIFICAR SE O GRAFO É CONEXO\n"
                   " 8 - VERIFICAR SE O GRAFO É REGULAR\n"
                   " 9 - VERIFICAR SE O GRAFO É COMPLETO\n"
                   "10 - BUSCA EM PROFUNDIDADE\n"
                   "11 - BUSCA EM LARGURA\n"
                   "12 - EXISTÊNCIA DE CAMINHO ENTRE VÉRTICES\n"
                   "13 - VISUALIZAÇÃO\n"
                   " 0 - SAIR DO PROGRAMA\n\n"
                   "     TECLE SUA ESCOLHA: ");

                   scanf("%d", &b);
                   fflush(stdin);

                   if(b != 0)
                   {
                        system("CLS");

                        if(b ==  1)
                        {
                            vInsVrt(GRAPHS);

                        } else
                        if(b ==  2)
                        {
                            vIRArst(GRAPHS);
                            GRAPHS.imprimirmatriz();

                        } else
                        if(b ==  3)
                        {
                            cout << "Digite o vértice que será calculado o grau: ";
                            cin >> item1;
                            valor = GRAPHS.obtergrauVertc(item1);
                            cout << "O grau desse vertice : " << valor << endl;
                        } else
                        if(b ==  4)
                        {
                            valor = GRAPHS.obtergrauGraph();
                            cout << "O grau do GRAFO é: " << valor << endl;

                        } else
                        if((b ==  5) || (b == 13))
                        {
                            cout << "     VERIFICAR OS VIZINHOS DE VÉRTICES\n";
                            cout << "Digite o número do vértice ou 0(zero) para todos: ";
                            cin >> item1;
                            GRAPHS.obteradjacentM(item1);
                            GRAPHS.imprimirmatriz();
                        } else
                        if(b ==  6)
                        {
                            cout << "NÃO IMPLEMENTADO\n";
                        } else
                        if(b ==  7)
                        {
                            cout << "NÃO IMPLEMENTADO\n";
                        } else
                        if(b ==  8)
                        {
                            cout << "NÃO IMPLEMENTADO\n";
                        } else
                        if(b ==  9)
                        {
                            cout << "NÃO IMPLEMENTADO\n";
                        } else
                        if(b == 10)
                        {
                            cout << "NÃO IMPLEMENTADO\n";
                        } else
                        if(b == 11)
                        {
                            cout << "NÃO IMPLEMENTADO\n";
                        } else
                        if(b == 12)
                        {
                            cout << "NÃO IMPLEMENTADO\n";
                        } /*else
                        if(b == 13)
                        {
                            cout << "NÃO IMPLEMENTADO\n";
                        }*/
                        else
                            printf("Opcao Invalida!");
                   }
                   //GRAPHS.imprimirmatriz();
    } while(b != 0);

    printf("\n\nSaindo...\n\n");

    return 0;
}
//---------------------------------------------------------------------------
