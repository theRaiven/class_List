#include "convertDecHex.h"
#include "Matrix.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>  // Для time(nullptr)
#include <type_traits> // Для std::is_same

using namespace std;

template <class T>
T ReadDimensionFromFile(const std::string& filename);

template <typename T>
void SelectInput(T& val);

// **************

void ShowMatrixMenu();
void ShowNumberConversionMenu();


int main()
{
    setlocale(LC_ALL, "rus");
    int mainChoice;
    bool running = true;
    
    while (running)
    {
        cout << "\nГлавное меню:\n";
        cout << "1. Работа с матрицами (перемножение)\n";
        cout << "2. Конвертация чисел\n";
        cout << "3. Справка\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1:
            ShowMatrixMenu();
            break;
        case 2:
            ShowNumberConversionMenu();
            break;
        case 3:
        {
            ifstream helpFile("./documentation.txt");
            if (!helpFile)
            {
                cerr << "Не удалось открыть файл справки. Убедитесь, что файл documentation.txt находится в текущей директории.\n";
            }
            else
            {
                string line;
                while (getline(helpFile, line))
                {
                    cout << line << endl;
                }
            }
            break;
        }
        case 0:
            running = false;
            break;
        default:
            cout << "Неверный выбор!\n";
            break;
        }
    }

    return 0;
}

template <typename T>
void SelectInput(T& val)
{
    int choice;
    cout << "1. Ввести вручную\n2. Считать из файла\nВаш выбор: ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Введите данные: ";
        cin >> val;
    }
    else
    {
        string name;
        cout << "Имя файла: ";
        cin >> name;
        val = ReadDimensionFromFile<T>(name);
    }
}

void ShowMatrixMenu()
{
    int choice, size;
    cout << "1. Обычное перемножение\n2. С транспонированием\nВаш выбор: ";
    cin >> choice;
    SelectInput(size);
    if (choice == 1) MultiplyStandard(size);
    else if (choice == 2) MultiplyTransposed(size);
    else cout << "Неверный выбор!\n";
}

void ShowNumberConversionMenu()
{
    int choice, type;
    string input;
    cout << "1. В десятичное => hex\n2. Из hex => десятичное\nВаш выбор: ";
    cin >> choice;
    if (choice == 0) return;
    if (choice == 1)
    {
        cout << "Тип: 1 - float, 2 - double\nВаш выбор: ";
        cin >> type;
    }
    SelectInput(input);
    try
    {
        if (choice == 1)
        {
            if (type == 1) cout << ConvertHex(stof(input)) << endl;
            else if (type == 2) cout << ConvertHex(stod(input)) << endl;
            else cout << "Неверный тип!\n";
        }
        else if (choice == 2)
        {
            if (input.size() == 8)
            {
                cout << ConvertDec(input) << endl;
            }
            else if (input.size() == 16)
            {
                cout << ConvertDec(input) << endl;
            }
            else
            {
                cout << "Неподдерживаемая длина hex-строки\n";
            }
        }
    }
    catch (exception& e) { cerr << "Ошибка: " << e.what() << endl; }
}
template <class T>
T ReadDimensionFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Ошибка открытия файла: " + filename);
    }

    T dimension;
    std::string line;

    if (!std::getline(file, line))
    {
        throw std::runtime_error("Файл пуст");
    }
    std::istringstream iss(line);
    if (!(iss >> dimension)) {
        throw std::runtime_error("Неверный формат числа в файле");
    }
    return dimension;
}