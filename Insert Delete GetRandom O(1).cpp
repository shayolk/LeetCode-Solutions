class RandomizedSet {
    int n;
    vector<int> nums;
    map<int,int> pos;
    
public:
    RandomizedSet() {
        n=0;
    }
    
    bool insert(int val) {
        if(pos.count(val)) return false;
        nums.push_back(val);
        pos[val]=n++;
        return true;
    }
    
    bool remove(int val) {
        if(!pos.count(val)) return false;
        pos[nums.back()]=pos[val];
        nums[pos[val]]=nums.back();
        pos.erase(val);
        nums.pop_back();
        --n;
        return true;
    }
    
    int getRandom() {
        if(!n) return -1;
        return nums[rand()%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
