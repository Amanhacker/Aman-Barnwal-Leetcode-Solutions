class Solution {
public:
    
   vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
    
        vector<string> res;
        unordered_map<string, int> popularity;                   // 1st arg - string, 2nd arg - Frequency of that feature
        
        for(auto &x : features)                                 popularity[x] = 0;
        
        unordered_set<string> uniqFeat;
        
        for(auto &x : responses) {
            
            stringstream ss(x);
            string word;
            
            while(ss >> word) {
                if(uniqFeat.insert(word).second)                popularity[word]++;
            }
            
            uniqFeat.clear();
        }
        
        stable_sort(features.begin(), features.end(), [&] (const string &a, const string &b) {
                         return popularity[a] > popularity[b];
                    }
        );
            
        return features;
    }
    
};