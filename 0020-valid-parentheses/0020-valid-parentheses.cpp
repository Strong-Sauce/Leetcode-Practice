class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('*');
        for(int i=0; i<s.size(); i++){
            if(s[i] == ')'){
                if(st.top() != '(') return 0;
                st.pop();
            }
            else if(s[i] == '}'){
                if(st.top() != '{') return 0;
                st.pop();
            }
            else if(s[i] == ']'){
                if(st.top() != '[') return 0;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.size() == 1) return 1;
        return 0;
    }
};