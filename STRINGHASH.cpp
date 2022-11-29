#include<bits/stdc++.h>
using namespace std;

// KMP Algorithm
int KMP(string &text,string &pattern){
    int n=text.size(),m=pattern.size();
    vector<int>LPS(m);
    LPS[0]=0;
    int i=1,p=0;
    while(i<m){
        if(pattern[i]==pattern[p]){
            p++;
            LPS[i]=p;
            i++;
        }
        else if(p==0){
            LPS[i]=0;
            i++;
        }
        else{
            p=LPS[p-1];
        }
    }
    int j=0;
    i=0;
    vector<int>indexes;
    while(i<n){
        if(text[i]==pattern[j]){
            i++,j++;
        }
        else if(j==0){
            i++;
        }
        else{
            j=LPS[j-1];
        }
        if(j==m){
            indexes.push_back(i-j);
        }
    }
    return (int)indexes.size();
}

// Rabin Karp Better Approach
long long inverse(long long n,long long mod){
    long long ans=1;
    long long b=mod-2;
    while(b){
        if(b&1){
            ans*=n;
            ans%=mod;
            b--;
        }
        b>>=1;
        n*=n;
        n%=mod;
    }
    return ans;
}
int rabingKarp(string &text,string &pattern){
    long long p=31,mod=1e9+7;
    int n=text.size(),m=pattern.size();
    int mx=max(n,m);
    long long pow[mx],inv[mx];
    pow[0]=1;
    for(int i=1;i<mx;i++){
        pow[i]=(pow[i-1]*p)%mod;
    }
    for(int i=0;i<mx;i++){
        inv[i]=inverse(pow[i],mod);
    }
    
    long long prefHash[n];
    prefHash[0]=(text[0]-'a'+1);
    for(int i=1;i<n;i++){
        prefHash[i]=(prefHash[i-1]+((text[i]-'a'+1)*pow[i])%mod)%mod;
    }
    long long hash=0;
    for(int i=0;i<m;i++){
        hash+=(pattern[i]-'a'+1)*pow[i];
        hash%=mod;
    }
    vector<int>indexes;
    for(int i=m-1;i<n;i++){
        long long here=((prefHash[i]+mod-(i-m>=0?prefHash[i-m]:0))%mod*inv[i-m+1])%mod;
        if(hash==here)indexes.push_back(i-m+1);
    }
    return (int)indexes.size();
}