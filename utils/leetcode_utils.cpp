//
// Created by 汪喆昊 on 2024/4/11.
//

#include "leetcode_utils.hpp"

using namespace std;

std::vector<std::vector<int>> make2DIntVecByStr(std::string &&vec_str) {
    vector<vector<int>> res;
    vector<int> sub_vec;
    int bracket_cnt = 0;
    int i = 0;
    while (i < vec_str.size()) {
        if (isdigit(vec_str[i]) && bracket_cnt == 2) {
            int j = i + 1;
            for (; j < vec_str.size(); j++) {
                if (!isdigit(vec_str[j])) {
                    break;
                }
            }
            string num_str = vec_str.substr(i, j - i);
            int num = stoi(num_str);
            if (i != 0 && vec_str[i - 1] == '-') {
                num = -num;
            }
            sub_vec.push_back(num);
            i = j;
        } else if (vec_str[i] == '[') {
            bracket_cnt++;
            i++;
        } else if (vec_str[i] == ']') {
            bracket_cnt--;
            if (bracket_cnt == 1) {
                res.push_back(sub_vec);
                sub_vec.clear();
            }
            i++;
        } else {
            i++;
        }
    }
    return res;
}

std::vector<std::vector<std::string>> make2DStrVecByStr(std::string &&vec_str) {
    vector<vector<string>> res;
    vector<string> sub_vec;
    int bracket_cnt = 0;
    int i = 0;
    while (i < vec_str.size()) {
        if (vec_str[i] == '\"' && bracket_cnt == 2) {
            int j = i + 1;
            for (; j < vec_str.size(); j++) {
                if (vec_str[j] == '\"') {
                    break;
                }
            }
            string str = vec_str.substr(i + 1, j - i - 1);
            sub_vec.push_back(str);
            i = j + 1;
        } else if (vec_str[i] == '[') {
            bracket_cnt++;
            i++;
        } else if (vec_str[i] == ']') {
            bracket_cnt--;
            if (bracket_cnt == 1) {
                res.push_back(sub_vec);
                sub_vec.clear();
            }
            i++;
        } else {
            i++;
        }
    }
    return res;
}

std::vector<int> makeIntVecByStr(std::string &&vec_str) {
    vector<int> res;
    int i = 0;
    while (i < vec_str.size()) {
        if (isdigit(vec_str[i])) {
            int j = i + 1;
            for (; j < vec_str.size(); j++) {
                if (!isdigit(vec_str[j])) {
                    break;
                }
            }
            string num_str = vec_str.substr(i, j - i);
            int num = stoi(num_str);
            if (i != 0 && vec_str[i - 1] == '-') {
                num = -num;
            }
            res.push_back(num);
            i = j + 1;
        } else {
            i++;
        }
    }
    return res;
}
