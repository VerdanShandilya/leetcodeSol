class NumberContainers {
public:
    unordered_map<int,int> m1;
    unordered_map<int,set<int>> m;

    NumberContainers() {
        
    }
    
    void change(int index, int number){
        if(m1.find(index)==m1.end()){
            m1[index]=number;
            m[number].insert(index);
        }
        else{
            int key=m1[index];
            m[key].erase(index);
            if(m[key].empty()){
                m.erase(key);
            }
            m1[index]=number;
            m[number].insert(index);
        }
    }
    
    int find(int number) {
        if(m.find(number)!=m.end()){
            auto num=m[number].begin();
            return *num;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */