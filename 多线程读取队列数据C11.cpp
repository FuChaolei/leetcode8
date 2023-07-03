#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <pthread.h>
using namespace std;
queue<int> q;
mutex mu;
void func(int n)
{
    mu.lock();
    if (!q.empty())
    {
        int top = q.front();
        q.pop();
        cout << top << " " << n << endl;
    }
    mu.unlock();
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        q.emplace(i);
    }
    for (int i = 0; i < 5; i++)
    {
        thread t(func, i);
        t.join();
    }
    return 0;
}
