#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct pt {
    ll x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) >= 0;
}


int main() {
    int n;
    scanf("%d", &n);

    vector<pt> a;
    
    pt firstPoint, secondPoint;
    ll x, y;
    
    scanf("%lld %lld", &x, &y);
    firstPoint.x = x;
    firstPoint.y = y;
    a.push_back(firstPoint);
    
    scanf("%lld %lld", &x, &y);
    secondPoint.x = x;
    secondPoint.y = y;
    a.push_back(secondPoint);
    
    for(int i = 2; i < n; ++i) {
        scanf("%lld %lld", &x, &y);
        pt point;
        point.x = x;
        point.y = y;
        a.push_back(point);
    }
    
    a.push_back(firstPoint);
    a.push_back(secondPoint);
    
    bool allCCW = true;
    bool allCW = true;
    
    for(int i = 2; i < (int)a.size(); ++i) {
        if(!ccw(a[i-2],a[i-1],a[i])) allCCW = false;
        if(!cw(a[i-2],a[i-1],a[i])) allCW = false;
    }    
    
    if(!allCW && !allCW) reverse(a.begin(),a.end());
    
    allCCW = true;
    allCW = true;
    
    for(int i = 2; i < (int)a.size(); ++i) {
        if(!ccw(a[i-2],a[i-1],a[i])) allCCW = false;
        if(!cw(a[i-2],a[i-1],a[i])) allCW = false;
    }  
    
    if(allCCW) cout << "YES" << endl;
    else if(allCW) cout << "YES" << endl;
    else cout << "NO" << endl;
}
