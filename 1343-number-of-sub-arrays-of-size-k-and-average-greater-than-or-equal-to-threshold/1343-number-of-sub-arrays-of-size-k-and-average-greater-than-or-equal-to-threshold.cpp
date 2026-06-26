class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int cursum = 0;
        int needsum = threshold*k;

        for(int i = 0;i<k;i++){
            cursum += arr[i];
        }
        if(cursum>=needsum){
            count++;
        }
        for(int i = k;i<arr.size();i++){
            cursum += arr[i];
            cursum -= arr[i-k];

            if(cursum>=needsum){
                count++;
            }
        }
        return count;
    }
};