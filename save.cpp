#include <bits/stdc++.h>

using namespace std;



int* cartas;
int qtd;
int pdm[20000];

int pd(int valor , int de , int ate , bool cond){

    if(de > ate || ate < de){
        return -INT_MAX;
    }

    int &pp = pdm[de + ate];
    if(pp == -1){
        if(de == ate){
        if(cond)
            return pp = valor + cartas[de];
        else
            return pp = valor;
        }else if(cond){
            return pp = max(pd(valor + cartas[de] , de + 1 , ate , false) , pd(valor + cartas[ate] , de , ate - 1 , false));
        }else{
            if(cartas[de] > cartas[ate]){
                return pp = pd(valor , de + 1 , ate , true);
            }else{
                return pp = pd(valor , de , ate - 1 , true);
            }
        }
    }else{
        return pp;
    }
}

int main(){

    while(cin >> qtd){

        cartas = new int[qtd];

        for(int i = 0 ; i < qtd ; i++){cin >> cartas[i];}
        memset(pdm , -1 , sizeof(pdm));

        cout << pd(0 , 0 , qtd - 1 , true) << endl;

    }



}
