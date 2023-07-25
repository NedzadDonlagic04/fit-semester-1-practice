#include<vector>
#include<string>
#include<fstream>
#include<random>

namespace detail {
    [[nodiscard]] std::vector<std::string> getAllFullNames() {
        std::ifstream file("./txt/fullnames.txt");
        std::string line {};
        std::vector<std::string> fullNames {};

        while(std::getline(file, line)) fullNames.push_back(line);

        return fullNames;
    }
}

namespace custom {
    class Employee {
        private:
            int employeeID {};
            std::string fullName {};
            int annualWage {};

        public: 
            Employee() = default;
            Employee(const Employee&) = default;

            Employee(const int employeeID, const std::string fullName, const int annualWage) : employeeID(employeeID), fullName(fullName),annualWage(annualWage) {}

            [[nodiscard]] inline int getEmployeeID() const {
                return this->employeeID;
            }

            [[nodiscard]] inline std::string getFullName() const {
                return this->fullName;
            }

            [[nodiscard]] inline int getAverageWage() const {
                return this->annualWage;
            }

            [[nodiscard]] inline std::string formattedEmployeeInfo() const {
                return "Employee " + this->fullName + " with the ID " + std::to_string(this->employeeID) + " has an annual wage of " + std::to_string(this->annualWage) + "$\n";
            }

            void swap(Employee &other) {
                std::swap(this->employeeID, other.employeeID);
                this->fullName.swap(other.fullName);
                std::swap(this->annualWage, other.annualWage);
            }

            Employee& operator=(Employee other) {
                this->swap(other);

                return *this;
            }

            ~Employee() {}
    };

    // Constants used for the random number
    // generation range, aren't parameters 
    // because I don't want them to be
    constexpr int MIN_WAGE = 80000;
    constexpr int MAX_WAGE = 200000;

    [[nodiscard]] std::vector<Employee> getRandomWorkersData(int numbersToGenerate) {
        if(numbersToGenerate < 1) numbersToGenerate = 1;
        const std::vector<std::string> fullNames { detail::getAllFullNames() };
        std::vector<Employee> randomEmployeeData (numbersToGenerate);

        std::random_device rd {};
        std::mt19937 rng(rd());
        std::uniform_int_distribution<> wageDistribution (MIN_WAGE, MAX_WAGE);
        std::uniform_int_distribution<> fullNameDistribution (0, fullNames.size());
        
        for(std::size_t i = 0; i < randomEmployeeData.size(); i++) {
            int fullNameIndex { fullNameDistribution(rng) };
            int wage { wageDistribution(rng) };

            randomEmployeeData[i] = Employee(i, fullNames[fullNameIndex], wage);
        }

        return randomEmployeeData;
    }
}