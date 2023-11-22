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
        cout << "Digite o elemento do v�rtice que ser� inserido: ";
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
        cout << "Digite o v�rtice de saida: ";
        cin >> item1;
        cout << "Digite o v�rtice de entrada: ";
        cin >> item2;
        cout << "Digite o peso desta aresta: ";
        cin >> peso;

        grafo.inserearesta(item1, item2, peso);
    }
    else if( c == 'r' || c == 'R')
    {
        cout << "Digite o v�rtice de saida: ";
        cin >> item1;
        cout << "Digite o v�rtice de entrada: ";
        cin >> item2;

        grafo.deletearesta(item1, item2);
    }
    else
        cout << "OPC�O INV�LIDA!\n";
}
//---------------------------------------------------------------------------
int main()
{
int b, numberV, item1, valor;

    setlocale(LC_ALL,"Portuguese_Brazil");

    printf("\n------------------ GRAFOS ------------------\n\n");

    printf("\nDigite o n�mero m�ximo de v�rtices do grafo: ");
    scanf("%d", &numberV);

    Grafo GRAPHS(numberV);

    printf("\nGrafo criado com sucesso!");

    do
    {
            printf("\n\n**** MENU DO PROGRAMA - GRAFOS ****\n\n"
                   " 1 - INSERIR V�RTICE\n"
                   " 2 - INSERIR OU REMOVER ARESTAS\n"
                   " 3 - CONSULTAR O GRAU DE UM V�RTICE\n"
                   " 4 - CONSULTAR O GRAU DO GRAFO\n"
                   " 5 - CONSULTAR OS VIZINHOS DE UM V�RTICE\n"
                   " 7 - VERIFICAR SE O GRAFO � CONEXO\n"
                   " 8 - VERIFICAR SE O GRAFO � REGULAR\n"
                   " 9 - VERIFICAR SE O GRAFO � COMPLETO\n"
                   "10 - BUSCA EM PROFUNDIDADE\n"
                   "11 - BUSCA EM LARGURA\n"
                   "12 - EXIST�NCIA DE CAMINHO ENTRE V�RTICES\n"
                   "13 - VISUALIZA��O\n"
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
                            cout << "Digite o v�rtice que ser� calculado o grau: ";
                            cin >> item1;
                            valor = GRAPHS.obtergrauVertc(item1);
                            cout << "O grau desse vertice : " << valor << endl;
                        } else
                        if(b ==  4)
                        {
                            valor = GRAPHS.obtergrauGraph();
                            cout << "O grau do GRAFO �: " << valor << endl;

                        } else
                        if((b ==  5) || (b == 13))
                        {
                            cout << "     VERIFICAR OS VIZINHOS DE V�RTICES\n";
                            cout << "Digite o n�mero do v�rtice ou 0(zero) para todos: ";
                            cin >> item1;
                            GRAPHS.obteradjacentM(item1);
                            GRAPHS.imprimirmatriz();
                        } else
                        if(b ==  6)
                        {
                            cout << "N�O IMPLEMENTADO\n";
                        } else
                        if(b ==  7)
                        {
                            cout << "N�O IMPLEMENTADO\n";
                        } else
                        if(b ==  8)
                        {
                            cout << "N�O IMPLEMENTADO\n";
                        } else
                        if(b ==  9)
                        {
                            cout << "N�O IMPLEMENTADO\n";
                        } else
                        if(b == 10)
                        {
                            cout << "N�O IMPLEMENTADO\n";
                        } else
                        if(b == 11)
                        {
                            cout << "N�O IMPLEMENTADO\n";
                        } else
                        if(b == 12)
                        {
                            cout << "N�O IMPLEMENTADO\n";
                        } /*else
                        if(b == 13)
                        {
                            cout << "N�O IMPLEMENTADO\n";
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
