#ifndef __MYPARSER_H__
#define __MYPARSER_H__

#include "MyArray.h"

MyArray ParseArgs(size_t argc, char *argv[]) {
    MyArray arr(5);
    arr.Add(10);
    arr.Add(30);
    arr.Add(20);
    arr.Add(1);
    arr.Add(10);
    arr.Add(2);
    arr.Add(10);
    arr.Add(3);
    arr.Add(10);
    arr.Add(4);
    arr.Add(12);
    arr.Add(120);
    arr.Add(5);
    return arr;
}

#endif // __MYPARSER_H__