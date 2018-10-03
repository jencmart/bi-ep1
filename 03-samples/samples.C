#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class SegmentTree {
    struct Node {
        Node(int from, int to, Node *parent) : m_from(from), m_to(to), m_left(nullptr), m_right(nullptr),
                                               m_parent(parent), m_min(-1), m_max(-1) {}

        ~Node() {
            delete m_left;
            delete m_right;
        }

        int m_from, m_to;
        Node *m_left;
        Node *m_right;
        Node *m_parent;
        int m_min;
        int m_max;
    };

    Node *m_root;
    int m_size;
    vector<Node *> m_leaves;

    Node *buildTree(Node *node) // todo i belive that better ways of building segment tree exists.
    {
        if (node->m_from == node->m_to) {
            m_leaves[node->m_from] = node;
            return node;
        }

        int left_From = node->m_from;
        int left_To = left_From + (node->m_to - node->m_from) / 2;

        int right_From = left_To + 1;
        int right_To = node->m_to;

        node->m_left = buildTree(new Node(left_From, left_To, node));
        node->m_right = buildTree(new Node(right_From, right_To, node));

        return node;
    }

    int getMin(int a, int b) { return a < b ? a : b; }

    int getMax(int a, int b) { return a > b ? a : b; }


    int getMinInRangeRecursively(Node *node, int idxFrom, int idxTo) {

        if (node->m_from > idxTo || node->m_to < idxFrom) { return -1; }
        if (node->m_from >= idxFrom && node->m_to <= idxTo) { return node->m_min; }
        //    if(node->m_from == idxFrom && node->m_to == idxTo) { return node->m_min; } /// desired segment in tree exists and everybody is happy
        //  if(node->m_from==node->m_to){ return node->m_min;}

        int minLeft = getMinInRangeRecursively(node->m_left, idxFrom, idxTo);
        int minRigt = getMinInRangeRecursively(node->m_right, idxFrom, idxTo);

        if (minLeft == -1) return minRigt;
        if (minRigt == -1) return minLeft;
        return getMin(minLeft, minRigt);
    }


    int getMaxInRangeRecursively(Node *node, int idxFrom, int idxTo) {
        if (node->m_from > idxTo || node->m_to < idxFrom) { return -1; }
        if (node->m_from >= idxFrom && node->m_to <= idxTo) { return node->m_max; }
        //   if(node->m_from == idxFrom && node->m_to == idxTo) { return node->m_max; } /// desired segment in tree exists and everybody is happy
        //   if(node->m_from==node->m_to){ return node->m_max;}
        int maxLeft = getMaxInRangeRecursively(node->m_left, idxFrom, idxTo);
        int maxRight = getMaxInRangeRecursively(node->m_right, idxFrom, idxTo);

        if (maxLeft == -1) return maxRight;
        if (maxRight == -1) return maxLeft;
        return getMax(maxLeft, maxRight);
    }

public:
    explicit SegmentTree(int size) : m_root(nullptr), m_size(size), m_leaves((unsigned) size) {
        m_root = buildTree(new Node(0, m_size - 1, nullptr));
    }

    ~SegmentTree() { delete m_root; }

    void insert(int value, int idx) { m_leaves[idx]->m_max = m_leaves[idx]->m_min = value; }

    void calculateTree() {
        pair<int, int> data = calculateRecursively(m_root);
        m_root->m_min = data.first;
        m_root->m_max = data.second;
    }

    pair<int, int> calculateRecursively(Node *node) {
        if (node->m_from == node->m_to) {
            return make_pair(node->m_min, node->m_max);
        }

        pair<int, int> dataLeft = calculateRecursively(node->m_left);
        pair<int, int> dataRight = calculateRecursively(node->m_right);
        node->m_min = getMin(dataLeft.first, dataRight.first);
        node->m_max = getMax(dataLeft.second, dataRight.second);
        return make_pair(node->m_min, node->m_max);
    }


    int getMinInRange(int idxFrom, int idxTo) { return getMinInRangeRecursively(m_root, idxFrom, idxTo); }

    int getMaxInRange(int idxFrom, int idxTo) { return getMaxInRangeRecursively(m_root, idxFrom, idxTo); }

    void printRecursively(Node *node) {
        if (node->m_from == node->m_to) {
            cout << "[" << node->m_from << "," << node->m_to << "] min:" << node->m_min << ", max: " << node->m_max
                 << endl;
            return;
        }

        cout << "[" << node->m_from << "," << node->m_to << "] min:" << node->m_min << ", max: " << node->m_max << endl;

        printRecursively(node->m_left);
        printRecursively(node->m_right);
    }

    void print() {
        printRecursively(m_root);
    }
};


bool getIndexes(int &idxFrom, int &idxTo, int j, int L, vector<int> &sampTimes) {
    int minTime = sampTimes[j - 1] - L; // Vi - Lj

    idxTo = j - 2;  // first value lesser than vi ! (must be in time range!)

    if (sampTimes[idxTo] < minTime) //tzn. pokud se to == je to jeste ok; pouze < je zle
        return false; //empty interval

    idxFrom = (int) (lower_bound(sampTimes.begin(), sampTimes.end(), minTime) -
                     sampTimes.begin()); // first val >=  minTime

    return true;
}


int main() {

    /// SCAN SAMPLES
    int samCnt;

    while (scanf("%d", &samCnt) == 1) {
        vector<int> sampValues(samCnt + 1, 0);
        vector<int> sampTimes(samCnt, 0);
        SegmentTree sampValuesSegmented(samCnt);
        for (int i = 1; i < samCnt + 1; ++i) {
            int ti, vi;
            scanf("%d%d", &ti, &vi);
            sampTimes[i - 1] = ti;
            sampValues[i] = vi + sampValues[i - 1];
            sampValuesSegmented.insert(vi, i - 1);
        }

        sampValuesSegmented.calculateTree();
        //  sampValuesSegmented.print();

        /// SCAN & CALCULATE QUERIES
        int queryCnt;
        scanf("%d", &queryCnt);
        for (int i = 0; i < queryCnt; ++i) {
            string op, func;
            int L;
            cin >> op >> func >> L;
            int cntValid = 0;
            int idxFrom, idxTo;
            int vi;

            if (func == "max") /// MAX
            {
                for (int j = samCnt; j > 1; --j) {
                    vi = sampValues[j] - sampValues[j - 1];
                    if (!getIndexes(idxFrom, idxTo, j, L, sampTimes)) continue;
                    int max = sampValuesSegmented.getMaxInRange(idxFrom, idxTo);
                    if ((op == "gt" && vi > max) || (op == "lt" && vi < max))
                        cntValid++;
                }
            } else if (func == "min") /// MIN
            {
                for (int j = samCnt; j > 1; --j) {
                    vi = sampValues[j] - sampValues[j - 1];
                    if (!getIndexes(idxFrom, idxTo, j, L, sampTimes)) continue;
                    int min = sampValuesSegmented.getMinInRange(idxFrom, idxTo);
                    if ((op == "gt" && vi > min) || (op == "lt" && vi < min))
                        cntValid++;
                }
            } else /// AVG
            {
                for (int j = samCnt; j > 1; --j) // on position 0 is blockingl on 1 is first elem - no previous...
                {
                    vi = sampValues[j] - sampValues[j - 1];
                    if (!getIndexes(idxFrom, idxTo, j, L, sampTimes)) continue;
                    int valA = sampValues[idxTo + 1];
                    int valB = sampValues[idxFrom];
                    double avg = (valA - valB) / (idxTo + 1.0 - idxFrom); //from musi mit (-1)
                    if ((op == "gt" && vi > avg) || (op == "lt" && vi < avg))
                        cntValid++;
                }
            }

            printf("%d\n", cntValid);
        }
    }
    return 0;
}