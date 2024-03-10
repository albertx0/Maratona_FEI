#include <bits/stdc++.h>

using namespace std;

int main(){
    	ios::sync_with_stdio(0);
    	cin.tie(0);

      //Algoritmo de sorting bubbleSort
      //Complexidade O(n^2)

      int lista[] = {10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1};
      int n = 10;
      for(int i = 0 ; i < n ; i++){
          for(int g = 0 ; g < n - 1 ; g++){
              if(lista[g] > lista[g + 1]){
                  swap(lista[g], lista[g + 1]);
              }
          }
      }
      for(int i = 0 ; i < n ; i++) cout << lista[i] << " ";
      cout << endl;
}
