#include <bits/stdc++.h>
using namespace std;

struct SPF {
    int N;
    vector<int> spf;

    SPF(int n) {
        N = n;
        spf.resize(N + 1);
        build();
    }

    void build() {
        for (int i = 0; i <= N; i++) spf[i] = i;
        if (N >= 0) spf[0] = 0;
        if (N >= 1) spf[1] = 1;

        for (int i = 2; i * i <= N; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= N; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
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
        map<int, int> cnt = factorCount(x);
        int ans = 1;
        for (auto [p, c] : cnt) {
            ans *= (c + 1);
        }
        return ans;
    }

    long long sumOfDivisors(int x) {
        map<int, int> cnt = factorCount(x);
        long long ans = 1;

        for (auto [p, c] : cnt) {
            long long term = 1;
            long long power = 1;
            for (int i = 0; i < c; i++) {
                power *= p;
                term += power;
            }
            ans *= term;
        }

        return ans;
    }

    int phi(int x) {
        int result = x;
        vector<int> primes = distinctPrimeFactors(x);
        for (int p : primes) {
            result -= result / p;
        }
        return result;
    }

    vector<int> allDivisors(int x) {
        map<int, int> cnt = factorCount(x);
        vector<int> divisors = {1};

        for (auto [p, c] : cnt) {
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
};

int main() {
    SPF s(1000000); // build up to 1e6

    int n;
    cin >> n;

    cout << "Prime? " << (s.isPrime(n) ? "YES" : "NO") << '\n';

    cout << "Prime factors: ";
    for (int x : s.primeFactors(n)) cout << x << " ";
    cout << '\n';

    cout << "Factor counts:\n";
    for (auto [p, c] : s.factorCount(n)) {
        cout << p << " -> " << c << '\n';
    }

    cout << "Distinct prime factors: ";
    for (int x : s.distinctPrimeFactors(n)) cout << x << " ";
    cout << '\n';

    cout << "Number of divisors: " << s.numberOfDivisors(n) << '\n';
    cout << "Sum of divisors: " << s.sumOfDivisors(n) << '\n';
    cout << "Phi(n): " << s.phi(n) << '\n';

    cout << "All divisors: ";
    for (int d : s.allDivisors(n)) cout << d << " ";
    cout << '\n';
}