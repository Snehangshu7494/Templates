//Question Link:
//Three Musketeers
//https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/

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

bool isVowel(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

vector<string>subsets;
void Subset_Gen(string& subset,ll i,string s){
    
    if(i==s.size()){
        subsets.pb(subset);
        return;
    }
    // i not in subset
    Subset_Gen(subset,i+1,s);

    // i in subset
    subset.pb(s[i]);
    Subset_Gen(subset,i+1,s);
    subset.pop_back();
}

void solve(){
    ll n;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    map<string,ll>mp;
    //calculate all possible vowel combinations
    for(auto x:s){
        //each vowel counted once
        set<char>vowels;
        for(auto c:x){
            if(isVowel(c)){
                vowels.insert(c);
            }
        }
        string vstr;
        for(auto z:vowels){
            vstr.pb(z);
        }
        //Get all possible combination by generating subsets
        subsets.clear();
        string ss;
        Subset_Gen(ss,0,vstr);
        for(auto el:subsets){
            if(el.size())mp[el]++;
        }

    }
    ll ans=0;
    for(auto &x:mp){
        //cout<<x.F<<spc<<x.S<<endl;
        if(x.S>=3){
            ll ct=x.S;
            ll ways=(ct*(ct-1)*(ct-2))/6;//nc3=n(n-1)(n-2)/3!
            if(x.F.size()){ans+=ways;}
            else{ans-=ways;}
        }
    }
    cout<<ans<<endl;
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