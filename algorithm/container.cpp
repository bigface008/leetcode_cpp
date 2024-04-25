//
// Created by 汪喆昊 on 2024/4/13.
//

#include "leetcode_utils.hpp"

using namespace std;

class PriorityQueue {
    friend auto format_as(PriorityQueue const& q) {
        return fmt::format("priority queue: [{}]", q.buff);
    }

public:
    PriorityQueue() = default;

    void push(pair<int, int> p) {
        buff.push_back(p);
        move_up(buff.size() - 1);
    }

    void pop() {
        if (buff.empty()) {
            return;
        }
        swap(buff[0], buff[buff.size() - 1]);
        buff.pop_back();
        move_down(buff.size(), 0);
    }

    pair<int, int> top() {
        if (buff.empty()) {
            return {0, 0};
        }
        return buff[0];
    }

    int size() const {
        return buff.size();
    }


private:
    vector<pair<int, int>> buff;

    void move_up(int child) {
        int parent = (child - 1) / 2;
        while (child > 0) {
            if (buff[parent].first < buff[child].first) {
                swap(buff[parent], buff[child]);
                child = parent;
                parent = (child - 1) / 2;
            } else {
                break;
            }
        }
    }

    void move_down(int n, int parent) {
        int child = 2 * parent + 1;
        while (child < n) {
            if (child + 1 < n && buff[child].first < buff[child + 1].first) {
                child++; // If right child node is bigger, chose the right one.
            }
            if (buff[parent].first < buff[child].first) {
                swap(buff[parent], buff[child]);
//                swap(buff[parent].first, buff[child].first);
//                swap(buff[parent].second, buff[child].second);
                parent = child;
                child = 2 * parent + 1;
            } else {
                break;
            }
        }
    }
};

int main() {
    auto q = PriorityQueue();
    q.push({-5, 23});
    q.push({12, 12});
    q.push({1, 2});
    fmt::println("{}", q);
}