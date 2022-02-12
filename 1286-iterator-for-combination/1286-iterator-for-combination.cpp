class CombinationIterator {
public:

    vector<string> v;
    int i = -1, n;
    
    map<char, int> vis;
    string temp = "";
    
    void findAllCombinations(string temp, int ind, string s, int len) {
        
        // Base Condition
        if(s.length() == 0) {
            
            if(ind == len) {
                v.push_back(temp);
                cout << temp << " ";
            }
            
            return;
        }
        
        findAllCombinations(temp + s[0], ind + 1, s.substr(1), len);
        findAllCombinations(temp, ind, s.substr(1), len);
        
        return;
    }
    
    CombinationIterator(string s, int l) {
    
        // Store all the combination of characters of len l in sorted order in a vector

        string temp = "";        
        findAllCombinations(temp, 0, s, l);
        
        cout << "Aman";
        
        sort(v.begin(), v.end());
        
        cout << endl;
        for(auto &x : v)                                        cout << x << " ";
        cout << endl;
        
        n = v.size();
    }
    
    string next() {
        
        if(i < n-1) {
            i++;
            return v[i];
        }    
        
        return "-1";
    }
    
    bool hasNext() {
    
        return (i < n-1);
    }
    
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */