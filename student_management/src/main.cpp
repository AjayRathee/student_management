/*
 * main.cpp
 *
 *  Created on: 06-Feb-2015
 *      Author: ajay
 */
#include "../include/reg.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>

int main()
{
	//char c;
	  int x;
	  //int cid;
	  //int siz;

  student st;

  cout<<"****************************************LOGIN********************************************\n";
cout<<"Enter 1 for Login and 2 for Creating a new account\n";
cin>>x;
system("clear");
//existing user
if (x==1)
{

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



