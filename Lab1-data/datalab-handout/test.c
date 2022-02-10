#include<stdio.h>

int howManyBits(int x) {
  x = x ^ (x >> 31);
  int a = !!(x >> 16) << 4;
  x = x >> a;
  int b = !!(x >> 8) << 3;
  x = x >> b;
  int c = !!(x >> 4) << 2;
  x = x >> c;
  int d = !!(x >> 2) << 1;
  x = x >> d;
  int e = !!(x >> 1) << 0;
  x = x >> e;
  return a + b + c + d + e + x + 1;
}

unsigned float_i2f(int x) {
  if(x){
    int sgn = x >> 31;
    x = (x ^ sgn) - sgn;
    int n = 30;
    while(!((x >> n) & 1)) --n;
    if(n <= 23){
      int frac = x & ((1 << n) - 1);
      int exp = (n + 127) << 23;
      x = sgn | exp | frac; 
    }
    else{
      int mask = ((1 << n) - 1) & (0xffffffff << (n - 23));
      int frac = ((x & mask) >> (n - 23)) & 0x807fffff;
      frac = frac ^ (x >> (n - 24) & 1); 
      int exp = (n + 127) << 23;
      x = sgn | exp | frac;
    }
  }
  return x;
}

int main(){
    int x;
    while(scanf("%d", &x) == 1){
        printf("%0x\n", float_i2f(x));
    }
    return 0;
}