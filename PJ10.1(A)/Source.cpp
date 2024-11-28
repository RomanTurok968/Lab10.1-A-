#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

enum Specialty { KOMP_NAUKY, INFORMATYKA, MATEMATYKA_EKONOMIKA, FIZYKA_INFORMATYKA, TRUDOVE_NAVCHANNYA };
string specialtyStr[] = { "Комп’ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student
{
    string prizv;
    unsigned course;
    Specialty specialty;
    int evaluations_physics;
    int evaluations_mathematics;
    int evaluations_computer_science;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
double ExcellentStudents(Student* p, const int N);
void PhysicsExcellent(Student* p, const int N);
double MaxAverageScore(Student* p, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів N: "; cin >> N;

    Student* p = new Student[N];
    int menuItem;
    do {
        cout << endl << "Виберіть дію:" << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [2] - вивід даних на екран" << endl;
        cout << " [3] - Обчислення відсотка відмінників" << endl;
        cout << " [4] - Виведення студентів, які отримали з фізики оцінку “5”" << endl;
        cout << " [5] - Обчислення найбільшого середнього бала" << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        switch (menuItem)
        {
        case 1:
            Create(p, N);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            cout << "Відсоток студентів, які навчаються на “відмінно”: "
                << ExcellentStudents(p, N) << "%" << endl;
            break;
        case 4:
            PhysicsExcellent(p, N);
            break;
        case 5:
            cout << "Найбільший середній бал серед студентів: "
                << MaxAverageScore(p, N) << endl;
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);

    delete[] p;
    return 0;
}

void Create(Student* p, const int N)
{
    int specialty;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " прізвище: "; getline(cin, p[i].prizv);
        cout << " курс: "; cin >> p[i].course;
        cout << " спеціальність (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> specialty;
        p[i].specialty = (Specialty)specialty;
        cout << " оцінки фізики: "; cin >> p[i].evaluations_physics;
        cout << " оцінки математики: "; cin >> p[i].evaluations_mathematics;
        cout << " оцінки інформатики: "; cin >> p[i].evaluations_computer_science;
    }
}

void Print(Student* p, const int N)
{
    cout << "=====================================================================================================================" << endl;
    cout << "| № | Прізвище        | Курс | Спеціальність           | Оцінки фізики | Оцінки математики | Оцінки інформатики |" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << i + 1 << " | "
            << setw(14) << left << p[i].prizv
            << "| " << setw(4) << right << p[i].course << " | "
            << setw(24) << left << specialtyStr[p[i].specialty] << " | "
            << setw(13) << right << p[i].evaluations_physics << " | "
            << setw(16) << right << p[i].evaluations_mathematics << " | "
            << setw(18) << right << p[i].evaluations_computer_science << " |" << endl;
    }
    cout << "=====================================================================================================================" << endl;
}

double ExcellentStudents(Student* p, const int N)
{
    int countExcellent = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].evaluations_physics == 5 && p[i].evaluations_mathematics == 5 && p[i].evaluations_computer_science == 5)
            countExcellent++;
    }
    return (double)countExcellent / N * 100;
}

void PhysicsExcellent(Student* p, const int N)
{
    cout << "Студенти, які отримали з фізики оцінку “5”:" << endl;
    bool found = false;
    for (int i = 0; i < N; i++)
    {
        if (p[i].evaluations_physics == 5)
        {
            cout << p[i].prizv << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Немає студентів з оцінкою “5” з фізики." << endl;
}

double MaxAverageScore(Student* p, const int N)
{
    double maxAverage = 0.0;
    for (int i = 0; i < N; i++)
    {
        double average = (p[i].evaluations_physics + p[i].evaluations_mathematics + p[i].evaluations_computer_science) / 3.0;
        if (average > maxAverage)
            maxAverage = average;
    }
    return maxAverage;
}
