#include <iostream>
#include <vector>
//4A9G0069林庠葳//
using namespace std;;

float Det(vector<vector<float>> Det_Matrix, int Det_n)
{
    if (Det_n == 1)
    {
        return Det_Matrix[0][0];
    }
    if (Det_n == 2)  // 2*2 矩陣公式
    {
        return Det_Matrix[0][0] * Det_Matrix[1][1] - Det_Matrix[0][1] * Det_Matrix[1][0];
    }

    float det = 0;
    vector<vector<float>> Minor_Matrix(Det_n - 1, vector<float>(Det_n - 1));  //子行列式值矩陣 小原矩陣1*1

    for (int i = 0; i < Det_n; i++) //矩陣大小 = 做幾次餘因子展開
    {
        for (int j = 1; j < Det_n; j++)
        {
            for (int s = 0, Row_cofactor_expansion = 0; s < Det_n; s++, Row_cofactor_expansion++)
            {
                if (s == i) //行數相對之情況
                {
                    Row_cofactor_expansion--;
                    continue;
                }
                Minor_Matrix[j - 1][Row_cofactor_expansion] = Det_Matrix[j][s]; //  n*n矩陣複製到子行列式值矩陣
            }
        }

        //棋盤正負號
        if (i % 2 == 0)
        {
            det += Det_Matrix[0][i] * Det(Minor_Matrix, Det_n - 1); //遞迴
        }
        else
        {
            det -= Det_Matrix[0][i] * Det(Minor_Matrix, Det_n - 1); //遞迴
        }
    }
    Det_Matrix.clear();  //刪除舊陣列
    return det;  //答案
}
//4A9G0069林庠葳//
int main()
{
    int n;  //陣列大小
    cin >> n;
    vector<vector<float>> Matrix(n, vector<float>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> Matrix[i][j];
        }
    }
    cout << "Det(A) = " << Det(Matrix, n);
}
