#include <iostream>
#include <bitset>
#include <sstream>
using namespace std;
bitset<64> bmap[64];
bitset<64> tmap[64];

int main(){

    for(int i=0;i<64;i++){
        long long tmp;
        cin>>tmp;
        bmap[i]=bitset<64>(tmp);
    }
    for (int i=0;i<64;i++) {
		for (int j = 63; j >-1; j--) {
			tmap[j][i]=bmap[63-i][j];
		}
	}
	for (int i=63;i>-1;i--){
        long long tmp;
        tmp=(long long)(tmap[i].to_ullong());
        cout<<tmp<<endl;
	}
    return 0;
}
