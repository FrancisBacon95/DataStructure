#include <iostream>
#include <vector>
#include<algorithm>
#define for_inc(i,s,e) for(int i=s; i<e; i++)
#define for_dec(i,s,e) for(int i=s; i>e; i--)
using namespace std;

int N;
vector<vector<int>> output;
void input(){
    for_inc(i,0,N){
        int len;
        cin >> len;
        vector<int> line;
        for_inc(j,0,len){
            int tmp;
            cin >> tmp;
            line.push_back(tmp);
        }
        output.push_back(line);
    }
}

void change(){
    while (1){
        int max_site = 0, min_site=0;
        for_inc(i,0,N){
            if (output[min_site].size() > output[i].size()) min_site = i;

            if (output[max_site].size() <= output[i].size()) {
                if (output[max_site].size() == output[i].size() && output[i].size()!=0){
                    if (output[max_site].back() > output[i].back()) continue;
                }
                max_site = i;
            }
        }
        if (output[max_site].size() - output[min_site].size() <= 1) break;
        output[min_site].push_back(output[max_site].back());
        output[max_site].pop_back();
    }
}

void print(){
    for_inc(i,0,N){
        cout<< i+1 << " > ";
        for_inc(j,0,output[i].size()) cout<< output[i][j] <<" ";
        cout<<endl;
    }
}

int main(){
    cin >> N;
    input();
    change();
    print();
    return 0;
}
