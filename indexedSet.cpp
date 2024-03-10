#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int , null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update> indexed_set;

int main(){
    	ios::sync_with_stdio(0);
    	cin.tie(0);

        // Estrutura de dados que se comporta como um set porem que nos permite indexala como se fosse um array
        // Todas as funcoes abaixo apresentam complexidade O(logN)
        indexed_set s;
        s.insert(2);
        s.insert(7);
        s.insert(14);

        auto x = s.find_by_order(2); //Retorna o ponteiro do indice selecionado
        cout << *x << "\n";
        cout << s.order_of_key(2) << "\n"; //Retorna o indice caso o numero inserido como parametro existe no array ordenado
        cout << s.order_of_key(15) << "\n"; //Caso o elemento nao exista no array ele retorna a posicao posicao que ele teria se existisse no array
}
