#include <iostream>
using namespace std;

class TrafficMonitor {
private:
    int **trafficData;
    int zones, intervals;

public:
    TrafficMonitor(int z, int t) : zones(z), intervals(t) {
        trafficData = new int*[zones];
        for (int i = 0; i < zones; ++i) {
            trafficData[i] = new int[intervals]();
        }
    }
    void inputTrafficData() {
        cout << "Enter traffic data for " << zones << " zones and " << intervals << " time intervals:\n";
        for (int i = 0; i < zones; ++i) {
            cout << "Zone " << i + 1 << ":\n";
            for (int j = 0; j < intervals; ++j) {
                cout << "  Interval " << j + 1 << ": ";
                cin >> trafficData[i][j];
            }
        }
    }
    int findBusiestZone() {
        int maxTraffic = 0;
        int busiestZone = 0;

        for (int i = 0; i < zones; ++i) {
            int totalTraffic = 0;
            for (int j = 0; j < intervals; ++j) {
                totalTraffic += *(*(trafficData + i) + j);
            }
            if (totalTraffic > maxTraffic) {
                maxTraffic = totalTraffic;
                busiestZone = i;
            }
        }
        return busiestZone + 1;
    }
    void displayTrafficData() {
        cout << "\nTraffic Data (Vehicles Count):\n";
        for (int i = 0; i < zones; ++i) {
            cout << "Zone " << i + 1 << ": ";
            for (int j = 0; j < intervals; ++j) {
                cout << trafficData[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~TrafficMonitor() {
        for (int i = 0; i < zones; ++i) {
            delete[] trafficData[i];
        }
        delete[] trafficData;
    }
};
int main() {
    int N, M;
    cout << "Enter the number of zones: ";
    cin >> N;
    cout << "Enter the number of time intervals: ";
    cin >> M;
    TrafficMonitor tm(N, M);
    tm.inputTrafficData();
    tm.displayTrafficData();

    int busiestZone = tm.findBusiestZone();
    cout << "\nThe busiest zone is Zone " << busiestZone << " with the highest total traffic.\n";

    return 0;
}
