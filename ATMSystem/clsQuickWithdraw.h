#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include"clsAtmSystem.h"
#include"clsInputValidate.h"
#include"Global.h"

class clsQuickWithdraw:protected clsScreen
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

    static short _ReadQuickWithdrawMenueOption()
    {
        cout << setw(37) << left << "" << "\n\nChoose what do you want to do? [1 to 9]? ";
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 9, "Enter Number between 1 to 9? ");
        return Choice;
    }

    static void _PerfromQuickWithdrawOption(short QuickWithDrawOption)
    {
        if (QuickWithDrawOption == 9)//exit 
            return;

        short WithDrawBalance = AtmSystem1.getQuickWithDrawAmount(QuickWithDrawOption);

        if (WithDrawBalance > AtmSystem1.AccountBalance)
        {
            cout << "\nThe amount exceeds your balance, make another choice.\n";
            cout << "Press Anykey to continue...";
            system("pause>0");
            ShowQuickWithdrawScreen();
            return;
        }
        AtmSystem1.Withdraw(WithDrawBalance);

        cout << "\n Done Succesfully" << endl;
        _PrintClien(AtmSystem1);

    }

public:
    
    static void ShowQuickWithdrawScreen()
    {
        system("cls");
        _DrawScreenHeader("\t\tQucik Withdraw Screen");

        system("cls");
        cout << "===========================================\n";
        cout << "\t\tQucik Withdraw\n";
        cout << "===========================================\n";
        cout << "\t[1] 20\t\t[2] 50\n";
        cout << "\t[3] 100\t\t[4] 200\n";
        cout << "\t[5] 400\t\t[6] 600\n";
        cout << "\t[7] 800\t\t[8] 1000\n";
        cout << "\t[9] Exit\n";
        cout << "===========================================\n";
        cout << "Your Balance is " << AtmSystem1.AccountBalance<<endl;

        _PerfromQuickWithdrawOption(_ReadQuickWithdrawMenueOption());
    }
};

