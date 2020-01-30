#include <bits/stdc++.h>
using namespace std;

const int nax = 1e5+7;

vector<int> edges[nax];
vector<int> visited, values;
map<int,pair<int,int>> seen;

vector<pair<int,int>> blockIndexes;
vector<int> bestIndexInBlock;

int findBestInRange(int l, int r) {
    
    int bestIndex = -1;
    
    for(int blockIndex = 0; blockIndex < (int)blockIndexes.size(); ++blockIndex) {
        
        int start = blockIndexes[blockIndex].first;
        int end = blockIndexes[blockIndex].second;
        
        //cout << blockIndex << " " << start << " " << end << endl;
        
        if(start >= l && end <= r) { //totally in range
            if(bestIndex == -1 || values[bestIndex] > values[bestIndexInBlock[blockIndex]]) {
                bestIndex = bestIndexInBlock[blockIndex];
            }
        } else if((l >= start && l <= end) || (r >= start && r <= end)) {
            for(int pos = start; pos <= end; ++pos) {
                if(pos >= l && pos <= r) {
                   if(bestIndex == -1 || values[bestIndex] > values[pos]) {
                        bestIndex = pos;
                   }
                }
            }
        }
    }

    return bestIndex;
}

void euler(int a, int p, int d) {
    visited.push_back(a);
    values.push_back(d);
    seen[a] = make_pair((int)visited.size()-1, (int)visited.size()-1);
    
    for(int b : edges[a]) if(b != p) {
        euler(b, a, d+1);
        visited.push_back(a);
        values.push_back(d);
        seen[a].second = (int)visited.size()-1;
    }
}

int main() {
    
    int n;
    scanf("%d",&n);
    
    for(int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d",&a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    euler(1, 0, 1);
    
    n = (int)visited.size();
    
    int ind = 0;
    while(ind < n) {
        int minIndex, minVal = 999999;
        int i = ind;
        
        for(; i < ind+(int)ceil(sqrt(n))+2 && i < n; ++i) {
            if(values[i] < minVal) {
                minIndex = i;
                minVal = values[i];
            }
        }
        
        blockIndexes.push_back(make_pair(ind,i));
        ind = i;
        bestIndexInBlock.push_back(minIndex);
    }
    
    //positions[ind] -> where block starts and ends
    //blocks[ind] -> {minIndex, vector of block}
    
    int q1, q2;
    bool first = true;
    
    while(scanf("%d %d", &q1, &q2)==2) {
        
        pair<int,int> pos1 = seen[q1];
        pair<int,int> pos2 = seen[q2];
        
        if(!first) {
            cout << " ";
        }
        first = false;
        
        if(pos1.first >= pos2.first && pos1.second <= pos2.second) {
            cout << q2;
        } else if(pos2.first >= pos1.first && pos2.second <= pos1.second) {
            cout << q1;
        } else {
            int l = min(pos1.second, pos2.second);
            int r = max(pos1.first, pos2.first);
            
            //cout << "l: " << l << ", " << " r: " << r << endl;
            
            cout << visited[findBestInRange(l,r)];
        }
    }
    
    cout << endl;
    
    return 0;
}
