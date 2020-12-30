#include <iostream>
#include <stack>
#include <array>
#include <deque>
#include<algorithm>
#define for_inc(i,s,e) for(int i=s; i<e; i++)
#define for_dec(i,s,e) for(int i=s; i>e; i--)
using namespace std;
deque<array<int, 3>> tmp_dq;
stack<array<int,3>> STACK;
int N;

bool compare(array<int, 3> a, array<int, 3> b){
    if (a[0]==b[0]) return a[1]<b[1];
    else return a[0]> b[0];
}

int main(){
    cin>> N;
    for_inc(i,0,N){
        int x, y;
        cin>> x>> y;
        array<int,3> p = {x,y,i+1};
        tmp_dq.push_back(p);
    }
    sort(tmp_dq.begin(), tmp_dq.end(), compare);
    STACK.push(tmp_dq.front());
    tmp_dq.pop_front();
    while (!tmp_dq.empty()){
        array<int,3> top = STACK.top();
        array<int,3> tmp = tmp_dq.front();
        tmp_dq.pop_front();
        if ((top[0] < tmp[0] && top[1] < tmp[1])||(top[0] > tmp[0] && top[1] > tmp[1])||(top[0] == tmp[0] && top[1] == tmp[1])){
            STACK.push(tmp);
        }
        if ((top[0] < tmp[0] && top[1] > tmp[1])||(top[0] < tmp[0] && top[1] == tmp[1])||(top[0] == tmp[0] && top[1] > tmp[1])){
            STACK.pop();
            STACK.push(tmp);
        if ((top[0] > tmp[0] && top[1] == tmp[1]) || (top[0] == tmp[0] && top[1] < tmp[1])) continue;
        }
    }
    deque<int> out;
    while (!STACK.empty()){
        out.push_back(STACK.top()[2]);
        STACK.pop();
    }
    sort(out.begin(),out.end());
    while(!out.empty()){
        cout<<out.front()<<endl;
        out.pop_front();
    }
    return 0;
}
