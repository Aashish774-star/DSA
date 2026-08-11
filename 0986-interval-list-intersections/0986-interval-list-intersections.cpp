class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {\
        vector<vector<int>> a = firstList;
        vector<vector<int>> b = secondList;
        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i < firstList.size() && j < secondList.size())
        {
            int st1 = a[i][0];
            int end1 = a[i][1];
            int st2 = b[j][0];
            int end2 = b[j][1];
            if(st1 <= st2)
            {
                if(end1 >= st2)
                {
                    int s = max(st1, st2);
                    int e = min(end1,end2);
                    res.push_back({s,e});
                }
            }
            else
                {
                    if(end2 >= st1)
                    {
                    int s = max(st1, st2);
                    int e = min(end1,end2);
                    res.push_back({s,e});
                    }
                }
            if(end1 <= end2)
            i++;
            else
            j++;
        }
        return res;
    }
};