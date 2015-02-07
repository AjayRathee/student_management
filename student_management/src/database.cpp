/*
 * database.cpp
 *
 *  Created on: 07-Feb-2015
 *      Author: ajay
 */
#include "../include/database.h"
#include <sstream>

void database::create_data(int database = 0)
{
	int n;
	string field,line,file_name;

	switch(database)
	{
	case 0:
	{
		data.open ("database.csv");
		file_name="database.csv";
		cout<<"Enter the Number of Fields in the Database. Spaces are not allowed."<<endl;
			cin>>n;
			for(int i=0;i<n;i++)
			{
				cout<<"Enter field no "<<i+1<<endl;
				cin>>field;
				data<<field<<",";

			}
			data<<endl;
			data.close();
		break;
	}
	case 1:
	{
		data.open ("subjects.csv");
		file_name="subjects.csv";
		break;
	}
	case 2:
	{
		data.open ("marks.csv");
		file_name="marks.csv";
		break;
	}
	default:
		cout<<"Wrong options"<<endl;
		break;
	}
	//, ios::out | ios::ate | ios::app) ;


	ifstream myfile ("database.csv");
	  if (myfile.is_open())
	  {
		cout<<"Database Header"<<endl;
	    while ( getline (myfile,line) )
	    {
	      cout << line << '\n';
	    }
	    myfile.close();
	  }

	  else cout << "Unable to open file "<<file_name<<endl;
}

void database::insert_data(int database = 0)
{
	string field,line,str,temp;

	switch(database)
	{
		case MAIN_DATABASE:
		{
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
					    data.open ("database.csv", ios::out | ios::ate | ios::app) ;
					  }

			else cout << "Unable to open file";
			break;
		}
		case SUBJECTS_DATABASE:
		{
			data.open ("subjects.csv", ios::out | ios::ate | ios::app) ;
			cout<<"Enter Your Entry Number" <<endl;
			cin>>temp;
			str=str+temp+",";
			do
			{
				cout<<"Enter Subject, Press X when done" <<endl;
				cin>>temp;
				str=str+temp+",";
			}while(temp!="X");

			break;
		}
		case MARKS_DATABASE:
		{
			data.open ("marks.csv", ios::out | ios::ate | ios::app) ;
			ifstream myfile ("subjects.csv");
			cout<<"Enter Your Entry Number" <<endl;
			cin>>temp;
			str=str+temp+",";
			if (myfile.is_open())
			{
				getline(myfile,line);
				istringstream ss(line);
				int s=0;
				while(getline(ss,field,','))
				{
					if(s)
					{
						cout<<"Enter Marks for "<<field<<":";
						cin>>temp;
						str=str+temp+",";
					}
					s=1;
				}
			}
						myfile.close();
			break;
		}
		default:
			cout<<"Wrong options"<<endl;
			break;
	}


	data<<str;
	data.close();
	cout<<"insert_data"<<field_header.size()<<endl;
	for (unsigned i=0; i<field_header.size(); ++i) {
	        cout << field_header.at( i ) << " ";
	    }
}

void database::edit_field(string str,int n)
{

}
