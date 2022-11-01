#include <queue>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << "\n";

    return 0;
}
