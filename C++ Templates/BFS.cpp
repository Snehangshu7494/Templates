#include<bits/stdc++.h>
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
#define vpll vector<pair<ll,ll>>
#define valset(arr,val) memset(arr,val,sizeof(arr));
/*
13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11

*/
//const ll N=1e5+10;
//Time complexity O(V+E)

void BFS(llv graph[],ll vertex,llv& visited,llv& level){
    queue<ll>Q;
    Q.push(vertex);
    visited[vertex]++;
    while(!Q.empty()){
        ll curr_v=Q.front();
        Q.pop();
        for(auto child:graph[curr_v]){

            if(visited[child]){continue;}
            Q.push(child);
            visited[child]++;
            level[child]=level[curr_v]+1;
        }
    }
}




void solve(){
    ll n,m;
    cin>>n;
    m=n-1;
    llv graph1[n+5];

    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        graph1[x].pb(y);// use vpll if there is weight
        graph1[y].pb(x);


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