/* Copyright 2022 */
//  String.h
//  Clang
//
//  Created by Paramie Willmann on 27.05.22.
//


#ifndef SET_H_
#define SET_H_

#include <gtest/gtest.h>
#include <cstdio>

class Set<T> {
    public:
        // Constructor.
        Set<T>();
        // Destructor.
        ~Set<T>();
        // Method to insert a element to set.
        insert(T x);
        // Method that erase a given element.
        erase(T x);
        // Method that check if element in set.
        lookup(T x);
        // return size of set.
        size_t size() const;
    private:

}