class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        stack<int> st;
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            if(height[st.top()] < height[i]) st.push(i);
        }

        vector<int> poles;
        while(!st.empty()){
            poles.push_back(st.top());
            st.pop();
        }

        int maxi = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<poles.size(); j++){
                int w = poles[j] - i;
                int h = min(height[poles[j]] , height[i]);
                maxi = max(maxi, h * w);
            }
        }

        return maxi;
    }
};