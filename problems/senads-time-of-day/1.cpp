// Done by YourFBIAgent
#include<iostream>
#include<chrono>
#include<string>
#include<vector>

// Making a namespace I don't have to repeat saying
// std::chrono::system_clock twice
using systemClock = std::chrono::system_clock;

[[nodiscard]] int getCurrentSystemHours() {
    auto currentTime { systemClock::now() };
    auto currentTimeT { systemClock::to_time_t(currentTime) };
    auto currentLocalTime { std::localtime(&currentTimeT) };

    return currentLocalTime->tm_hour;
}

[[nodiscard]] std::string getCurrentTimePeriod(int hours) {
    std::vector<std::pair<int, std::string>> timePeriods = {
        { 6, "Early Morning" },
        { 10, "Late Morning" },
        { 12, "Early Afternoon" },
        { 14, "Afternoon" },
        { 17, "Evening" },
        { 20, "Late Evening" },
        { 23, "Night Time" }
    };

    for(auto it = timePeriods.begin(); it + 1 != timePeriods.end(); it++) {
        if(hours >= it->first && hours < (it+1)->first) return it->second;     
    }

    return timePeriods.back().second;
}

int main(int argv, char* argc[]) {
    int currentHour { getCurrentSystemHours() };

    std::cout<<"It is currently: \""<<getCurrentTimePeriod(currentHour)<<"\"\n";

    return 0;
}