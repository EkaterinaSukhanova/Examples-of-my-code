#ifndef MASS_OF_STR_HPP
#define MASS_OF_STR_HPP
#include <fstream>
#include <iostream>
using namespace std;

class mass_of_str
{
public:
    mass_of_str(size_t size, istream &file);
    mass_of_str(mass_of_str &mass2);
    void print();
    void print_number_str(int i);
    ~mass_of_str();
    void concatenation(mass_of_str &mass2);
    void merger_and_finding_repeat(mass_of_str &mass2);
    void sort();
private:
    char** str;
    size_t size;
};

int counting_number_of_str(istream &file);
void merger_sort_print(mass_of_str &mass1, mass_of_str &mass2);
#endif
