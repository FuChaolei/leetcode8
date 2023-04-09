#include <bits/stdc++.h>
using namespace std;
class AbstractApple
{
public:
    virtual void ShowName() = 0;
};
class ChinaApple : public AbstractApple
{
public:
    virtual void ShowName()
    {
        cout << "im chinaapple" << endl;
    }
};
class USAApple : public AbstractApple
{
public:
    virtual void ShowName()
    {
        cout << "im usaapple" << endl;
    }
};
class AbstractBanana
{
public:
    virtual void ShowName() = 0;
};
class ChinaBanana : public AbstractBanana
{
public:
    virtual void ShowName()
    {
        cout << "im chinabanana" << endl;
    }
};
class USABanana : public AbstractBanana
{
public:
    virtual void ShowName()
    {
        cout << "im usabanana" << endl;
    }
};
class AbstractFactory
{
public:
    virtual AbstractApple *CreateApple() = 0;
    virtual AbstractBanana *CreateBanana() = 0;
};
class ChinaFactory : public AbstractFactory
{
public:
    virtual AbstractApple *CreateApple()
    {
        return new ChinaApple;
    }
    virtual AbstractBanana *CreateBanana()
    {
        return new ChinaBanana;
    }
};
class USAFactory : public AbstractFactory
{
public:
    virtual AbstractApple *CreateApple()
    {
        return new USAApple;
    }
    virtual AbstractBanana *CreateBanana()
    {
        return new USABanana;
    }
};
int main()
{
    AbstractFactory *factory = new ChinaFactory;
    AbstractApple *apple = factory->CreateApple();
    apple->ShowName();
    delete apple;
    delete factory;
    apple = nullptr;
    factory = nullptr;
    return 0;
}
