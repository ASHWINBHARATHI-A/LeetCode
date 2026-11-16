class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int c=0,n=nums.size();

        for(int i=0;i<n;i++){
            int a=nums[i],m=nums[i];

            for(int j=i;j<n;j++){
                a&=nums[j];
                m=min(m,nums[j]);
                if(a==m)c++;
            }
        }
        return c;
    }
};