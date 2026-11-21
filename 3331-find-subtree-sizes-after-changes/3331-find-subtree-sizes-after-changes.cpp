
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n), tree(n);
        vector<int> last(26, -1);
        vector<int> newParent = parent;
        vector<int> ans(n, 1);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        function<void(int)> dfs1 = [&](int node) {
            int c = s[node] - 'a';
            int old = last[c];

            if (node != 0 && old != -1) {
                newParent[node] = old;
            }

            last[c] = node;

            for (int child : adj[node]) {
                dfs1(child);
            }

            last[c] = old;
        };

        dfs1(0);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        function<int(int)> dfs2 = [&](int node) {
            for (int child : tree[node]) {
                ans[node] += dfs2(child);
            }
            return ans[node];
        };

        dfs2(0);

        return ans;
    }
};
