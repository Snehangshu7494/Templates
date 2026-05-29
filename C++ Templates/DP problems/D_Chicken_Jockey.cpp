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
#define trav(m,a) for(auto m:a){cout<<m<<" ";}cout<<"\n";
#define travP(m,a) for(auto m:a){cout<<m.first<<" "<<m.second<<"\n";}cout<<"\n";
#define vpll vector<pair<ll,ll>>

ll dp[200005];
ll fun(ll id,llv &arr){
    if(id<0){return 0;}
    if(dp[id]!=-1){return dp[id];}
    if(id==0){return arr[id];}
    ll ans1=fun(id-1,arr)+arr[id]-1;
    ll ans2=fun(id-2,arr)+max(0LL,arr[id]-id)+arr[id-1];
    dp[id]=min(ans1,ans2);
    //cout<<arr[id]<<spc<<id<<spc<<dp[id]<<spc<<ans2<<endl;
    return dp[id]=min(ans1,ans2);
    
}


void solve() {
    memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n;
    llv arr(n);
    for(int i=0;i<n;i++){cin>>arr[i];}
    cout<<fun(n-1,arr)<<endl;


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
