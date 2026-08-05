class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        vector<pair<int, int>> blocks;
        int total_ones = 0;

        // 1. Identify all contiguous blocks of '1's
        for (int i = 0; i < n; ) {
            if (s[i] == '1') {
                int start = i;
                while (i < n && s[i] == '1') {
                    i++;
                    total_ones++;
                }
                blocks.push_back({start, i - 1});
            } else {
                i++;
            }
        }

        int m = blocks.size();
        if (m == 0) return vector<int>(queries.size(), 0);

        // 2. Precalculate maximal '0' expansions and internal gains
        vector<int> L(m), R(m), internal_gains(m);
        vector<int> block_starts(m), block_ends(m);
        
        for (int i = 0; i < m; ++i) {
            L[i] = (i > 0) ? blocks[i - 1].second + 1 : 0;
            R[i] = (i < m - 1) ? blocks[i + 1].first - 1 : n - 1;
            internal_gains[i] = R[i] - L[i] - (blocks[i].second - blocks[i].first);
            block_starts[i] = blocks[i].first;
            block_ends[i] = blocks[i].second;
        }

        // 3. Build a Sparse Table for O(1) Range Maximum Queries
        int max_log = 0;
        while ((1 << max_log) <= m) max_log++;
        vector<vector<int>> st(m, vector<int>(max_log));
        
        for (int i = 0; i < m; ++i) {
            st[i][0] = internal_gains[i];
        }
        
        for (int j = 1; j < max_log; ++j) {
            for (int i = 0; i + (1 << j) <= m; ++i) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }

        // Precompute logarithms for O(1) lookup
        vector<int> lg(m + 1, 0);
        for (int i = 2; i <= m; ++i) {
            lg[i] = lg[i / 2] + 1;
        }

        auto query_st = [&](int l, int r) {
            if (l > r) return -1;
            int j = lg[r - l + 1];
            return max(st[l][j], st[r - (1 << j) + 1][j]);
        };

        auto get_gain = [&](int idx, int li, int ri) {
            if (idx < 0 || idx >= m) return -1;
            int a = blocks[idx].first, b = blocks[idx].second;
            if (!(a > li && b < ri)) return -1;
            int left = max(li, L[idx]);
            int right = min(ri, R[idx]);
            return right - left - (b - a);
        };

        // 4. Process queries efficiently
        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int li = q[0], ri = q[1];

            // Find blocks that are strictly inside (li, ri)
            int idx_start = upper_bound(block_starts.begin(), block_starts.end(), li) - block_starts.begin();
            int idx_end = lower_bound(block_ends.begin(), block_ends.end(), ri) - block_ends.begin() - 1;

            int max_gain = 0;
            if (idx_start <= idx_end) {
                // Check edge blocks whose expansions are constrained by li or ri
                max_gain = max(max_gain, get_gain(idx_start, li, ri));
                max_gain = max(max_gain, get_gain(idx_end, li, ri));
                
                // Query unconstrained internal blocks via Sparse Table in O(1)
                if (idx_start + 1 <= idx_end - 1) {
                    max_gain = max(max_gain, query_st(idx_start + 1, idx_end - 1));
                }
            }
            answer.push_back(total_ones + max_gain);
        }

        return answer;
    }
};