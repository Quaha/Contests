#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

struct line {
    int k = 0, b = 0;
    int operator()(int x) {
        return k * x + b;
    }
    bool operator==(const line& other) {
        return k == other.k && b == other.b;
    }
};

line FILLER{0, -INF};

struct LiChao { // Upper envelope

    struct Node {
        int left_id = -1;
        int right_id = -1;
        line l = FILLER;
    };

    int a, b;
    vector<Node> tree;

    LiChao(int l, int r) {
        a = l, b = r;
        tree.push_back(Node());
    }

    int getLeft(int x) {
        if (tree[x].left_id == -1) {
            tree[x].left_id = tree.size();
            tree.push_back(Node());
        }
        return tree[x].left_id;
    }

    int getRight(int x) {
        if (tree[x].right_id == -1) {
            tree[x].right_id = tree.size();
            tree.push_back(Node());
        }
        return tree[x].right_id;
    }

    void add(line l) {
        add(l, a, b, 0);
    }

    void add(line l, int lx, int rx, int x) {
        int mx = (lx + rx) / 2;
        if (tree[x].l(mx) < l(mx)) {
            swap(l, tree[x].l);
        }
        if (rx - lx == 1 || l == FILLER) {
            return;
        }
        if (l(lx) < tree[x].l(lx)) {
            add(l, mx, rx, getRight(x));
        }
        else {
            add(l, lx, mx, getLeft(x));
        }
    }

    int get(int y) {
        return get(y, a, b, 0);
    }

    int get(int y, int lx, int rx, int x) {
        if (rx - lx == 1 || tree[x].l == FILLER) {
            return tree[x].l(y);
        }
        int mx = (lx + rx) / 2;
		
        if (y < mx) {
            return max(tree[x].l(y), get(y, lx, mx, getLeft(x)));
        }
        return max(tree[x].l(y), get(y, mx, rx, getRight(x)));
    }
};