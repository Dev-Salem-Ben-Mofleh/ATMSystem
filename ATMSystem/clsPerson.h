#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsPerson
{

private:

    string _Name;
    string _Phone;

public:


    clsPerson(string Name, string Phone)
    {

        _Name = Name;
        _Phone = Phone;
    }


    //Property Set
    void SetName(string Name)
    {
        _Name = Name;
    }

    //Property Get
    string GetName()
    {
        return _Name;
    }
    __declspec(property(get = GetName, put = SetName)) string Name;

    //Property Set
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    //Property Get
    string GetPhone()
    {
        return _Phone;
    }
    __declspec(property(get = GetPhone, put = SetPhone)) string Phone;



};

