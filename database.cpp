#include <iostream> // Ці рядки включають необхідні заголовочні файли, які будуть використовуватися в цьому файлі. 
#include "sqlite3.h" // <iostream> включає стандартні потоки введення/виведення, "sqlite3.h" містить оголошення для роботи з базою даних SQLite, "customer.h" включає оголошення класу Customer, а "database.h" включає оголошення класу DataBase.
#include "customer.h"
#include "database.h"

DataBase::DataBase() // Цей код є конструктором класу DataBase. Він відкриває з'єднання з базою даних SQLite, яка знаходиться в файлі db.db. 
///Потім виконується SQL-запит для видалення всіх записів з таблиці Customers.
{
    int rc = sqlite3_open("db.db", &db);
    char* errMsg;
    const std::string query = "DELETE FROM Customers";
    rc = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
}

DataBase::~DataBase() // Цей код є деструктором класу DataBase. Він закриває з'єднання з базою даних SQLite, що було відкрите в конструкторі.
{
    sqlite3_close(db);
}

void DataBase::insertInDB(Customer* customers, int number, int i) // Цей метод insertInDB виконує SQL-запит для вставки нового запису в таблицю Customers бази даних. 
// Запит формується з даних об'єкта Customer, отриманих через переданий вказівник customers, із значенням number (кількість записів) і i (індекс поточного запису). Запит виконується за допомогою функції sqlite3_exec.
{
    char* errMsg;
    const std::string query = "INSERT INTO Customers (ID, FirstName, LastName, CreditCardNumber, BankAccountNumber) "
        "VALUES (" + std::to_string(customers[i].getID()) + ", '" + customers[i].getFirstName() +
        "', '" + customers[i].getLastName() + "', " + std::to_string(customers[i].getCreditCardNumber()) +
        ", " + std::to_string(customers[i].getBankAccoutNumber()) + ");";
    sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
}

void DataBase::clearDB() // Цей метод clearDB виконує SQL-запит для видалення всіх записів з таблиці Customers бази даних. Запит виконується за допомогою функції sqlite3_exec.
{
    char* errMsg;
    const std::string query = "DELETE FROM Customers";
    sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
}
