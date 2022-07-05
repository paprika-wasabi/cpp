/* Copyright 2022 */
//  HeatMap.cpp
//  Clang
//
//  Created by Paramie Willmann on 30.06.22.
//

#include "./HeatMap.h"
#include <string_view>
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include "./TerminalManager.h"

// ____________________________________________________________________________
HeatMap::HeatMap() {
    currentNode_ = new Node;
    currentNode_->next_ = nullptr;
    currentNode_->prev_ = nullptr;
    currentNode_->_coordinate = nullptr;
}

// ____________________________________________________________________________
HeatMap::~HeatMap() {
    Node *temp;
    // free all nodes.
    while (currentNode_->next_ != nullptr) {
        temp = currentNode_;
        currentNode_ = currentNode_->next_;
        delete temp;
    }
    // free last node.
    delete currentNode_;
}

// ____________________________________________________________________________
void HeatMap::getMax() {
    while (currentNode_->next_ != nullptr) {
        if (currentNode_->_coordinate->first > max_x) {
            max_x = currentNode_->_coordinate->first;
        }
        if (currentNode_->_coordinate->second > max_y) {
            max_y = currentNode_->_coordinate->second;
        }
        currentNode_ = currentNode_->next_;
    }
    Movetohead();
}

// ____________________________________________________________________________
void HeatMap::getMin() {
    currentNode_ = currentNode_->next_;
    min_x = currentNode_->_coordinate->first;
    min_y = currentNode_->_coordinate->second;
    while (currentNode_->next_ != nullptr) {
        if (currentNode_->_coordinate->first < min_x) {
            min_x = currentNode_->_coordinate->first;
        }
        if (currentNode_->_coordinate->second < min_y) {
            min_y = currentNode_->_coordinate->second;
        }
        currentNode_ = currentNode_->next_;
    }
    Movetohead();
}

// ____________________________________________________________________________
int HeatMap::get_x(float first) {
    float x = (first - min_x) * (di_Col_ / (max_x - min_x));
    return x;
}

// ____________________________________________________________________________
int HeatMap::get_y(float second) {
    float y = (second - min_y) * (di_Row_ / (max_y - min_y));
    return y;
}

// ____________________________________________________________________________
void HeatMap::Movetohead() {
    while (currentNode_->prev_ != nullptr) {
        currentNode_ = currentNode_->prev_;
    }
}

// ____________________________________________________________________________
void HeatMap::readPointsFromFile(const std::string& filename) {
    std::ifstream file;
    file.open(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::string_view lineView = line;
        size_t pos1 = lineView.find('(');
        size_t pos2 = lineView.find(' ', pos1 + 1);
        std::pair<float, float> coordinates;
        std::string_view fcoor = lineView.substr(pos1 + 1, 9);
        std::string_view scoor = lineView.substr(pos2 + 1, 9);
        coordinates.first = std::stod(fcoor.data());
        coordinates.second = std::stod(scoor.data());
        Node *prev_head;
        prev_head = currentNode_;
        currentNode_ = new Node;
        currentNode_->_coordinate = new std::pair<float, float>(coordinates);
        currentNode_->next_ = prev_head;
    }
    while (currentNode_->next_ != nullptr) {
        Node *temp = currentNode_;
        currentNode_ = currentNode_->next_;
        currentNode_->prev_ = temp;
    }
    Movetohead();
}

// ____________________________________________________________________________
void HeatMap::computeHeatMap(int Row, int Col) {
    getMin();
    getMax();
    di_Row_ = Row;
    di_Col_ = Col;
    Map_ = new float[di_Row_*di_Col_];
    while (currentNode_->next_ != nullptr) {
        float temp_x = currentNode_->_coordinate->first;
        float temp_y = currentNode_->_coordinate->second;
        temp_x = get_x(temp_x);
        temp_y = get_y(temp_y);
        int new_x = static_cast<int>(temp_x);
        int new_y = static_cast<int>(temp_y);
        Map_[new_x*di_Col_ + new_y]++;
        currentNode_ = currentNode_->next_;
    }
    MaxInt_ = Map_[0];
    for (int row = 0; row < di_Row_; ++row) {
        for (int col = 0; col < di_Col_; ++col) {
            if (Map_[row*di_Col_ + col] > MaxInt_) {
            MaxInt_ = Map_[row*di_Col_ + col];
            }
        }
    }
    for (int row = 0; row < di_Row_; ++row) {
        for (int col = 0; col < di_Col_; ++col) {
            float temp = (Map_)[row*di_Col_ + col];
            temp = static_cast<float>(temp) / static_cast<float>(MaxInt_);
            Map_[row*di_Col_ + col] = temp;
        }
    }
}

// ____________________________________________________________________________
void HeatMap::drawHeatMap(TerminalManager* tm) {
    UserInput userinput;
    for (int row = 0; row < di_Row_; ++row) {
        for (int col = 0; col < di_Col_; ++col) {
            (*tm).drawPixel(row, col, true, Map_[row*di_Col_ + col]);
            (*tm).refresh();
        }
    }
    (*tm).refresh();
    while (true) {
        userinput = (*tm).getUserInput();
        if (!userinput.isKeyQ()) {
            sleep(1);
        } else {
            break;
        }
    }
}

// ____________________________________________________________________________
const std::pair<float, float> HeatMap::getFirstPair() {
    while (currentNode_->next_ != nullptr) {
        currentNode_ = currentNode_->next_;
    }
    currentNode_ = currentNode_->prev_;
    float x = currentNode_->_coordinate->first;
    float y = currentNode_->_coordinate->second;
    return std::make_pair(x, y);
}

// ____________________________________________________________________________
const std::pair<float, float> HeatMap::getLastPair() {
    Movetohead();
    float x = currentNode_->_coordinate->first;
    float y = currentNode_->_coordinate->second;
    return std::make_pair(x, y);
}
