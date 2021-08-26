class Solution {    
public:
    bool isValidSerialization(string preorder) {
        int i=0, n=preorder.size(), nodes=1;
        while(i<n) {
            --nodes;
            if(nodes<0) return false;
            if(preorder[i]!='#') nodes+=2;
            while(i<n && preorder[i]!=',') ++i;
            ++i;
        }
        return nodes==0;
    }
};
