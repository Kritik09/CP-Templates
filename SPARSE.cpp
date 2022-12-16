#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct SPARSE{
    vector<vector<T>>sparse;
	using F=function<T(const T&,const T&)>;
    int N,LOG;
	F FUN;
    T E;
    SPARSE(){};
    SPARSE(int _N,int _LOG,T _E,F _FUN){
        N=_N,E=_E,FUN=_FUN,LOG=_LOG;
        sparse.assign(LOG,vector<T>(N,E));
    }
    template<typename U>
    void build(const vector<U>&arr){
        for(int i=0;i<LOG;i++){
            for(int j=0;j+(1LL<<i)-1<N;j++){
                if(i==0){
                    sparse[i][j]=arr[j];
                }
                else{
                    sparse[i][j]=FUN(sparse[i-1][j],sparse[i-1][j+(1LL<<(i-1))]);
                }
            }
        }
    }
	T logQuery(int l,int r){
        if(l>r){
            return E;
        }
		T ANS=E;
		for(int i=LOG;i>=0;i--){
			int range=r-l+1;
			if(range<(1LL<<i))continue;
			else{
				ANS=FUN(ANS,sparse[i][l]);	
				l+=(1LL<<i);
			}
		}
		return ANS;
	}
    T query(int l,int r){
        if(l>r){
            return E;
        }
        int range=r-l+1;
        int jump=log2(range); 
        T ANS=FUN(sparse[jump][l],sparse[jump][r-(1LL<<jump)+1]);
        return ANS;
    }
};
// SPARSE<long long> st(n,25,0,[&](auto x,auto y){return gcd(x,y);});