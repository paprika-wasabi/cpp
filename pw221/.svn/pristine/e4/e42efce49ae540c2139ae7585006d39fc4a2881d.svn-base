/* Copyright 2022 */
//  String.cpp
//  Clang
//
//  Created by Paramie Willmann on 06.06.22.
//
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include "./String.h"

int main() {
    int n = 0;
    int elements = 10000;
    std::ifstream myfile;
    myfile.open("input.txt");
    std::string myline;
    printf("create Sorter1 with move method...\n");
    StringSorter Sorterwithmove(elements);
    printf("create Sorter1 with copy method...\n");
    StringSorter Sorterwithcopy(elements);
    printf("create QuickSort with move method...\n");
    StringSorter QuickSorterwithmove(elements);
    printf("create QucikSort with copy method...\n");
    StringSorter QuickSorterwithcopy(elements);
    if ( myfile.is_open() ) {
        for (n = 0; n < elements; n++) {
            std::getline(myfile, myline);
            // printf("insert:[%d] %s \n", n + 1, myline.c_str());
            Sorterwithcopy[n] = myline.c_str();
            Sorterwithmove[n] = myline.c_str();
            // QuickSorterwithcopy[n] = myline.c_str();
            // QuickSorterwithmove[n] = myline.c_str();
        }
    }
    clock_t time;
    clock_t time1;
    clock_t time2;
    // clock_t time3;
    // clock_t time4;
    time = clock();
    Sorterwithcopy.bsortwithcopy();
    time1 = clock() - time;
    printf("copy time with bubble sort: %f seconds\n",
            static_cast<float>(time1)/ CLOCKS_PER_SEC);
    time = clock();
    Sorterwithmove.bsortwithmove();
    time2 = clock() - time;
    printf("move time with bubble sort: %f seconds\n",
            static_cast<float>(time2)/ CLOCKS_PER_SEC);

    // time = clock();
    // QuickSorterwithcopy.q_sortwithcopy();
    // time3 = clock() - time;

    // time = clock();
    // QuickSorterwithmove.q_sortwithmove();
    // time4 = clock() - time;

    // printf("copy time with quick sort: %f seconds\n",
    //         static_cast<float>(time3)/ CLOCKS_PER_SEC);
    // printf("move time with quick sort: %f seconds\n",
    //         static_cast<float>(time4)/ CLOCKS_PER_SEC);
    return 0;
}
