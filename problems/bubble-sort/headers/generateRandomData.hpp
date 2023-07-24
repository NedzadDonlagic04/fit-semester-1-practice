#include<vector>
#include<random>

namespace custom {
    // Constants used for the random number
    // generation range, aren't parameters 
    // because I don't want them to be
    constexpr int MIN = 0;
    constexpr int MAX = 42000;
    
    [[nodiscard]] std::vector<int> generateRandomNumbers(int numbersToGenerate) {
        if(numbersToGenerate < 1) numbersToGenerate = 1;

        std::vector<int> randomNumbers (numbersToGenerate);

        std::random_device rd {};
        std::mt19937 rng(rd());
        std::uniform_int_distribution<> distribution(MIN, MAX);

        for(std::size_t i = 0; i < randomNumbers.size(); i++) randomNumbers[i] = distribution(rng);

        return randomNumbers;
    }
}