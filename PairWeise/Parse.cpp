#include "./Parse.hpp"
#include <fstream>
#include <iostream>

// __________________________________________________________________
void Parse::ReadDataFromFile(const std::string& filename1, const std::string& filename2) {
    std::ifstream optionFile(filename1);
    std::ifstream constraintsFile(filename2);
    char c1;
    char c2;
    std::string word1 = "";
    std::string word2 = "";
    while (optionFile.get(c1))
    {     
        if (c1 == ',' || c1 == '\n') {
            options_.push_back(word1);
            if (c1 == '\n') {
                options_.push_back("\n");
            }
            word1 = "";
            continue;
        } else {
            word1 += c1;
        }
    }
    options_.push_back(word1);
    optionFile.close();
    while (constraintsFile.get(c2))
    {
        if (c2 == ',' || c2 == '\n') {
            constraints_.push_back(word2);
            if (c2 == '\n') {
                constraints_.push_back("\n");
            }
            word2 = "";
            continue;
        } else {
            word2 += c2;
        }
    }
    constraints_.push_back(word2);
    constraintsFile.close();

}

// __________________________________________________________________
void Parse::PrettyPrinter() {
    std::ofstream MyFile1("a_Copy.options");
    for(unsigned int i = 0; i < options_.size(); i++)
    {   
        if ((options_[i + 1] == "\n") && (i < (options_.size() - 1))) {
            //std::cout << options_[i];
            MyFile1 << options_[i];
        } else if (options_[i] == "\n" || (i == options_.size() - 1)) {
            //std::cout << options_[i];
            MyFile1 << options_[i];
        } else {
            //std::cout << options_[i] << ",";
            MyFile1 << options_[i] << ",";
        }
    }
    //std::cout << std::endl;
    MyFile1.close();

    std::ofstream MyFile2("a_Copy.constraints");
    for(unsigned int i = 0; i < constraints_.size(); i++)
    {
        if ((constraints_[i + 1] == "\n") && (i < (constraints_.size() - 1))) {
            //std::cout << constraints_[i];
            MyFile2 << constraints_[i];
        } else if (constraints_[i] == "\n" || (i == constraints_.size() - 1)) {
            //std::cout << constraints_[i];
            MyFile2 << constraints_[i];
        } else {
            //std::cout << constraints_[i] << ",";
            MyFile2 << constraints_[i] << ",";
        }
    }
    //std::cout << std::endl;
    MyFile2.close();
}
