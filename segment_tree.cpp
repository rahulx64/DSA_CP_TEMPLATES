#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    // Build the tree
    void buildTree(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            // Recursively build the left and right subtrees
            buildTree(arr, 2 * node + 1, start, mid);
            buildTree(arr, 2 * node + 2, mid + 1, end);
            // Internal node will have the sum of both its children
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // Range sum query
    int query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) {
            // No overlap
            return 0;
        }
        if (L <= start && end <= R) {
            // Total overlap
            return tree[node];
        }
        // Partial overlap
        int mid = (start + end) / 2;
        int leftSum = query(2 * node + 1, start, mid, L, R);
        int rightSum = query(2 * node + 2, mid + 1, end, L, R);
        return leftSum + rightSum;
    }

    // Point update
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            // Leaf node
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                // If idx is in the left child, recurse on the left child
                update(2 * node + 1, start, mid, idx, value);
            } else {
                // If idx is in the right child, recurse on the right child
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            // Internal node will have the sum of both its children
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);
    }

    // Range sum query
    int query(int L, int R) {
        return query(0, 0, n - 1, L, R);
    }

    // Update element at index idx to value
    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    cout << "Sum of values in given range = " << segTree.query(1, 3) << endl; // Output: 15

    segTree.update(1, 10);
    cout << "Updated sum of values in given range = " << segTree.query(1, 3) << endl; // Output: 22

    return 0;
}
