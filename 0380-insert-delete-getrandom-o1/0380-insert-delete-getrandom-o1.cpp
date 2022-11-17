class RandomizedSet {
    vector<int> numbers;
    unordered_map<int, int> numIndexMap;
public:
    RandomizedSet() {
        // srand (time(NULL));
    }
    
    bool insert(int val) {
        if(numIndexMap.find(val) != numIndexMap.end()) {
            return false;
        }
        
        numbers.push_back(val);
        numIndexMap[val] = numbers.size() - 1;
        
        return true;
    }
    
    bool remove(int val) {
        if(numIndexMap.find(val) == numIndexMap.end()) {
            return false;
        }
        
        int indexOfVal = numIndexMap[val];
        int lastIndex = numbers.size() - 1;
        int lastIndexVal = numbers[lastIndex]; 
        
        // swap
        swap(numbers[indexOfVal], numbers[lastIndex]);
        numIndexMap[lastIndexVal] = indexOfVal;
        numbers.pop_back();
        numIndexMap.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return numbers[rand() % numbers.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */