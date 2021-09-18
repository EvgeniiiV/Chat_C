#include<iostream>
using namespace std;
#include<string>
#include <streambuf>
#include "Chat_C.h"
#include <vector>


template <typename T> bool compare_LP(T LP, T L, T P)//compares login and password
{
    return LP == L + P;
}

template <typename T1, typename T2> T2 request(T1 rst, T2 a, T2 b, T2 first)
{
    T2 choice = 0;
    if (!first)
    {
        cout << "REGISTRATION of next USER: press key 1" << endl;//for registrarion
        do//to prevent invalid input
        {
            cin.clear();
            streamsize L = cin.rdbuf()->in_avail();
            cin.ignore(L);
            cin >> choice;
            if (!cin)
                cout << "ENTER a DIGIT" << endl;
            if (choice != a)
                cout << "ENTER " << a << endl;
        } while ((choice != a) || !cin);
    }
    if (first)
    {
        do//to prevent invalid input during 
        {
            cout << rst << endl;
            cin.clear();
            streamsize L = cin.rdbuf()->in_avail();
            cin.ignore(L);
            cin >> choice;
            if (!cin)
                cout << "ENTER a DIGIT" << endl;
            if (choice != a && choice != b)
                cout << "ENTER " << a << " or " << b << endl;
        } while ((choice != a && choice != b) || !cin);
    }
    return choice;
}

template <typename T> T next_request()//case 5, 6
{
    size_t choice = 0;
    do
    {
        cout << "\nLogout and Registration: press key 1" << endl;
        cout << "Logout and Authorization: press key 2" << endl;
        cout << "Create new contact: press key 3" << endl;
        cout << "Chose another contact: press key 4" << endl;
        cout << "Next message to this contact: press key  5" << endl;
        cout << "Message for everyone: press key 6" << endl;
        cout << "Quit: press key 7" << endl;
        cin.clear();
        streamsize L = cin.rdbuf()->in_avail();
        cin.ignore(L);
        cin >> choice;
        if (!cin)
            cout << "ENTER a DIGIT" << endl;
        if (choice < 1 || choice > 7)
            cout << "ENTER 1 - 7" << endl;
    } while (choice < 1 || choice > 7 || !cin);
    return choice;
}

size_t Factorial(size_t num)
{
    size_t p = 0;
    size_t f = 1;
    for (size_t i = 1; i <= num; i++)
        f *= i;
    return (num != 0) ? f : 1;
}

size_t Presence(size_t num)
{
    if (num <= 2) return 1;
    num--;
    size_t p = 0;
    size_t d = num;
    do
    {
        p += Factorial(num) / (Factorial(num - d) * Factorial(d));
        d--;
    } while (d >= 2);
    p += num;

    return p;
}