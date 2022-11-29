#include<bits/stdc++.h>
using namespace std;

// Seive
void seive(vector<int>&prime,int N=2e5){
    prime.clear();
    prime.assign(N+10,1);
    prime[0]=prime[1]=0;
    for(long long i=2;i*i<=N;i++){
        if(prime[i]){
            for(long long j=i*i;j<=N;j+=i){
                prime[j]=0;
            }
        }
    }
}

// Factorization Seive
void seiveF(vector<int>&se,int N=2e5){
    se.clear();
    se.assign(N+10,-1);
    for(int i=2;i<=N;i++){
        if(se[i]==-1){
            for(int j=i;j<=N;j+=i){
                se[j]=i;
            }
        }
    }
    int q;cin>>q;
    
}
vector<int> getFactors(vector<int>&se,int n){
    vector<int>facs;
    while(n>1){
        facs.push_back(se[n]);
        n=n/se[n];
    }
    return facs;
}

// Square Root
long long Sqrt(long long val){
    long long l=1,r=1e9,ans=-1;
    while(l<=r){
        long long mid=l+(r-l)>>1LL;
        if(mid*mid<=val){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}

// Binary Exponentiation
long long Pow(long long a,long long b,long long mod=1e9+7){
    long long ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        b>>=1LL;
        a=(a*a)%mod;
    }
    return ans;
}

// Inverse
long long inverse(long long val,long long mod=1e9+7){
    return Pow(val,mod-2,mod);
}
