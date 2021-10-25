#ifndef MATRIZDEREAL_H
#define MATRIZDEREAL_H
#include <iostream>
#include <iomanip>
#include <exception>
#include <string>
/*  Alunos: Rafael Felipe Cordeiro
 *          Bruno Lino Nascimento
 *
 *  Trabalho de matriz
 *
 *
 */
using namespace std;
class MatrizDeReal
{
private:
    unsigned int sizeL;//tamanho da linha
    unsigned int sizeC;//tamanho da coluna
    double **matriz;
public:
    MatrizDeReal(int,int);
    MatrizDeReal& operator+(const MatrizDeReal&);
    MatrizDeReal& operator-(const MatrizDeReal&);
    MatrizDeReal& operator*(const MatrizDeReal&);
    friend istream& operator>>(istream&, MatrizDeReal&);
    friend ostream& operator<<(ostream&, MatrizDeReal&);
    bool setMatriz(int,int);
    MatrizDeReal inverter(MatrizDeReal&);

    ~MatrizDeReal();
};

#endif // MATRIZDEREAL_H
