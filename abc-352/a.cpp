/*
Author: JNIDV
Date created:

Solution:

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    if (z >= min(x, y) && max(x, y) >= z)
        cout << "Yes\n";
    else
        cout << "No\n";
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
