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
lf dp[3005][3005];
lf arr[3005];
lf fun(ll n,ll h){
    if(n<1){return 0;}
    ll t=n-h;
    lf ph=arr[n];
    lf pt=1-arr[n];
    if(h<0){return 0;}
    if(n<h){return 0;}
    if(dp[n][h]!=(lf)-1){return dp[n][h];}
    if(n==1){
        if(h==0){return pt;}
        else{
            return ph;
        }
    }

    lf ans=fun(n-1,h)*pt+fun(n-1,h-1)*ph;
    return dp[n][h]=ans;
}


void solve() {
    
    ll n;
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n;i++){
        lf x=fun(n,i);
    }
    lf ans=0;
    for(int i=(n+1)/2;i<=n;i++){
        ans+=fun(n,i);
    }
    cout<<pdis(9)<<ans<<endl;





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
