#ifndef CUSTOMER_H /// Ці директиви препроцесора (#ifndef, #define) використовуються для уникнення подвійного включення файлу. 
#define CUSTOMER_H /// Вони перевіряють, чи не було вже попередньо включення файлу customer.h. 
                   /// Якщо такого включення не було, то виконується наступний код. 
                   ///Це захищає від повторного включення файлу, що може призвести до проблем з множинним визначенням.

#include <iostream> ///Цей рядок включає заголовочний файл <iostream>, який містить оголошення потокових класів std::ostream і std::istream, а також стандартні об'єкти std::cin, std::cout і std::cerr.

class Customer /// Цей рядок починає оголошення класу Customer і визначає його приватні та публічні члени.
{
private:
    int ID, creditCardNumber, bankAccountNumber;
    std::string lastName, firstName;
public:
    Customer(); /// Ці рядки оголошують конструктор за замовчуванням, конструктор з параметрами та деструктор класу Customer.
    Customer(int ID, std::string firstName, std::string lastName, int creditCardNumber, int bankAccountNumber);
    ~Customer();

    void setID(int newID); /// Ці рядки оголошують публічні методи-сеттери, які встановлюють значення приватних полів класу Customer.
    void setFirstName(std::string newFirstName);
    void setLastName(std::string newLastName);
    void setCreditCardNumber(int newCreditCardNumber);
    void setBankAccoutNumber(int newBankAccoutNumber);

    int getID(); /// Ці рядки оголошують публічні методи-геттери, які повертають значення приватних полів класу Customer.
    std::string getFirstName();
    std::string getLastName();
    int getCreditCardNumber();
    int getBankAccoutNumber();

    std::string toString() const; /// Цей рядок оголошує публічний метод toString(), який повертає рядкове представлення об'єкта класу Customer.

    friend std::ostream& operator<<(std::ostream& os, const Customer& customer); ///Цей рядок оголошує декларацію функції-дружньої operator<<, яка перевантажує оператор виводу << для об'єкта класу Customer. 
    /// Функція отримує посилання на потік os типу std::ostream та константне посилання на об'єкт класу Customer.
};

void sortByLastName(Customer* customers, int numCustomers);
void filterByCreditCardRange(Customer* customers, int numCustomers, int minRange, int maxRange);/// Ці рядки оголошують прототипи функцій sortByLastName та filterByCreditCardRange. 
/// Функції не повертають значення (void) і отримують вказівник на масив об'єктів Customer, кількість об'єктів numCustomers та, у випадку функції filterByCreditCardRange, мінімальне та максимальне значення для фільтрації.

#endif