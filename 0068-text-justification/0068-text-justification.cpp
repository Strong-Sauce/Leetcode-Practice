class Solution {
    vector<string> ans;

    void sol(vector<string>& words, int mw, int l, int r) {
        int wordLen = 0;

        // Total length of words
        for(int i = l; i < r; i++)
            wordLen += words[i].size();

        int gaps = r - l - 1;

        // Single word
        if(gaps == 0) {
            string s = words[l];
            s += string(mw - s.size(), ' ');
            ans.push_back(s);
            return;
        }

        int totalSpaces = mw - wordLen;

        int spaces = totalSpaces / gaps;
        int extra = totalSpaces % gaps;

        string s = "";

        for(int i = l; i < r; i++) {
            s += words[i];

            if(i < r - 1) {
                int currSpaces = spaces;

                // First `extra` gaps get one additional space
                if(i - l < extra)
                    currSpaces++;

                s += string(currSpaces, ' ');
            }
        }

        ans.push_back(s);
    }

public:
    vector<string> fullJustify(vector<string>& words, int mw) {

        int n = words.size();

        int l = 0;
        int wordLen = 0;

        for(int r = 0; r < n; r++) {

            // Minimum spaces between r-l+1 words = r-l
            int required = wordLen + words[r].size() + (r - l);

            if(required <= mw) {
                wordLen += words[r].size();
            }
            else {
                // words[l ... r-1] form one line
                sol(words, mw, l, r);

                l = r;
                wordLen = words[r].size();
            }
        }

        // Last line
        string last = "";

        for(int i = l; i < n; i++) {
            if(i > l)
                last += " ";

            last += words[i];
        }

        last += string(mw - last.size(), ' ');

        ans.push_back(last);

        return ans;
    }
};