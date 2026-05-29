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
#define bitcnt(x) __builtin_popcountll(x)
#define Check "Check "
#define trav(m,a) for(auto m:a){cout<<m<<" ";}cout<<"\n";
#define travP(m,a) for(auto m:a){cout<<m.first<<" "<<m.second<<"\n";}cout<<"\n";
#define vpll vector<pair<ll,ll>>

ll inv=0;
void Merge(llv&arr,ll st,ll mid,ll ed){
    llv temp;
    ll p1=st,p2=mid+1;
    while(p1<=mid && p2<=ed){
        if(arr[p1]<=arr[p2]){
            temp.pb(arr[p1]);
            p1++;
        }
        else{
            temp.pb(arr[p2]);
            inv+=mid-p1+1;
            p2++;
        }
    }
    while(p1<=mid){
        temp.pb(arr[p1]);
        p1++;       
    }
    while(p2<=ed){
        temp.pb(arr[p2]);
        //inv+=mid-p1+1;
        p2++;        
    }
    for(int i=0;i<temp.size();i++){
        arr[i+st]=temp[i];
    }
}


void Merge_Sort(llv&arr,ll st,ll ed){
    if(st<ed){
        ll mid=(st+ed)/2;
        Merge_Sort(arr,st,mid);//left side
        Merge_Sort(arr,mid+1,ed);//right side
        Merge(arr,st,mid,ed);
    }
}

void solve(){
    ll n;
    cin>>n;
    llv arr(n);
    inv=0;
    for(int i=0;i<n;i++){cin>>arr[i];}
    Merge_Sort(arr,0,n-1);
    cout<<inv<<endl;
}









int main(){
    EDA_PARI_NA_BHAI

   ll t=1;

    cin>>t;
   int test=1;

   while(t--){
    //cout<<"Case "<<test++<<": ";
    solve();

   }

}
