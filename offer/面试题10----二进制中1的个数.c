
//普通解法1
int NumberOf1(int n){
    int count = 0;
    unsigned int flag = 1;
    while(flag){
        if(n & flag)
            count++;
        flag = flag << 1;
    }
    return count;
}

//优化版解法
int NumberOf1(int n){
    int count = 0;
    while(n){
        count++;
        n=(n-1)&n;
    }
    return count;
}
