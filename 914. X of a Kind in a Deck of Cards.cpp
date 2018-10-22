class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() <= 1)
            return false;
        unordered_map<int, int> m;
        for(auto i: deck)
            m[i]++;
        int res = 0;
        for(auto i: m)
            res = __gcd(i.second, res);
        return res > 1;
    }
};