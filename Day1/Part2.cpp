/*
   12 Dec 2023 at 3:52 PM
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

    map<string, string> numMap = {{"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};

    for (ll i = 0; i < sz(vs); i++) {
        set<pair<int, string>> allOccurrences;
        string curr = vs[i];

        for (auto [key, value] : numMap) {
            ll pos = curr.find(key);
            // cout<<"key: "<<key<<" ";
            while (pos != string::npos) {
                // curr.replace(pos, key.length(), value);
                // cout<<"pos: "<<pos<<" ";
                allOccurrences.insert({pos, key});
                pos = curr.find(key, pos + key.length());
            }
            // cout<<endl;
        }

        if (allOccurrences.size() >= 1) {
            auto first = allOccurrences.begin();
            curr.replace(first->first, 1, numMap[first->second]);
        }

        if (allOccurrences.size() >= 2) {
            auto last = allOccurrences.rbegin();
            curr.replace(last->first, 1, numMap[last->second]);
        }

        // cout << "curr: " << curr << "  ";

        string svalue = "";

        for (ll j = 0; j < curr.size(); j++) {
            if (isdigit(curr[j])) {
                svalue.push_back(curr[j]);
            }
        }

        string temp = to_string(svalue[0] - '0') + to_string(svalue[sz(svalue) - 1] - '0');
        // cout << "temp: " << temp << endl;
        svalue = temp;

        // cout << "svalue: " << svalue << endl;

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

/*
    12 Dec 2023 at 4:16 PM

two1nine -> 29
eightwothree -> 83
abcone2threexyz -> 13
xtwone3four -> 24
4nineeightseven2 -> 42
zoneight234 -> 14
7pqrstsixteen -> 76

In this example, the calibration values are 29, 83, 13, 24, 42, 14, and 76. Adding these together produces 281.

*/