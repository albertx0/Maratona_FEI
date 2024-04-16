#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UnionFind{
    private:
        vi p , rank , setSize;
        int numSets;
    public:
        UnionFind(int N){
            p.assign(N , 0);
            for(int i = 0 ; i < N ; i++) p[i] = i;
            rank.assign(N , 0);
            setSize.assign(N , 1);
            numSets = N;
        }
    
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i , int j) { return findSet(i) == findSet(j); }
    int numDisjointSet() {return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }

    void unionSet(int i , int j){

        if(isSameSet(i , j)) // Caso i e j estejam no mesmo set
            return;
        int x = findSet(i) , y = findSet(j); // Encontra o vertice representativo de ambos os itens
        if(rank[x] > rank[y])  // mantem x "menor" que y
            swap(x , y);
        p[x] = y; // Coloca x abaixo de y
        if(rank[x] == rank[y]) 
            ++rank[y];
        
        setSize[y] += setSize[x]; // Combina os sets em y
        --numSets; // Reduz o numero de sets
    }
};

int main(){
    UnionFind UF(5);
    printf("%d\n" , UF.numDisjointSet()); // 5
    UF.unionSet(0 , 1);

    printf("%d\n" , UF.numDisjointSet()); // 4
    UF.unionSet(2 , 3);

    printf("%d\n" , UF.numDisjointSet()); // 3
    UF.unionSet(4 , 3);
    
    printf("%d\n" , UF.numDisjointSet()); // 2;

    printf("isSameSet(0 , 3) = %d\n" , UF.isSameSet(0 , 3)); // 0 (false)
    printf("isSameSet(4 , 3) = %d\n" , UF.isSameSet(4 , 3)); // 1 (true)


    for(int i = 0 ; i < 5 ; i++) // 1 for {0 , 1} and 3 for {2 , 3 , 4}
        printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n",
                i, UF.findSet(i), i, UF.sizeOfSet(i));
    
    UF.unionSet(0 , 3);
    printf("%d\n" , UF.numDisjointSet()); // 1

    for(int i = 0 ; i < 5 ; i++) // 3 for {0 , 1 , 2 , 3 , 4}
        printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n",
                i, UF.findSet(i), i, UF.sizeOfSet(i));

    return 0;
}
