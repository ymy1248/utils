#include <cmath>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <gtest/gtest.h>

#include "env.hpp"

using namespace boost::archive;

struct S1
{
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version) 
    {
        std::cout << "S1 serialize\n";
        ar & _i;
    }

    int _i;
};

struct S
{
    S() = default;
    S(S &&s) = delete;
    S(const S &s) = delete;
    void operator=(const S &s) = delete;
    S& operator=(S &&s) = delete;

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version) 
    {
        std::cout << "S serialize\n";
        ar & _s;
    }
    S1 _s;
};

struct PtrTest 
{
    PtrTest() : _data(10), _ptrs(10)
    {
        for (int i = 0; i < 10; ++i) {
            _data[i] = i;
            _ptrs[i] = &_data[i];
        }
    }

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version) 
    {
        ar & _data;
        ar & _ptrs;
    }
    std::vector<int> _data;
    std::vector<int*> _ptrs;
};

TEST(Archive, basic) {
    int i;
    {
        i = 1;
        std::ofstream file("archive.txt");
        text_oarchive oa(file);
        oa << i;
    }

    {
        int j = 100;
        std::ifstream ifile("archive.txt");
        text_iarchive ia(ifile);
        ia >> j;
        EXPECT_EQ(i, j);
    }

    S s;
    s._s._i = 12346;
    {
        std::ofstream ofile("s.txt");
        text_oarchive oa(ofile);
        oa << s;
    }

    {
        std::ifstream ifile("s.txt");
        text_iarchive ia(ifile);
        S si;
        ia >> si;
        EXPECT_EQ(si._s._i, s._s._i);
    }

    {
        S *sPtr1 = &s;
        S *sPtr2 = &s;
        std::ofstream ofile("sPtr.txt");
        text_oarchive oa(ofile);
        oa << sPtr1;
        oa << sPtr2;
        std::cout << "sPtr1: " << sPtr1 << std::endl;
        std::cout << "sPtr2: " << sPtr2 << std::endl;
    }

    {
        S *sPtr1, *sPtr2;
        std::ifstream ifile("sPtr.txt");
        text_iarchive ia(ifile);
        ia >> sPtr1;
        ia >> sPtr2;
        std::cout << "sPtr1: " << sPtr1 << std::endl;
        std::cout << "sPtr2: " << sPtr2 << std::endl;
        EXPECT_EQ(sPtr1->_s._i, s._s._i);
        EXPECT_EQ(sPtr2->_s._i, s._s._i);
        EXPECT_EQ(sPtr2, sPtr1);
    }

    // {
    //     PtrTest test;
    //     std::ofstream ofile("PtrTest.txt");
    //     text_oarchive oa(ofile);
    //     oa << test;
    // }

    // {
    //     PtrTest test;
    //     std::ifstream ifile("PtrTest.txt");
    //     text_iarchive ia(ifile);
    //     ia >> test;
    //     for (auto &p : test._ptrs) {
    //         std::cout << *p << std::endl;
    //     }
    // }
}