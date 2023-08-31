#include <iostream>
using namespace std;

/*
Para que uma pessoa verifique se poderá ou não ser promovida
é necessário que ela assine um contrato, o contrato é dado
pela função virtual "AskForPromotion"
*/

// classe abstrata
class AbstractEmployee{
    // virtual function or abstract function (regra para promoção)
    virtual void AskForPromotion() = 0;
};

// Classe
/*
para inserir a assinatura do contrato na classe de empregados
basta adicionar (:AbstractEmployee) na frente da classe
assim dizemos que a classe Employee assinou o contrato AbstractEmployee
*/
class Employee : AbstractEmployee{ // em outras palavras, aqui temos uma herança
    private:
        // Objetos
        string Company;
        int Age;
    protected:
        string Name;
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

        // Contrato de promoção
        virtual void AskForPromotion(){
            // Regra para a promoção
            if(Age > 30){
                cout << getName() << " got promoted!" << endl;
            } else{
                cout << getName() << ", sorry No promotion for you!" << endl;
            }
        }
        /*
        quando uma função virtual é invocada ela verifica se existe implementações
        desta função em outras classes derivadas e se sim, execute-as
        */
        virtual void Work(){
            cout << Name << " is checking email, task backlog, performing tasks ... " << endl;
        }

};
/*
criando uma classe de desenvolvedores
Além disso a classe de desenvolvedores herda a classe
de trabalhadores (sendo assim a classe filha)

Obs: se a classe pai tem uma função construtora, então
a classe que herda estas informações também necessita ter
*/
class Developer : public Employee { // quando colocamos público, temos acesso a todas as funções herdadas
    public:
        string FavProgrammingLanguage;
        Developer(string name, string company, int age, string favprogramminglanguage)
            // funções construtoras que já foram herdadas e não precisamos nos preocupar
            : Employee(name,company, age)
        {
            // funções construtoras que devemos nos preocupar
            FavProgrammingLanguage = favprogramminglanguage;
        }
        void FixBug(){
            cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
        }
        // função derivada da classe employee e adaptada para a classe Developer
        void Work(){
            cout << Name << " is writing " <<  FavProgrammingLanguage << " code"<< endl;
        }
};

class Teacher : public Employee{
    public:
        string Subject;
        void PrepareLesson(){
            cout << Name << " is preparing " << Subject << " lesson " << endl;
        }
        Teacher(string name, string company, int age, string subject)
            : Employee(name, company, age)
        {
            Subject = subject;
        }
        // função derivada da classe employee e adaptada para a classe Teacher
        void Work(){
            cout << Name << " is teaching " <<  Subject << endl;
        }
};

int main()  // O mais comum em usar polymorfismo é quando
            // referencias de classes pai são usadas para referenciar
            // objetos de classes filhas, mas com algumas adaptações
            // olhar a função Work que é dada como exemplo
{
    Developer developer1("Saldina", "YT - CodeBeauty", 25, "C++");
    Teacher teacher1("Jack", "Cool School", 35, "History");

    // criando ponteiros da classe base para um objeto derivado
    Employee* employee1 = &developer1;
    Employee* employee2 = &teacher1;

    //
    employee1->Work();
    employee2->Work();
}
