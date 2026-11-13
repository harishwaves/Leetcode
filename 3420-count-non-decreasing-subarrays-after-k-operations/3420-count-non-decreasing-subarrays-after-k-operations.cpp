class Solution {
public:
    typedef long long ll;
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll> cumsum(n);
        cumsum[0] = nums[0];
        for(int i=1;i<n;i++){
            cumsum[i] = cumsum[i-1] + nums[i];
        }

        //Range sum
        auto RangeSum = [&](int i,int j)-> long long{
            if(i>j) return 0;
            return cumsum[j] - ((i>0) ? cumsum[i-1] : 0);
        };

        //Next greater to the right
        vector<int> NGR(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                NGR[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        //operations[i] = total operation to make i to n-1 non decreasing
        vector<ll> operations(n+1,0);
        for(int i=n-1;i>=0;i--){
            int m = NGR[i];
            ll segmentOperations = (1LL*nums[i]*(m-i)) - RangeSum(i,m-1);  //i to m-1 segment
            operations[i] = segmentOperations + operations[m];
        }

        deque<int> deq;
        ll result = 0;

        int i = 0,j=0;
        while(j<n){
            while(!deq.empty() && nums[deq.back()]<nums[j]){
                deq.pop_back();
            }
            deq.push_back(j);

            //shring if required
            while(i<=j){
                int mxidx = deq.front();
                ll op = (operations[i] - operations[mxidx]) + (1LL*nums[mxidx]*(j-mxidx+1)) - RangeSum(mxidx,j);

                if(op<=k) break;
                else{
                    i++;
                    if(deq.front() < i){
                        deq.pop_front();
                    }
                }
            }
            result += (j-i+1);
            j++;
        }
        return result;
    }
};