#include <iostream>
#include <fstream>
#include <list>
#include<string>
#define for_inc(i,s,e) for(int i=s; i<e; i++)
using namespace std;
list<char> gen;
list<char>::iterator it;
int N;
void read(){
    ifstream readFile;
    readFile.open("./sapiens.txt");
    if(readFile.is_open()){
        int idx=0;
        while(!readFile.eof()){
            string tmp;
            getline(readFile, tmp);
            if(idx !=0){
                for_inc(i,0,tmp.length())gen.push_back(tmp[i]);
            }
            idx++;
        }
    }
    readFile.close();
}
void go_tmp(list<char> &tmp,int i,int j){
    advance(it,i-1);
    for_inc(k,0,j-i+1){
        tmp.push_back(*it);
        it=gen.erase(it);
    }
}
void Front(int i,int j){
    list<char> tmp;
    it=gen.begin();
    go_tmp(tmp,i,j);
    gen.splice(gen.begin(),tmp);
}
void Back(int i,int j){
    list<char> tmp;
    it=gen.begin();
    go_tmp(tmp,i,j);
    gen.splice(gen.end(),tmp);
}
void Cut(int i,int j){
    it=gen.begin();
    advance(it,i-1);
    for_inc(k,0,j-i+1){
        it=gen.erase(it);
    }
}
void Double(int i,int j){
    list<char> tmp;
    it=gen.begin();
    advance(it,i-1);
    for_inc(k,0,j-i+1){
        tmp.push_back(*it);
        it++;
    }
    gen.splice(it,tmp);
}
void Flip(int i,int j){
    list<char> tmp;
    it=gen.begin();
    go_tmp(tmp,i,j);
    tmp.reverse();
    it=gen.begin();
    advance(it,i-1);
    gen.splice(it,tmp);
}
void Report(int i,int j){
    it=gen.begin();
    advance(it,i-1);
    for_inc(k,0,j-i+1){
        cout<<*it;
        it++;
    }
    cout<<endl;
}
int main(){
    read();
    cin>>N;
    for_inc(i,0,N){
        string act;
        int I, J;
        cin >>act>>I>>J;
        if(I>gen.size()){
            if(act=="report")cout<<"NONE"<<endl;
        continue;
        }
        if(J>gen.size())J=gen.size();
        if(act=="front")Front(I,J);
        else if(act=="back")Back(I,J);
        else if(act=="cut")Cut(I,J);
        else if(act=="double")Double(I,J);
        else if(act=="flip")Flip(I,J);
        else Report(I,J);
    }
    return 0;
}
