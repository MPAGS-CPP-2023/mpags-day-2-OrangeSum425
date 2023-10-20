#include <iostream>
#include <string>
#include <vector>

std::string transformChar(const char in_char){
    const std::string numberWords[] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    };

    if (std::isalpha(in_char)) {
        return std::string(1, std::toupper(in_char));}
    else if(std::isdigit(in_char)){
        int digit = in_char-'0';    
        if (digit >= 0 && digit <= 9) {
        return numberWords[digit];
    }
    }
    return "";     
}

bool processCommandLine(
    const std::vector<std::string>& args,
    bool& helpRequested,
    bool& versionRequested,
    std::string& inputFileName,
    std::string& outputFileName) {
    
    for (size_t i = 0; i < args.size(); i++) {
        const std::string& arg = args[i];

        if (arg == "-h" || arg == "--help") {
            helpRequested = true;
        }
        else if (arg == "--version") {
            versionRequested = true;
        }
        else if (arg == "-i") {
            if (i + 1 < args.size()) {
                inputFileName = args[i + 1];
                i++; 
            } else {
                std::cerr << "Error: -i option requires an input file." << std::endl;
                return false; 
            }
        }
        else if (arg == "-o") {
            if (i + 1 < args.size()) {
                outputFileName = args[i + 1];
                i++; 
            } else {
                std::cerr << "Error: -o option requires an output file." << std::endl;
                return false; 
            }
        }
        else {
            std::cout << "Argument " << i << ": " << arg << std::endl;
        }
    }

    return true; 
}





int main(int argc, char* argv[])
{
  std::string inputFileName;
  std::string outputFileName;
  bool helpRequested = false;
  bool versionRequested = false;
  const std::vector<std::string> cmdLineArgs { argv, argv+argc };

  processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFileName, outputFileName);

  if (helpRequested) {
        std::cout << "Help message: Here is a program for the day 1 course exercise 7" << std::endl;
        std::cout << "Input the password, then it will be converted to uppercase letters." << std::endl;
        std::cout << "Usage: " << argv[0] << " [options] [arguments]" << std::endl;
        return 0;
    }

    if (versionRequested) {
        std::cout << "Program version: 0.2.0 (For the day 2 course)." << std::endl;
        return 0;
    }


  //variables
char in_char{'x'};
std::string out_str{""};

  // Take letter from input:
std::cout << "Enter characters: ";
while (std::cin >> in_char) {
    out_str +=transformChar(in_char);}

    
std::cout << "Transformed result: "<< out_str << std::endl;
}