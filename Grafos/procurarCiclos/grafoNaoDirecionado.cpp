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

vector<bool> visitados;
vector<int> pais;

int inicio_ciclo , fim_ciclo;

bool dfs(vector<vector<int>> &grafo , int source , int pai){
		visitados[source] = true;

		for(int &v : grafo[source]){
				if(v == pai) continue;

				if(visitados[v]){
						fim_ciclo = source;
						inicio_ciclo = v;
						return true;
					}
					pais[v] = source;
					if(dfs(grafo , v , pais[v]))
						return true;
			}
			return false;
	}

void acharCiclo(vector<vector<int>> &grafo){
		visitados.resize(n , false);
		pais.resize(n , -1);
		inicio_ciclo = -1;

		for(int v = 0 ; v < n ; v++){
				if(!visitados[v] and dfs(grafo , v , pais[v]))
					break;
		}

		if(inicio_ciclo == -1)
			cout << "Nao possui ciclo" << endl;
		else{
			vector<int> ciclo;
			ciclo.push_back(inicio_ciclo);

			for(int v = fim_ciclo ; v != inicio_ciclo  ; v = pais[v])
				ciclo.push_back(v);
			ciclo.push_back(inicio_ciclo);

			cout << "Possui ciclo: ";
			for(auto &v : ciclo)
				cout << v << " ";
			cout << endl;
		}
	}

int main(){ _
	vector<vector<int>> grafo = {{1 , 2} , {0 , 2} , {0 , 1}};
	n = 3;
	acharCiclo(grafo);
	return 0;
}
