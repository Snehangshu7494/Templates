//https://codeforces.com/problemset/problem/189/A
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
#define bitcnt(x) __builtin_popcountll(x)
#define Check "Check "
#define vpll vector<pair<ll,ll>>

ll rib[4005];
ll cut(ll n,llv &a){
    if(n<0){return NINF;}
    if(n==0){return 0;}
    if(rib[n]!=-1){return rib[n];}
    ll ans=NINF;
    for(auto len:a){
        ll ans1=cut(n-len,a)+1;
        ans=max(ans,ans1);
    }
    return rib[n]=ans;
}



void solve() {
    memset(rib,-1,sizeof(rib));
    ll n;
    cin>>n;
    ll a,b,c;
    cin>>a>>b>>c;
    llv arr={a,b,c};
    cout<<cut(n,arr)<<endl;
}







int main(){
    EDA_PARI_NA_BHAI
    
   ll t=1;
   
    //cin>>t;
   int test=1;
   
   while(t--){
    //cout<<"Case "<<test++<<": ";
    solve();
    
   }

}