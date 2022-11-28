#include<bits/stdc++.h>
using namespace std;

// KMP Algorithm
void KMP(){
    string a,b;cin>>a>>b;
    int n=a.size(),m=b.size();

    vector<int>LPS(m);
    LPS[0]=0;
    int i=1,p=0;
    while(i<m){
        if(b[i]==b[p]){
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
    while(i<n){
        if(a[i]==b[j]){
            i++,j++;
        }
        else if(j==0){
            i++;
        }
        else{
            j=LPS[j-1];
        }
        if(j==m){
            cout << i-j << '\n';
            break;
        }
    }
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
void RB(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long p=31,mod=1e9+7;
    string a,b;cin>>a>>b;
    int n=a.size(),m=b.size();
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
    prefHash[0]=(a[0]-'a'+1);
    for(int i=1;i<n;i++){
        prefHash[i]=(prefHash[i-1]+((a[i]-'a'+1)*pow[i])%mod)%mod;
    }
    long long hash=0;
    for(int i=0;i<m;i++){
        hash+=(b[i]-'a'+1)*pow[i];
        hash%=mod;
    }
    long long ans=0;
    for(int i=m-1;i<n;i++){
        long long here=((prefHash[i]-(i-m>=0?prefHash[i-m]:0))*inv[i-m+1])%mod;
        if(here<0)here+=mod;
        if(hash==here)ans++;
    }
    cout << ans << '\n';
}


// Rabin Karp String Matching Algo
void solve(){
    const long long mod=1e9+7;
    string str;cin>>str;
    string pat;cin>>pat;
    int n=str.size();
    int m=pat.size();
    vector<long long>pow(m);
    int p=31;
    pow[0]=1;
    for(int i=1;i<m;i++){
        pow[i]=(pow[i-1]*p)%mod;
    }
    long long hash=0,curHash=0;
    for(int i=0;i<m;i++){
        hash=(hash + (pow[m-1-i]*(pat[i]-'a'+1))%mod)%mod;
        curHash=(curHash + (pow[m-1-i]*(str[i]-'a'+1))%mod)%mod;
    }
    auto match=[&](int idx){
        for(int i=0;i<m;i++,idx++){
            if(pat[i]!=str[idx])return false;
        }
        return true;
    };
    vector<int>ans;
    if(hash==curHash and match(0)){
        ans.push_back(1);
    }
    for(int i=0,j=m;j<n;j++,i++){
        curHash=(curHash - (pow[m-1]*(str[i]-'a'+1))%mod)%mod;
        curHash=(curHash * p)%mod;
        curHash=(curHash + (str[j]-'a'+1))%mod;
        if(curHash<0){
            curHash+=mod;
        }
        if(curHash==hash and match(i+1)){
            ans.push_back(i+2);
        }
    }
    if(ans.empty()){
        cout << "Not Found\n";
    }
    else{
        cout << ans.size() << '\n';
        for(auto it:ans){
            cout << it << ' ';
        }
        cout << '\n';
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}