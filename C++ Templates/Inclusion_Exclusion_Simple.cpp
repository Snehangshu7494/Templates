
#include<bits/stdc++.h>
//#include<conio.h>
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
#define bitcnter(x) __builtin_popcountll(x)
#define Check "Check "
#define vpll vector<pair<ll,ll>>

llv prm={2,3,5,7};
ll gc(ll x) {
    ll n=4;
    ll bad=0;
    for (ll mask=1;mask<(1<<n);mask++) {
        ll lcm=1;
        int bit=0;
        for (int i=0; i<n; i++) {
            if (mask&(1<<i)) {
                lcm=lcm*prm[i]/__gcd(lcm,1LL*prm[i]);
                bit++;
            }
        }
        ll con=x/lcm;
        if(bit%2==1){
            bad+=con;
        }
        else{
            bad-=con;
        }
    }
    return x-bad;
}

void solve(){
    ll l,r;
    cin>>l>>r;
    cout<<gc(r)-gc(l-1)<<endl;
}
    







int main(){
    EDA_PARI_NA_BHAI
    
   ll t=1;
   
    cin>>t;
   int test=1;
   
   while(t--){
    //cout<<"Case "<<test++<<": ";
    solve();
    
   }

}