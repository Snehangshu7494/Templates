#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 1e6;
static const long long MOD = 1e9 + 7;

long long fact[MAXN + 1];
long long invfact[MAXN + 1];

// Fast exponentiation
long long modpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void pfact() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invfact[MAXN] = modpow(fact[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i--) {
        invfact[i - 1] = (invfact[i] * i) % MOD;
    }
}

// nCr = n! / (r! * (n-r)!)
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

// nPr = n! / (n-r)!
long long nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[n - r] % MOD;
}

// IF MOD is not prime

// const int MAXN = 5005;
// ll MOD;
// vector<vector<ll>> C(MAXN + 1, vector<ll>(MAXN + 1, 0));
// vector<ll> fact(MAXN + 1, 1);

// void build() {
//     for (int i = 1; i <= MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;

//     for (int n = 0; n <= MAXN; n++) {
//         C[n][0] = C[n][n] = 1 % MOD;
//         for (int r = 1; r < n; r++) {
//             C[n][r] = (C[n - 1][r - 1] + C[n - 1][r]) % MOD;
//         }
//     }
// }

// ll nCr(int n, int r) {
//     if (r < 0 || r > n) return 0;
//     return C[n][r];
// }

// ll nPr(int n, int r) {
//     if (r < 0 || r > n) return 0;
//     return (C[n][r] * fact[r]) % MOD;
// }

int main() {
    pfact();

    cout << "10C3 = " << nCr(10, 3) << endl; // 120
    cout << "10P3 = " << nPr(10, 3) << endl; // 720

    return 0;
}
