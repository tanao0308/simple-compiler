def dfs(d) {
    res=1;
    if (d) {
        res = res + dfs(d-1);
        if(d-1) {
            res = res + dfs(d-2);
        }
    }
    return res;
}

d=10;
result = dfs(d);