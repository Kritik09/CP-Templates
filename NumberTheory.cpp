#include<bits/stdc++.h>
using namespace std;

struct NumberTheory{

    // Seive of Eratosthenes
    vector<int>isPrime;
    void seive(int N=2e5+10){
        isPrime.clear();
        isPrime.assign(N+10,1);
        isPrime[0]=isPrime[1]=0;
        for(long long i=2;i*i<=N;i++){
            if(isPrime[i]){
                for(long long j=i*i;j<=N;j+=i){
                    isPrime[j]=0;
                }
            }
        }
    }

    // Generate primes
    vector<int> generatePrimes(int N=2e5){
        vector<int>primes;
        if(isPrime.empty()){
            seive(N);
        }
        for(int i=2;i<=N;i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
        return primes;
    }
    
    // Factorization Seive
    vector<int>se;
    void factorizationSeive(int N=2e5){
        se.clear();
        se.assign(N+10,-1);
        for(int i=2;i<=N;i++){
            if(se[i]==-1){
                for(int j=i;j<=N;j+=i){
                    se[j]=i;
                }
            }
        }
    }
    vector<int> primeFactorsSeive(int N){
        if(se.empty()){
            factorizationSeive(N);
        }
        vector<int>facs;
        while(N>1){
            facs.push_back(se[N]);
            N/=se[N];
        }
        return facs;
    }

    // Prime Factorization
    map<long long,int> primeFactors(long long N){
        map<long long,int>factors;
        while(N%2==0){
            factors[2]++;
            N/=2;
        }
        for(long long i=3;i*i<=N;i+=2){
            while(N%i==0){
                factors[i]++;
                N/=i;
            }
        }
        if(N>2){
            factors[N]++;
        }
        return factors;
    }
    
    // Square Root
    long long Sqrt(long long val){
        long long l=1,r=1e9,ans=-1;
        while(l<=r){
            long long mid=l+(r-l)/2;
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
    long long Pow(long long a,long long b,long long MOD=1e9+7){
        long long ans=1;
        while(b){
            if(b%2){
                ans=(ans*a)%MOD;
            }
            b/=2;
            a=(a*a)%MOD;
        }
        return ans;
    }

    // Inverse
    long long modInverse(long long val,long long MOD=1e9+7){
        return Pow(val,MOD-2,MOD);
    }

    // Factorial MOD P
    vector<long long>factorial;
    void genFactorials(int N=2e5,long long MOD=1e9+7){
        factorial.clear();
        factorial.assign(N+10,0);
        factorial[0]=factorial[1]=1;
        for(int i=1;i<=N;i++){
            factorial[i]=i*factorial[i-1];
            factorial[i]%=MOD;
        }
    }

    // NPR MOD P
    long long nPr(long long n,long long r,long long MOD=1e9+7){
        if((int)factorial.size()<=n){
            genFactorials(n,MOD);
        }
        if(n<r){
            return 0;
        }
        if(r==0){
            return 1;
        }
        long long ans=factorial[n];
        ans = (ans * modInverse(factorial[n-r],MOD))%MOD;
        return ans;
    }

    // NCR MOD P
    long long nCr(long long n,long long r,long long MOD=1e9+7){
        if((int)factorial.size()<=n){
            genFactorials(n,MOD);
        }
        if(n<r){
            return 0;
        }
        if(r==0){
            return 1;
        }
        long long ans=factorial[n];
        ans = (ans * modInverse(factorial[r],MOD))%MOD;
        ans = (ans * modInverse(factorial[n-r],MOD))%MOD;
        return ans;
    }

    // GCD
    long long GCD(long long a,long long b){
        if(a==0){
            return b;
        }
        return GCD(b%a,a);
    }

    // LCM
    long long LCM(long long a,long long b){
        return (a*b)/GCD(a,b);
    }
};
NumberTheory obj=NumberTheory();
