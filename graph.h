#include <iostream>

using namespace std;
//---------------------------------------------------------------------------
class Grafo
{
private:
    int maxvertices;
    int numvertices;
    int* vertices;
    int** matrizadjacencias;
//---------------------------------------------------------------------------
public:
    Grafo(int numver);
    ~Grafo();
    int obterindice(int item);
    bool estacheio();
    void inserevertice(int item);
    void inserearesta(int Nosaida, int Noentrada, int peso);
    void deletearesta(int Nosaida, int Noentrada);
    int obterpeso(int Nosaida, int Noentrada);
    int obtergrauGraph();
    int obtergrauVertc(int item);
    void obteradjacentM(int item);
    void obteradjacentD(int item);
    void imprimirmatriz();
    void imprimirvertices();
};
//---------------------------------------------------------------------------
