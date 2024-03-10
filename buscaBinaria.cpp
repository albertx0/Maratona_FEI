#include <bits/stdc++.h>

using namespace std;

int main(){
    	ios::sync_with_stdio(0);
    	cin.tie(0);

        //Algoritmo de Busca Binaria
        //Complexidade O(logN)

        int lista[] = {10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1};
        int n = 10;
        sort(lista , lista + n);

        int de = 0 , ate = n - 1;
        int numBusca = 1; //Numero para ser buscado com exemplo na lista
        int indice = -1;
        while(de <= ate){
            int meio = (de + ate) / 2;
            if(lista[meio] == numBusca){
                indice = meio;
                break;
            }else if(lista[meio] < numBusca){
                de = meio + 1;
            }else if(lista[meio] > numBusca){
                ate = meio - 1;
            }
        }

        if(indice == -1){
            cout << "O numero informado nao existe na lista...\n";
        }else{
            cout << "Numero encontrado no indice: " << indice << endl;
        }
}
