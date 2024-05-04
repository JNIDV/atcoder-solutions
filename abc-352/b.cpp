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
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length(), i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            cout << j + 1 << " ";
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    cout << "\n";
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
