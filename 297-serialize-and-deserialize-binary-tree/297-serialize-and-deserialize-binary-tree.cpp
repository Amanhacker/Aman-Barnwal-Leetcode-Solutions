/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string res = "";
        
        if(root == NULL)                                            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false) {
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL)                                        res += "#,";
            else                                                    res += to_string(temp->val) + ",";
            
            if(temp != NULL) {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        TreeNode* root = NULL;
        
        int n = data.length();
        
        if(n == 0)                                                   return root;
        
        stringstream s(data);
        string str;
        
        getline(s, str, ',');
        
        root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false) {
            
            TreeNode* temp = q.front();
            q.pop();
            
            getline(s, str, ',');
            
            // For Left child
            if(str == "#")                                          temp->left = NULL;
            
            else {
                
                TreeNode* tempLeft = new TreeNode(stoi(str));;
                temp->left = tempLeft;
                
                q.push(tempLeft);
            }
            
            getline(s, str, ',');
            
            // Now, for right child 
            if(str == "#")                                          temp->right = NULL;
            
            else {
                
                TreeNode* tempRight = new TreeNode(stoi(str));
                temp->right = tempRight;
                
                q.push(tempRight);
            }
        }
        
        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));