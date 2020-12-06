//TODO 120sq brett
//TODO 120sq til 64 sq brett
//TODO printBoard, 1 faktiske verdier, en med brikker (boolean for aa velge.)
//TODO enum brikke til navn
#include <bits/stdc++.h>
using namespace std;

enum pieces : short {e = 0, P, p = 1, N, n = 2, B, b = 3, R, r = 4, Q, q = 5,K, k = 6};
short tenTwelveBoard[120];




short sq120sq64Converter(short n) {
    short ans =  8 * ((n - 21) / 10) + n % 10 - 1 ;
    return ans;
}
short sq64TOsq120(short n) {
    short ans = n % 8 + n / 8 * 10 + 21 ;
    return ans;
}