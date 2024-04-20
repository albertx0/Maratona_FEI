#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree {
    private:
        vll ft;
    public:
        //Cria uma FT vazia
        FenwickTree(int m) { ft.assign(m + 1 , 0); }

        //Constroi a FT por meio do vetor f
        void build(const vll &f) {
            int m = (int)f.size() - 1; //f[0] sempre eh zero
            ft.assign(m + 1 , 0);

            for(int i = 1 ; i <= m ; i++){
                ft[i] += f[i]; //Adiciona o valor

                if(i + LSOne(i) <= m) // Se i tem pai
                    ft[i + LSOne(i)] += ft[i]; //Adiciona para o pai
            }
        }

    FenwickTree(const vll &f) { build(f); } //Criar uma FT baseada no f

    //Criar um FT baseada em um vetor de indices s
    FenwickTree(int m , const vi &s){ 
        vll f(m + 1 , 0);
        for(int i = 0 ; i < (int)s.size() ; i++)
            ++f[s[i]];
        build(f);
    }

    ll rsq(int j) { //Retorna RSQ(1 , j) Soma dos 
        ll sum = 0;             //elementos do vetor
        for(; j ; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    //Retorna a soma dos elementos do intervalo do vetor original
    ll rsq(int i , int j) { return rsq(j) - rsq(i - 1); }

    //Adiciona v ao elemento na posicao i do vetor original
    void update(int i , ll v) {
        for(; i < (int)ft.size() ; i += LSOne(i))
            ft[i] += v;
    }

    // Retorna a posicao do k-esimo elemento 
            //no vetor original comencando do 1
    int select(ll k) { //O(log^2 m)
        int lo = 1 , hi = ft.size() - 1;

        for(int i = 0 ; i < 30 ; i++){
            int mid = (lo + hi) / 2;
            (rsq(1 , mid) < k) ? lo = mid : hi = mid;
        }
        return hi;
    }
};

//Utilizar quando eh necessario atualizar intervalos de elementos
                // e fazer consultas pontuais
class RUPQ { //Variante RUPQ
    private:
        FenwickTree ft;
    public:
        //Inicia o objeto ft com uma FT de tamanho m
        RUPQ(int m) : ft(FenwickTree(m)) {} 

        //Atualiza um intervalo [ui , uj] do vetor original
        // adicionando v
        void range_update(int ui , int uj , int v){ 
            ft.update(ui , v); //[ui , ui + 1 , ... m] + v
            ft.update(uj + 1 , -v); //[uj + 1, uj + 2, ...., m] -v
        }                           //[ui , ui + 1 , ... , uj] + v

        //rsq(i) eh suficiente
        ll point_query(int i) {return ft.rsq(i); } 
};

class RURQ {
    private:
        RUPQ rupq;
        FenwickTree purq;
    public:
        //Inicializacao
        RURQ(int m) : rupq(RUPQ(m)) , purq(FenwickTree(m)) {} 
        void range_update(int ui , int uj , int v){
            rupq.range_update(ui , uj , v); // [ui, ui+1, .., uj] +v
            purq.update(ui , v * (ui - 1)); // -(ui-1)*v antes ui
            purq.update(uj + 1 , -v * uj);  // +(uj-ui+1)*v depois uj
        }

        ll rsq(int j){
            return rupq.point_query(j) * j - //Calculo inicial
                        purq.rsq(j); //Fator cancelante
        }

        ll rsq(int i , int j) { return rsq(j) - rsq(i - 1); } //Padrao
};

int main(){

}
