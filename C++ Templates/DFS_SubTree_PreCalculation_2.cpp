//https://codeforces.com/problemset/problem/2114/E

#include<bits/stdc++.h>
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


const ll N=2e5+10;
//Time complexity O(V+E)
llv graph[N];

void DFS(ll par,ll vertex,llv &maxsum,llv &minsum,llv& value){

    //take action on vertex after entering it
    //if(visited[vertex]){return;} 
    //this line can be written if not used in the loop

    
    ll sum=value[vertex];
    maxsum[vertex]=max(sum,sum-minsum[par]);
    minsum[vertex]=min(sum,sum-maxsum[par]);
    for(auto child:graph[vertex]){

        //take action on child before entering it
        if(child==par){continue;}
        DFS(vertex,child,maxsum,minsum,value);
        //take action on child after exiting it


        

    }

    //take action on vertex before exiting it

}
void solve(){

    ll n;
    cin>>n;
    llv minsum(n+1),maxsum(n+1),value(n+1),ac(n+1);
    for(int i=1;i<=n;i++){cin>>value[i];}
    for(int i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        if(!ac[x]){
            ac[x]++;
            graph[x].clear();

        }
        if(!ac[y]){
            ac[y]++;
            graph[y].clear();

        }
        graph[x].pb(y);
        graph[y].pb(x);

    }

    DFS(0,1,maxsum,minsum,value);
    for(int i=1;i<=n;i++){cout<<maxsum[i]<<spc;}cout<<endl;





}

int main(){
    //EDA_PARI_NA_BHAI
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
