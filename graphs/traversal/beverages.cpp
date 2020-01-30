#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vi> invalid;
vector<bool> vis;
map<string, int> bevs;
map<int, string> nums;
int n;
int TC = 1;

void invalidate(int cur, int inv) {
    
    invalid[cur][inv] = true;
    for(int i = 0; i < n; ++i) if(i != cur) {
        if(invalid[i][cur]) {
            invalidate(i, inv);
        }
    }
}


void dfs(int cur) {
    //can we print it now?
    //if there is any
    int i = 0;

    for(; i < n; ++i) if(i != cur && !vis[i]) {
        if(invalid[cur][i]) {
            for(int j = cur+1; j < n; ++j) if(!vis[j]) {
                dfs(j);
                return;
            }
        }
    }
    
    cout << " " << nums[cur];
    vis[cur] = true;
    
    //this is a pure vertex now
    for(i = 0; i < n; ++i) if(!vis[i]) {
        dfs(i);
        return;
    }

}

int main() {
    
    while(scanf("%d%*c", &n) != EOF) {
    
        string beverage;
        bevs.clear();
        nums.clear();
        
        invalid.resize(n);
        for(int i = 0; i < n; ++i) {
            invalid[i].assign(n, false);
        }
        
        for(int i = 0; i < n; ++i) {
            cin >> beverage;
            bevs[beverage] = i;
            nums[i] = beverage;
        }
        
        int c;
        cin >> c;
        
        vector<pair<string, string>> constraints;
        
        for(int i = 0; i < c; ++i) {
            string bev1, bev2;
            cin >> bev1 >> bev2;
            constraints.push_back(make_pair(bev1, bev2));
            invalid[bevs[bev2]][bevs[bev1]] = true;
        }
        
        for(int i = 0; i < c; ++i) {
            string bev1, bev2;
            bev1 = constraints[i].first, bev2 = constraints[i].second;
            invalidate(bevs[bev2], bevs[bev1]);
        }
        
        vis.assign(n, false);

        cout << "Case #" << TC << ": Dilbert should drink beverages in this order:";
        dfs(0);
        cout << "." << endl << endl;
        
        TC++;
    }

    return 0;

}
