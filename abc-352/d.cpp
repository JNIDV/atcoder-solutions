/*
Author: JNIDV
Date created:

Solution:

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct DSU
{
    vector<int> parent, size;
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
            make_set(i);
    }
    void make_set(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }
    bool is_same(int a, int b) { return find_set(a) == find_set(b); }
    int find_set(int v) { return v == parent[v] ? v : parent[v] = find_set(parent[v]); }
    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

ll log2_floor(ll i)
{
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
vector<vector<ll>> build_min(ll N, ll K, vector<ll> &array)
{
    vector<vector<ll>> st(K + 1, vector<ll>(N + 1));
    for (ll i = 0; i < N; i++)
        st[0][i] = array[i];
    for (ll i = 1; i <= K; i++)
        for (ll j = 0; j + (1 << i) <= N; j++)
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    return st;
}

ll min_query(ll L, ll R, vector<vector<ll>> &st)
{
    ll i = log2_floor(R - L + 1);
    return min(st[i][L], st[i][R - (1 << i) + 1]);
}

vector<vector<ll>> build_max(ll N, ll K, vector<ll> &array)
{
    vector<vector<ll>> st(K + 1, vector<ll>(N + 1));
    for (ll i = 0; i < N; i++)
        st[0][i] = array[i];
    for (ll i = 1; i <= K; i++)
        for (ll j = 0; j + (1 << i) <= N; j++)
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    return st;
}

ll max_query(ll L, ll R, vector<vector<ll>> &st)
{
    ll i = log2_floor(R - L + 1);
    return max(st[i][L], st[i][R - (1 << i) + 1]);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    vector<ll> idx(n + 1);
    for (int i = 0; i < n; i++)
    {
        idx[p[i]] = i;
    }
    vector<vector<ll>> mx_arr = build_max(n + 1, 30, idx);
    vector<vector<ll>> mn_arr = build_min(n + 1, 30, idx);
    ll ans = n;
    for (ll i = 1; i + k - 1 <= n; i++)
    {
        ans = min(ans, max_query(i, i + k - 1, mx_arr) - min_query(i, i + k - 1, mn_arr));
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
