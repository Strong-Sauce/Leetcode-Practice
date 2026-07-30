#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> left; // max-heap for smaller half
    priority_queue<int, vector<int>, greater<int>> right; // min-heap for larger half

public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: push into max-heap first
        left.push(num);

        // Step 2: balance left -> right (largest of left goes to right)
        right.push(left.top());
        left.pop();

        // Step 3: rebalance if right is bigger
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) return left.top();
        return (left.top() + right.top()) / 2.0;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */