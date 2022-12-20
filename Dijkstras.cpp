#include<bits/stdc++.h>
using namespace std;

struct Dijkstras{
    int N;
    vector<vector<pair<int,int>>>adj;
    vector<long long>distance;
    vector<int>parent;
    Dijkstras(int _N){
        N=_N;
        adj.assign(N+10,{});
        distance.assign(N+10,1e18+10);
        parent.assign(N+10,-1);
    }
    void dijkstras(int source){
        set<pair<long long,int>>st;
        st.insert({0,source});
        distance[0]=0;
        parent[0]=0;
        while(!st.empty()){
            auto it=st.begin();
            int node=it->second;
            long long weight=it->first;
            st.erase(it);
            for(auto child:adj[node]){
                int currnode=child.first;
                int currweight=child.second;
                int disFromSource=currweight+distance[node];
                if(distance[currnode]>disFromSource){
                    st.erase({distance[currnode],currnode});
                    distance[currnode]=disFromSource;
                    parent[currnode]=node;
                    st.erase({distance[currnode],currnode});
                }
            }
        }
    }
};