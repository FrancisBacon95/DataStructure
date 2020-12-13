#include <stdio.h>
#include <iostream>
using namespace std;
int n;
int target[5];

int main(){
    cin >> n;
    int base[n][2];
    for(auto b:base) cin>>b[0]>>b[1];
    for(int i=0;i<5;i++) cin >> target[i];

    for(auto t:target){
        int now[2];
        now[0]=base[0][0];
        now[1]=base[0][1];
        int idx=1;
        int next[2];
        next[0]=base[idx][0];
        next[1]=base[idx][1];
        for(int i=0;i<t;i++){
            if (now[0]==next[0] && now[1]==next[1]){
                if (idx==n-1)
                    idx=0;
                else
                    idx+=1;
                next[0]=base[idx][0];
                next[1]=base[idx][1];
            }

            int road[2];
            road[0]=next[0]-now[0];
            road[1]=next[1]-now[1];
            if (road[0]!=0){
                if (road[0]>0)
                    now[0]+=1;
                else
                    now[0]-=1;

            }else{
                if (road[1]>0)
                    now[1]+=1;
                else
                    now[1]-=1;
            }
        }
        cout<< now[0]<<" "<<now[1]<<endl;
    }
}
