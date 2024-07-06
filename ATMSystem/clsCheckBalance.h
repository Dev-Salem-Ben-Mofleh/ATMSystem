#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include"clsAtmSystem.h"
#include"clsInputValidate.h"
#include"Global.h"

class clsCheckBalance:protected clsScreen
{

public:

    static void ShowCheckBalanceScreen()
    {
        system("cls");
        _DrawScreenHeader("\Check Balance Screen");

        cout << "\nYour Balance is: " << AtmSystem1.AccountBalance << "\n";
    }

};

