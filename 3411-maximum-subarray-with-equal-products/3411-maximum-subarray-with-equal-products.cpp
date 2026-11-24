class Solution {
public:
    int LCM(int a,int b){
        for(int i=min(a,b);i<=a*b;i++){
            if(i%a==0 && i%b==0) return i;
        }
        return 1;
    }

    int GCD(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i=0;i<n;i++){
            long long pro = 1,gcd=nums[i],lcm=nums[i];
            for(int j=i;j<n;j++){
                if(pro > 2520*gcd*lcm) break;
                pro *= nums[j];
                lcm = LCM(lcm,nums[j]);
                gcd = GCD(gcd,nums[j]);
                if(pro==gcd*lcm) ans = max(ans,j-i+1);
            }   
        }
        return ans;
    }
};