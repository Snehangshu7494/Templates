//https://www.geeksforgeeks.org/problems/rod-cutting0840/1
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

class Solution {
  public:
    ll mem[1005];
    int maxval(int n,vector<int> &price){
        if(n==0){return 0;}
        if(mem[n]!=-1){return mem[n];}
        ll ans=NINF;
        for(int i=0;i<n;i++){
            ll ans1=NINF;
            if(n-i-1>=0)ans1=maxval(n-i-1,price)+price[i];
            ans=max(ans,ans1);
        }
        return mem[n]=ans;
    }

    int cutRod(vector<int> &price) {
        memset(mem,-1,sizeof(mem));
        int n=price.size();
        return maxval(n,price);
    }
};


void solve() {

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