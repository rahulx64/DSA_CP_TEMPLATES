#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> tree; // Segment tree array
    vector<int> lazy; // Lazy propagation array
    int n; // Size of the input array

    // Build the segment tree from the input array
    void buildTree(const vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            // Leaf node
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            // Recursively build the left and right children
            buildTree(arr, start, mid, 2 * node + 1);
            buildTree(arr, mid + 1, end, 2 * node + 2);
            // Internal node: sum of children
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // Range update function (adds 'value' to the range [l, r])
    void updateRange(int start, int end, int l, int r, int value, int node) {
        // Handle any pending updates
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node]; // Update current node
            if (start != end) {
                lazy[2 * node + 1] += lazy[node]; // Mark left child for lazy update
                lazy[2 * node + 2] += lazy[node]; // Mark right child for lazy update
            }
            lazy[node] = 0; // Clear the lazy value
        }

        // No overlap
        if (start > end || start > r || end < l) {
            return;
        }

        // Total overlap
        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * value; // Update current node
            if (start != end) {
                lazy[2 * node + 1] += value; // Mark left child for lazy update
                lazy[2 * node + 2] += value; // Mark right child for lazy update
            }
            return;
        }

        // Partial overlap
        int mid = (start + end) / 2;
        updateRange(start, mid, l, r, value, 2 * node + 1);
        updateRange(mid + 1, end, l, r, value, 2 * node + 2);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Update current node
    }

    // Range query function (queries the sum in the range [l, r])
    int queryRange(int start, int end, int l, int r, int node) {
        // Handle any pending updates
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node]; // Update current node
            if (start != end) {
                lazy[2 * node + 1] += lazy[node]; // Mark left child for lazy update
                lazy[2 * node + 2] += lazy[node]; // Mark right child for lazy update
            }
            lazy[node] = 0; // Clear the lazy value
        }

        // No overlap
        if (start > end || start > r || end < l) {
            return 0;
        }

        // Total overlap
        if (start >= l && end <= r) {
            return tree[node];
        }

        // Partial overlap
        int mid = (start + end) / 2;
        int leftQuery = queryRange(start, mid, l, r, 2 * node + 1);
        int rightQuery = queryRange(mid + 1, end, l, r, 2 * node + 2);
        return leftQuery + rightQuery;
    }

public:
    // Constructor: initializes segment tree and lazy array
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n); // Segment tree size is roughly 4 times the input size
        lazy.resize(4 * n, 0); // Lazy array initialized to 0
        buildTree(arr, 0, n - 1, 0); // Build the segment tree
    }

    // Public method to update a range
    void updateRange(int l, int r, int value) {
        updateRange(0, n - 1, l, r, value, 0);
    }

    // Public method to query a range
    int queryRange(int l, int r) {
        return queryRange(0, n - 1, l, r, 0);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11}; // Example input array
    SegmentTree st(arr);

    cout << "Initial Range Sum (0, 5): " << st.queryRange(0, 5) << endl;

    st.updateRange(1, 3, 10); // Increment range [1, 3] by 10
    cout << "After Update Range Sum (0, 5): " << st.queryRange(0, 5) << endl;

    cout << "Range Sum (1, 3): " << st.queryRange(1, 3) << endl;

    return 0;
}
