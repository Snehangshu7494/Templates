//https://leetcode.com/problems/coin-change/description/
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

ll cons[200005];
    
ll coin(ll num,vector<int>& arr) {
    if(num==0){return cons[num]= 0;}
    if(num<0){return INF;}
    if(cons[num]!=-1){return cons[num];}
    ll ans=INF;
    for(auto x:arr){
        ll ans1=coin(num-x,arr)+1;
        ans=min(ans,ans1);
    }
    return cons[num]=ans;
}
int coinChange(vector<int>& coins, int amount) {
    memset(cons,-1,sizeof(cons));
    coin(amount,coins);
    return cons[amount]>=INF?-1: cons[amount]; 
}

void solve() {
    vector<int> coins={1,2,5};
    int amount =11;
    cout<<coinChange(coins, amount)<<endl;

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