#include<unordered_map>
#include<string>
using namespace std;

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {

    }
    
    void insert(string key, int val) {
        int reduceNum = 0;
        if(_cntMap.find(key)!=_cntMap.end()){
            reduceNum = _cntMap[key];
        }
        for(int len=1; len<=key.length(); len++){
            string prefix = key.substr(0, len);
            if(_prefixMap.find(prefix)==_prefixMap.end()) _prefixMap[prefix] = 0;
            _prefixMap[prefix] -= reduceNum;
            _prefixMap[prefix] += val;
        }
        _cntMap[key] = val;
    }
    
    int sum(string prefix) {
        if(_prefixMap.find(prefix)==_prefixMap.end()) return 0;
        else return _prefixMap[prefix];
    }
private:
    unordered_map<string, int> _cntMap, _prefixMap;
};
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */