#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct DSU{
    int N;
    vector<T> parent,rank;
    DSU(){}
    DSU(int _N){
        N=_N;
        parent.assign(N+10,0);
        rank.assign(N+10,0);
        for(T i=0;i<=N;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }
    ~DSU(){
        parent.clear();
        rank.clear();
    }
    template<typename U>
    T findSet(U node){
        if(parent[node]==node)return node;
        return parent[node]=findSet(parent[node]);
    }
    template<typename U>
    bool unite(U nodeX,U nodeY){
        nodeX=findSet(nodeX);
        nodeY=findSet(nodeY);
        if(nodeX==nodeY)return false;
        if(rank[nodeX]<rank[nodeY])swap(nodeX,nodeY);
        rank[nodeX]+=rank[nodeY];
        parent[nodeY]=nodeX;
        return true;
    }
    template<typename U>
    bool isSame(U nodeX,U nodeY){
        return findSet(nodeX)==findSet(nodeY);
    }
};
// DSU<int>dsu(n);