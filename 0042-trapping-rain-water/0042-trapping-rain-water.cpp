class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        if(n<=2) return 0;

        int l=0,r=n-1;
        int lmax = 0, rmax = 0;
        int sum = 0, lvl = 0;
        while(l<r){
            if(arr[l] <= arr[r]){
                if(lmax > arr[l]) sum += lmax - arr[l];
                else lmax = arr[l];
                l++;
            }
            else{
                if(rmax > arr[r]) sum += rmax - arr[r];
                else rmax = arr[r];
                r--;
            }
        }
        return sum;
    }
};