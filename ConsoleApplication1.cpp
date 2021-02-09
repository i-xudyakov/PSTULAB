#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream input("InputeFile.txt");
struct Information
{
    string nositel;
    string obiem;
    string name;
    string autor;
};
void vivod(Information infof)
{
    cout << "Носитель: " << infof.nositel << endl;;
    cout << "Объём: " << infof.obiem << endl;
    cout <<"Название: " << infof.name << endl;;
    cout <<"Автор: " << infof.autor << endl;
    cout << endl;
}
Information fileinput(Information infof)
{
    getline(input, infof.nositel);
    getline(input, infof.obiem);
    getline(input, infof.name);
    getline(input, infof.autor);
    return infof;
} 
int main()
{
    bool f=false;
    int i=1;
    string k;
    int l, a;
    int n = 4;
    if (input.is_open()) 
    {
        Information info[20];
        setlocale(LC_ALL, "rus");
        for (int i = 1; i < n; i++)
        {
            info[i] = fileinput(info[i]);
        }
        for (int i = 1; i < 4; i++)
        {
            vivod(info[i]);
        }
        cout << "Введите объем, которым владеет файл который нужно удалить (Объём= число(TB,GB,KB,MB,B) = ";
        getline(cin, k);
        while (f==false) 
        {
            for (i = 1; i < 4; i++)
            {
                if (info[i].obiem == k) { f = true; l = i;}
            }
            if (f == false) { cout << "Данный объем не найден, введите другой: "; getline(cin, k); }
        }
        cout << endl;
        for (l = l; l < n; l++)
        {
            info[l] = info[l + 1];
        }
        for (int i = 1; i < n - 1; i++)
        {
            vivod(info[i]);
        }
        cout << "Введите номер структуры, перед  которой нужно добавить ещё один элемент: ";
        cin >> a;
        cout << endl;
        while ((a > n - 2) || (l < 1))
        {
            cout << "Структуры под таким номером нет, введите другой номер: "; 
            cin >> a;
            cout << endl; 
        }
        cout << endl;
        for (i = n-1; i > a; i--)
        {
            info[i]=info[i-1];
        }
        info[a]=fileinput(info[a]);
        for (int i = 1; i < n; i++)
        {
            vivod(info[i]);
        }
        input.close();
    }
    else { cout << "Файл с данными отсутствует или закрыт"; }
    input.close();
}
