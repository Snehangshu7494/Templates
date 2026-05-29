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
const ll N=1005,M=1005;
const ll MOD=1e9+7;
ll n,m;
char grid[N][M];
ll dp[N][M];
ll fun(ll x,ll y){
    if(x<1 || y<1 || x>n || y>m){return 0;}
    if(grid[x][y]=='#'){return 0;}
    if(dp[x][y]!=-1){return dp[x][y];}
    if(x==1 && y==1){return 1;}
    dp[x][y]=(fun(x-1,y)+fun(x,y-1))%MOD;
    //cout<<dp[x][y]<<spc<<x<<spc<<y<<endl;
    return dp[x][y];
}

void solve() {

    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<fun(n,m)<<endl;

    




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
