#include <iostream>

using namespace std;

/*
Direcao:
    - 0: direita para a esquerda
    - 1: esquerda para a direita
*/
int lme(int *lista, int *direcao, int n){
    int indice=-1,valor=0,ii;
    for(ii=0;ii<n;ii++){
        if(valor<lista[ii]){
            if((direcao[ii]==0)&&(ii>0)&&(lista[ii]>lista[ii-1])){
                indice = ii;
                valor = lista[ii];
            }
            else if ((direcao[ii]==1)&&(ii<n-1)&&(lista[ii]>lista[ii+1])){
                indice = ii;
                valor = lista[ii];
            }
        }
    }
    return indice;
}

void swapLista(int *lista,int *direcao, int ii, int jj){
    int aux;
    aux = lista[ii];
    lista[ii] = lista[jj];
    lista[jj] = aux;

    aux = direcao[ii];
    direcao[ii] = direcao[jj];
    direcao[jj] = aux;
}

void reverseLista(int *lista, int *direcao, int valor, int n){
    int ii;
    for(ii=0;ii<n;ii++){
        if(valor<lista[ii]){
            if(direcao[ii] == 0)
                direcao[ii] = 1;
            else
                direcao[ii] = 0;
        }
    }
}

int pintLista(int *lista,  int n){
    int ii;
    cout << "Permutacao = ";
    for(ii=0;ii<n;ii++){
        cout << lista[ii]<<" ";
    }
    cout << endl;
}

void johnsonTrotter(int n){
    int ii,lista[n]={0},direcao[n]={0},valor,k;
    // Primeira permutacao
    cout << "Permutacao = ";
    for(ii=0;ii<n;ii++){
        lista[ii] = ii+1;
        direcao[ii] = 0;
        cout << lista[ii] << " ";
    }
    cout << endl;
    while(true){
        // maior elemento movel
        k = lme(lista,direcao,n);
        valor= lista[k];
        if(k==-1)
            break;
        else if(direcao[k] == 0)
            swapLista(lista,direcao,k,k-1);
        else
            swapLista(lista,direcao,k,k+1);
        reverseLista(lista,direcao,valor,n);
        pintLista(lista,n);
    }

}

int main()
{
    int permutacoes = 4;
    cout << "2 - Implementar o algoritmo Johnson-Trotter!" << endl;
    johnsonTrotter(permutacoes);
    return 0;
}
