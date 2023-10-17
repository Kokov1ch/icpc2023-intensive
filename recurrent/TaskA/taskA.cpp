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
            for (int i = 0; i + len - 1 < s; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + rows[i][0] * rows[k][1] * rows[j][1]);
                }
            }
        }
        out << dp[0][s - 1] << endl;
        in.close();
        out.close();
    }
};
