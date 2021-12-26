class Solution {
public:
    
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    
        int n = hand.size();
        
        if(n % groupSize != 0)                                      return false;
        
        // Can or cannot be possible
        sort(hand.begin(), hand.end());

        while(hand.size() > 0) {

            int temp = hand[0];

            // Form the group and remove the group
            for(int c=0; c<groupSize; c++) {

                auto it = find(hand.begin(), hand.end(), temp);

                if(it != hand.end())                            hand.erase(it);    
                else                                            return false;

                temp++;
            }
        }

        return true;
    }
    
};