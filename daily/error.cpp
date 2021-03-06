#include <iostream>
#include <exception>

using namespace std;

struct myexception : public exception
{
    const char *what() const throw()
    {
        return "C++ exception";
    }
};

int main()
{
    try
    {
        // throw exception();
        throw myexception();
        // throw exception();
    }
    catch(myexception &e)
    {
        cout << e.what() << endl;
    }
    catch(exception &e)
    {
        cout << "其他错误" << endl;
    }

    return 0;
}
