class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long common = min(need1,need2);
        long long extra = abs(need1-need2);

        long long commoncost = common*min(costBoth ,(cost1+cost2));

        long long extrasinglecost = need1>need2 ? cost1 : cost2;

        long long extracost = extra*min((long long)costBoth,extrasinglecost);

        return commoncost + extracost;
    }
};