//
// Created by 汪喆昊 on 2025/3/2.
//

// 变种的处理区间不同数的数量的题目

#include <iostream>
#include <map>

using namespace std;
#define int long long

const int N = 1e6 + 10;
const int mo = 1e9 + 7;
int n, m, x, y, z, a[N], k, p[N], b[N];
void add(int x, int y) {
    for (int i = x; i <= 2 * n; i += (i & (-i))) {
        b[i] += y;
    }
}

int get(int x) {
    int sum = 0;
    for (int i = x; i; i -= (i & (-i))) {
        sum += b[i];
    }
    return sum;
}

int fid(int x, int y) { return get(y) - get(x - 1); }

void slove() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    int l = 1, r = 2 * n;
    vector<pair<pair<int, int>, int>> v;
    for (int i = 1; i <= m; i++) {
        char o;
        cin >> o >> x;
        if (o == 'L') {
            if (x >= n) {
                v.push_back({{n, 1}, i});
            } else {
                v.push_back({{l + x - 1, l}, i});
            }
            l = (l + x) % n;
            if (l == 0) {
                l = n;
            }
        } else {
            if (x >= n) {
                v.push_back({{n, 1}, i});
            } else {
                v.push_back({{r, r - x + 1}, i});
            }
            r = ((r - x) % n + n) % n + n;
            if (r == n) {
                r = 2 * n;
            }
        }
    }
    map<int, int> mp;
    sort(v.begin(), v.end());
    r = 1;
    for (auto [xl, g] : v) {
        auto [x, y] = xl;
        while (r <= x) {
            if (mp[a[r]]) {
                add(mp[a[r]], -1);
            }
            add(r, 1);
            mp[a[r]] = r;
            r++;
        }
        p[g] = fid(y, x);
    }
    for (int i = 1; i <= m; i++) {
        cout << p[i] << endl;
    }
}

//class Base {
//public:
//    Base(int value) : m_value(value) {}
//    virtual void add(int value) {
//        m_value += value;
//    }
//    virtual void print() {
//        cout << "Base: " << m_value << endl;
//    }
//private:
//    int m_value;
//};
//
//class Drive :public Base {
//public:
//    Drive(int value) : m_value(value) {}
//    virtual void print() {
//        std::cout << "Drive: " << m_value << std::endl;
//    }
//private:
//    int m_value;
//};

signed main() {
//    Drive d(1);
//    d.add(2);
//    d.print();
//    return 0;
//    int t = 1;
//    while (t--) {
//        slove();
//    }
}
