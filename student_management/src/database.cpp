/*
 * database.cpp
 *
 *  Created on: 07-Feb-2015
 *      Author: ajay
 */
#include "../include/database.h"
#include <sstream>
#include <boost/algorithm/string.hpp>

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
					if(s) //skip first entry "entryno"
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

int database::edit_field(string entry,string old_str,string new_str,int database)
{

	string field,line,str,temp;
	fstream myfile;
	ofstream tempfile;
	size_t found;

	switch(database)
	{
	case MAIN_DATABASE:
	{
		myfile.open("database.csv");
		tempfile.open("database.csv.tmp");

		if (!myfile.is_open()) cout<<"Could not open"<<myfile<<endl;
		if (!tempfile.is_open()) cout<<"Could not open"<<tempfile<<endl;

     break;
	}
	case SUBJECTS_DATABASE:
	{
		myfile.open("subjects.csv");
		tempfile.open("subjects.csv.tmp");

		if (!myfile.is_open()) cout<<"Could not open"<<myfile<<endl;
		if (!tempfile.is_open()) cout<<"Could not open"<<tempfile<<endl;

		break;
	}
	case MARKS_DATABASE:
	{
		myfile.open("marks.csv");
		tempfile.open("marks.csv.tmp");

		if (!myfile.is_open()) cout<<"Could not open"<<myfile<<endl;
		if (!tempfile.is_open()) cout<<"Could not open"<<tempfile<<endl;

		break;
	}

	}

	if (myfile.is_open())
	{
		while(getline(myfile,line))
		{
			found = line.find(entry);
			if(found!=string::npos) break;
			tempfile<<line<<endl;
		}
		if(found == string::npos)
		{
			cout <<"Entry No "<<entry<<" not found"<<endl;
			myfile.close();
			return -1;
		}
		else
		{

		    size_t pos = line.find(old_str);
			if(pos == string::npos)
				{
			  		cout <<"Entry "<<old_str<<" not found"<<endl;
			  		myfile.close();
			  		return -1;
			  	}
			else
			   {
					cout<<line.length()<<endl;
					size_t file_pos = myfile.tellp();
					cout<<file_pos<<endl;
					//myfile.seekp(file_pos-line.length()); // move the cursor back
					//cout<<myfile.tellp()<<endl;
					line.replace(pos,old_str.length(),new_str);
					cout<<"Edit file "<<line<<endl;
					tempfile<<line<<endl;
					while(getline(myfile,line))  tempfile<<line<<endl;

			   }
		tempfile.close();
		myfile.close();
		// ********** cleanup*********
        switch(database)
        {
        	case MAIN_DATABASE:
        		if(rename("database.csv.tmp","database.csv")) cout<<"Error Renaming"<<endl;
        		return -1;
        		break;
        	case SUBJECTS_DATABASE:
        	    if(rename("subjects.csv.tmp","subjects.csv")) cout<<"Error Renaming"<<endl;
        	    return -1;
        	    break;
        	case MARKS_DATABASE:
        	    if(rename("marks.csv.tmp","marks.csv")) cout<<"Error Renaming"<<endl;
        	    return -1;
        	    break;
        }

		}
	}
	return 0;
}

int database::search_field(string search,int database)
{
	string field,line,str,temp;
	ifstream myfile;
	size_t found;

	switch(database)
		{
		case MAIN_DATABASE:
		{
			myfile.open("database.csv");
			if (!myfile.is_open()) cout<<"Could not open"<<myfile<<endl;
			while(getline(myfile,line))
			{
				found = line.find(search);
				if(found!=string::npos) cout<<line<<endl;
			}
	     break;
		}
		case SUBJECTS_DATABASE:
		{
			myfile.open("subjects.csv");
			if (!myfile.is_open()) cout<<"Could not open"<<myfile<<endl;
			while(getline(myfile,line))
			{
				found = line.find(search);
				if(found!=string::npos) cout<<line<<endl;
			}
			break;
		}
		case MARKS_DATABASE:
		{
			myfile.open("marks.csv");
			if (!myfile.is_open()) cout<<"Could not open"<<myfile<<endl;
			while(getline(myfile,line))
			{
				found = line.find(search);
				if(found!=string::npos) cout<<line<<endl;
			}
			break;
		}

		}
	myfile.close();
	return 0;
}

int database::delete_field(string entry,string del_str,int database)
{

	string field,line,str,temp;
	fstream myfile;
	ofstream tempfile;
	size_t found;

	switch(database)
	{
	case MAIN_DATABASE:
	{
		cout<<"Sorry you are not allowed to delete entries in Main Database"<<endl;
		return -1;
     break;
	}
	case SUBJECTS_DATABASE:
	{
		myfile.open("subjects.csv");
		tempfile.open("subjects.csv.tmp");

		if (!myfile.is_open()) cout<<"Could not open"<<myfile<<endl;
		if (!tempfile.is_open()) cout<<"Could not open"<<tempfile<<endl;

		break;
	}
	case MARKS_DATABASE:
	{
		myfile.open("marks.csv");
		tempfile.open("marks.csv.tmp");

		if (!myfile.is_open()) cout<<"Could not open"<<myfile<<endl;
		if (!tempfile.is_open()) cout<<"Could not open"<<tempfile<<endl;

		break;
	}

	}

	if (myfile.is_open())
	{
		while(getline(myfile,line))
		{
			found = line.find(entry);
			if(found!=string::npos) break;
			tempfile<<line<<endl;
		}
		if(found == string::npos)
		{
			cout <<"Entry No "<<entry<<" not found"<<endl;
			myfile.close();
			return -1;
		}
		else
		{

		    size_t pos = line.find(del_str);
			if(pos == string::npos)
				{
			  		cout <<"Entry "<<del_str<<" not found"<<endl;
			  		myfile.close();
			  		return -1;
			  	}
			else
			   {
					cout<<line.length()<<endl;
					size_t file_pos = myfile.tellp();
					cout<<file_pos<<endl;
					//myfile.seekp(file_pos-line.length()); // move the cursor back
					//cout<<myfile.tellp()<<endl;
					line.replace(pos,del_str.length(),"#");
					cout<<"Edit file "<<line<<endl;
					tempfile<<line<<endl;
					while(getline(myfile,line))  tempfile<<line<<endl;

			   }
		tempfile.close();
		myfile.close();
		// ********** cleanup*********
        switch(database)
        {
        	case MAIN_DATABASE:

        		break;
        	case SUBJECTS_DATABASE:
        	    if(rename("subjects.csv.tmp","subjects.csv")) cout<<"Error Renaming"<<endl;
        	    return -1;
        	    break;
        	case MARKS_DATABASE:
        	    if(rename("marks.csv.tmp","marks.csv")) cout<<"Error Renaming"<<endl;
        	    return -1;
        	    break;
        }

		}
	}
	return 0;
}

int search_multi_field(string entry,string name,string dob,string dept,string degree)
{

	string field,line,str,temp;
		ifstream myfile;
		size_t found;

		if(!entry.compare("#"))
		{
			myfile.open("database.csv");
			if (!myfile.is_open()) cout<<"Could not open"<<myfile<<endl;
			cout<<"Results for Entry Number:"<<endl;
			while(getline(myfile,line))
			{
				found = line.find(entry);
				if(found!=string::npos) cout<<line<<endl;
			}
		}

		if(!name.compare("#"))
		{
			myfile.open("database.csv");
			if (!myfile.is_open()) cout<<"Could not open"<<myfile<<endl;
			cout<<"Results for Name:"<<endl;
			while(getline(myfile,line))
			{
				found = line.find(entry);
				if(found!=string::npos) cout<<line<<endl;
			}
		}

		if(!dob.compare("#"))
		{
			myfile.open("database.csv");
			if (!myfile.is_open()) cout<<"Could not open"<<myfile<<endl;
			cout<<"Results for D.O.B:"<<endl;
			while(getline(myfile,line))
			{
				found = line.find(entry);
				if(found!=string::npos) cout<<line<<endl;
			}
		}

		if(!dept.compare("#"))
		{
			myfile.open("database.csv");
			if (!myfile.is_open()) cout<<"Could not open"<<myfile<<endl;
			cout<<"Results for Department:"<<endl;
			while(getline(myfile,line))
			{
				found = line.find(entry);
				if(found!=string::npos) cout<<line<<endl;
			}
		}

		if(!degree.compare("#"))
		{
			myfile.open("database.csv");
			if (!myfile.is_open()) cout<<"Could not open"<<myfile<<endl;
			cout<<"Results for Degree:"<<endl;
			while(getline(myfile,line))
			{
				found = line.find(entry);
				if(found!=string::npos) cout<<line<<endl;
			}
		}
		myfile.close();
	return 0;
}
