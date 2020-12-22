#include <iostream>
#include <vector>
using namespace std;
int n;
int k;

int main(){
    cin>>n>>k;
    int seat[n+1]={0,};
    int out[k][3];
    for(int i=0;i<k;i++){
        int idx;
        cin >>idx;
        if (seat[idx]==0){seat[idx]=1;}
        else{
            seat[idx]=0;
            for(int j=0;j<3;j++){out[i][j]=0;}
            continue;
        }


        int tmp[3]={0,};
        tmp[0]=idx;
        ///////////// BEFORE /////////////
        for(int j=idx-1;j>0;j--){
            if(seat[j]==1){
                tmp[1]=j;
                break;
            }
        }
        if (tmp[1]==0){
            for(int j=n;j>=idx;j--){
                if(seat[j]==1){
                    tmp[1]=j;
                    break;
                }
            }
        }
        ///////////// AFTER /////////////
        for(int j=idx+1;j<=n;j++){
            if(seat[j]==1){
                tmp[2]=j;
                break;
            }
        }
        if (tmp[2]==0){
            for(int j=0;j<=idx;j++){
                if(seat[j]==1){
                    tmp[2]=j;
                    break;
                }
            }
        }

        for(int j=0;j<3;j++){
            out[i][j]=tmp[j];
        }
    }
    ///////////// OUTPUT /////////////

    for(int i=0;i<k;i++){
        if(out[i][0]==0){continue;}
        for(int j=0;j<3;j++){
            cout<<out[i][j]<<" ";
        }
        cout<<endl;
    }
}
