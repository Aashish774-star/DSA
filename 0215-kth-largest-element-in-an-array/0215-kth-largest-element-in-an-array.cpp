class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // Min-heap to keep track of the k largest elements
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};

/*sort
return nums[n-k];*/