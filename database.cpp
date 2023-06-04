#include <iostream> // ֳ ����� ��������� �������� ���������� �����, �� ������ ����������������� � ����� ����. 
#include "sqlite3.h" // <iostream> ������ ��������� ������ ��������/���������, "sqlite3.h" ������ ���������� ��� ������ � ����� ����� SQLite, "customer.h" ������ ���������� ����� Customer, � "database.h" ������ ���������� ����� DataBase.
#include "customer.h"
#include "database.h"

DataBase::DataBase() // ��� ��� � ������������� ����� DataBase. ³� ������� �'������� � ����� ����� SQLite, ��� ����������� � ���� db.db. 
///���� ���������� SQL-����� ��� ��������� ��� ������ � ������� Customers.
{
    int rc = sqlite3_open("db.db", &db);
    char* errMsg;
    const std::string query = "DELETE FROM Customers";
    rc = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
}

DataBase::~DataBase() // ��� ��� � ������������ ����� DataBase. ³� ������� �'������� � ����� ����� SQLite, �� ���� ������� � �����������.
{
    sqlite3_close(db);
}

void DataBase::insertInDB(Customer* customers, int number, int i) // ��� ����� insertInDB ������ SQL-����� ��� ������� ������ ������ � ������� Customers ���� �����. 
// ����� ��������� � ����� ��'���� Customer, ��������� ����� ��������� �������� customers, �� ��������� number (������� ������) � i (������ ��������� ������). ����� ���������� �� ��������� ������� sqlite3_exec.
{
    char* errMsg;
    const std::string query = "INSERT INTO Customers (ID, FirstName, LastName, CreditCardNumber, BankAccountNumber) "
        "VALUES (" + std::to_string(customers[i].getID()) + ", '" + customers[i].getFirstName() +
        "', '" + customers[i].getLastName() + "', " + std::to_string(customers[i].getCreditCardNumber()) +
        ", " + std::to_string(customers[i].getBankAccoutNumber()) + ");";
    sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
}

void DataBase::clearDB() // ��� ����� clearDB ������ SQL-����� ��� ��������� ��� ������ � ������� Customers ���� �����. ����� ���������� �� ��������� ������� sqlite3_exec.
{
    char* errMsg;
    const std::string query = "DELETE FROM Customers";
    sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
}
