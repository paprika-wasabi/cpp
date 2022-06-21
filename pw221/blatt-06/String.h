/* Copyright 2022 */
//  String.h
//  Clang
//
//  Created by Paramie Willmann on 27.05.22.
//


#ifndef STRING_H_
#define STRING_H_

#include <gtest/gtest.h>
#include <cstdio>

class String {
    public:
        //constructor.
        explicit String();

        //destructor.
        ~String();

        // assign a "String" to ours String Class.
        String& operator=(const char* other);

        // copy constructor.
        String(const String& other);

        // copy another String class which already exist.
        String& operator=(const String& other);

        // return size of string.
        size_t size() const;

        // return data of string.
        char* c_str() const;


    private:
        // Initialise the char array.
        char* data_ = nullptr;

        // Initialise size of array.
        size_t size_;
};

class StringSorter {
    public:
        // constructor
        explicit StringSorter(int size);

        // destructor
        ~StringSorter();

        // return size of Sorter.
        size_t size() const;

        // operation to get that elemnt at index i.
        String& operator[](size_t i) const;

        // Sort the StringSorter.
        void sort();

    private:
        // Private variables.
        String* dataSorter_;

        // Initialise size of array.
        size_t sizeSorter_;

        // medthod that swap index l and r.
        void swap(int l, int r);  // NOLINT
        FRIEND_TEST(StringSorter, Swap);

        // help function to implementing quicksort.
        void quicksort(int l, int r);
        int partition(int l, int r);

        // Test function.
        void test();
};

#endif  // STRING_H_
