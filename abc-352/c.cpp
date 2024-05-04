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
    int n;
    cin >> n;
    ll ans = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ans += a;
        mx = max(mx, (ll)b - a);
    }
    ans += mx;
    cout << ans << "\n";
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
