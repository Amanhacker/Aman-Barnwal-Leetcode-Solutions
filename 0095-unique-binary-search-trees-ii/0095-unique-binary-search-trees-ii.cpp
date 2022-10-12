/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<TreeNode*> generateTreeHelper(int start, int end) {
        
        vector<TreeNode*> res;
        
        if(start > end) {
            
            TreeNode* node = NULL;
            res.push_back(node);
            
            return res;
        }                                     
        
        if(start == end) {
            
            TreeNode* node = new TreeNode(start);
            res.push_back(node);
            
            return res;
        }
        
        // Take ith node as root 
        
        for(int i=start; i<=end; i++) {
            
            vector<TreeNode*> leftNodes = generateTreeHelper(start, i - 1);
            vector<TreeNode*> rightNodes = generateTreeHelper(i + 1, end);
            
            for(auto &l : leftNodes) {
                for(auto &r : rightNodes) {
                    
                    TreeNode* node = new TreeNode(i);
                    
                    node->left = l;
                    node->right = r;
                    
                    res.push_back(node);
                }
            }
        }
    
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
    
        return generateTreeHelper(1, n);        
    }
    
};