/* Copyright 2022 */
//  HeatMap.h
//  Clang
//
//  Created by Paramie Willmann on 30.06.22.
//

#ifndef HEATMAP_H_
#define HEATMAP_H_

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include "./TerminalManager.h"

class HeatMap {
    // create pointer that point to Map.
    float *Map_;

 private:
    // Hold screen dimension.
    int di_Row_;
    int di_Col_;
    // Hold Point which is maximun and minimum pair.
    float max_x;
    float max_y;
    float min_x;
    float min_y;
    // Data Structure to collect all Point.
    class Node {
     public:
         ~Node() { delete _coordinate;}
         std::pair<float, float>* _coordinate;
         Node* next_ = nullptr;
         Node* prev_ = nullptr;
    };
    // Head reference for Linked List.
    Node* currentNode_;
    // get Maximum and Minimum Point.
    void getMax();
    void getMin();
    // after traverse along the list then move back to head.
    void Movetohead();
    // Method for simple linear transformation.
    // using Linear Interpolation.
    int get_x(float first);
    int get_y(float second);
    // Hold Maximum Intensity.
    float MaxInt_;

 public:
    // Constructor.
    HeatMap();
    // Free allocate all Mememory.
    ~HeatMap();
    // get file name using linked list to store the data.
    void readPointsFromFile(const std::string& filename);
    // Compute the given data in to Pixel coordinates.
    void computeHeatMap(int Row, int Col);
    // Draw all pixel according to Intensity.
    void drawHeatMap(TerminalManager* tm);
    // Method to help test.
    const std::pair<float, float> getLastPair();
    const std::pair<float, float> getFirstPair();
    const float getMaxInt() { return MaxInt_; }
};

#endif  //  HEATMAP_H_
