#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class num
{
public:
    num(int v) : value(v) {}
    int value = 0;
};
class num_hash
{
public:
    size_t operator()(const num &n) const
    {
        return hash<int>()(n.value);
    }
};
class num_equal
{
public:
    size_t operator()(const num &lhs, const num &rhs) const
    {
        return lhs.value == rhs.value;
    }
};

int main()
{
    unordered_set<num, num_hash, num_equal> s;
    num x[7] = {0, 1, 2, 5, 6, 9, 78};
    for (int i = 0; i < 7; i++)
    {
        s.insert(x[i]);
    }
    for (auto i = s.begin(); i != s.end(); i++)

    {
        cout << i->value << " ";
    }

    unordered_map<int, int> ump;

    cout << "\n";
    return 0;
}
