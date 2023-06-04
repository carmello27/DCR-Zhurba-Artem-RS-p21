#include <iostream>
#include "customer.h"

Customer::Customer() ///� ����� ����� ����������� ��������� �������� <iostream>, 
                     ///� ����� ��������� ������������ ���� "customer.h", ���� ������ ���� ����� Customer. 
                     ///��� ����������� ����������� �� ������������� ��� ����� Customer.
{

}

Customer::Customer(int ID, std::string firstName, std::string lastName, int creditCardNumber, int bankAccountNumber)
{
    this->ID = ID;  /// �� ���������� ������������ ����� Customer, ���� ������ ��������� ID, firstName, lastName, creditCardNumber �� bankAccountNumber. 
                    ///�� �� ��������� ������������ ��������� ����� ��'����.
    this->firstName = firstName;
    this->lastName = lastName;
    this->creditCardNumber = creditCardNumber;
    this->bankAccountNumber = bankAccountNumber;
}

Customer::~Customer() /// ��� ����������� ����� Customer ��������� �������. �� ������, �� ���� ����������� ��, �� ������� �������� ��� ������� ��'���� ����� Customer.
{

}

void Customer::setID(int newID) /// �� ������� ���������� �������� ���� ID ��'���� ����� Customer �� �������� �������� newID.
{
    ID = newID;
}
void Customer::setFirstName(std::string newFirstName) /// �� ������� ���������� �������� ���� firstName ��'���� ����� Customer �� �������� �������� newFirstName.
{
    firstName = newFirstName;
}
void Customer::setLastName(std::string newLastName) /// �� ������� ���������� �������� ���� lastName ��'���� ����� Customer �� �������� �������� newLastName.
{
    lastName = newLastName;
}
void Customer::setCreditCardNumber(int newCreditCardNumber) /// �� ������� ���������� �������� ���� creditCardNumber ��'���� ����� Customer �� �������� �������� newCreditCardNumber.
{
    creditCardNumber = newCreditCardNumber;
}
void Customer::setBankAccoutNumber(int newBankAccoutNumber) /// �� ������� ���������� �������� ���� bankAccountNumber ��'���� ����� Customer �� �������� �������� newBankAccoutNumber.
{
    bankAccountNumber = newBankAccoutNumber;
}


int Customer::getID() /// �� ������� ������� �������� ���� ID ��'���� ����� Customer.
{
    return ID;
}
std::string Customer::getFirstName() /// �� ������� ������� �������� ���� firstName ��'���� ����� Customer.
{
    return firstName;
}
std::string Customer::getLastName() /// �� ������� ������� �������� ���� LastName ��'���� ����� Customer.
{
    return lastName;
}
int Customer::getCreditCardNumber() /// �� ������� ������� �������� ���� creditCardNumber ��'���� ����� Customer.
{   
    return creditCardNumber;
}
int Customer::getBankAccoutNumber() ///�� ������� ������� �������� ���� bankAccountNumber ��'���� ����� Customer.
{
    return bankAccountNumber;
}


std::string Customer::toString() const /// ��� ����� ������� �����, ���� ������ �������������� ���������� ��� ��'��� ����� Customer, ��������� ID, firstName, lastName, creditCardNumber �� bankAccountNumber.
{
    return std::to_string(ID) + "  " 
    + firstName + "  " 
    + lastName + "  " 
    + std::to_string(creditCardNumber) + "  "
    + std::to_string(bankAccountNumber);
}


std::ostream& operator<<(std::ostream& os, const Customer& customer) /// �� ������� ����������� �������� ������ (<<) ��� ��'���� ����� Customer. ���� ����������� ����� toString() ��� ��������� ��������� ������������� ��'���� Customer � �������� ���� � ���� os. 
{
    os << customer.toString();
    return os;
}


void sortByLastName(Customer* customers, int numCustomers) /// �� ������� ����� ����� ��'���� ����� Customer �� �������� (lastName). ���� ����������� �������� ���������� ����������.
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


void filterByCreditCardRange(Customer* customers, int numCustomers, int minRange, int maxRange) /// �� ������� ������� ��'���� ����� Customer �� ������� �������� ������ (creditCardNumber). 
                                                                                                /// ���� �������� �� ��'����, � ���� ����� �������� ������ ����������� � �������� ������� minRange � maxRange.
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
