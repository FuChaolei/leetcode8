#include <bits/stdc++.h>
using namespace std;
class Lazy
{
public:
    static Lazy *get_Instance()
    {
        if (!l_)
        {
            l_ = new Lazy;
            cout << "success" << endl;
            return new Lazy;
        }
        return l_;
    }

private:
    Lazy() {}
    static Lazy *l_;
};
Lazy *Lazy::l_ = nullptr;
int main()
{
    Lazy *tmp = Lazy::get_Instance();
    delete tmp;
    tmp = nullptr;
    return 0;
}
