class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_ending = nums[0];
        int ans = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            int v1 = best_ending + nums[i];
            int v2 = nums[i];
            best_ending = max(v1,v2);
            ans = max(ans, best_ending); 
        }
        return ans;
    }

    int smallestSumSubarray(vector<int>& arr) {
        int best_ending = arr[0];
        int ans = arr[0];
        int n = arr.size();
        for(int i = 1; i < n; i++)
        {
            int v1 = best_ending + arr[i];
            int v2 = arr[i];
            best_ending = min(v1,v2);
            ans = min(ans,best_ending);
        }
        return ans;
    }

    int maxAbsoluteSum(vector<int>& nums) {
       
        int maxSum = maxSubArray(nums);
        int minSum = smallestSumSubarray(nums);

        return max(abs(maxSum), abs(minSum));


    }
};