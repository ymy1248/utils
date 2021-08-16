#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

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

int main() 
{
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
}