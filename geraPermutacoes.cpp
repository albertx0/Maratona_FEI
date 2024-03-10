#include <bits/stdc++.h>

using namespace std;

int n = 3; //Numero total de numeros a serem permutados
vector<int> permutacoes;

int main(){
    	ios::sync_with_stdio(0);
    	cin.tie(0);
        
        //Funcao para exibir todas as permutacoes possiveis
        //Complexidade O(N!)
        
       for(int i = 0 ; i < n ; i++){
            permutacoes.push_back(i);
       }

       do{
        for(int i = 0 ; i < n ; i++){cout << permutacoes[i] << " ";}
        cout << endl;
       }while(next_permutation(permutacoes.begin() , permutacoes.end()));
}
