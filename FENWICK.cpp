#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct FENWICK{
    int N,M;
    vector<T>fenwick;
    vector<vector<T>>fenwick2d;
    FENWICK(){}
    FENWICK(int _N){
        N=_N;
        fenwick.assign(N+10,0);
    }
    FENWICK(int _N,int _M){
        N=_N,M=_M;
        fenwick2d.assign(N+10,vector<T>(M+10,0));
    }
    template<typename U>
    void update(int index,U value){
        while(index<=N){
            fenwick[index]+=value;
            index+=index&(-index);
        }
    }
    template<typename U>
    void update(int index,int jndex,U value){
        while(index<=N){
            int tempJndex=jndex;
            while(tempJndex<=M){
                fenwick2d[index][tempJndex]+=value;
                tempJndex+=tempJndex&(-tempJndex);
            }
            index+=index&(-index);
        }
    }
    T sum(int index){
        T SUM=0;
        while(index>0){
            SUM+=fenwick[index];
            index-=index&(-index);
        }
        return SUM;
    }
    T sum(int index,int jndex){
        T SUM=0;
        while(index>0){
            int tempJndex=tempJndex;
            while(tempJndex>0){
                SUM+=fenwick2d[index][tempJndex];
                tempJndex-=tempJndex&(-tempJndex);
            }
            index-=index&(-index);
        }
        return SUM;
    }
    T query(int low,int high){
        return sum(high)-sum(low-1);
    }
    T query(int x1,int y1,int x2,int y2){
        return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
    }
};
// FENWICK<long long>ft(n);