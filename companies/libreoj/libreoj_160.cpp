#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

#define int long long
using namespace std;
const int N = 50010;
int n, m;
//int w[N], v[N];
//int dfn[N];
//vector<int> ve[N];
//int fa[N];
int cnt = -1;

inline int read() {
    char ch;
    int x = 0;
    bool f = false;

    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = true;

    for (; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + (ch ^ 48);

    if (f)
        x = -x;

    return x;
}

void dfs(int x, vector<int> ve[], int maxn[], int dfn[]) {
    //cout<<x<<"\n";
    cout << "dfs x=" << x << endl;
    ++cnt;
    dfn[cnt] = x;
    cout << "cnt " << cnt << endl;
//    dfn[++cnt] = x;
    maxn[x] = cnt;

    for (int i = 0; i < ve[x].size(); i++) {
        int to = ve[x][i];
        dfs(to, ve, maxn, dfn);
        maxn[x] = max(maxn[x], maxn[to]);
    }
}

signed main() {
    cin >> n >> m;
    vector<int> ve[N];
    int w[N], v[N];
    int maxn[N];
    int dfn[N];
    int fa[N];
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m; j++)
            dp[i][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> fa[i];
        ve[fa[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++)
        cin >> w[i];

    for (int i = 1; i <= n; i++)
        cin >> v[i];



    dfs(0, ve, maxn, dfn);

    for (int i = n; i >= 0; i--) {
        for (int j = 0; j <= m; j++) {
            //cout<<i<<" "<<j<<"\n";
            if (j >= w[dfn[i]])
                dp[i][j] = max(dp[i][j], dp[i + 1][j - w[dfn[i]]] + v[dfn[i]]);

            dp[i][j] = max(dp[i][j], dp[maxn[dfn[i]] + 1][j]);
        }
    }

    int ans = 0;

    for (int j = 0; j <= m; j++)
        ans = max(ans, dp[0][j]);

    cout << ans;
    return 0;
}