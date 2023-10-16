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

#define ll long long
#define MOD 1'000'000'007
using namespace std;

class taskC {

private:
    ll gcd(ll a, ll b, ll &x, ll &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        ll x1, y1;
        ll d = gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    }

    ll modInverse(ll value) {
        ll x, y;
        ll d = gcd(value, MOD, x, y);
        x = (x % MOD + MOD) % MOD;
        return x;
    }

    void factorial(vector<ll> &values, ll n) {
        values[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            values[i] = values[i - 1] * i % MOD;
        }
    }

public:
    void solve() {
        ll n, k;
        cin >> n >> k;
        vector<ll> fact(n + 1);
        factorial(fact, n);
        cout << (fact[n] * modInverse(fact[k] * fact[n - k] % MOD)) % MOD;
    }

};