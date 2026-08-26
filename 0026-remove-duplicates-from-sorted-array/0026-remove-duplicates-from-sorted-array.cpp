class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0; //off
        int fast = 1; // cm
        int res = 1;
        int n = nums.size();
        while(fast < n)
        {
            if(nums[fast] == nums[fast-1])
            {
                fast++;
                continue;
            }
            nums[slow+1] = nums[fast];
            slow++;
            fast++;
            res++;
        }
        return res;
    }
};