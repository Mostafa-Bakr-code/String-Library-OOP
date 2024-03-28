
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cctype>
#include "clsString.h";
#include "clsDate.h";
#include "clsPeriod.h";
#include "clsUtil.h";
#include "clsPeriod.h";
#include "clsInputValidate.h";


using namespace std;


int main() {
	

    //__________________________________________________
    //Testing clsPeriod.h

    clsPeriod Period1(clsDate(1, 1, 2022), clsDate(10, 1, 2022));
    Period1.Print();

    clsPeriod Period2(clsDate(1, 1, 2022), clsDate(5, 1, 2022));
    Period2.Print();

    cout << "\n";

    cout << clsPeriod::overlapCountBetween2Periods(Period1, Period2) << endl;
    cout << "_____________________________________________";

    //___________________________________________________
    
    //Testing clsUtil.h

    clsUtil::Srand();
    cout << clsUtil::randomNumber(1, 10) << endl;
    cout << clsUtil::GetRandomCharacter(clsUtil::CapitalLetter) << endl;
    cout << clsUtil::GenerateWord(clsUtil::MixChars, 8) << endl;
    cout << clsUtil::GenerateKey(clsUtil::MixChars) << endl;
    clsUtil::GenerateKeys(10, clsUtil::MixChars);

    cout << "\n";

    //Swap Int
    int x = 10, y = 20;
    cout << x << " " << y << endl;
    clsUtil::Swap(x, y);
    cout << x << " " << y << endl << endl;

    //Swap double
    double a = 10.5, b = 20.5;
    cout << a << " " << b << endl;
    clsUtil::Swap(a, b);
    cout << a << " " << b << endl << endl;

    //Swap String
    string s1 = "Ali", s2 = "Ahmed";
    cout << s1 << " " << s2 << endl;
    clsUtil::Swap(s1, s2);
    cout << s1 << " " << s2 << endl << endl;

    //Swap Dates
    clsDate d1(1, 10, 2022), d2(1, 1, 2022);
    cout << d1.dateToString() << " " << d2.dateToString() << endl;
    clsUtil::Swap(d1, d2);
    cout << d1.dateToString() << " " << d2.dateToString() << endl;

    //Shuffl Array

    //int array
    int Arr1[5] = { 1,2,3,4,5 };
    clsUtil::ShuffleArray(Arr1, 5);
    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr1[i] << endl;
    }

    //string array
    string Arr2[5] = { "Ali","Fadi","Ahmed","Qasem","Khalid" };
    clsUtil::ShuffleArray(Arr2, 5);
    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr2[i] << endl;
    }

    int Arr3[5];
    clsUtil::FillArrayWithRandomNumbers(Arr3, 5, 20, 50);
    cout << "\nArray after fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr3[i] << endl;
    }


    string Arr4[5];
    clsUtil::FillArrayWithRandomWords(Arr4, 5, clsUtil::MixChars, 8);
    cout << "\nArray after fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr4[i] << endl;
    }


    string Arr5[5];
    clsUtil::FillArrayWithRandomKeys(Arr5, 5, clsUtil::MixChars);
    cout << "\nArray after filling keys:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr5[i] << endl;
    }

    cout << "\nText1 " << clsUtil::Tabs(5) << "Text2\n";

    const short EncryptionKey = 2; //this is the key.

    string TextAfterEncryption, TextAfterDecryption;
    string Text = "Mustafa Bakr";
    TextAfterEncryption = clsUtil::EncryptText(Text, EncryptionKey);
    TextAfterDecryption = clsUtil::DecryptText(TextAfterEncryption, EncryptionKey);

    cout << "\nText Before Encryption : ";
    cout << Text << endl;
    cout << "Text After Encryption  : ";
    cout << TextAfterEncryption << endl;
    cout << "Text After Decryption  : ";
    cout << TextAfterDecryption << endl;

    //_______________________________________________________________________
    // Testing clsValidate.h 
    cout << "_________________________________________________\n\n";

    cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(),
        clsDate(8, 12, 2022),
        clsDate(31, 12, 2022)) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(),
        clsDate(31, 12, 2022),
        clsDate(8, 12, 2022)) << endl;

    cout << "\nPlease Enter a Number:\n";
    int x1 = clsInputValidate::ReadIntNumber("Invalid Number, Enter again:\n");
    cout << "x1=" << x1;

    cout << "\nPlease Enter a Number between 1 and 5:\n";
    int y1 = clsInputValidate::ReadIntNumberBetween(1, 5, "Number is not within range, enter again:\n");
    cout << "y1=" << y1;

    cout << "\nPlease Enter a Double Number:\n";
    double a1 = clsInputValidate::ReadDblNumber("Invalid Number, Enter again:\n");
    cout << "a1=" << a1;

    cout << "\nPlease Enter a Double Number between 1 and 5:\n";
    double b1 = clsInputValidate::ReadDblNumberBetween(1, 5, "Number is not within range, enter again:\n");
    cout << "b1=" << b1;

    cout << endl << clsInputValidate::isValideDate(clsDate(31, 12, 2022)) << endl;

    system("pause>0");
	return 0;
}