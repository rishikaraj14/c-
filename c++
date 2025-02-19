include <iostream>
using namespace std;

class SmartLight {
private:
    static int defaultBrightness; // Static variable for global brightness
    int brightness; // Private instance variable for individual brightness

public:
    // Constructor initializing brightness with the default value
    SmartLight() {
        brightness = defaultBrightness;
    }

    // Static function to set default brightness (global)
    static int setDefaultBrightness(int level) {
        defaultBrightness = level;
        return defaultBrightness;
    }

    // Static function to get default brightness
    static int getDefaultBrightness() {
        return defaultBrightness;
    }

    // Function to set brightness of an individual light
    int setBrightness(int level) {
        brightness = level;
        return brightness;
    }

    // Func
