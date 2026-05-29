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
7 7
1 2
3 2
3 4
7 4
6 2
5 6
7 5
7

answer=2

*/
//const ll N=1e5+10;
//Time complexity O(V+E)
/*
    you are given a directed graph
    how many edges needed to be reversed to reach a certain vertex
*/
void BFS(vector<vpll>& graph,ll vertex,llv& level){
    deque<ll>Q;
    Q.push_back(vertex);
    level[vertex]=0;
    while(!Q.empty()){
        ll curr_v=Q.front();
        Q.pop_back();
        for(auto child:graph[curr_v]){
            ll cv=child.F;
            ll wt=child.S;
            //if(visited[child]){continue;}
            if(level[curr_v]+wt<level[cv]){
                level[cv]=level[curr_v]+wt;
                if(wt==0){
                    Q.push_front(cv);
                }
                else{
                    Q.push_back(cv);
                }
            }
        }
    }
}




void solve(){
    ll n,m;
    cin>>n>>m;
    //m=n-1; // For trees
    vector<vpll> graph(n+5);

    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        if(x==y){continue;}//avoid self connection
        graph[x].pb({y,0});// use vpll if there is weight
        graph[y].pb({x,1});


    }
    ll end;
    cin>>end;
    llv level(n+5,INF);
    BFS(graph,1,level);
    cout<<(level[end]==INF?-1:level[end])<<endl;




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