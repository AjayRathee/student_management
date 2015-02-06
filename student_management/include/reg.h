/*
 * reg.h
 *
 *  Created on: 06-Feb-2015
 *      Author: ajay
 */

#ifndef INCLUDE_REG_H_
#define INCLUDE_REG_H_

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;


 class student
{
 public:
  char name[50];
 char entryno[12];
 char DOB[8];

char degree[6];
void log_det();
void reg();
};



#endif /* INCLUDE_REG_H_ */
