#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define f first
#define s second

#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;

vector<char>cor;
vector<int>pai;

int inicio_ciclo , fim_ciclo;

bool dfs(vector<vector<int>> &grafo , int source){
		cor[source] = 1;

		for(auto &vertice : grafo[source]){
			if(cor[vertice] == 0){
				pai[vertice] = source;
				if(dfs(grafo , vertice))
					return true;
			}else if(cor[vertice] == 1){
				fim_ciclo = source;
				inicio_ciclo = vertice;
				return true;
			}
		}
		cor[source] = 2;
		return false;
}

void acharCiclo(vector<vector<int>> &grafo){
		cor.assign(n , 0);
		pai.assign(n , -1);
		inicio_ciclo = -1;

		for(int v = 0 ; v < n ; v++){
			if(cor[v] == 0 && dfs(grafo , v))
				break;
		}
		if(inicio_ciclo == -1){
			cout << "Sem ciclo" << endl;
			}
		else{
				vector<int> ciclo;
				ciclo.push_back(inicio_ciclo);

				for(int v = fim_ciclo ; v != inicio_ciclo ; v = pai[v])
					ciclo.push_back(v);
				ciclo.push_back(inicio_ciclo);
				reverse(ciclo.begin() , ciclo.end());

				cout << "Ciclo Encontrado: ";
				for(auto &v : ciclo)
					cout << v << " ";
				cout << endl;
			}
	}
int main(){ _
	vector<vector<int>> grafo = {{1} , {2} , {0}};
	n = 3;
	acharCiclo(grafo);	

	return 0;
}
