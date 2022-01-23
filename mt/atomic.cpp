#include <gtest/gtest.h>
#include <atomic>
#include <thread>

using namespace std;

const uint REPEAT = 2E4;

class X {
 public:
    int i;
};

std::atomic<X*> p;
int A = 0, B = 0, r1 = 0, r2 = 0;

void release()
{
    A = B + 1;
    B = 1;
    X *x = new X();
    x->i = 42;
    p.store(x, std::memory_order_release);
}

void acquire()
{
    X *x = nullptr;
    while (!p.load(std::memory_order_acquire)) {
    }
    x = p;
    r1 = A;
    r2 = x->i;
}

TEST(atomic, release_acquire)
{
    for (uint i = 0; i < REPEAT; ++i) {
        A = 0;
        B = 0;
        r1 = 0;
        r2 = 0;
        p = nullptr;
        thread t1(release);
        thread t2(acquire);
        t1.join();
        t2.join();
        EXPECT_EQ(r1, 1);
        EXPECT_EQ(r2, 42);
    }
}

atomic<bool> x, y;
atomic<int> z;

void write_x()
{
    x.store(true, std::memory_order_seq_cst);
}

void write_y()
{
    y.store(true, std::memory_order_seq_cst);
}

void read_x_then_y()
{
    while (!x.load(std::memory_order_seq_cst)){};
    if (y.load(memory_order_seq_cst))
        ++z;
}

void read_y_then_x()
{
    while (!y.load(std::memory_order_seq_cst)){};
    if (x.load(std::memory_order_seq_cst))
        ++z;
}

TEST(atomic, sc)
{
    for (int i = 0; i < REPEAT; ++i) {
        x = false;
        y = false;
        z = 0;
        thread a(write_x);
        thread b(write_y);
        thread c(read_x_then_y);
        thread d(read_y_then_x);
        a.join();
        b.join();
        c.join();
        d.join();
        EXPECT_NE(z, 0);
    }
}


void write_x_r() 
{
    x.store(true, std::memory_order_release);
}

void write_y_r()
{
    y.store(true, std::memory_order_release);
}

void read_x_then_y_a()
{
    while (!x.load(std::memory_order_acquire)){};
    if (y.load(std::memory_order_acquire))
        ++z;
}

void read_y_then_x_a()
{
    while (!y.load(std::memory_order_acquire)){};
    if (x.load(std::memory_order_acquire))
        ++z;
}

TEST(atomic, ar)
{
    for(int i = 0; i < REPEAT; ++i) {
        x = false;
        y = false;
        z = 0;
        thread a(write_x_r);
        thread b(write_y_r);
        thread c(read_x_then_y_a);
        thread d(read_y_then_x_a);
        a.join();
        b.join();
        c.join();
        d.join();
        EXPECT_EQ(x, true);
        EXPECT_EQ(y, true);
        // EXPECT_NE(z, 0);
    }
}

void write_x_then_y()
{
    x.store(true, std::memory_order_relaxed);
    y.store(true, std::memory_order_relaxed);
}

void read_y_then_x_relaxed()
{
    while (!y.load(std::memory_order_relaxed)){};
    if (x.load(std::memory_order_relaxed))
        ++z;
}

TEST(atomic, relaxed)
{
    for (int i = 0; i <REPEAT; ++i) {
        x = false;
        y = false;
        z = 0;
        thread a(write_x_then_y);
        thread b(read_y_then_x_relaxed);
        a.join();
        b.join();
        // EXPECT_EQ(z, 0);
    }
}