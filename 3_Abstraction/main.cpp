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

        // Contrato de promoção
        virtual void AskForPromotion(){
            // Regra para a promoção
            if(Age > 30){
                cout << getName() << " got promoted!" << endl;
            } else{
                cout << getName() << ", sorry No promotion for you!" << endl;
            }
        }

};


int main()
{
    Employee employee1("Saldina", "YT - CodeBeauty", 25);
    Employee employee2("John", "Amazon", 35);

    employee1.AskForPromotion();
    employee2.AskForPromotion();

}
