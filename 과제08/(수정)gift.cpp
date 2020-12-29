#include <iostream>
#include <vector>
using namespace std;

int n, r, c;
vector<int> coef;
vector<int> var;

void solution() {
    int total=0;
    vector<int> tmp=var;
    for(int i=var.size()-1;i>-1;i--){
        total += tmp[tmp.size()-1]*coef[i];
        tmp.pop_back();
    }
    if(var.size()==n-1) {
        if(!((c-total)%coef[n-1])) {
            r--;
            if(!r) {
                var.push_back((c-total)/coef[n-1]);
                for(int j=0; j<var.size();j++) cout << var[j] << " ";
            }
        }
    }
    else {
        tmp=var;
        int upper=(c-total)/coef[var.size()]+1;
        int next=2;
        if(!((c-total)%coef[var.size()])) upper--;
        while(tmp.size()!=0){
            if(tmp[tmp.size()-1]!=1) {
                next--;
                break;
            }
            tmp.pop_back();
        }
        for(int i=next;i<upper;i++){
            var.push_back(i);
            solution();
            if(!r) break;
            var.pop_back();
        }
    }
}

int main() {
    cin >> n >> r;
    for (int i=0; i < n; i++){
        int tmp;
        cin >> tmp;
        coef.push_back(tmp);
        var.push_back(1);
    }
    cin >> c;
    if(r<3)cout<<"NONE"<<endl;
    while(var.size()!=0) {
        var.pop_back();
        solution();
        if(!r) break;
    }
    return 0;
}
