#include "std_lib_facilities.h"

constexpr double cm_to_m = 0.01;
constexpr double in_to_m = (2.54 * cm_to_m);
constexpr double ft_to_m = (12.0 * in_to_m);
const vector <string> legal_units { "cm", "m", "in", "ft" };

bool legalUnit(string unit)     // függvény
{
    bool legal = false;             
    for (int i = 0; i < 4; i++) //a vectorban szereplő elemekkel összehasonlítom, hogy legal-e                      
    {
        if (unit == legal_units[i])
        {
            legal = true;
        }

    }
    return legal;
}

void showLegalUnits() // ez a függvény (megmutatja) kiírja, hogy mik a legal unitok
{
    cout << "\tcm for centimeters\n"        //    \t tabulátor
        << "\tm for meters\n"
        << "\tin for inches\n"
        << "\tft for feet\n";
}

double convertToMeter(double value, string unit)     // függvény
{
    if ("cm" == unit)
    {
        return value * cm_to_m;
    }
    if ("in" == unit)
    {
        return value * in_to_m;
    }
    if ("ft" == unit)
    {
        return value * ft_to_m;
    }
    else
    {
        return value;
    }
}

int main()
{
    cout << "Enter a double value followed by unit!\n";

    double value = 0.0;
    double valueMeter = 0.0;
    double max = 0.0;
    double min = 0.0;
    string unit = " ";
    double sum = 0.0;
    int count = 0;
    vector<double> values(0);


    showLegalUnits();

    

    while (cin >> value >> unit)
    {
        if (legalUnit(unit))
        {
            valueMeter = convertToMeter(value, unit);
            cout << value << unit;
            if (unit != "m")
            {
                cout << "(" << valueMeter << "m)";
            }
            if (count == 0)
            {
                min = value;
                max = value;

                cout << " it is the first value and therefore the smallest and largest so far\n";
            }
            if (valueMeter < min)
            {
                cout << "The smallest so far." << endl;
                min = valueMeter;
            }
            if (valueMeter > max)
            {
                cout << "The largest so far." << endl;
                max = valueMeter;
            }
            else
            {
                cout << '\n';
            }
            sum = sum + valueMeter; //megegyezik ezzel: sum += valueMeter;
            values.push_back(valueMeter); // (Adds a new element at the end of the vector, after its current last element.)
            count++; // megszámolja, hogy hány darab érték van
        }
        else
        {
            cout << "No legal unit. Enter one of" << endl;
            showLegalUnits();
        }
    }
    cout << "The smallest: " << min << " m\n"
        << "The largest: " << max << " m\n"
        << "Number of values entered: " << count << '\n'
        << "The sum of values: " << sum << " m\n";

    sort(values); // növekvő sorrendbe teszi

    cout << "The entered values in increasing order: ";
    for (auto value : values)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
    keep_window_open();
}