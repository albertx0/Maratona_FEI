#include <bits/stdc++.h>

using namespace std;

int main(){
    //Algoritimo de sorting Counting Sort
    //Complexidade O(n)
    //Possui limitacoes quando trata-se de um problema que os valores do menor e maior numero do array sao bastante distintos
    
    vector<int> teste = {9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 100000};

    int minimo = INT_MAX;
    int maximo = INT_MIN;

    for(int i = 0 ; i < teste.size() ; i++){
        minimo = min(minimo , teste[i]);
        maximo = max(maximo , teste[i]);
    }
    
    int k = maximo - minimo + 1;
    
    vector<int>reps(k , 0);
    
    for(int i = 0 ; i < teste.size() ; i++){
        reps[teste[i] - minimo]++;
    }
    
    teste.clear();
    
    for(int i = 0 ; i < k ; i++){
        while(reps[i] != 0){
            teste.push_back(i+minimo);
            reps[i]--;
        }
    }
    for(int i = 0 ; i < teste.size() ; i++){
        cout << teste[i] << " ";
    }
}
