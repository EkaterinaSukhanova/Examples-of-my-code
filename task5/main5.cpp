/*Вариант 5.
Разработать класс для «Массива строк». Написать несколько конструкторов, в том числе
конструктор копирования. Реализовать методы для поэлементной конкатенации двух
массивов, упорядочения строк в лексикографическом порядке, слияния двух массивов с
удалением повторяющихся строк, а также для вывода на экран всего массива и заданной
строки. Создать массив объектов и передавать объекты в функцию, которая выполняет
слияние объектов и для полученного объекта-результата производит лексикографическое
упорядочения строк.*/
#include <iostream>
#include <fstream>
#include <cstring>
#include "mass_of_str.hpp"
#define max_str_size 1000
using namespace std;

int main()
{
     ifstream in1("myfile.txt");
     if(!in1)
     {
          cout << "No file #1" <<"\n" ;
          return 1;
     }

     ifstream in2("myfile2.txt");
     if(!in2)
     {
          cout << "No file #2" <<"\n" ;
          return 1;
     }

     int number_of_str1 = counting_number_of_str(in1);
     int number_of_str2 = counting_number_of_str(in2);

     mass_of_str mass1(number_of_str1, in1);
     mass_of_str mass2(number_of_str2, in2);

     merger_sort_print(mass1, mass2);

     return 0;
}
