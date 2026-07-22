class Solution {
public:
    class SegTree {
        int n;
        vector<int> tree;
    public:
        SegTree(const vector<int>& data) {
            n = data.size();
            if (n > 0) {
                tree.resize(4 * n, 0);
                build(data, 0, 0, n - 1);
            }
        }

        void build(const vector<int>& data, int node, int start, int end) {
            if (start == end) {
                tree[node] = data[start];
                return;
            }
            int mid = start + (end - start) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }

        int query(int node, int start, int end, int l, int r) {
            if (r < start || end < l) return -1;
            if (l <= start && end <= r) return tree[node];
            int mid = start + (end - start) / 2;
            return max(query(2 * node + 1, start, mid, l, r),
                       query(2 * node + 2, mid + 1, end, l, r));
        }
    };

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<pair<int, int>> blocks;
        int total_ones = 0;

        // 1. Identify all 1-blocks
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

        // 2. Precalculate maximal 0-block expansions (L and R boundaries)
        vector<int> L(m), R(m), internal_gains(m);
        vector<int> block_starts(m), block_ends(m);
        
        for (int i = 0; i < m; ++i) {
            L[i] = (i > 0) ? blocks[i - 1].second + 1 : 0;
            R[i] = (i < m - 1) ? blocks[i + 1].first - 1 : n - 1;
            internal_gains[i] = R[i] - L[i] - (blocks[i].second - blocks[i].first);
            block_starts[i] = blocks[i].first;
            block_ends[i] = blocks[i].second;
        }

        SegTree tree(internal_gains);
        vector<int> answer;
        answer.reserve(queries.size());

        auto get_gain = [&](int idx, int li, int ri) {
            if (idx < 0 || idx >= m) return -1;
            int a = blocks[idx].first, b = blocks[idx].second;
            if (!(a > li && b < ri)) return -1;
            int left = max(li, L[idx]);
            int right = min(ri, R[idx]);
            return right - left - (b - a);
        };

        // 3. Process each query efficiently
        for (const auto& q : queries) {
            int li = q[0], ri = q[1];

            // Find blocks completely strictly inside (li, ri)
            int idx_start = upper_bound(block_starts.begin(), block_starts.end(), li) - block_starts.begin();
            int idx_end = lower_bound(block_ends.begin(), block_ends.end(), ri) - block_ends.begin() - 1;

            int max_gain = 0;
            if (idx_start <= idx_end) {
                // Case A: Evaluate the first block in range
                max_gain = max(max_gain, get_gain(idx_start, li, ri));
                // Case B: Evaluate the last block in range
                max_gain = max(max_gain, get_gain(idx_end, li, ri));
                // Case C: Query the maximum internal gain for blocks strictly in between
                if (idx_start + 1 <= idx_end - 1) {
                    max_gain = max(max_gain, tree.query(0, 0, m - 1, idx_start + 1, idx_end - 1));
                }
            }
            answer.push_back(total_ones + max_gain);
        }

        return answer;
    }
};