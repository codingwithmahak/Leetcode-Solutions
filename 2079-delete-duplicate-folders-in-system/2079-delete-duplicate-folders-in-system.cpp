class Solution {
public:
    struct Node {
        string name;
        unordered_map<string, Node*> children;
        bool deleted = false;
        Node(string n) : name(n) {}
    };
    
    void insert(Node* root, vector<string>& path) {
        Node* curr = root;
        for (const string& folder : path) {
            if (!curr->children.count(folder))
                curr->children[folder] = new Node(folder);
            curr = curr->children[folder];
        }
    }
    
    string serialize(Node* node, unordered_map<string, vector<Node*>>& seen) {
        if (node->children.empty()) return "";
        vector<pair<string, string>> subs;
        for (auto& p : node->children) {
            subs.push_back({p.first, serialize(p.second, seen)});
        }
        sort(subs.begin(), subs.end());
        string s;
        for (auto& pr : subs) {
            s += "(" + pr.first + pr.second + ")";
        }
        seen[s].push_back(node);
        return s;
    }
    
    void mark(Node* node) {
        node->deleted = true;
        for (auto& p : node->children) {
            mark(p.second);
        }
    }
    
    void collect(Node* node, vector<string>& path, vector<vector<string>>& res) {
        if (node->name != "" && !node->deleted) res.push_back(path);
        for (auto& p : node->children) {
            if (!p.second->deleted) {
                path.push_back(p.first);
                collect(p.second, path, res);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node("");
        for (auto& path : paths) insert(root, path);
        unordered_map<string, vector<Node*>> seen;
        serialize(root, seen);
        for (auto& pr : seen) {
            if (pr.second.size() > 1) {
                for (Node* node : pr.second) mark(node);
            }
        }
        vector<vector<string>> res;
        vector<string> path;
        collect(root, path, res);
        return res;
    }
};
