class Solution {
    public int removeDuplicates(int[] nums) {
        int slow = 0; //slow = unique elements ke last position
        int fast = 1; // fast = array ko scan/check karta hai
        int res = 1;  // res = unique elements ki total count
        int n = nums.length; // array ka size
        while(fast < n)
        {
            if(nums[fast] == nums[fast - 1])
            {
                fast++;
                continue;
            }
            nums[slow + 1] = nums[fast];
            slow++;
            fast++;
            res++;
        }
        return res;
    }
}