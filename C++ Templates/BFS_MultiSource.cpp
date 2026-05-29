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
ll visited[505][505];
ll level[505][505];
void BFS(vector<llv>& graph,queue<pair<ll,ll>>&Q){
    while(!Q.empty()){
        ll curr_vx=Q.front().F;
        ll curr_vy=Q.front().S;
        Q.pop();
        vpll children={
            {curr_vx+1,curr_vy},{curr_vx-1,curr_vy},
            {curr_vx,curr_vy+1},{curr_vx,curr_vy-1},
            {curr_vx+1,curr_vy+1},{curr_vx+1,curr_vy-1},
            {curr_vx-1,curr_vy+1},{curr_vx-1,curr_vy-1}

        };
        for(auto child:children){
            if(child.F<0 || child.F>graph.size()-1 ||child.S<0 || child.S>graph[0].size()-1)
            {continue;}
            if(visited[child.F][child.S]){continue;}//only 2 levels can stay in the queue at the same time
            Q.push({child.F,child.S});
            visited[child.F][child.S]++;
            level[child.F][child.S]=level[curr_vx][curr_vy]+1;
        }
    }
}




void solve(){
    valset(visited,0);
    valset(level,0);
    ll n,m;
    cin>>n>>m;
    vector<llv>vec(n);
    ll maxi=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll x;
            cin>>x;
            maxi=max(x,maxi);
            vec[i].pb(x);
        }
    }
    queue<pair<ll,ll>>q;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j]==maxi){
                q.push({i,j});//putting in all the sources at once
                visited[i][j]++;
            }
        }
    }
    BFS(vec,q);
    ll tt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tt=max(tt,level[i][j]);
        }
    }
    cout<<tt<<endl;




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