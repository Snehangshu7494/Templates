#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<vector>
#include<climits>
#include<queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define EDA_PARI_NA_BHAI  { ios_base::sync_with_stdio(false); cin.tie(0); }
#define ll long long
#define lf double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
#define llv vector<ll>
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define pdis(n) fixed<<setprecision(n)
#define spc " "
#define INF INT_MAX
#define NINF INT_MIN
#define Check "Check "
#define vpll vector<pair<ll,ll>>

vector<bool> is_prime(100005, true);
int limit =100004;
void sieve() {
    //vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int num = 2; num * num <= limit; ++num) {
        if (is_prime[num]) {
            for (int multiple = num * num; multiple <= limit; multiple += num) {
                is_prime[multiple] = false;
            }
        }
    }
    //return is_prime;
}


ll findClosestNumber(llv& vec, ll target) {
    auto it = lower_bound(vec.begin(), vec.end(), target);

    // Handle edge cases
    if (it == vec.begin()) return *it;           // If target is smaller than all elements
    if (it == vec.end()) return *(it - 1);       // If target is larger than all elements
    
    int higher = *it;        // Closest >= target
    int lower = *(it - 1);   // Closest < target
    
    // Return the closest one
    return (abs(higher - target) < abs(lower - target)) ? higher : lower;
}



ll mloga(ll a, ll b)
{
    ll ans = 0;
    while (a > b-1) {
        a /= b;
        ans++;
    }
return ans;
}

llv prime;
set<ll> ext;
ll done=0;
void prm() {
    ll limit=100005;
    std::vector<bool> is_prime(limit + 1, true);
    
    
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime

    for (int num = 2; num <= limit; ++num) {
        if (is_prime[num]) {
            prime.push_back(num);
            //ext.insert(num);
            for (int multiple = num * 2; multiple <= limit; multiple += num) {
                is_prime[multiple] = false;
            }
        }
    }

    
}




void solve(){

    ll n,q;
    cin>>n>>q;
    llv arr(n),freq(2e5+5),mult(2e5+5);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]]++;
    }
    for(int i=2;i<=2e5;i++){
        for(int j=i;j<=2e5;j+=i){
            mult[i]+=freq[j];
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll ans=mult[x]+mult[y];
        ll lc=x*y;
        lc/=__gcd(x,y);
        if(lc<=2e5){
            ans-=mult[lc];
        }
        cout<<ans<<endl;
    }


}







int main(){
    //EDA_PARI_NA_BHAI
    
   ll t=1;
   
  cin>>t;
   int test=1;
   
   while(t--){
    //cout<<"Case "<<test++<<": ";
    solve();
    
   }

}