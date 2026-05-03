#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

class Calc
{
private:
    string operatorr;
    double num1, num2;
    string str1, str2;
    vector <double> arr1;
    vector <double> arr2;
    double item;

    string getOperator() {
        return operatorr;
    }
    double getNum1() {
        return num1;
    }
    double getNum2() {
        return num2;
    }
    string getStr1() {
        return str1;
    }
    string getStr2() {
        return str2;
    }
    void setOperator(string _operatorr) {
        operatorr = _operatorr;
    }
    void setNum1(double _num1) {
        num1 = _num1;
    }
    void setNum2(double _num2) {
        num2 = _num2;
    }
    void setStr1(string _str1) {
        str1 = _str1;
    }
    void setStr2(string _str2) {
        str2 = _str2;
    }
    double sum() {
        return num1 + num2;
    }
    double sub() {
        return num1 - num2;
    }
    double prod() {
        return num1 * num2;
    }
    double divi() {
        return num1 / num2;
    }
    double sinn() {
        return sin(num1);
    }
    double coss() {
        return cos(num1);
    }
    double Log10() {
        return log10(num1);
    }
    double Log() {
        return log(num1) / log(num2);
    }
    string sumStr() {
        return str1 + str2;
    }
    void sumArr(vector <double> arr1, vector <double> arr2) {
        for (int i = 0; i < arr1.size(); i++) {
            cout << arr1[i] + arr2[i] << ' ';
        }
    }

public:
    void calculation() {
        while (true) {
            cout << "\nвведите оператор\n";
            cin >> operatorr;
            setOperator(operatorr);
            if (operatorr == "exit")
                break;
            else if (operatorr == "+" || operatorr == "-" || operatorr == "*" || operatorr == "/" || operatorr == "log") {
                cout << "введите 1 число\n";
                cin >> num1;
                setNum1(num1);

                cout << "введите 2 число\n";
                cin >> num2;
                setNum2(num2);

                if (operatorr == "+")
                    cout << sum();
                else if (operatorr == "-")
                    cout << sub();
                else if (operatorr == "*")
                    cout << prod();
                else if (operatorr == "/")
                    cout << divi();
                else {
                    cout << Log();
                }
            }
            else if (operatorr == "sin" || operatorr == "cos" || operatorr == "sin" || operatorr == "log10") {
                cout << "введите число\n";
                cin >> num1;
                setNum1(num1);

                if (operatorr == "cos")
                    cout << coss();
                else if (operatorr == "sin")
                    cout << sinn();
                else
                    cout << Log10();
            }
            else if (operatorr == "sumStr") {
                cout << "введите 1 строку\n";
                cin >> str1;
                setStr1(str1);
                cout << "введите 2 строку\n";
                cin >> str2;
                setStr2(str2);

                cout << sumStr();
            }
            else if (operatorr == "sumArr") {
                cout << "введите 1 массив (5 символов)\n";
                for (int i = 0; i < 5; i++) {
                    cin >> item;
                    arr1.push_back(item);
                }
                cout << "введите 2 массив (5 символов)\n";
                for (int i = 0; i < 5; i++) {
                    cin >> item;
                    arr2.push_back(item);
                }

                sumArr(arr1, arr2);
            }
            else {
                cout << "неверный оператор\n";
            }
        }
    }
};

enum Post
{
    programmer, manager, analyst, none
};

istream& operator>>(istream& is, Post& post)
{
    string name;
    is >> name;

    if (name == "programmer(0)" || name == "programmer")
        post = programmer;
    else if (name == "manager(1)" || name == "manager")
        post = manager;
    else if (name == "analyst(2)" || name == "analyst")
        post = analyst;
    else
        post = none;
    return is;
}

inline ostream& operator<<(ostream& os, Post& post)
{
    switch (post) {
    case programmer: {
        os << "programmer(0)";
        break;
    }
    case manager: {
        os << "manager(1)";
        break;
    }
    case analyst: {
        os << "analyst(2)";
        break;
    }
    case none: {
        os << "none(3)";
        break;
    }
    }
    return os;
}

void cinIntp(unsigned int& num) {
    while (true) {
        cin >> num;
        if (cin.fail() || num < 0) {
            cout << "ошибка! повторите набор: ";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
            break;
    }
}

void cinStr(string& str) {
    while (true) {
        cin >> str;
        if (str.size() < 2) {
            cout << "слишком короткое имя!: ";
            cin.clear();
        }
        else
            break;
    }
}

void cinFeatures(string &name, string &surname, unsigned int &age, unsigned int &salary, Post &post) {
    cout << "имя: ";
    cinStr(name);
    cout << "фамилия: ";
    cinStr(surname);
    cout << "возраст: ";
    cinIntp(age);
    cout << "зарплата: ";
    cinIntp(salary);
    cout << "должность: ";
    cin >> post;
    cout << '\n';
}

class Staff
{
private:
    string name;
    string surname;
    unsigned int age;
    unsigned int salary;
    Post post;

public:
    Staff(string _name, string _surname, unsigned int _age, unsigned int _salary, Post _post) {
        name = _name;
        surname = _surname;
        age = _age;
        salary = _salary;
        post = _post;
    }
    string getName() {
        return name;
    }
    string getSurname() {
        return surname;
    }
    unsigned int getAge() {
        return age;
    }
    unsigned int getSalary() {
        return salary;
    }
    Post getPost() {
        return post;
    }
};

class AccountSystem
{
private:
    vector <Staff> stuff;
    string name;
    string surname;
    unsigned int age;
    unsigned int salary;
    Post post;

    string startMessage = "Добро пожаловать в систему учёта сотрудников Московского Политеха!";
    string helpMessage = "\nДоступные операции:\n\nupdate - загрузить список сотрудников из файла\nadd - добавить нового сотрудника\nremove - удалить сотрудника\nlist - вывести список сотрудников\nsearchByName - поиск по имени\nsearchByPost - поиск по должности\nsave - сохранить изменения\nhelp - вывести справку\nexit - выход\n\n";

    string nameSearch;
    unsigned int postSearch;
    unsigned int width = 30;

public:
    AccountSystem() {
        update();
        cout << startMessage;
        cout << helpMessage;
    }

    void help() {
        cout << helpMessage;
    }

    void add() {
        cinFeatures(name, surname, age, salary, post);
        Staff item(name, surname, age, salary, post);
        stuff.push_back(item);
        save();
    }

    void remove() {
        cout << "введите номер сотрудника: ";
        int i;
        cin >> i;
        stuff.erase(stuff.begin() + i);
        cout << "\nсотрудник успешно удалён\n";
        save();
    }

    void coutHeader() {
        cout << setw(5) << left << "#" << setw(width) << left << "имя" << setw(width) << left << "фамилия" << setw(width) << left << "возраст" << setw(width) << left << "зарплата" << setw(width) << left << "должность" << '\n';
    }

    void coutRow(int i) {
        Post post = stuff[i].getPost();
        cout << setw(5) << left << i << setw(width) << left << stuff[i].getName() << setw(width) << left << stuff[i].getSurname() << setw(width) << left << stuff[i].getAge() << setw(width) << left << stuff[i].getSalary() << setw(width) << left << post << "\n\n";
    }

    void list() {
        coutHeader();
        for (int i = 0; i < stuff.size(); i++) {
            coutRow(i);
        }
    }

    void searchByName() {
        bool flag = false;
        cout << "\nвведите имя для поиска: ";
        cinStr(nameSearch);
        coutHeader();
        for (int i = 0; i < stuff.size(); i++) {
            if (stuff[i].getName() == nameSearch) {
                coutRow(i);
                flag = true;
            }
        }
        if (!flag)
            cout << "\nсовпадений не обнаружено\n";
    }

    void searchByPost() {
        bool flag = false;
        cout << "\nвведите должность для поиска: ";
        cin >> postSearch;
        coutHeader();
        for (int i = 0; i < stuff.size(); i++) {
            if (stuff[i].getPost() == postSearch) {
                coutRow(i);
                flag = true;
            }
        }
        if (!flag)
            cout << "\nсовпадений не обнаружено\n";
    }

    void update() {
        ifstream file("staff.txt");
        if (file.is_open()) {
            while (file >> name >> surname >> age >> salary >> post) {
                //file >> name >> surname >> age >> salary >> post;
                Staff item(name, surname, age, salary, post);
                stuff.push_back(item);
            }
            file.close();
            cout << "\nобновление выполнено успешно!\n\n";
        }
        else
            cout << "\nошибка открытия файла!\n";
    }

    void save() {
        ofstream file1("staff.txt", ios::trunc);
        if (file1.is_open()) {
            file1.clear();
            for(int i = 0; i < stuff.size(); i++) {
                Post post = stuff[i].getPost();
                file1 << setw(width) << left << stuff[i].getName() << setw(width) << left << stuff[i].getSurname() << setw(width) << left << stuff[i].getAge() << setw(width) << left << stuff[i].getSalary() << setw(width) << left << post << "\n\n";
            }
            file1.close();
            cout << "\nсохранение выполнено успешно!\n\n";
        }
        else
            cout << "\nошибка открытия файла!\n";
    }

    void UNKNOWN() {
        cout << "\nтакой операции не существует!\n";
        cout << helpMessage;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    //AccountSystem system;
    //string method;

    //Calc calc;
    //calc.calculation();
    cout << "(0) - запустить калькулятор\n(1) - запустить систему учёта сотрудников\n\n";
    bool prNumber;
    cin >> prNumber;

    if (!prNumber) {
        Calc calc;
        calc.calculation();
    }
    else {
        AccountSystem system;
        string method;
        while (true) {
            cin >> method;
            if (method == "exit") {
                return 0;
            }
            else if (method == "help") {
                system.help();
            }
            else if (method == "update") {
                system.update();
            }
            else if (method == "save") {
                system.save();
            }
            else if (method == "add") {
                system.add();
            }
            else if (method == "remove") {
                system.remove();
            }
            else if (method == "list") {
                system.list();
            }
            else if (method == "searchByName") {
                system.searchByName();
            }
            else if (method == "searchByPost") {
                system.searchByPost();
            }
            else {
                system.UNKNOWN();
            }
        }
    }
    return 0;
}
