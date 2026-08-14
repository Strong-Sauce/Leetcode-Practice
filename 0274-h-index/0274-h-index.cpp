class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int>freq(n+1,0);

        for(int i=0; i<n; i++){
            if(citations[i] >= n){
                freq[n]++;
            }else{
                freq[citations[i]]++;
            }
        }

        int index = n;
        int sum = freq[n];

        while(sum < index){
            index--;
            sum += freq[index];
        }
        return index;
    }
};