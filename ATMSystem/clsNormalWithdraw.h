#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include"clsAtmSystem.h"
#include"clsInputValidate.h"
#include"Global.h"

class clsNormalWithdraw :protected clsScreen
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

    static int _ReadWithDrawAmont()
    {
        int Amount;
        cout << "\nEnter an amount multiple of 5's ? ";

        cin >> Amount;

        while (Amount % 5 != 0)
        {
            cout << "\nEnter an amount multiple of 5's ? ";
            cin >> Amount;
        }
        return Amount;
    }

    static void _PerfromNormalWithdrawOption()
    {

        int WithDrawBalance = _ReadWithDrawAmont();

        if (WithDrawBalance > AtmSystem1.AccountBalance)
        {
            cout << "\nThe amount exceeds your balance, make another choice.\n";
            cout << "Press Anykey to continue...";
            system("pause>0");
            ShowNormalWithdrawScreen();
            return;
        }
        AtmSystem1.Withdraw(WithDrawBalance);

        cout << "\n Done Succesfully" << endl;
        _PrintClien(AtmSystem1);

    }

public:

    static void ShowNormalWithdrawScreen()
    {
        system("cls");
        _DrawScreenHeader("\tNormal Withdraw Screen");

        _PrintClien(AtmSystem1);

        _PerfromNormalWithdrawOption();
    }
};

