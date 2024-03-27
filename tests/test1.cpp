#include <banking.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class Acc_Interface {
public:
    virtual ~Acc_Interface() = default;
    virtual void set_money(int) = 0;
};

class Acc : public Acc_Interface {
public:
    void set_money(int money) {
	// code
    }
};

class Acc_Mock : public Acc_Interface {
public:
    ~Acc_Mock() override  = default;
    MOCK_METHOD1(set_money, void(int));
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
    Acc_Mock a;
    Acc_Mock b;
    
    EXPECT_CALL(a, set_money(50)).Times(1);
    a.set_money(50);
}
