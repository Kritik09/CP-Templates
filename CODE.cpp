/* I tried so hard and got so far
   but in the end it doesn't even matter
   I had to fall, to loose it all */ 

//Author : Kritik09

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifdef Kritik09
#define deb(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: (", DBG(__VA_ARGS__);
#else
#define deb(...)
#endif

//<---------------------------------------Hash Directives---------------------------------------------------------------->
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define nline cout << "\n";
#define yes return cout << "Yes\n",void();
#define no return cout << "No\n",void();
#define endl "\n"
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
template<typename T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update >;
template<typename T> using ordered_multiset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//<---------------------------------------Debugging Templates---------------------------------------------------------------->
void _print(int t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(long t) {cerr << t;}
void _print(long long t) {cerr << t;}
void _print(float t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(unsigned t) { cerr << t; }
template <size_t S> void _print(bitset<S> t) {cerr << t;}
template <typename H, typename... T> void DBG(H h, T... t);
template <typename T> void _print(vector <T> v);
template <typename T, typename V> void _print(pair <T, V> p);
template <typename T> void _print(set <T> v);
template <typename T,typename V> void _print(set <T,greater<V>> v);
template <typename T> void _print(unordered_set <T> v);
template <typename T> void _print(multiset <T> v);
template <typename T,typename V> void _print(multiset <T,greater<V>> v);
template <typename T, typename V> void _print(map <T, V> v);
template <typename T, typename V, typename G> void _print(map <T, V,greater<G>> v);
template <typename T, typename V> void _print(unordered_map <T, V> v);
template <typename T, typename V> void _print(multimap <T, V> v);
template <typename T, typename V, typename G> void _print(multimap <T, V, greater<G>> v);
template <typename T> void _print(deque <T> v);
template <typename T> void _print(ordered_set<T> &s);
template <typename T> void _print(ordered_multiset<T> &s);
template <typename T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T, typename V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <typename T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T, typename V> void _print(set <T,greater<V>> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T, typename V> void _print(multiset <T,greater<V>> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T, typename V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T, typename V, typename G> void _print(map <T, V, greater<G>> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T, typename V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T, typename V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T, typename V, typename G> void _print(multimap <T, V, greater<G>> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T> void _print(deque <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T> void _print(ordered_set<T> &s) {cerr << "[ ";for(auto &it:s) cerr << it << ' ';cerr<<"]";}
template <typename T> void _print(ordered_multiset<T> &s) {cerr << "[ ";for(auto &it:s) cerr << it << ' ';cerr<<"]";}
void DBG(){cerr << ")" << endl;}
template<typename H, typename... T>void DBG(H h, T... t) { _print(h); if(sizeof...(t))cerr << ", ";DBG(t...);}

//<---------------------------------------FAST TEMPLATE---------------------------------------------------------------->
template<typename T> istream& operator>>(istream& in,vector<T>&a){ for(auto &it:a){ in>>it; } return in; }
template<typename T> ostream& operator<<(ostream& out,vector<T>&a){ for(auto &it:a){ out << it << ' '; } return out; }
template<typename T> bool umin(T& a, const T& b) { return b<a?a=b, 1:0; }
template<typename T> bool umax(T& a, const T& b) { return a<b?a=b, 1:0; } 

//<---------------------------------------Code---------------------------------------------------------------->

/* 10% luck, 20% skill
   15% concentrated power of will
   5% pleasure, 50% percent pain
   and a 100% reason to remember the name */

const int N=2e5+10;
const long long mod=1e9+7;
// const long long mod=998244353;
const long double PIE=3.141592653589793238462;

void solve(int ttc){
    
}

signed main(){
    #ifdef Kritik09
    clock_t startTime = clock();
    #endif
    fastio
    int ttc=1;
    cin>>ttc;
    for(int i=1;i<=ttc;i++){
        // cout << "Case #" << i << ": ";
        solve(i);
    }
    #ifdef Kritik09
    clock_t endTime = clock();
    cerr << "\nTime Taken: " << double(endTime - startTime) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    #endif
    return 0;
}