#include<iostream>
#include "./headers/generateData.hpp"

namespace ctm = custom;

void insertionSort(std::vector<ctm::Employee> &employeeData) {
    for(std::size_t i = 1; i < employeeData.size(); i++) {
        for(std::size_t ii = i; ii > 0 && employeeData[ii-1].getAverageWage() > employeeData[ii].getAverageWage(); ii--) {
            employeeData[ii-1].swap(employeeData[ii]);
        } 
    }
}

void outputEmployeeData(const std::vector<ctm::Employee> &employeeData ,const std::string &text) {
    std::cout<<text;

    for(const auto &v : employeeData) std::cout<<v.formattedEmployeeInfo();

    std::cout<<'\n';
}

int main(int argv, char* argc[]) {
    std::vector<ctm::Employee> employeeData {ctm::getRandomWorkersData(100)}; 

    outputEmployeeData(employeeData, "Employees before sort: \n");

    insertionSort(employeeData);

    outputEmployeeData(employeeData, "Employees after sort: \n");

    return 0;
}
