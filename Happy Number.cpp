class Solution {
    int fuck(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=pow(n%10,2);
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set <int> s;
        while(true)
        {
            if(n==1)    return true;
            n=fuck(n);
            if(s.find(n)==s.end())  s.insert(n);
            else    return false;
        }
    }
};
