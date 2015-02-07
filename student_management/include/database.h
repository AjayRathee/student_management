/*
 * database.h
 *
 *  Created on: 06-Feb-2015
 *      Author: ajay
 */

#ifndef INCLUDE_DATABASE_H_
#define INCLUDE_DATABASE_H_

#include <fstream>
#include <iostream>
#include <vector>

#define MAIN_DATABASE 0
#define SUBJECTS_DATABASE 1
#define MARKS_DATABASE 2

using namespace std;
class database
{
	ofstream data;
	vector <string> field_header;
public:
	void insert_data(int database);
	void create_data(int database);
	void edit_field(string str,int n);
	void delete_field(string str,int n);
};


#endif /* INCLUDE_DATABASE_H_ */
