#include <iostream>
using namespace std;

// Classe
class Employee{
    private:
        // Objetos
        string Name;
        string Company;
        int Age;

    public:

        /*
        Encapsulamento
        O Encapsulamento é feito a partir de dois comandos
        setters e getter
        Obs: estes métodos só funcionam porque estão na aba "public"
        */

        // setter
        void setName(string name){
            Name = name; // a função set recebe o valor name e encapsula em Name
        }

        // getter
        string getName(){
            return Name; // a função get retorna o valor Name
        }

        // setter and getter
        void setCompany(string company){
            Company = company;
        }
        string getCompany(){
            return Company;
        }

        // setter and getter

        /*
        A vantagem de usar setters e getters é poder definir
        regras para o encapsulamento de informações, como o
        exemplo abaixo:
        */

        void setAge(int age){
        // apenas salva a informação se o funcionário for maior de idade
            if (age >= 18){
                Age = age;
            }

        }
        int getAge(){
            return Age;
        }

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
    employee1.IntroduceYourself();

    Employee employee2("John", "Amazon", 35);
    employee2.IntroduceYourself();

    employee1.setAge(15);
    cout << employee1.getName() << " is " << employee1.getAge() << " years old." << endl;
    return 0;
}
