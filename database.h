#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>//Ці рядки коду включають необхідні заголовочні файли для використання класу sqlite3 та класу Customer.
#include "customer.h"

class DataBase // Ця роздільна стрічка позначає початок оголошення класу DataBase. Він має приватне поле db, яке є вказівником на об'єкт sqlite3. Це поле буде використовуватись для збереження з'єднання з базою даних.
{
private:
    sqlite3* db;       

public: // Ці рядки коду оголошують публічні методи класу DataBase. Методи включають конструктор DataBase, деструктор ~DataBase, метод insertInDB, який вставляє дані з об'єкта Customer в базу даних, і метод clearDB, який очищає таблицю бази даних.   
    DataBase();
    ~DataBase();
    void insertInDB(Customer* customers, int number, int i);
    void clearDB();
};

#endif // Ця рядок коду завершує директиву препроцесора #ifndef та #define, що означає кінець включення файлу database.h.