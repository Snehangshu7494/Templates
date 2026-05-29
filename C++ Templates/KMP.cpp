//https://codeforces.com/contest/329/problem/B

#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define EDA_PARI_NA_BHAI { ios_base::sync_with_stdio(false); cin.tie(0); }
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
ll ans=0;
const ll N=100000;
ll failure[N];
// 1 based indexing
void failure_table(string pattern){
    ll m=pattern.size();
    failure[0]=0;
    failure[1]=0;//base case
    /*
    i is the length of prefix we are dealing with
    j is the index of largest partial match (the largest prefix/suffix)
    of the string under i-1
    */

    for(int i=2;i<=m;i++){
        int j=failure[i-1];
        while(true){
            /*
            check if the last character of prefix of length i "expands"
            the current cadidate
            */
            if(pattern[j]==pattern[i-1]){
                failure[i]=j+1;
                break;
            }
            // we cant expand even the empty string
            if(j==0){
                failure[i]=0;
                break;
            }
            //go to the next best partial match
            j=failure[j];
        }
    }
}

ll KMP(string text,string pattern){
    ll n=text.size();
    ll m=pattern.size();

    int i=0;//first caharcter of pattern
    int j=0;//first character of text
    ll match=0;
    while(true){
        if(j==n){
            return match;//reached end of text
        }
        //caharcter matched
        if(text[j]==pattern[i]){
            i++;
            j++;
            if(i==m){
                match++; //WE FOUND A COMPLETE MATCH
            }
        }
        else{
            if(i==0){
                /*
                we reached an empty string and failed to "expand" even it
                we go to the next character of text
                the state of matching remains 0
                */
               j++;
            }
            else{
                // we try to go to the next best(largest match)
                i=failure[i];
            }
        }
    }
    return match;

}


void solve(){

    string text="ABABAC";
    string pat="AB";
    //Do editing on line 77 based of what you need
    //Thats the part where the string completely matches
    cout<<KMP(text,pat)<<endl;

}

int main(){
    //EDA_PARI_NA_BHAI
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}