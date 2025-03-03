#include <math.h>
#include <iostream>
#include <vector>

using namespace std;
int high, width, temp;
float pro(int pro_i, int pro_j,int now_pro , vector<vector<float>> GS_Array, vector<vector<float>> Orthogonality_v)
{
    float sum = 0;
    float temp_ans = 0, temp_under = 0, temp_top = 0;
    if (pro_i <= 0)
    {
        return sum;
    }
    for (int j = 0; j < width; j++)
    {
        temp_top += GS_Array[now_pro][j] * Orthogonality_v[pro_i - 1][j]; //top
        temp_under += Orthogonality_v[pro_i - 1][j] * Orthogonality_v[pro_i - 1][j]; //under
    }
    temp_ans = temp_top / temp_under;
    temp_ans = temp_ans * Orthogonality_v[pro_i - 1][pro_j];
    sum += pro(pro_i - 1, pro_j, now_pro, GS_Array, Orthogonality_v);
    if (temp_ans + sum <=0.0000001 && temp_ans + sum >= -0.0000001)
    {
        return 0;
    }
    else
    {
        return temp_ans + sum;
    }
}

int main()
{
    cin >> high >> width;
    vector<vector<float>> GS_Array(high, vector<float>(width));
    vector<vector<float>> Orthogonality_v(high, vector<float>(width));
    for (int i = 0; i < high; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cin >> temp;
            GS_Array[i][j] = temp;
        }
    }
    for (int i = 0; i < high; i++)
    {
        if (i == 0)
        {
            Orthogonality_v[i] = GS_Array[i];
        }
        else
        {
            for (int j = 0; j < width; j++)
            {
                Orthogonality_v[i][j] = GS_Array[i][j] - pro(i,j,i, GS_Array, Orthogonality_v);
            }
        }
    }
    cout << endl;
    cout << "{";
    for (int i = 0; i < high; i++)
    {
        cout << "(";
        for (int j = 0; j < width; j++)
        {
            cout << Orthogonality_v[i][j];
            if (j < width - 1)
            {
                cout << ",";
            }
        }
        cout << ")";
    }
    cout << "}";
}