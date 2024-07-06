#pragma once
#include <iostream>
#include"clsPerson.h"
#include<vector>
#include<string>
#include"clsString.h"
#include<fstream>


using namespace std;

class clsAtmSystem :public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 };

    enMode  _Mode;

    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;
    bool _MarkForDelete = false;

    static clsAtmSystem _ConvertLinetoRecordOpject(string Line, string Seperator = "#//#")
    {
        vector<string> vAtmClient;

        vAtmClient = clsString::Split(Line, Seperator);

        return clsAtmSystem(enMode::UpdateMode, vAtmClient[0], vAtmClient[1], vAtmClient[2], vAtmClient[3], stod(vAtmClient[4]));

    }

    static string ConvertRecordOpjectToLine(clsAtmSystem AtmClient, string Seperator = "#//#")
    {

        string stClientRecord = "";

        stClientRecord += AtmClient.AccountNumber() + Seperator;
        stClientRecord += AtmClient.PinCode + Seperator;
        stClientRecord += AtmClient.Name + Seperator;
        stClientRecord += AtmClient.Phone + Seperator;
        stClientRecord += to_string(AtmClient.AccountBalance);

        return stClientRecord;

    }

    vector <clsAtmSystem> _LoadCleintsOpjectDataFromFile()
    {

        vector <clsAtmSystem> vAtmClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsAtmSystem AtmClient = _ConvertLinetoRecordOpject(Line);

                vAtmClients.push_back(AtmClient);
            }

            MyFile.close();

        }

        return vAtmClients;

    }

    vector <clsAtmSystem> _SaveCleintsOpjectDataToFile(vector <clsAtmSystem> vAtmClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsAtmSystem C : vAtmClients)
            {


                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordOpjectToLine(C);
                MyFile << DataLine << endl;


            }

            MyFile.close();

        }

        return vAtmClients;

    }

    static clsAtmSystem _GetEmptyOpject()

    {
        return clsAtmSystem(enMode::EmptyMode, "", "", "", "", 0);
    }


public:

    clsAtmSystem(enMode Mode, string AccountNumber, string PinCode, string Name, string Phone, double AccountBalance)
         : clsPerson(Name, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    //Property Get
    string AccountNumber()
    {
        return _AccountNumber;
    }

    //Property Set
    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    //Property Get
    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
    //Property Set
    void SetAccountBalance(double AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    //Property Get
    double GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

    static clsAtmSystem FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsAtmSystem Client = _ConvertLinetoRecordOpject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyOpject();
    }

    static bool IsClientExist(string AccountNumber, string PinCode)
    {

        clsAtmSystem Client1 = clsAtmSystem::FindClientByAccountNumberAndPinCode(AccountNumber, PinCode);
        return (!Client1.IsEmpty());
    }

    short getQuickWithDrawAmount(short QuickWithDrawOption)
    {
        switch (QuickWithDrawOption)
        {
        case 1:
            return  20;
        case 2:
            return 50;
        case 3:
            return 100;
        case 4:
            return 200;
        case 5:
            return 400;
        case 6:
            return 600;
        case 7:
            return 800;
        case 8:
            return 1000;
        default:
            return 0;

        }

    }

    void Withdraw(double Amount)
    {
        _AccountBalance -= Amount;
        
        vector <clsAtmSystem> vAtmClients = _LoadCleintsOpjectDataFromFile();
        for (clsAtmSystem &C : vAtmClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }
        _SaveCleintsOpjectDataToFile(vAtmClients);

    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;

        vector <clsAtmSystem> vAtmClients = _LoadCleintsOpjectDataFromFile();
        for (clsAtmSystem& C : vAtmClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }
        _SaveCleintsOpjectDataToFile(vAtmClients);

    }
};

