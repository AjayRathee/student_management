/*
 * main.cpp
 *
 *  Created on: 06-Feb-2015
 *      Author: ajay
 */
#include "../include/reg.h"
#include "../include/database.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <iterator>

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;



int main()
{
	//char c;
	  int x;
	  string s,s1;
	  //int cid;
	  //int siz;

  student st;
  database dat;
  cout<<"****************************************LOGIN********************************************\n";
cout<<"Enter 1 for Login and 2 for Creating a new account\n";
cin>>x;
system("clear");
//existing user
if (x==1)
{
   //dat.create_data(MARKS_DATABASE);
	dat.insert_data(MARKS_DATABASE);
}
//new user
else if(x==2)
{
	st.reg();

}
else
{
	cout<<"Invalid option.\nTry again\n";
}
 return 0;
}



