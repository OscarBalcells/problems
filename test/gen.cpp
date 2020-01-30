#include <bits/stdc++.h>
using namespace std;

string generateString(int s, int i) {
    string ans = "";
    for(int i = 0; i < s; ++i) {
        ans += char(rand()%26+'a');
    }
    return ans;
}

int main() {
    
    int n;
    cin >> n;
    
    cout << n << endl;
    
    for(int i = 0; i < n; ++i) {
        cout << char(generateString(rand()%30+i) << endl;
    }
    
    return 0;
}
