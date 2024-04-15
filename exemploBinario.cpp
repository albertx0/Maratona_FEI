#include <bits/stdc++.h>

using namespace std;

int main(){
    // Exercicio 1026 beecrowd
    long long num1 , num2;

    while(cin >> num1 >> num2){
        bitset<sizeof(int) * 32> b1(num1); // Declara dois bitsets de 32 bits
        bitset<sizeof(int) * 32> b2(num2);
        
        bitset<sizeof(int) * 32> Nb1 = ~b1; // Realiza o not dos dois bitsets
        bitset<sizeof(int) * 32> Nb2 = ~b2;

        bitset<sizeof(int) * 32> and1 =(Nb1&b2); // Realiza dois ands
        bitset<sizeof(int) * 32> and2 =(b1&Nb2);

        bitset<sizeof(int) * 32> fin = (and1|and2); // Realiza um or

        string resu = fin.to_string(); // Tranformas de binario para string

        cout << stoll(resu , 0 , 2) << endl; // Imprime em formato long long, o terceiro parametro , 2 ,
                                                                            // demonstra a funcao que a string é binaria
    }

    return 0;
}
