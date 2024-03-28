#pragma once
#include <iostream>
#include <vector>
#include <cctype>
#include <ctime>
#include "clsString.h";
#include <string>
#include "clsDate.h"

using namespace std;



class clsUtil
{

public:

    enum enCharType {
        SmallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void  Srand()
    {
        srand((unsigned)time(NULL));
    }

    static int randomNumber(int From, int To) {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

	static char GetRandomCharacter(enCharType Type) {

        // Mix is Capital/Samll/Digits only
        if (Type == enCharType::MixChars) {

            Type = (enCharType)randomNumber(1, 3);
        }

		switch (Type) {

		case enCharType::CapitalLetter: return char(randomNumber(65, 90));

		case enCharType::SmallLetter: return char(randomNumber(97, 122));

		case enCharType::Digit: return char(randomNumber(48, 57));

		case enCharType::SpecialCharacter: return char(randomNumber(33, 47));

        defualt:
        {
            return char(randomNumber(65, 90));
            break;
        }

		}
	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}

	static string GenerateKey(enCharType CharType = enCharType::CapitalLetter)
	{
		string Key = "";
		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord (CharType, 4) + "-";
		Key = Key + GenerateWord (CharType, 4) + "-";
		Key = Key + GenerateWord (CharType, 4);
		return Key;
	}

	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : " << GenerateKey(CharType) << endl;
		}
	}

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = randomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::swapDates(A, B);

    }

    static  void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
        }

    }

    static  void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
        }

    }

    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static string  EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }


};

