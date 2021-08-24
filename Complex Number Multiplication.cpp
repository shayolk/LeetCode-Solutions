class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto parse=[&](string s) {
            bool flag=true;
            string r, i;
            for(char c: s) {
                if(flag && c=='+') {
                    flag=false;
                    continue;
                }
                if(flag) r+=c;
                else i+=c;
            }
            i.pop_back();
            return pair<int,int> {stoi(r), stoi(i)};
        };
        pair<int, int> x=parse(num1), y=parse(num2);
        return to_string(x.first*y.first - x.second*y.second) + '+' + to_string(x.first*y.second + x.second*y.first) + 'i';
    }
};
