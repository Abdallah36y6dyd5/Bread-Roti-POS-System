//#pragma warning (disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;

string readSrting(){
    string text;
    cin.ignore(100000,'\n');
    getline(cin,text);
    return text;
}

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
    stDate Date;
    short Kodam = 0;
    short Profit = 0;
};






string ConvertDateRecordToLine(stDate Date, string Seperator = "/")
{

    string stDateRecord = "";
    stDateRecord += to_string(Date.Year) + Seperator;
    stDateRecord += to_string(Date.Month) + Seperator;
    stDateRecord += to_string(Date.Day);

    return stDateRecord;
}

string ConvertFallRecordDataToLine(stAmountsSale Amounts, string Seperator = "#//#")
{

    string stAmountsSaleRecord = "";
    stAmountsSaleRecord += to_string(Amounts.Bread) + Seperator;
    stAmountsSaleRecord += to_string(Amounts.Roti) + Seperator;
    stAmountsSaleRecord += to_string(Amounts.RotiParis) + Seperator;
    stAmountsSaleRecord += to_string(Amounts.RotiBor) + Seperator;
    stAmountsSaleRecord += to_string(Amounts.LargCake) + Seperator;
    stAmountsSaleRecord += to_string(Amounts.SmallCake) + Seperator;
    stAmountsSaleRecord += to_string(Amounts.LargTamriah) +Seperator;
    stAmountsSaleRecord += to_string(Amounts.Ceroasah) + Seperator;
    stAmountsSaleRecord += to_string(Amounts.Pan) + Seperator;
    stAmountsSaleRecord += to_string(Amounts.Tamriah_20) + Seperator;
    stAmountsSaleRecord += to_string(Amounts.Kodam) + Seperator;
    stAmountsSaleRecord += to_string(Amounts.Profit) + Seperator;
    stAmountsSaleRecord += ConvertDateRecordToLine(Amounts.Date) ;
    
    

    return stAmountsSaleRecord;
}



vector <float> LoadQuantitiesFormFile(string FileName){
    vector <float> Quantities;
    ifstream MyFile;
    MyFile.open(FileName, ios::in);
    if(MyFile.is_open()){
        string Kind;
        while(getline(MyFile, Kind)){
            if(Kind.find('=') != std::string::npos){
                Kind.erase(0, Kind.find('=') + 1);
                Quantities.push_back(stof(Kind));
            }
        }
        MyFile.close();
    }
    return Quantities;
}
//?_____________________________________________________
vector <float> Kinds = LoadQuantitiesFormFile("Data.txt");
int nRoti = Kinds[0];
float nBread = Kinds[1];
int nRotiParis = Kinds[2];
int nRotiBor = Kinds[3];
int nLargCake = Kinds[4];
int nSmallCake = Kinds[5];
int nLargTamrah = Kinds[6];
int nCroasah = Kinds[7];
int nPan = Kinds[8];
int nTAbo20 = Kinds[9];
int nKodam = Kinds[10];

int LeftRoti = Kinds[11];
float LeftBread = Kinds[12];
int LeftRotiParis= Kinds[13];
int LeftRotiBor = Kinds[14];
int LeftLargCake = Kinds[15];
int LeftSmallCake = Kinds[16];
int LeftTamriah = Kinds[17];
int LeftCroasah = Kinds[18];
int LeftPan = Kinds[19];
int LeftTAbo20 = Kinds[20];
int LeftKodam = Kinds[21];

float AshrafRafeeq = Kinds[22]/200;

int LocalOutputs = Kinds[23];
int GlobalOutputs = Kinds[24];

//?_____________________________________________________

void SaveDataToFile(string FileName , stAmountsSale Amounts){
    fstream MyFile;
    MyFile.open(FileName , ios::out | ios::app);
    if(MyFile.is_open()){
        string RecordFallData ;
        RecordFallData= ConvertFallRecordDataToLine(Amounts);
        MyFile << RecordFallData << endl;
    }
    MyFile.close();
}
//?_______________________________________________________

stDate GetNowDate(){
    stDate Date;
    time_t t = time(0);
    tm *now = localtime(&t);
    Date.Year = 1900+ now->tm_year;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday ;
    return Date;

}
stAmountsSale FillDataByAmounts(){
    stAmountsSale Data;
    int x;
    Data.Bread = nBread - AshrafRafeeq - LeftBread;
    Data.Roti = nRoti -30 - LeftRoti ;
    Data.RotiParis = nRotiParis - LeftRotiParis;
    Data.RotiBor = nRotiBor - LeftRotiBor;
    Data.LargCake = nLargCake - LeftLargCake ;
    Data.SmallCake = nSmallCake - LeftSmallCake ;
    Data.LargTamriah = nLargTamrah - LeftTamriah;
    Data.Ceroasah = nCroasah - LeftCroasah;
    Data.Pan = nPan - LeftPan;
    Data.Tamriah_20 = nTAbo20 - LeftTAbo20;
    Data.Date = GetNowDate();
    Data.Kodam = nKodam - LeftKodam;
    Data.Profit = Data.Bread * 50 + Data.Roti * 5 + Data.RotiParis * 2 + Data.RotiBor + Data.LargCake * 20 + Data.SmallCake * 10 + Data.LargTamriah * 20 + Data.Ceroasah * 20 + Data.Pan * 10 + Data.Tamriah_20 * 4 + Data.Kodam * 7;
    
    
    
    return Data;

}

void ShowGlobal(){

    stAmountsSale TheData = FillDataByAmounts();

    cout << "خ = " << nBread << " - " <<AshrafRafeeq  << " = " << (float)(nBread - AshrafRafeeq) <<" - "<< LeftBread << " = " << TheData.Bread *150 << endl;
    cout << "ص = " << nRoti << " - 30 = " << nRoti -30 << " - " << LeftRoti << " = " << TheData.Roti *20 << endl;
    cout << "ف = " << nRotiParis << " - " << LeftRotiParis << " = " <<TheData.RotiParis *23 << endl; 
    cout << "ب = " << nRotiBor << " - " << LeftRotiBor << " = " <<TheData.RotiBor *24 << endl;
    cout << "ت ك = " << nLargTamrah << " - " << LeftTamriah << " = " <<TheData.LargTamriah *80 <<endl;
    cout << "كرواسه = " << nCroasah << " - " << LeftCroasah << " = " <<TheData.Ceroasah *180 << endl;
    cout << "ك ك = " << nLargCake << " - " << LeftLargCake << " = " <<TheData.LargCake *80 << endl;
    cout << "ك ص = " << nSmallCake<< " - " << LeftSmallCake<< " = " << TheData.SmallCake *40 << endl;
    cout << "بان = " << nPan << " - " << LeftPan << " = " << TheData.Pan *40 << endl;
    cout << "ت ابو 20 = " <<nTAbo20 << " - " <<LeftTAbo20 << " = " << TheData.Tamriah_20 *16 << endl;

    int Total = TheData.Bread *150 + TheData.Roti *20 + TheData.RotiParis *23 + TheData.RotiBor *24 + TheData.LargTamriah *80 + TheData.Ceroasah *180 + TheData.LargCake *80 + TheData.SmallCake *40 + TheData.Pan *40 + TheData.Tamriah_20 *16;
    
    cout << "\nالخرج = " << GlobalOutputs ;
    cout << "\t\t" << "المجموع = " << Total << endl;
    cout << "___________________________________________________\n\n" ;
    cout <<"\t\t" << "الناتج = " << (Total - GlobalOutputs) << endl;
    char Answer = 'N';
    cout << "Are Sure For Save This Page ? (Y/N) : ";
    cin >> Answer;
    if(toupper(Answer) == 'Y'){
        SaveDataToFile("Reports.txt" , TheData);
        cout << "Done Successfully .\n";
    }
    if(readSrting() == "712")
        cout << "\t\t" << "الربح = " << TheData.Profit << endl;
    



}
void ShowLocal(){
    
    cout << "خ = " << nBread << nBread <<" - "<< LeftBread << " = " << (float)(nBread - LeftBread)*200 << endl;
    cout << "ص = " << nRoti << " - "<< LeftRoti << " = " << (nRoti  - LeftRoti) *25 << endl;
    cout << "ف = " << nRotiParis << " - " << LeftRotiParis << " = " << (nRotiParis-LeftRotiParis)*25 << endl; 
    cout << "ب = " << nRotiBor << " - " << LeftRotiBor << " = " << (nRotiBor-LeftRotiBor)*25 << endl;
    cout << "ت ك = " << nLargTamrah << " - " << LeftTamriah << " = " << (nLargTamrah-LeftTamriah)*100 <<endl;
    cout << "كرواسه = " << nCroasah << " - " << LeftCroasah << " = " << (nCroasah - LeftCroasah)*200 << endl;
    cout << "ك ك = " << nLargCake << " - " << LeftLargCake << " = " << (nLargCake-LeftLargCake)*100 << endl;
    cout << "ك ص = " << nSmallCake<< " - " << LeftSmallCake<< " = " <<(nSmallCake-LeftSmallCake)*50 << endl;
    cout << "بان = " << nPan << " - " << LeftPan << " = " <<(nPan - LeftPan)*50 << endl;
    cout << "ت ابو 20 = " <<nTAbo20 << " - " <<LeftTAbo20 << " = " <<(nTAbo20-LeftTAbo20)*20 << endl;

    int Total = (nBread-LeftBread)*200 + (nRoti - LeftRoti)*25 + (nRotiParis-LeftRotiParis)*25 + (nRotiBor - LeftRotiBor)*25 + (nLargTamrah - LeftTamriah)*100 + (nCroasah-LeftCroasah)*200 + (nLargCake-LeftLargCake)*100 + (nSmallCake-LeftSmallCake)*50 + (nPan-LeftPan)*50 + (nTAbo20-LeftTAbo20)*20;
    int Profit = (nBread-AshrafRafeeq-LeftBread)*50 + (nRoti - 30 - LeftRoti)*5 + (nRotiParis-LeftRotiParis)*2 + (nRotiBor - LeftRotiBor)*1 + (nLargTamrah - LeftTamriah)*20 + (nCroasah-LeftCroasah)*20 + (nLargCake-LeftLargCake)*20 + (nSmallCake-LeftSmallCake)*10 + (nPan-LeftPan)*10 + (nTAbo20-LeftTAbo20)*4 + (nKodam-LeftKodam)*7;
    cout << "\nالخرج = " << LocalOutputs ;
    cout << "\t\t" << "المجموع = " << Total << endl;
    cout << "___________________________________________________\n\n" ;
    cout <<"\t\t" << "الناتج = " << (Total - LocalOutputs) << endl;
    if(readSrting() == "712")
        cout << "\t\t" << "الربح = " << Profit << endl;



}




int main(){
    cout << "[1]حسبة العنصره , [2]حسبة التجريبيه : " ;
    short n;
    cin >> n;
    if(n == 1)
        ShowGlobal();
    else if(n ==2)
        ShowLocal();
    
    
    return 0;
}