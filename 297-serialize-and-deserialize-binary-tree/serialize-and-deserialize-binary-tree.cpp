class Codec {
public:
    string serialize(TreeNode* root) {
        string s; ser(root, s); return s;
    }
    TreeNode* deserialize(string data) {
        int i = 0; return des(data, i);
    }
private:
    void ser(TreeNode* n, string& s) {
        if (!n) { s += "# "; return; }
        s += to_string(n->val) + " ";
        ser(n->left, s); ser(n->right, s);
    }
    TreeNode* des(string& s, int& i) {
        while (i < (int)s.size() && s[i] == ' ') i++;
        if (s[i] == '#') { i++; return nullptr; }
        int sign = 1; if (s[i]=='-'){sign=-1;i++;}
        int val = 0; while (i < (int)s.size() && isdigit(s[i])) val = val*10 + (s[i++]-'0');
        TreeNode* node = new TreeNode(val * sign);
        node->left = des(s, i); node->right = des(s, i);
        return node;
    }
};