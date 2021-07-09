class Solution {
public:
    int gcd(int a, int b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    bool canMeasureWater(int x, int y, int z) {
        if(z==0)
            return true;
        if((x+y)<z)
            return false;
        int g=gcd(x,y);
        return z%g==0;
    }
};
