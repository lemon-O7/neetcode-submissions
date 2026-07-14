class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> triplet(3,0);
        for(int i=0;i<triplets.size();i++) {
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2]) {
                continue ;
            }
            else {
                if(triplet[0]<= target[0] && triplet[1]<= target[1] && triplet[2]<= target[2]) {
                    triplet[0] = max(triplet[0],triplets[i][0]);
                    triplet[1] = max(triplet[1],triplets[i][1]);
                    triplet[2] = max(triplet[2],triplets[i][2]);
                }
            }
        }
        

        return triplet == target;
    }
};