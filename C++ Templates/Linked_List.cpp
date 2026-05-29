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

class Node{
    public:
    ll data;
    Node* next;

    Node(ll val){
        data=val;
        next=NULL;
    }
};

class List{
    Node* head;
    Node* tail;
    public:
    List(){
        head=tail=NULL;
    }
    void push_front(ll val){
        Node* NewNode=new Node(val);
        if(head==NULL){
            head=tail=NewNode;
            return;
        }
        else{
            NewNode->next=head;
            head=NewNode;
        }
    }
    void push_back(ll val){
        Node* NewNode=new Node(val);
        if(head==NULL){
            head=tail=NewNode;
            return;
        }
        else{
            tail->next=NewNode;
            tail=NewNode;
        }
    }
    void pop_front(){
        if(head==NULL){return;}
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void pop_back(){
        if(head==NULL){return;}
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        Node* Mara=tail;
        tail=temp;
        tail->next=NULL;
        delete Mara;
    }
    void Printll(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<spc;
            temp=temp->next;
        }
    }
};


void solve(){

    List list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);
    list.pop_front();
    list.pop_back();
    list.Printll();




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