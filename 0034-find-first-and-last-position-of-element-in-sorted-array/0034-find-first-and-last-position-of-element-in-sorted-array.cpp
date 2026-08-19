class Solution {
public:
    int first(vector<int>& nums, int x)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int res = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] < x)
            low = mid + 1;
            else if(nums[mid] > x)
            high = mid - 1;
            else{
            res = mid;
            high = mid - 1;
            }
        }
        return res;
    }
    int last(vector<int>& nums, int x)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int res = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] < x)
            low = mid + 1;
            else if(nums[mid] > x)
            high = mid - 1;
            else{
            res = mid;
            low = mid + 1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first(nums,target);
        int l = last(nums,target);

        return {f,l};
    }
};