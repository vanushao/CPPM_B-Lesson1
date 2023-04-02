#include <fstream>
#include <iostream>

int * fill_array(const int size, std::ifstream& fin) {
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        fin >> arr[i];
    }
    return arr;
}

void shift_array(int *arr, const int size, bool direction) {
    if (direction) {
        int tmp = arr[size-1];
        for (int i = size - 1; i > 0; --i) {
            arr[i] = arr[i-1];
        }
        arr[0] = tmp;
    }
    else {
        int tmp = arr[0];
        for (int i = 0; i < (size - 1); ++i) {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = tmp;
    }
}

int main()
{
    std::ifstream finput("in.txt");
    //finput.open("in.txt");
    
    if (!finput) {
        std::cout << "Can't read file or file doesn't exist" << std::endl;
        return 1;
    }

    int n_item;
    finput >> n_item;
    int* arr_n = fill_array(n_item, finput);

    int m_item;
    finput >> m_item;
    int* arr_m = fill_array(m_item, finput);
    finput.close();

    shift_array(arr_n, n_item, false);
    shift_array(arr_m, m_item, true);
    std::ofstream foutput("out.txt");
    
    foutput << m_item << '\n';
    for (int i = 0; i < (m_item - 1); ++i){
        foutput << arr_m[i] << " ";
    }
    foutput << arr_m[m_item - 1] << '\n';

    foutput << n_item << '\n';
    for (int i = 0; i < (n_item - 1); ++i) {
        foutput << arr_n[i] << " ";
    }
    foutput << arr_n[n_item - 1] << '\n';


    delete[] arr_n;
    delete[] arr_m;
    arr_n = nullptr;
    arr_m = nullptr;
    foutput.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
