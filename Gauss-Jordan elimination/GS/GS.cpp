#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;;
//------------------4a9g0069林庠葳-------------------//
int main()
{
    bool can_do = false;
    bool ischange_0 = false;
    bool CK_1 = false;
    int change_count = 0;
    int m, n, temp;
    int cow = 0;
    int count = 0;
    float num = 0;
    float sub_element = 0;
    int address = 0;
    cin >> n >> m;
    vector<vector<float>> GS_Array(n, vector<float>(m));
    vector<float> CP_Array(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {   
            cin >> temp;
            GS_Array[i][j] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (GS_Array[0][0] == 0)
        {
            address = i;
            CP_Array.assign(GS_Array[address + 1].begin(), GS_Array[address + 1].end());
            GS_Array[address + 1].assign(GS_Array[address].begin(), GS_Array[address].end());
            GS_Array[address].assign(CP_Array.begin(), CP_Array.end());
        }
    }
    while(cow != n)
    {
        if (change_count > n)
        {
            break;
        }
        count = 0;
        for (int j = 0; j < m; j++)
        {
            if (GS_Array[cow][j] == 0)
            {
                count++;
                if (count == m && cow != n - 1)
                {
                    address = cow;
                    CP_Array.assign(GS_Array[address + 1].begin(), GS_Array[address + 1].end());
                    GS_Array[address + 1].assign(GS_Array[address].begin(), GS_Array[address].end());
                    GS_Array[address].assign(CP_Array.begin(), CP_Array.end());
                    ischange_0 = true;
                    change_count++;
                    cow--;
                }
                else if (cow == n - 1)
                {
                    change_count++;
                }
            }
            else if (GS_Array[cow][j] == 1)
            {
                for (int s = 1 + cow; s < n; s++)
                {
                    if (GS_Array[s][j] != 0)
                    {
                        address = s;
                        sub_element = (GS_Array[s][j] / GS_Array[cow][j]) * -1;
                        for (int k = 0; k < m; k++)
                        {
                            GS_Array[address][k] = GS_Array[address][k] + (GS_Array[cow][k] * sub_element);
                        }
                    }
                }
            }
            else
            {
                float top_element = GS_Array[cow][j];
                for (int s = 0; s < m; s++)
                {
                    if (GS_Array[cow][s] != 0)
                    {
                        GS_Array[cow][s] = GS_Array[cow][s] * (1 / top_element);
                    }
                }
                for (int s = 1 + cow; s < n; s++)
                {
                    if (GS_Array[s][j] != 0)
                    {
                        address = s;
                        sub_element = (GS_Array[s][j] / GS_Array[cow][j]) * -1;
                        for (int k = 0; k < m; k++)
                        {
                            GS_Array[address][k] = GS_Array[address][k] + (GS_Array[cow][k] * sub_element);
                        }
                    }
                }
            }
            if (GS_Array[cow][j] == 1 || ischange_0)
            {
                cow++;
                ischange_0 = false;
                break;
            } 
        }
    }
    cow = n - 1;

    while (cow != 0)
    {
        for (int i = 0; i < m; i++)
        {
            if (GS_Array[cow][i] != 0)
            {
                for (int j = cow - 1; j >= 0; j--)
                {
                    if (GS_Array[j][i] != 0) 
                    {
                        address = j;
                        sub_element = (GS_Array[j][i] / GS_Array[cow][i]) * -1;
                        for (int k = 0; k < m; k++)
                        {
                            GS_Array[address][k] = GS_Array[address][k] + (GS_Array[cow][k] * sub_element);
                        }
                    }
                }
                break;
            }
        }
        cow--;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%.2f ", GS_Array[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

