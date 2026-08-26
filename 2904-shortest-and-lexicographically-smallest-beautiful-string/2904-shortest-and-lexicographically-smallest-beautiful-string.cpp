class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int l = 0;
        int count = 0;
        for (int r = 0; r < n; r++) {
            if (s[r] == '1')count++;
            if (count == k) {
                while (s[l] == '0') l++;
                string temp = s.substr(l, r - l + 1);
                if (ans.empty() || temp.size() < ans.size() || (temp.size() == ans.size() && temp < ans)) ans = temp;
                l++;
                count--;
            }
        }
        return ans;
    }
};