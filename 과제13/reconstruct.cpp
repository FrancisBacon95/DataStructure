#include<bits/stdc++.h>
using namespace std;
int postIdx=0;
map<string,int> cmd;
vector<string> type = {"Inorder","Preorder","Postorder"};
void set_cmd(){for(int i=0;i<type.size();i++) cmd[type[i]]=i;}
int search(vector<char> vec,char data,int n,int t){
	int i=0;
	for (i=0;i<n;i++)
		if (vec[i]==data)
			return i;
    if (t==0) return -1;
    else return i;
}

void toPost(vector<char> in,vector<char> pre,int n){
	int root=search(in,pre[0],n,0);
    if (root!=0){
		vector<char> sub_pre1(pre.begin()+1,pre.end());
		toPost(in,sub_pre1,root);
    }
	if (root!=n-1){
        vector<char> sub_in(in.begin()+root+1,in.end());
        vector<char> sub_pre2(pre.begin()+root+1,pre.end());
		toPost(sub_in,sub_pre2,n-root-1);
	}
	cout<<pre[0];
}

void fillPre(vector<char> in,vector<char> post,int inStrt,int inEnd,stack<char> &s,int n){
    if (inStrt>inEnd)
        return;
    int val=post[postIdx];
    int inIdx=search(in,val,n,1);
    postIdx--;
    fillPre(in,post,inIdx+1,inEnd,s,n);
    fillPre(in,post,inStrt,inIdx-1,s,n);
    s.push(val);
}

void toPre(vector<char> in,vector<char> post,int n){
    int len=n;
    postIdx=len-1;
    stack<char> s;
    fillPre(in, post,0,len-1,s,n);
    while (s.size()>0){
        cout<<s.top();
        s.pop();
    }
}

int main(){
    set_cmd();
    pair<int,vector<char>> input[2];
    string tmp1;
    string tmp2;
    int n;
    for(int i=0;i<2;i++){
        cin>>tmp1>>tmp2;
        vector<char> tmp3 = vector<char>(tmp2.begin(), tmp2.end());
        n=tmp3.size();
        if(cmd[tmp1]==0) input[0]=make_pair(cmd[tmp1],tmp3);
        else input[1]=make_pair(cmd[tmp1],tmp3);
    }

    if(input[1].first==1){
        cout<<"Postorder ";
        toPost(input[0].second,input[1].second,n);
    }
    else{
        cout<<"Preorder ";
        toPre(input[0].second,input[1].second,n);
    }
    return 0;
}
