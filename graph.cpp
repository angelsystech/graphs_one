#include <iostream>
#include <stdio.h>
#include <string.h>
#include "graph.h"

using namespace std;
//---------------------------------------------------------------------------
Grafo::Grafo(int numver) //construtor
{
maxvertices = numver;
vertices    = new int[maxvertices];

        matrizadjacencias = new int*[maxvertices];

        for (int i = 0; i < maxvertices; i++)
        {
            matrizadjacencias[i] = new int[maxvertices];
        }


        for (int i = 0; i < maxvertices; i++)
        {
            for (int j = 0; j < maxvertices; j++)
            {
                matrizadjacencias[i][j] = 0;
            }
        }
}
//---------------------------------------------------------------------------
Grafo::~Grafo() //destrutor
{
    delete [] vertices;

    for (int i = 0; i < maxvertices; i++)
    {
        delete [] matrizadjacencias[i];
    }
        delete [] matrizadjacencias;
}
//---------------------------------------------------------------------------
int Grafo::obterindice(int item)
{
int indice = 0;

        while (item != vertices[indice])
        {
            indice++;
        }
        return indice;
}
//---------------------------------------------------------------------------
bool Grafo::estacheio()
{
    return (numvertices == maxvertices);
}
//---------------------------------------------------------------------------
void Grafo::inserevertice(int item)
{
    if(estacheio())
    {
        cout << "O numero maximo de vertices foi alcancado!\n";
    }
    else
    {
        vertices[numvertices] = item;
        numvertices++;
    }
}
//---------------------------------------------------------------------------
void Grafo::inserearesta(int Nosaida, int Noentrada, int peso)
{
int linha = obterindice(Nosaida);
int coluna = obterindice(Noentrada);

    matrizadjacencias[linha][coluna] = peso;

    matrizadjacencias[coluna][linha] = peso; //Remover se for direcionado
}
//---------------------------------------------------------------------------
void Grafo::deletearesta(int Nosaida, int Noentrada)
{
int linha = obterindice(Nosaida);
int coluna = obterindice(Noentrada);

    matrizadjacencias[linha][coluna] = 0;

    matrizadjacencias[coluna][linha] = 0; //Remover se for direcionado
}
//---------------------------------------------------------------------------
int Grafo::obterpeso(int Nosaida, int Noentrada)
{
int linha = obterindice(Nosaida);
int coluna = obterindice(Noentrada);

    return (matrizadjacencias[linha][coluna]);
}
//---------------------------------------------------------------------------
int Grafo::obtergrauVertc(int item)
{
int linha = obterindice(item);
int grau = 0;

    for (int i = 0; i < maxvertices; i++)
    {
        if(matrizadjacencias[linha][i] != 0)
            grau++;
    }
    return grau;
}
//---------------------------------------------------------------------------
int Grafo::obtergrauGraph()
{
int linha;
int grau = 0;

    for (int i = 0; i < maxvertices; i++)
    {
        linha = obterindice(i + 1);

        for (int j = 0; j < maxvertices; j++)
            if(matrizadjacencias[linha][j] != 0)
                grau++;
    }
    return grau;
}
//---------------------------------------------------------------------------
void Grafo::obteradjacentM(int item)
{
int linha = obterindice(item);

    if(item != 0)
    {
        linha = obterindice(item);

        printf("%d%s", vertices[linha], ":");
        obteradjacentD(linha);
    }
    else
    {
        for (int i = 0; i < maxvertices; i++)
        {
            linha = obterindice(i + 1);

            printf("%d%s", vertices[linha], ":");
            obteradjacentD(linha);
            printf("\n");
        }
    }
    printf("\n\n");
}
//---------------------------------------------------------------------------
void Grafo::obteradjacentD(int item)
{
    for (int i = 0; i < maxvertices; i++)
    {
        if(matrizadjacencias[item][i] != 0)
            printf(" %d", vertices[i]);
    }
}
//---------------------------------------------------------------------------
void Grafo::imprimirmatriz()
{
    cout << "Matriz de adjacencias:\n";

    for(int i = 0; i < maxvertices; i++)
    {
        for(int j = 0; j < maxvertices; j++)
        {
                cout << matrizadjacencias[i][j] << " ";
        }
        cout << endl;
    }
}
//---------------------------------------------------------------------------
void Grafo::imprimirvertices()
{
    cout << "Lista de Vertices:\n";

    for(int i = 0; i < numvertices; i++)
    {
        cout << i << ": " << vertices[i] << endl;
    }
}
//---------------------------------------------------------------------------
