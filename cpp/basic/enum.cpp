#include <env.hpp>

using namespace std;

enum class SelectOpts : uint32_t {
    FLAT_IN = 0x001,
    FLAT_OUT = 0x002,
    FLAT_BID = 0x003,

    HIER_IN,
    HIER_OUT,
    HIER_BID,

    INT_HIER_FLAT,
    INT_HIER_NET,
};

enum class FlatSelectOpts : uint32_t {
    FLAT_IN = (uint32_t)SelectOpts::FLAT_IN,
    FLAT_OUT = (uint32_t)SelectOpts::FLAT_OUT,
    FLAT_BID = (uint32_t)SelectOpts::FLAT_BID,
};


int func(SelectOpts opts)
{
    cout << (uint32_t)opts << endl;
    return 1;
}

int flatFunc(FlatSelectOpts opts)
{
    return func(static_cast<SelectOpts>(opts));
}

template<typename Enum>
Enum operator|(const Enum &lhs, const Enum &rhs)
{
    return static_cast<Enum>(static_cast<typename underlying_type<Enum>::type>(lhs) | 
                            static_cast<typename underlying_type<Enum>::type>(rhs));
}

template<typename Enum>
bool operator&(const Enum &lhs, const Enum &rhs)
{
    return static_cast<bool>(static_cast<typename underlying_type<Enum>::type>(lhs) &
                             static_cast<typename underlying_type<Enum>::type>(rhs));
}
// FlatSelectOpts operator|(FlatSelectOpts& lhs, FlatSelectOpts& rhs)
// {
//     return (FlatSelectOpts)((uint32_t)lhs | (uint32_t)rhs);
// }
// 
// bool operator&(FlatSelectOpts& lhs, FlatSelectOpts& rhs)
// {
//     return static_cast<bool>((uint32_t)lhs & (uint32_t)rhs);
// }


int main() {
    FlatSelectOpts o1 = FlatSelectOpts::FLAT_OUT;
    FlatSelectOpts o2 = FlatSelectOpts::FLAT_IN;
    flatFunc(o1 | o2);
    flatFunc(FlatSelectOpts::FLAT_IN | FlatSelectOpts::FLAT_BID);

    // if (o1 & o2) {
    //     cout << "true" << endl;
    // } else {
    //     cout << "false" << endl;
    // }

    cout << is_same<uint32_t, underlying_type<FlatSelectOpts>::type>::value << endl;
    cout << is_convertible<uint32_t, uint32_t>::value << endl;
}