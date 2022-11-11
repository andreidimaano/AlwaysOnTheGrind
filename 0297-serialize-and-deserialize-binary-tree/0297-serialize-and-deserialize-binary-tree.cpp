/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const string NULLSTRING = "N";
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream serializedString;
        encode(root, serializedString);
        return serializedString.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream serializedString(data);
        return decode(serializedString);
    }
private:
    void encode(TreeNode* root, ostringstream& serializedString) {
        if(root == nullptr) {
            serializedString << NULLSTRING << " ";
            return;
        }
        
        serializedString << root->val << " ";
        encode(root->left, serializedString);
        encode(root->right, serializedString);
    }
    
    TreeNode* decode(istringstream& serializedString) {
        string currValue = "";
        serializedString >> currValue;
        
        if(currValue == NULLSTRING) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(stoi(currValue));
        root->left = decode(serializedString);
        root->right = decode(serializedString);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));