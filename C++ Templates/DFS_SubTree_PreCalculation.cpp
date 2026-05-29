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
    Given Q queries (Q<=1e5)
    In each query given V, 
    Print subtree sum of V and
    Number of even numbers in subtree of V
*/
const ll N=1e5+10;
//Time complexity O(V+E)
llv graph[N];
llv subtree_sum(N);
llv even(N);
void DFS(llv& visited,ll vertex){

    //take action on vertex after entering it
    //if(visited[vertex]){return;} 
    //this line can be written if not used in the loop

    visited[vertex]++;
    subtree_sum[vertex]+=vertex;
    if(vertex%2==0){
        even[vertex]++;
    }
    for(auto child:graph[vertex]){

        //take action on child before entering it
        if(visited[child]){continue;}
        DFS(visited,child);
        //take action on child after exiting it
        subtree_sum[vertex]+=subtree_sum[child];
        even[vertex]+=even[child];

        

    }

    //take action on vertex before exiting it

}


void solve(){
    ll n,m;
    cin>>n>>m;
    //llv graph1[n+5];
    llv visited(n+5);
    //ll graph2[n][n];
    //valset(graph2,0);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        graph[x].pb(y);// use vpll if there is weight
        graph[y].pb(x);
        //graph2[x][y]=1;//=w if there is weight
        //graph2[y][x]=1;


    }
    DFS(visited,1);
    for(int i=1;i<=n;i++){cout<<subtree_sum[i]<<spc;}cout<<endl;
    for(int i=1;i<=n;i++){cout<<even[i]<<spc;}cout<<endl;
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