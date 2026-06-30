class Solution {
public:

    bool checkpass(int capacity, vector<int> &weights, int days){
        int required_day = 1;
        int curweight = 0;

        for(int i = 0;i<weights.size();i++){

            if(curweight+weights[i] > capacity){
                required_day++;
                curweight = weights[i];
            }else{
                curweight += weights[i];
            }
        }
        return required_day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int n = weights.size();
        for(int i = 0;i<weights.size();i++){
            sum += weights[i];
        }
        int low = *max_element(weights.begin(), weights.end());
        int high = sum;

        while(low < high){
            int mid = low + (high - low)/2;

            if(checkpass(mid, weights, days)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }

        return low;

    }
};