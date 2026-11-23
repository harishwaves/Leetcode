class ProductOfNumbers {
public:
    vector<int> st;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        st.push_back(num);
    }
    
    int getProduct(int k) {
        int pro = 1;
        int n = st.size();
        for(int i=n-k;i<n;i++){
            pro *= st[i];
        }
        return pro;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */