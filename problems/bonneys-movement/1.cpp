#include<iostream>
#include<string_view>
#include<array>
#include<limits>

std::string_view getCurrentBonneyPosition(const int time) {
    constexpr std::string_view CAMERA_NAMES[] = {"CAM 1B", "CAM 1C", "CAM 3", "CAM 2A", "CAM 2B"};
    constexpr std::array MINUTES_MOVING_BETWEEN_CAMS = { 2, 8, 3, 2 };
    constexpr auto MINUTES_SPENT_IN_ROOM { 1 };

    return CAMERA_NAMES[0];
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
        } 

        std::cout<<inputText<<": ";
        std::cin>>input;
    } while(std::cin.fail());
}

int main(int argv, char* argc[]) {
    int timeSinceShiftStart {};

    handleUserInput(timeSinceShiftStart, "Enter time since shift started");

    std::cout<<timeSinceShiftStart;

    return 0;
}
