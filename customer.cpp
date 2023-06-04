#include <iostream>
#include "customer.h"

Customer::Customer() ///У цьому рядку підключається необхідна бібліотека <iostream>, 
                     ///а також локальний заголовочний файл "customer.h", який містить опис класу Customer. 
                     ///Далі визначається конструктор за замовчуванням для класу Customer.
{

}

Customer::Customer(int ID, std::string firstName, std::string lastName, int creditCardNumber, int bankAccountNumber)
{
    this->ID = ID;  /// Це визначення конструктора класу Customer, який приймає параметри ID, firstName, lastName, creditCardNumber та bankAccountNumber. 
                    ///Всі ці параметри присвоюються відповідним полям об'єкта.
    this->firstName = firstName;
    this->lastName = lastName;
    this->creditCardNumber = creditCardNumber;
    this->bankAccountNumber = bankAccountNumber;
}

Customer::~Customer() /// Код деструктора класу Customer залишений порожнім. Це означає, що немає спеціальних дій, які потрібно виконати при знищенні об'єкта класу Customer.
{

}

void Customer::setID(int newID) /// Ця функція встановлює значення поля ID об'єкта класу Customer на передане значення newID.
{
    ID = newID;
}
void Customer::setFirstName(std::string newFirstName) /// Ця функція встановлює значення поля firstName об'єкта класу Customer на передане значення newFirstName.
{
    firstName = newFirstName;
}
void Customer::setLastName(std::string newLastName) /// Ця функція встановлює значення поля lastName об'єкта класу Customer на передане значення newLastName.
{
    lastName = newLastName;
}
void Customer::setCreditCardNumber(int newCreditCardNumber) /// Ця функція встановлює значення поля creditCardNumber об'єкта класу Customer на передане значення newCreditCardNumber.
{
    creditCardNumber = newCreditCardNumber;
}
void Customer::setBankAccoutNumber(int newBankAccoutNumber) /// Ця функція встановлює значення поля bankAccountNumber об'єкта класу Customer на передане значення newBankAccoutNumber.
{
    bankAccountNumber = newBankAccoutNumber;
}


int Customer::getID() /// Ця функція повертає значення поля ID об'єкта класу Customer.
{
    return ID;
}
std::string Customer::getFirstName() /// Ця функція повертає значення поля firstName об'єкта класу Customer.
{
    return firstName;
}
std::string Customer::getLastName() /// Ця функція повертає значення поля LastName об'єкта класу Customer.
{
    return lastName;
}
int Customer::getCreditCardNumber() /// Ця функція повертає значення поля creditCardNumber об'єкта класу Customer.
{   
    return creditCardNumber;
}
int Customer::getBankAccoutNumber() ///Ця функція повертає значення поля bankAccountNumber об'єкта класу Customer.
{
    return bankAccountNumber;
}


std::string Customer::toString() const /// Цей метод повертає рядок, який містить розформатовану інформацію про об'єкт класу Customer, включаючи ID, firstName, lastName, creditCardNumber та bankAccountNumber.
{
    return std::to_string(ID) + "  " 
    + firstName + "  " 
    + lastName + "  " 
    + std::to_string(creditCardNumber) + "  "
    + std::to_string(bankAccountNumber);
}


std::ostream& operator<<(std::ostream& os, const Customer& customer) /// Ця функція перевантажує оператор виводу (<<) для об'єктів класу Customer. Вона використовує метод toString() для отримання рядкового представлення об'єкта Customer і виводить його у потік os. 
{
    os << customer.toString();
    return os;
}


void sortByLastName(Customer* customers, int numCustomers) /// Ця функція сортує масив об'єктів класу Customer за прізвищем (lastName). Вона використовує алгоритм сортування бульбашкою.
{
    for (int i = 0; i < numCustomers - 1; i++)
    {
        for (int j = 0; j < numCustomers - i - 1; j++)
        {
            if (customers[j].getLastName() > customers[j + 1].getLastName()) 
            {
                std::swap(customers[j], customers[j + 1]);
            }
        }
    }
}


void filterByCreditCardRange(Customer* customers, int numCustomers, int minRange, int maxRange) /// Ця функція фільтрує об'єкти класу Customer за номером кредитної картки (creditCardNumber). 
                                                                                                /// Вона виводить усі об'єкти, у яких номер кредитної картки знаходиться в заданому діапазоні minRange і maxRange.
{    
    for (int i = 0; i < numCustomers; i++) 
    {
        int creditCardNumber = customers[i].getCreditCardNumber();        

        if (creditCardNumber >= minRange && creditCardNumber <= maxRange) 
        {
            std::cout << customers[i] << std::endl;
        }
    }
}
