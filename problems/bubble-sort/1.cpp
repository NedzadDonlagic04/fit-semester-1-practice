#include<iostream>
#include<vector>
#include<string>
#include "./headers/generateRandomData.hpp"

void bubbleSort(std::vector<int> &vec) {
    for(std::size_t i = 0; i < vec.size(); i++) {
        for(std::size_t ii = 1; ii < vec.size() - i; ii++) {
            if(vec[ii - 1] > vec[ii]) std::swap(vec[ii - 1], vec[ii]);
        }
    }
}

void outputVector(const std::vector<int> &vec ,const std::string &text) {
    std::cout<<text;

    for(const auto &v : vec) std::cout<<v<<' ';
    
    std::cout<<"\n\n";
}

int main(int argv, char* argc[]) {
    std::vector<int> randNums { custom::generateRandomNumbers(100) };

    outputVector(randNums, "Vector before sort: ");

    bubbleSort(randNums);

    outputVector(randNums, "Vector after sort: ");

    return 0;
}
