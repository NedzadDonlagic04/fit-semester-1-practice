#include<iostream>
#include<cmath>
#include<limits>
#include<string>

// This function only works for non negative ints
[[nodiscard]] std::string convertIntToBinaryStr(const int numberOfBits, int numberToConvert) {
  std::string binaryStr {};

  for(numberToConvert = std::abs(numberToConvert); numberToConvert != 0; numberToConvert /= 2) binaryStr = std::to_string(numberToConvert % 2) + binaryStr;

  if (binaryStr == "") binaryStr = "0";

  return std::string(numberOfBits - binaryStr.size(), '0') + binaryStr;
}

void clearBuffer() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void handleInput(int &input, const std::string &inputMessage) {
  do {
    std::cout<<inputMessage;
    std::cin>>input;
    
    if (std::cin.fail()) {
      std::cout<<"Error incorrect input!\n";
      clearBuffer();
    }

  } while(std::cin.fail()); 
}

void handleRangedInput(int &input, const std::string &inputMessage, const int min, const int max) {
  do {
    handleInput(input, inputMessage);
    
    if (input < min || input > max) std::cout<<"Input has to be between "<<min<<" and "<<max<<'\n';
  } while(input < min || input > max);
}

/*  Put these 2 options into the same function due to the difference
 *  between them being like 1-2 lines of code, so this felt like
 *  a good compromise
*/
void handleSignedBitOr1sComplementOption(const int numberOfBits, const int numberToConvert, bool is1sComplement = false) {
  const int biggestNum { static_cast<int>(std::pow(2, numberOfBits - 1)) - 1 };
  const int smallestNum { -biggestNum + 1 }; 
  const std::string optionName = (is1sComplement)? "1s Complement" : "Signed Bit";

  if (numberToConvert < smallestNum || numberToConvert > biggestNum) {
    std::cout<<"The given number "<<numberToConvert<<" cannot be converted with the \""<<optionName<<"\" option with only "<<numberOfBits<<" bits\n";   
  } else {
    std::string binaryStr { convertIntToBinaryStr(numberOfBits, numberToConvert) }; 
    
    if (is1sComplement) 
      for(auto &bit : binaryStr) 
        bit = (bit == '0')? '1' : '0';
    else binaryStr[0] = (numberToConvert < 0)? '1' : '0';

    std::cout<<"The given number "<<numberToConvert<<" with the \""<<optionName<<"\" option is the number "<<binaryStr<<" in binary\n";   
  }
}

void handles2sComplementOption(const int numberOfBits, const int numberToConvert) {
  const int biggestNum { static_cast<int>(std::pow(2, numberOfBits - 1)) - 1 };
  const int smallestNum { -biggestNum - 1 }; 

  if (numberToConvert < smallestNum || numberToConvert > biggestNum) {
    std::cout<<"The given number "<<numberToConvert<<" cannot be converted with the \"2s Complement\" option with only "<<numberOfBits<<" bits\n";   
  } else {
    std::string binaryStr { convertIntToBinaryStr(numberOfBits, numberToConvert) }; 
    
    // The result is reduced by 1 because I want to reverse everything after the 1st 1
    std::size_t posOfLast1 { binaryStr.find_last_of('1') - 1 };

    if(posOfLast1 != std::string::npos) 
      // We learned this method for 2s complement in Digital Logic class, no clue if it has
      // some official name or what, look from right to left and reverse everything past
      // the first 1 you see
      for(std::ptrdiff_t i = posOfLast1; i >= 0; i--) 
        binaryStr[i] = (binaryStr[i] == '0')? '1' : '0';

    std::cout<<"The given number "<<numberToConvert<<" with the \"2s Complement\" option is the number "<<binaryStr<<" in binary\n";   
  }
}

int main () {
  char option {};

  std::cout<<"Welcome to the decimal number to binary converter!\n";
  std::cout<<"This console app is used to practice a bit of programming a digital logic\n";
  std::cout<<"Enter one of the options below to convert whatever decimal number you want to binary\n";

  do {
    std::cout<<"\nConvert a number to binary with: \n";
    std::cout<<"1 - A signed bit\n";
    std::cout<<"2 - 1's complement\n";
    std::cout<<"3 - 2's complement\n";
    std::cout<<"4 - Or Quit\n";

    std::cout<<"Enter an option: ";
    std::cin>>option;

    if (option == '1' || option == '2' || option == '3') {
      int numberOfBits {}, numberToConvert {};
      
      handleRangedInput(numberOfBits, "Enter the number of bits: ", 2, 32);
      handleInput(numberToConvert, "Enter the number to convert: ");
      
      if (option == '1') 
        handleSignedBitOr1sComplementOption(numberOfBits, numberToConvert);
      else if (option == '2') 
        handleSignedBitOr1sComplementOption(numberOfBits, numberToConvert, true);
      else 
        handles2sComplementOption(numberOfBits, numberToConvert);

    } else if (option != '4') std::cout<<"Error given input isn't an option!\n"; 

  } while(option != '4');

  return 0;
}
