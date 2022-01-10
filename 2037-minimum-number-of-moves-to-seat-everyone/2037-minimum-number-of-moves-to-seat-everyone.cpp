class Solution {
public:
   
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        
        int moves = 0;
        
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int n = seats.size();
        
        for(int i=0; i<n; i++) {
            moves += abs(students[i] - seats[i]);
        }
        
        return moves;
    }
    
};