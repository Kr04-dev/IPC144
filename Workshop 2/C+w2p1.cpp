#include <iostream>
#include <iomanip>
#define _CRT_SECURE_NO_WARNINGS
#define TAX 0.13

using namespace std;

void w2p1(int& numShirt, int& total, int& sub_total, int& taxPrice, double& pS, 
          double& pM, double& pL) {

    const char patSize = 'S';

    cout << "Set Shirt Prices" << endl;
    cout << "================" << endl;
    cout << "Enter the price for a SMALL shirt: $";
    cin >> pS;
    cout << "Enter the price for a MIDIUM shirt: $";
    cin >> pM;
    cout << "Enter the price for a LARGE shirt: $";
    cin >> pL;
    cout << endl;

    cout << "Shirt Store Price List" << endl;
    cout << "======================" << endl;
    cout << "SMALL  : $" << pS << endl;
    cout << "MIDIUM : $" << pM << endl;
    cout << "LARGE  : $" << pL << endl;
    cout << "Patty's shirt size is '" << patSize << "'" << endl;
    cout << "Number of shirts Patty is buying: ";
    cin >> numShirt;  
    cout << "" << endl;
    cout << "Patty's shopping cart..." << endl;
    cout << "Contains : " << numShirt << " shirts" << endl;

    sub_total = (pS * numShirt) * 100;
    cout << "Sub-total: $" << (sub_total / 100.0) << endl;
    taxPrice = (sub_total * TAX) + 0.5;
    cout << "Taxes    : $" << (taxPrice / 100.0) << endl;
    total = sub_total + taxPrice;
    cout << "Total    : $" << (total / 100.00) << endl;

}

void w2p2(int& numShirtPat, int& numShirtSal, int& numShirtTom, int& totalPat, 
          int& totalSal, int& totalTom, int& sub_totalPat, int& sub_totalSal, 
          int& sub_totalTom, int& taxPricePat, int& taxPriceTom, int& taxPriceSal, 
          int& toonie_cal, int& loonie_cal, int& quarters_cal, int& dimes_cal, 
          int& nickels_cal, int& pennies_cal, double& pS, double& pM, double& pL,
          double& coin_cal, double& sub_totalD, double& totalD, double& taxPriceD,
          char& pat, char& sal, char& tom){

    cout << "Set Shirt Prices" << endl;
    cout << "================" << endl;
    cout << "Enter the price for a SMALL shirt: $";
    cin >> pS;
    cout << "Enter the price for a MIDIUM shirt: $";
    cin >> pM;
    cout << "Enter the price for a LARGE shirt: $";
    cin >> pL;
    cout << endl;

    cout << "Shirt Store Price List" << endl;
    cout << "======================" << endl;
    cout << "SMALL  : $" << pS << endl;
    cout << "MIDIUM : $" << pM << endl;
    cout << "LARGE  : $" << pL << endl;

    pat = 'S';
    cout << "Patty's shirt size is '" << pat << "'" << endl;
    cout << "Number of shirts Patty is buying: ";
    cin >> numShirtPat;
    sub_totalPat = (pS * numShirtPat + 0.005) * 100;
    taxPricePat = (sub_totalPat * TAX) + 0.5;
    totalPat = sub_totalPat + taxPricePat;
    cout << "" << endl;

    tom = 'L';
    cout << "Tommy's shirt size is '" << tom << "'" << endl;
    cout << "Number of shirts Tommy is buying: ";
    cin >> numShirtTom;
    sub_totalTom = (pL * numShirtTom + 0.005) * 100;
    taxPriceTom = (sub_totalTom * TAX) + 0.5;
    totalTom = sub_totalTom + taxPriceTom;
    cout << "" << endl;

    pat = 'M';
    cout << "Sally's shirt size is '" << sal << "'" << endl;
    cout << "Number of shirts Sally is buying: ";
    cin >> numShirtSal;
    sub_totalSal= (pM * numShirtSal+ 0.005) * 100;
    taxPriceSal = (sub_totalSal* TAX) + 0.5;
    totalSal= sub_totalSal + taxPriceSal;
    cout << "" << endl;

    cout << "Customer Size Price Qty Sub-Total       Tax     Total" << endl;
    cout << "-------- ---- ----- --- --------- --------- ---------" << endl;
    cout << "Patty    " << setw(4) << left << pat << " " << setw(5) << pS << " " << setw(5) << numShirtPat << " " << setw(9) << sub_totalPat / 100.0 << " " << setw(9) << taxPricePat / 100.0 << " " << setw(9) << totalPat / 100.0 << endl;
    cout << "Sally    " << setw(4) << left << sal << " " << setw(5) << pM << " " << setw(5) << numShirtSal << " " << setw(9) << sub_totalSal / 100.0 << " " << setw(9) << taxPriceSal / 100.0 << " " << setw(9) << totalSal / 100.0 << endl;
    cout << "Tommy    " << setw(4) << left << tom << " " << setw(5) << pL << " " << setw(5) << numShirtTom << " " << setw(9) << sub_totalTom / 100.0 << " " << setw(9) << taxPriceTom / 100.0 << " " << setw(9) << totalTom / 100.0 << endl;
    sub_totalD = sub_totalPat + sub_totalSal + sub_totalTom;
    taxPriceD = taxPricePat + taxPriceSal + taxPriceTom;
    totalD = totalPat + totalSal + totalTom;
    cout << setw(33) << sub_totalD / 100 << " " << setw(9) << taxPriceD / 100 << " " << setw(9) << totalD / 100 << "\n\n";

    cout << "Dailt retail sales represented by coins" << endl;
    cout << "=======================================" << endl;
    cout << "Sales EXCLUDING tax" << endl;
    cout << "Coin     Qty   Balance"  << endl;
    cout << "-------- --- ---------" << endl;
    cout << setw(22) << sub_totalD / 100 << endl;
    coin_cal = sub_totalD;

    toonie_cal = coin_cal / 200;
    coin_cal -= toonie_cal * 200;
    cout << "Toonies" << setw(4) << toonie_cal << setw(9) << coin_cal / 100 << endl;
    loonie_cal = coin_cal / 100;
    coin_cal -= loonie_cal * 100;
    cout << "Loonies" << setw(4) << loonie_cal << setw(9) << coin_cal / 100 <<  endl;
    quarters_cal = coin_cal / 25;
    coin_cal -= quarters_cal * 25;
    cout << "Quarters" << setw(3) << quarters_cal << setw(9) << coin_cal / 100 << endl;
    dimes_cal = coin_cal / 10;
    coin_cal -= dimes_cal * 10;
    cout << "Dimes" << setw(6) << dimes_cal << setw(9) << coin_cal / 100 << endl;
    nickels_cal = coin_cal / 5;
    coin_cal -= nickels_cal * 5;
    cout << "Nickels" << setw(4) << nickels_cal << setw(9) << coin_cal / 100 << endl;
    pennies_cal = coin_cal / 1;
    coin_cal -= pennies_cal * 1;
    cout << "Pennies" << setw(4) << pennies_cal << setw(9) << coin_cal / 100 << endl;

    cout << "Average cost/shirt: $" << (sub_totalD / (numShirtPat + numShirtSal + numShirtTom)) / 100 << endl;


}

int main(){
 
    int numShirtPat, numShirtSal, numShirtTom, totalPat, totalSal, totalTom, 
        sub_totalPat, sub_totalSal, sub_totalTom, taxPricePat, taxPriceTom, 
        taxPriceSal, toonie_cal, loonie_cal, quarters_cal, dimes_cal, nickels_cal, 
        pennies_cal;
    double pS, pM, pL, coin_cal, sub_totalD, totalD, taxPriceD;
    char pat, sal, tom;

    //w2p1(numShirt, total, sub_total, taxPrice, pS, pM, pL);

    w2p2(numShirtPat, numShirtSal, numShirtTom, totalPat, totalSal, totalTom, sub_totalPat, sub_totalSal, sub_totalTom, taxPricePat, taxPriceTom, taxPriceSal, toonie_cal, loonie_cal, quarters_cal, dimes_cal, nickels_cal, pennies_cal, pS, pM, pL, coin_cal, sub_totalD, totalD, taxPriceD, pat, sal, tom);

	return 0;
}
