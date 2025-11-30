#include<bits/stdc++.h>
using namespace std;

int t, n;
vector<int> dp(1001, 1);
int main() {
    cin >> t;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i] += dp[];
        }
    }
    while(t--) {
        cin >> n;
   
        cout << dp[n] << "\n";
    }
}
/*

#define MOD 1'000'000'009

//DP[i][j] : i를 1, 2, 3의 합으로 구성하는 방법중 마지막에 사용한 수가 j인 경우
int n, t;
vector<vector<int>> dp(1000001, vector<int>(4));
int DP(int i, int j) {
    if (i <= 0) return 0;
    if (dp[i][j] != 0) return dp[i][j];
    switch (j) {
        case 1: return dp[i][1] = (DP(i - 1, 2) + DP(i - 1, 3))%MOD;
        case 2: return dp[i][2] = (DP(i - 2, 1)+ DP(i - 2, 3))%MOD;
        case 3: return dp[i][3] = (DP(i - 3, 1) + DP(i - 3, 2))%MOD;
    }
}
int main() {
    cin >> t;
    dp[1][1] = 1; dp[2][2] = 1; dp[3][1] = 1, dp[3][2] = 1, dp[3][3]=1;
    while (t--) {
        cin >> n;
        cout << ((DP(n, 1) + DP(n, 2))%MOD + DP(n, 3))%MOD << "\n";
    }
}
/*
#define MOD 1'000'000'009
int n, t;
vector<long long int> dp(1000001);
long long int DP(int s) { 
    if (s <= 0) return 0;
    if (dp[s] != 0) return dp[s];
    return dp[s] = (DP(s - 1) + DP(s - 2)+ DP(s - 3))%MOD;
}
int main() {
    cin >> t;
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    while (t--) {
        cin >> n;
        cout << DP(n)%MOD << "\n";
    }
}
/*
int main() {
    int r, w, c, sum=0;
    cin >> r >> c >> w;
    vector<vector<int>> v(r + w, vector<int>(r+w));
    for (int i = 0; i < r+w; i++) {
        v[i][0] = 1; v[i][i] = 1;
    }

    for (int i = 2; i < r + w; i++) {
        for (int j = 1; j < i; j++) {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            
        }
    }
    for (int i = 0; i < r+w; i++) {
        for (int j = 0; j < i+1; j++) {
            cout << v[i][j] << " ";
            if (r - 1 <= i && i <= r + w - 2 && c-1<=j && j <= c+i-r)
                sum += v[i][j];
        }
        cout << "\n";
    }
    cout << sum;
}
/*
// DP[i] = { i까지 오는데 걸리는 최소 점프 횟수
int main() {
    int n;
    cin >> n;
    vector<int> v(n), dp(n, 1001);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dp[0] = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 1; i+j < n && j <= v[i]; j++) {
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }
    for (int i = 0; i < n; i++) cout << dp[i] << ' ';
    cout << (dp[n - 1] == 1001 ? -1 : dp[n - 1]);
}
/*
int n;
vector<int> dp(1001), v(1001);
vector<pair<int, int>> a;
//DP[i] : i개의 카드를 사기 위해 지불해야하는 최댓값
// 1 -> 몇 개를 샀는지
// 2 -> i번째 카드팩을 j번 산 가격보다 i*j번 카드의 값이 크면 i*j는 탈락
// 3 -> DP[i] = 
int main() {
    int n, maxl = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> v[i], dp[i] = v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if(j % i == 0) v[j] = max(v[j], v[i] * j / i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
        maxl = max(maxl, dp[i] + dp[n - i]);
    }
    cout << maxl;
}
/*
//DP[i] : A 에서 K로 가는 데 필요한 최소 연산 횟수
//DP[i*2] = max(DP[i] + 1, DP[i*2]);
//DP[i+1] = max(DP[i] + 1, DP[i+1]);
vector<int> dp(1000001, 1000001);
int main() {
    int a, k;
    cin >> a >> k;
    dp[a] = 0;
    for (int i = a; i < k; i++) {

        if (i * 2 <= k) dp[i * 2] = min(dp[i] + 1, dp[i * 2]);
        if (i + 1 <= k) dp[i + 1] = min(dp[i] + 1, dp[i+1]);
    }
    cout << dp[k];
}
/*
// DP[i] : i를 1,2,3 의 합으로 나타내는 방법의 수
// DP[i] = DP[i-1] + DP[i-2] + Dp[i-2];
vector<int> dp(12);
int DP(int n) {
    if (n <= 0) return 0;
    if (dp[n] != 0) return dp[n];
    return dp[n] = DP(n-1) + DP(n - 2) + DP(n - 3);
}
int main() {
    int t, n;
    cin >> t;
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    while (t--) {
        cin >> n;
        cout << DP(n) << "\n";
    }
    for (int i = 0; i <= 11; i++) cout << dp[i] << " ";
}
/*
//DP[i]:  i-2, i-1번째 계단을 연속으로 밟지않고 i번째 계단을 밟을때 최대 점수
//DP[i] = max(DP[i - 2], v[i - 1] + dp[i - 3])) + v[i];
vector<int> v(302), dp(302);
int DP(int n) {
    if (n == -1) return 0;
    if (n == 1 || n == 0) return v[n];
    if (dp[n] != 0) return dp[n];
    return dp[n] =  max(DP(n - 2), v[n - 1] + DP(n-3)) + v[n];
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    dp[1] = v[1];
    cout << DP(n);
}

/*
//dp[i][j] : i번째 자리에서 자리수가 j인 오르막수의 개수
//dp[i][j] = dp[i-1][j] -> i-1번째 수까지 오르막수가 성립하고
//           + dp[i][j-1] -> i-1번   째 수가 무엇인지에 따라 i번째 자리에 들어올 수 있는 수가 바뀜
int main() {
    int n, cnt=0;
    cin >> n;
    vector<vector<int>> dp(n+1, vector<int>(10));
    for (int i = 1; i <= 10; i++) dp[1][i-1] = i;
    for (int i=1; i<=n; i++) dp[i][0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 10007;
        }
    }
    cout << dp[n][9];
} 
/*
vector<int> v(10003);
vector<vector<int>> dp(10003, vector<int>(2, -1));
int n;
// DP[i][j] = 0~i번째까지 i번째 칸을 밟았을때
// j가 0이면 i-1번째 칸을 밟지 않았을 때의 앞으로 얻을 수 있는 포도주 양의 최대값
// j가 1이면 i-1번째 칸을 밟고 넘어왔을 때의 앞으로 얻을 수 있는 포도주양의 최대값
int DP(int i, int j) {
    if (i >= n) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (j == 0) return dp[i][0] = max(DP(i + 1, 1), DP(i + 2, 0)) + v[i];
    else return dp[i][1] = max(DP(i + 2, 0), DP(i + 3, 0)) + v[i];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << max(DP(0, 0), DP(1, 0));
}
/*
int main() {
    int n, maxl=0;
    cin >> n;
    vector<int> v(n), dp(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        maxl = max(maxl, dp[i]);
    }
    cout << maxl + 1;
}
/*
int main() {
    int n, a, p;
    cin >> n >> a >> p;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if () {

    }
    cout << ans;

}
/*
int main() {
    long long int m=0, r = 0, n, k, sum;
    cin >> n;
    vector<long long int> v(n+1);
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> k;
    sum = v[0];
    for (int l = 0; l < n; l++) {
        while (sum <= k && r<n) sum += v[++r];
        if(sum > k)m += n - r;
        sum -= v[l];
    }
    cout << m;
}
/*
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, ans=0;
    cin >> n;
    vector<int> v(n+1), s(n+1);
    
    for (int i = 1; i <= n; i++) cin >> v[i], s[i] = v[i] + s[i-1];
    cin >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if ( s[j] - s[i] + v[i] > k) {
                ans++;
            }
        }
    }
    cout << ans;
}
/*
int main() {
    int n, maxl = 1;
    cin >> n;
    vector<int> v(n + 1), dp1(n + 1, 1), dp2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (v[i] > v[j]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            if (v[i] > v[j]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++) maxl = max(dp1[i]+dp2[i]-1, maxl);
    cout << maxl << "\n";
}
/*
int main() {
    int n, maxl=1;
    cin >> n;
    vector<int> v(n+1), dp1(n+1, 1), dp2(n+1, 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <= i; j++) {
            if (v[i] > v[j]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    cout << dp1[n] << "\n";
}
/*
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1));
    for (int i = 1; i <= str1.size(); i++) {
        for (int j = 1; j <= str2.size(); j++) {
            if(str1[i-1] == str2[j-1]) dp[i][j]+= dp[i-1][j-1]+1;
            else dp[i][j] += max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[str1.size()][str2.size()];
}
/*
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> v(3, vector<int>(n + 1));
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> v[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                if (j == 0) v[j][i] += max(v[1][i - 1], v[2][i - 1]);
                else if (j == 1) v[j][i] += max(v[0][i-1], v[2][i-1]);
                else v[j][i] += max(v[0][i-1], v[1][i-1]);
            }
        }
        cout << max(max(v[0][n], v[1][n]), v[2][n]);
    }
}
/*
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> v(2, vector<int>(n + 1));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        for (int i = 0; i < n; i++)
    }
}
/*
int main() {
    long long int n;
    cin >> n;
   
    vector<vector<long long int>> v(n, vector<long long int>(n, 0));
    vector<vector<long long int>> c(n, vector<long long int>(n, 0));
    c[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if (v[i][j]) {
                if (i + v[i][j] < n) {
                    c[i + v[i][j]][j] += c[i][j];
                }
                if (j + v[i][j] < n) {
                    c[i][j + v[i][j]] += c[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }
    cout << c[n - 1][n - 1];
}
/*
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> v(2, vector<int>(n+1));
        for(int i=0; i<2; i++ ){    
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        for(int i=0; i<n; i++ )
    }
}
/*
int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> v(n+2), s(n+2), b(n+2), c(n+2), d(n+2);
    v[0] = -1000000000, v[n+1] = 1000000000;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s[i] += s[i - 1] + c[i-1];
        c[i] = v[i] < v[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        b[i] += b[i + 1] + d[i+1];
        d[i] = v[i] > v[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == 0 && b[i] == 0 && v[i-1] <= v[i+1]) ans++;
    }
    for (int i = 1; i <= n; i++) {
        cout << "s : " << s[i] << "  b : " << b[i] << " \n";
    }
    cout << ans;
}
/*
vector<int> v, visited, edge;
void dfs(int s) {
    visited[s] = 1;
    if (!visited[edge[s]])
        dfs(edge[s]);
}
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        v.resize(n + 1), visited.resize(n+1), edge.resize(n+1);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            edge[i + 1] = v[i];
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
                sum++;
            }
        }
        v.clear(), edge.clear(), visited.clear();
        cout << sum << "\n";
    }
}
/*
int main() {
    int n, zsum = 0, osum = 0;
    zsum = 0, osum = 0;
    string s;
    cin >> s;
    if (s[0] == '0') zsum++;
    else osum++;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            if (s[i] == '1') osum++;
            else zsum++;
        }
    }
    cout << min(zsum, osum);
}
/*
int main() {
    int n, m, sum=0, c=1;
    cin >> n >> m;
    vector<int> v(550001);
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            v[c++] = i;
        }
    }
    for (int i = n; i <= m; i++) {
        sum += v[i];
    }
    cout << sum;
}

/*
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n+1, vector<int>(m+1));
    int ki = (k-1)/m+1, kj = (k-1)%m+1;
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 || j == 1) v[i][j] = 1;
            else v[i][j] = v[i-1][j] + v[i][j-1];
        }
    }
    if (k == 0) {
        cout << v[n][m];
        return 0;
    }
    cout << v[ki][kj] * v[n - ki + 1][m - kj + 1];
}
/*int n, k, a, b, maxl;

vector<vector<int>> dp(90, vector<int>(2));
int main() { 
    cin >> n;
    dp[1][0] = 0, dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    cout << dp[n][1] + dp[n][0];
}
/*
int n, maxl;
vector<int> v;
void dp(int i, int s, int cnt) {
    s += v[i];
    if (maxl < s) maxl = s;
    if (i < n-1) {
        if (cnt < 2) {
            dp(i+1, s, v    )
        }
        dp ()
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> n;
    
}
/*
int n, t;
vector<long long int> v(101);
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        v[1] = v[2] = v[3] = 1;
        for (long long int i = 4; i <= n; i++) {
            v[i] = v[i - 3] + v[i - 2];
            
        }
        cout << v[n] << "\n";
    }
}
/*
int p[100001], sz[100001], cnt[501];
vector<pair<int, pair<int, int>>> e;
vector<pair<int, int>> v;
int find(int a) {
    if (a == p[a]) return a;
    return p[a] = find(p[a]);
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u, sz[u] += sz[v];
}
int main() {
    int n, m, c, d, sum=0, s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
    for (int i = 0; i < m; i++) {
        cin >> c >> d >> s;
        e.push_back({ s, { c, d } });
        v[d].push_back(s, { c });
    }
    sort(e.begin(), e.end());
    for (pair<int, pair<int, int>> s : e) {
        int start = find(s.second.second), end = find(s.second.first);
        if (start == end) continue;
        merge(start, end);
        sum += s.first;
        if()
    }
    cout << sum;
}
/*
int p[100001], sz[100001];
vector<pair<long long int, int>> vx, vy, vz;
vector<tuple< long long int, int, int>> pv;
bool compare1(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
long long int n, x, y, z, sum, cnt;
int find(int a) {
    if (a == p[a]) return a;
    return p[a] = find(p[a]);
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u, sz[u] += sz[v];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        vx.push_back({ x, i }), vy.push_back({ y, i }), vz.push_back({ z, i });
    }
    sort(vx.begin(), vx.end(), compare1), sort(vy.begin(), vy.end(), compare1), sort(vz.begin(), vz.end(), compare1);
    for (int i = 0; i < n - 1; i++) {
        pv.push_back(make_tuple(abs(vx[i].first - vx[i + 1].first), vx[i].second, vx[i + 1].second));
        pv.push_back(make_tuple(abs(vy[i].first - vy[i + 1].first), vy[i].second, vy[i + 1].second));
        pv.push_back(make_tuple(abs(vz[i].first - vz[i + 1].first), vz[i].second, vz[i + 1].second));
    }
    sort(pv.begin(), pv.end());
    for (int i = 0; i < pv.size(); i++) {
        long long int start = get<1>(pv[i]), end = get<2>(pv[i]), value = get<0>(pv[i]);
        if (find(start) != find(end)) {
            cout << start << "  " << end << "\n";
            merge(start, end);
            sum += value;
        }
    }
    cout << sum;
}
/*
unsigned long long int p[10001], sz[10001], x[10001];
vector<pair<unsigned long long int, pair<int, int>>> pv;
int find(int a) {
    if (a == p[a]) return a;
    return p[a] = find(p[a]);
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u, sz[u] += sz[v];
}
int main() {
    unsigned long long int n, a, b, c, d;
    double sum = 0;
    cin >> n;
    iota(p + 1, p + 1 + int(n), 1);
    cin >> a >> b >> c >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i]; 
        for (int j = 1; j < i; j++) {
            pv.push_back({ (a * x[j]%c + b * x[i]%c) % c ^ d, {i, j} });
            pv.push_back({ (a * x[j]%c + b * x[i]%c) % c ^ d, {j, i} });
            cout << ((a * x[j] + b * x[i]) % c ^ d) << " ";
        }
    }
    sort(pv.begin(), pv.end());
    for (int i = 0; i < pv.size(); i++) {
        unsigned long long int start = pv[i].second.first, end = pv[i].second.second, len = pv[i].first;
        if (find(start) != find(end)) {
            merge(start, end);
            sum += len;
        }
    }
    cout << sum;
}
/*
int p[200001], sz[200001];
vector<pair<int, pair<int, int>>> v;
int find(int a) {
    if (a == p[a]) return a;
    return p[a] = find(p[a]);
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u, sz[u] += sz[v];
}
int main() {
    int S, E, V, n, m, cnt = 0, sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> S >> E >> V;
        v.push_back({ V, {S, E} });
    }
    for (int i = 1; i <= n; i++) {
        cin >> V;
        v.push_back({ V, {i, 0} });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        int start = v[i].second.first, end = v[i].second.second, len = v[i].first;
        if (find(start) != find(end)) {
            merge(start, end);
            sum += len;
        }
    }
    cout << sum;
}
    /*
    int sz[200001], p[200001];
    int find(int s) {
        if (s == p[s]) return s;
        return p[s] = find(p[s]);
    }
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        p[v] = u, sz[u] += sz[v];
    }
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int n, m, sum = 0, cnt = 0;
        cin >> n >> m;
        vector< tuple<int, int, int>> pv(m);
        for (int i = 1; i <= n; i++) p[i] = i;
        for (int i = 0; i < m; i++) {
            tuple<int, int, int> a;
            cin >> get<1>(a) >> get<2>(a) >> get<0>(a);
            pv.push_back(a);
        }
        sort(pv.begin(), pv.end());
        iota(p + 1, p + 1 + n, 1);
        for (tuple<int, int, int> a : pv) {
            int s = find(p[get<1>(a)]), e = find(p[get<2>(a)]);
            if (s != e) {
                merge(s, e);
                sum += get<0>(a);
                cnt++;
                if (cnt >= n) break;
            }
        }
        cout << sum;
    }
/*
int n, m, c, a, b;
int sz[1000001];
int p[1000001];
int find(int s) {
    if (s == p[s]) return s;
    return p[s] = find(p[s]);
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u, sz[u] += sz[v];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
    for (int i = 0; i < m; i++) {
        cin >> c >> a >> b;
        if (c == 0) merge(a, b);
       else cout << ((find(a) == find(b)) ? "YES\n" : "NO\n");
    }
}
/*
#define tpi4 tuple<int, int, int, int>
vector<vector<vector<int>>> v;
vector<string> graph;
queue<tpi4> q;
int n, m, k, minl = 1000001, dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
void BFS() {
    q.push({0, 0, 0, 0});
    while (!q.empty()) {
        tpi4 f = q.front();
        for (int i = 0; i < 4; i++) {
            int x = get<0>(f) + dx[i], y = get<1>(f) + dy[i], s = get<2>(f)+1, b = get<3>(f); 
            if (0 <= x && x < n && 0 <= y && y < m) {

                if (graph[x][y] == '0') {
                    q.push({ x, y, s + 1 , b });
                    if(v[x][y] > v[get<0>(f)][get<1>(f)] + 1)
                        v[x][y] = v[get<0>(f)][get<1>(f)] + 1;
                }
                else if (b < k) {
                    q.push({ x, y, s + 1 , b+1 });
                    if(v[x][y] > v[get<0>(f)][get<1>(f)] + 1)
                        v[x][y] = v[get<0>(f)][get<1>(f)] + 1;
                }
            }
        }
        q.pop();
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    graph.resize(n + 1), v.resize(n+1, vector<vector<int>>(m + 1, vector<int>(k+1)));
    for (int i = 0; i < n; i++) cin >> graph[i];
    v[0][0][0] = 0;
    BFS();
    for (int i = 0; i <= k; i++) {
        minl = min(minl, v[n - 1][m - 1][i]);
    }
}
/*
int n, m, a, b, idg[32001];
vector<vector<int> > v;
priority_queue<int> pq;
queue<int> q;
int main() {
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        idg[a]++;
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (idg[i] == 0) q.push(i);
    while (!q.empty()) {
        int k = q.front();
        for (int i : v[k]) {
            if (--idg[i] == 0) pq.push(i);
        }
        while (!pq.empty()) cout << pq.top() << " ", pq.pop();
        cout << k << " ";
        q.pop();
    }
}
/*
int n, m, a, b, idg[32001];
vector<vector<int> > v;
priority_queue<int> pq;
queue<int> q;
int main() {
    cin >> n >> m;
    v.resize(n+1);
    for (int i = 0; i < m; i++)     cin >> a >> b;

    for(int i=1; i<=n; i++) if(idg[i]==0) q.push(i);
    while(!q.empty()) {
        int k = q.front();
        for(int i:v[k]) {
            if(--idg[i]==0) q.push(i);
        }
        cout << k << " ";
        q.pop();
    }   
}
/*
int t, n, xs, ys, x2, y2;
int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { -1, 1, -2, 2, -2, 2, 1, -1};
bool check(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0)), visited(n+1, vector<int>(n+1, 0));
        cin >> xs >> ys >> x2 >> y2;
        queue<pair<pair<int,int>,int>> q;
        q.push({{ xs, ys }, 0});
        while (!q.empty()) {
            int x = q.front().first.first, y = q.front().first.second, z=q.front().second;
            q.pop();
            if (x == x2 && y == y2) {
                cout << z << "\n";
                break;
            }
            for (int i = 0; i < 8; i++) {
                if (check(x + dx[i], y + dy[i]) && !visited[x+dx[i]][y+dy[i]]) {
                    q.push({ { x + dx[i], y + dy[i] }, z+1});
                    visited[x + dx[i]][y + dy[i]] = 1;
                }
            }
            
        }
    }
}
/*
vector<int> d, r, g;
vector<vector<int>> v;
queue<int> q;
int main() {
    int n, k, t, x, y, w;
    cin >> t;
    while (t--) {

        cin >> n >> k;
        d.resize(n+1, 0), r.resize(n + 1, 0), g.resize(n+1, 0);
        v.resize(n+1);
        for (int i = 1; i <= n; i++) cin >> d[i];
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            v[x].push_back(y);
            g[y]++;
        }
        cin >> w;
        for (int i = 1; i <= n; i++) {
            if (g[i] == 0) {
                r[i] = d[i];
                q.push(i);
            }
        }
        while (!q.empty()) {
            int a = q.front();
            for (int i : v[a]) {
                g[i]--;
                if (g[i] == 0) {
                    q.push(i);
                }
                r[i] = max(r[a] + d[i], r[i]);
            }
            q.pop();
        }
        cout << r[w] << "\n";
        v.clear(); r.clear(), d.clear(), g.clear();
    }
}
/*
int main() {
    int n, p, q, r, s, a, sum=0;
    cin >> n >> p >> q >> r >> s >> a;
    vector<int> v(n+1);
    v[1] = a;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) v[i] = p * v[i / 2] + q;
        else v[i] = r * v[i / 2] + s;
        sum += v[i];
    }
    cout << sum+a;
}
/*
int main() {
    long long int n;
    cin >> n;
    if (n > INT_MAX || n < INT_MIN) cout << "long long";
    else if (n > SHRT_MAX || n < SHRT_MIN) cout << "int";
    else cout << "short";
}
/*
int n;
string str[5] = { "재귀함수가 뭔가요?", "잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.", "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.", "그의 답은 대부분 옳았다고 하네.그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.", "라고 답변하였지." };
void f(int s) {
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < s; j++) cout << str[0];
        if (i == 6 && s + 1 < n) f(s + 1);
        cout << str[i] << "\n";
    }
}
int main() {
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    f(0);
}
/*
int main() {
    float n, m;
    cin >> n >> m;
    cout << !(n - n * (m / 100) >= 100);
}
/*
int main() {
    int n, m;
    string str;
    cin >> n >> m;
    unordered_map<string, int> s;
    unordered_map<int, string> d;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        s[str] = i;
        d[i] = str;
    }
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (str[0] <= '9') cout << d[stoi(str)] << "\n";
        else cout << s[str] << "\n";
    }
}
/*int main() {
    long long int n, s=0, c=0;
    cin >> n;
    string a;
    cin >> a;
    for (int i = 0; i <=n; i++) {  if (a[i] == '1') c++; else s += c * (c + 1) / 2, c = 0; }
    cout << s;
}
/*
int res, v[11][11];
int c(int s, int w, int a) {
    for (int i = a; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (v[s + i][w + j] != 1) return 0;
        }
    }
    return 1;
}
void dfs(int s, int cnt) {
    if (s == 10) { res = min(res, cnt); return; }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            if (c(s, i, j)) {

            }
        }
    }
}
int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> v[i][j];
        }
    }
    dfs(0, 0);
    cout << res;
}
/*
int n, res;
vector<int> v;
int c(int s, int w) {
    for (int i = 0; i < s; i++) {
        if (abs(v[i] - w) == abs(i - s)) return 0;
        if (v[i] == w) return 0;
    }
    return 1;
}
void dfs(int s) {
    if (s == n) { res++; return; }
    for (int i = 0; i < n; i++) {     
        if (c(s, i))v[s] = i, dfs(s + 1),v[s] = -1; 
    }
}
int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n+1, -1);
    dfs(0);
    cout << res;
}
/*
// dp[i][j] ==  i개에 쏘고, 1부터 j까지 갔을때 최댓값
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, k, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, -1, 1 }, sum = 0;
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m));
    vector<int> ruby;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> v[i][j], ruby.push_back();
    }

    }
    sort(ruby.begin(), ruby.end(), greater<int>());
    for (int i = 0; i < ((k>ruby.size()) ? ruby.size():k); i++) cout << ruby[i] << "and \n", sum += ruby[i];
    cout << sum;
}
/*
#define llt long long int
#define pllt pair<llt, llt>
bool cmp(pllt a, pllt b) {
    if (a.second == b.second) return a.first > b.first;
    else return a.second > b.second;
}
int main() {
    llt n, d, h;
    cin >> n;
    vector<pllt> v;
    vector<vector<pllt>> dp;
    for (int i = 0; i < n; i++) {
        cin >> d >> h;
        v.push_back(make_pair(d, h));
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) {
        llt sum = 0;
        for (int j = i; j >=0; j--) {
            //cout << j << ", " << v[j].first << "  == " << v[j].second + v[j].first * j << "\n";
            sum += v[j].second + v[j].first * (i-j);
        }
        cout << sum << "\n";
    }
}
/*보류 : 꿀잼 루비 문제
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, k, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, -1, 1 }, sum = 0;
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m));
    vector<int> ruby;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> v[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < 2; l++) {
                int x = i + dx[l], y = j + dy[l];
                if (0 <= x && x < n && 0 <= y && y < m) {
                    
                }
            }
        }
    }
    sort(ruby.begin(), ruby.end(), greater<int>());
    for (int i = 0; i < 5; i++) sum += ruby[i];
    cout << sum;
}
/*
#define ppi pair<int, pair<float, float>>
using namespace std;
bool cmp(ppi a, ppi b) {
    
    if (a.second.second / a.second.first == b.second.second / b.second.first)
        return a.first < b.first;
    else
        return a.second.second / a.second.first >b.second.second / b.second.first;
}
int main() {
    vector<ppi> v;
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, t, s;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t >> s, v.push_back({ i + 1, {t, s} });
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) cout << v[i].first << " ";
}
/*
vector<int> dp;
int n;
void d(int s, int a ) {
    if (s <= n) {
        if (dp[s + 1] != -1) {
            dp[s + 1] = !a;
            d(s + 1, !a);
        }
        if (dp[s + 3] != -1) {
            dp[s + 3] = !a;
            d(s + 3, !a);
        }
        if (dp[s + 4] != -1) {
            dp[s + 4] = !a;
            d(s + 4, !a);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    dp.resize(n + 6);
    d(0, 1);
    cout << (dp[0] != dp[n] ? "CY" : "SK");
}
/*
vector<vector<int>> a(3, vector<int>(3)), b(3, vector<int>(3));
int main() {
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[1][j];
            b[1][j] = a[1][j];
            if (j == 0) a[1][j] += min(a[0][1], a[0][0]);
            else if (j == 1) a[1][j] += min(a[0][1], min(a[0][0], a[0][2]));
            else if(j==2) a[1][j] += min(a[0][2], a[0][1]);
            if (j == 0) b[1][j] += max(b[0][1], b[0][0]);
            else if (j == 1) b[1][j] += max(b[0][1], max(b[0][0], b[0][2]));
            else if (j == 2) b[1][j] += max(b[0][2], b[0][1]);
            
        }
        for (int j = 0; j < 3; j++) {
            swap(a[0][j], a[1][j]);
            swap(b[0][j], b[1][j]);
        }
    }
    cout << max(max(b[0][0], b[0][1]), b[0][2]) << " " << min(min(a[0][0], a[0][1]), a[0][2]);
}
/*
vector<int> dp;
int n;
void d(int s, int a) {
    if (s <= n) {
        if (dp[s + 1] != -1) {
            dp[s + 1] = !a;
            d(s + 1, !a);
        }
        if (dp[s + 3] != -1) {
            dp[s + 3] = !a;
            d(s + 3, !a);
        }
        if (dp[s + 4] != -1) {
            dp[s + 4] = !a;
            d(s + 4, !a);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    dp.resize(n + 6);
    d(0, 1);
    cout << (dp[0]!=dp[n]?"CY":"SK");
}
/*
int a[1000][1000];
int main() {
    int  r, c;
    cin >> r >> c;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (j == 1 || i == 1)
                a[i][j] = 1;
            else
                a[i][j] = a[i - 1][j] % 10007 + a[i][j - 1] % 10007;
        }
    }
    cout << a[r-c+1][c+1] % 10007;
}

/*
int main() {
    int n, q, u, v;
    cin >> n >> q >> u >> v;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for(Int i=)
}
/*
int n, m, maxl;
vector<vector<int>> v, dp;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.resize(n + 1, vector<int>(m + 1, 0)), dp.resize(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    dp[1][1] = v[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i + 1 <= n && j <= m)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + v[i + 1][j]);
            if (i <= n && j + 1 <= m)
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + v[i][j + 1]);
           }
    }
    cout << dp[n][m];
}
/*
int main() {
    int n, maxl;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << maxl;
}
/*
int main() {
    int n, maxl=-1000000000;
    cin >> n;
    vector<int> v(n+1), dp(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        dp[i] = dp[i - 1] > 0 ? dp[i - 1] + v[i] : v[i];
        maxl = max(maxl, dp[i]);
    }
    cout << maxl;
}
/*
vector<vector<int>> a(1001, vector<int>(3));
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 3; j++){
            cin >> a[i][j];
            if (j == 0) a[i][j] += min(a[i - 1][1], a[i - 1][2]);
            else if (j == 1) a[i][j] += min(a[i - 1][0], a[i - 1][2]);
            else a[i][j] += min(a[i - 1][0], a[i - 1][1]);
        }
    }
    cout << min(min(a[n][0], a[n][1]), a[n][2]);
}

/*
int ans;
void d(int s, int a) {
    if (s == 3) {
        ans = a;
        return;
    }
    if (s == 1) {
        ans = a;
        return;
    }
    d(s - 1, !a);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    d(n, 1);
    cout << (ans == 1 ? "SK" : "CY");
}
/* 11053
vector<pair<long long int, long long int>> dp(41);
pair<long long int,long long int> fibonacci(int n) {
    if (n == 0) {
        dp[n].first = 1;
        return dp[n];
    }
    else if (n == 1) {
        dp[n].second = 1;
        return dp[n];
    }
    else {
        if (dp[n].first == 0 && dp[n].second == 0) {
            pair<long long int, long long int> dp1, dp2 ;
            if (dp[n - 1].first == 0 && dp[n - 1].second == 0) dp1 = fibonacci(n - 1);
            else dp1 = dp[n - 1];
            if (dp[n - 2].first == 0 && dp[n - 2].second == 0) dp2 = fibonacci(n - 2);
            else dp2 = dp[n - 2];
            dp[n] = { dp1.first + dp2.first, dp1.second + dp2.second };
        }
        return dp[n];
    }
}
int main() {
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        fibonacci(n);
        cout << dp[n].first << " " << dp[n].second << "\n";
    }
}
/*
int main() {
    int n, k, maxl;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

}
/*
string str;
int ans, n, ch;
vector<string> v;
vector<int> dp;
int f(int e) {
    bool ret = false;
    if (e == str.size()) {  return 1; }
    if (dp[e] != -1) return dp[e];
    for (string i : v) {
        for (int j = 0; j < i.size(); j++) {
            if (str.size() < i.size() + e || str[e+j] != i[j]) break;
            if(j==i.size()-1) ret |= f(e + i.size());
        }
    }
    return dp[e] = ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> str >> n;
    v.resize(n), dp.resize(str.size()+1, -1);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << f(0);
}
/*
queue<pair<int, int>> q;
string str;
int ans, n, sizeS, ch;
vector<pair<string, int>> v;
void f(pair<string, int> s) {
    if (s.first == str && ans ) { ans = 1; return; }
    for (pair<string, int> i : v) {
        if (s.second + i.second <= sizeS) {
            f(make_pair(s.first + i.first, s.second + i.second));
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> str >> n;
    v.resize(n);
    sizeS = str.size();
    for (int i = 0; i < n; i++) cin >> v[i].first, v[i].second = v[i].first.size();
    for (pair<string, int> i : v)  f(i);
    cout << ans;
}
/*
void h(int a, int b, int c, int d) {
    if(a == b) 
    h()
}
int main() {
    int k;
    cin >> k;
    cout << q.size() << "\n";
    while (!q.empty()) {
        cout << q.front().first << " " << q.front().second << "\n";
    }
}
/*
vector<vector<char>> v;
void draw(int s, int e) {
    for (int i = s; i < s + 3; i++) {
        for (int j = e; j < e + 3; j++) {
            if (i != j) v[i][j] = '*';
        }
    }
}
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j];
        }
    }
}
/*

/*
int d(int s, int e) {
    for (int i = s + (e - s)/3; i< i++) {
    }
}
int main() {
    int n;
    while (cin >> n) {
        cin >> n;
        vector<char> v(n+1);
        for (int i = 0; i < pow(3,n); i++) v[i] = '-';
        d(0, pow(3, n));
        for (int i = 0; i < pow(3, n); i++) cout << v[i];
    }
/*
int ans;
void d(int s, int a) {
    if (s == 3) { 
        ans = a;
        return;
    }
    if (s == 1) {
        ans = a;
        return;
    }
    d(s-1, !a);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    d(n, 1);
    cout << (ans==1?"SK":"CY");
}

    /*

    /*i
    */
/*
int main() {
    int q, x, y;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        if (x == 0 && y == 0) cout << 0 << "\n";
        else if (x == y) cout << 1 << "\n";
        else if (x > 0 && y == 0) cout << 0 << "\n";
        else if (x == 0 && y != 0) cout << 1 << "\n";
        else if (x < 0 && y == 0) cout << 1 << "\n";
        else if (x > 0 && y != 0) cout << 1 << "\n";
        else if (x < 0 && y != 0) cout       << 1 << "\n";
        else cout << 2 << "\n";
    }
}/*
int main() {
    int n;
    cin >> n;
    string str1 = "So Lucky", str2 = "So Lucky";
    vector<int> va(n + 1), vb(n + 1);
    for (int i = 0; i < n; i++) cin >> va[i], vb[i] = va[i];

    for (int i = 0; i < n - 1; i++) {
        if ((va[i] + va[i + 1]) % 2 == 1 && va[i + 1] < va[i]) swap(va[i], va[i + 1]);
        if ((vb[i] + vb[i + 1]) % 2 == 0 && vb[i + 1] < vb[i]) swap(vb[i], vb[i + 1]);
    }
    for (int i = 1; i < n; i++) {
        cout << va[i] << " " << vb[i] << "\n";
        if (va[i] < va[i - 1]) str1 = "Unlucky";
        if (vb[i] < vb[i - 1]) str2 = "Unlucky";
    }
    cout << str1 << "\n" << str2;
}
/*
long long int m, x, a, s, xo;
int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (a == 1) cin >> x, xo^=x, s += x;
        if (a == 2) cin >> x, s -= x, xo ^= x;
        if (a == 3) cout << s << "\n";
        if (a == 4) cout << xo << "\n";
    }
}
/*
int main() {
    int n;
    cin >> n;
    string str1 = "So Lucky", str2 = "So Lucky";
    vector<int> va(n + 1), vb(n + 1);
    for (int i = 0; i < n; i++) cin >> va[i], vb[i] = va[i];

    for (int i = 0; i < n - 1; i++) {
        if ((va[i] + va[i + 1]) % 2 == 1 && va[i+1] < va[i]) swap(va[i], va[i + 1]);
        if ((vb[i] + vb[i + 1]) % 2 == 0 && vb[i + 1] < vb[i]) swap(vb[i], vb[i + 1]);
    }
    for (int i = n-2; i >=0; i--) {
        if ((va[i] + va[i + 1]) % 2 == 1 && va[i + 1] < va[i]) swap(va[i], va[i + 1]);
        if ((vb[i] + vb[i + 1]) % 2 == 0 && vb[i + 1] < vb[i]) swap(vb[i], vb[i + 1]);
    }
    for (int i = 0; i < n - 1; i++) {
        if ((va[i] + va[i + 1]) % 2 == 1 && va[i + 1] < va[i]) swap(va[i], va[i + 1]);
        if ((vb[i] + vb[i + 1]) % 2 == 0 && vb[i + 1] < vb[i]) swap(vb[i], vb[i + 1]);
    }
    for (int i = 1; i < n; i++){
        cout << va[i] << " " << vb[i] << "\n";
        if (va[i] < va[i - 1]) str1 = "Unlucky";
        if (vb[i] < vb[i - 1]) str2 = "Unlucky";
    }
    cout << str1 << "\n" << str2;
}
/*
long long int m, x, a, s;
int main() {
    cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (a == 1) cin >> x, v.push_back(x), s += x;
        if (a == 2) cin >> x; s -= x;
        if (a == 3) cout << s << "\n";
        if(a==4) {
            long long xo = 0;
            for(long long int i : v) xo ^= i;
            cout << xo << "\n";
        }
    }
}
/*
int x, y, n, x1, x2, y1, y2, ans = INT_MAX;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
vector<vector<pair<int, int> > > v;
vector<int> p(3000);
int main() {
    for (int i = 2; i <= 3000; i++) {
        if (p[i] == 0) {
            for (int j = i * 2; j <= 3000; j += i) {
                if (p[j] == 0) p[j] = 1;
            }
        }
    }
    p[1] = 1;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    v.resize(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v[1].push_back({ x, y });
    }
    pq.push({ 0, w });
    while (!pq.empty()) {
        int k = pq.top().second, f = pq.top().first;
        pq.pop();
        if (ans[k] >= f) {
            for (int i = 0; i < v[k].size(); i++) {
                int K = v[k][i].first, F = f + v[k][i].second;
                if (F < ans[K]) pq.push({ F, K }), ans[K] = F;
            }
        }

    }
    cout << ans << "\n";
}
/*
int main() {
    int n, m, q, a, c, v;
    cin >> n >> m >> q;
    vector<vector<int>> g(n+1, vector<int>(m+1));
    for (int i = 0; i < q; i++) {
        cin >> a >> c >> v;
        if (a == 1) g[c-1][m] += v;
        if (a == 2) g[n][c-1] += v;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[n][j]+g[i][m] << " ";
        }
        cout << "\n";
    }
}
/*
int main() {
    int q, x, y;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        if (x == 0 && y == 0) cout << 0 << "\n";
        else if (x == y) cout << 1 << "\n";
        else if (x < 0 && y < 0) cout << 2 << "\n";
        else if (y == 0 && x > 0) cout << 0 << "\n";
        else if (x == 0 && y != 0) cout << 1 << "\n";
        else if (x < 0 && y == 0) cout << 1 << "\n";
        else if (x > 0 && y > 0) cout << 1 << "\n";
        else if (x > 0 && y < 0) cout << 1 << "\n";
    }
}
/*
using namespace std; // MAYBE NYPC
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long int k, n, minl=LLONG_MAX, s=0;
    cin >> n >> k;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<long long int> p(n + 1, 0);
    for (int i = 0; i < n; i++) p[i + 1] = p[i] + v[i];
    for (int i = 0; i <= n - k; i++) {
        long long int m = i + k / 2;
        long long int l = v[m]*(m-i)-p[m]+p[i], r = p[i+k]-p[m+1]-v[m]*(i+k-1-m);
            minl =  min(minl, l + r);
    }
    cout << minl;
}
/*
int n, m, s;
int main() {
    cin >> n >> m;
    vector<int> v(n*2);
    for (int i = 0; i < n * 2; i++) cin >> v[i];
    

    cout << s;
}
/*
int main() {
    int n, s, m, k, t, c = 0, p[2001] = { 0 }, a[2001]={0}, f = 0;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) { cin >> k >> t; if (t && c >= s) { p[k] = 1; } else c++; }
    for (int i = 1; i <= n; i++) if (p[i]) cout << i << "\n", f=1;
    if (!f) cout << -1;
} 
/*
int main() {
    int n, k, s = 0, maxl = INT_MIN;
    cin >> n >> k;
    vector<int> v(n+1, 0);
    for (int i = 1; i <= n; i++) { cin >> v[i]; s += v[i]; if (i >= k) { s -= v[i - k]; maxl = max(s, maxl); } }
    cout << maxl;
}
/*
int main() {
    int n, m, k, a, b, c, d;
    cin >> n >> m;
    vector<vector<int>> v;
    v.resize(n + 1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            v[i][j] +=  + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> c >> d;
        cout << v[c][d] -v[a-1][d] - v[c][b-1] + v[a - 1][b-1] << "\n";
    }
}
/*
int main() {
    int n;
    cin >> n;
    vector<int> v(n+1), a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        a[i] = v[i]-v[i - 1];
    }
   
}
/*
long long int s,  n, k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1, j = n; i <= k; i++, j--) {
        s += j*i-i+1;
        cout << s << "\n";
    }
    cout << s;
}
/*
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
int main() {
    int n, s = 0, cnt = 1;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i], pq.push({ v[i], i + 1 });
    while (!pq.empty()) {
        pair<int, int> k = pq.top();
        pq.pop();
        if (k.first != cnt) { s += k.second; }
        cnt++;
    }
    cout << s;
}
/*
int n, s, c;
int main() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        s += v[i];
        if (s < 0) {
            int m=0, mj;
            for (int j = 0; j <= i; j++) {
                if (m > v[j]) m = v[j], mj = j;
            }
            s-=v[mj], v[mj] = 0, c++;
        }
    }
    cout << c;
}
/*
int c, n;
void f(int s) { if (n) { while (!(s % 10)) s /= 10, c++; f(s * --n); } };
int main() { cin >> n, f(n), cout << c;}
/*
vector<vector<int>> visited, graph;
vector<pair<int, int>> v, vi;
queue<pair<int, int>> q;
int n, m, maxl, dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
int BFS() {
    int cnt = 0;
    while (!q.empty()) {
        pair<int, int> k = q.front();
        for (int i = 0; i < 4; i++) {
            int x = k.first + dx[i], y = k.second + dy[i];
            if (0 <= x && x < n && 0 <= y && y < m) {
                if (!visited[x][y] && graph[x][y] == 0) {
                    q.push({ x, y });
                    visited[x][y] = 1;
                    cnt++;
                }
            }
        }
        q.pop();
    }
    return v.size() - cnt - 3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    graph.resize(n + 1, vector<int>(m + 1));
    visited.resize(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) v.push_back({ i, j });
            if (graph[i][j] == 2) vi.push_back({ i, j });
        }
    }
    cout << v.size() << "  ";
    vector<int> s(v.size(), 0);
    for (int i = 0; i < 3; i++) s[i] = 1;
    do {
        vector<pair<int, int>> p;
        q = queue<pair<int, int>>();
        for (int i = 0; i < v.size(); i++) if (s[i]) p.push_back(v[i]);
        for (pair<int, int> a : p) { graph[a.first][a.second] = 1; }
        for (pair<int, int> a : vi) { q.push({ a.first, a.second }); }
        maxl = max(maxl, BFS());
        visited.assign(n + 1, vector<int>(m + 1, 0));
        for (pair<int, int> a : p) { graph[a.first][a.second] = 0; }
    } while (prev_permutation(s.begin(), s.end()));
    cout << maxl;
}
/*
int main() {
    int n=1, sum = 0;
    string str;
    stack<char> stk;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[') stk.push(str[i]);
        if (i + 1 == str.size() || str[i + 1] == '[' || str[i + 1] == '(') {
            if (str[i] == ']') {
                if (stk.top() == '(') { cout << 0; return 0; }
                stk.pop();
                n *= 3;
            }
            else {
                if (stk.top() == '[') { cout << 0; return 0; }
                stk.pop();
                n *= 2;
            }

        }
        else {
            sum += n;
            n = 1;
        }
    }
    if (!stk.empty()) cout << 0;
}
/*
int t, n;
int getB(int i) {
}   
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int i = n, j = 0; i > 0; i /= 10, j++) {
                getB(i % 10);
            }
        }
    }

}
/*
int n, m, a, b, c;
char ch;
string str;
int main() {
    cin >> n >> m;
    cin >> str;
    for (int i = 0; i < m; i++) {
        cin >> a >> ch >> b >> c;
    }
}
/*
int n, k, a, root, pre, j, sum;
vector<vector<int>> v;
vector<int> t;
vector<pair<int, int>> p;
void dfs(int s, int cnt) {
    for (int i = 0; i < v[s].size(); i++) {
        p[v[s][i]].second = cnt + 1;
        dfs(v[s][i], cnt + 1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0) break;
        v.resize(1000001), t.resize(n + 1), p.resize(1000001);
        pre = 0, j = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> t[i];
            if (i == 1) root = t[i];
            else if (t[i] - pre == 1) v[t[j]].push_back(t[i]);
            else v[t[++j]].push_back(t[i]);
            p[t[i]].first = t[j];
            pre = t[i];
        }
        dfs(t[1], 1);
        for (int i = 1; i <= n; i++) {
            if (p[k].second == p[t[i]].second && p[p[k].first].first == p[p[t[i]].first].first && p[k].first != p[t[i]].first) {
                sum++;
            }
        }
        cout << sum << "\n";
        v.clear(), t.clear(), p.clear();
    }
}
/*
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, t, a, b, c;
    cin >> n >> t;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        for (int j = 0; j < c; j++) {
            v.push_back(a + b * j);
        }
    }
    sort(v.begin(), v.end());
    int left = 0, right = v.size() - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (v[mid] == t) {
            cout << 0;
            return 0;
        }
        else if (v[mid] > t) right = mid - 1;
        else  left = mid + 1;
    }
    auto it = lower_bound(v.begin(), v.end(), t);
    if (it == v.end()) cout << -1;
    else cout << *it - t;
}
/*
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ans(n+1);
    stack<int> stk;
    string v; cin >> v;
    for (int i = n-1; i >= 0; i--) {
        if (stk.size() < n - m) stk.push(v[i]-48), ans[stk.size()-1]=v[i]-48;
        else if (stk.top() < v[i]-48) stk.pop(), stk.push(v[i]-48), ans[stk.size()-1] = v[i]-48;
    }
    for (int i = n-1; i>=0; i--) {
        if (ans[i]) cout << ans[i];
    }

}
/*

vector<long long int> v(20000001), arr(20000001);
long long int n, m, a, b, ans;
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a]++;
    }
    for (int i = 1; i <= n; i++) {
        v[arr[i]]++;
    }
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            cout << ans;
            break;
        }
        else {
            if (v[i] >= 2) v[i + 1] += v[i] - 1, ans += v[i] - 1;
        }
    }
}
/*
int n, m, k, cnt, cnt2, sum, dx[] = { 0, 0, 1, -1 }, dy[] = { 1,-1,0,0 };
vector<vector<int>> v, visited;
void dfs(int x, int y) {
    cnt2++;
    for (int i = 0; i < 4; i++) {
        if (0 <= x + dx[i] && x + dx[i] < n && 0 <= y + dy[i] && y + dy[i] < m) {
            if (!visited[x + dx[i]][y + dy[i]]) {
                v[x + dx[i]][y + dy[i]] = cnt;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    v.resize(n, vector<int>(m, 0)), visited.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x-1][y-1] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!v[i][j]) {
                cnt++;
                cnt2 = 0;
                dfs(i, j);
                sum += cnt2 * cnt2;
            }
        }
    }
    cout << sum;
}
/*
vector<long long int> v(2000001), arr(2000001);
long long int n, m, a, b, ans;
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a]++;
    }
    for (int i = 1; i <= n; i++) {
        v[arr[i]]++;
    }
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            cout << ans;
            break;
        }
        else {
            if (v[i] >= 2) v[i + 1] += v[i] - 1, ans += v[i] - 1;
        }
    }
}
/*

/*
int  a, b;
int arr[500][500], visited[500][500];
int main() {
    cin >> a >> b;
    if ((a * b) % 2 == 1) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++){
            if (visited[i][j]== 0) {
                if (j <= b-2) {
                    int t = arr[i][j];
                    arr[i][j] = arr[i][j + 1];
                    arr[i][j + 1] = t;
                    visited[i][j] = 1;
                    visited[i][j+1] = 1;

                }
                else {
                    swap(arr[i][j], arr[i + 1][j]);

                    visited[i][j] = 1;
                    visited[i+1][j] = 1;
                }
            }
         }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout<< arr[i][j] << " ";
        }
        cout << "\n";
    }


}
/*
//int main() {
//    int n, m;
//    int a, b;
//    int arr[200000];
//    cin >> n >> m;
//    for (int i = 0; i < m; i++) {
//        cin >> a >> b;
//        arr[a]++;
//    }
//
//}
/*

/*
int main() {
    long long int n, a, first, minl=1000000, maxl=0, mini, maxi;
    cin >> n;
    string str="hard";
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        if(minl>a)minl = a, mini = i;
        if (maxl < a) maxl = a, maxi = i;
    }
    if (mini == 0) {
        cout << "ez";
    }
    else if (maxi == 0) {
        cout << "hard";
    }
    else cout << "?";
}
/*
int n, sum, minl;
string str;
vector<int> r, c;
void getRes(int s) {
    if (s == n + 1) {
        int sum = 0;
        for (int i = 1; i <= 1 << (n - 1); i *= 2) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (r[j] & i) cnt++;
            }
            sum += min(cnt, n - cnt);
        }
        minl=min(minl, sum);
        return;
    }
    getRes(s + 1);
    r[s] = ~r[s];
    getRes(s + 1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    r.resize(n + 1, 0), c.resize(n + 1, 0);
    cout << "    ";
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if (str[i] == 'T') r[i]++;
            if (j != str.size() - 1) r[i] = 1 << r[i];
        }
    }
    getRes(1);
    cout << minl;
}
/*
int n, m, dx[] = { 0, 1, 1 }, dy[] = { 1, 1, 0 }, maxl;
vector<vector<int>> v;
vector<int> cnt(5);

void make(int i, int j, int c) { v[i][j] = 1; if(c==2||c==4) v[i + 1][j] = 2; if (c == 3||c==4) v[i][j + 1] = 3; if(c==4) v[i + 1][j + 1] = 4; }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.resize(n + 1, vector<int>(m + 1));
    cnt[1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                if (n - i >= 2 && m - j >= 2) make(i, j, 4), cnt[2] = 1, cnt[3] = 1, cnt[4] = 1;
                else if (n - 1 - i >= 1 && m - j - 1 >= 0) make(i, j, 2), cnt[2] = 1;
                else if (n - 1 - i >= 0 && m - j - 1 >= 1) make(i, j, 3), cnt[3] = 1;
                else if (n - 1 - i >= 0 && m - j - 1 >= 0)make(i, j, 1);
            }
        }
    }
    for (int i = 1; i <= 4; i++) maxl += cnt[i];
    cout << maxl << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

/*
long long int n, k, s, maxl;
vector<long long int> v;
bool good(long long int x) {
    long long int t = 0;
    for (long long int cnt : v) {
        if (cnt > x) t += cnt - x;
        if (t > k) return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; ++i) cin >> v[i], maxl = max(maxl, v[i]);
    long long int l = 0, r = maxl, ans = maxl;
    while (l <= r) {
        long long int m = (l+r)/2;
        if (good(m)) ans = m,r = m - 1;
        else l = m + 1;
    }
    cout << ans << '\n';
    return 0;
}
/*

/*
using namespace std;
int n, k, l, r, ans;
vector<int> v;
int main() {
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    l = 0, r = n - 1;
    sort(v.begin(), v.end());
    while (l < r) {
        if (v[l] + v[r] <= k) ans++, l++, r--;
        else r--;
    }
    cout << ans;
}
/*
using namespace std;
int main() {
    long long int n, a=1, ans;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a *= i;
    }
    cout << a / 60 / 60 / 24 / 7;
}

/*
int main() {
    int n, a;
    cin >> n;
    vector<int> uv(n), dv(n);
    string ans(n, '0');
    long long use = 0, ds = 0;

    for (int i = 0; i < n; i++) cin >> uv[i];
    for (int i = 0; i < n; i++) {
        cin >> dv[i];
        ds += (dv[i] != -1) ? dv[i] : 0;
    }

    for (int i = 0; i < n; i++) {
        if (ds < use) break;
        if (dv[i] != -1) ds -= dv[i];

        if (uv[i] != -1 && uv[i] <= ds - use) {
            ans[i] = '+';
            use += uv[i];
        }
        else if (dv[i] != -1 &&  ds < use) {
            ans[i] = '-';
            use -= dv[i];
        }
        else {
            ans[i] = '0';
        }
    }

    cout << ans << '\n';
}

/*
int n, k, x, y, z, sum=1000000000, atked;
map<int, vector<pair<int, int>>> row, col;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> x >> y >> z;
        row[x].emplace_back(max(1, y-z), min(n, y + z));
        col[y].emplace_back(max(1, x - z), min(n, x + z));
    }

    
    cout << n * n - atked;
}
/*
int main() {
    int cnt=0;
    string str, f;
    getline(cin, str);
    getline(cin, f);
    for (int i = 0;;) {
        if(str.find(f, i) != string::npos)
            cnt++,   i = str.find(f, i) + f.size();
        else break;
    }
    cout << cnt;
}
/*
int main() {d
    int n, t;  string str, ans;
    cin >> t;
    while (t--) {
        cin >> n >> str;
        for (char c : str) { for (int i = 0; i < n; i++) cout << c; }
        cout << "\n";
    }
}
/*
int main(){
    vector<int> v(27, -1);
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (v[str[i] - 97] == -1) v[str[i] - 97] = i;
    }
    for (int i : v) cout << i << " ";
}
/*
int main() {
    string str;
    getline(cin, str);
    int sum = count(str.begin(), str.end(), ' ') + 1;
    if (str[0] == ' ') sum--;
    if (str[str.size()-1] == ' ') sum--;
    cout << sum;
}
/*
int main() {
    int s = 0, n;
    string str;
    cin >> n >> str;
    for (char c : str) { s += int(c)-48; }
    cout << s;
}
/*
int main() {
    string str;
    cin >> str;
    cout << str << "\n";
    cout << str.size() << "\n";
    string r;
    r.resize(str.size());
    reverse_copy(str.begin(), str.end(), r.begin());
    cout << r;
    vector<char> v = ;
}
/*
long long int n, k, sum, a, b;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    vector<pair<int, int>> jw(n);
    vector<int> bg(k);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> jw[i].first >> jw[i].second;
    }
    for (int i = 0; i < k; i++) cin >> bg[i];
    sort(jw.begin(), jw.end());
    sort(bg.begin(), bg.end());
    int j = 0;
    for (int i = 0; i < k; i++) {
        while (j < n && jw[j].first <= bg[i]) { pq.push(jw[j].second), j++;}
        if(!pq.empty()) sum += pq.top(), pq.pop();
    }
    cout << sum;

}
/*
int n, c=1;
int main() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    // 1 1 2 3 6 7 30
    for (int i = 0; i < n; i++) {
        if(c < v[i]) {
            break;
        }
        c+=v[i];

    }
    cout << c;

}
/*
vector<int> v;
int main() {
    int n;
    cin >> n;
    v.resize(n + 1);
    v[1] = 1, v[2] = 2;
    for (int i = 3; i <= n; i++) {
        v[i] = (v[i - 1] % 10 + v[i - 2] % 10) % 10;
    }
    cout << v[n];
}
/*
int main() {
    int n, c=0;
    cin >> n;
    while (n >= 0) {
        if (n % 5 == 0)     {
            c += n / 5;
            
            cout << c;
            return 0;
        } 
        n -= 2;
        c++;
    }
    cout << -1;
}
/*
int main() {
    int n;
    vector<long long int> v(46);
    int n; 
    v[0] = 0, v[1] = 1;
    cin >> n;
    for (int i = 2; i <= n; i++) v[i] = v[i - 1] + v[i - 2];
    cout << v[n];
}
/*
int t, k, n;
int main() {
    cin >> t;
    vector<vector<int>> v(16, vector<int>(16));
    for (int i = 0; i < 15; i++) {
        for (int j = 1; j <= 15; j++) {
            if (i == 0) v[i][j] = j;
            else {
                v[i][j] += v[i - 1][j] + v[i][j-1];
            }
        }
    }
    while (t--) {
        cin >> k >> n;
        cout << v[k][n] << "\n";
    }
}
/*
int main() {
    vector<long long int> v(46);
    int n; 
    v[0] = 0, v[1] = 1;
    cin >> n;
    for (int i = 2; i <= n; i++) v[i] = v[i - 1] + v[i - 2];
    cout << v[n];
}
/*
bool compare(pair<int, int> a, pair<int, int> b) {return a.first > b.first;}
bool compare2(int a, int b) { return a > b; }
int n, k, sum, a, b;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    vector<int> s(k);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i].first = b, v[i].second = a;
    }
    for (int i = 0; i < k; i++) cin >> s[i];
    sort(v.begin(), v.end(), compare);
    sort(s.begin(), s.end(), compare2);
    int j = k-1;
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < k; l++) { if (v[i].second <= s[l] && s[l] ) { sum += v[i].first; j--; s[l] = 0;  break; } }
        if (j == -1) break;
        //cout << v[i].second << "  " << s[j] << "\n";
        
    }
    cout << sum;

}
/*
int n, m, sum1, sum2;
int getdiff(string s1, string s2) { int cnt = 0;  for (int i = 0; i < m; i++) if (s1[i] != s2[i]) cnt++; return cnt; }
int main() {
    string s="WBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWB", s2="BWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBW", str;
    cin >> n >> m;
    while (n--) cin >> str, sum1 += getdiff(n % 2 ? s2 : s, str), sum2+=getdiff(n%2?s:s2, str);
    cout << min(sum1, sum2);
}
/*
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n); string s = "YES";
        for (int i = 0; i < n; i++) cin >> v[i];
         v[0] = min(v[0], n - v[0] + 1);
        for (int i = 1; i < n; i++) { 
            if (min(v[i], n - v[i] + 1) >= v[i - 1]) v[i] = min(v[i], n - v[i] + 1);
            else if(max(v[i], n - v[i] + 1) >= v[i - 1]) v[i] = max(n - v[i] + 1, v[i]);
            else { s = "NO"; break; }
        }
         cout << s << "\n";
    }
}
/*
int main() {
    int b, s=0; string n;
    cin >> n >> b;
    for (int i = 0; i < n.size(); i++) s += (n[i] <= '9' ? n[i] - '0' : n[i] - 'A' + 10) * pow(b, n.size() - i - 1);
    cout << s;
}
/*
int n, c;
string s;
vector<int> cnt(27);
int main() {
    cin >> n;
    while (n--) cin >> s, cnt[s[0] - 97]++;
    for (int i = 0; i < 26; i++) if (cnt[i] >= 5) { cout << char(i + 97);  c++; }
    if(!c)cout << "PREDAJA";
}
/*
int n, m, t, a;
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        queue<pair<int, int>> q;
        vector<int> v(10);
        int b=1, cnt = 0;
        for (int i = 0; i < n; i++) cin >> a, q.push({a, i}), v[a]++, b=max(b, a);
        while (!q.empty()) {
                cout << q.front().first << "  " << q.front().second << "\n";
            if (q.front().first == b) {
                v[b]--;
                for (int i = 9; i >= 1; i--) { if (v[i]) b = i; break; }
                cnt++;
                if (q.front().second == m) { cout << cnt << "\n"; break;}
                q.pop();
            }
            q.push(q.front());
            q.pop();
        }
    }
    
}
/*
int main() {
    int n, sum=1;
    string str;
    cin >> n >> str;
    if (str[n - 1] == 'W') sum = 0;
    for (int i = 1; i < n; i++) {
        if (str[i-1] == 'E' && str[i] == 'W') sum++;
    }
    cout << sum;
}
/*
double n, m;
int main() {
    cin >> n >> m;
    cout << (abs(n / m - 1) * 2);
}
/*
int main() {
    int n, t, s=0, d=2;
    cin >> n >> t;
    pair<int, int> c = { 0, 0 };
    vector<pair<int,string>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        int m = v[i].first - s;
        s = v[i].first;
        if (d == 0) c.first-= m;
        if (d == 1) c.second += m;
        if (d == 2) c.first += m;
        if (d == 3) c.second -= m;

        if (v[i].second == "right") d = (d + 1) % 4;
        if (v[i].second == "left") d = (d - 1)<0?3:d-1;

    }

    if (d == 0) c.first -= t-s;
    if (d == 1) c.second += t-s;
    if (d == 2)c.first += t-s;
    if (d == 3) c.second -= t-s;
    cout << c.first << " " << c.second << "\n";
}
/*
int main() {
    float n, a, b;
    float bmi;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        float bmi = b / (a / 100) / (a / 100);
        if (a >= 204) printf("4\n");
        else if (a >= 161) {
            if (20 <= bmi && bmi < 25) printf("1\n");
            else if ((18.5 <= bmi && bmi < 20) || (25 <= bmi && bmi < 30)) printf("2\n");
            else if ((16 <= bmi && bmi < 18.5) || (30 <= bmi && bmi < 35)) printf("3\n");
            else if (bmi < 16 || 35 <= bmi) printf("4\n");
        }
        else if (a >= 159) {
            if (16.5 <= bmi && bmi < 35) printf("3\n");
            else if (bmi < 16 || 35 <= bmi) printf("4\n");
        }
        else if (a >= 146) printf("4\n");
        else if (a >= 140.1) printf("5\n");
        else printf("6\n");
    }
}
/*
int main() {
    int n, sum = 0;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        sum += str.length();
    }
    cout << sum;
}
/*

/*
int n, a, minl = -1, sum;
vector<int> v;
vector<vector<int>> d;
void dfs(int s, int suma, vector<int> visited, int cnt) {
    visited[s] = 1;
    //끊어져 있으면 -> 찾는 방법?
    
    cout << "\n";
    for (int i : d[s]) {
        if (!visited[i] && !i) {
            visited[i] = 1;
            dfs(i, suma + v[i], visited, cnt+1);
        }
    }
}
int main() {
    cin >> n;
    v.resize(n+1), d.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i], sum+=v[i];
    for (int i = 1; i <= n; i++) {
        cin >> a;
        d[i].resize(n+1);
        for (int j = 0; j < a; j++) cin >> d[i][j], cout << d[i][j] << " ";
    }
    for (int i = 1; i <= n; i++) {
        dfs(i, 0, vector<int>(n+1), 1);
    }
    cout << minl;
}
/*
bool compare(pair<int, int> a, pair<int, int> b) {
    if() v[i
}
int n, k, sum;
int main() {
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    vector<int> s(k);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < k; i++) cin >> s[i];
    sort(v.begin(), v.end());
    sort(s.begin(), s.end());
    int j = k-1;
    for (int i = n - 1; i >= 0; i--) {
        if (j == 0) break;
        if (v[i].first <= s[j]) sum += v[i].second, j--;
    }
    cout << sum;

}
/*
int n, m, dx[] = { 0, 0, 1, -1 }, dy[] = { 1,-1,0,0 };
int main() {
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                if (0 <= i + dx[k] && i + dx[k] <= n && 0 <= j + dy[k] && j + dy[k] <= m && v[i][j] > v[i + dx[k]][j + dy[k]]) {
                    if(i+dx[k]== n-1 && j+dy[k]==m-1) 
                }
            }
        }
    }
}
/*
vector<int> p;
vector<pair<long long int, int>> vx, vy, vz;
vector<tuple<long long int, int, int>> planet, v;
bool compare1(pair<int, int> a, pair<int, int> b) {
    return abs(a.first) > abs(b.first);
}
long long int n, x, y, z, sum, cnt;
int find(int a) {
    if (a == p[a]) return a;
    return p[a] = find(p[a]);
}
int main() {
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        planet.push_back(make_tuple(x, y, z));
        vx.push_back({ x, i }), vy.push_back({ y, i }), vz.push_back({ z, i });
    }
    sort(vx.begin(), vx.end(), compare1), sort(vy.begin(), vy.end(), compare1), sort(vz.begin(), vz.end(), compare1);
    for (int i = 0; i < n - 1; i++) {
        v.push_back(make_tuple(abs(vx[i].first - vx[i + 1].first), vx[i].second, vx[i + 1].second));
        v.push_back(make_tuple(abs(vy[i].first - vy[i + 1].first), vy[i].second, vy[i + 1].second));
        v.push_back(make_tuple(abs(vz[i].first - vz[i + 1].first), vz[i].second, vz[i + 1].second));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        int start = get<1>(v[i]), end = get<2>(v[i]), value = get<0>(v[i]);
        if (find(start) != find(end)) {
            p[find(end)] = find(start);
            sum += value;
        }
    }
    cout << sum;
}
/*
int n, a, b;
int main() {
    cin >> n;
ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> stk;
    while (n--) {
        cin >> a;
        if (a == 1) cin >> b, stk.push_back(b);
        if (a == 2) { if (!stk.empty()) cout << stk.back() << "\n", stk.pop_back(); else cout << "-1" << "\n"; }
        if (a == 3) cout << stk.size() << "\n";
        if (a == 4) cout << stk.empty() << "\n";
        if (a == 5) cout << (stk.empty() ? -1 : stk.back()) << "\n";
    }
}
/*
int n, a;
string str;
deque<int> dq;
int main() {
    cin >> n;
    while (n--) {
        cin >> str;
        if (str == "push_back") cin >> a, dq.push_back(a);
        if (str == "push_front") cin >> a, dq.push_front(a);
        if (str == "pop_back") {
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.back() << "\n", dq.pop_back();
        }
        if (str == "pop_front") {
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.front() << "\n", dq.pop_front();
        }
        if (str == "size") cout << dq.size() << "\n";
        if (str == "empty") cout << dq.empty() << "\n";
        if (str == "front") cout << (!dq.empty() ? dq.front() : -1) << "\n";
        if (str == "back") cout << (!dq.empty() ? dq.back() : -1) << "\n";

    }
}
/*
int n, a, i, j;
string str;
int main() {
    cin >> n;
    queue<int> q;
    while (n--) {
        cin >> str;
        if (str == "push") {
            cin >> a;
            q.push(a);
        }
        if (str == "pop") {
            if (q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n", q.pop();
        }
        if (str == "size") cout << q.size() << "\n";
        if (str == "empty") cout << q.empty() << "\n";
        if (str == "front") cout << (q.empty()?-1:q.front()) << "\n";
        if (str == "back") cout << (q.empty()?-1:q.back()) << "\n";
    }
}
/*
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    priority_queue<int, vector<int>, greater<int> > pq;
    int n, x, c = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; pq.push(x); }
    for (int i = 0; i < n + n - 2; i++) {
        
        c += pq.top();
        if (i % 2 == 1) sum+=c,pq.push(c), c = 0;
        pq.pop();
    }
    cout << sum;
}
/*
long long int t, n, m, res;
long long int v[31][31];
int main() {
    cin >> t;
    v[0][0] = 1, v[0][1] = 0;
    for(int i=1; i<31; i++) {
        v[i][i] = 1, v[i][0] = 1, v[i][1] = i;
        for (int j = 0; j <= i; j++) v[i][j] = v[i-1][j] +v[i-1][j-1]; 
    }
    while (t--) { cin >> n >> m; cout << v[m][n] << "\n";}
}
/*
int main() {
    int n, i, s, e, sum, min = 2000000001, min1, min2;
    cin >> n;
    vector<int> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    s = 0, e = n - 1;
    while (s < e)
    {
        sum = v[s] + v[e];
        if (abs(sum) < min) min = abs(sum), min1 = v[s], min2 = v[e];
        if (sum == 0) break;
        if (sum < 0) s++;
        else e--;
    }
    printf("%d %d", min1, min2);
}

/*
int main() {
    int t, n, m, d[] = {0, 31, 28, 31,30, 31, 30, 31, 31, 30, 31, 30 ,31};
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (--m == 0) m = 12, n--;
        cout << n << " " << m << " " << ((!(n % 4) && ((n % 100) || !(n % 400)) && m == 2) ? 29 : d[m] )<< "\n";
    }
}
/*
vector<int> p;
vector<tuple<int, int, int>> pv;
int find(int a) {
    if (a == p[a]) return a;
    return find(p[a]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, sum = 0, cnt = 0;
    cin >> n >> m;
    p.resize(n + 1);
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        tuple<int, int, int> a;
        cin >> get<1>(a) >> get<2>(a) >> get<0>(a);
        pv.push_back(a);
    }
    sort(pv.begin(), pv.end());
    for (tuple<int, int, int> a : pv) {
        int s = find(p[get<1>(a)]), e = find(p[get<2>(a)]);
        if (s != e) {
            p[e] = p[s];
            sum += get<0>(a);
            cnt++;
            if (cnt >= n) break;
        }
    }
    cout << sum;
}
/*
int main() {
    long long int n, c, b;
    cin >> n;
    b = n % 10;
    n /= 10;
    c = n % 10;
    n /= 10;
    while (n > 0) {
        if (n % 10 - c != c - b) {
            cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
            return 0;
        }
        b = c;
        c = n % 10;
        n /= 10;
    }
    cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
}
/*
int main() {
    int n;
    string str;
    cin >> n >> str;
    if (str.size() <= 25) cout << str;
    else {

        int ch = false;
        
        for (char c : str.substr(11, str.size() - 23)) {
            if (c == '.') {
                ch = true;
                break;
            }
        }
        if (!ch) {
            cout << str.substr(0, 11) << "..." << str.substr(str.size() - 11) << endl;
        }
        else {
            cout <<str.substr(0, 9) << "......" << str.substr(str.size() - 10) << endl;
        }
    }
}
/*
int main() {
    int n, ch=0;
    string ans = "YES";
    cin >> n;
    vector<int> v(n);
    cin >> v[0];
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        if (v[i - 1] >= v[i]) ch = 1;
        if (ch && v[i-1]<=v[i]) ans = "NO";

    }
    cout << ans;
}
/*

/*
int main() {
    int n;
    scanf("%d", &n);
    for (int i = n; i > 0; i--) {
        if (i == 1) {
            printf("1 bottle of beer on the wall, 1 bottle of beer.\n");
            printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
        }
        else {
            printf("%d bottles of beer on the wall, %d bottles of beer.\n", i, i);
            printf("Take one down and pass it around, %d %s of beer on the wall.\n\n", i - 1, (i - 1 == 1) ? "bottle" : "bottles");
        }
    }
    printf("No more bottles of beer on the wall, no more bottles of beer.\n");
    printf("Go to the store and buy some more, %d %s of beer on the wall.", n, n == 1 ? "bottle" : "bottles");
}
/*
using namespace std;
long long int n, sum;
vector<int> v;
deque<int> d;
int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = n-1; i >=0; i--) {
        if (i % 2 == 0) d.push_back(v[i]);
        else d.push_front(v[i]);
    }
    for (int i = 0; i < n; i++) {
        int q = d.front();
        d.pop_front(), d.push_back(q);
        sum += q * d.front();
    }
    cout << sum << "\n";
    while (!d.empty()) cout << d.front() << " ", d.pop_front();
}
/*
int main() {
    int n, cnt=0;
    cin >> n;
    while (n > 0) {
        int j = 0, sum=0;
        for (int i = n; i > 0; i /= 10) {
            if (i % 10 == 1) cnt++;
            else sum += i % 10 * pow(10, j++);
        }
        n = sum;
        if(n>0)cnt++, n--;
    }
    cout << cnt;
}
/*
int main() {
    int n, c=0;
    cin >> n;
    while (n >= 0) {
        if (n % 5 == 0) {
            c += n / 5;
            cout << c;
            return 0;
        }
        n -= 3;
        c++;
    }
    cout << -1;
}
/*
int main() {
    int n, s, a, b, c=1, sum=0;
    cin >> n >> s >> a;
    while (a--){
        cin >> b;
        if (s < b) sum += b - s, c += b - s, s=b;
        else if (b < c) sum += c - b, s -= c - b, c=b;
    }
    cout << sum;
}
/*
int main() {
    int n, s, sum=0;
    cin >> n;
    for (int i = 0; i < n * 2; i++) cin >> s, sum += abs(s);
    cout << sum;
}
/*
int main() {
    int n, l, k, sum=0;
    cin >> n >> l >> k;
    vector<int>  v(n), v2(n);
    for (int i = 0; i < n; i++) cin >> v[i] >> v2[i];
    sort(v2.begin(), v2.end());
    for (int i = n - 1; i >= 0; i--) {
        if (k&&v2[i] <= l) sum+=140, k--, v2[i]=0;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (k && v2[i] && v[i] <= l) sum += 100, k--;
    }
    cout << sum;
}
/*
int main() {
    int n, cnt=0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] < b[i]) cnt += b[i] - a[i];
    }
    cout << cnt;
}
/*
int main() {
    int t, num, q, d, n, p;
    cin >> t;
    while (t--)
    {
        cin >> num;
        cout << num / 25 << " ";
        num %= 25;
        cout << num / 10 << " ";
        num %= 10;
        cout << num / 5 << " ";
        num %= 5;
        cout << num  << "\n";
    }
}
/*
int main() {
    for (int i = 1; i <= 100; i++) {
        for (int j = 2; j <= i; j++) {
            int cnt = 0;
            for (int k = j; k <= i; k++) {
                for (int l = k; l <= i; l++) {
                    if (j * j * j + k * k * k + l * l * l == i * i * i && !cnt) {
                        cnt++;
                        cout << "Cube = " << i << ", Triple = (" << j << "," << k << "," << l << ")\n";
                    }
                }
            }
        }
    }
}
/*
int main() {
    int a[10], maxl=0, res=0;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 10; i++) {
        if (abs(100 - res) >= abs(100 - maxl)) {
           res = maxl;
        }
        maxl += a[i];
    }
    cout << res;
}
/*
int main() {
    int sum = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        sum += pow(16, (s.length() - i - 1)) * ((('A' <= s[i] && s[i] <= 'Z')? s[i]-55 : s[i]-48));
    }
    cout << sum;
}
/*
int main() {
    int a, b, c, v[81] = { 0 }, maxl=0, r;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                v[i + j + k]++;
                if(maxl<v[i+j+k]) maxl = v[i + j + k], r = i+j+k;
            }
        }
    }
    cout << r;
}
/*
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + (c+b) / 60) % 24 << " " << ((b + c) % 60);
}
/*
int main() {
    int n, f;
    cin >> n >> f;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            if ((n - n % 100 + i * 10 + j) % f==0) {
                cout << i << j;
                return 0;
            }
        }
    }
}
/*

/*
int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    for (int i = 1; ; i++) {
        int cnt = 0;
        if (i % a == 0) cnt++;
        if (i % b == 0) cnt++;
        if (i % c == 0) cnt++;
        if (i % d == 0) cnt++;
        if (i % e == 0) cnt++;
        if (cnt >= 3) { cout << i; break; }
    }
}  
/*
int main() {
    int n, m, mincnt = 64;
    cin >> n >> m;
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 8 < n && j + 8 < m) {
                int cnt = 0;
                for (int i2 = i; i2 < i + 8; i2++) {
                    for (int j2 = j; j2 < j+8; j2++) {
                        if (v[i2 + 1][j2] == v[i2][j2] || v[i2][j2 + 1] == v[i][j]) cnt++;
                    }
                }
            }
        }
    }
    cout << mincnt;
}
/*int main() {
    int n, m, maxl=0;
    cin >> n >> m;
    for (int i = 1; i < m; i++) {
        int r=0, v=n*i;
        while (v > 0) {
            r = (v % 10) + r*10;
            v /= 10;
        }
        maxl = max(r, maxl);
    }
    cout << maxl;
}
/*
int main() {
    int t, k, f;
    cin >> t;
    while (t--) {
        cin >> k;
        string res = "0";
        vector<string> v(k); f = 0;
        for (int i = 0; i < k; i++) cin >> v[i];
        for (int i = 0; i < k && !f; i++) {
            for (int j = 0; j < k; j++) {
                if (i != j) {
                    int ch = 1;
                    string s = v[i] + v[j];
                    for (int l = 0; l < s.size() / 2; l++) {
                        if (s[l] != s[s.size() - l - 1]) ch = 0;
                    }
                    if (ch) { res = s; f = 1; break; }
                }
            }
        }
        cout << res << "\n";
    }
}
/*
int main() {
    int x1, x2, y1, y2, s1, s2;
    cin >> x1 >> y1 >> s1 >> x2 >> y2 >> s2;
    for (int i = -999; i <= 999; i++) {
        for (int j = -999; j <= 999; j++) {
            if (x1 * i + y1 * j == s1 && x2 * i + y2 * j == s2) cout << i << " " << j;
        }
    }
}
/*
int main() {    
    int n, m, c[100] = { 0 }, maxs=0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if(c[i]+c[j]+c[k]<=m) maxs = max(c[i]+c[j]+c[k], maxs);
            }
        }
    }
    cout << maxs;
}
/*
int main() {
    int v[9], sum=0, ch[9];
    for (int i = 0; i < 9; i++) { cin >> v[i], sum += v[i]; ch[i] = 1; }
    for (int i   = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - v[i] - v[j] == 100) ch[i] = 0, ch[j] = 0;
        }
    }
    for (int i = 0; i < 9; i++) if (ch[i]) cout << v[i] << "\n";
}
/*
int t, v[10], d[13] = {0, 31, 29, 31,30, 31, 30, 31, 31, 30, 31, 30, 31 }, cnt = 0;
int check(int n) {
    int a = n;
    while (a > 0) {
        if (v[a % 10]) { return 0; }
        a /= 10;
        if (a == 0) return 1;
    }
    return v[n] == 0;
}
int main() {
    cin >> t;
    while (t--) {
        cnt = 0;
        for (int i = 0; i < 10; i++) cin >> v[i];
        for (int i = 1; i <= 12; i++) {
            if (check(i)) {
                for (int j = 1; j <= d[i]; j++) {
                    cnt += check(j);
                }
            }
        }
        cout << cnt << "\n";
    }
}
/*
int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t = i;
        while (t > 0) {
            if (t % 10 == 3 || t % 10 == 6 || t % 10 == 9) cnt++;
            t /= 10;
        }
    }
    cout << cnt;
}
/*
int n, maxl, maxi, cnt;
vector<int> v, a;
int main() {
    cin >> n;
    v.resize(n + 1), a.resize(n+1);
    for (int i = 0; i < n; i++)cin >> v[i];
    for (int i = 0; i < n; i++) {
        
    }
    cout << cnt;
}
/*int n, s, a[500002];
int main() {
    cin >> n;
    for (int i = 1; i <=n ; i++) cin >> a[i];
    for (int i = n; i > 0; i--) {
        s += a[i + 1] + 1 <= a[i] ? a[i]=a[i+1]+1 : a[i];
    }
    cout << s;
}
/*
long long int l, n, k;
vector<long long int> v, res;
set<long long int> visited;
void bfs() {
    queue<pair<long long int, long long int>> q;
    for (int i = 0; i < n; i++) q.push(make_pair(v[i], 0));
    while (!q.empty()) {
        pair<long long int, long long int> X = q.front();
        if (0 <= X.first && X.first <= l && !visited.count(X.first)) res.push_back(X.second), visited.insert(X.first);
        if (res.size() >= k) break;
        if (X.first + 1 <= l && !visited.count(X.first + 1)) q.push(make_pair(X.first + 1, X.second + 1));
        if (X.first - 1 <= l && X.first - 1 >= 0 && !visited.count(X.first - 1)) q.push(make_pair(X.first - 1, X.second + 1));
        q.pop();
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> l >> n >> k;
    v.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> v[i];
    bfs();
    sort(res.begin(), res.end());
    for (int i = 0; i < k; i++) cout << res[i] << "\n";
}
/*
    vector<int> visited(53), v(53);
    int n, m, cnt, sum, k;
    string w, s;
    int f(char c) { return 'A' <= c && c <= 'Z' ? c - 65 : c - 71; }
    int main() {
        cin >> n >> m >> w >> s;
        for (int i = 0; i < n; i++) { if (!visited[f(w[i])]) k++; visited[f(w[i])]++; }
        for (int i = 0; i < m; i++) { if (++v[f(s[i])] == visited[f(s[i])]) cnt++; if (i >= n) { if (v[f(s[i - n])]-- == visited[f(s[i - n])]) cnt--; }if (cnt == k) sum++;  }
        cout << sum;
    }
/*int main() {
    int n, a, b,sum=0;
    cin >> n;
    vector<pair<int,int>> v(n);
    vector<int> visited(1001);
    priority_queue<pair<int, int>> pq1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    for (int i = 0; i < n; i++) {
        if (!visited[v[i].first]) sum += v[i].second, pq2.push(v[i]);
        else pq1.push(v[i]);
    }
    while(pq)
    cout << sum;
}
/*

/*
long long int cnt, n;
vector<double> v, d;
int main() {
    cin >> n;
    v.resize(n + 1), d.resize(n+1);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) {
        double r = log2(double(v[i - 1] / v[i]));
        d[i] = ceil(d[i - 1] + r); 
        if (d[i] < 0) d[i] = 0;
        cnt += d[i];
    }
    cout << cnt;
}
/*
int n;
int main() {
    cin >> n;
    //4, 4 + 5 , 9 + 16
    //2^2 3^2 5^2, 33^2
    cout << int(pow(pow(2, n)+1, 2));
}
/*
string a;
int n, sum;
int main() {
    cin >> a;
    cin >> n;
    for (int i = 0; i < a.length(); i++) {
        a[i] -= '0' <= a[i] && a[i] <= '9' ? '0' : ('A'-10);
       sum+= a[i]*pow(n, a.length() - i - 1);
    }
    cout << sum;
}
/*
vector<pair<int, int>> v(3);
int main() {
    for(int i=0; i<3; i++) cin >> v[i].first >> v[i].second;
    cout << (v[0].first==v[1].first?v[2].first:(v[1].first==v[2].first?v[0].first:v[1].first)) << " " << (v[0].second == v[1].second ? v[2].second : (v[1].second == v[2].second ? v[0].second : v[1].second));
}
/*
int n, sum;
vector<int> v, r;
int main() {
    cin >> n;
    v.resize(n + 1), r.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        r[i] = r[i - 1] >= n - i + 1;
    }
}
/*
int n, cnt, sum, a;
vector<double> v, l;
int main() {
    cin >> n;
    v.resize(n + 1), l.resize(n+1);
    for (int i = 0; i < n; i++) cin >> a, v[i]=log2(a);
    for (int i = 1; i < n; i++) {
        while (v[i] < v[i-1]) v[i]++, cnt++;
    }
    double l_ratio = 0.0;
    l_ratio = log2((double));
    cout << cnt;
}
/*
int n, cnt;
vector<double> v;
int main() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> v[i], v[i]**=10;  
    for (int i = 1; i < n; i++)while (v[i] < v[i - 1]) v[i] *= 2,cnt++;
    cout << cnt;
}
/*
int n, m, cnt, res, cheeze, dx[] = { 1, -1, 0, 0 }, dy[] = { 0,0,-1,1 };
vector<vector<int>> v, visited;
void dfs(int s, int e) {
    visited[s][e] = 1;
    for (int i = 0; i < 4; i++) {
        if (0 <= s + dx[i] && s + dx[i] < n && 0 <= e + dy[i] && e + dy[i] < m && v[s+dx[i]][e+dy[i]] = 1) {

            dfs(s + dx[i], e + dy[i]);
        }
    }

}
int main() {
    cin >> n >> m;
    v.resize(n, vector<int>(m)), visited.resize(n, vector<int>(m));
    while (cnt) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && v[i][j] == 1) {
                    dfs(i, j);
                    if (!cnt) break;
                    else cheeze = 0;
                }
            }
        }
    }
    cout << res << "\n" << cheeze;
}
/*
string str;
int cnt;
int main() {
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        cnt++;
        if (i + 1 < str.length()) {
            if (str[i] == 'c' && (str[i + 1] == '=' || str[i + 1] == '-')) i++;
            else if (str[i] == 'd') {
                if (i + 2 < str.length() && str[i + 1] == 'z' && str[i + 2] == '=')  i+=2;
                if (str[i + 1] == '-') i++;
            }
            else if (str[i] == 'l' && str[i + 1] == 'j') i++;
            else if (str[i] == 'n' && str[i + 1] == 'j') i++;
            else if ((str[i] == 's' || str[i] == 'z') && str[i + 1] == '=') i++;
        }
    }
    cout << cnt;
}
/*
string str, g;
double a, sum1, sum2;
int main() {
    for (int i = 0; i < 20; i++) {
        cin >> str >> a >> g;
        if (g[0] == 'P') continue;
        sum2 += a;
        if (g[0] == 'F') continue;
        sum1 += (69 - g[0])*a;
        if (g[1] == '+') sum1 += 0.5*a;
    }
    cout <<  sum1 / sum2;
}
/*
string str;
int cnt;
int main() {
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i + 1] < str.length()) {
            if (str[i] == 'c' && (str[i + 1] == '=' || str[i + 1] == '-')) i++, cnt++;
            if (str[i] == 'd') {
                if (i + 1 < str.length())
            }
        }
    }
}
/*
int main() {
    string str;
    vector<int> v(26);
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        v[str[0] - 97]++;
        for (int j = 1; j < str.length(); j++) {
            if(v[str[j] - 97] != 0 && str[j - 1] != str[j]) {
                cnt++;
                break;
            }
            v[str[j] - 97]++;
        }
        fill(v.begin(), v.end(), 0);
    }
    cout << n-cnt;
}
/*

/*
int main() {
    vector<int> v(27);
    int maxl=0;
    char a;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (97 <= str[i]) v[str[i] - 97]++;
        else v[str[i] - 65]++;
    }
    for (int i = 0; i < 26; i++) {
        cout << maxl << "    " << v[i] << "\n";
        if (maxl == v[i]) a = '?' , maxl = v[i];
        else if (maxl < v[i]) a = i + 65, maxl = v[i];
    }   
    cout << a;
}
/*
string str;
int main() {
    cin >> str;
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - i - 1]) {
            cout << "0";
            return 0;
        }
    }
    cout << "1";
}
/*
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n-1; j++) {
            cout << " ";
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= i; j++) {
            cout << " ";
        }
        for (int j = 0; j < (n - i) * 2 - 3; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}
/*
string str;
int cnt, Ccnt, Bcnt;
int main() {
    cin >> str;
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i]!='D') {
            if (str[i] == 'C') Ccnt++, str[i]='D';
            if (Ccnt&&str[i]=='B') cnt++, str[i] = 'D', Ccnt--;
        }
    }
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] != 'D') {
            if (str[i] == 'B') Bcnt++, str[i] = 'D';
            if (Bcnt && str[i] == 'A') cnt++, str[i] = 'D', Bcnt--;
        }
    }
    cout << cnt;
}
/*
lint n, a, ocnt, ecnt, esum, osum;
vector<int> v;
int main() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 1) v[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (v[i]) osum += i - ocnt++;
        else esum += i - ecnt++;
    }
    // 1001
    cout << min(esum, osum);
}
/*
int n, m, x, y, minc = INT_MAX;
vector<pair<int, int>> h;
vector<int> p;
int getDistance(vector<pair<int, int>> selected) {
    int maxDist = 0;
    for (int i = 0; i < n; i++) {
        int minDistance = INT_MAX;
        for (pair<int, int> ch : selected) {
            int  distance = abs(h[i].first - ch.first) + abs(h[i].second - ch.second);
            minDistance = min(minDistance, distance);
        }
        maxDist = max(minDistance, maxDist);
    }
    return maxDist;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        h.push_back({ x, y });
    }
    p.resize(h.size());
    fill(p.end() - m, p.end(), 1);
    do {
        vector<pair<int, int>> selected;
        for (int i = 0; i < h.size(); i++) {
            if (p[i]) selected.push_back(h[i]);
        }
        minc = min(minc, getDistance(selected));
    } while (next_permutation(p.begin(), p.end()));
    cout << minc;
}
/*
int n, m, x, y, minl=1000000000;
vector<pair<int,int>> v;
vector<vector<int>> c;
int main() {
    cin >> n >> m;
    v.resize(n + 1), c.resize(n+1, vector<int>(n+1));
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                c[i][j] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            }
        }
    }
    fill(c.end() - m, c.end(), 1);
    do {
        vector<pair<int, int>> selected;
        for (int i = 0; i < c.size(); ++i) {
            if (p[i]) selected.push_back(c[i]);
        }
        minc = min(minc, chickenDistance(selected));
    } while (next_permutation(p.begin(), p.end()));
    cout << minc;
    cout << minl;
}
/*
int n, m, dx[] = { 1,-1,0,0 }, dy[]={0,0,1,-1};
vector<vector<int>> v, c;
int main() {
    cin >> n >> m;
    v.resize(n, vector<int>(m)), c.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    c[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < 4; l++) {
                if (0 <= i + dx[l] && i + dx[l] < n && 0 <= j + dy[l] && j + dy[l] < m) {
                    if (v[i][j] > v[i + dx[l]][j + dy[l]]) {
                        c[i + dx[l]][j + dy[l]]+=c[i][j];
                    }
                }
            }
        }
    }
    cout << c[n-1][m-1];
}
/*
int n, a, minl=1000000, maxl=-1000000;
int main() {cin >> n; while (n--) cin >> a, maxl = max(a, maxl), minl = min(a, minl); cout << minl << " " << maxl;}  
/*
int main() {
    int t, a, b;
     cin >> t;
     while (t--) {
         int c = 1;
         cin >> a >> b;
         for (int i = 0; i < b; i++) {
             c = (c*a)%10;
         }
         cout << (c==0?10:c) << "\n";
     }
 }
/*
int main() {
    int a[31] = { 0 }, n;
    for (int i = 0; i < 28; i++) {
        cin >> n;
        a[n-1]++;
    }
    for (int i = 0; i < 30; i++) if (a[i] == 0) cout << i + 1 << "\n";
}
/*
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cout << "*";
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) cout << "*";
        cout << "\n";
    }
}
/*
int main() {
   /* int t, a, b;
    cin >> t;
    while (t--) {
        int c = 1;
        cin >> a >> b;
        for (int i = 0; i <= b; i++) {
            c *= a;
            c %= b;
        }
        cout << c==0 << "\n";
    }
}
/*
int cal(int a, int b) {
    return a+b;
}
void cal2(int a, int b) {
    cout << a + b;
}
int main() {    
    int x, y;
    cin >> x >> y;
    int result;
    result = cal(x, y);
    cout << result << "\n";
    cal2(x, y);
    return 0;
}

/*
int n, a, b;
vector<pair<int, int>> v;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}
/*
int n, sum;
vector<int> v;
int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        sum += v[i] * v[(i+1) % n]; 
    }
    cout << sum << "\n";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
}
/*
int n, m, maxl;
vector<vector<int>> v, c;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.resize(n + 1, vector<int>(m + 1, 0)), c.resize(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    c[1][1] = v[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i + 1 <= n && j <= m)
                c[i + 1][j] = max(c[i + 1][j], c[i][j] + v[i + 1][j]);
            if (i <= n && j+1 <= m)
                c[i][j+1] = max(c[i][j+1], c[i][j] + v[i][j+1]);
            if (i + 1 <= n && j + 1 <= m)
                c[i + 1][j+1] = max(c[i + 1][j+1], c[i][j] + v[i + 1][j+1]);
        }
    }
    cout << c[n][m];
}
/*
int n, a, b;
vector<pair<int, int>> v;
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}
/*
int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++ ) {
        for (int j = 0; j < i-1; j++) {
            cout << " ";
        }
        for (int j = 0; j < (n-i) * 2 + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < i-1; j++) {
            cout << " ";
        }
        for (int j = 0; j < (n - i) * 2 + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}
/*
int n, m, c, a, b, x, y, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0,1 };
vector<vector<int>> visited;
vector<string> v;
string isAvailable = "No";
void dfs(int s, int e, int ps, int pe) {
    visited[s][e] = 1;
    for (int i = 0; i < 4; i++) {
        if (0 <= s + dx[i] && s + dx[i] < n && 0 <= e + dy[i] && e + dy[i] < m && v[s + dx[i]][e + dy[i]] == v[s][e]) {
            if (s + dx[i] != ps && e + dy[i] != pe) {
                if (visited[s + dx[i]][e + dy[i]] == 1)
                    isAvailable = "Yes";
                else
                     dfs(s + dx[i], e + dy[i], s, e);
            }
        }
    }

}
int main() {
    cin >> n >> m;
    v.resize(n + 1), visited.resize(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) dfs(i, j, i, j);
        }
    }
    cout << isAvailable;

}
/*
int n;
void fibo(int a, int b, int c) {
    cout << a << "\n";
    if (c==n) cout << (b+a*2) % 10007;
    else fibo(b, (b+ a * 2) % 10007, c+1);
}
int main() {
    cin >> n, fibo(0, 1, 1);
}
/*
int n, m, c, a, b, x, y, dx[] = {0,1,}, dy[] = {1,0};
vector<vector<int>> visited;
vector<string> v;
string isAvailable = "No";
void dfs(int s, int e) {
    visited[s][e] = 1;
    for (int i = 0; i < 2; i++) {
        if (0 <= s + dx[i] && s + dx[i] < n && 0 <= e + dy[i] && e + dy[i] < m && v[s + dx[i]][e + dy[i]] == v[s][e]) {
            if (visited[s + dx[i]][e + dy[i]] == 1)
                isAvailable = "Yes";
            else dfs(s + dx[i], e + dy[i]);
        }
    }

}
int main() {
    cin >> n >> m;
    v.resize(n + 1), visited.resize(n + 1, vector<int>(m+1));
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) dfs(i, j);
        }
    }
    cout << isAvailable;

}
/*
int n, m, c, a, b, x, y;
vector<vector<int>> v;
vector<int> visited;
void dfs(int s, int cnt) {
    if (s == y) c = cnt;
    visited[s] = 1; 
    for (int i = 0; i < v[s].size(); i++) {
        if(visited[v[s][i]]==0) dfs(v[s][i], cnt+1);
    }
}
int main() {
    cin >> n;
    v.resize(n + 1), visited.resize(n+1);
    cin >> x >> y;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(x, 0);
    if (c == 0) cout << -1;
    else cout << c;

}
/*
int n, a, maxl=0;
vector<vector<int>> v;
int main() {
    cin >> n;
    v.resize(n + 1, vector<int>(n+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a;
            v[i][j] += a;
            maxl = max(v[i][j], maxl);
            if (i < n - 1) {
                v[i + 1][j] = max(v[i][j], v[i + 1][j]);
                v[i + 1][j + 1] = max(v[i][j], v[i + 1][j + 1]);
            }
        }
    }
    cout << maxl;
}
/*
void fibo(int a, int b, int c) {
    if (!(c - 1)) cout << (a + b) % 10007;
    else fibo(b, (a + b)%10007, c - 1);
}
int main() {
    int n;
    cin >> n, fibo(0, 1, n);
}
/*
int n, m, tsize, a, b, ans;
vector<int> v;
void getm(int l, int r) {
    if (l > r) return;
    if (l % 2 == 1) ans = min(v[l], ans);
    if (r % 2 == 0) ans = min(v[r], ans);
    getm((l + 1) / 2, (r - 1) / 2);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    tsize = pow(2, ceil(log2(n)) + 1);
    v.resize(tsize, 1000000000);
    for (int i = tsize / 2; i < tsize / 2 + n; i++)  cin >> v[i];
    for (int i = tsize - 1; i > 1; i -= 2)
        v[i / 2] = min(v[i], v[i - 1]);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        ans = 1000000000;
        getm(tsize / 2 + a - 1, tsize / 2 + b - 1);
        cout << ans  << "\n";
    }
}
/*
int n, res, maxl;
vector<int> r;
vector<pair<int,int>> v;
int main() {
    cin >> n;
    v.resize(n + 2), r.resize(n+2);
    for (int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;
    
    for (int i = 1; i <= n+1; i++) {
        r[i] = max(maxl, r[i]);
        if (i + v[i].first <= n + 1) {
            res = max(res, r[i] + v[i].second);
            r[i + v[i].first] = max(r[i+v[i].first], r[i] + v[i].second);
        }
        maxl = max(maxl, r[i]);
    }
    cout << res;
}
/*
int n, m, t, a, res, SIZE;
vector<int> v, c;
void getSum(int l, int r) {
    if (l > r) return;
    if (l % 2 == 1) res += v[l];
    if (r % 2 == 0) res += v[r];
    getSum((l + 1) / 2, (r - 1) / 2);
}
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        SIZE = pow(2, ceil(log2(n+m+1)) + 1);
        cout << "SIZE :  " << SIZE << "\n";
        v.resize(SIZE), c.resize(n+1);
        for (int i = SIZE / 2; i < SIZE / 2 + n; i++) v[i] = 1;
        for (int i = 0; i < n; i++) c[a] = i+1;
        for(int i=0; i<m; i++) {
            cin >> a;
            getSum(SIZE/2 + c[a], SIZE/2);
            cout << SIZE / 2 + c[a] - 1 << "    " << SIZE / 2 + c[a] + res - 1 << "\n";
            v[SIZE / 2 + c[a] - 1] = 0, v[SIZE / 2 + c[a] + res - 1] = 1;
            cout << "AND || \n";
            c[a] += res;
            cout << res;
            res = 0;
        }
        cout << "\n";
    }
}
/*int n, m, a, b, c, SIZE, res;
vector<int> v;

void getSum(int l, int r) {
    if (l > r) return;
    if (l % 2 == 1) res = min(res, v[l]);
    if (r % 2 == 0) res = min(res, v[r]);
    getSum((l + 1) / 2, (r - 1) / 2);
}
void update(int l, int r) {
    
}
int main() {
    cin >> n >> m;
    SIZE = pow(2, ceil(log2(n)) + 1);
    v.resize(SIZE);
    for (int i = SIZE/2; i < SIZE/2+n; i++) cin >> v[i];
    for(int i=SIZE-1; i++)
}
/*
#define SIZE pow(2, ceil(log2(1000001)) + 1)
using namespace std;
int n, a;
long long sum;
vector<int> b, c, v(SIZE);
void getSum(int l, int r) {
    if (l > r) return;
    if (l % 2 == 1) sum += v[l];
    if (r % 2 == 0) sum += v[r];
    getSum((l + 1) / 2, (r - 1) / 2);
}
int main() {
    cin >> n;
    b.resize(1000001), c.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) {
        cin >> a;
        b[a] = i;
    }
    for (int i = 0; i < n; i++) {
       
        getSum(SIZE/2+b[c[i]], SIZE/2+n-1);
        for (int j = SIZE / 2 + b[c[i]]; j >= 1; j /= 2) v[j]++;
    }
    cout << sum;
}
/*
#define SIZE pow(2, ceil(log2(1000001)) + 1)
using namespace std;
int n, a, b, c;
vector<int> v;
int getSum(int d, int k) {
    if (d >= SIZE / 2) return d;
    if (v[d * 2] >= k) return getSum(d * 2, k);
    else return getSum(d * 2 + 1, k - v[d * 2]);
}
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(SIZE, 0);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == 2) {
            cin >> c;
            for (int j = SIZE / 2 + b - 1; j >= 1; j /= 2) v[j] += c;
        }
        else {
            int res = getSum(1, b);
            for (int j = res; j >= 1; j /= 2) v[j]--;
            cout << int(res - SIZE / 2 + 1) << "\n";
        }
    }
}
/*#define SIZE pow(2, ceil(log2(1000001)) + 1)
using namespace std;
int n, m, a, b, c, d;
    vector<long long> v(SIZE);
    void addK(int l, int r, int k) {
        if (l > r) return;
        if (l % 2 == 1) v[l]+= k;
        if (r % 2 == 0) v[r]+= k;
        addK((l + 1) / 2, (r - 1) / 2, k);
    }
void query(int k, int sum) {
    if (k == 1) cout << sum << "\n";
    else query(k / 2, sum + v[k / 2]);
    }
    int main() {
    cin >> n;
    for (int i = SIZE/2; i < SIZE/2+n; i++) {
        cin >> v[i];
    }
    cin >> m;
    while (m--) {
        cin >> a >> b;
        if (a == 1) {
            cin >> c >> d;
            addK(b, c, d);
        }
        else query(SIZE / 2 + b, 0);
    }
}
/*
#define SIZE pow(2, ceil(log2(1000001)) + 1)
using namespace std;
int n, a, b, c;
vector<int> v;
int getSum(int d, int k) {
    if (d >= SIZE / 2) return d;
    if (v[d * 2] >= k) return getSum(d * 2, k);
    else return getSum(d * 2 + 1, k - v[d * 2]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(SIZE, 0);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == 2) {
            cin >> c;
            for (int j = SIZE / 2 + b - 1; j >= 1; j /= 2) v[j] += c;
        }
        else {
            int res = getSum(1, b);
            for (int j = res; j >= 1; j /= 2) v[j]--;
            cout << int(res - SIZE / 2 + 1) << "\n";
        }
    }
}
/*
#define SIZE pow(2, ceil(log2(1000001)) + 1)
using namespace std;
int n, a, b, c;
vector<int> v(SIZE);
int getSum(long long int d, int k) {

    if (d>SIZE/2)  return d;
    cout << d << "  ?  " << k << " " << v[d] << "!!\n";
    if (k <= v[d]) getSum( d * 2, k);
    else getSum(d * 2 + 1, k);
    v[d]--;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cout << SIZE;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == 1) {
            int res = getSum(1, b)-SIZE/2;
            v[res]--;
            cout << "!!" << res << "\n";
            for (int j = SIZE / 2 + b - 1; j > 1; j /= 2)
                v[j / 2] = v[j] + v[j % 2 == 0 ? j + 1 : j - 1];
        }
        else {
            cin >> c;
            v[SIZE / 2 + b - 1] += c;
            for (int j = SIZE / 2 + b - 1; j > 1; j /= 2)
                v[j / 2] = v[j] + v[j % 2 == 0 ? j + 1 : j - 1], cout << v[j/2] << "\n";
            
        }

    }
}
/*
int n, m, a, b, c, tsize, res;
vector<int> v;
void getSum(int l, int r) {
    if (l > r) return;
    if (l % 2 == 1) res = min(res, v[l]);
    if (r % 2 == 0) res = min(res, v[r]);
    getSum((l + 1) / 2, (r - 1) / 2);
}
int main() {
    cin >> n;
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    tsize = pow(2, ceil(log2(n)) + 1);
    v.resize(tsize, 1);
    for (int i = tsize / 2; i < tsize / 2 + n; i++) cin >> v[i];
    for (int i = tsize - 1; i > 1; i -= 2) v[i / 2] = min(v[i], v[i - 1]);
    cin >> m;
    while (m--) {
        cin >> a >> b >> c;
        if (a == 1) {
            v[tsize / 2 + b - 1] = c;
            for (int j = tsize / 2 + b - 1; j > 1; j /= 2) v[j / 2] = v[j]*v[j % 2 == 0 ? j + 1 : j - 1];
        }
        else {
            res = 1000000001;
            getSum(tsize / 2 + b - 1, tsize / 2 + c - 1);
            cout << res << "\n";
        }
    }
}
/*
int n, m, a, b, c, tsize, res;
vector<int> v;
void getSum(int l, int r) {
    if (l > r) return;
    if (l % 2 == 1) res = min(res, v[l]);
    if (r % 2 == 0) res = min(res, v[r]);
    getSum((l + 1) / 2, (r - 1) / 2);
}
int main() {
    cin >> n;
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    tsize = pow(2, ceil(log2(n)) + 1);
    v.resize(tsize, 1000000001);
    for (int i = tsize / 2; i < tsize / 2 + n; i++) cin >> v[i];
    for (int i = tsize - 1; i > 1; i -= 2) v[i / 2] = min(v[i], v[i - 1]);
    cin >> m;
    while (m--) {
        cin >> a >> b >> c;
        if (a == 1) {
            v[tsize / 2 + b - 1] = c;
            for (int j = tsize / 2 + b - 1; j > 1; j /= 2) v[j / 2] = min(v[j], v[j % 2 == 0 ? j + 1 : j - 1]);
        }
        else {
            res = 1000000001;
            getSum(tsize / 2 + b - 1, tsize / 2 + c - 1);
            cout << res << "\n";
        }
    }
}
/*
long long n, m, tsize, sum, x, y, a, b;
vector<long long> v;
void getSum(int l, int r) {
    if (l > r) return;
    if (l % 2 == 1) sum += v[l];
    if (r % 2 == 0) sum += v[r];
    getSum((l + 1) / 2, (r - 1) / 2);
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    cin >> n >> m;
    tsize = pow(2, ceil(log2(n)) + 1);
    v.resize(tsize);
    for (int i = tsize / 2; i < tsize/2+n; i++) cin >> v[i];
    for (int i = tsize - 1; i > 1; i -= 2) v[i / 2] = v[i] + v[i - 1];
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        getSum(tsize/2 + x - 1, tsize / 2 + y - 1);
        cout << sum << "\n", sum = 0;
        v[tsize / 2 + a - 1] = b;
        for (int j = tsize / 2 + a - 1; j > 1; j /= 2) v[j / 2] = v[j] + v[j % 2 == 0 ? j + 1 : j - 1];
    }
}
/*
long long n, m, k, tsize, sum=1, a, b, c;
vector<long long> v;
void getSum(long long l, long long r) {
    if (l > r) return;
    if (l % 2 == 1) sum = sum*v[l] % 1000000007;
    if (r % 2 == 0) sum = sum*v[r] % 1000000007;
    getSum((l + 1) / 2, (r - 1) / 2);
}
int main() {
    cout.tie(0);
    cin >> n >> m >> k;
    tsize = pow(2, ceil(log2(n)) + 1);
    v.resize(tsize, 1);
    for (int i = tsize / 2; i < tsize / 2 + n; i++)  cin >> v[i];
    for (int i = tsize - 1; i > 1; i -= 2)    v[i / 2] = v[i] * v[i - 1] % 1000000007;
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if(a==1)v[tsize / 2 + b - 1] = c;
        if (a == 1) for (int j = tsize / 2 + b - 1; j > 1; j /= 2) v[j/2] = v[j]*v[j%2==0?j+1:j-1] % 1000000007;
        else getSum(tsize / 2 + b - 1, tsize / 2 + c - 1), cout << sum % 1000000007 << "\n", sum = 1;
    }
}
/*
long long n, m, Lsum, Rsum, sum, cnt=1;
vector<long long> a, v;
string str;
int f(int r) { return (r < n ? (r < 0 ? n - 1 : r) : 0); }
int check(int r) { return (str[f(r - 1)] == 'R' && str[f(r + 1)] == 'L'); }

int main() {
    cin >> n >> m >> str;
    a.resize(n + 1), v.resize(n+1);
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    for (int i = 0; i < n; i++) {
        if (check(i)&&v[i]==0) {
            for (int j = f(i - 1); str[j] == 'R'; j = f(j - 1)) Lsum += a[j];
            for (int j = f(i + 1); str[j] == 'L'; j = f(j - 1)) {
                Rsum += a[j];
            }
            if(v[f(i] =='R'){
            }
            sum -= min(Lsum, Rsum) >= m ? m  : min(Lsum, Rsum)/cnt;
            cout << "sum = " << sum << "    cnt = " << cnt << "\n";
            Lsum = 0, Rsum = 0; cnt = 1;
        }
    }
    cout << sum;
}
/*
long n, m, inp, tsize, a, b;
pair<long, long> ans;
vector<pair<long, long>> v;
void getm(int l, int r) {
    if (l > r) return;
    if(l%2==1) ans = make_pair(max(v[l].first, ans.first), min(v[l].second, ans.second));
    if(r%2==0) ans = make_pair(max(v[r].first, ans.first), min(v[r].second, ans.second));
    getm((l + 1) / 2, (r - 1) / 2);
}
int main() {
    cin >> n >> m;
    tsize = pow(2, ceil(log2(n)) + 1);
    v.resize(tsize, make_pair(0, 100000001));
    for (int i = tsize / 2; i < tsize / 2 + n; i++)  cin >> inp, v[i] = make_pair(inp, inp);
    for (int i = tsize - 1; i > 1; i -= 2)
        v[i / 2] = make_pair(max(v[i].first, v[i-1].first), min(v[i].second, v[i-1].second));
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        ans = make_pair(0, 100000001);
        getm(tsize / 2 + a - 1, tsize / 2 + b - 1);
        cout << ans.second << " " << ans.first << "\n";
    }
}
/*
long int n, m, k, tsize, sum, a, b, c, ch;
vector<long int> v;
void getSum(long int l, long int r) {
    if (l > r) return;
    if (l % 2 == 1) sum += v[l];
    if (r % 2 == 0) sum += v[r];
    getSum((l + 1) / 2, (r - 1) / 2);
}
int main() {
    cin >> n >> m >> k;
    tsize = pow(2, ceil(log2(n)) + 1);
    v.resize(tsize);
    for (int i = tsize / 2; i < tsize / 2 + n; i++)  cin >> v[i];
    for (int i = tsize - 1; i > 1; i -= 2)    v[i / 2] = v[i] + v[i - 1];
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        ch = c - v[tsize / 2 + b - 1];
        if (a == 1) for (int j = tsize / 2 + b - 1; j >= 1; j /= 2) v[j] += ch;
        else getSum(tsize / 2 + b - 1, tsize / 2 + c - 1), cout << sum << "\n", sum = 0;
    }
}
/*
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int res = 0, a, n, cnt = 0, cnt2 = 0;
    cin >> n;
    vector<int> v(n + 1), c(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a;
        v[a]++;
        if (v[a] == 2) cnt2++;
        c[i] = cnt2;
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] == 1) res += cnt2 - c[i], cout << cnt2 << " " << c[i] << "\n";
        else if (v[i] >= 2) res += cnt2 - c[i] - 1, cout << cnt2 << " " << c[i] << "\n";
    }
    cout << res;
}
/*
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    long long cnt = 0;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    map<int, int> f;
    for (int i = 0; i < n; i++) f[arr[i]]++;

    for (pair<int,int> i : f) {
        int x = i.first;
        int count = i.second;

        if (count >= 2) {
            for (pair<int,int> j : f) {
                if (j.first != x) {
                    cnt += j.second * (count * (count - 1) / 2);
                }
            }
        }
    }
    cout << cnt << "\n";
}
/*
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int res=0, a, n, cnt = 0, cnt2 = 0;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a;
        v[a]++;
        if (v[a] == 1) cnt++;
        if (v[a] == 2) cnt2++;
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] == 1) {
            res += cnt2;
        }
        else if (v[i] >= 2) {
            res += v[i] * cnt2-v[i];
        }
    }
    cout << res;
}
/*
int main() {
    int n, cnt=0, i, j, s=0;
    cin >> n;
    vector<int> v(n + 1), c(n + 1), res(n+2);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (v[i] == c[i]) cnt++;
    }
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            s = 0, i = l, j = r;
            while (i < j) {
                if (v[i] == c[j]&&v[j]!=c[j]) s++;
                if (v[j] == c[i]&&v[i]!=c[i]) s++;
                if (v[i] != c[j] && v[j] == c[i]) s--;
                if (v[j] != c[i] && v[i] == c[i]) s--;
                i++, j--;
            }
            cout << l << " & " << r <<  " / " << cnt << " " << s << " " << cnt + s << "!\n";
            res[cnt+s]++;
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << res[i] << "\n";
    }
}
/*
* int main() {
    int n, a, b, t;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        vector<vector<int>> v(a, vector<int>(b))
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 'B') {
                    if (i + a < n && j + b < n) {
                        if(v[i+a][j+b]=='G') v[i+a][j+b] = 'G';
                        else {
                            cout << -1;
                            return 0;
                        }
                    }
                    else {
                        cout << -1;
                        return 0;
                    }
                }
                if (v[i][j] == '')
            }
        }
        for (int i = 0; i < n; i++) {
            for (int i = 0; i < n; i++) {

            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int a, n, cnt = 0, cnt2 = 0;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a;
        v[a]++;
        if (v[a] == 1) cnt++;
        if (v[a] == 2) cnt2++;
    }
    cout << cnt << "  " << cnt2 << "\n";
    cout << cnt2 * (cnt - 1);
}
/*
int main() {    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int a, n,cnt=0, cnt2=0;
    cin >> n;
    vector<int> v(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        v[a]++;
        if (v[a] == 1) cnt++;
        if (v[a] == 2) cnt2++;
    }
    cout << cnt2 * (cnt - cnt2); 
}

/*
int main() {
    int n, m, od=0, ev=0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) { 
        cin >> v[i];
        if (v[i] % 2 == 0) ev++;
        else od++;
    }
    m = od - ev;
    if (ev > od) cout << od * 2 + 1;
    else if (od > ev + 1) {
        if (m % 3 >= 0) cout << ev * 2 + (m / 3) * 2 - (m % 3 == 1);
        else cout << ev * 2 + (m / 3) * 2 + 1;
    }
    else cout << od + ev;
}
/*
int main() {
    int i = 0, j = 0, cnt=0;
    string cowphabet, str;
    cin >> cowphabet >> str;
    while (i < str.size()) {
        cnt++;
        for (int j = 0; j < 26; j++) {
            if (i<=str.size()&&cowphabet[j] == str[i]) i++;
        }
    }
    cout << cnt;
}
/*bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first; 
}

int main() {
    int n, a, b;
    cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}
/*
int n, x, y, a, xd, yd, d;
string str; 
vector<pair<int, int>> p, v;
void dfs(int node, int par, int dep) {
    p[node].first = par;
    p[node].second = dep;
    if (a+1 == x) xd = node;
    else if (a+1 == y) yd = node;
    v[node].first = a++;
    while (str[a] == '0') { dfs(++d, node, dep + 1); }
    if (a+1 == x) xd = node;
    else if (a+1 == y) yd = node;
    v[node].second = a++;
}
int lca(int s1, int s2) {
    while (p[s1].second > p[s2].second) s1 = p[s1].first;
    while (p[s2].second > p[s1].second) s2 = p[s2].first;
    while (s1 != s2) s1 = p[s1].first, s2 = p[s2].first;
    return s1;
}
int main() {
    cin >> n >> str >> x >> y;
    p.resize(n + 1); v.resize(n + 1);
    dfs(++d, 0, 0);
    int l = lca(xd, yd);
    cout << v[l].first+1 << " " << v[l].second + 1;
}
/*
int a, b, d, n, m;
struct nd {
    int parent, depth, distance;
};
struct vt {
    int child, distance;
    vt(int x, double y) : child(x), distance(y) {}
};
vector<vector<vt>> v;
vector<nd> p;
void dfs(int node, int par, int dep) {
    p[node].parent = par;
    p[node].depth = dep;
    for (vt ch : v[node]) {
        if (ch.child != par) {
            p[ch.child].distance = p[node].distance + ch.distance;
            dfs(ch.child, node, dep + 1);
        }
    }
}
int lca(int s1, int s2) {
    while (p[s1].depth > p[s2].depth) {
        s1 = p[s1].parent;
    }
    while (p[s2].depth > p[s1].depth) {
        s2 = p[s2].parent;
    }
    while (s1 != s2) {
        s1 = p[s1].parent;
        s2 = p[s2].parent;
    }
    return s1;
}
int main() {
    ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(n + 1), p.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> d;
        v[a].push_back(vt(b, d));
        v[b].push_back(vt(a, d));
    }
    dfs(1, 0, 0);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << p[a].distance + p[b].distance - p[lca(a, b)].distance * 2 << "\n";
    }
}
/*
deque<int> d;
int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 1 || a == 2) {
            cin >> b;
            if (a == 1) d.push_front(b);
            if (a == 2) d.push_back(b);
        }
        else if (a == 5) cout << d.size() << "\n";
        else if (a == 6) cout << d.empty() << "\n";
        else if (!d.empty()) {
            if (a == 3) cout << d.front() << "\n", d.pop_front();
            if (a == 4) cout << d.back() << "\n", d.pop_back();
            if (a == 7) cout << d.front() << "\n";
            if (a == 8) cout << d.back() << "\n";
        }
        else cout << "-1\n";
    }
}
    /*
    int a, b, d, n, m;
    vector<vector<pair<int, int>>> v;
    vector<pair<int, pair<int, int>>> p;

    void dfs(int node, int par, int dep) {
        p[node].second.first = par;
        p[node].second.second = dep;
        for (pair<int, int> ch : v[node]) {
            if (ch.first != par) {
                p[ch.first].first = p[node].first + ch.second;
                dfs(ch.first, node, dep + 1);
            }
        }
    }
    int lca(int s1, int s2) {
        while (p[s1].second.second > p[s2].second.second) {
            s1 = p[s1].second.first;
        }
        while (p[s2].second.second > p[s1].second.second) {
            s2 = p[s2].second.first;
        }
        while (s1 != s2) {
            s1 = p[s1].second.first;
            s2 = p[s2].second.first;
        }
        return s1;
    }
    int main() {
        ios::sync_with_stdio(false);  cin.tie(nullptr);cout.tie(nullptr);
        cin >> n;
        v.resize(n + 1), p.resize(n + 1);
        for (int i = 0; i < n-1; i++) {
            cin >> a >> b >> d;
            v[a].push_back({ b, d });
            v[b].push_back({ a, d });
        }
        dfs(1, 0, 0);
        cin >> m;
        cout << "!!";
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            int l = lca(a, b);
            cout << p[a].first + p[b].first - p[l].first * 2 << "\n";
        }
    }
/*
int a, b, sum, n, m;
vector<vector<int>> v;
vector<pair<int, int>> p;

void dfs(int node, int par, int dep) {

    p[node].first = par;
    p[node].second = dep;
    for (int ch : v[node]) {
        if (ch != par) {
            dfs(ch, node, dep + 1);
        }
    }
}
int lca(int s1, int s2) {
    while (p[s1].second > p[s2].second) {
        s1 = p[s1].first;
    }
    while (p[s2].second > p[s1].second) {
        s2 = p[s2].first;
    }
    while (s1 != s2) {
        s1 = p[s1].first;
        s2 = p[s2].first;
    }
    return s1;
}

int main() {
    cin >> n;
    v.resize(n + 1), p.resize(n + 1);
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0, 0);
    cin >> m;
    vector<int> l(m + 1);

    l[0] = 1;
    for (int i = 1; i <= m; i++){
        cin >> l[i];
        int s = lca(l[i - 1], l[i]);
        sum += p[l[i]].second + p[l[i - 1]].second - p[s].second * 2;
    }
    cout << sum;
}
/*
int a, b, n;
vector<pair<int, int>> p;

void dfs(int node, int par, int dep) {

    p[node].first = par;
    p[node].second= dep;
    if (node * 2 + 1 <= 1023) {
        dfs(node * 2, node, dep + 1);
        dfs(node * 2 + 1, node, dep + 1);
    }
}
int lca(int s1, int s2) {
    while (p[s1].second > p[s2].second) {
        s1 = p[s1].first;
    }
    while (p[s2].second > p[s1].second) {
        s2 = p[s2].first;
    }
    while (s1 != s2) {
        s1 = p[s1].first;
        s2 = p[s2].first;
    }
    return s1;
}

int main() {
    cin >> n;
    p.resize(1024);
    dfs(1, 0, 0);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << lca(a, b)*10 << "\n";

    }
}
/*
int a, b, d, n, m;
vector<vector<pair<int,int>>> v;
vector<pair<int, pair<int, int>>> p;

void dfs(int node, int par, int dep) {

    p[node].second.first = par;
    p[node].second.second = dep;
    for (pair<int,int> ch : v[node]) {
        if (ch.first != par) {
            dfs(ch.first, node, dep + 1);
        }
    }
}
int lca(int s1, int s2) {
    while (p[s1].second.second > p[s2].second.second) {
        s1 = p[s1].second.first;
    }
    while (p[s2].second.second > p[s1].second.second) {
        s2 = p[s2].second.first;
    }
    while (s1 != s2) {
        s1 = p[s1].second.first;
        s2 = p[s2].second.first;
    }
    return s1;
}

int main() {
    cin >> n;
    v.resize(n + 1), p.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> d;
        v[a].push_back({b, d});
        v[b].push_back({ a, d });
    }
    dfs(1, 0, 0);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << "\n";

    }
}
/*
int n, a, b, m;
vector<vector<int>> v;
vector<int> l, p, d;

void dfs(int node, int par, int dep) {

    p[node] = par;
    d[node] = dep;
    for (int ch : v[node]) {
        if (ch != par) {
            dfs(ch, node, dep + 1);
        }
    }
}
int lca(int s1, int s2) {
    while (d[s1] > d[s2]) {
        s1 = p[s1];
    }
    while (d[s2] > d[s1]) {
        s2 = p[s2];
    }
    while (s1 != s2) {
        s1 = p[s1];
        s2 = p[s2];
    }
    return s1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(n + 1), p.resize(n+1), d.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0, 0);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}
/*
set<int> res;
int num;
void dfs(vector<int> t1, vector<int> t2, int vt1, int cnt) {
    if (cnt != 5) {
        for (int i = 1; i <= 100; i++) {
            if (cnt % 2 == 1) {
                if (t1[i] != 0) {
                    t1[i]--, t2[i]++;
                    dfs(t1, t2, vt1-i, cnt+1);
                    t1[i]++, t2[i]--;
                }
            }
            else {
                if (t2[i] != 0) {
                    t2[i]--, t1[i]++;
                    dfs(t1, t2, vt1+i, cnt+1);
                    t2[i]++, t1[i]--;
                }
            }
        }
    }
    else res.insert(vt1);
}
int main() {
    vector<int> t1(101), t2(101);
    for (int i = 0; i < 10; i++) {
        cin >> num, t1[num]++;
    }
    for (int i = 0; i < 10; i++) {
        cin >> num, t2[num]++;
    }
    dfs(t1, t2, 1000, 1);
    cout << res.size();
    
}
/*
vector<int> v, d;
vector<pair<pair<int, int>, int>> result;
vector<vector<int>> r;
int n, avg, sum, res, a, b;
void dfs(int s ) {

    for(int i : r[s]) {
        if (d[s] < 0) {
            d[i] += d[s];
            res++;
            result.push_back({ { i, s }, -d[s] });
            d[s] = 0;
        }
        dfs(i);
    }
}
void needfs(int s) {
    d[s] = avg - v[s];
    for (int i : r[s]) needfs(i);
}
int main() {
    cin >> n;
    v.resize(n + 1), d.resize(n+1), r.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    avg = sum / n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        r[a].push_back(b);
        r[b].push_back(a);
    }
    needfs(1);
    dfs(1);
    cout << res << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first.first << " " << result[i].first.second << " " << result[i].second << "\n";
    }
}
/*
int t, n, k;
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> v(n);
        string str;
        cin >> str;
        for (int i = 0; i < n; i++) {

        }
        cout << c << "\n" << str << "\n";
        
    }
}
/*long long int n, maxl, sum, last, maxc;
vector<int> v;
int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (v[i] != last) {
            sum = v[i] * (n - i);
            if (sum > maxl) maxl = sum, maxc = v[i];
        }
    }
    cout << maxl << " " << maxc;
}
/*
vector<vector<int>> v;
int k, n, a, sum,dsum, cnt;
int main() {
    cin >> k >> n;
    v.resize(n + 1, vector<int>(k + 1));
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a;
            v[a][i] = j;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int l = 0; l < k; l++) {
                if (v[i][l] > v[j][l])  sum++;
                else if (v[i][l] < v[j][l])  dsum++;
            }
            if (sum == k || dsum == k) cnt++;
            sum = 0, dsum = 0;
        }
    }

    cout << cnt;

}
/*
using namespace std;
int n, sum, cnt;
vector<int> v;
int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        sum = 0;
        vector<int> c(1001);
        for (int j = i; j < n; j++) {
            sum += v[j];
            c[v[j]] = 1;
            if (c[sum / (j - i + 1)]&&sum%(j-i+1)==0) {
                cnt++;
            }
        }
    }
    cout << cnt;
}
/*
vector<int> v;
int main() {
    v.resize(7);
    for (int i = 0; i < 7; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << v[0] << " " << v[1] << " " << v[6] - v[0] - v[1];
}
/*
int n, m;
vector<vector<int>> v;
vector<int> d;
void dfs(vector<int> s, vector<int> visited) {
    if (s.size() == m) {
        v.push_back(s);
    }
    else {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                s.push_back(d[i]);
                visited[i] = 1;
                dfs(s, visited);
                s.pop_back();
                visited[i] = 0;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    vector<int> visited(n + 1), s;
    d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    dfs(s, visited);
    for (int i = 0; i < v.size(); i++) {
        for (int j : v[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
}
/*
int n, mini, maxi;
void dfs(vector<int> v, vector<int> op) {
    for (int i = 0; i < n; i++) {
         
    }
}
int main() {
    cin >> n;

    vector<int> v(n + 1), op(4);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    dfs(v, op);
}
/*

/*
int n, m;
vector<vector<int>> v;
void dfs(vector<int> s, int d) {
    if (s.size() == m) {
        v.push_back(s);
    }
    else {
        for (int i = d; i <= n; i++) {
            s.push_back(i);
            dfs(s, i);
            s.pop_back();
        }
    }
}
int main() {
    cin >> n >> m;
    vector<int> s;
    dfs(s, 1);
    for (int i = 0; i < v.size(); i++) {
        for (int j : v[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
}
/*
int n, m;
vector<vector<int>> v;
void dfs(vector<int> s, vector<int> visited) {
    if (s.size() == m) {
        v.push_back(s);   
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                s.push_back(i);
                visited[i] = 1;
                dfs(s, visited);
                s.pop_back();
                visited[i] = 0;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    vector<int> visited(n + 2), s;
    dfs(s, visited);
    for (int i = 0; i < v.size(); i++) {
        for (int j : v[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
}
/*
vector<vector<int>> v(9, vector<int>(9)), row(9, vector<int>(9)), column(9, vector<int>(9)), square(9, vector<int>(9));
int getSquareIndex(int x, int y) {
    return (x / 3) * 3 + (y / 3);
}
int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> v[i][j];
            if (v[i][j] != 0) {
                row[j][v[i][j]] = 1;
                column[i][v[i][j]] = 1;
                sqaure[getSqaureIndex(i, j)][v[i][j]] = 1;
            }
        }
    }
}
/*
int l, c;
vector<char> v;
vector<int> p;
int main() {
    cin >> l >> c;
    v.resize(c);
    for (int i = 0; i < c; i++) cin >> v[i];
    sort(v.begin(), v.end());
    p.resize(v.size());
    fill(p.begin(), p.begin() + l, 1);
    do {
        vector<char> selected;
        int vowel = 0, consonant = 0;
        for (int i = 0; i < v.size(); i++) {
            if (p[i]) {
                selected.push_back(v[i]);
                if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') vowel++;
                else consonant++;
            }
        }
        if (vowel >= 1 && consonant >= 2) {
            for (int i = 0; i < selected.size(); i++) {
                cout << selected[i] << " ";
            }
            cout << "\n";
        }
    } while (prev_permutation(p.begin(), p.end()));
}
/*
int n, m, input, minc=INT_MAX;
vector<pair<int,int>> c, h;
vector<vector<int>> v;
vector<int> p;
int chickenDistance( vector<pair<int, int>> selected) {
    int sum = 0;
    for (pair<int, int> house : h) {
        int hx = house.first,  hy = house.second,  minDistance = INT_MAX;
        for (pair<int, int> chicken : selected) {
            int cx = chicken.first, cy = chicken.second, distance = abs(hx - cx) + abs(hy - cy);
            minDistance = min(minDistance, distance);
        }
        sum += minDistance;
    }
    return sum;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input;
			if (input == 1) h.push_back({ i, j });
			else if (input == 2) c.push_back({ i, j });
		}
	}
	p.resize(c.size());
	fill(p.end() - m, p.end(), 1);
    do {
        vector<pair<int, int>> selected;
        for (int i = 0; i < c.size(); ++i) {
            if (p[i]) selected.push_back(c[i]);
        }
        minc = min(minc, chickenDistance(selected));
    } while (next_permutation(p.begin(), p.end()));
    cout << minc;
}

//int n;
//struct Trie {
//	map<char, Trie*> trie;
//};
//Trie *nd, *t;
//int main() {
//	string str;
//	vector<string> vt;
//	cout << fixed;
//	cout.precision(2);
//	while (scanf("%d", &n) != EOF) {
//		t = new Trie();
//		nd = t;
//		int sum = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> str;
//			vt.push_back(str);
//			for (int j = 0; j < str.size(); j++) {
//				if (nd->trie[str[j]] == nullptr) {
//					cout << str[j] << "\n";
//					nd->trie[str[j]] = new Trie();
//				}
//				nd = nd->trie[str[j]];
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			nd = t;
//			for (int j = 0; j < vt[i].size(); j++) {
//				
//				cout << "vt[i] << " << vt[i][j] << "  " << nd->trie.size() << "\n";
//				
//				if (nd->trie.size() >= 1) {
//					if (nd->trie.size() > 1) sum++;
//					if (nd->trie.find(vt[i][j]) != nd->trie.end()) {
//						if (nd->trie.size() > 1) sum++;
//						nd = nd->trie[vt[i][j]];
//					}
//					else {
//						 //키가 존재하지 않으면 탈출 또는 예외 처리
//						cout << "키가 존재하지 않습니다: " << vt[i][j] << "\n";
//						break;
//					}
//				}
//			}
//		}
//		cout << float(sum / n) << "\n";
//		cout << float(1 / 3) << "\n";
//	}
//}
/*
#include<bits/stdc++.h>
using namespace std;
int n;
struct Trie {
    map<string, Trie*> trie;
};
void dfs(Trie* v, int lvl) {
    for (map<string, Trie*>::iterator it = v->trie.begin(); it != v->trie.end(); it++) {
        for (int j = 0; j < lvl; j++) {
            cout << " ";
        }
        cout << it->first << "\n";
        dfs(it->second, lvl + 1);
    }
}
int main() {
    cin >> n;
    Trie* t = new Trie();
    for(int i=0; i<n; i++) {
        Trie* nd = t;
        int j = 0;
        string str;
        cin >> str;
        while(str.find('\\', j)!=std::string::npos) {
            string s = str.substr(j, str.find("\\", j)-j);
            if (nd->trie[s]==nullptr) {
                nd->trie[s] = new Trie();
            }
            nd = nd->trie[s];
            cout  << "     " << j  << "     " << s << "\n";
            j = str.find('\\', j)+1;
        }
         if (nd->trie[str.substr(j)] == nullptr) {
            nd->trie[str.substr(j)] = new Trie();
        }
    }
    dfs(t, 0);
}

#include<bits/stdc++.h>
using namespace std;
int n,  k, first=1;
struct Trie {
    map<string, Trie*> trie;
};
void dfs(Trie* v, int lvl) {
    for (map<string, Trie*>::iterator it = v->trie.begin(); it != v->trie.end(); it++) {
        for (int j = 0; j < lvl; j++) {
            cout << "--";
        }
        cout << it->first << "\n";
        dfs(it->second, lvl + 1);
    }
}
int main() {
    cin >> n;
    Trie* t = new Trie();
    for(int i=0; i<n; i++) {
        Trie* nd = t;
        string str;
        cin >> k;
        for(int j=0; j<k; j++) {
            cin >> str;
            if (nd->trie[str]==nullptr) {
                nd->trie[str] = new Trie();
            }
            nd = nd->trie[str];
        }
    }
    dfs(t, 0);
}
*/
