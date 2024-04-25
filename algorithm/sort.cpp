//
// Created by 汪喆昊 on 2024/4/13.
//

#include "leetcode_utils.hpp"

using namespace std;

void quick_sort(vector<int> &vec);
void heap_sort(vector<int> &vec);
void merge_sort(vector<int> &vec);

// helper
void _merge_sort(vector<int> &vec, int start, int end);
void merge(vector<int> &vec, int start, int mid, int end);
void _quick_sort(vector<int> &vec, int start, int end);
void heapify(vector<int> &vec, int len, int index);

void merge_sort(vector<int> &vec) {
    _merge_sort(vec, 0, vec.size() - 1);
}

void _merge_sort(vector<int> &vec, int start, int end) {
    if (end <= start) {
        return;
    }
    int mid = (start + end) / 2;
    _merge_sort(vec, start, mid);
    _merge_sort(vec, mid + 1, end);
    merge(vec, start, mid, end);
}

void merge(vector<int> &vec, int start, int mid, int end) {
    vector<int> buff(end - start + 1, 0);
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (vec[i] < vec[j]) {
            buff[k] = vec[i];
            i++;
        } else {
            buff[k] = vec[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        buff[k] = vec[i];
        i++;
        k++;
    }
    while (j <= mid) {
        buff[k] = vec[j];
        j++;
        k++;
    }

    for (int m = start, n = 0; m <= end; m++, n++) {
        vec[m] = buff[n];
    }
}

void heapify(vector<int> &vec, int len, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int max_index = index;
    if (left < len && vec[left] > vec[max_index]) {
        max_index = left;
    }
    if (right < len && vec[right] > vec[max_index]) {
        max_index = right;
    }
    if (max_index != index) {
        swap(vec[max_index], vec[index]);
        heapify(vec, len, max_index);
    }
}

void heap_sort(vector<int> &vec) {
    for (int i = vec.size() / 2; i >= 0; i--) {
        heapify(vec, vec.size(), i);
    }

    for (int i = vec.size() - 1; i >= 1; i--) {
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

void test_heap_sort() {
    vector<int> vec{23, 12, -10, 2, 5, 13, 6, 7, 8, -12};
    fmt::println("before {}", vec);
    heap_sort(vec);
    fmt::println("after {}", vec);
}

void test_merge_sort() {
    vector<int> vec{23, 12, -10, 2, 5, 13, 6, 7, 8, -12};
    fmt::println("before {}", vec);
    merge_sort(vec);
    fmt::println("after {}", vec);
}

int main() {
    //    test_heap_sort();
    test_merge_sort();
}
