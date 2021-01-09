#include <bits/stdc++.h>
#define for_inc(i,s,e) for(int i=s; i<e; i++)
using namespace std;
int N;
map<int,char> friends;
map<int, char> numbering;
map<char, stack<char>> connect;
map<char, int> visit;
int min_of_all[2]={-1,-1};
void input(){
   cin >> N;
   for_inc(i,0,3){
      char tmp; cin>>tmp;
      friends[i]=tmp;
   }
   for_inc(i,0,N){
      char main; cin >> main;
      stack<char> tmp_v;
      char* chck="$";
      while(true){
         char tmp;cin >> tmp;
         if(tmp == *chck) break;
         else tmp_v.push(tmp);
      }
      numbering[i]=main;
      connect[main]= tmp_v;
      visit[main]=0;
   }
}
void bfs(char strt_n, char end_n, map<char, int> &vst, int t, int &mom){
   if (strt_n == end_n){
      if (mom > t) mom=t;
      if (mom<0) mom=t;
      return;
   }
   if (mom>0 && mom<=t) return;
   if (min_of_all[0]!=-1 && t> min_of_all[0]){
      mom=(N-2)*2+(N-1); return;
   }

   if (t!=0) t=t+2;
   vst[strt_n]=1;

   stack<char> candidates=connect[strt_n];
   while(candidates.size()!=0){
      char next_n=candidates.top();
      candidates.pop();
      if (vst[next_n]==0){
         vst[next_n]=1;
         map<char, int> new_vst;
         new_vst.insert(vst.begin(), vst.end());
         bfs(next_n, end_n, new_vst, t+1, mom);
      }else continue;
   }
}

int main(){
   input();
   for_inc(i,0,N){
      int max_of_target[2]={-1,i};
      for_inc(j,0,3){
         int min_of_man=-1;
         map<char, int> copied_visit;
         copied_visit.insert(visit.begin(), visit.end());
         bfs(friends[j],numbering[i],copied_visit, 0, min_of_man);
         if (max_of_target[0]<min_of_man) max_of_target[0]=min_of_man;
         if(min_of_all[0]!=-1 && max_of_target[0] > min_of_all[0]) break;
      }
      if (max_of_target[0] == min_of_all[0]){
         if (numbering[i] < numbering[min_of_all[1]]) min_of_all[1]=i;
      }
      else if(max_of_target[0] > min_of_all[0]){
         if(min_of_all[0]==-1){
            min_of_all[0]=max_of_target[0];
            min_of_all[1]=i;
         }else continue;
      }
      else {
         min_of_all[0]=max_of_target[0];
         min_of_all[1]=i;
      }
   }
   cout<< numbering[min_of_all[1]]<<endl<<min_of_all[0];
}
