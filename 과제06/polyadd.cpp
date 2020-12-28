#include <iostream>
#include <vector>
using namespace std;
int n;

class poly{
    vector<int> result;
    int cnt=0;
public:
    void add(int _coef, int _exp);
    void print();
};

void poly::add(int _coef, int _exp){
    if (result.size()<_exp+1){
        result.resize(_exp+1);
    }
    if (result[_exp]==0){cnt++;}
    result[_exp]+=_coef;
    if (result[_exp]==0){cnt--;}
}

void poly::print(){
    if (cnt==0){cout<<1<<endl<<0<<" "<<0<<endl;
    }else{
        cout << cnt << endl;
        for (auto iter = result.end()-1; iter != result.begin()-1; iter--) {
            if(*iter !=0)
                cout << *iter << " " << iter - result.begin() << endl;
        }
    }
}

int main(){
    poly Poly;
    cin >> n;
    for (int i=0;i<n;i++){
        int k;
        cin >> k;
        for(int j=0; j<k; j++){
            int coef, exp;
            cin >> coef >> exp;
            Poly.multi(coef,exp);
        }
    }
    Poly.print();
}
