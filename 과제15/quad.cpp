#include <bits/stdc++.h>
using namespace std;
int K;
int arr[64][64];
map<string,int> cmd;
vector<string> type = {"QTS","IMG"};
void set_cmd(){for(int i=0;i<type.size();i++) cmd[type[i]]=i;}
class Node{
public:
   vector<Node*> child;
   int value;
   Node(){
      int value=-1;
      vector<Node*> child;
   }
   Node(int v):value(v){}
   ~Node();
   void push_child(Node* n){child.push_back(n);}
};
vector<Node*> result;
void to_IMG(Node* root, int N, int x, int y){
   vector<Node*> children=root->child;
   if (children.size()==0){
      for(int i=y; i<y+N; i++){
         for(int j=x; j<x+N; j++) arr[i][j]=root->value;
      }
   }else{
      int dx[]={N/2,0,0,N/2};
      int dy[]={0,0,N/2,N/2};
      for(int i=0; i<4;i++) to_IMG(children[i],N/2,x+dx[i],y+dy[i]);
   }
   return;
}

void to_QTS(int N, int r, int c){
   if(N==1){
      cout<<arr[r][c];
      return;
   }

   bool all_0=true, all_1=true;
   for (int i = r; i<r+N; i++){
      for(int j = c; j<c+N; j++){
         if(arr[i][j]) all_0=false;
         else all_1=false;
      }
   }
   if (all_0) cout<<0;
   else if (all_1) cout<<1;
   else{
      cout<<"(";
      to_QTS(N/2,r,c+N/2);
      to_QTS(N/2,r,c);
      to_QTS(N/2,r+N/2,c);
      to_QTS(N/2,r+N/2,c+N/2);
      cout<<")";
   }
   return;
}

int main(){
   set_cmd();
   string sel;
   cin >> K;
   cin >> sel;
   string tmp;
   int N=(int)pow(2,K);
   switch(cmd[sel]){
   case 0:{
         cin >> tmp;
         deque<char> line(tmp.begin(),tmp.end());
         if(line.size()==1){
            for(int i=0;i<N;i++){for(int j=0;j<N;j++) cout<<line.front();cout<<endl;}
            break;
         }
         stack<Node*> Stack;
         Node* root= new Node();
         Stack.push(root);
         const char* chck[]={"(",")"};
         line.pop_front();
         while(line.size()){
            if(line.front()==*chck[0]){
               Node* tmp_N=new Node();
               Stack.push(tmp_N);
            }else if(line.front()==*chck[1]){
               Node* tmp_N= Stack.top();
               Stack.pop();
               if (Stack.size()==0) root=tmp_N;
               else Stack.top()->push_child(tmp_N);
            }else{
               Node* tmp_N=new Node((int)(line.front()-'0'));
               if (Stack.size()==0) root=tmp_N;
               else Stack.top()->push_child(tmp_N);
            }
            line.pop_front();
         }
         to_IMG(root, N, 0, 0);
         for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
               if (arr[i][j]!=-1)cout<<arr[i][j];
            }
            cout<<endl;
         }
         break;
      }
   case 1:
      for (int r=0; r<N; r++){
         cin >> tmp;
         char line[tmp.length()+1];
         strcpy(line,tmp.c_str());
         for (int c=0; c<N; c++){
               arr[r][c]=(int)(line[c]-'0');
         }
      }
      to_QTS(N,0,0);
      break;
  }
}
