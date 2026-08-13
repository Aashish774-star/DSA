class Solution { 
public: 
    vector<int> nextGreaterElements(vector<int>& nums) { 
        int n = nums.size(); 
        vector<int> res(n, -1); 
        stack<int> st; 
 
        st.push(nums[n - 1]); 
 
        for(int i = n - 2; i >= 0; i--) 
        { 
            while(!st.empty() && st.top() <= nums[i]) 
            { 
                st.pop(); 
            } 
 
            if(st.empty()) 
            res[i] = -1; 
            else 
            res[i] = st.top(); 
 
            st.push(nums[i]); 
        }

        // Circular part
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }

            if(res[i] == -1 && !st.empty())
                res[i] = st.top();

            st.push(nums[i]);
        }
 
        return res; 
    } 
};