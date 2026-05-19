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

enum enCompare{GreaterThan = 1 , LessThan = 2, Epual = 3};
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

string ConvertDateRecordToLine(stDate Date, string Seperator = "/")
{

    string stDateRecord = "";
    stDateRecord += to_string(Date.Year) + Seperator;
    stDateRecord += to_string(Date.Month) + Seperator;
    stDateRecord += to_string(Date.Day);

    return stDateRecord;
}

short Defference(short N1 , short N2){
    short TheDefference = N2 - N1;
    return ((TheDefference >= 0) ? TheDefference : TheDefference * -1);
}

enCompare CompareBetweenToNumbers(short N1, short N2){
    if(Defference(N1,N2) <= 300)
        return enCompare::Epual;
    if(N1 > N2)
        return enCompare::GreaterThan;
    return enCompare::LessThan;
}

void ShowStocks(vector <stAmountsSale> & vAllData){
    vector <stAmountsSale> ::iterator iter;
    cout << setw(14) << " " << "  "; 
    for(iter = vAllData.begin() ; iter != vAllData.end() ; iter ++){
        if((iter+1) != vAllData.end() ){
            if(CompareBetweenToNumbers(iter->Profit , (iter+1)->Profit) == enCompare::Epual){
                cout << setw(14) << left << "➡" << "    "; 
            }
            else if(CompareBetweenToNumbers(iter->Profit , (iter+1)->Profit) == enCompare::GreaterThan){
                cout << setw(14) << left << "↘" << "    ";
            }
            else
                cout<< setw(14) << left << "↗" << "    ";
        }
    }
    cout << endl;
}
void PrintDatesOfStocks(vector <stAmountsSale> & vAllData){
    for(stAmountsSale &Data : vAllData){
        cout << setw(14) << left << ConvertDateRecordToLine(Data.Date) << "  ";
    }
    cout << endl;
}
void PrintProfitOfStocks(vector <stAmountsSale> &vAllData){
    for(stAmountsSale &Data : vAllData){
        cout << setw(14) << left << Data.Profit << "  ";
    }
    cout << endl;
}

void PrintAmountsInPlain(vector <stAmountsSale> & vAllData){
    vector <stAmountsSale> ::iterator iter;
    cout << setw(14) << " " << "  "; 
    for(iter = vAllData.begin() ; iter != vAllData.end() ; iter ++){
        if((iter+1) != vAllData.end() ){
            cout << setw(14) << ("R =" + to_string(Defference(iter->Roti , (iter+1)->Roti)) + " | B =" + to_string(Defference(iter->Bread , (iter + 1)->Bread))) << "  ";
        }
    }
    cout << endl;
}

void ShowPlainsOfReports(vector <stAmountsSale> & vAllData){
    ShowStocks(vAllData);
    PrintDatesOfStocks(vAllData);
    PrintProfitOfStocks(vAllData);
    PrintAmountsInPlain(vAllData);
}

int main(){
    vector <stAmountsSale> vAllData = FillVectorWithFullData("Reports.txt");
    ShowPlainsOfReports(vAllData);

    return 0;
}