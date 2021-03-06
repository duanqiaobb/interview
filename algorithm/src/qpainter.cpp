/**
 * [编程题] 画家小Q
 * 时间限制：1秒
 *
 * 空间限制：32768K
 *
 * 画家小Q又开始他的艺术创作。小Q拿出了一块有NxM像素格的画板, 画板初始状态是空白的,用'X'表示。
 * 小Q有他独特的绘画技巧,每次小Q会选择一条斜线, 如果斜线的方向形如'/',即斜率为1,小Q会选择这条斜线中的一段格子,都涂画为蓝色,用'B'表示;如果对角线的方向形如'\',即斜率为-1,小Q会选择这条斜线中的一段格子,都涂画为黄色,用'Y'表示。
 * 如果一个格子既被蓝色涂画过又被黄色涂画过,那么这个格子就会变成绿色,用'G'表示。
 * 小Q已经有想画出的作品的样子, 请你帮他计算一下他最少需要多少次操作完成这幅画。
 *
 * 输入描述:
 * 每个输入包含一个测试用例。
 * 每个测试用例的第一行包含两个正整数N和M(1 <= N, M <= 50), 表示画板的长宽。
 * 接下来的N行包含N个长度为M的字符串, 其中包含字符'B','Y','G','X',分别表示蓝色,黄色,绿色,空白。整个表示小Q要完成的作品。
 *
 * 输出描述:
 * 输出一个正整数, 表示小Q最少需要多少次操作完成绘画。
 *
 * 输入例子1:
 * 4 4
 * YXXB
 * XYGX
 * XBYY
 * BXXY
 *
 * 输出例子1:
 * 3
 *
 * 例子说明1:
 * XXXX
 * XXXX
 * XXXX
 * XXXX
 * ->
 *  YXXX
 *  XYXX
 *  XXYX
 *  XXXY
 *  ->
 *  YXXB
 *  XYBX
 *  XBYX
 *  BXXY
 *  ->
 *  YXXB
 *  XYGX
 *  XBYY
 *  BXXY
 *
 *
 *
 */

#include<iostream>
#include<vector>
using namespace std;

int qpainter(int rows, int cols, char **palette) {
    int total = 0;
    char** p = palette;

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            if(p[i][j] == 'Y' || p[i][j] == 'G') {
                int k = 0;
                while((i+k < rows && j+k < cols) && (p[i+k][j+k] == 'Y' || p[i+k][j+k] == 'G')) {
                    if (p[i+k][j+k] == 'Y') {
                        p[i+k][j+k] = 'X';
                    } else {
                        p[i+k][j+k] = 'B';
                    }
                    k++;
                }
                total+=1;
            }
            if (p[i][j] == 'B' || p[i][j] == 'G') {
                int k = 0;
                while((i+k < rows && j-k >= 0) && (p[i+k][j-k] == 'B' || p[i+k][j-k] == 'G')) {
                    if (p[i+k][j-k] == 'B') {
                        p[i+k][j-k] = 'X';
                    } else {
                        p[i+k][j-k] = 'Y';
                    }
                    k++;
                }
                total+=1;
                }
        }
    }
    for(int i = 0; i < rows;i++) {
        for(int j = 0; j < cols; j++) {
            switch(p[i][j]) {
                case 'Y':
                    total+=1;
                    break;
                case 'B':
                    total+=1;
                    break;
                case 'G':
                    total+=2;
                    break;
                default:
                    break;
            }
        }
    }
    return total;
}

int main(int argc, char** argv) {
     int cols, rows;
     int steps = 0;
     cin >> rows >> cols;
     char **p;
     char *ptr;
     /**
     p= (char **)malloc(sizeof(char*)*rows);
     for (int k = 0; k < rows; k++) {
         p[k] = (char*)malloc(sizeof(char)*cols);
     }
     **/
     p = (char**)malloc(sizeof(char*)*rows+sizeof(char)*rows*cols);
     ptr = (char*)(p+rows);
     cin.ignore();
     for(int i = 0; i < rows;i++) {
         for(int j = 0; j < cols; j++) {
             cin >> p[i][j];
         }
         cin.ignore();
     }
    steps = qpainter(rows,cols,p);
    cout << steps << endl;
}
