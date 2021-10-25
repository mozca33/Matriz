#include "matrizdereal.h"


MatrizDeReal::MatrizDeReal(int linha, int coluna):
    sizeL{0}, sizeC{0}, matriz{nullptr}
{
    sizeL = linha;
    sizeC = coluna;
    matriz = new double *[sizeL];
    for (unsigned int i = 0; i < sizeL; i++)
    {
        matriz[i] = new double [sizeC];
        for (unsigned int j = 0; j < sizeC; j++)
            matriz[i][j] = 0;
    }
}

MatrizDeReal& MatrizDeReal::operator+(const MatrizDeReal &obj)
{
    if  (this->sizeL != obj.sizeL || this->sizeC != obj.sizeC)
        throw string("Erro: a ordem das matrizes sao diferentes.\n");
    int linha,coluna;
    linha  = this->sizeL;
    coluna = this->sizeC;
    MatrizDeReal *aux = new MatrizDeReal(linha,coluna);
    for (unsigned int i = 0; i < sizeL; i++)
        for (unsigned int j = 0; j < sizeC; j++){
            aux->matriz[i][j] = this->matriz[i][j] + obj.matriz[i][j];
        }
    return *aux;
}

MatrizDeReal& MatrizDeReal::operator-(const MatrizDeReal &obj)
{
    if  (this->sizeL != obj.sizeL || this->sizeC != obj.sizeC)
        throw string("Erro: a ordem das matrizes sao diferentes.\n");

    int linha,coluna;
    linha  = this->sizeL;
    coluna = this->sizeC;
    MatrizDeReal* aux = new MatrizDeReal(linha,coluna);
    for (unsigned int i = 0; i < sizeL; i++)
        for (unsigned int j = 0; j < sizeC; j++)
            aux->matriz[i][j] = this->matriz[i][j] - obj.matriz[i][j];

    return *aux;
}

MatrizDeReal& MatrizDeReal::operator*(const MatrizDeReal &obj)
{
    if  (this->sizeC != obj.sizeL)
        throw string("Erro: o numero de linhas da matriz 1 e o numero de colunas da matriz 2 sao diferentes.");

    int nLinha, nColuna, linE;
    nLinha=linE=0;

    int linha,coluna;
    linha  = this->sizeL;
    coluna = obj.sizeC;
    //nLinha e nColuna = posições
    //linha e coluna = tamanhos
    //linE = posição da linha da matriz esquerda ( matriz 1 )
    MatrizDeReal* aux = new MatrizDeReal(linha,coluna);

    for (unsigned int i = 0; i < sizeL; i++)
        for (unsigned int j = 0; j < sizeC; j++)
            aux->matriz[i][j] = 0;//inicialização da matriz aux.

    while(nLinha < linha)
    {//multiplicação da matriz 1 com a matriz 2
        nColuna=0;
        while(nColuna < coluna)
        {
            for (unsigned int j = 0; j < this->sizeC; j++)
                aux->matriz[nLinha][nColuna] += this->matriz[linE][j] * obj.matriz[j][nColuna];

            nColuna++;
        }
        linE++;
        nLinha++;
    }
    return *aux;
}

bool MatrizDeReal::setMatriz(int l,int c)
{
    if  (l<1 || c<1) return false;
    sizeL = l;
    sizeC = c;
    if  (this->matriz != nullptr)delete [] this->matriz;
    matriz = new double *[sizeL];
    for (unsigned int i = 0; i < sizeL; i++)
        matriz[i] = new double [sizeC];
    return true;
}

MatrizDeReal MatrizDeReal::inverter(MatrizDeReal& obj)
{
    if  (obj.sizeL != obj.sizeC)
        throw string("Erro: a matriz nao e quadrada.\n");

    int linha,coluna;
    coluna = linha = sizeL;

    MatrizDeReal *copia = new MatrizDeReal(linha,coluna);
    for (unsigned int i = 0; i < obj.sizeL; i++)
        for (unsigned int j = 0; j < obj.sizeC; j++)
            copia->matriz[i][j] = obj.matriz[i][j];
    //cópia da matriz 2

    MatrizDeReal *ident = new MatrizDeReal(linha,coluna);

    for (int p = 0; p < linha; p++)
        for (int j = 0; j < coluna; j++)
        {
            if(p == j)
                ident->matriz[p][j] = 1;
            else
                ident->matriz[p][j] = 0;
        }//matriz identidade

    double pivo, num;
    for (int i = 0; i < linha; i++)
    {
        pivo = copia->matriz[i][i];
        for (int p = 0; p < linha; p++)
        {//transformando a diagonal principal em 1(s)
            copia->matriz[i][p] = copia->matriz[i][p] / pivo;
            ident->matriz[i][p] = ident->matriz[i][p] / pivo;
        }

        for (int j = 0; j < linha; j++)
            if  (i != j)
            {//não estou na diagonal principal
                num = copia->matriz[j][i];

                for(int k = 0; k < linha; k++)
                {
                    copia->matriz[j][k] = copia->matriz[j][k] - (num * copia->matriz[i][k]);
                    ident->matriz[j][k] = ident->matriz[j][k] - (num * ident->matriz[i][k]);
                }
            }
    }

    return *ident;
}

ostream& operator<<(ostream& saida, MatrizDeReal& obj){
    for (unsigned int i = 0; i < obj.sizeL; i++)
    {
        cout<<"|";
        for (unsigned int j = 0; j < obj.sizeC; j++)
            saida<<setw(2)<<obj.matriz[i][j]<<" ";
        cout<<"|";
        cout<<endl;
    }
    saida<< endl;
    return saida;
}
istream& operator>>(istream& entrada, MatrizDeReal& obj){
    cout<<setw(15)<<"[L][C]\n";
    for (unsigned int i = 0; i < obj.sizeL;i++)
    {
        for (unsigned int j = 0; j < obj.sizeC; j++)
        {
            cout<<"Posicao ["<<i+1<<"]["<<j+1<<"]: ";
            entrada>>obj.matriz[i][j];
        }
    }
    return entrada;
}

MatrizDeReal::~MatrizDeReal(){
    delete [] matriz;
}
