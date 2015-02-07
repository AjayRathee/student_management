/*
 * database.cpp
 *
 *  Created on: 07-Feb-2015
 *      Author: ajay
 */
#include "../include/database.h"
#include <sstream>

void database::create_data()
{
	int n;
	string field,line;
	cout<<"Enter the Number of Fields in the Database. Spaces are not allowed."<<endl;
	cin>>n;
	data.open ("database.csv");//, ios::out | ios::ate | ios::app) ;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter field no "<<i+1<<endl;
		cin>>field;
		data<<field<<",";

	}
	data<<endl;
	data.close();

	ifstream myfile ("database.csv");
	  if (myfile.is_open())
	  {
		//getline(myfile,line);
		  cout<<"Database Header"<<endl;
	    while ( getline (myfile,line) )
	    {
	      cout << line << '\n';
	    }
	    myfile.close();
	  }

	  else cout << "Unable to open file";
}

void database::insert_data()
{
	string field,line,str,temp;
	ifstream myfile ("database.csv");


		  if (myfile.is_open())
		  {
			getline(myfile,line);
			istringstream ss(line);
			while(getline(ss,field,','))
			{
				cout<<"Enter "<<field<<":";
				cin>>temp;
				field_header.push_back(temp);
				str=str+temp+",";
			}

		    myfile.close();
		  }

		  else cout << "Unable to open file";
	data.open ("database.csv", ios::out | ios::ate | ios::app) ;
	data<<str;
	data.close();
	cout<<"insert_data"<<field_header.size()<<endl;
	for (unsigned i=0; i<field_header.size(); ++i) {
	        cout << field_header.at( i ) << " ";
	    }
}
