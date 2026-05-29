//https://leetcode.com/problems/island-perimeter/description/

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

//const ll N=1e5+10;
//Time complexity O(V+E)
void DFS(int i,int j,int ini_colour,int colour,vector<vector<int>>& image){
    int n=image.size();
    int m=image[0].size();
    if(i<0||j<0)return;
    if(i>=n||j>=m)return;
    if(image[i][j]!=ini_colour)return;
    image[i][j]=colour;

    DFS(i-1,j,ini_colour,colour,image);
    DFS(i+1,j,ini_colour,colour,image);
    DFS(i,j+1,ini_colour,colour,image);
    DFS(i,j-1,ini_colour,colour,image);


}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color){
            DFS(sr,sc,image[sr][sc],color,image);
        }
        return image;
}

void solve(){
    
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