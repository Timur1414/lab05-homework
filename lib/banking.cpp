#include "banking.h"

Account::Account() {
    id = -1;
    money = 0;
}

Account::Account(int& id) {
    this->id = id++;
    money = 0;
}

Account::Account(int& id, int money) {
    this->id = id++;
    this->money = money;
}

int Account::get_id() {
    return id;
}

int Account::get_money() {
    return money;
}

void Account::set_money(int money) {
    this->money = money;
}


Transaction::Transaction(Account* from, Account* to, int sum) {
    this->from = from;
    this->to = to;
    this->sum = sum;
}

bool Transaction::can_exec() {
    return from->get_money() >= sum;
}

void Transaction::exec() {
    if (!can_exec())
        return;
    from->set_money(from->get_money() - sum);
    to->set_money(to->get_money() + sum);
}