class Solution {
public:
    
    string encode(int num) {
    
        string res = "";
        
        res = bitset<32>(num + 1).to_string().substr(32-(int)log2(num + 1));
        return res;
    }
    
};