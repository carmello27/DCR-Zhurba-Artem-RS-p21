#include <iostream> //Ці рядки коду включають необхідні заголовочні файли для використання класу Customer і для введення/виведення даних з консолі.
#include "customer.h"

Customer::Customer() //Цей рядок коду визначає конструктор за замовчуванням для класу Customer. Конструктор порожній, тобто не приймає жодних аргументів і не має тіла.
{

}

Customer::Customer(int ID, std::string firstName, std::string lastName, int creditCardNumber, int bankAccountNumber)
{
    this->ID = ID; //Цей рядок коду визначає конструктор з параметрами для класу Customer. Він приймає п'ять аргументів, які встановлюють значення полів об'єкта Customer.cpp

    this->firstName = firstName;
    this->lastName = lastName;
    this->creditCardNumber = creditCardNumber;
    this->bankAccountNumber = bankAccountNumber;
}

Customer::~Customer() // Цей рядок коду визначає деструктор для класу Customer. Деструктор порожній, тобто не має тіла.
{

}

void Customer::setID(int newID) // Ці рядки коду визначають набір методів "set" для класу Customer, які встановлюють значення полів об'єкта Customer.
{
    ID = newID;
}
void Customer::setFirstName(std::string newFirstName)
{
    firstName = newFirstName;
}
void Customer::setLastName(std::string newLastName)
{
    lastName = newLastName;
}
void Customer::setCreditCardNumber(int newCreditCardNumber)
{
    creditCardNumber = newCreditCardNumber;
}
void Customer::setBankAccoutNumber(int newBankAccoutNumber)
{
    bankAccountNumber = newBankAccoutNumber;
}

int Customer::getID() // Ці рядки коду визначають набір методів "get" для класу Customer, які повертають значення полів об'єкта Customer.
{
    return ID;
}
std::string Customer::getFirstName()
{
    return firstName;
}
std::string Customer::getLastName()
{
    return lastName;
}
int Customer::getCreditCardNumber()
{
    return creditCardNumber;
}
int Customer::getBankAccoutNumber()
{
    return bankAccountNumber;
}

std::string Customer::toString() const // Цей рядок коду визначає метод toString(), який повертає рядкове представлення об'єкта Customer, об'єднуючи значення полів у одному рядку.
{
    return std::to_string(ID) + "  "
        + firstName + "  "
        + lastName + "  "
        + std::to_string(creditCardNumber) + "  "
        + std::to_string(bankAccountNumber);
}

std::ostream& operator<<(std::ostream& os, const Customer& customer) // Цей рядок коду перевантажує оператор << для класу Customer, що дозволяє виводити об'єкт Customer за допомогою потоку виведення. Об'єкт Customer перетворюється на рядок за допомогою методу toString(), і цей рядок виводиться за допомогою потоку os.
{
    os << customer.toString();
    return os;
}

void sortByLastName(Customer* customers, int numCustomers) // Цей рядок коду визначає функцію sortByLastName, яка сортує масив об'єктів Customer за прізвищем в алфавітному порядку. Використовується алгоритм сортування "бульбашкою".
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

void filterByCreditCardRange(Customer* customers, int numCustomers, int minRange, int maxRange) //Цей рядок коду визначає функцію filterByCreditCardRange, яка виводить об'єкти Customer, які мають номер кредитної картки в заданому діапазоні (minRange і maxRange). Об'єкти виводяться на консоль за допомогою оператора <<.
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