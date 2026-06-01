// Author: Hugo Ramirez
// Date: 05/31/2026
// Description: This program shows the use of functional and no-functional characteristics 
#include <iostream>
#include <random>
#include <stdexcept>
#include <iomanip>

using namespace std;

class DangerZoneException : public runtime_error {
public:
    double value;
    DangerZoneException(double val)
        : runtime_error("Danger zone reading detected"), value(val) {}
};

int main() {
    double lowerBound, upperBound;

    cout << "Sensor Quality Control Simulator\n\n";
    cout << "Enter the LOWER danger threshold (between 10 and 100): ";
    cin >> lowerBound;
    cout << "Enter the UPPER danger threshold (between 10 and 100): ";
    cin >> upperBound;

    if (lowerBound >= upperBound || lowerBound < 10 || upperBound > 100) {
        cerr << "Invalid thresholds. Lower must be < Upper, both within [10, 100].\n";
        return 1;
    }

    mt19937 engine(random_device{}());
    uniform_real_distribution<double> dist(10.0, 100.0);

    int exceptionCount = 0;

    cout << "\nGenerating 25 sensor readings...\n";
    cout << fixed << setprecision(2);
    cout << "Danger zone: [" << lowerBound << ", " << upperBound << "]\n\n";

    for (int i = 1; i <= 25; i++) {
        double reading = dist(engine);

        try {
            if (reading >= lowerBound && reading <= upperBound) {
                throw DangerZoneException(reading);
            }

            cout << "Reading " << setw(2) << i
                 << ": " << setw(7) << reading << "  [OK]\n";

        } catch (const DangerZoneException& e) {
            exceptionCount++;
            cout << "Reading " << setw(2) << i
                 << ": " << setw(7) << e.value
                 << "  [!! EXCEPTION: " << e.what() << " !!]\n";
        }
    }

    cout << "\n--- Summary ---\n";
    cout << "Total danger zone exceptions caught: " << exceptionCount << " / 25\n";

    return 0;
}