#include <iostream>
#include <queue>
#include <pthread.h>
using namespace std;
pthread_mutex_t mu;
queue<int> q;
void *func(void *arg)
{
    int n = *((int *)arg);
    pthread_mutex_lock(&mu);
    if (!q.empty())
    {
        int top = q.front();
        q.pop();
        cout << top << " " << n << endl;
    }
    pthread_mutex_unlock(&mu);
    return 0;
}
int main()
{
    pthread_mutex_init(&mu, 0);
    for (int i = 0; i < 5; i++)
    {
        q.emplace(i);
    }
    int a[5];
    pthread_t pids[5];
    for (int i = 0; i < 5; i++)
    {
        a[i] = i;
        pthread_create(&pids[i], 0, func, (void *)(&a[i]));
    }
    int res = 0;
    void *func_res;
    for (int i = 0; i < 5; i++)
    {
        res = pthread_join(pids[i], &func_res);
        if (res != 0)
        {
            cout << "cuowu: " << i << endl;
        }
    }
    pthread_mutex_destroy(&mu);
    return 0;
}
