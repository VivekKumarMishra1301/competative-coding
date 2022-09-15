#include <iostream>
using namespace std;
void fun()
{
    cout << "hello" << endl;
    fun();
}
int main()
{
    fun();
}