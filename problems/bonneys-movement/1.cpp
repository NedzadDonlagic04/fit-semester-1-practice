#include<iostream>
#include<string_view>
#include<array>
#include<limits>
#include<numeric>
#include<vector>

[[nodiscard]] std::vector<std::string_view> getCurrentBonneyPosition(int time) {
    // Constant values used for calculation later on
    constexpr int CAMERA_COUNT { 5 };
    constexpr std::string_view CAMERA_NAMES[CAMERA_COUNT] = {"1B", "1C", "3", "2A", "2B"};
    constexpr std::array MINUTES_MOVING_BETWEEN_CAMS = { 2, 8, 3, 2 };
    constexpr int MINUTES_SPENT_IN_ROOM { 1 };

    // Stores function return val
    std::vector<std::string_view> bonneyPosition {};

    /* 
        Gets the total time moving by summing the time needed to go between CAMS
        as well as adds 1 min for each room in a single direction
    */
    const int totalTimeMoving = 
        std::accumulate(MINUTES_MOVING_BETWEEN_CAMS.begin(), MINUTES_MOVING_BETWEEN_CAMS.end(), 0) 
        + MINUTES_MOVING_BETWEEN_CAMS.size();
    
    /* 
        Get result of division between time and total time moving
        so we can remove the unnecessary calculations
        IE let's say we have 31 mins since the shift started
        if the total time moving from on end to the other is 19 mins
        then with this we know that 19 mins happened once so Bonney is coming
        back from CAM 2B
    */
    const int timeQuotient = time / totalTimeMoving;

    time %= totalTimeMoving;

    std::ptrdiff_t startIndex { 0 };
    std::ptrdiff_t endIndex { CAMERA_COUNT - 1 };
    int step { 1 };

    /* 
        If odd number Bonney is coming from 2B to 1B
        So we have to switch indexes for the constant arrays above
        to function properly
    */
    if (timeQuotient % 2 != 0) {
        std::swap(startIndex, endIndex);
        step = -step;
    }

    for (std::ptrdiff_t i = startIndex; i != endIndex; i+= step) {
        time--;

        if (time <= 0) {
            bonneyPosition = { CAMERA_NAMES[i] };
            break;
        }
        
        if (timeQuotient % 2 == 0) time -= MINUTES_MOVING_BETWEEN_CAMS[i];
        else time -= MINUTES_MOVING_BETWEEN_CAMS[i - 1];

        if (time <= 0) {
            bonneyPosition = { CAMERA_NAMES[i], CAMERA_NAMES[i + step] };
            break;
        }
    }

    return bonneyPosition;
}

void clearInputAfterError() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void handleUserInput(int &input, std::string_view inputText) {
    do {
        if (std::cin.fail()) {
            std::cout<<"Error!\nInput has to be a valid whole number!\n";
            clearInputAfterError();
        } else if (input < 0) {
            std::cout<<"Error!\nEntered time can't be a negative number!\n";
        } 

        std::cout<<inputText<<": ";
        std::cin>>input;
    } while(std::cin.fail() || input < 0);
}

int main(int argv, char* argc[]) {
    int timeSinceShiftStart {};

    handleUserInput(timeSinceShiftStart, "Enter time since shift started");

    const auto currentBonneyPosition { getCurrentBonneyPosition(timeSinceShiftStart) };

    if (currentBonneyPosition.size() == 1) {
        std::cout<<"Bonney is currently in CAM "<<currentBonneyPosition[0]<<'\n';
    } else {
        std::cout<<"Bonney is going from CAM "<<currentBonneyPosition[0]<<" to CAM "<<currentBonneyPosition[1]<<'\n';
    }

    return 0;
}
