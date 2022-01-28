class Solution {
public:

    unordered_map<string, string> u;
    int n = 0;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        string encoded = "http://tinyurl.com/";
        n++;
        
        encoded += to_string(n);
        u[encoded] = longUrl;
        
        return encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
    
        return u[shortUrl];
    }
    
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));