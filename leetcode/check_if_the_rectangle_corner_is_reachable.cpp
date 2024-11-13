//
// https://leetcode.cn/problems/check-if-the-rectangle-corner-is-reachable/?envType=daily-question&envId=2024-11-08
//

#include "leetcode_utils.hpp"

using namespace std;

// class Solution {
// public:
//     bool canReachCorner(int xCorner, int yCorner, vector<vector<int>> &circles) {
//         const int N = circles.size();
//         for (int i = 0; i < N; i++) {
//             auto &circle = circles[i];
//             int x1 = circle[0], y1 = circle[1], r1 = circle[2];
//             if (isPointInCircle(xCorner, yCorner, x1, y1, r1)
//                 || isPointInCircle(0, 0, x1, y1, r1)) {
//                 return false;
//             }
//
//         }
//         return true;
//     }
//
// private:
//     bool isPointInCircle(int px, int py, int cx, int cy, int cr) {
//         return pow(px - cx, 2) + pow(py - cy, 2) <= pow(cr, 2);
//     }
// };

class Solution2 {
    // 判断点 (x,y) 是否在圆 (ox,oy,r) 内
    bool in_circle(long long ox, long long oy, long long r, long long x, long long y) {
        return (ox - x) * (ox - x) + (oy - y) * (oy - y) <= r * r;
    }

public:
    bool canReachCorner(int X, int Y, vector<vector<int>> &circles) {
        int n = circles.size();
        vector<int> vis(n);
        auto dfs = [&](auto &&dfs, int i) -> bool {
            long long x1 = circles[i][0], y1 = circles[i][1], r1 = circles[i][2];
            // 圆 i 是否与矩形右边界/下边界相交相切
            if (y1 <= Y && abs(x1 - X) <= r1 || x1 <= X && y1 <= r1 || x1 > X && in_circle(x1, y1, r1, X, 0)) {
                return true;
            }
            vis[i] = true;
            for (int j = 0; j < n; j++) {
                long long x2 = circles[j][0], y2 = circles[j][1], r2 = circles[j][2];
                // 在两圆相交相切的前提下，点 A 是否严格在矩形内
                if (!vis[j] && (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2) &&
                    x1 * r2 + x2 * r1 < (r1 + r2) * X && y1 * r2 + y2 * r1 < (r1 + r2) * Y && dfs(dfs, j)) {
                    return true;
                }
            }
            return false;
        };
        for (int i = 0; i < n; i++) {
            long long x = circles[i][0], y = circles[i][1], r = circles[i][2];
            if (in_circle(x, y, r, 0, 0) || // 圆 i 包含矩形左下角
                in_circle(x, y, r, X, Y) || // 圆 i 包含矩形右上角
                // 圆 i 是否与矩形上边界/左边界相交相切
                !vis[i] && (x <= X && abs(y - Y) <= r || y <= Y && x <= r || y > Y && in_circle(x, y, r, 0, Y)) &&
                    dfs(dfs, i)) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>> &circles) {
        const int N = circles.size();
        vector<bool> visited(N, false);
        for (int i = 0; i < N; i++) {
            long long x = circles[i][0], y = circles[i][1], r = circles[i][2];
            if (isPointInCircle(0, 0, x, y, r)
                || isPointInCircle(xCorner, yCorner, x, y, r)
                || (!visited[i]
                    && (x <= xCorner
                            && abs(y - yCorner) <= r || y <= yCorner
                            && x <= r || y > yCorner
                            && isPointInCircle(0, yCorner, x, y, r))
                    && dfs(i, circles, visited, xCorner, yCorner))) {
                return false;
            }
        }
        return true;
    }

private:
    bool dfs(int i, vector<vector<int>> &circles, vector<bool> &visited, int X, int Y) {
        visited[i] = true;
        long long x1 = circles[i][0], y1 = circles[i][1], r1 = circles[i][2];
        if (y1 <= Y && abs(x1 - X) <= r1 ||
            x1 <= X && y1 <= r1 ||
            x1 > X && isPointInCircle(X, 0, x1, y1, r1)) {
            return true;
        }
        visited[i] = true;
        for (int j = 0; j < circles.size(); j++) {
            if (j == i) {
                continue;
            }
            long long x2 = circles[j][0], y2 = circles[j][1], r2 = circles[j][2];
            // 在两圆相交相切的前提下，点 A 是否严格在矩形内
            if (!visited[j] && (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2) &&
                x1 * r2 + x2 * r1 < (r1 + r2) * X &&
                y1 * r2 + y2 * r1 < (r1 + r2) * Y &&
                dfs(j, circles, visited, X, Y)) {
                return true;
            }
        }
        return false;
    }

    bool isPointInCircle(long long px, long long py, long long cx, long long cy, long long cr) {
        return (px - cx) * (px - cx) + (py - cy) * (py - cy) <= cr * cr;
    }
};

class Solution3 {
public:
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>> &circles) {
        const int N = circles.size();
        vector<int> parents(N + 4, 0);
        vector<int> ranks(N + 4, 0);
        iota(parents.begin(), parents.end(), 0);
        for (int i = 0; i < N; i++) {
            auto &c1 = circles[i];
            long long x1 = c1[0], y1 = c1[1], r1 = c1[2];
            if (isPointInCircle(0, 0, x1, y1, r1) || isPointInCircle(xCorner, yCorner, x1, y1, r1)) {
                return false;
            }
            if (x1 - xCorner >= r1 || y1 - yCorner >= r1) {
                continue;
            }
            if (abs(y1) <= r1 && x1 <= xCorner) {
                connect(i, N, parents, ranks);
                if (!check(N, parents)) {
                    return false;
                }
            }
            if (abs(x1) <= r1 && y1 <= yCorner) {
                connect(i, N + 1, parents, ranks);
                if (!check(N, parents)) {
                    return false;
                }
            }
            if (abs(yCorner - y1) <= r1 && x1 <= xCorner) {
                connect(i, N + 2, parents, ranks);
                if (!check(N, parents)) {
                    return false;
                }
            }
            if (abs(xCorner - x1) <= r1 && y1 <= yCorner) {
                connect(i, N + 3, parents, ranks);
                if (!check(N, parents)) {
                    return false;
                }
            }
            for (int j = 0; j < N; j++) {
                if (j == i) {
                    continue;
                }
                auto &c2 = circles[j];
                long long x2 = c2[0], y2 = c2[1], r2 = c2[2];
                if (pow(x1 - x2, 2) + pow(y1 - y2, 2) <= pow(r1 + r2, 2)
                    && x1 * r2 + x2 * r1 < (r1 + r2) * xCorner
                    && y1 * r2 + y2 * r1 < (r1 + r2) * yCorner) {
                    connect(i, j, parents, ranks);
                    if (!check(N, parents)) {
                        return false;
                    }
                }
            }
        }
//        if (findParent(N, parents) == findParent(N + 1, parents) ||
//            findParent(N, parents) == findParent(N + 2, parents) ||
//            findParent(N + 2, parents) == findParent(N + 3, parents) ||
//            findParent(N + 1, parents) == findParent(N + 3, parents)) {
//            return false;
//        }
//        return true;
        return check(N, parents);
    }

private:
    void connect(int u, int v, vector<int> &parents, vector<int> &ranks) {
        int pu = findParent(u, parents);
        int pv = findParent(v, parents);
        if (pu == pv) {
            return;
        }
        if (ranks[pu] > ranks[pv]) {
            parents[pv] = pu;
        } else if (ranks[pv] > ranks[pu]) {
            parents[pu] = pv;
        } else {
            parents[pv] = pu;
            ranks[pu]++;
        }
    }

    int findParent(int u, vector<int> &parents) {
        while (parents[u] != u) {
            parents[u] = parents[parents[u]];
            u = parents[u];
        }
        return u;
    }

    bool isPointInCircle(long long px, long long py, long long cx, long long cy, long long cr) {
        return (px - cx) * (px - cx) + (py - cy) * (py - cy) <= cr * cr;
    }

    bool check(int N, vector<int> &parents) {
        if (findParent(N, parents) == findParent(N + 1, parents) ||
            findParent(N, parents) == findParent(N + 2, parents) ||
            findParent(N + 2, parents) == findParent(N + 3, parents) ||
            findParent(N + 1, parents) == findParent(N + 3, parents)) {
            return false;
        }
        return true;
    }
};

bool isPointInCircle2(long long px, long long py, long long cx, long long cy, long long cr) {
    if (pow(px - cx, 2) + pow(py - cy, 2) == pow(cr, 2)) {
        fmt::println("on circle!");
    }
    return pow(px - cx, 2) + pow(py - cy, 2) <= pow(cr, 2);
}

bool in_circle(long long ox, long long oy, long long r, long long x, long long y) {
    return (ox - x) * (ox - x) + (oy - y) * (oy - y) <= r * r;
}

int main() {
    //        auto f = [](int xCorner, int yCorner, vector<vector<int>> &&circles, bool expect) {
    //            auto output = Solution().canReachCorner(xCorner, yCorner, circles);
    //            leetcode_assert(output == expect, "check_if_the_rectangle_corner_is_reachable xCorner={} yCorner={}
    //            circles={} expect={} output={}", xCorner, yCorner, circles, expect, output);
    //        };
    //        f(3, 3, {{7, 6, 5}}, false);
    fmt::println("{}", isPointInCircle2(499980000, 699999999, 200000000, 500000000, 500000000));
    fmt::println("{}", in_circle(499980000, 699999999, 200000000, 500000000, 500000000));
}
