#include <iostream>
using namespace std;

int main()
{
    const int BORDER = 5;
    const int AREA_TRIAN = (BORDER + 1) * BORDER / 2;
    int matrix[AREA_TRIAN];

    for (int i = 0; i < AREA_TRIAN; ++i)
    {
        cin >> matrix[i];
    }

    int result[AREA_TRIAN];

    //это лучшее что я мог сделать со своим кодом
    int start_ind = 0;
    int down_border = BORDER - 1;
    int delta = 0;
    int sum = 0;
    int end_ind;
    int delta_border = 0;
    int res_ind;
    int delta_res_ind = 0;
    int delta_start = 0;
    int delta_res = 0;
    int delta_delta_res = 0;

    for (int i = 0; i < AREA_TRIAN; ++i)
    {
        end_ind = start_ind + BORDER - down_border;
        res_ind = start_ind + delta_start;

        for (int j = start_ind; j < end_ind; ++j)
        {
            res_ind += delta_res_ind;
            sum += matrix[j] * matrix[res_ind];
            ++delta_res;
            delta_res_ind = BORDER - delta_res;
        }

        delta_res_ind = 0;
        delta_res = delta_delta_res;
        ++delta_start;
        result[i] = sum;
        sum = 0;

        if (down_border == delta_border)
        {
            ++delta_delta_res;
            delta_start = 0;
            start_ind += BORDER - delta;
            ++delta;
            down_border =  BORDER - 1; 
            ++delta_border;
        }
        else
        {
            --down_border;
        }
    }

    for (int i = 0; i < AREA_TRIAN; ++i)
    {
        cout << result[i] << ' ';
    }
}
