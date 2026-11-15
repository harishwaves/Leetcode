class Solution {
public:
    typedef long long ll;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9+7;
        ll sum = 0;
        int ans = 0;
        int even = 1,odd = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum%2!=0){
                ans = (ans+even)%mod;
                odd++;
            }
            else{
                ans = (ans+odd)%mod;
                even++;
            }
        }
        return ans;
    }
};