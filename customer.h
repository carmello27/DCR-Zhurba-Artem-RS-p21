#ifndef CUSTOMER_H /// ֳ ��������� ������������ (#ifndef, #define) ���������������� ��� ��������� ��������� ��������� �����. 
#define CUSTOMER_H /// ���� ����������, �� �� ���� ��� ���������� ��������� ����� customer.h. 
                   /// ���� ������ ��������� �� ����, �� ���������� ��������� ���. 
                   ///�� ������ �� ���������� ��������� �����, �� ���� ��������� �� ������� � ��������� �����������.

#include <iostream> ///��� ����� ������ ������������ ���� <iostream>, ���� ������ ���������� ��������� ����� std::ostream � std::istream, � ����� ��������� ��'���� std::cin, std::cout � std::cerr.

class Customer /// ��� ����� ������ ���������� ����� Customer � ������� ���� ������� �� ������ �����.
{
private:
    int ID, creditCardNumber, bankAccountNumber;
    std::string lastName, firstName;
public:
    Customer(); /// ֳ ����� ���������� ����������� �� �������������, ����������� � ����������� �� ���������� ����� Customer.
    Customer(int ID, std::string firstName, std::string lastName, int creditCardNumber, int bankAccountNumber);
    ~Customer();

    void setID(int newID); /// ֳ ����� ���������� ������ ������-�������, �� ������������ �������� ��������� ���� ����� Customer.
    void setFirstName(std::string newFirstName);
    void setLastName(std::string newLastName);
    void setCreditCardNumber(int newCreditCardNumber);
    void setBankAccoutNumber(int newBankAccoutNumber);

    int getID(); /// ֳ ����� ���������� ������ ������-�������, �� ���������� �������� ��������� ���� ����� Customer.
    std::string getFirstName();
    std::string getLastName();
    int getCreditCardNumber();
    int getBankAccoutNumber();

    std::string toString() const; /// ��� ����� ������� �������� ����� toString(), ���� ������� ������� ������������� ��'���� ����� Customer.

    friend std::ostream& operator<<(std::ostream& os, const Customer& customer); ///��� ����� ������� ���������� �������-������� operator<<, ��� ����������� �������� ������ << ��� ��'���� ����� Customer. 
    /// ������� ������ ��������� �� ���� os ���� std::ostream �� ���������� ��������� �� ��'��� ����� Customer.
};

void sortByLastName(Customer* customers, int numCustomers);
void filterByCreditCardRange(Customer* customers, int numCustomers, int minRange, int maxRange);/// ֳ ����� ���������� ��������� ������� sortByLastName �� filterByCreditCardRange. 
/// ������� �� ���������� �������� (void) � ��������� �������� �� ����� ��'���� Customer, ������� ��'���� numCustomers ��, � ������� ������� filterByCreditCardRange, �������� �� ����������� �������� ��� ����������.

#endif