#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void _print(int t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(long t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(float t) { cerr << t; }
void _print(string t) { cerr << t; }
template <typename H, typename... T>
void DBG(H h, T... t);
template <typename T>
void _print(vector<T> v);
template <typename T, typename V>
void _print(pair<T, V> p);
template <typename T>
void _print(set<T> v);
template <typename T, typename V>
void _print(set<T, greater<V>> v);
template <typename T>
void _print(unordered_set<T> v);
template <typename T>
void _print(multiset<T> v);
template <typename T, typename V>
void _print(multiset<T, greater<V>> v);
template <typename T, typename V>
void _print(map<T, V> v);
template <typename T, typename V, typename G>
void _print(map<T, V, greater<G>> v);
template <typename T, typename V>
void _print(unordered_map<T, V> v);
template <typename T, typename V>
void _print(multimap<T, V> v);
template <typename T, typename V, typename G>
void _print(multimap<T, V, greater<G>> v);
template <typename T>
void _print(deque<T> v);
template <typename T>
void _print(ordered_set<T> &s);
template <typename T>
void _print(ordered_multiset<T> &s);
template <typename T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T, typename V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <typename T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T, typename V>
void _print(set<T, greater<V>> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T>
void _print(unordered_set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T, typename V>
void _print(multiset<T, greater<V>> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T, typename V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T, typename V, typename G>
void _print(map<T, V, greater<G>> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T, typename V>
void _print(unordered_map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T, typename V>
void _print(multimap<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T, typename V, typename G>
void _print(multimap<T, V, greater<G>> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T>
void _print(deque<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T>
void _print(ordered_set<T> &s)
{
    cerr << "[";
    for (auto &it : s)
        cerr << it << ' ';
    cerr << endl;
}
template <typename T>
void _print(ordered_multiset<T> &s)
{
    cerr << "[";
    for (auto &it : s)
        cerr << it << ' ';
    cerr << endl;
}
void DBG() { cerr << ")" << endl; }
template <typename H, typename... T>
void DBG(H h, T... t)
{
    _print(h);
    if (sizeof...(t))
        cerr << ", ";
    DBG(t...);
}

#define deb(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: (", DBG(__VA_ARGS__);
