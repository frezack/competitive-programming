#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <list>
#include <forward_list>
#include <algorithm> // max...
#include <utility> // pair
#include <complex>
#include <climits> // int, ll...
#include <limits> // double...
#include <cmath> // abs, atan...
#include <cstring> // memset
#include <string>
#include <functional> // greater, less...
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef pair<double, int> di;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, ll> mil;
typedef map<ll, ll> mll;

#define INF 1000000000 // 10^9
#define PI acos(-1)
#define EPS 1e-9

int V, E;

struct ufds {
    vi p, r;
    int numSets;

    ufds(int N) {
        p.assign(N, 0); r.assign(N, 0); numSets = N;
        for (int i = 0; i < N; i++) p[i] = i;
    }

    int findSet(int i) { // finds and path compresses if possible
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x != y) {
            if (r[x] > r[y]) p[y] = x;
            else {
                p[x] = y;
                if (r[x] == r[y]) r[y]++;
            }
            numSets--;
        }
    }

    void print() {
        cout << "p[] = ";
        for (int i = 0; i < p.size(); i++)
            cout << i << " -> " << p[i] << "; ";
        cout << endl;
    }
};

int kruskal(vector<pair<int, ii>> &edgeList) {
    sort(edgeList.begin(), edgeList.end());
    int mst_cost = 0;
    ufds uf(V);

    for (int i = 0; i < E && uf.numSets != 1; i++) {
        pair<int, ii> front = edgeList[i];
        if (!uf.isSameSet(front.second.first, front.second.second)) {
            mst_cost += front.first;
            uf.unionSet(front.second.first, front.second.second);
        }
    }

    if (uf.numSets != 1) return INT_MAX; // this graph is not connected
    return mst_cost;
}

int main() {
    while (cin >> V >> E && !(V == 0 && E == 0)) {
        vector<pair<int, ii>> edgeList;
        int cost = 0;
        for (int i = 0; i < E; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            cost += z;
            edgeList.push_back(make_pair(z, ii(x, y)));
        }

        cout << cost - kruskal(edgeList) << endl;
    }

    return 0;
}