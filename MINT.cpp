#include<bits/stdc++.h>
using namespace std;

template<typename T,long long mod>
struct mint {
	T x;
	mint() : x(0) {}
	mint(T _x) {
		_x %= mod;
		if (_x < 0) _x += mod;
		x = _x;
	}
 
	mint& operator += (const mint &a) {
		x += a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator -= (const mint &a) {
		x += mod - a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator *= (const mint &a) {
		x = (T)x * a.x % mod;
		return *this;
	}
	mint pow(T pw) const {
		mint res = 1;
		mint cur = *this;
		while(pw) {
			if (pw & 1) res *= cur;
			cur *= cur;
			pw >>= 1;
		}
		return res;
	}
	mint inv() const {
		assert(x != 0);
		T t = x;
		T res = 1;
		while(t != 1) {
			T z = mod / t;
			res = (T)res * (mod - z) % mod;
			t = mod - t * z;
		}
		return res;
	}
	mint& operator /= (const mint &a) {
		return *this *= a.inv();
	}
	mint operator + (const mint &a) const {
		return mint(*this) += a;
	}
	mint operator - (const mint &a) const {
		return mint(*this) -= a;
	}
	mint operator * (const mint &a) const {
		return mint(*this) *= a;
	}
	mint operator / (const mint &a) const {
		return mint(*this) /= a;
	}
	bool operator == (const mint &a) const {
		return x == a.x;
	}
	bool operator != (const mint &a) const {
		return x != a.x;
	}
	bool operator < (const mint &a) const {
		return x < a.x;
	}
	bool operator <= (const mint &a) const {
		return x <= a.x;
	}
	bool operator > (const mint &a) const {
		return x > a.x;
	}
	bool operator >= (const mint &a) const {
		return x >= a.x;
	}
    friend ostream& operator<<(ostream& out,mint& a){
        out << a.x;
        return out;
    }
    friend istream& operator>>(istream& in,mint& a){
        in>>a.x;
        return in;
    }
};
using Mint=mint<long long,(long long)1e9+7>;