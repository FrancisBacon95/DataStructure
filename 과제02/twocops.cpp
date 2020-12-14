#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;
int k;
int t;

int main (){
    cin >> k;
    int base[k][2];
    for(auto b:base) cin>>b[0]>>b[1];
    cin >> t;
    int c1[2]={base[0][0],base[0][1]};
    int start_c1=0; int next_c1=1;
    int c2[2]={base[k/2-1][0],base[k/2-1][1]};
    int start_c2=k/2-1; int next_c2=k/2-2;
    int meet=0;
    bool change=false;

    for(int i=0;i<t;i++){

        if ((abs(c1[0]-c2[0])<=1 && c1[1]==c2[1]) || (abs(c1[1]-c2[1])<=1 && c1[0]==c2[0])){
            if (!change){
                int tmp1=start_c2;
                int tmp2=next_c2;
                start_c2=next_c1;
                next_c2=start_c1;
                start_c1=tmp2;
                next_c1=tmp1;
                meet=meet+1;
                change=true;
                if (abs(c1[0]-c2[0]==0) && c1[1]==c2[1])
                    change=false;
            }
            else{change=false;}
        }

        if (c1[0]==base[next_c1][0] &&c1[1]==base[next_c1][1]){
            if (next_c1==k-1){
                start_c1=k-1;
                next_c1=0;
            }
            else{
                start_c1=next_c1;
                next_c1=next_c1+1;
            }
        }
        if (c2[0]==base[next_c2][0] &&c2[1]==base[next_c2][1]){
            if (next_c2==0){
                start_c2=0;
                next_c2=k-1;
            }
            else{
                start_c2=next_c2;
                next_c2=next_c2-1;
            }
        }
        int road_c1[2]={base[next_c1][0]-c1[0],base[next_c1][1]-c1[1]};
        int road_c2[2]={base[next_c2][0]-c2[0],base[next_c2][1]-c2[1]};


        if (road_c1[0]==0){
            if (road_c1[1]>0){
                c1[1]=c1[1]+1;

            }else{
                c1[1]=c1[1]-1;
            }
        }else{
             if (road_c1[0]>0){
                c1[0]=c1[0]+1;

            }else{
                c1[0]=c1[0]-1;
            }
        }

        if (road_c2[0]==0){
            if (road_c2[1]>0){
                c2[1]=c2[1]+1;

            }else{
                c2[1]=c2[1]-1;
            }
        }else{
             if (road_c2[0]>0){
                c2[0]=c2[0]+1;

            }else{
                c2[0]=c2[0]-1;
            }
        }
    }

    if (meet%2==0){
        cout<<c1[0]<<" "<<c1[1]<<endl<<c2[0]<<" "<<c2[1]<<endl;
    }else{
        cout<<c2[0]<<" "<<c2[1]<<endl<<c1[0]<<" "<<c1[1]<<endl;
    }
}
