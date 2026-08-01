class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int low = 0;
        int high = 0;
        int res = 0;
        int zero = 0;

        for(high = 0; high < n; high++)
        {
            // current element 0 hai to count increase
            if(nums[high] == 0)
                zero++;

            // agar k se jyada zero ho gaye
            // left side se window shrink karo
            while(zero > k)
            {
                if(nums[low] == 0)
                    zero--;

                low++;
            }

            int len = high - low + 1;
            res = max(res, len);
        }

        return res;
    }
};
