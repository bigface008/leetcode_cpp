//
// https://leetcode.com/problems/online-stock-span/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

class StockSpanner {
public:
    StockSpanner() = default;

    int next(int price) {
        int span = 1;
        while (!stk.empty() && price >= stk.top().first) {
            span += stk.top().second;
            stk.pop();
        }
        pair<int, int> p{price, span};
        stk.push(p);
        return p.second;
    }

private:
    stack<pair<int, int>> stk; // {val, day}
};

int main() {
    StockSpanner stockSpanner = StockSpanner();
    fmt::println("stockSpanner.next((100)) {}", stockSpanner.next(100)); // return 1
    fmt::println("stockSpanner.next((80)) {}", stockSpanner.next(80));  // return 1
    fmt::println("stockSpanner.next((60)) {}", stockSpanner.next(60));  // return 1
    fmt::println("stockSpanner.next((70)) {}", stockSpanner.next(70));  // return 2
    fmt::println("stockSpanner.next((60)) {}", stockSpanner.next(60));  // return 1
    fmt::println("stockSpanner.next((75)) {}", stockSpanner.next(75));  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
    fmt::println("stockSpanner.next((85)) {}", stockSpanner.next(85));  // return 6
}
