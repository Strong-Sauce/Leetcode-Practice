// top down
// class Solution {
// public:
//     vector<int> memo;
//     vector<string> wordDict;
//     string s;

//     bool wordBreak(string s, vector<string>& wordDict) {
//         memo = vector(s.length(), -1);
//         this->wordDict = wordDict;
//         this->s = s;
//         return dp(s.length() - 1);
//     }

//     bool dp(int i) {
//         if (i < 0) return true;

//         if (memo[i] != -1) {
//             return memo[i] == 1;
//         }

//         for (string word : wordDict) {
//             int currSize = word.length();
//             // Handle out of bounds case
//             if (i - currSize + 1 < 0) {
//                 continue;
//             }

//             if (s.substr(i - currSize + 1, currSize) == word &&
//                 dp(i - currSize)) {
//                 memo[i] = 1;
//                 return true;
//             }
//         }

//         memo[i] = 0;
//         return false;
//     }
// };

// bottom up
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         vector<bool> dp(s.length());
//         for (int i = 0; i < s.length(); i++) {
//             for (string word : wordDict) {
//                 // Handle out of bounds case
//                 if (i < word.length() - 1) {
//                     continue;
//                 }

//                 if (i == word.length() - 1 || dp[i - word.length()]) {
//                     if (s.substr(i - word.length() + 1, word.length()) ==
//                         word) {
//                         dp[i] = true;
//                         break;
//                     }
//                 }
//             }
//         }
//         return dp[s.length() - 1];
//     }
// };

// another dp aproch
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};