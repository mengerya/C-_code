class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=0)
            return 0;
        int i = 0;
        for(size_t j=1;j<n;j++){
            if(A[i] != A[j])
                A[++i]=A[j];
        }
        return i+1;
    }
};
