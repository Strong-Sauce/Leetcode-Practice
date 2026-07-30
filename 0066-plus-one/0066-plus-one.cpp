#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;   // just add 1 and return
                return digits;
            }
            digits[i] = 0;     // carry over
        }
        // if we reach here, all digits were 9 → need new leading 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
