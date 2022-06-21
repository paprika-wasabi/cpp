/* Copyright 2022 */
//  Set.h
//  Clang
//
//  Created by Paramie Willmann on 22.06.22.
//


#ifndef SET_H_
#define SET_H_

#include <gtest/gtest.h>
#include <cstdio>

template<class T>
class Set {
    public:
        // Constructor.
        Set();
        // Destructor.
        ~Set();
        // Method to insert a element to set.
        insert(T x);
        // Method that erase a given element.
        erase(T x);
        // Method that check if element in set.
        lookup(T x);
        // return size of set.
        size_t size() const;
    private:
        T* _element;
        size_t size_;
}