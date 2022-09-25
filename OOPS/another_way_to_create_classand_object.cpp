#include <iostream>
using namespace std;
class Student
{
public:
    int age;
    int roll;
};
int main()
{
    // Static creation object

    Student s1;
    Student s2, s3;
    s1.age = 24;
    s2.roll = 104;
    cout << s1.age << endl;
    cout << s2.roll << endl;

    // Dynamic creation

    Student *s4 = new Student;
    (*s4).age = 24;
    s4->roll = 24;
    cout << (*s4).age << endl;
    cout << s4->roll << endl;
}