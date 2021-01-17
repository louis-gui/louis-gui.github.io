#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#define MOVETO(x,y) printf("\033[%d;%dH", (x), (y))
static void _SetPos(int x, int y)//ÒÆ¶¯¹â±êµ½X¡¢YÎ»ÖÃ
{
COORD position;
HANDLE handle;
handle=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(handle, position);
}
int main() {
    int W = 20, S = W * W, *m, z[2] = {0}, l = 3, i, c = 'D', C, *p,f;
    for (srand(time(0)),m = (int*)calloc(S, 4), C = m[1] = -1; C - 27;_SetPos(1,1)) {
        if (_kbhit())C = _getch() & 95, C - 65 && C - 68 &&
            C - 83 && C - 87 || (C ^ c) & 20 ^ 4 && (c = C);
        p = z + !!(c & 2), *p += c / 3 & 2, *p = (--*p + W) % W;
        f = 1, *(p = m + *z + z[1] * W) > 0 && (C = 27);
        for (; *p && (m[i = rand() % S] || (--m[i], ++l, --f)););
        for (i = 0, *p = l; i < S; ++i % W || _cputs("|\n"))
                _cputs(m[i]>0?m[i]-=f,"\033[0;32;32m■■\033[0;37;37m":m[i]?"\033[0;31;31m■■\033[0;37;37m":"■■");                  }
    return 0;
}

