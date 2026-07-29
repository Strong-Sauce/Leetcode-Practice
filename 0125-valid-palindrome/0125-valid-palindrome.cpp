#include <typeinfo>
class Solution {
public:
    bool isPalindrome(string s) {
        int size=s.size();
    for(int i=0,j=size-1; i<=j ; ){
        if((65<=int(s[i]) && int(s[i])<=90) || (97<=int(s[i]) && int(s[i])<=122) || (48<=int(s[i]) && int(s[i])<=57) ){
            if((65<=int(s[j]) && int(s[j])<=90) || (97<=int(s[j]) && int(s[j])<=122) || (48<=int(s[j]) && int(s[j])<=57)){
                if (s[i] == s[j] || ((int(s[i])-int(s[j]) ==32 || int(s[i])-int(s[j]) ==(-32)) && ((65<=int(s[i]) && int(s[i])<=90) || (97<=int(s[i]) && int(s[i])<=122) && (65<=int(s[j]) && int(s[j])<=90) || (97<=int(s[j]) && int(s[j])<=122)))) {     
                    i++, j--;
                } 
                else {   
                    return 0;
                }
            }
            else {
                j--;
            }
        }
        else{
            i++;
        }
    }
    return 1;
    }
};