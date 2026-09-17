class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i] == target) cnt++;
        }
        if(cnt>=2) return 2;
        vector<int> pre(n,INT_MAX);
        int left=0,sum=0,ans=INT_MAX;
        for(int right=0;right<n;right++){
            sum += arr[right];
            while(sum>target){
                sum -= arr[left];
                left++;
            }
            if(sum==target){
                int len = right - left + 1;
                if(left>0 && pre[left-1] != INT_MAX){
                    ans = min(ans,len+pre[left-1]);
                }
                pre[right]=len;
            }
            if(right>0){
                pre[right] = min(pre[right],pre[right-1]);
            }
        }
            return ans == INT_MAX ? -1 : ans; 
    }
};