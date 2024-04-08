//
// https://leetcode.com/problems/find-median-from-data-stream/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

class MedianFinder {
private:
    priority_queue<double> max_heap;
    priority_queue<double, vector<double>, greater<>> min_heap;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (max_heap.empty()) {
            max_heap.push(num);
            return;
        }
        if (max_heap.size() == min_heap.size()) {
            double max_curr = max_heap.top();
            double min_curr = min_heap.top();
            if (min_curr < num) {
                max_heap.push(min_curr);
                min_heap.pop();
                min_heap.push(num);
            } else if (max_curr <= num && num <= min_curr) {
                max_heap.push(num);
            } else {
                min_heap.push(max_curr);
                max_heap.pop();
                max_heap.push(num);
            }
        } else if (max_heap.size() > min_heap.size()) {
            double curr = max_heap.top();
            if (curr < num) {
                min_heap.push(num);
            } else {
                min_heap.push(curr);
                max_heap.pop();
                max_heap.push(num);
            }
        } else {
            double curr = min_heap.top();
            if (curr < num) {
                max_heap.push(curr);
                min_heap.pop();
                min_heap.push(num);
            } else {
                max_heap.push(num);
            }
        }
    }

    double findMedian() {
        if (max_heap.empty()) {
            return 0;
        }
        if (max_heap.size() == min_heap.size()) {
            return (max_heap.top() + min_heap.top()) / 2;
        }
        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        } else {
            return min_heap.top();
        }
    }
};

int main() {
    //    auto f = [](, int expect) {
    //        ;
    //        leetcode_assert(output == expect, "find_median_from_data_stream expect={} output={}", expect, output);
    //    };
    //    f();
//    {
//        auto finder = MedianFinder();
//        finder.addNum(1);
//        finder.addNum(2);
//        fmt::println("findMedian() = {}", finder.findMedian());
//        finder.addNum(3);
//        fmt::println("findMedian() = {}", finder.findMedian());
//    }
    {
        auto finder = MedianFinder();
        finder.addNum(6);
        finder.addNum(10);
        finder.addNum(2);
        finder.addNum(6);
        finder.addNum(5);
        finder.addNum(0);
        finder.addNum(6);
        fmt::println("findMedian() = {}", finder.findMedian());
    }
}
