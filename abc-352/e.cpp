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

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, vector<int>>> arr(m);
    for (int i = 0; i < m; i++)
    {
        int k, c;
        cin >> k >> c;
        vector<int> s;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            s.push_back(a);
        }
        arr[i].first = c;
        arr[i].second = s;
    }
    std::sort(arr.begin(), arr.end());
    vector<Edge> edges;
    for (int i = 0; i < m; i++)
    {
        int c = arr[i].first;
        for (int j = 0; j + 1 < (arr[i].second).size(); j++)
        {
            edges.push_back({(arr[i].second)[j] - 1, (arr[i].second)[j + 1] - 1, c});
        }
    }
    ll cost = 0;
    DSU dsu = DSU(n);
    std::sort(edges.begin(), edges.end());
    for (Edge e : edges)
    {
        if (dsu.find_set(e.u) != dsu.find_set(e.v))
        {
            cost += e.weight;
            dsu.union_sets(e.u, e.v);
        }
    }
    for (int i = 0; i + 1 < n; i++)
    {
        if (dsu.find_set(i) != dsu.find_set(i + 1))
        {
            cout << -1 << "\n";
            return;
        }
    }
    cout << cost << "\n";
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
