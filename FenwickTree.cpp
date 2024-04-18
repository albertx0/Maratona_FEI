#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & - (S)) //Usado para pegar o bit
                                    //menos significativo

typedef vector<int> vi;

class FenwickTree {
    private:
        vi ft;
    public:
        FenwickTree(int m) { ft.assign(m + 1 , 0); }

        int rsq(int j){ //Calcula a soma dos valores da arvore
            int sum = 0;  //ate o indice j, utilizando LSOne para iterar
            for(; j ; j -= LSOne(j))
                sum += ft[j];
            return sum;
        }

        int rsq(int i , int j){ return rsq(j) - rsq(i - 1); } //Retorna a soma
                                                        //Acumulada entre os indices j e i - 1
        void update(int i , int v) { //Soma elementos da arvore na posicao i com v
            for(; i < (int)ft.size() ; i += LSOne(i))
                ft[i] += v;
        }
};   

int main(){
    FenwickTree ft(10); //Criar a arvore de tam 10

    //Atualizando o valor dos elementos
    ft.update(1 , 5);//Elemento 1 foi somado com o valor 5
    ft.update(3 , 7);//Elemento 3 foi somado com o valor 7
    ft.update(6 , 3);//Elemento 6 foi somado com o valor 3

    cout << "Soma ate o indice 5: " << ft.rsq(5) << endl;
    cout << "Soma no intervalo [2 , 7]: " << ft.rsq(2 , 7) << endl;
}
