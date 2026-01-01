def g(x) {
    if (x) {
        return 1;
    } else {
        return 2;
    }
}
def f(y) {
    res=0;
    while(y+1) {
        res=res+y+g(y);
        y=y-1;
    }
    return res;
}

result = f(2);