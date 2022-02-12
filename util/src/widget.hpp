#include <iostream>
#include <atomic>

class Widget {
 public:
    Widget() {
        std::cout << "Base CTOR\n";
        ++_ctor;
    }

    explicit Widget(int num) : _num(num) {
        std::cout << "Base " << _num << " CTOR\n";
        ++_ctor;
    };

    Widget(const Widget &b) {
        _num = b._num;
        std::cout << "Base " << _num << " Copy CTOR\n";
        ++_ctor;
    }
    Widget(const Widget &&b) {
        _num = b._num;
        std::cout << "Base " << _num << " Move CTOR\n";
        ++_ctor;
    }

    Widget& operator=(const Widget &b) {
        _num = b._num;
        std::cout << "Base " << _num << " Copy Assignment\n";
        return *this;
    }

    Widget& operator=(const Widget &&b) {
        _num = b._num;
        std::cout << "Base " << _num << " Move Assignment\n";
        return *this;
    }
    ~Widget() {
        ++_dtor;
        std::cout << "Base " << _num << " DTOR\n";
    }

    bool operator<(const Widget &other) const
    {
        return _num < other._num;
    }


    void echo() const;

    int _num;

    static void initRefCount();
    static std::atomic<uint32_t>  _ctor;
    static std::atomic<uint32_t> _dtor;
};