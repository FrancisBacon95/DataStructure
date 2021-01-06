#include <bits/stdc++.h>
#define NP nullptr
using namespace std;
int K;
map<string,int> cmd;
vector<string> type={"+","-","depth","leaf"};
void set_cmd(){for(int i=0;i<type.size();i++)cmd[type[i]]=i;}
struct N{
    N* L;N* R;string d;
};
class BST{
public:
    N* RT;
    BST():RT(NP){};
    ~BST(){};
    void Add(string v){
        N* n=new N();
        N* tmpRoot=NP;
        n->d=v;
        if(RT==NP)RT=n;
        else{
            N* ptr=RT;
            while(ptr!=NP){
                tmpRoot=ptr;
                if(n->d<ptr->d)ptr=ptr->L;
                else ptr=ptr->R;
            }
            if(tmpRoot->d<n->d)tmpRoot->R=n;
            else tmpRoot->L=n;
        }
    }
    N* MaxN(N* n){
        if(n==NP)return NP;
        while(n->R!=NP)n=n->R;
        return n;
    }
    N* DelSeq(N* n, string v){
        if(n==NP)return n;
        else if(n->d>v)n->L=DelSeq(n->L,v);
        else if(n->d<v)n->R=DelSeq(n->R,v);
        else{
            N* ptr=new N();
            if (n->R==NP&&n->L==NP){
                n=NP;
            }else if (n->R==NP){
                n=n->L;
                delete ptr;
            }else if (n->L==NP){
                n=n->R;
                delete ptr;
            }else{
                ptr=MaxN(n->L);
                n->d=ptr->d;
                n->L=DelSeq(n->L, ptr->d);
            }
        }
        return n;
    }
    void DelN(string v){
        N* ptr=RT;
        DelSeq(ptr,v);
    }
    void Dpth(int lv){
        if(RT==NP)return;
        queue<N*> q;
        vector<string> v;/////////////////
        q.push(RT);
        int LV=0,flag=0;
        while(!q.empty()){
            int SIZE=q.size();
            while(SIZE--){
                N* ptr=q.front();
                q.pop();
                if(LV==lv){
                    flag=1;
                    //cout<<ptr->d<<" ";
                    v.push_back(ptr->d);//////////////////////
                }else{
                    if(ptr->L)q.push(ptr->L);
                    if(ptr->R)q.push(ptr->R);
                }
            }
            LV++;
            if(flag==1)break;
        }
        //if(LV<=lv)cout<<"NO";
        if(v.size()) for(auto x:v)cout<<x<<" ";//////////////////
        else cout<<"NO";//////////////////

        return;
    }
    void Leaf(N* n){
        if(n==NP)return;
        if(n->L==NP&&n->R==NP){
            cout<<n->d<<" ";
            return;
        }
        if(n->L!=NP )Leaf(n->L);
        if(n->R!=NP)Leaf(n->R);
    }
    void LeafN(){
        N* ptr=RT;
        Leaf(ptr);
    }
};
int main(){
    set_cmd();BST bst=BST();cin>>K;
    for (int i=0;i<K;i++){
        string tmp,str;
        cin>>tmp;
        switch(cmd[tmp]){
        case 0:
            cin>>str;
            bst.Add(str);
            break;
        case 1:
            cin>>str;
            bst.DelN(str);
            break;
        case 2:
            cin>>str;
            bst.Dpth(stoi(str)-1);
            cout<<endl;
            break;
        case 3:
            bst.LeafN();
            cout<<endl;
            break;
        }
    }
}
