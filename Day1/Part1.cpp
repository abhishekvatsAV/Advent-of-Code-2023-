/*
   12 Dec 2023 at 2:04 PM
    Tuesday
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using vvl = vector<vector<ll>>;
#define loop(i, a, b) for (ll i = a; i <= b; i++)
#define pb push_back
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define endl '\n'

const int mod = 1e7;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

double PI = acos(-1);
const int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
const int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
// for grid movement - up, down, left, right
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

/*



*/

void solve() {
    vector<string> vs;
    string input;

    while (getline(cin, input)) {
        vs.push_back(input);
    }

    ll ans = 0;

    for (ll i = 0; i < vs.size(); i++) {
        string curr = vs[i];
        string svalue = "";

        for (ll j = 0; j < curr.size(); j++) {
            if (isdigit(curr[j])) {
                svalue.push_back(curr[j]);
            }
        }

        if (svalue.size() == 1) {
            svalue += svalue;
        }
        // cout << "svalue: " << svalue << endl;
        if (svalue.size() > 2) {
            string temp = to_string(svalue[0] - '0') + to_string(svalue[sz(svalue) - 1] - '0');
            // cout << "temp: " << temp << endl;
            svalue = temp;
        }

        ll value = stoi(svalue);
        ans += value;
    }

    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // freopen("speed.in", "r", stdin); freopen("speed.out", "w", stdout);

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}
