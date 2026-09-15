#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to check if substring s[l...r] is a palindrome
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; 
            r--;
        }
        return true;
    }

    // Top-Down Recursive Helper Function
    int solve(int i, int n, int k, const string& s, vector<int>& memo) {
        // Base Case: Reached or exceeded string length
        if (i >= n) {
            return 0;
        }

        // Return memoized result if already computed
        if (memo[i] != -1) {
            return memo[i];
        }

        // Choice 1: Skip current character s[i]
        int ans = solve(i + 1, n, k, s, memo);

        // Choice 2: Try palindrome of length 'k' starting at index i
        if (i + k <= n && isPalindrome(s, i, i + k - 1)) {
            ans = max(ans, 1 + solve(i + k, n, k, s, memo));
        }

        // Choice 3: Try palindrome of length 'k + 1' starting at index i
        if (i + k + 1 <= n && isPalindrome(s, i, i + k)) {
            ans = max(ans, 1 + solve(i + k + 1, n, k, s, memo));
        }

        // Store result in DP table and return
        return memo[i] = ans;
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        // memo[i] stores max palindromes starting from index i to n-1
        vector<int> memo(n + 1, -1);

        // Start top-down recursion from index 0
        return solve(0, n, k, s, memo);
    }
};