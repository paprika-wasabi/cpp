// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <iostream>
#include <string>
#include <utility>
#include <vector>

// A thing with a member function toString.
class Thing {
 public:
  virtual ~Thing() { }
  virtual std::string toString() const { return "THING"; }
  // virtual std::string toString() const = 0;  // { return "THING"; }
};

// An integer thing that inherits from Thing (in this case, the member function
// toString).
class IntegerThing : public Thing {
 public:
  explicit IntegerThing(int value) { value_ = value; }
  std::string toString() const override { return std::to_string(value_); }
 private:
  int value_;
};

// A string thing that inherits from Thing (in this case, the member function
// toString).
class StringThing : public Thing {
 public:
  explicit StringThing(std::string s) : contents_(std::move(s)) { }
  std::string toString() const override { return contents_; }
 private:
  std::string contents_;
};

// Play around with things.
int main() {
  Thing thing1;
  IntegerThing thing2(7);
  StringThing thing3("doof");
  // std::cout << thing1.toString() << std::endl;
  // std::cout << thing2.toString() << std::endl;
  // std::cout << thing3.toString() << std::endl;

  // A vector of three (different) things.
  std::vector<Thing*> things;
  things.push_back(&thing1);
  things.push_back(&thing2);
  things.push_back(&thing3);

  // Show the sizes of the objects in bytes.
  std::cout << "Size of thing1 in bytes: " << sizeof(thing1) << std::endl;
  std::cout << "Size of thing2 in bytes: " << sizeof(thing2) << std::endl;
  std::cout << "Size of thing3 in bytes: " << sizeof(thing3) << std::endl;

  // Show the result of toString of each of the three objects.
  std::cout << std::endl;
  for (const auto thing : things) {
    std::cout << thing->toString() << std::endl;
  }

  Thing* thing4 = new StringThing("ziemlich doof");
  // Thing* thing4 = new IntegerThing(8734);
  IntegerThing* thing5 = static_cast<IntegerThing*>(thing4);
  // IntegerThing* thing5 = dynamic_cast<IntegerThing*>(thing4);
  std::cout << std::endl;
  std::cout << "Adress of thing4: " << thing4 << std::endl;
  std::cout << "Adress of thing5: " << thing5 << std::endl;
  delete thing4;
}
