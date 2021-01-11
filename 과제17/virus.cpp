#include <bits/stdc++.h>
#define for_inc(i,s,e) for(int i=s; i<e; i++)
using namespace std;
map<int,char> in;
vector<vector<int>> grid;
int N,M,k;
int maxi=0, cnt=0, tmp_m=0;
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};

void input(){
   cin>>N>>M>>k;
   for_inc(i,0,M){
      vector<int> row;
      for_inc(j,0,N){
         char elem; int tmp=0; char* str = "#";
         cin>>elem;
         if (*str==elem) tmp=1;
         row.push_back(tmp);
      }
      grid.push_back(row);
   }
}

void dfs(int y, int x){
   if (grid[y][x]!=1) return;
   tmp_m++;
   grid[y][x]=8;
   for_inc(i,0,4){
      int ny=y+dy[i], nx=x+dx[i];
      if (0<=ny && ny<M && 0<=nx && nx<N) dfs(ny,nx);
   }
}

int main(){
   input();
   for_inc(y,0,M){
      for_inc(x,0,N){
         tmp_m=0;
         dfs(y, x);
         if (tmp_m>=k){
            cnt++;
            if(tmp_m>maxi) maxi=tmp_m;
         }
      }
   }
   cout<<cnt<<" "<<maxi;
}
