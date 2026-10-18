class Solution {
public:
    int digitsum(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n = n/10;
        }
        return sum;
    }
    int num_of_cycles(unordered_map<int,int>& mp,vector<int>& nums){
        int n = nums.size();
        vector<bool> visited(n,0);
        int cycles = 0;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            cycles++;
            int j = i;
            while(!visited[j]){
                visited[j] = 1;
                j = mp[nums[j]];
            }
        }
        return cycles;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedarr = nums;
        sort(sortedarr.begin(),sortedarr.end(),[&](int a,int b){
            int sumdigitsA = digitsum(a);
            int sumdigitsB = digitsum(b);
            if(sumdigitsA==sumdigitsB) return a<b;
            else return sumdigitsA<sumdigitsB;
        });
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[sortedarr[i]] = i;
        }
        return n - num_of_cycles(mp,nums);

    }
};