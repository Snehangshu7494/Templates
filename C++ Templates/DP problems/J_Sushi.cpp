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
ll n;
lf dp[302][302][302];
lf fun(ll o,ll t,ll th){
    if(o+t+th==1 && o==1){return n;}
    if(o<0 || t<0 || th<0){return 0;}
    
    if(dp[o][t][th]!=-1){return dp[o][t][th];}
    // lf pro1=o*1.0/n*1.0;
    // pro1*=fun(o-1,t,th);
    // lf pro2=t*1.0/n*1.0;
    // pro2*=fun(o+1,t-1,th);
    // lf pro3=th*1.0/n*1.0;
    // pro3*=fun(o,t+1,th-1);
    lf ans=n/((o+t+th)*1.0);
    ll k=(o+t+th);
    ans+=fun(o-1,t,th)*(o*1.0/k*1.0)+fun(o+1,t-1,th)*(t*1.0/k*1.0)+fun(o,t+1,th-1)*(th*1.0/k*1.0);
    return dp[o][t][th]=ans;
}


void solve() {
    cin>>n;
    ll o=0,t=0,th=0;
    for(int i=0;i<302;i++){
        for(int j=0;j<302;j++){
            for(int k=0;k<302;k++){
                dp[i][j][k]=-1;
            }
        }
    }
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x==1){o++;}
        if(x==2){t++;}
        if(x==3){th++;}
    }
    cout<<pdis(9)<<fun(o,t,th)<<endl;





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
