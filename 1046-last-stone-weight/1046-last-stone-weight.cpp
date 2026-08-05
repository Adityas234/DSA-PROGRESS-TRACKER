class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> mh(stones.begin(), stones.end());

        while(mh.size()>1){
            int max1 = mh.top();
            mh.pop();
            int max2 = mh.top();
            mh.pop();

            if(max1 != max2){
                mh.push(max1 - max2);
            }
        }

        return mh.empty() ? 0 : mh.top();
    }
};