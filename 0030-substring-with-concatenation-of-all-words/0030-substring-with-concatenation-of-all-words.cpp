class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size();
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        
        if (totalLen > n) return ans;

        unordered_map<string, int> need;

        for (string word : words) need[word]++;

        for (int offset=0; offset<wordLen; offset++) {
            int l = offset;
            int count = 0;

            unordered_map<string, int> window;
            for (int r = offset; r + wordLen <= n; r += wordLen) {
                string word = s.substr(r, wordLen);
                if (need.find(word) == need.end()) {
                    window.clear();
                    count = 0;
                    l = r + wordLen;
                    continue;
                }
                window[word]++;
                count++;
                while (window[word] > need[word]) {
                    string leftWord = s.substr(l, wordLen);
                    window[leftWord]--;
                    l += wordLen;
                    count--;
                }
                if (count == wordCount) {
                    ans.push_back(l);
                    string leftWord = s.substr(l, wordLen);
                    window[leftWord]--;
                    l += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};