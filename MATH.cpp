#include<bits/stdc++.h>
using namespace std;

// Square Root
long long Sqrt(long long val){
    long long l=1,r=1e9,ans;
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
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}

// Inverse
long long inverse(long long val,long long mod=1e9+7){
    return Pow(val,mod-2,mod);
}

int main(){

}