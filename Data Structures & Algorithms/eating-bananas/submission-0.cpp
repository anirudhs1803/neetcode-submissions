class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left =1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while(left<= right){
            int mid = left+ (right-left)/2;
            long long hoursneeded = 0;
            for(int p : piles){
                hoursneeded+= (p+mid-1)/mid;
            }

            if(hoursneeded <=h){
                result= mid;
                right= mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return result;
    }
};
