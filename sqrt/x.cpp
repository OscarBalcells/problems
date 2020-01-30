#include <bits/stdc++.h>
using namespace std;

bool valid(int n) {
    while(n > 0) {
        if(n%10 == 0 || n%10 > 3) {
            return false;
        }
    }
    return true;
}
vector<int> robot = {3,1,1,2,1,3,1,2,3,3};

string segment(int l, int r) {

}

int main() {
    
    for(int h = 0; h < 26; ++h) {
        for(int e = 0; e < 26; ++e) if(e != h) {
            for(int i = 0; i < 26; ++i) if(i != e && i != h) {
                int ans = 8*(h*10 + e) + i;
                int s = ans%10;
                int u = (ans/10)%10;
                if(d1 != h && d1 != e && d1 != i && d1 != d2) {
                    if(d2 != h && d2 != e && d2 != i) {
                        cout << h << " " << e << " " << " " << i << " " << u << " " << s << endl;
                    }
                }
            }
        }
    }
    

}
