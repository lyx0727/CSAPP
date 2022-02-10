int func4(int arg1, int arg2, int arg3){
    int res = arg3;
    res -= arg2;
    int tmp = res;
    tmp >>= 31;
    res += tmp;
    res >>= 1;
    tmp = res + arg2;
    return arg1 == tmp ? 0 : 
        (arg1 > tmp ? 2 * func4(arg1, arg2, tmp - 1) : 2 * func4(arg1, tmp + 1, arg3) + 1);
}

int func4_s(int arg1, int arg2, int arg3){
    int x = arg3 < arg2 ? (arg3 + arg2 + 1) / 2 : (arg3 + arg2) / 2; 
    if(arg1 == x)
        return 0;
    else if(arg1 < x)
        return 2 * func4(arg1, x + 1, arg3) + 1;
    else if(arg1 > x)
        return 2 * func4(arg1, arg2, x - 1);
}