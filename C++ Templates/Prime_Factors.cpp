#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<vector>
#include<climits>
#include<queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
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
#define Check "Check "
#define vpll vector<pair<ll,ll>>

llv Prime_Factor(ll n){
    llv fact;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            fact.pb(i);
            n/=i;
        }
    }
    if(n>1){fact.pb(n);}
    return fact;
}


void solve(){
    llv arr=Prime_Factor(24);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<spc;
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