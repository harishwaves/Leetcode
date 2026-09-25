class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        int i=0,j=0;
        while(j<m){
            j = i+n-1;
            int k = i,l=0;
            while(k<m && l<n && haystack[k]==needle[l]){
                k++;l++;
            }
            if(k==j+1) return i;
            i++;
        }
        return -1;
    }
};