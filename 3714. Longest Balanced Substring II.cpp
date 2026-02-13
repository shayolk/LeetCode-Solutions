class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int cnta, cntb, cntc;
        int ans = 0;
        // 1 char
        cnta = cntb = cntc = 0;
        for (char c: s) {
            switch (c) {
                case 'a': {
                    ++cnta;
                    cntb = 0;
                    cntc = 0;
                    break;
                }
                case 'b': {
                    cnta = 0;
                    ++cntb;
                    cntc = 0;
                    break;
                }
                case 'c': {
                    cnta = 0;
                    cntb = 0;
                    ++cntc;
                    break;
                }
                default: {
                    break;
                }
            }
            ans = max({ans, cnta, cntb, cntc});
        }
        // 2 chars
        map<int,int> ind2;
        cnta = cntb = cntc = 0;
        ind2 = {};
        ind2[0] = -1;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            switch (c) {
                case 'a': {
                    ind2 = {};
                    break;
                }
                case 'b': {
                    ++cntb;
                    break;
                }
                case 'c': {
                    ++cntc;
                    break;
                }
                default: {
                    break;
                }
            }
            int cnt = cntb - cntc;
            if (ind2.count(cnt)) {
                ans = max(ans, i - ind2[cnt]);
            } else {
                ind2[cnt] = i;
            }
        }
        cnta = cntb = cntc = 0;
        ind2 = {};
        ind2[0] = -1;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            switch (c) {
                case 'a': {
                    ++cnta;
                    break;
                }
                case 'b': {
                    ind2 = {};
                    break;
                }
                case 'c': {
                    ++cntc;
                    break;
                }
                default: {
                    break;
                }
            }
            int cnt = cntc - cnta;
            if (ind2.count(cnt)) {
                ans = max(ans, i - ind2[cnt]);
            } else {
                ind2[cnt] = i;
            }
        }
        cnta = cntb = cntc = 0;
        ind2 = {};
        ind2[0] = -1;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            switch (c) {
                case 'a': {
                    ++cnta;
                    break;
                }
                case 'b': {
                    ++cntb;
                    break;
                }
                case 'c': {
                    ind2 = {};
                    break;
                }
                default: {
                    break;
                }
            }
            int cnt = cnta - cntb;
            if (ind2.count(cnt)) {
                ans = max(ans, i - ind2[cnt]);
            } else {
                ind2[cnt] = i;
            }
        }
        // 3 chars
        cnta = cntb = cntc = 0;
        map<pair<int,int>,int> ind3;
        ind3[{0, 0}] = -1;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            switch (c) {
                case 'a': {
                    ++cnta;
                    break;
                }
                case 'b': {
                    ++cntb;
                    break;
                }
                case 'c': {
                    ++cntc;
                    break;
                }
                default: {
                    break;
                }
            }
            pair<int,int> cnt = {cnta - cntb, cntb - cntc};
            if (ind3.count(cnt)) {
                ans = max(ans, i - ind3[cnt]);
            } else {
                ind3[cnt] = i;
            }
        }
        return ans;
    }
};
