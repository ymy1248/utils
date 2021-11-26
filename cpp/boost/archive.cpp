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
    {
        std::ofstream file("archive.txt");
        text_oarchive oa(file);
        int i = 1;
        oa << i;
    }

    {
        int j = 100;
        std::ifstream ifile("archive.txt");
        text_iarchive ia(ifile);
        ia >> j;
        std::cout << j << std::endl;
    }

    {
        S s;
        s._s._i = 12345;
        std::ofstream ofile("s.txt");
        text_oarchive oa(ofile);
        oa << s;
    }

    {
        std::ifstream ifile("s.txt");
        text_iarchive ia(ifile);
        S s;
        ia >> s;
        std::cout << s._s._i << std::endl;
    }

    {
        S s;
        s._s._i = 12345;
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