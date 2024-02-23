#pragma once


class Account {
private:
    int id;
    int money;
public:
    Account();
    Account(int&);
    Account(int&, int);

    int get_id();
    int get_money();
    void set_money(int);
};


class Transaction {
private:
    Account* from;
    Account* to;
    int sum;
public:
    Transaction(Account*, Account*, int);
    bool can_exec();
    void exec();
};
