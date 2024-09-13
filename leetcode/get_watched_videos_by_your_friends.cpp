//
// https://leetcode.com/problems/get-watched-videos-by-your-friends/
//

#include "leetcode_utils.hpp"

using namespace std;

vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id,
                                      int level) {
    int N = watchedVideos.size();
    deque<int> dq; // dist, idx
    vector<bool> visited(N, false);
    unordered_map<string, int> video_freq;

    visited[id] = true;
    dq.push_back(id);
    while (!dq.empty() && level > 0) {
        int size = dq.size();
        for (int i = 0; i < size; i++) {
            int node = dq.front();
            dq.pop_front();
            for (int nbr : friends[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    dq.push_back(nbr);
                }
            }
        }
        level--;
    }
    while (!dq.empty()) {
        for (string &video : watchedVideos[dq.front()]) {
            video_freq[video]++;
        }
        dq.pop_front();
    }
    vector<string> ans;
    for (auto &p : video_freq) {
        ans.push_back(p.first);
    }
    sort(ans.begin(), ans.end(), [&](auto &a, auto &b) {
        int fa = video_freq[a];
        int fb = video_freq[b];
        return fa < fb || (fa == fb && a < b);
    });
    return ans;
}

int main() {
    auto f = [](vector<vector<string>> &&watchedVideos, vector<vector<int>> &&friends, int id, int level,
                vector<string> &&expect) {
        auto output = watchedVideosByFriends(watchedVideos, friends, id, level);
        leetcode_assert(
            output == expect,
            "get_watched_videos_by_your_friends watchedVideos={} friends={} id={} level={} expect={} output={}",
            watchedVideos, friends, id, level, expect, output);
    };
    f({{"A", "B"}, {"C"}, {"B", "C"}, {"D"}}, {{1, 2}, {0, 3}, {0, 3}, {1, 2}}, 0, 2, {"D"});
}
