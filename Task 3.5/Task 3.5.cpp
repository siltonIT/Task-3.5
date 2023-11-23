#include <iostream>
using namespace std;

int main()
{
    const int BORDER = 3;
    const int AREA_TRIAN = (BORDER + 1) * BORDER / 2;
    int matrix_el[AREA_TRIAN];
    int matrix[BORDER][BORDER] = {0};
    
    for (int i = 0; i < AREA_TRIAN; ++i)
    {
        cin >> matrix_el[i];
    }

    int delta_row = BORDER - 1;
    int counter = AREA_TRIAN - 1;

    for (int i = BORDER - 1; i >= 0; --i)
    {
        for (int n = BORDER - 1; n >= delta_row; --n)
        {
            matrix[i][n] = matrix_el[counter];
            --counter;
        }

        --delta_row;
    }

    int res_el[AREA_TRIAN];
    int column_index = 0;
    int res_index = 0;

    for (int i = 0; i < BORDER*BORDER; ++i)
    {
        int sum = 0;
        
        for(int n = 0; n < BORDER; ++n)
        {
            sum += matrix[i / 3][n] * matrix[n][column_index];
        }

        ++column_index;

        if (column_index > 2)
        {
            column_index = 0;
        }

        if (sum == 0)
        {
            continue;
        }

        res_el[res_index] = sum;
        ++res_index;
    }

    delta_row = BORDER - 1;
    counter = AREA_TRIAN - 1;
    int res_matrix[BORDER][BORDER] = {0};

    for (int i = BORDER - 1; i >= 0; --i)
    {
        for (int n = BORDER - 1; n >= delta_row; --n)
        {
            res_matrix[i][n] = res_el[counter];
            --counter;
        }

        --delta_row;
    }

    for (int i = 0; i < BORDER; ++i)
    {
        for (int n = 0; n < BORDER; ++n)
        {
            if (matrix[i][n] == 0)
            {
                cout << ' ' << '\t';
                continue;
            }

            cout << matrix[i][n] << '\t';
        }

        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < BORDER; ++i)
    {
        for (int n = 0; n < BORDER; ++n)
        {
            if (matrix[i][n] == 0)
            {
                cout << ' ' << '\t';
                continue;
            }

            cout << res_matrix[i][n] << '\t';
        }

        cout << endl;
    }

}
