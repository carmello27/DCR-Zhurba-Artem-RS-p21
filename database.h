#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>//ֳ ����� ���� ��������� �������� ���������� ����� ��� ������������ ����� sqlite3 �� ����� Customer.
#include "customer.h"

class DataBase // �� �������� ������ ������� ������� ���������� ����� DataBase. ³� �� �������� ���� db, ��� � ���������� �� ��'��� sqlite3. �� ���� ���� ����������������� ��� ���������� �'������� � ����� �����.
{
private:
    sqlite3* db;       

public: // ֳ ����� ���� ���������� ������ ������ ����� DataBase. ������ ��������� ����������� DataBase, ���������� ~DataBase, ����� insertInDB, ���� �������� ��� � ��'���� Customer � ���� �����, � ����� clearDB, ���� ����� ������� ���� �����.   
    DataBase();
    ~DataBase();
    void insertInDB(Customer* customers, int number, int i);
    void clearDB();
};

#endif // �� ����� ���� ������� ��������� ������������ #ifndef �� #define, �� ������ ����� ��������� ����� database.h.