#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

int n = 3; //Numero total de numeros a serem permutados
vector<int> permutacoes;
vector<bool> escolhido(n , false); //Vector booleano para verificar se um numero ja foi escolhido

void functionPermutations();

int main(){
    	ios::sync_with_stdio(0);
    	cin.tie(0);
        
        //Codigo pode ser facilmente adptado para numeros de acordo com a entrada do problema
        
        functionPermutations();
}

void functionPermutations(){
    if(permutacoes.size() == n){
        for(int i = 0 ; i < n ; i++){cout << permutacoes[i] << " ";}
        cout << endl;
    }else{
        for(int i = 0 ; i < n ; i++){
            if(escolhido[i]) continue;
            escolhido[i] = true;
            permutacoes.push_back(i);
            functionPermutations();
            escolhido[i] = false;
            permutacoes.pop_back();
        }
    }
}
