#include<bits/stdc++.h>
using namespace std;

default_random_engine rd(time(0));
long long longGen(long long low,long long high){
    uniform_real_distribution<double> dist(low,high);
    return dist(rd); 
}

vector<long long> generateArray(long long low,long long high,int N){
    vector<long long>arr;
    for(int i=0;i<N;i++){
        arr.push_back(longGen(low,high));
    }
    return arr;
}
template<typename T>
void randomShuffle(vector<T>&arr){
    shuffle(arr.begin(),arr.end(),rd);
}
int main(){
    
}