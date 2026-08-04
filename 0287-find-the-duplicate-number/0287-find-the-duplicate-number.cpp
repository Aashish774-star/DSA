class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     int slow = 0;
     int fast = 0;
     // Phase 1: Detect cycle 
     while(true){
        slow = nums[slow];
        fast = nums[fast];
        fast = nums[fast];
       // fast = nums[nums[fast]];
        // Phase 2: Find duplicate (cycle entrance)
        if(slow == fast)
        {
            slow = 0;
            while(slow != fast)
            {
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
     }   
     return -1;
    }
};