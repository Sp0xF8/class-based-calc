#pragma once

#include <stdio.h>
#include <vector>
#include <string>

// template <typename T, typename S>
// struct baseClac {
//     T a;
//     S b;
//     char c;

//     baseClac(T a, S b, char c) {
//         this->a = a;
//         this->b = b;
//         this->c = c;
//     }

//     void print() {
//         printf("%d %f %c\n", a, b, c);
//     }
    
// };

struct pair {
    int b1;
    int b2;

    pair(int b1, int b2) {
        this->b1 = b1;
        this->b2 = b2;
    }
};

class BracketStrack {
    std::vector<int> start;

    std::vector<pair> pairs;


    public:

        void add_start(int start) {
            this->start.push_back(start);
        }
        void pop_start() {
            this->start.pop_back();
        }

        int get_start() {
            return start.back();
        }

        void add_pair(int b1, int b2) {
            pairs.push_back(pair(b1, b2));
        }

        void pop_pair() {
            pairs.pop_back();
        }

        pair get_pair() {
            return pairs.back();
        }

        std::vector<pair> get_pairs() {
            return pairs;
        }

        void print_pairs() {
            printf("Pairs:    ");
            for (int i = 0; i < pairs.size(); i++) {
                printf("%d %d ", pairs[i].b1, pairs[i].b2);
            }
            printf("\n");

        }


        void print_stacks() {
            printf("Start stack:    ");
            for (int i = 0; i < start.size(); i++) {
                printf("%d ", start[i]);
            }
            printf("\n");

        }

        void findBrackets(std::string string) {
            for (int i = 0; i < sizeof(string) - 2; i++) {
                if (string[i] == '('){
                    add_start(i);
                } else if (string[i] == ')') {
                    add_pair(get_start(), i);
                    pop_start();
                }
            }
            
        }

};


class intCalc {
    int a;
    int b;
    char c;

    int result;

    public:

        intCalc(int a, int b, char c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }

        ~intCalc() {
            printf("Destructor called\n");
        }

        void set(int a, int b, char c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }

        int getValue() {
            return result;
        }

        void print() {
            printf("%d %c %d \n", a, c, b);
        }

        void calculate(){
            switch (c) {
                case '+':
                    result = a + b;
                    printf("%d %c %d = %d\n", a, c, b, result);
                    break;
                case '-':
                    result = a - b;
                    printf("%d %c %d = %d\n", a, c, b, result);
                    break;
                case '*':
                    result = a * b;
                    printf("%d %c %d = %d\n", a, c, b, result);
                    break;
                case '/':
                    result = a / b;
                    printf("%d %c %d = %d\n", a, c, b, result);
                    break;
                default:
                    printf("Invalid operator\n");
                    break;
            }
        }
};
