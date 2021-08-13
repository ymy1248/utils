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
}