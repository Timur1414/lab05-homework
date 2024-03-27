#include <banking.h>
#include <iostream>


int main() {
    int last_id = 0;
    Account a(last_id, 10);
    Account b(last_id, 50);
    std::cout << "Money before transaction:\n";
    std::cout << "A: " << a.get_money() << "    B: " << b.get_money() << std::endl;

    Transaction t1(&a, &b, 10);
    t1.exec();

    std::cout << "Money after transaction:\n";
    std::cout << "A: " << a.get_money() << "    B: " << b.get_money() << std::endl;

    return 0;
}
