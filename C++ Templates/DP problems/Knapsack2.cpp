//https://atcoder.jp/contests/dp/tasks/dp_e
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

ll bag[100005][105];
ll knap(ll W,llv&arr,ll idx,llv& val, ll v){
    if(v==0){return 0;}
    if(idx<0){return INF;}
    if(bag[v][idx]!=-1){return bag[v][idx];}
    ll ans1=INF,ans2=INF;
    ans1=knap(W,arr,idx-1,val,v);
    if(v-val[idx]>=0)ans2=knap(W,arr,idx-1,val,v-val[idx])+arr[idx];
    return bag[v][idx]=min(ans1,ans2); 
}

void solve() {
    memset(bag,-1,sizeof(bag));
    ll n,W;
    cin>>n>>W;
    llv arr(n),val(n);
    for(int i=0;i<n;i++){
        cin>>arr[i]>>val[i];
    }
    for(ll i=1e5;i>=0;i--){
        ll w=knap(W,arr,n-1,val,i);
        if(w<=W){cout<<i<<endl;return;}
    }
    
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