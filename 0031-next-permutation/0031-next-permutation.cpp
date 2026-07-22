class Solution {
public:
    void nextPermutation(vector<int>& A) {
    // Step 1: Find the Pivot
    int pivot = -1;
    int n = A.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            pivot = i;
            break;
        }
    }
    // If no pivot is found, we are at the last permutation
    if (pivot == -1)
    {
        reverse(A.begin(), A.end());
        return;
    }
    // Step 2: Next Larger Element
    for (int i = n - 1; i > pivot; i--)
    {
        if (A[i] > A[pivot])
        {
            swap(A[i], A[pivot]);
            break;
        }
    }
    // Step 3: Reverse (pivot + 1) to end
    // reverse(A.begin() + pivot + 1, A.end());
    int i = pivot + 1, j = n - 1;
    while (i < j)
    {
        swap(A[i], A[j]);
        i++;
        j--;
    }
    }
};