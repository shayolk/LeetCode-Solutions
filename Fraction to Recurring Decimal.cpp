class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool n=numerator<0, d=denominator<0;
        numerator=abs(numerator);
        denominator=abs(denominator);
        long long quo=numerator/denominator;
	    long long rem=numerator%denominator;
	    string ans=(n^d && (quo || rem))?"-":"";
        ans+=to_string(quo);
	    if(!rem) return ans;
	    string dec=".";
	    int ind=1;
	    map<long long,int> pos;
	    while(rem && !pos.count(rem)) {
	        pos[rem]=ind;
	        rem*=10;
	        long long here=rem/denominator;
	        rem%=denominator;
	        string his=to_string(here);
	        dec+=his;
	        ind+=his.size();
	    }
	    if(!rem) return ans+dec;
	    return ans+dec.substr(0, pos[rem])+'('+dec.substr(pos[rem], dec.size()-pos[rem])+')';
    }
};
