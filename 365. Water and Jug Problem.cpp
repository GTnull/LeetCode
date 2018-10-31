class Solution {
public:
    // m * x + n * y = z
    bool canMeasureWater(int x, int y, int z) {
        return (z == 0 || (x + y >= z && z %(__gcd(x, y)) == 0));
    }
};