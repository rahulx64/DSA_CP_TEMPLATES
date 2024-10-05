class disjoint {
    vector<int> vs;
    vector<int> pa;

public:
    disjoint(int n) {
        vs.resize(n + 1, 1);
        pa.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            pa[i] = i;
        }
    }

    int findupar(int node) {
        if (node == pa[node]) {
            return node;
        }
        return pa[node] = findupar(pa[node]);
    }

    void unionbysize(int u, int v) {
        int x = findupar(u);
        int y = findupar(v);
        if (x == y)
            return;
        if (vs[x] == vs[y]) {
            vs[x] += vs[y];
            pa[y] = x;
        } else if (vs[x] > vs[y]) {
            vs[x] += vs[y];
            pa[y] = x;
        } else {
            vs[y] += vs[x];
            pa[x] = y;
        }
    }
};

disjoint ds(n);
