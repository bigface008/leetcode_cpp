//
// https://leetcode.com/problems/string-compression/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int compress(vector<char> &chars) {
    if (chars.empty()) {
        return 0;
    }
    int i = 1;
    int j = 0; // write index
    int res = 1;
    int c_cnt = 1;
    char prev_c = chars[0];
    while (true) {
        if (i < chars.size() && chars[i] == prev_c) {
            c_cnt++;
        } else {
            chars[j] = prev_c;
            if (c_cnt == 1) {
                j += 1;
            } else {
                int num_len = 0;
                int temp_cnt = c_cnt;
                while (temp_cnt > 0) {
                    temp_cnt /= 10;
                    num_len += 1;
                }
                temp_cnt = c_cnt;
                for (int k = num_len - 1; k >= 0; k--) {
                    chars[j + 1 + k] = temp_cnt % 10 + '0';
                    temp_cnt /= 10;
                }
                j += num_len + 1;
            }
            if (i >= chars.size()) {
                break;
            }
            c_cnt = 1;
            prev_c = chars[i];
        }
        i++;
    }
    return j;
}

int main() {
    auto f = [](vector<char> &&chars, int expect) {
        auto output = compress(chars);
        leetcode_assert(output == expect, "string_compression chars={} expect={} output={}", chars, expect, output);
    };
//    f({'a', 'a', 'b', 'b', 'c', 'c', 'c'}, 6);
//    f({'a'}, 1);
    f({'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}, 4);
}
