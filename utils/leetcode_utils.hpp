//
// Created by 汪喆昊 on 2024/3/27.
//

#ifndef LEETCODE_CPP_LEETCODE_UTILS_HPP
#define LEETCODE_CPP_LEETCODE_UTILS_HPP

#include <fmt/format.h>
#include <fmt/ranges.h>
#include <numeric>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>
#include <bitset>
#include "list_node.hpp"
#include "tree_node.h"

template <typename... Args>
void leetcode_assert(bool is_right, const fmt::format_string<Args...> fmt_str, Args &&...args) {
    auto desc = fmt::format(fmt_str, std::forward<Args>(args)...);
    if (is_right) {
        fmt::println("[PASSED] {}", desc);
    } else {
        fmt::println("[FAILED] {}", desc);
    }
}

std::vector<std::vector<int>> make2DIntVecByStr(std::string &&vec_str);
std::vector<std::vector<std::string>> make2DStrVecByStr(std::string &&vec_str);
std::vector<int> makeIntVecByStr(std::string &&vec_str);

#endif // LEETCODE_CPP_LEETCODE_UTILS_HPP
