cmake_minimum_required(VERSION 3.27)
project(leetcode_cpp)
include(FetchContent)

set(CMAKE_CXX_STANDARD 20)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 10.1.1
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/fmt)
FetchContent_MakeAvailable(fmt)

include_directories("./dependencies")
include_directories("./utils")

link_libraries(fmt::fmt-header-only)

add_library(utils STATIC
        utils/leetcode_utils.hpp
        utils/list_node.cpp
        utils/list_node.h)
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/utils)

link_libraries(utils)

add_executable(longest_substr leetcode/longest_substr.cpp)
add_executable(add_binary leetcode/add_binary.cpp)
add_executable(bytedance leetcode/bytedance.cpp)
add_executable(two_sum leetcode/two_sum.cpp)
add_executable(add_two_numbers leetcode/add_two_numbers.cpp)
add_executable(kth_largest leetcode/kth_largest.cpp)
add_executable(letter_combinations leetcode/letter_combinations.cpp)
add_executable(combinations leetcode/combinations.cpp)
add_executable(replace_brace leetcode/replace_brace.cpp)
add_executable(permutations leetcode/permutations.cpp)
add_executable(combination_sum leetcode/combination_sum.cpp)
add_executable(generate_parentheses leetcode/generate_parentheses.cpp)
add_executable(word_search leetcode/word_search.cpp)
add_executable(n_queens_ii leetcode/n_queens_ii.cpp)
add_executable(tencent leetcode/tencent.cpp)
add_executable(powx_n leetcode/powx_n.cpp)
add_executable(max_points_on_a_line leetcode/max_points_on_a_line.cpp)
add_executable(find_k_pairs_with_smallest_sums leetcode/find_k_pairs_with_smallest_sums.cpp)
add_executable(trie_prefix_tree leetcode/trie_prefix_tree.cpp)
add_executable(design_add_and_search_words_data_structure leetcode/design_add_and_search_words_data_structure.cpp)
add_executable(word_search_ii leetcode/word_search_ii.cpp)
add_executable(number_of_1_bits leetcode/number_of_1_bits.cpp)
add_executable(single_number leetcode/single_number.cpp)
add_executable(single_number_ii leetcode/single_number_ii.cpp)
add_executable(bitwise_and_of_numbers_range leetcode/bitwise_and_of_numbers_range.cpp)
add_executable(search_insert_position leetcode/search_insert_position.cpp)
add_executable(search_a_2d_matrix leetcode/search_a_2d_matrix.cpp)
add_executable(find_peak_element leetcode/find_peak_element.cpp)
add_executable(search_in_rotated_sorted_array leetcode/search_in_rotated_sorted_array.cpp)
add_executable(find_first_and_last_position_of_element_in_sorted_array leetcode/find_first_and_last_position_of_element_in_sorted_array.cpp)
add_executable(find_minimum_in_rotated_sorted_array leetcode/find_minimum_in_rotated_sorted_array.cpp)
add_executable(median_of_two_sorted_arrays leetcode/median_of_two_sorted_arrays.cpp)
add_executable(triangle leetcode/triangle.cpp)
add_executable(minimum_path_sum leetcode/minimum_path_sum.cpp)
add_executable(unique_paths_ii leetcode/unique_paths_ii.cpp)
add_executable(longest_palindromic_substring leetcode/longest_palindromic_substring.cpp)
add_executable(interleaving_string leetcode/interleaving_string.cpp)
add_executable(edit_distance leetcode/edit_distance.cpp)
add_executable(maximal_square leetcode/maximal_square.cpp)
add_executable(ipo leetcode/ipo.cpp)
