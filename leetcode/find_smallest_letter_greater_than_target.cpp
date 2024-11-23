//
// https://leetcode.cn/problems/find-smallest-letter-greater-than-target/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        const int N = letters.size();
        int start = 0, end = N - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int ch = letters[mid];
            if (ch > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        if (start < 0 || start >= N || letters[start] <= target) {
            return letters[0];
        }
        return letters[start];
    }
};


int main() {
    auto f = [](vector<char>&& letters, char target, char expect) {
        auto output = Solution().nextGreatestLetter(letters, target);
        leetcode_assert(output == expect, "find_smallest_letter_greater_than_target letters={} target={} expect={} output={}", letters, target, expect, output);
    };
    f();
}
