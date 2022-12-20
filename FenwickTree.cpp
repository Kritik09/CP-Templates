#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct FenwickTree{
    int N,M;
    vector<T>fenwick;
    vector<vector<T>>fenwick2d;
    FenwickTree(){}
    FenwickTree(int _N,int offset=0){
        N=_N+offset;
        fenwick.assign(N+10,0);
    }
    FenwickTree(int _N,int _M,int xoffset=0,int yoffset=0){
        N=_N+xoffset,M=_M+yoffset;
        fenwick2d.assign(N+10,vector<T>(M+10,0));
    }
    template<typename U>
    void update(int index,U value,int offset=0){
        index+=offset;
        while(index<=N){
            fenwick[index]+=value;
            index+=index&(-index);
        }
    }
    template<typename U>
    void update(int index,int jndex,U value,int xoffset=0,int yoffset=0){
        index+=xoffset;
        while(index<=N){
            int tempJndex=jndex+yoffset;
            while(tempJndex<=M){
                fenwick2d[index][tempJndex]+=value;
                tempJndex+=tempJndex&(-tempJndex);
            }
            index+=index&(-index);
        }
    }
    T sum(int index,int offset=0){
        index+=offset;
        T SUM=0;
        while(index>0){
            SUM+=fenwick[index];
            index-=index&(-index);
        }
        return SUM;
    }
    T sum(int index,int jndex,int xoffset=0,int yoffset=0){
        index+=xoffset;
        T SUM=0;
        while(index>0){
            int tempJndex=tempJndex+yoffset;
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
// FenwickTree<long long>ft(n);