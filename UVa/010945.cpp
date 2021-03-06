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

int main() {
    string s;
    while (getline(cin, s) && s != "DONE") {
        bool palindrome = true;
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            while (i <= j && !isalpha(s[i])) i++;
            while (i <= j && !isalpha(s[j])) j--;
            if (i <= j && tolower(s[i]) != tolower(s[j])) {
                palindrome = false;
                break;
            }

            i++, j--;
        }

        if (palindrome) cout << "You won't be eaten!" << endl;
        else cout << "Uh oh.." << endl;
    }

    return 0;
}