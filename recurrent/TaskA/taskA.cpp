#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <unordered_set>
#include <fstream>

#define ll long long
using namespace std;

class taskA {
public:
    void solve() {
        ifstream in("input.txt");
        ofstream out("output.txt");
        int s, n, m;
        in >> s;
        vector<vector<ll>> dp(s, vector<ll>(s, 0));
        vector<vector<int>> rows(s, vector<int>(2, 0));


        for (int i = 0; i < s; i++) {
            dp[i][i] = 0;
        }

        for (int i = 0; i < s; i++) {
            in >> n >> m;
            rows[i][0] = n;
            rows[i][1] = m;
        }

        for (int len = 2; len <= s; len++) {
            for (int l = 0; l + len - 1 < s; l++) {
                int r = l + len - 1;
                dp[l][r] = INT_MAX;
                for (int k = l; k < r; k++) {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + rows[l][0] * rows[k][1] * rows[r][1]);
                }
            }
        }
        out << dp[0][s - 1] << endl;
        in.close();
        out.close();
    }
};
