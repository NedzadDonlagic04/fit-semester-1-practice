#include<iostream>
#include<string>
#include<array>
#include<iomanip>
#include<limits>

bool isInputAValidFloat(const std::string &input) {
    auto dotLimitReached { false };

    for(const auto &c : input) {
        if(!dotLimitReached && c == '.') dotLimitReached = true;
        else if(c < 48 || c > 57 || (c == '.' && dotLimitReached)) return false;
    }
    return true;
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*
    Performs user input by converting the input to a string
    and then trying to convert it to a float, if it fails this
    means the entered value isn't a number and the user needs
    to redo the input properly
*/
void handleInput(float &var, const std::string &inputText) {
    std::string temp {};
    auto inputValid {true};

    while(1) {
        std::cout<<inputText<<": ";
        std::cin>>temp;
        
        if(isInputAValidFloat(temp)) {
            var = std::stof(temp);
            break;
        } else {
            std::cout<<"\nError! Input has to be a valid decimal number!\n"; 
            clearInputBuffer();
        }
    }

    clearInputBuffer();
}

int main(int argv, char* argc[]) {
    std::array<std::string, 7> daysOfTheWeek = { 
        "Monday", 
        "Tuesday", 
        "Wednesday", 
        "Thursday", 
        "Friday", 
        "Saturday", 
        "Sunday" 
    };

    float currentAmountOfMoney {}, averageEarnedPerDay {};

    handleInput(currentAmountOfMoney, "Enter the amount of money at the start of the week");
    handleInput(averageEarnedPerDay, "Enter the average amount of money earned per day");

    std::cout<<'\n';
    std::cout<<std::fixed<<std::setprecision(2);
    for(const auto &day : daysOfTheWeek) {
        currentAmountOfMoney += averageEarnedPerDay;
        
        std::cout<<"At the end of "<<day<<"\'s workday you will have earned "<<currentAmountOfMoney<<"$\n";
    }

    return 0;
}
