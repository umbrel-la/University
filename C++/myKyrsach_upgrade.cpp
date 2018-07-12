#include <iostream>
using namespace std;

// 1 �������
int **giveMemoryToM1(int**, const int&, const int&);
void fill_M1(int**, const int&, const int&);
void showM1(int**, const int&, const int&);
int **freeM1(int **, const int&);

// 2 �������
int **giveMemoryToM2(int**, const int&, const int&);
void fill_M2(int**, const int&, const int&);
void showM2(int**, const int&, const int&);
int **freeM2(int**, const int&);

// ������� 3
int **giveMemoryToM3(int**, const int&, const int&);
void fill_M3(int**, int**, int**, const int&, const int&, const int&);
void showM3(int**, const int&, const int&);
int **zeroingM3(int**, const int&, const int&);
int **freeM3(int**, const int&);


int main()
{
    setlocale(0, "rus");
    ios_base::sync_with_stdio(false);
    
    int **ptrM1 = nullptr,
    **ptrM2 = nullptr,
    **ptrM3 = nullptr;
    int row, columns, rowM2, columnsM2;
    
    cout << "**********��������� ������ **********\t" << endl;
    // 1 �������
    
    cout << "����� ���-�� ����� 1 ������� ";
    cin >> row;
    cout << "����� ���-�� �������� 1 ������� ";
    cin >> columns;
    
    ptrM1 = giveMemoryToM1(ptrM1, row, columns);
    fill_M1(ptrM1, row, columns);
    do{
        // 2 �������
        cout << "����� ���-�� ����� 2 ������� ";
        cin >> rowM2;
        cout << "����� ���-�� �������� 2 ������� ";
        cin >> columnsM2;
        if (columns != rowM2){
            cout << "��������� ������ ���������� !" << endl;
        }
    } while (row != columnsM2);
    ptrM2 = giveMemoryToM2(ptrM2, rowM2, columnsM2);
    fill_M2(ptrM2, rowM2, columnsM2);
    
    
    showM1(ptrM1, row, columns);
    cout << endl;
    showM2(ptrM2, rowM2, columnsM2);
    cout << endl;
    // ��������� ������ ��� 3 �������
    ptrM3 = giveMemoryToM3(ptrM3, row, columnsM2);
    // ��������� 3 �������
    ptrM3 = zeroingM3(ptrM3, row, columnsM2);
    // ��������� ���� ������
    fill_M3(ptrM1, ptrM2, ptrM3, row, columns, columnsM2);
    showM3(ptrM3, row, columnsM2);
    ptrM1 = freeM1(ptrM1, row);
    ptrM2 = freeM2(ptrM2, rowM2);
    ptrM3 = freeM3(ptrM3, row);
    
    cin.get();
}

// 1 �������
// ��������� ������ ��� 1 �������
int **giveMemoryToM1(int **M1, const int &row, const int &colums)
{
    M1 = new int *[row];
    for (int i = 0; i < (row); i++){
        M1[i] = new int[colums];
    }
    return M1;
}
// ��������� 1 �������
void fill_M1(int **M1, const int &row, const int &columns)
{
    for (int i = 0; i < row; i++){
        for (int j = 0; j < columns; j++){
            cout << "[" << i << "." << j << "]";
            cin >> M1[i][j];
        }
    }
}
// ������� 1 ������� �� �������
void showM1(int **M1, const int &row, const int &columns)
{
    for (int i = 0; i < row; i++){
        cout << "|";
        for (int j = 0; j < columns; j++){
            cout << M1[i][j] << " ";
        }
        cout << "|";
        cout << endl;
    }
    
}

// 2 �������
// ��������� ������ ��� 2 �������
int **giveMemoryToM2(int **M2, const int &rowM2, const int &columsM2)
{
    M2 = new int *[rowM2];
    for (int i = 0; i < rowM2; i++){
        M2[i] = new int[columsM2];
    }
    return M2;
}
// ��������� 2 �������
void fill_M2(int **M2, const int &rowM2, const int &columnsM2)
{
    for (int i = 0; i < rowM2; i++){
        for (int j = 0; j < columnsM2; j++){
            cout << "[" << i << "." << j << "]";
            cin >> M2[i][j];
        }
    }
}
// ������� 2 ������� �� �������
void showM2(int **M2, const int &rowM2, const int &columnsM2)
{
    for (int i = 0; i < rowM2; i++){
        cout << "|";
        for (int j = 0; j < columnsM2; j++){
            cout << M2[i][j] << " ";
        }
        cout << "|";
        cout << endl;
    }
}

// 3 �������
// ��������� ������ ��� 3 �������
int **giveMemoryToM3(int **M3, const int &row, const int &columns)
{
    
    M3 = new int*[row];
    for (int i = 0; i < row; i++){
        M3[i] = new int[columns];
    }
    
    return M3;
}
// ��������� 1 ������� �� 2
void fill_M3(int **ptrM1, int **ptrM2, int **ptrM3, const int &row, const int &colums, const int &columsM2)
{
    for (int i = 0; i < row; i++){
        for (int j = 0; j < columsM2; j++){
            for (int m = 0; m < colums; m++){
                ptrM3[i][j] += ptrM1[i][m] * ptrM2[m][j];
            }
        }
    }
}

// ����� 3 �������
void showM3(int **ptrM3, const int &row, const int &colomns)
{
    for (int i = 0; i < row; i++){
        cout << "|";
        for (int j = 0; j < colomns; j++){
            cout << ptrM3[i][j] << " ";
        }
        cout << "|";
        cout << endl;
    }
}

// ��������� 3 �������

int **zeroingM3(int **M3, const int &row, const int &colomns)
{
    
    for (int i = 0; i < row; i++){
        for (int j = 0; j < colomns; j++){
            M3[i][j] = 0;
        }
    }
    
    return M3;
}

// ������������ 1 �������
int **freeM1(int **M1, const int &row)
{
    for (int i = 0; i < row; i++){
        delete[] M1[i];
    }
    delete M1;
    return nullptr;
}

// ������������ 2 �������
int **freeM2(int **M2, const int &row)
{
    for (int i = 0; i < row; i++){
        delete[] M2[i];
    }
    delete M2;
    return nullptr;
}

// ������������ 3 �������
int **freeM3(int **M3, const int &row)
{
    for (int i = 0; i < row; i++){
        delete[] M3[i];
    }
    delete M3;
    return nullptr;
}
