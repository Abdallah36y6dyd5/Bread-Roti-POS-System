#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct stDate{
    short Year = 0;
    short Month = 0;
    short Day = 0;
};
struct stAmountsSale{
    float Bread = 0;
    short Roti = 0;
    short RotiParis = 0;
    short RotiBor = 0;
    short LargCake = 0;
    short SmallCake = 0;
    short LargTamriah = 0;
    short Ceroasah = 0;
    short Pan = 0;
    short Tamriah_20 = 0;
    short Kodam = 0;
    short Profit = 0;
    stDate Date;
};

string ConvertDateRecordToLine(stDate Date, string Seperator = "/")
{

    string stDateRecord = "";
    stDateRecord += to_string(Date.Year) + Seperator;
    stDateRecord += to_string(Date.Month) + Seperator;
    stDateRecord += to_string(Date.Day);

    return stDateRecord;
}

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}
stDate ConvertDateLinetoRecord(string Line, string Seperator = "/")
{
    stDate Date;
    vector<string> vDates;
    vDates = SplitString(Line, Seperator);
    Date.Year = stoi(vDates[0]);
    Date.Month = stoi(vDates[1]);
    Date.Day = stoi(vDates[2]);
    return Date;
}

stAmountsSale ConvertDataAmountSalesLinetoRecord(string Line, string Seperator = "#//#")
{
    stAmountsSale Amounts;
    vector<string> vAmountsSales;
    vAmountsSales = SplitString(Line, Seperator);
    Amounts.Bread = stoi(vAmountsSales[0]);
    Amounts.Roti = stoi(vAmountsSales[1]);
    Amounts.RotiParis = stoi(vAmountsSales[2]);
    Amounts.RotiBor = stoi(vAmountsSales[3]);
    Amounts.LargCake = stoi(vAmountsSales[4]);
    Amounts.SmallCake = stoi(vAmountsSales[5]);
    Amounts.LargTamriah = stoi(vAmountsSales[6]);
    Amounts.Ceroasah = stoi(vAmountsSales[7]);
    Amounts.Pan = stoi(vAmountsSales[8]);
    Amounts.Tamriah_20 = stoi(vAmountsSales[9]);
    Amounts.Kodam = stoi(vAmountsSales[10]);
    Amounts.Profit = stoi(vAmountsSales[11]);
    Amounts.Date = ConvertDateLinetoRecord(vAmountsSales[12]);
   

    return Amounts;
}

vector <stAmountsSale> FillVectorWithFullData(string FileName){
    vector <stAmountsSale> vAmounts;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if(MyFile.is_open()){
        string FullDataRecord ;
        while(getline(MyFile , FullDataRecord)){
            vAmounts.push_back(ConvertDataAmountSalesLinetoRecord(FullDataRecord));
        }
    }
    MyFile.close();
    return vAmounts;
}

void PrintRecordData(stAmountsSale Data){
    cout <<"| " << setw(5) << left << Data.Bread;
    cout <<"| " << setw(5) << left << Data.Roti;
    cout <<"| " << setw(10) << left << Data.RotiParis;
    cout <<"| " << setw(8) << left << Data.RotiBor;
    cout <<"| " << setw(10) << left << Data.LargCake;
    cout <<"| " << setw(10) << left << Data.SmallCake;
    cout <<"| " << setw(12) << left << Data.LargTamriah;
    cout <<"| " << setw(10) << left << Data.Ceroasah;
    cout <<"| " << setw(5) << left << Data.Pan;
    cout <<"| " << setw(10) << left << Data.Tamriah_20;
    cout <<"| " << setw(5) << left << Data.Kodam;
    cout <<"| " << setw(6) << left << Data.Profit;
    cout <<"| " << setw(10) << left << ConvertDateRecordToLine(Data.Date);
    cout << "\n";
}
void ShowReports (){
    vector <stAmountsSale> vAmounts = FillVectorWithFullData("Reports.txt");
    cout << "\n_______________________________________________________________________________________________________________________________\n";

    cout <<"| " << setw(5) << left << "Bread";
    cout <<"| " << setw(5) << left << "Roti";
    cout <<"| " << setw(10) << left << "Roti Paris";
    cout <<"| " << setw(8) << left << "Roti Bor";
    cout <<"| " << setw(10) << left << "Larg Cake";
    cout <<"| " << setw(10) << left << "Small Cake";
    cout <<"| " << setw(12) << left << "Larg Tamriah";
    cout <<"| " << setw(10) << left << "Ceroasah";
    cout <<"| " << setw(5) << left << "Pan";
    cout <<"| " << setw(10) << left << "Tamriah_20";
    cout <<"| " << setw(5) << left << "Kodam";
    cout <<"| " << setw(6) << left << "Profit";
    cout <<"| " << setw(10) << left << "Date";
    cout << "\n_______________________________________________________________________________________________________________________________\n";

    for(stAmountsSale & Data : vAmounts){
        PrintRecordData(Data);
        cout << "-------------------------------------------------------------------------------------------------------------------------------\n";
    }
    

}
int main(){
    ShowReports();
    return 0;
}