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
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void polygonArea(const vector<pt> points) { 
    ll area = 0; 
  
    // Calculate value of shoelace formula 
    int j = (int)points.size() - 1; 
    for (int i = 0; i < (int)points.size(); i++) { 
        area += (points[j].x + points[i].x) * (points[j].y - points[i].y); 
        j = i;
    } 
  
    if(area % 2 == 0) {
        cout << ll(area/2) << ".0" << endl;
    } else {
        cout << ll(area/2) << ".5" << endl;
    }
} 

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == (int)a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == (int)a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

int main() {
    int n;
    scanf("%d", &n);

    vector<pt> a;
    
    for(int i = 0; i < n; ++i) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        pt point;
        point.x = x+(ll)1e9;
        point.y = y+(ll)1e9;
        a.push_back(point);
    }
    
    convex_hull(a);
    cout << (int)a.size() << endl;

    for(pt x : a) {
        x.x -= (ll)1e9;
        x.y -= (ll)1e9;
        cout << x.x << " " << x.y << endl;
    }
    
    polygonArea(a);
}
