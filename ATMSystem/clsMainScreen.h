#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include<iomanip>
#include"clsQuickWithdraw.h"
#include"clsNormalWithdraw.h"
#include"clsDeposit.h"
#include"clsCheckBalance.h"
using namespace std;

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eQucikWithdraw = 1, eNormalWithDraw = 2, eDeposit = 3,
        eCheckBalance = 4, eExit = 5
    };


    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 5, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowQuickWithdrawScreen()
    {
         //cout << "\nClient List Screen Will be here...\n";
        clsQuickWithdraw::ShowQuickWithdrawScreen();
    }

    static void _ShowNormalWithdrawScreen()
    {
        // cout << "\nAdd New Client Screen Will be here...\n";
        clsNormalWithdraw::ShowNormalWithdrawScreen();
    }

    static void _ShowDepositScreen()
    {
       // cout << "\nDelete Client Screen Will be here...\n";
        clsDeposit::ShowDepositScreen();
    }

    static void _ShowCheckBalanceScreen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
        clsCheckBalance::ShowCheckBalanceScreen();
    }



    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eQucikWithdraw:
        {
            system("cls");
            _ShowQuickWithdrawScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eNormalWithDraw:
            system("cls");
            _ShowNormalWithdrawScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCheckBalance:
            system("cls");
            _ShowCheckBalanceScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tATM Main Menue Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Quick Withdraw.\n";
        cout << setw(37) << left << "" << "\t[2] Normal Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Deposit\n";
        cout << setw(37) << left << "" << "\t[4] Check Balance.\n";
        cout << setw(37) << left << "" << "\t[5] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }


};

