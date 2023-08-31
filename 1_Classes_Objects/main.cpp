#include <iostream>
using namespace std;

// Classe
class Employee{
    public:
        // Objetos
        string Name;
        string Company;
        int Age;

        void IntroduceYourself(){
            cout << "Name - " << Name << endl;
            cout << "Company - " << Company << endl;
            cout << "Age - " << Age << endl;
        }

        // Função construtora
        Employee(string name, string company, int age){
            Name = name;
            Company = company;
            Age = age;
        }

};

int main()
{
    Employee employee1("Saldina", "YT - CodeBeauty", 25);

    /*
    employee1.name = "Saldina";
    employee1.company = "YT - CodeBeauty";
    employee1.age = 25;
    */

    employee1.IntroduceYourself();

    Employee employee2("John", "Amazon", 35);

    /*
    employee2.name = "John";
    employee2.company = "Amazon";
    employee2.age = 35;
    */

    employee2.IntroduceYourself();

    return 0;
}
