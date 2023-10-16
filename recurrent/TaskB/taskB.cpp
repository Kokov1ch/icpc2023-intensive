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
using namespace std;
const int MOD = 1000000007;

ll gcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0){
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

ll modInverse(ll value)
{
    ll x, y;
    ll d = gcd(value, MOD, x, y);
    x = (x % MOD + MOD) % MOD;
    return x;
}

ll factorial(int value)
{

    if(value == 1 || value == 0)
    {
        return 1;
    }
    else
        return value * factorial(value-1) % MOD;
}

//void solve() {
//    int n, k;
//    cin >> n >> k;
//    cout << (factorial(n) * modInverse(factorial(k) * factorial(n - k) % MOD)) % MOD;
//}
