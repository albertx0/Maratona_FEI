#include <bits/stdc++.h>

using namespace std;

int main(){
    	ios::sync_with_stdio(0);
    	cin.tie(0);

        //Algoritmo para calcular a maior soma de um subarray
        //Complexidade O(N)

        int melhorSoma = 0;

        int lista[] = {-1 , 2 , 4 , -3 , 5 , 2 , -5 , 2};
        int n = 8;
        int soma = 0;
        for(int i = 0 ; i < n ; i++){
            soma = max(lista[i] , soma + lista[i]);
            melhorSoma = max(melhorSoma , soma);
        }

    	cout << melhorSoma << endl;
}
