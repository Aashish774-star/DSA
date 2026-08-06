class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int best_ending = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int v1 = best_ending + nums[i];
            int v2 = nums[i];

            best_ending = max(v1, v2);
            ans = max(ans, best_ending);
        }

        return ans;
    }

    int minSubArray(vector<int>& nums) {
        int best_ending = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int v1 = best_ending + nums[i];
            int v2 = nums[i];

            best_ending = min(v1, v2);
            ans = min(ans, best_ending);
        }

        return ans;
    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int maxSum = maxSubArray(nums);
        int minSum = minSubArray(nums);

        // All elements negative hain
        if(maxSum < 0) {
            return maxSum;
        }

        int totalSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        int circularSum = totalSum - minSum;

        return max(maxSum, circularSum);
    }
};