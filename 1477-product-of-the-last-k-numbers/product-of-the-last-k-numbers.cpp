class ProductOfNumbers {
private:
    vector<int> sum;
public:
    ProductOfNumbers() {
        sum.push_back(1);
    }
    void add(int num) {
        if(num==0){
            sum.clear();
            sum.push_back(1);
        }
        else{
            sum.push_back(sum.back()*num);
        }
    }
    
    int getProduct(int k) {
        if(k>=sum.size()){
            return 0;
        }
        return sum.back()/sum[sum.size()-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */