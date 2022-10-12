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

    void bfs(TreeNode* root, string &res) {
        
        if(root == NULL)                        return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false) {
            
            int n = q.size();
            
            while(n--) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp == NULL)                res += "#,";
                else                            res += to_string(temp->val) + ',';   
                
                if(temp != NULL) {
                    q.push(temp->left);
                    q.push(temp->right);
                }   
            }
        }
        
        return;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string res = "";
        
        bfs(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        TreeNode* root = NULL;
        
        int n = data.length();
        
        if(n == 0)                              return root;
        
        stringstream ss(data);
        string str;
        
        getline(ss, str, ',');
        int rootVal = stoi(str);
        
        root = new TreeNode(rootVal);
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false) {
            
            int n1 = q.size();
            
            while(n1--) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                // For left node of "temp" node
                getline(ss, str, ',');
                
                if(str == "#")                      temp->left = NULL;
                
                else {
                    
                    int leftVal = stoi(str);
                    TreeNode* leftNode = new TreeNode(leftVal);
                    temp->left = leftNode;
                    
                    q.push(leftNode);
                }
                
                 // For right node of "temp" node
                getline(ss, str, ',');
                
                if(str == "#")                      temp->right = NULL;
                
                else {
                    
                    int rightVal = stoi(str);
                    TreeNode* rightNode = new TreeNode(rightVal);
                    temp->right = rightNode;
                    
                    q.push(rightNode);
                }
            }
        }        
        
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;