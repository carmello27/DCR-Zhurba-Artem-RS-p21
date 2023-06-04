#include <iostream> //ֳ ����� ���� ��������� �������� ���������� ����� ��� ������������ ����� Customer � ��� ��������/��������� ����� � ������.
#include "customer.h"

Customer::Customer() //��� ����� ���� ������� ����������� �� ������������� ��� ����� Customer. ����������� �������, ����� �� ������ ������ ��������� � �� �� ���.
{

}

Customer::Customer(int ID, std::string firstName, std::string lastName, int creditCardNumber, int bankAccountNumber)
{
    this->ID = ID; //��� ����� ���� ������� ����������� � ����������� ��� ����� Customer. ³� ������ �'��� ���������, �� ������������ �������� ���� ��'���� Customer.cpp

    this->firstName = firstName;
    this->lastName = lastName;
    this->creditCardNumber = creditCardNumber;
    this->bankAccountNumber = bankAccountNumber;
}

Customer::~Customer() // ��� ����� ���� ������� ���������� ��� ����� Customer. ���������� �������, ����� �� �� ���.
{

}

void Customer::setID(int newID) // ֳ ����� ���� ���������� ���� ������ "set" ��� ����� Customer, �� ������������ �������� ���� ��'���� Customer.
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

int Customer::getID() // ֳ ����� ���� ���������� ���� ������ "get" ��� ����� Customer, �� ���������� �������� ���� ��'���� Customer.
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

std::string Customer::toString() const // ��� ����� ���� ������� ����� toString(), ���� ������� ������� ������������� ��'���� Customer, ��'������� �������� ���� � ������ �����.
{
    return std::to_string(ID) + "  "
        + firstName + "  "
        + lastName + "  "
        + std::to_string(creditCardNumber) + "  "
        + std::to_string(bankAccountNumber);
}

std::ostream& operator<<(std::ostream& os, const Customer& customer) // ��� ����� ���� ����������� �������� << ��� ����� Customer, �� �������� �������� ��'��� Customer �� ��������� ������ ���������. ��'��� Customer �������������� �� ����� �� ��������� ������ toString(), � ��� ����� ���������� �� ��������� ������ os.
{
    os << customer.toString();
    return os;
}

void sortByLastName(Customer* customers, int numCustomers) // ��� ����� ���� ������� ������� sortByLastName, ��� ����� ����� ��'���� Customer �� �������� � ���������� �������. ��������������� �������� ���������� "����������".
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

void filterByCreditCardRange(Customer* customers, int numCustomers, int minRange, int maxRange) //��� ����� ���� ������� ������� filterByCreditCardRange, ��� �������� ��'���� Customer, �� ����� ����� �������� ������ � �������� ������� (minRange � maxRange). ��'���� ���������� �� ������� �� ��������� ��������� <<.
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