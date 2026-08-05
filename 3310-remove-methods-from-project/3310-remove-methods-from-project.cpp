class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
         vector<vector<int>> graph(n);
        for (const auto& inv : invocations) {
            graph[inv[0]].push_back(inv[1]);
        }
        
        // Step 2: Identify all suspicious nodes
        vector<bool> isSuspicious(n, false);
        queue<int> q;
        q.push(k);
        isSuspicious[k] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (!isSuspicious[v]) {
                    isSuspicious[v] = true;
                    q.push(v);
                }
            }
        }
        
        // Step 3: Validate boundaries
        for (const auto& inv : invocations) {
            if (!isSuspicious[inv[0]] && isSuspicious[inv[1]]) {
                vector<int> all(n);
                for (int i = 0; i < n; ++i) all[i] = i;
                return all;
            }
        }
        
        // Step 4: Collect valid methods
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!isSuspicious[i]) result.push_back(i);
        }
        return result;
        
    }
};