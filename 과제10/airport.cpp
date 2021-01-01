#include <iostream>
#include <array>
#include <deque>
#include <vector>
#include<algorithm>
#define for_inc(i,s,e) for(int i=s; i<e; i++)
#define for_dec(i,s,e) for(int i=s; i>e; i--)
using namespace std;
int k;
vector<deque<int>> result;

void input(int i){
    deque<int> line;
    while(1){
        int num;
        cin >> num;
        if(num==0) break;
        line.push_back(num);
    }
    if (!line.empty()) result.push_back(line);
}

bool compare(array<int,2> a, array<int, 2> b){
    if (a[0]!=b[0]) return a[0]<b[0];
    else return a[1]<b[1];
}

void output(){
    while(!result.empty()){
        array<int,2> cand={10001,0};
        for_inc(i,0,result.size()) {
            if (result[i].front() <= cand[0]){
                if (result[i].front() == cand[0] && i > cand[1]) continue;
                cand={result[i].front(),i};
            }
        }
        cout<<cand[0]<<endl;
        result[cand[1]].pop_front();
        if (result[cand[1]].empty()) result.erase(result.begin()+cand[1]);
    }
}

int main(){
    cin >> k;
    for_inc(i,0,k) input(i);
    output();
    return 0;
}
