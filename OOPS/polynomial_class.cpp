
#include <iostream>
using namespace std;
class Polynomial
{
public:
    int *degCoeff; // Name of your array (Don't change this)

    // Complete the class
    int capacity;

public:
    // Default Constructor
    Polynomial()
    {
        degCoeff = new int[5];
        capacity = 5;
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = 0;
        }
    }

    // Copy constructor
    Polynomial(Polynomial const &d)
    {
        this->degCoeff = new int[d.capacity];
        for (int i = 0; i < d.capacity; i++)
        {
            this->degCoeff[i] = d.degCoeff[i];
        }
        this->capacity = d.capacity;
    }

    // Copy assignment operator
    void operator=(Polynomial const &d)
    {
        this->degCoeff = new int[d.capacity];
        for (int i = 0; i < d.capacity; i++)
        {
            this->degCoeff[i] = d.degCoeff[i];
        }
        this->capacity = d.capacity;
    }

    // print
    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i] != 0)
            {

                cout << degCoeff[i] << "x" << i << " ";
            }
        }
    }

    // setCoefficient
    void setCoefficient(int x, int y)
    {

        while (x >= capacity)
        {

            int *newData = new int[2 * capacity];
            for (int i = 0; i < 2 * capacity; i++)
            {
                newData[i] = 0;
            }
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = degCoeff[i];
            }
            delete[] degCoeff;
            degCoeff = newData;
            capacity *= 2;
        }

        degCoeff[x] = y;
    }

    // +
    Polynomial operator+(Polynomial const &p2)
    {

        Polynomial pNew;
        int i;
        for (i = 0; i < this->capacity && i < p2.capacity; i++)
        {

            pNew.setCoefficient(i, this->degCoeff[i] + p2.degCoeff[i]);
        }

        int j = i, k = i;
        for (; j < this->capacity; j++)
        {

            pNew.setCoefficient(j, this->degCoeff[j]);
        }

        for (; k < p2.capacity; k++)
        {

            pNew.setCoefficient(k, p2.degCoeff[k]);
        }
        return pNew;
    }

    Polynomial operator-(Polynomial const &p2)
    {

        Polynomial pNew;
        int i;
        for (i = 0; i < this->capacity && i < p2.capacity; i++)
        {

            pNew.setCoefficient(i, this->degCoeff[i] - p2.degCoeff[i]);
        }

        int j = i, k = i;
        for (; j < this->capacity; j++)
        {

            pNew.setCoefficient(j, this->degCoeff[j]);
        }

        for (; k < p2.capacity; k++)
        {

            pNew.setCoefficient(k, (-1) * p2.degCoeff[k]);
        }
        return pNew;
    }

    Polynomial operator*(Polynomial const &p2)
    {

        Polynomial pNew;

        for (int i = 0; i < this->capacity; i++)
        {

            for (int j = 0; j < p2.capacity; j++)
            {

                // if(this -> degCoeff[i] != 0 && p2.degCoeff[j] != 0){

                int coeff1 = this->degCoeff[i] * p2.degCoeff[j];
                if (pNew.capacity > i + j)
                {
                    coeff1 += pNew.degCoeff[i + j];
                }

                pNew.setCoefficient(i + j, coeff1);
                //}
            }
        }
        return pNew;
    }
};
int main()
{
    int count1, count2, choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for (int i = 0; i < count1; i++)
    {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++)
    {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++)
    {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for (int i = 0; i < count2; i++)
    {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++)
    {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++)
    {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch (choice)
    {
        // Add
    case 1:
        result = first + second;
        result.print();
        break;
        // Subtract
    case 2:
        result = first - second;
        result.print();
        break;
        // Multiply
    case 3:
        result = first * second;
        result.print();
        break;

    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }

    return 0;
}
