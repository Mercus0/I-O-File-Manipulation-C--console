/*
File NameS:Assignment_1(Tesk_1_IO_FileManipulation)
Author	  :Yan_Naing_Soe
Email Address: yn453368@gmail.com
Assignment Number:1
Description:Program to perform file manipulation
Last Change:January 27,2023
*/


#include<iostream>		//for input/output string
#include<fstream>		//for using files
#include<string>		//for string type
#include<iomanip>		//for setw(set field width)
#include<iomanip>
using namespace std;	//for cin/cout functions

class Member							//define a member class(Base class)
{
	private:
		string MemberName, MemberID;	///class data 
	protected:							///	 for access 
		string MemberType;				///	   member's name,id,
		int CreditPoint;				///		type and credit point

	public:
		void Menu();
		void InputNewMember();			//add for new member
		void WriteRecord();				//assign member's data to the file
		void ModifiesDetails();			//edit member's details
		void DisplayMember();			//display all member's data

		virtual void display()				//base class to show inheritance
		{
			cout << "\nThere are three kinds of member."<<endl;
		}
}	m;					// A variable to call Member's class function

class Silver : public Member {		//derived Class(Inheritance the Member(base class)
public:
	void display() {
		cout << "1.Silver member is the normal member"<<endl;
	}
}S;

class Gold :public Silver {			//derived Class(Inheritance the Silver class)
public:
	void display() {
		cout << "2.Gold member is the VIP member." << endl;
	}
}G;

class Ordinary :public Gold {	//derived class (Inheritance the Gold class)
public:
	void display()
	{
		cout << "3.Ordinary member that have no credit point" << endl;
		cout << endl;
	}
}O;			

class polymorphism :public Member //class for output Polymorphism
{
public:
	void display()
	{
		cout << "This is polymorphism" << endl;
		cout << "\n";
	}
};

int main()								
{
	m.Menu();			//call the Menu() function from the Member's class
}   

void Member::Menu()		//For Menu page display
{
	int userinput;		//declear a variable
	
		system("cls");	//clear screen
		cout << "                         Main Menu                           " << endl;		///
		cout << "___________________________________________________________" << endl;			///	 
		cout << "\n-->Enter '1' to add a new member to the file." << endl;						///		
		cout << "\n-->Enter '2' to modifies the details of an existing membet." << endl;		/// Display Main Menu 
		cout << "\n-->Enter '3' to displays the member details form the file." << endl;			///		to the user
		cout << "\n-->Enter '4' to exit." << endl;												///
		cout << "\n__________________________________________________________" << endl;			///
		cin >> userinput;				//get the user's input

		switch (userinput)				//check the user input		
		{
			case 1:						//add new member
			{
				m.InputNewMember();		//go to the input new member function	
				m.WriteRecord();		//assign member's data to the file	
				break;					
			}

			case 2:						//modifies the member's details
			{
				m.ModifiesDetails();	//Call  the ModifiesDetails function
				break;
			}

			case 3:						//display member's detials
			{

				polymorphism poly;		//declear the function
				Member* menber;			//pointer to base class
				menber = &poly;			//store the data of polymorphism 
				

				m.DisplayMember();		//Call the DisplayMember function	

				m.display();			//output from base class(Member class)
				G.display();			//output from derived class(Gold class)
				S.display();			//output from derived class(Silver class)
				O.display();			//output form derived class(Ordinary class)

				menber->display();		//call member's display function

				system("pause");
				m.Menu();			//return to the main menu after displayed member's details
				break;
			}

			case 4:
			{
				exit(0);				//exit from the progream
			}

			default:					//For user's input invaiid 
			{	system("cls");			//clear the screen
				cout << "Wrong input!!...	Please choose again.\n";	
				system("pause");		//pause the system temporarily
				m.Menu();				//return to the main menu finally
			}
		}
}

void Member::WriteRecord()							   //write member's data to the file (function)
{
	char ch;										   //declear a char 
	
	ofstream myfile("MEMBER.txt", ios::app);		   //create Member.txt file

	if (myfile.is_open())							   //when Member.txt open
	{
		myfile << MemberName << " " << MemberID << " " << MemberType << " " << CreditPoint << endl;	//input data to 
		cout << "\nSuccessful Regristration.....THANK YOU" << endl;									// the Member.txt
		myfile.close();								  //close the Member.txt	
	}

	else											  //If Member.txt is not open
	{
		cout << "\nUnsuccessful Regristration...."<<endl;
	}		
	
		cout << "\nDo you want to add new member again.[y/n]" << endl; //ask the user to do or not[y/n]
		cin >> ch;									//get the userinput
		ch = tolower(ch);							//change to lower_case the userinput
		
		if (ch == 'y')								//if userinput "y"
		{
			m.InputNewMember();						//call the input new member function
			m.WriteRecord();						// and then assign to the file again
		}
		else if (ch == 'n') m.Menu();				//if user input "n" ,back to the main menu again
}

void Member::DisplayMember()						//display all member's details function
{
	system("cls");									//clear the screen				
	string line;									
	int i = 0;
	string array[4];								//declear array that have four room
	fstream ReadFile;					
	ReadFile.open("MEMBER.txt", ios::in | ios::out);//open file for reading and writing
	cout << "|             Member's List Table             |" << endl;///
	cout << left << setw(46) << setfill('-') << "-" << endl;		  ///
	cout << left << setw(4) << setfill(' ') << "NO";				  ///
	cout << left << setw(10) << setfill(' ') << "Name";				  ///Labels of Member's detail table
	cout << left << setw(10) << setfill(' ') << "Id";				  ///
	cout << left << setw(15) << setfill(' ') << "Member Type";		  ///
	cout << left << setw(10) << setfill(' ') << "Credit" << endl;
	cout << left << setw(46) << setfill('-') << "-" << endl;

	while (getline(ReadFile, line))					//get line form Member.txt
	{
		ofstream test("test.txt");					//create read test file
		test << line;
		test.close();

		fstream test1("test.txt", ios::in | ios::out); //create file to read and write
		if (test1.is_open())
		{
			for (int i = 0; i < 4; ++i)
			{
				test1 >> array[i];					//assign string to the array from file
			}
		}
		i = i + 1;
		cout << left << setw(4) << setfill(' ') << i;
		cout << left << setw(10) << setfill(' ') << array[0];
		cout << left << setw(10) << setfill(' ') << array[1];//assign a data to each array and display like a table
		cout << left << setw(15) << setfill(' ') << array[2];
		cout << left << setw(10) << setfill(' ') << array[3];
		cout << endl;
		cout << left << setw(46) << setfill('-') << "-" << endl;
		test1.close();
	}
	cout << "\t" << "\n***There are " << i << " members in the table List.***" << endl;//member's count
	cout << endl;
	ReadFile.close();
	//system("pause");
	getchar();
}

void Member::ModifiesDetails()		//edid member's details
{
	system("cls");
	m.DisplayMember();		//display member's details first
		string search,line1, myarray[4];
		char edit;	

		fstream infile("MEMBER.txt", ios::in | ios::out);	//call MEMBER.txt to read and write file

		infile.is_open();	//check whether MEMBER.txt is open

		if (!infile)		//if file is not open error return
		{
			cout << "Unable to open file" << endl;
			exit(1);
		}
		cout << "\nEnter the member's Id what you want to edit." << endl;	//ask the member Id to edit
		cin >> search;		//get member Id
		size_t pos;
		bool control=false;	
		while (infile.good())
		{
			getline(infile, line1);
			pos = line1.find(search);
			if (pos != string::npos)	//found member's Id
			{
				control= true;
				ofstream tempfile("file.txt");	//assign to the file,a string that is found 
				tempfile << line1;				//	in the file (Id search)
				tempfile.close();

				fstream showfile("file.txt", ios::in || ios::out);	//create file to show where Member's id found
				if (showfile.is_open())
				{
					for (int i = 0; i < 4; ++i)	//assign each data to each array
					{
						showfile >> myarray[i];
					}
				}

				cout << endl;
				cout << left << setw(10) << setfill(' ') << "Name";					//
				cout << left << setw(15) << setfill(' ') << "Member Type";			// Table's Labels
				cout << left << setw(10) << setfill(' ') << "Credit Points" << endl;//

				cout << left << setw(10) << setfill(' ') << myarray[0];				//
				cout << left << setw(15) << setfill(' ') << myarray[2];				//show data
				cout << left << setw(10) << setfill(' ') << myarray[3];				//
				cout << endl;

				cout << "\nWhat do you want do edit?" << endl;		//
				cout << "\t*'n' For member's name." << endl;		//Ask the user 
				cout << "\t*'t' For member's type." << endl;	    //	to edit(name or type 
				cout << "\t*'c' For member's credit point" << endl; //		or credit point)

				cin >> edit;  edit = tolower(edit);					//get the input(n,t,c)
				switch (edit)										//check the user input
				{
				case 'n':			//edit name
				{
					fstream newfile("file.txt", ios::in | ios::out);

					if (newfile.is_open())
					{
						for (int i = 0; i < 4; ++i)
						{
							newfile >> myarray[i];	//add the string from the file to the array
						}
					}

					newfile.close();

					fstream newfile2("file.txt", ios::in | ios::out);
					cout << "Enter the new member name : ";		cin >> myarray[0];	//get the new member name

					cout << endl;
					cout << left << setw(10) << setfill(' ') << "Name";				//Member table label
					cout << left << setw(15) << setfill(' ') << "Member Type";			
					cout << left << setw(10) << setfill(' ') << "Credit Points" << endl;

					cout << left << setw(10) << setfill(' ') << myarray[0];			//show the edited string
					cout << left << setw(15) << setfill(' ') << myarray[2];
					cout << left << setw(10) << setfill(' ') << myarray[3];
					cout << endl;

					newfile2 << myarray[0] << " " << myarray[1] << " " << myarray[2] << " " << myarray[3];	
							//add edited array to the file
					newfile2.close();
					infile.close();
					break;
				}

				case 't':	//edit member type
				{
					fstream newfile("file.txt", ios::in | ios::out);

					if (newfile.is_open())
					{
						for (int i = 0; i < 4; ++i)
						{
							newfile >> myarray[i];	//add the string from the file to the array
						}
					}

					newfile.close();

					fstream newfile2("file.txt", ios::in | ios::out);
					cout << "Enter the new Member's type : ";		cin >> myarray[2];//get the new member type

					cout << endl;
					cout << left << setw(10) << setfill(' ') << "Name";				  //Member table label
					cout << left << setw(15) << setfill(' ') << "Member Type";
					cout << left << setw(10) << setfill(' ') << "Credit Points" << endl;

					cout << left << setw(10) << setfill(' ') << myarray[0];			  //get the new member type
					cout << left << setw(15) << setfill(' ') << myarray[2];
					cout << left << setw(10) << setfill(' ') << myarray[3];
					cout << endl;

					newfile2 << myarray[0] << " " << myarray[1] << " " << myarray[2] << " " << myarray[3];
					//add edited array to the file
					newfile2.close();
					infile.close();
					break;
				}

				case 'c':	//edit credit point
				{
					fstream newfile("file.txt", ios::in | ios::out);

					if (newfile.is_open())
					{
						for (int i = 0; i < 4; ++i)
						{
							newfile >> myarray[i];	//add the string from the file to the array
						}
					}

					newfile.close();

					fstream newfile2("file.txt", ios::in | ios::out);
					cout << "Enter the new Credit point : ";	cin >> myarray[3];	//get the new member type	

					cout << endl;
					cout << left << setw(10) << setfill(' ') << "Name";				//get the new member type
					cout << left << setw(15) << setfill(' ') << "Member Type";
					cout << left << setw(10) << setfill(' ') << "Credit Points" << endl;

					if (myarray[3] == "0")		//check credit point is zero
					{
						myarray[2] = "Ordinary";	//if zero change to member type to Ordinary
					}
					cout << left << setw(10) << setfill(' ') << myarray[0];			////get the new member type
					cout << left << setw(15) << setfill(' ') << myarray[2];
					cout << left << setw(10) << setfill(' ') << myarray[3];
					cout << endl;

					newfile2 << myarray[0] << " " << myarray[1] << " " << myarray[2] << " " << myarray[3];	
					//add edited array to the file
					newfile2.close();
					infile.close();
					break;
				}

				}
				ifstream file;
				ofstream outfile;
				ofstream newfile;
				string linen;
				file.open("MEMBER.txt");	
				outfile.open("news.txt");	//create news file 

				while (getline(file, linen))
				{
					if ((linen.find(search, 0)) == string::npos)	//assign data to the file except the same string
						outfile << linen << "\n";
				}
				outfile.close();
				file.close();
				remove("MEMBER.txt");			 //remove file
				rename("news.txt", "MEMBER.txt");//rename file

				newfile.open("MEMBER.txt", ios::app);
				newfile << myarray[0] << " " << myarray[1] << " " << myarray[2] << " " << myarray[3];	
				//add new string to the file
				cout << "\nSuccessful edit...\n";
				newfile.close();
				system("pause");
				m.DisplayMember();
				
			}
		}if (control == false)					//if Member's ID not found
		{
			cout << "Member ID not found...Please Choose again"<<endl;
			system("pause");
			m.ModifiesDetails();
		}
		m.Menu();
}

void Member::InputNewMember()					//derived class for input new member
	{
		int choose;
		m.CreditPoint = 0;
		system("cls");

		cout << "\nWelcome......	\n";
		cout << "Please enter the new member name.\n";	cin >> MemberName;	//get member-name
		cout << "\nPlease enter the Member's ID.\n";	cin >> MemberID;	//get member-id

		do {
			cout << "\nPlease choose the Member-type.\n";
			cout << "\t(1) For Gold Member\n" <<
				"\t(2) For Silver Member\n" <<
				"\t(3) For Oridinary Member\n" << endl;   cin >> choose;		//get member type

			switch (choose)							//check the member type
			{
			case 1:								//gold member
			{
				MemberType = "Gold";
				cout << "You are Gold Member" << endl;
				break;
			}

			case 2:								//silver member
			{
				MemberType = "Silver";
				cout << "You are Silver Member" << endl;;
				break;
			}

			case 3:								//oridernary member
			{
				MemberType = "Ordinary";
				cout << "You are Ordinary member,that member has no credit point." << endl;
				break;
			}

			default:							//wrong input
			{
				cout << endl << choose << " don't exit.Please choose correctly members types.\n";	//valid member
				cout << endl;
				break;
			}

			}
		} while (choose != 1 && choose != 2 && choose != 3);			//loop until correct member type

		if (choose == 1 || choose == 2)									//if member type correct/get credit point
		{


			cout << "\nPlease enter the Credit point" << endl;
			cin >> CreditPoint;
		}
	}
	

