class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(),  stones.end());
            int max1 = stones[stones.size() - 1];
            int max2 = stones[stones.size() - 2];

            if (stones.size() >= 2) {
                stones.resize(stones.size() - 2);
            }

            stones.push_back(max1-max2);
        }
        int rs = stones[0];
        return rs;
    }
};