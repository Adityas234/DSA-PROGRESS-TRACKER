class Solution {
public:

    long long hours(vector<int>& piles, int k){
        long long hour = 0;
        for(int pile : piles){
            hour += (pile + k - 1) / k;
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = low + (high-low)/2;

            if(hours(piles, mid)<=h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};