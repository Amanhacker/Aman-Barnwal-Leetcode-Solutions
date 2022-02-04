/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    // Height of a node root of a n-ary tree 
    int dfs(Node* root, int &maxi) {
        
        if(root == NULL)                                        return 0;
        if(root->children.size() == 0)                          return 0;
        
        vector<Node*> ch = root->children;
        
        // Store the first and second largest child paths (initially 0)
        int largestChildPath = 0;
        int secondLargestChildPath = 0;
        
        // Only, we need to take care of two largest children and then add the same
        for(auto &x : ch) {
            
             // Find the child's max path
            int childPath = 1 + dfs(x, maxi);
            
            // Update largest or second largest if appropriate
            if (childPath > largestChildPath) {
                secondLargestChildPath = largestChildPath;
                largestChildPath = childPath;
            }
            
            else if (childPath > secondLargestChildPath) {
                secondLargestChildPath = childPath;
            }
        }
        
        maxi = max(maxi, largestChildPath + secondLargestChildPath);
        
        return largestChildPath;
    }
    
    int diameter(Node* root) {
    
        int maxi = 0;
        
        // Run dfs from root
        dfs(root, maxi);
        
        return maxi;
    }
    
};