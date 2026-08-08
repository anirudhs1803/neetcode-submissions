class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int leftmax = 0;
        int rightmax = 0;
        int total =0;

        while(l<r){
            if(height[l] < height[r]){
                leftmax = max(leftmax, height[l]);
                total+= leftmax- height[l];
                l++;
            }
            else{
                rightmax = max(rightmax, height[r]);
                total+= rightmax- height[r];
                r--;
            }
        }
        return total;
        

    }
};
