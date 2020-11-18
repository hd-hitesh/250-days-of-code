class Solution {
    public:
    int t[1001];
    public:
    Solution()
    {
     memset(t,-1,sizeof(t));   
    }
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        int m,nn;
        if(t[n-1]==-1)
           t[n-1]= climbStairs(n-1);
        if(t[n-2]==-1)
            t[n-2]= climbStairs(n-2);
            m=t[n-1];
        nn=t[n-2];
        return m+nn;
    }
};