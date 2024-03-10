#include <bits/stdc++.h>

using namespace std;

int main(){
    	ios::sync_with_stdio(0);
    	cin.tie(0);
        
        //Funcao eficiente para contar quantos elementos de uma lista possuem um valor informado, ao utilizar a funcao ela ja assume que o array esta ordenado
        //Complexidade log2(N) + 1
        //Utiliza algo aproximado da Busca binaria
        
        int lista[] = {10 , 9 , 8 , 7 , 6 , 5 , 4 , 1 , 1 , 1};
        int n = 10;

        sort(lista , lista + n);

        auto a = lower_bound(lista , lista + n , 1);
        auto b = upper_bound(lista , lista + n , 1);

        cout << b - a << endl;
}
