//https://codeforces.com/problemset/problem/1178/B
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
#define bitcnter(x) __builtin_popcountll(x)
#define Check "Check "
#define vpll vector<pair<ll,ll>>
ll f=0;
map<ll,ll>parent;
void DFS(ll a,ll b,ll par ){
    parent[a]=par;
    if(a==b){f=1;return;}
    if(a>b){return;}
    if(f){return;}
    if(!parent[2*a]){DFS(2*a,b,a);}
    if(!parent[(10*a)+1]){DFS((10*a)+1,b,a);}
}
llv path(ll vertex){
    llv ans;
    while(vertex!=-1){
        ans.pb(vertex);
        vertex=parent[vertex];
    }
    reverse(all(ans));
    return ans;
}
void solve(){

    string s;
    cin>>s;
    string ss;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='v' && s[i+1]=='v'){
            ss.pb('w');
        }
        if(s[i]=='o'){
            ss.pb('o');
        }
    }

    ll n=ss.size();
    ll a = 0, b = 0, c = 0;    
    for (int i = 0; i < n; ++i) {
        if (ss[i] == 'o') {
            b += a;
        }
        else if (ss[i] == 'w') {
            a++;
            c += b;
        }
    }
    cout << c << endl;  




    
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