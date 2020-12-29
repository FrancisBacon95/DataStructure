#include <iostream>
#include <vector>
using namespace std;
int n;

class poly{
    vector<long> result;
    long cnt=0;
public:
    void add(long _coef, long _exp);
    void mult(poly &tmp);
    void print();
};

void poly::add(long _coef, long _exp){
    if (result.size()<_exp+1){
        result.resize(_exp+1);
    }
    if (result[_exp]==0){cnt++;}
    result[_exp]+=_coef;
    if (result[_exp]==0){cnt--;}
}

void poly::mult(poly &tmp){
    vector<long> new_result;
    long new_cnt=0;
    for (auto iter = result.begin(); iter != result.end(); iter++){
        for (auto jter = (tmp.result).begin(); jter != (tmp.result).end(); jter++){
            if((*iter)!=0 && (*jter)!=0){
                long new_exp  = (iter-result.begin())+(jter-(tmp.result).begin());
                long new_coef = (*iter)*(*jter);
                if (new_result.size()<new_exp+1){
                    new_result.resize(new_exp+1);
                }
                if (new_result[new_exp]==0){new_cnt++;}
                new_result[new_exp]+=new_coef;
                if (new_result[new_exp]==0){new_cnt--;}
            }
        }
    }
    result=new_result;
    cnt=new_cnt;
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
    int k1;
    cin >>k1;
    for (int j=0;j<k1;j++){
        long coef, exp;
        cin >> coef >> exp;
        Poly.add(coef,exp);
    }

    for (int i=1;i<n;i++){
        int k;
        cin >> k;
        poly tmp_Poly;
        for(int j=0; j<k; j++){
            long coef, exp;
            cin >> coef >> exp;
            tmp_Poly.add(coef,exp);
        }
        Poly.mult(tmp_Poly);
    }
    Poly.print();
}

