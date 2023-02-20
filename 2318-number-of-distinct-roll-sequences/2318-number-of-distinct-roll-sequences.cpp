#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define v64 vector<ll>
#define vp64 vector<pair<ll, ll>>
#define p64 pair<ll, ll>
#define forn(i, a, b) for (ll i = a; i < b; i++)
#define pqmin priority_queue<ll, vector<ll>, greater<ll>>
#define pqmax priority_queue<ll>
#define um unordered_map<ll, ll>
#define us unordered_set<ll>
#define pb push_back
#define ln "\n"
#define inc(v) sort(v.begin(), v.end())
#define dec(v) sort(v.rbegin(), v.rend())
const ll mod = 1e9 + 7;
tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> T;
// Ordered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
vp64 pf(ll n)
{
    vector<pair<ll, ll>> ans;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            pair<ll, ll> p;
            p.first = i;
            p.second = cnt;
            ans.push_back(p);
        }
    }
    if (n > 1)
    {
        pair<ll, ll> p;
        p.first = n;
        p.second = 1;
        ans.push_back(p);
    }
    return ans;
}
ll fastpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return (t * t) % mod;
    else
        return (a * (t * t) % mod) % mod;
}
class Solution
{
public:
    int dp[10001][7][7];
    int f(int n, int l1 = 0, int l2 = 0)
    {
        if (n == 0)
            return 1;
        ll res = 0;
        auto &t = dp[n][l1][l2];
        if(t!=-1) return t;
        for (int idx = 1; idx <= 6; idx++)
        {
            if (l1 == idx || l2 == idx)
                continue;
            if (__gcd(l2, idx) == 1 || l2==0)
            {
                res = (res + f(n - 1, l2, idx)) % mod;
            }
        }
        return t = res;
    }
    int distinctSequences(int n)
    {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};