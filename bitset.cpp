#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    //Exemplos de utilizacao do bitset, possui vantagens por utilizar apenas 1 bit de memoria

    bitset<10> s(string("0010011010")); //Quando criado desta maneira, a ordem sera da direita para a esquerda
    cout << s.count() << "\n"; // 4

    bitset<10> a(string("0010110110"));
    bitset<10> b(string("1011011000"));
    cout << (a&b) << "\n"; // 0010010000
    cout << (a|b) << "\n"; // 1011111110
    cout << (a^b) << "\n"; // 1001101110
}
