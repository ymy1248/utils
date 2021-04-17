#include <iostream>
#include <assert.h>

using namespace std;

// Greatest Common Divisor
int euclidean_gcd(int a, int b)
{
  if (a < b) {
    int reg = b;
    b = a;
    a = reg;
  }
  int res = a % b;
  if (res == 0) {
    return b;
  }
  return euclidean_gcd(b, res);
}

int binary_gcd(int a, int b)
{
  if (a == b) return a;
  if (a < b) return binary_gcd(b - a, a);
  else return binary_gcd(a - b, b);
}

int gcb(int a, int b)
{
  if (a == b) return a;
  if (a < b) return gcb(b, a);
  if (!(a & 0x1) && !(b & 0x1)) return gcb(a>>1, b>>1) << 1;
  if (!(a & 0x1)) return gcb(a>>1, b);
  if (!(b & 0x1)) return gcb(a, b>>1);
  return gcb(b, a - b);
}

int main()
{
  int a, b;
  cin >> a;
  cin >> b;
  cout << euclidean_gcd(a,b) << endl;
  cout << binary_gcd(a,b) << endl;
  cout << gcb(a,b) << endl;
  assert(euclidean_gcd(a,b) == binary_gcd(a,b));
  assert(euclidean_gcd(a,b) == gcb(a,b));
}
