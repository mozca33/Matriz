#include "testamatriz.h"

void TestaMatriz::menu()
{
    MatrizDeReal M1(1,1),M2(1,1);
    int op, l,c,i=1;
    do
    {
        cout<< "Digite:\n";
        cout<< "1 - Para obter as matrizes(n=2)\n";
        cout<< "2 - Para mostrar as matrizes.\n";
        cout<< "3 - Para somar as matrizes (Mesma ordem).\n";
        cout<< "4 - Para subtrair as matrizes (Mesma ordem).\n";
        cout<< "5 - Para multiplicar as matrizes (Numero de colunas da matriz 1 = ao numero de linhas da matriz 2).\n";
        cout<< "6 - Para dividir as matrizes(Multiplicacao pelo inverso da segunda).\n";
        cout<< "7 - Para encerrar o programa.\n";
        cin>> op;
        switch(op)
        {
        case 1: // obter matriz
            do
            {
                cout<<"Digite o tamanho da matriz "<<i<<":"<<endl;
                cout<<"Linha(s): ";
                cin>>l;
                cout<<"\nColuna(s): ";
                cin>>c;
                cout<<endl;
            }while(!M1.setMatriz(l,c));
            cout<< "Digite os elementos da matriz "<<i<<":"<<endl;
            cin >> M1;
            i++;
            do
            {
                cout<<"\nDigite o tamanho da matriz "<<i<<":"<<endl;
                cout<<"Linha(s): ";
                cin >>l;
                cout<<"\nColuna(s): ";
                cin >>c;
                cout<<endl;
            }while(!M2.setMatriz(l,c));
            cout<< "Digite os elementos da matriz "<<i<<":"<<endl;
            cin >> M2;
            i = 1;
            break;

        case 2: // mostrar
            cout<< "Matriz 1:\n";
            cout<< M1 <<" "<<endl;
            cout<< "Matriz 2:\n";
            cout<< M2 <<" "<<endl;
            break;

        case 3: // somar
            try{
            cout<< M1+M2<<endl;
            }catch(string& msg){
                cout<<msg<<endl;
            }
            break;

        case 4: // subtrair
            try{
            cout<< M1-M2<<endl;
            }catch(string& msg){
                cout<<msg<<endl;
            }
            break;

        case 5: // multiplicar
            try{
            cout<< M1*M2<<endl;
            }catch(string& msg){
                cout<<msg<<endl;
            }
            break;
        case 6: // dividir
            try{
            MatrizDeReal invertida = M2.inverter(M2);
            cout <<M1*invertida<<endl;
            }catch(string& msg){
                cout<<msg<<endl;
            }
            break;

        case 7:
            M2.~MatrizDeReal();
            break;

        default:
            cout<<"Opcao invalida.\n";
        }
    }while(op!=7);
}
