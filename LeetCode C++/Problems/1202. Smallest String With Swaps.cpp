class Solution {
public:
    int *parent, *rank;

    int find(int x) {
        if (parent[x] != x)
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if (rank[x]<rank[y])
        parent[x]=y;
        else if (rank[x]>rank[y])
        parent[y]=x;
        else {
            parent[y] = x;
            rank[x]++;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // fill parent array (for union find) and create unions
        parent = new int[s.length()];
        rank = new int[s.length()]();
        for (int i=0; i<s.length(); i++) {
            parent[i] = i;
        }
        for (auto& p:pairs)
        uni(p[0], p[1]);
        // unordered_map<int, string> groups;
        // vector<string> groups(s.length());
        string *groups = new string[s.length()];
        for (int i=0; i<s.length(); i++) {
            int p = find(i);
            groups[p].push_back(s[i]);
        }
        for (int i=0;i<s.length(); i++)
        sort(groups[i].begin(), groups[i].end(), greater<char>());
        // for (auto& v:groups)
        //     sort(v.begin(), v.end(), greater<char>());
        for (int i=0; i<s.length(); i++) {
            int p = find(i);
            s[i] = groups[p].back();
            groups[p].pop_back();
        }
        return s;
    }};
