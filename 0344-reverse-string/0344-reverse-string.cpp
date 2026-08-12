class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        string res = "";
        for(int i = 0; i < s.size(); i++)
        {
            st.push(s[i]);
        }
        while(!st.empty())
        {
            char c = st.top();
            st.pop();
            res.push_back(c);
        }
        for(int i = 0; i < s.size(); i++)
        {
            s[i] = res[i];
        }
    }
};