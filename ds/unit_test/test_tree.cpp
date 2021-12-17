#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <gtest/gtest.h>
#include "tree.hpp"

using namespace ymy;

class TreeBasic : public ::testing::Test {
 protected:
    TreeBasic() 
    {
        BtNode<int> *n7 = new BtNode<int>(7);
        BtNode<int> *n6 = new BtNode<int>(6);
        BtNode<int> *n3 = new BtNode<int>(3, n7);
        BtNode<int> *n2 = new BtNode<int>(2, nullptr, n6);
        BtNode<int> *n1 = new BtNode<int>(1, n3);
        BtNode<int> *n0 = new BtNode<int>(0, n1, n2);
        _bt.setRoot(n0);
    }
    void SetUp() override 
    {
    }

    void TearDown() override
    {
    }

    BT<int> _bt;
};

TEST_F(TreeBasic, serialization)
{
}
