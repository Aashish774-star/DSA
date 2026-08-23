class Solution {
public:

    int helper(int m, int n, int guess)
    {
        int row = m;
        int col = 1;
        int count = 0;

        while(row >= 1 && col <= n)
        {
            if(row * col <= guess)
            {
                count = count + row;
                col++;
            }
            else
            {
                row--;
            }
        }

        return count;
    }

    int findKthNumber(int m, int n, int k)
    {
        int low = 1;
        int high = m * n;

        int res = -1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            int ans = helper(m, n, mid);

            if(ans < k)
            {
                low = mid + 1;
            }
            else
            {
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};