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

void mult(ll k){
    cout<<"mul "<<k<<endl;
    cout.flush();
    ll z;
    cin>>z;
}

void sum(){
    cout<<"digit "<<endl;
    cout.flush();
    ll z;
    cin>>z;
}

void add(ll k){
    cout<<"add "<<k<<endl;
    cout.flush();
    ll z;
    cin>>z;    
}


void solve(){
    ll n;
    cin>>n;
    ll k=999999999;
    mult(k);
    sum();
    if(n!=81)add(n-81);
    cout<<"!"<<endl;
    cout.flush();
    ll z;
    cin>>z;


}







int main(){
    //EDA_PARI_NA_BHAI
    
   ll t=1;
   
  cin>>t;
   int test=1;
   
   while(t--){
    //cout<<"Case "<<test++<<": ";
    solve();
    
   }

}