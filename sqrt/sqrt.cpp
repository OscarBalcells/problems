#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
const int oo = 1e9+7;

int n;
vector<int> nums;
vector<pair<int,ii>> blocks;

int query(int l, int r) {
    
    int ans = oo;
    
    for(int i = 0; i < (int)blocks.size(); ++i) {
        int start = blocks[i].second.first;
        int end = blocks[i].second.second;
        
        if(start >= l && end <= r) {
            ans = min(ans, blocks[i].first);
        } else if((l >= start && l <= end) || (r >= start && l <= end)) {
            for(int pos = max(start,l); pos <= end && pos <= r; ++pos) {
                //cout << start << " " << end << ", " << l << " " << r << " " << nums[pos] << endl;
                ans = min(ans, nums[pos]);
            }
        }
    }
    
    return ans;
}

void update(int pos, int val) {
    nums[pos] = val;
    for(int i = 0; i < (int)blocks.size(); ++i) {
        int start = blocks[i].second.first;
        int end = blocks[i].second.second;
        
        if(pos >= start && pos <= end) {
            int minimum = oo;
            for(int ind = start; ind <= end; ++ind) {
                minimum = min(nums[ind],minimum);
            }
            blocks[i].first = minimum;
            return;
        }
    }
}

void build() {
    
    int k = (int)sqrt(n);
    
    for(int i = 0; i < n;) {
        int minimum = oo;
        int ind = i;
        for(; ind < i+k+2 && ind < n; ++ind) {
            minimum = min(minimum, nums[ind]);
        }
        blocks.push_back(make_pair(minimum, ii(i, ind-1)));
        i = ind;
    }
    
}

int main() {
    
    scanf("%d", &n);
    
    nums.resize(n);
    for(int& x : nums) {
        scanf("%d", &x);
    }
    
    build();
    
    int m;
    scanf("%d", &m);
    
    for(int i = 0; i < m; ++i) {
        int t, a, b;
        scanf("%d %d %d", &t, &a, &b);
        if(t == 1) {
            //id, x
            update(a-1, b);
        } else {
            //l, r
            cout << query(a-1, b-1) << endl;
        }
    }
    
    return 0;
}
