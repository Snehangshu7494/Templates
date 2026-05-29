
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

ll cost[200005];
ll jump(llv&arr, ll p,ll k){
    if(p==1){return cost[p]=0;}
    //if(p==2){return cost[p]=abs(arr[1]-arr[2]);}
    if(cost[p]!=-1){return cost[p];}
    ll ans=INF;
    for(int i=1;i<=k;i++){
        if(p-i>=1){
            ll ans1=jump(arr,p-i,k)+abs(arr[p]-arr[p-i]);
            ans=min(ans,ans1);
        }
    }
    //ll ans1=jump(arr,p-1)+abs(arr[p]-arr[p-1]);
    //ll ans2=jump(arr,p-2)+abs(arr[p]-arr[p-2]);
    return cost[p]=ans;
}

void solve() {
    ll n,k;
    cin>>n>>k;
    llv arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    memset(cost,-1,sizeof(cost));
    jump(arr,n,k);
    cout<<cost[n]<<endl;


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