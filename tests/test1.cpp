#include <banking.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class Transaction_Interface {
public:
    virtual ~Transaction_Interface() = default;
    virtual bool can_exec() = 0;
    virtual void exec() {
        if (!can_exec())
            return;
        // code
    }
};

class Transaction_Mock : public Transaction_Interface {
public:
    Transaction_Mock(Account* from, Account* to, int sum) : Transaction_Interface(from, to, sum) {}
    ~Transaction_Mock() override  = default;
    MOCK_METHOD0(can_exec, bool());
    MOCK_METHOD0(exec, void());
};


TEST(Banking_tests, Transaction1) {
    int last_id = 0;
    Account a(last_id, 10);
    Account b(last_id, 50);
    Transaction t1(&a, &b, 10);
    t1.exec();
    EXPECT_EQ(a.get_money(), 0);
    EXPECT_EQ(b.get_money(), 60);
}

TEST(Banking_tests, Transaction2) {
    int last_id = 0;
    Account a(last_id, 10);
    Account b(last_id, 50);
    Transaction t1(&a, &b, 50);
    t1.exec();
    EXPECT_EQ(a.get_money(), 10);
    EXPECT_EQ(b.get_money(), 50);
}

TEST(Banking_tests, Mock) {
    int last_id = 0;
    Account a(last_id, 10);
    Account b(last_id, 50);
    Transaction_Mock t1(&a, &b, 10);
    EXPECT_CALL(t1, can_exec()).Times(1);
    t1.exec();
    EXPECT_CALL(t1, exec()).Times(1);    
}
