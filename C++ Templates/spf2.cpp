#include <bits/stdc++.h>
using namespace std;

struct NumberTheory {
    int N;
    long long MOD;
    vector<int> spf;
    vector<int> primes;

    NumberTheory(int n, long long mod = 1000000007LL) {
        N = n;
        MOD = mod;
        spf.assign(N + 1, 0);
        buildSPF();
    }

    void buildSPF() {
        for (int i = 0; i <= N; i++) spf[i] = i;
        if (N >= 0) spf[0] = 0;
        if (N >= 1) spf[1] = 1;

        for (int i = 2; i <= N; i++) {
            if (spf[i] == i) primes.push_back(i);
            for (int p : primes) {
                if (1LL * i * p > N || p > spf[i]) break;
                spf[i * p] = p;
            }
        }
    }

    bool isPrime(int x) {
        if (x < 2) return false;
        return spf[x] == x;
    }

    vector<int> primeFactors(int x) {
        vector<int> factors;
        while (x > 1) {
            factors.push_back(spf[x]);
            x /= spf[x];
        }
        return factors;
    }

    map<int, int> factorCount(int x) {
        map<int, int> cnt;
        while (x > 1) {
            cnt[spf[x]]++;
            x /= spf[x];
        }
        return cnt;
    }

    vector<pair<int,int>> factorize(int x) {
        vector<pair<int,int>> ans;
        while (x > 1) {
            int p = spf[x], c = 0;
            while (x % p == 0) {
                x /= p;
                c++;
            }
            ans.push_back({p, c});
        }
        return ans;
    }

    vector<int> distinctPrimeFactors(int x) {
        vector<int> ans;
        while (x > 1) {
            int p = spf[x];
            ans.push_back(p);
            while (x % p == 0) x /= p;
        }
        return ans;
    }

    int numberOfDivisors(int x) {
        auto cnt = factorCount(x);
        int ans = 1;
        for (auto [p, c] : cnt) ans *= (c + 1);
        return ans;
    }

    long long sumOfDivisors(int x) {
        auto cnt = factorCount(x);
        long long ans = 1;

        for (auto [p, c] : cnt) {
            long long term = 1;
            long long cur = 1;
            for (int i = 0; i < c; i++) {
                cur *= p;
                term += cur;
            }
            ans *= term;
        }
        return ans;
    }

    int phi(int x) {
        int result = x;
        auto dpf = distinctPrimeFactors(x);
        for (int p : dpf) result -= result / p;
        return result;
    }

    vector<int> allDivisors(int x) {
        auto fac = factorize(x);
        vector<int> divisors = {1};

        for (auto [p, c] : fac) {
            vector<int> temp;
            long long mul = 1;
            for (int i = 1; i <= c; i++) {
                mul *= p;
                for (int d : divisors) {
                    temp.push_back(d * mul);
                }
            }
            for (int v : temp) divisors.push_back(v);
        }

        sort(divisors.begin(), divisors.end());
        return divisors;
    }

    long long binpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }

    long long modpow(long long a, long long b, long long mod = -1) {
        if (mod == -1) mod = MOD;
        a %= mod;
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long long gcdll(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcmll(long long a, long long b) {
        return (a / gcdll(a, b)) * b;
    }

    long long modInversePrime(long long a, long long mod = -1) {
        if (mod == -1) mod = MOD;
        return modpow(a, mod - 2, mod);
    }

    long long extendedGCD(long long a, long long b, long long &x, long long &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        long long x1, y1;
        long long g = extendedGCD(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return g;
    }

    long long modInverse(long long a, long long mod) {
        long long x, y;
        long long g = extendedGCD(a, mod, x, y);
        if (g != 1) return -1; // inverse doesn't exist
        x %= mod;
        if (x < 0) x += mod;
        return x;
    }
};

int main() {
    NumberTheory nt(1000000); // supports values up to 1e6

    int n;
    cin >> n;

    cout << "isPrime: " << nt.isPrime(n) << '\n';

    cout << "primeFactors: ";
    for (int x : nt.primeFactors(n)) cout << x << " ";
    cout << '\n';

    cout << "factorCount:\n";
    for (auto [p, c] : nt.factorCount(n)) {
        cout << p << " -> " << c << '\n';
    }

    cout << "distinctPrimeFactors: ";
    for (int x : nt.distinctPrimeFactors(n)) cout << x << " ";
    cout << '\n';

    cout << "numberOfDivisors: " << nt.numberOfDivisors(n) << '\n';
    cout << "sumOfDivisors: " << nt.sumOfDivisors(n) << '\n';
    cout << "phi: " << nt.phi(n) << '\n';

    cout << "allDivisors: ";
    for (int d : nt.allDivisors(n)) cout << d << " ";
    cout << '\n';

    cout << "binpow(2,10): " << nt.binpow(2,10) << '\n';
    cout << "modpow(2,10): " << nt.modpow(2,10) << '\n';
    cout << "gcd(24,36): " << nt.gcdll(24,36) << '\n';
    cout << "lcm(24,36): " << nt.lcmll(24,36) << '\n';
    cout << "modInversePrime(5): " << nt.modInversePrime(5) << '\n';
}