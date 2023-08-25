#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

#include <baseCalc.h>

// #include "../inc/baseCalc.h"



#define _DEBUG_ALL

//create a vector of type intCalc
std::vector<intCalc> intCalcVector;

BracketStrack bracketStack;

void stepThrough(std::string calculation) {
        std::string tempA;
        int a;
        std::string tempB;
        int b;
        char c;

        bool aFound = false;

        for (int i = 0; i < sizeof(calculation) - 2; i++) {
            

            if (calculation[i] == '\0') {
                continue;
            }

            if(calculation[i] == ' ' && aFound == false) {
                aFound = true;
                continue;
            }

            if (calculation[i] == ' ') {
                continue;
            }

            if (calculation[i] == '+' || calculation[i] == '-' || calculation[i] == '*' || calculation[i] == '/') {
                c = calculation[i];
                continue;
            }

            if (aFound == false) {
                tempA += calculation[i];
            } else {
                tempB += calculation[i];
            }

        }
        a = std::stoi(tempA);
        b = std::stoi(tempB);

        intCalcVector.emplace_back(intCalc(a, b, c));


    }

void bracketStepThrough(std::string str){
    
}

void populateClasses(std::string input) {
    for (int i = 0; i < bracketStack.get_pairs().size(); i++) {

        std::string subString = input.substr(bracketStack.get_pairs()[i].b1 + 1, bracketStack.get_pairs()[i].b2 - bracketStack.get_pairs()[i].b1 - 1);
        //for loop cycling through the pairs in lifo order, check if there are any brackets between the current ranges,

        for (int j = 0; j < bracketStack.get_pairs().size(); j++) {
            if (bracketStack.get_pairs()[j].b1 > bracketStack.get_pairs()[i].b1 && bracketStack.get_pairs()[j].b2 < bracketStack.get_pairs()[i].b2) {
                //call BracketStepThrough
                bracketStack.pop_pair();
                intCalcVector.pop_back();
            } else {
                //call stepThrough
                stepThrough(subString);
            }
        }
        stepThrough(subString);

        printf("\n");
    }
}

int main() {
    printf("===========[ C L A S S  B A S E D  C A L C U L A T O R ]===========\n");

    // intCalcVector.push_back(intCalc());
    // intCalcVector.push_back(intCalc());

    // for (int i = 0; i < intCalcVector.size(); i++) {
    //     intCalcVector[i].calculate();
    // }


    
    std::string input;
    printf("Enter a calculation: ");
    std::getline(std::cin, input);


    bracketStack.findBrackets(input);

    bracketStack.print_stacks();
    bracketStack.print_pairs();

    populateClasses(input);
    

    for (int i = 0; i < intCalcVector.size(); i++) {
        intCalcVector[i].calculate();
    }

    // stepThrough(input, &intCalcVector[0]);

    // intCalcVector[0].calculate();
    
    
    // Create a new instance of the baseClas

    return 0;
}