//
// Created by 汪喆昊 on 2024/3/27.
//

#ifndef LEETCODE_CPP_LEETCODE_UTILS_HPP
#define LEETCODE_CPP_LEETCODE_UTILS_HPP

#include <fmt/format.h>
#include <fmt/ranges.h>
#include <map>
#include <string>
#include <vector>

template <typename... Args>
void leetcode_assert(bool is_right, const fmt::format_string<Args...> fmt_str, Args &&...args) {
    auto desc = fmt::format(fmt_str, std::forward<Args>(args)...);
    if (is_right) {
        fmt::println("[PASSED] {}", desc);
    } else {
        fmt::println("[FAILED] {}", desc);
    }
}

void leetcode_assert(bool is_right, std::string str) {
    if (is_right) {
        fmt::println("[PASSED] {}", str);
    } else {
        fmt::println("[FAILED] {}", str);
    }
}

#endif // LEETCODE_CPP_LEETCODE_UTILS_HPP
