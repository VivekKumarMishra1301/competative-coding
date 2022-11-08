class CustomStack {
public:
    int size;
    int* stc;
    int maxsize;
    CustomStack(int maxSize) {
        this->maxsize = maxSize;
        stc = new int[maxSize];
        size = 0;
    }

    void push(int x) {
        if (size == maxsize) {
            return;
        }
        else {
            stc[size++] = x;
        }
    }

    int pop() {
        if (size == 0) {
            return -1;
        }

        return stc[--size];



    }

    void increment(int k, int val) {
        int i = 0;
        while (i < size && i < k) {
            stc[i] = stc[i] + val;
            i++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */