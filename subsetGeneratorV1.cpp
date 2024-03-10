#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
void gerarSubconjuntos(int k);

int n = 3; // Valor que corresponde qual numero vai criar os Sub Conjuntos
vector<int> subConjunto;
int main(){
    	ios::sync_with_stdio(0);
    	cin.tie(0);

        gerarSubconjuntos(0); //Funcao recursiva em que o numero colocado como parametro demonstra o numero inicial do conjunto
}

void gerarSubconjuntos(int k){
    if(k == n){
        if(subConjunto.size() == 0){
            cout << "Conjunto vazio...\n";
        }else{
            for(int i = 0 ; i < subConjunto.size() ; i++){cout << subConjunto[i] << " ";}
            cout << endl;
        }
    }else{
        gerarSubconjuntos(k + 1);
        subConjunto.push_back(k);
        gerarSubconjuntos(k + 1);
        subConjunto.pop_back();
    }
}
