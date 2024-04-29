#include <bits/stdc++.h>

using namespace std;

int i;

#define LSOne(S) ((S) & -(S))

int main(){
    int l[] = {1 , 2 , 3 , 4 , 5 , 6 , 7};
    int X; cin >> X;
    int n = 7;
    for(int i = 0 ; i < (1<<n) ; i++){ // Para cada subconjunto
        int soma = 0;
        int mask = i; // Inicia o mask com o sunconjunto atual

        while(mask){
            int two_pow_j = LSOne(mask); // Encontra o bit menos significativo
            // Obtem o indice do bit menos significativo
            int j = __builtin_ctz(two_pow_j); 
            soma += l[j];
            mask -= two_pow_j; // Remove o bit menos significativo da mascara
        }
        if(soma == X){ // Se a resposta for alcancada
            printf("Resposta encontrada !\n");
            break;
        }
    }

    return 0;    
}
