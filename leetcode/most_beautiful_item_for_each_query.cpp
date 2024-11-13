//
// https://leetcode.com/problems/most-beautiful-item-for-each-query/?envType=daily-question&envId=2024-11-12
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
        const int N = items.size(), M = queries.size();
        map<int, int> priceToMaxBeauty;
        for (int i = 0; i < N; i++) {
            int price = items[i][0], beauty = items[i][1];
            priceToMaxBeauty[price] = max(priceToMaxBeauty[price], beauty);
        }
        vector<pair<int, int>> newItems;
        int maxBeauty = 0;
        for (auto it = priceToMaxBeauty.begin(); it != priceToMaxBeauty.end(); it++) {
            auto [price, beauty] = *it;
            maxBeauty = max(maxBeauty, beauty);
            newItems.emplace_back(price, maxBeauty);
        }
        vector<int> ans(M, 0);
        for (int i = 0; i < M; i++) {
            int idx = -1;
            int query = queries[i];
            int start = 0, end = newItems.size() - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                int price = newItems[mid].first;
                if (price <= query) {
                    idx = mid;
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            ans[i] = idx != -1 ? newItems[idx].second : 0;
        }
        return ans;
    }
};

int main() {
    auto f = [](vector<vector<int>> &&items, vector<int> &&queries, vector<int> &&expect) {
        auto output = Solution().maximumBeauty(items, queries);
        leetcode_assert(output == expect, "most_beautiful_item_for_each_query items={} queries={} expect={} output={}",
                        items, queries, expect, output);
    };
//    f(make2DIntVecByStr("[[1,2],[3,2],[2,4],[5,6],[3,5]]"), {1, 2, 3, 4, 5, 6}, {2, 4, 5, 5, 6, 6});
    f(make2DIntVecByStr(
          "[[193,732],[781,962],[864,954],[749,627],[136,746],[478,548],[640,908],[210,799],[567,715],[914,388],[487,"
          "853],[533,554],[247,919],[958,150],[193,523],[176,656],[395,469],[763,821],[542,946],[701,676]]"),
      {885, 1445, 1580, 1309, 205, 1788, 1214, 1404, 572, 1170, 989, 265, 153, 151, 1479, 1180, 875, 276, 1584},
      {962, 962, 962, 962, 746, 962, 962, 962, 946, 962, 962, 919, 746, 746, 962, 962, 962, 919, 962});
}
