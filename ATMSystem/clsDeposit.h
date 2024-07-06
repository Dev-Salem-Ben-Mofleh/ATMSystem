#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include"clsAtmSystem.h"
#include"clsInputValidate.h"
#include"Global.h"

class clsDeposit :protected clsScreen
{

private:
    static void _PrintClien(clsAtmSystem AtmClient)
    {

        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nAcc. Number : " << AtmClient.AccountNumber();
        cout << "\nFull Name   : " << AtmClient.Name;
        cout << "\nPassword    : " << AtmClient.PinCode;
        cout << "\nPhone       : " << AtmClient.Phone;
        cout << "\nBalance     : " << AtmClient.AccountBalance;
        cout << "\n___________________\n";

    }

    static double _ReadDepositAmount()
    {
        double Amount;
        cout << "\nEnter a positive Deposit Amount? ";

        cin >> Amount;
        while (Amount <= 0)
        {
            cout << "\nEnter a positive Deposit Amount? ";
            cin >> Amount;
        }
        return Amount;
    }

    static void _PerfromDepositOption()
    {

        double DepositAmount = _ReadDepositAmount();

        AtmSystem1.Deposit(DepositAmount);

        _PrintClien(AtmSystem1);
        cout << "\n Done Succesfully" << endl;


    }

public:

    static void ShowDepositScreen()
    {
        system("cls");
        _DrawScreenHeader("\tDeposit Screen");
        _PrintClien(AtmSystem1);
         _PerfromDepositOption();

    }


};

