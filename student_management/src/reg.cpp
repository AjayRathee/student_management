/*
 /*
 * reg.cpp
 *
 *  Created on: 06-Feb-2015
 *      Author: krishna
 */
#include "../include/reg.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>

void student::reg()
{
	student st;
	ofstream det;
        ofstream acc;
	string s;
	acc.open ("account.csv", ios::out | ios::ate | ios::app) ;

	cout<<"Enter the Entry Number\n";
	cin>>st.entryno;
	cout<<"Enter your name\n";
	cin>>st.name;
	cout<<"Enter your DOB without any spaces in the format DDMMYYYY\n";
	cin>>st.DOB;
	s=st.DOB;

	cout<<"Enter your degree\n";
	cin>>st.degree;


	det.open ("login.csv", ios::out | ios::ate | ios::app) ;
	string s1,s2,s3;
	    cout << "Enter New Username: ";
	    cin >> s1;
	    cout << "Enter New Password: ";
	    cin >> s2;
	    cout << "Re-Enter Password: ";
	    cin >> s3;
	    if (s2==s3)
	 	{
			det << s1 <<","<<s2<< endl;

			acc<<st.entryno<<","<<st.name<<","<<st.DOB<<","<<st.degree<<endl;
			cout << "Account Created.Please proceed to the login page.\n";

		}
	    else
			cout << "Passwords does not match.Account creation failed\n";
det.close();
acc.close();

}



