//
// https://leetcode.com/problems/design-circular-deque/
//

#include "leetcode_utils.hpp"

using namespace std;

class MyCircularDeque {
private:
    vector<int> buffer;
    int beginIdx, endIdx;
    int capacity;

    int nextIdx(int idx) {
        return (idx + 1) % (capacity + 1);
    }

    int prevIdx(int idx) {
        return (idx + capacity) % (capacity + 1);
    }

public:
    MyCircularDeque(int k) : buffer(k + 1, -1), capacity(k), beginIdx(0), endIdx(0) {}

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        beginIdx = prevIdx(beginIdx);
        buffer[beginIdx] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        buffer[endIdx] = value;
        endIdx = nextIdx(endIdx);
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        buffer[beginIdx] = -1;
        beginIdx = nextIdx(beginIdx);
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        endIdx = prevIdx(endIdx);
        buffer[endIdx] = -1;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return buffer[beginIdx];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return buffer[prevIdx(endIdx)];
    }

    bool isEmpty() {
        return beginIdx == endIdx;
    }

    bool isFull() {
        if (beginIdx == endIdx) {
            return false;
        } else if (beginIdx < endIdx) {
            return endIdx - beginIdx == capacity;
        } else {
            return beginIdx - endIdx == 1;
        }
    }
};

int main() {
    {
        auto dq = MyCircularDeque(3);
        dq.insertLast(1);
        dq.insertLast(2);
        dq.insertFront(3);
        dq.insertFront(4);
        fmt::println("{}", dq.getRear());
    }
};
