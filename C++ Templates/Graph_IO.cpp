#include<bits/stdc++.h>
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
#define vpll vector<pair<ll,ll>>
#define valset(arr,val) memset(arr,val,sizeof(arr));

void solve(){
    ll n,m;
    cin>>n>>m;
    llv graph1[n];
    ll graph2[n][n];
    valset(graph2,0);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        graph1[x].pb(y);// use vpll if there is weight
        graph1[y].pb(x);
        graph2[x][y]=1;//=w if there is weight
        graph2[y][x]=1;


    }
}




int main(){
    //EDA_PARI_NA_BHAI
    
   ll t=1;
   
  //cin>>t;
   int test=1;
   
   while(t--){
    //cout<<"Case "<<test++<<": ";
    solve();
    
   }

}