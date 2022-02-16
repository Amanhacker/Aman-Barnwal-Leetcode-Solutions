class Solution {
public:
    
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
    
        // Given 2 segment (left1, right1), (left2, right2), how can we check whether they overlap?
        // If these two intervals overlap, it should exist an number x,

        // left1 < x < right1 && left2 < x < right2
        // left1 < x < right2 && left2 < x < right1

        // left1 < right2 && left2 < right1 is the sufficient condition
      
        // For X-Coordinate
        int left1 = r1[0], right1 = r1[2];
        int left2 = r2[0], right2 = r2[2];
        
        // For Y-Coordinate
        int left3 = r1[1], right3 = r1[3];
        int left4 = r2[1], right4 = r2[3];
            
        return ( (left1 < right2 && left2 < right1) && (left3 < right4 && left4 < right3) );
    }
    
};