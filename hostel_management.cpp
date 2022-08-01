#include <iostream> 
#include<conio.h>
#include <sqlite3.h> 
#include<windows.h>
#include<string>
#include<iomanip>
#include<cstring>

using namespace std;
int choice;
int path;
int oauth;
string title;
string usern, ussern,passn,pasn,email;
static int  callback(void* data, int argc, char** argv, char** azColName)
	{
		char k;
		int chook = std::stoi((const char*)data);
		if (chook)
		{
			switch (chook)
			{
			case 1:
			case 2:
			case 3:
			case 4:
				for (int i = 0; i < argc; i++) {

					if (passn == argv[i])
					{
						//cout << "SucessESS" << endl;
						//getchar();
						//ussern = usern;
						return 0;
						break;
					}
					else {
						//cout << "error!!";
						return 1;
					}
				}
			}
		}
		else
		{
			cout << endl;
			for (int i = 0; i < argc; i++)
			{
				cout << setw(20) << azColName[i] << setw(10);
				cout << "|";
				cout << " " << argv[i] ? argv[i] : "NULL";

				cout << "\n";
			}
			cout << endl;
			return 0;
		}
	}
class director {
public:
	string firstname, lastname,sq,sql;
    int exit = 0,ID;
	sqlite3* DB;
	char* messageError; 
	 
	void deleteRecord(int choic,int select);
	int disp_homepage();
	void disp_director_options();
	void insertt(int choic,int select);
	void displayAll(int choic, int select);
	void single_record(int choic, int select);
	void message();
	void modify_record(int choic,int select);
	void login(int auth);
	void disp_options();
	void display_attendants();
	void disp_attendants_options();
	void programEntry(int choic);
};
class admin :public director {
public:
	
	void complaints();
	
	
};
int director::disp_homepage()//displays the message on level 1
{
	system("color 02");//sets the background colour as black and text colour as light green
	cout << '\t' << '\t' << '\t';
	for (int i = 0; i <= 59; i++)
		cout << "-";
	Sleep(100);
	cout << endl;
	cout << '\t' << '\t' << '\t' << '\t' << " WELCOME TO QUAD MASTERS ACCOMODATION SYSTEM " << endl;
	Sleep(100);
	cout << '\t' << '\t' << '\t';
	for (int i = 0; i <= 59; i++)
		cout << "-";
	Sleep(100);

	cout << endl << endl;

	//sign in options
	cout << '\t' << '\t' << '\t' << "To continue sign in as: " << endl << endl;
	Sleep(100);
	cout << '\t' << '\t' << '\t' << '\t' << "1.DIRECTOR" << endl;
	Sleep(100);
	cout << '\t' << '\t' << '\t' << '\t' << "2.ADMINSTRATOR" << endl;
	Sleep(100);
	cout << '\t' << '\t' << '\t' << '\t' << "3.STUDENT" << endl;
	Sleep(100);
	cout << '\t' << '\t' << '\t' << '\t' << "4.HOSTEL ATTEDANT" << endl;
	Sleep(100);
	cout << '\t' << '\t' << '\t' << '\t' << "5.EXIT" << endl << endl;
	Sleep(100);
	cout << '\t' << '\t' << '\t' << "sign in as 1 2 3 or 4:  ";
	cin >> choice;
	Sleep(100);
	cin.get();
	//login(choice);
	return choice;
}
void director::disp_director_options()
{
	int choose;
	while (1)
	{
		// message();
		cout << '\t' << '\t' << '\t' << "1.Add new admins..." << endl;
		Sleep(100);
		cout << '\t' << '\t' << '\t' << "2.Display details of all admins..." << endl;
		Sleep(100);
		cout << '\t' << '\t' << '\t' << "3.Display a single admin record..." << endl;
		Sleep(100);
		cout << '\t' << '\t' << '\t' << "4.Modify admins record..." << endl;
		Sleep(100);
		cout << '\t' << '\t' << '\t' << "5.Delete admins record..." << endl;
		Sleep(100);
		cout << '\t' << '\t' << '\t' << "6.Display hostels available..." << endl;
		Sleep(100);
		cout << '\t' << '\t' << '\t' << "7.Allocate students hostel..." << endl;
		Sleep(100);
		cout << '\t' << '\t' << '\t' << "8.Logout..." << endl;
		Sleep(100);
		cout << '\t' << '\t' << "Enter any one of the above choice: ";
		cin >> choose;
		cout << endl;
		getchar();
		system("cls");
		message();
		cin.get();
		if (choose == 1 || choose == 2 || choose == 3 || choose == 4 || choose == 5 || choose == 6 || choose == 7 || choose == 8)
		{
			switch (choose)
			{
			case 1:
				
				insertt(choice,path);
				getchar();
				system("cls");

				break;
			case 2:

				displayAll(choice, path);
				getchar();
				system("cls");
				break;
			case 3:
				single_record(choice, path);
					getchar();
				system("cls");
				break;
			case 4:
				modify_record(choice,path);
				break;
			case 5:

				deleteRecord(choice,path);
				break;
			case 6:

				//edit.hostel_list();
				getchar();
				system("cls");

				break;
			case 7:

				//hom.AllocateStudents();
				//hom.SuccessfulApplicants();
				getchar();
				system("cls");
				break;
			case 8:
				system("cls");
				disp_homepage();
				//edit.login(choice);

				break;
			}
		}
	}
}
void director::disp_options()
{
	while (1)
	{
		int choose,opt;
		//message();cout << "Enter details(students/attendants)"<<endl;

		cout << '\t' << '\t' << '\t' << "1.Students options " << endl;
		Sleep(100);
		cout << '\t' << '\t' << '\t' << "2.Attendants options" << endl;
		Sleep(100);
		cout << '\t' << '\t' << '\t' << "3.Logout..." << endl;
		Sleep(100);


		
		
		cout << endl << endl << '\t' << '\t' << "Enter your choice: ";
		cin >> choose;

		getchar();
		system("cls");

		if (choose == 1 || choose == 2 || choose == 3)
		{
			
			switch (choose)
			{
			case 1:

				while (1)
				{
					message();
					path = 1;
					cout << '\t' << '\t' << '\t' << "1.Add new student..." << endl;
					Sleep(100);
					cout << '\t' << '\t' << '\t' << "2.Display details of all students..." << endl;
					Sleep(100);
					cout << '\t' << '\t' << '\t' << "3.Display a single record of a student..." << endl;
					Sleep(100);
					cout << '\t' << '\t' << '\t' << "4.Display hostels available..." << endl;
					Sleep(100);
					cout << '\t' << '\t' << '\t' << "5.Modify a record..." << endl;
					Sleep(100);
					cout << '\t' << '\t' << '\t' << "6.Delete a record..." << endl;
					Sleep(100);
					cout << '\t' << '\t' << '\t' << "7.Back..." << endl;
					Sleep(100);
					cout << endl << endl << '\t' << '\t' << "Enter your choice: ";
					cin >> opt;
					getchar();
					system("cls");
					switch (opt)
					{
					case 1:
						message();
						insertt(choice,path);
						break;
					case 2:
						message();
						displayAll(choice, path);
						break;
					case 3:
						message();
						single_record(choice,path);
						break;
					case 5:
						modify_record(choice, path);
						break;
					case 6:
						message();
						deleteRecord(choice,path);
						break;
					case 7:
						break;
					default:
						cout << '\t' << '\t' << '\t' << "Invalid option,try again" << endl;
					}
					if (opt == 7)
						break;
					getchar();
					getchar();
					system("cls");
				}

				//message();
				//add_details();
				break;
			case 2:
				while (1) {
					path = 2;
					cout << '\t' << '\t' << '\t' << "1.Add new attendant..." << endl;
					Sleep(100);
					cout << '\t' << '\t' << '\t' << "2.Display details of all attedants..." << endl;
					Sleep(100);
					cout << '\t' << '\t' << '\t' << "3.Display a single record of an attendant..." << endl;
					Sleep(100);
					cout << '\t' << '\t' << '\t' << "4.Modify a record..." << endl;
					Sleep(100);
					cout << '\t' << '\t' << '\t' << "5.Delete a record..." << endl;
					Sleep(100);
					cout << '\t' << '\t' << '\t' << "6.Back..." << endl;
					Sleep(100);
					cout << endl << endl << '\t' << '\t' << "Enter your choice: ";
					cin >> opt;
					getchar();
					system("cls");
					switch (opt) {
					case 1:
						insertt(choice, path);
						break;
					case 2:
						displayAll(choice, path);
						break;
					case 3:
						single_record(choice, path);
						break;
					case 4:
						modify_record(choice, path);
						break;
					case 5:
						deleteRecord(choice, path);
						break;
					case 6:
						break;
					default:
						cout << '\t' << '\t' << '\t' << "Invalid option,try again" << endl;
					}
					if (opt == 6)
						break;
					//message();
					//SuccessfulApplicants();//displasys details of all students
					system("pause");
					system("cls");//clears whats on screen before displaying options
				}
				break;
			case 3:
				cout << endl << '\t' << '\t' << '\t' << "THANK YOU WE VALUE YOU!!" << endl << '\t' << '\t' << '\t' << '\t' << "WELCOME AGAIN!!" << endl;
				getchar();
				disp_homepage();
				break;
		
			default:
				cout << endl << '\t' << '\t' << '\t' << "INVALID OPTION,ENTER THE CORRECT OPTION!!" << endl << endl;
			}
		}
		else
			continue;
		getchar();
	}
}
void director::deleteRecord(int choic,int select)
{
	string sql, adminId, regNo;
	sqlite3_open("QUAD.db", &DB);
	switch (choic)
	{
	case 1:
		cout << "\t" << "\t" << "\t" << "Enter the ID of the record you want to delete: ";
		cin >> adminId;

		sql = "DELETE FROM ADMINS  WHERE ID='" + adminId + "';";
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);//routine to execute delete query
		goto message;
		break;
	case 2:
		switch (select)
		{
		case 1:
			cout << "\t" << "\t" << "\t" << "Enter the REGNO of the record you want to delete: ";
			cin >> regNo;

			sql = "DELETE FROM STUDENTS  WHERE ID ='" + regNo + "';";
			exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);//routine to execute delete query
			goto message;
			break;
		case 2:
			cout << "\t" << "\t" << "\t" << "Enter the ID of the record you want to delete: ";
			cin >> adminId;

			sql = "DELETE FROM ATTENDANTS  WHERE ID='" + adminId + "';";
			exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);//routine to execute delete query
			goto message;
			break;
		}
		break;
	message:
		{
			if (exit != SQLITE_OK)
			{
				cerr << "RECORD NOT DELETED" << endl;
				sqlite3_free(messageError);
			}
			else
				cout << "RECORD DELETED SUCCESSFULLY!!" << endl;
		}

	}
	getchar();
	sqlite3_close(DB);
}
int main()
{
	director hom;
	admin hom1;
	hom.disp_homepage();
	hom.programEntry(choice);
    return (0);
}
void director::insertt(int choic,int select) {
	string firstname,lastname, password,sql,admNo,gender,address;
	int ID,age;
	
	int roomno;
	string fname, lname, hostname, choise, mashida,  regno;
	
	int exit;
	const char* data = "0";
	sqlite3_open("QUAD.db", &DB);
	switch (choic)
	{
	case 1:
		cout << "Enter firstname: ";
		cin >> firstname;
		cout << "Enter lastname: ";
		cin >> lastname;
		cout << "Enter national ID: ";
		cin >> ID;
		sql = "INSERT INTO ADMINS VALUES('" + to_string(ID) + "','" + firstname + "','" + lastname + "',LOWER('" + lastname + "." + firstname + ".director.quad.ke')) ;";
		exit = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data, &messageError);//routine to execute delete query
		goto message;
		break;

	case 2:

		switch (select) {
		case 1:

			cout << "Enter firstname: ";
			cin >> firstname;
			cout << "Enter lastname: ";
			cin >> lastname;
			cout << "Enter DEGREE ID: ";
			cin >> ID;
			cout << "Enter admission number: ";
			cin >> admNo;
			cout << "enter age: ";
			cin >> age;
			cout << "enter gender: ";
			cin >> gender;
			cout << "enter address: ";
			cin >> address;
			sql = "INSERT INTO STUDENTS VALUES('" + to_string(ID) + "','" + admNo + "','" + firstname + "','" + lastname + "','" + to_string(age) + "','" + gender + "','" + address + "',LOWER('" + lastname + "." + firstname + ".students.quad.ke')) ;";
			exit = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data, &messageError);//routine to execute delete query
			goto message;
			break;
		case 2:
			cout << "Enter firstname: ";
			cin >> firstname;
			cout << "Enter lastname: ";
			cin >> lastname;
			cout << "Enter national ID: ";
			cin >> ID;
			sql = "INSERT INTO ATTENDANTS VALUES('" + to_string(ID) + "','" + firstname + "','" + lastname + "',LOWER('" + lastname + "." + firstname + ".attendants.quad.ke')) ;";
			exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);//routine to execute delete query
			sql = "SELECT *FROM ATTENDANTS WHERE ID='" + to_string(ID) + "';";
			exit = sqlite3_exec(DB, sql.c_str(), callback, (void*)data, &messageError);
			goto message;
			break;
		}
		break;
	case 3:
		cout << "   COMPLAINS SECTION        ";
		cout << endl << endl << '\t' << '\t' << '\t' << "Enter your  first name: ";
		cin >> fname;
		cout << endl << endl << '\t' << '\t' << '\t' << "Enter your  last name : ";
		cin >> lname;
		cout << '\t' << '\t' << '\t'  << "Enter your registration number: ";
		cin >> regno;
		cout << '\t' << '\t' << '\t' << "input your hostel name: ";
		cin >> hostname,
		cout << '\t' << '\t' << '\t' << "input your room number: ";
		cin >> roomno;
		cout << '\t' << '\t' << '\t' << "categorize your complaint into either;" << endl;
		cout << '\t' << '\t' << '\t' <<"> an electric issue"<<endl;
		cout << '\t' << '\t' << '\t' << ">hygiene issue" << endl;
		cout << '\t' << '\t' << '\t' << ">carpentry issue "<<endl;
		cin >> choise;
		cin.ignore();
		cout << '\t' << '\t' << '\t' << "pass your complaint to us, will do our best to work on it soonest,";
		getline(cin, mashida);

		//sql = "INSERT INTO MINEE VALUES('" + fname + "','" + lname + "','" + regno + "','" + hostname + "','" + to_string(roomno) + "','" + choise + "','" + mashida + "');";
		sql = "INSERT INTO STUDENTS_COMPLAINS_LIST VALUES('" + fname + "','" + lname + "','" + regno + "','" + hostname + "','" + to_string(roomno) + "','" + choise + "','" + mashida + "');";
		exit = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data, &messageError);//routine to execute delete query
		sql = "SELECT *FROM STUDENTS_COMPLAINS_LIST WHERE ID='" + regno + "';";
		exit = sqlite3_exec(DB, sql.c_str(), callback, (void*)data, &messageError);
		if (exit != SQLITE_OK)
		{
			cerr << "COMPLAIN NOT ADDED!!" << endl;
			sqlite3_free(messageError);
		}
		else
			cout << endl << "we have received your complain,working on it" << endl;
		cout << endl;
		break;


	message:
		{
			if (exit != SQLITE_OK)
			{
				cerr << "RECORD NOT ADDED!!" << endl;
				sqlite3_free(messageError);
			}
			else
				cout << "RECORD ADDED SUCCESSFULLY!!" << endl;
		}
	}
	sqlite3_close(DB);
}
void director::displayAll(int choic, int select) {
	int exit=0;
	string sql;
	const char* data = "0";
	sqlite3_open("QUAD.db", &DB);

	switch (choic)
	{
	case 1:
		sql = "SELECT *FROM ADMINS;";
		exit = sqlite3_exec(DB, sql.c_str(), callback, (void*)data, &messageError);

		goto message;
		break;
	case 2:
		switch (select)
		{
		case 1:
				sql = "SELECT *FROM STUDENTS;";
				exit = sqlite3_exec(DB, sql.c_str(), callback, (void*)data, &messageError);
				goto message;
			break;
		case 2:
			sql = "SELECT *FROM ATTENDANTS;";
			exit = sqlite3_exec(DB, sql.c_str(), callback, (void*)data, &messageError);
			goto message;
			break;
		}
		break;
	case 4:
		sql = "SELECT *FROM STUDENTS_COMPLAINS_LIST;";
		exit = sqlite3_exec(DB, sql.c_str(), callback, (void*)data, &messageError);
		goto message;
		break;
	}

	//exit = sqlite3_exec(DB, sql.c_str, callback, 0, &messageError);
message:
	{
	if (exit != SQLITE_OK)
	{
		cerr << "ERROR TO FETCH THE RECORD!!" << endl;
		sqlite3_free(messageError);
	}
	}
}
void director::single_record(int choic, int select)
{
	string sql,ID;
	sqlite3_open("QUAD.db", &DB);
	switch (choic) {
	case 1:
		cout << "Enter the id of the person you want to display:";
		cin >> ID;
		sql = "SELECT *FROM ADMINS WHERE ID='" + ID + "';";
		exit = sqlite3_exec(DB, sql.c_str(), callback, 0, &messageError);
		break;
	case 2:
		switch (select)
		{
		case 1:
			cout << "Enter the students reg no of the person you want to display:";
			cin >> ID;
			sql = "SELECT *FROM STUDENTS WHERE ID='" + ID + "';";
			exit = sqlite3_exec(DB, sql.c_str(), callback, 0, &messageError);
			break;
		case 2:
			cout << "Enter the id of the person you want to display:";
			cin >> ID;
			sql = "SELECT *FROM ATTENDANTS WHERE ID='" + ID + "';";
			exit = sqlite3_exec(DB, sql.c_str(), callback, 0, &messageError);
			break;
		}


	case 4:
		cout << "Enter the id of the person with an issue: ";
		cin >> ID;
		sql = "SELECT *FROM STUDENTS_COMPLAINS_LIST WHERE ID='" + ID + "';";
		exit = sqlite3_exec(DB, sql.c_str(), callback, 0, &messageError);
		break;
		break;
	}
	if (exit != SQLITE_OK)
	{
		cerr << "RECORD NOT FOUND!!" << endl;
		sqlite3_free(messageError);
	}
	
	sqlite3_close(DB);
}
void director::message()
{
	system("cls");
	cout << setw(25);
	for (int i = 0; i <= 59; i++)
		cout << "-";
	Sleep(100);
	cout << endl;
	cout << setw(65) << " HOSTEL MANAGEMENT SYSTEM " << endl;
	Sleep(100);
	cout << setw(25);
	for (int i = 0; i <= 59; i++)
		cout << "-";
	Sleep(100);
	cout << endl;
	cout << endl << setw(30) << "WELCOME "  << email;
	Sleep(100);
	cout << setw(50) << "You signed in as: " << title << endl << endl;
	Sleep(100);
	cout << endl << endl;

}
void director::display_attendants()
{
	cout << '\t' << '\t' << '\t' << "1." << endl;
	Sleep(100);
}
void admin:: complaints() {
	int roomno ;
	string fname ,lname ,hostname,choise,mashida,sql,regno;
	int exit;

	exit=sqlite3_open("QUAD.db",&DB);
	cout << "   COMPLAINS SECTION        ";
	cout << endl << endl << '\t' << '\t' << '\t' << "Enter your  first name(as you registred with) : ";
	cin >> fname;
	cout << endl << endl << '\t' << '\t' << '\t' << "Enter your  last name(as you registred with) : ";
	cin >> lname;
	cout << '\t' << '\t' << '\t' << "Enter your registration number: ";
	cin >> regno;
	cout << "input your hostel name: ";
	cin>>hostname,
	cout << "input your room number: ";
	cin >> roomno;
	cout << "categorize your complaint into either an electric issue, hygiene issue, carpentry issue or others:";
	cin >> choise;
	cout << "pass your complaint to us, will do our best to work on it soonest,";
	cin >> mashida;

	//sql = "INSERT INTO MINEE VALUES('" + fname + "','" + lname + "','" + regno + "','" + hostname + "','" + to_string(roomno) + "','" + choise + "','" + mashida + "');";
	sql = "INSERT INTO MINEE VALUES('" + fname + "','" + lname + "','" + regno + "','" + hostname + "','" + to_string(roomno) + "','" + choise + "','" + mashida + "';)";
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);//routine to execute delete query

	if (exit != SQLITE_OK)
	{
		cerr << "COMPLAIN NOT ADDED!!" << endl;
		sqlite3_free(messageError);
	}
	else
	cout << endl << "we have received your complain,working on it" << endl;
	cout << endl;
	sqlite3_close(DB);
}
void director::disp_attendants_options()
{
	 int choic1;
	 while (1) {
		 cout << endl << endl << '\t' << '\t' << '\t' << "1.Display a single task.... ";
		 Sleep(100);
		 cout << endl << endl << '\t' << '\t' << '\t' << "2.Display all tasks.... ";
		 Sleep(100);
		 cout << endl << endl << '\t' << '\t' << '\t' << "3.Logout.... ";
		 Sleep(100);
		 cout << endl << endl << '\t' << '\t' << '\t' << "Enter your choice: ";
		 cin >> choic1;
		 switch (choic1)
		 {
		 case 1:
			 single_record(choice, path);
			 getchar();
			 getchar();
			 system("cls");
			 break;
		 case 2:
			 displayAll(choice, path);
			 getchar();
			 getchar();
			 system("cls");
			 break;
		 case 3:
			 system("cls");
			 disp_homepage();
			 break;
		 default:
			 cout << endl << '\t' << '\t' << '\t' << "Invalid option!!" << endl;
		 }
		
	 }
}
void director::modify_record(int choic,int select) {
	string ID,sql,lastname,firstname,admNo,gender,address;
	static string ID1;
	int exit,age;
	sqlite3_open("QUAD.db", &DB);
	
	switch (choic)
	{
	case 1:
		cout << "\t" << "\t" << "\t" << "Enter the ID(national ID) of the record you want to modify: ";
	    cin >> ID;
		sql = "SELECT *FROM ADMINS WHERE ID='" + ID + "';";
		exit = sqlite3_exec(DB, sql.c_str(), callback, 0, &messageError);

		cout << endl << endl << "\t" << "\t" << "\t" << "Enter new details.... ";
		cout  << endl << "\t" << "\t" << "\t" << "Enter firstname: ";
		cin >> firstname;//
		cout << "\t" << "\t" << "\t" << "Enter lastname: ";
		cin >> lastname;
		cout << "\t" << "\t" << "\t" << "Enter national ID: ";
		cin >> ID1;
		
			sql = "UPDATE ADMINS SET FIRSTNAME =UPPER('" + firstname + "'),LASTNAME=UPPER('" + lastname + "'),ID='" + ID + "',EMAIL=LOWER('" + lastname + "." + firstname + ".quad.ke') WHERE ADMIN_ID ='" + ID + "'";
			exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);//routine to execute delete query

			sql = "SELECT *FROM ADMINS  WHERE ID='" + ID + "';";
			exit = sqlite3_exec(DB, sql.c_str(), callback, 0, &messageError);//routine to execute delete query
	
		goto message;
		getchar();
		break;

	case 2:
		switch (select) {
		case 1:
			cout << "\t" << "\t" << "\t" << "Enter the ADM NO. of the record you want to modify: ";
			cin >> ID;
			sql = "SELECT *FROM STUDENTS WHERE ID='" + ID + "';";
			exit = sqlite3_exec(DB, sql.c_str(), callback, 0, &messageError);
			cout << endl << endl << "\t" << "\t" << "\t" << "Enter new details.... ";
			cout << "Enter firstname: ";
			cin >> firstname;
			cout << "Enter lastname: ";
			cin >> lastname;
			cout << "Enter DEGREE ID: ";
			cin >> ID1;
			cout << "Enter admission number: ";
			cin >> admNo;
			cout << "enter age: ";
			cin >> age;
			cout << "enter gender: ";
			cin >> gender;
			cout << "enter address: ";
			cin >> address;
			sql = "UPDATE STUDENTS SET DEGREE_ID='" + ID1 + "',ID=UPPER('" + admNo + "'),FIRSTNAME=UPPER('" + firstname + "'),LASTNAME=UPPER('" + lastname + "'),AGE='" + to_string(age) + "',GENDER='" + gender + "',ADDRESS='" + address + "',EMAIL=LOWER('" + lastname + "." + firstname + ".quad.ke') WHERE ADM_NO='"+ID+"';";
			exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);//routine to execute delete query
			
			sql = "SELECT *FROM STUDENTS WHERE ID='" + ID1 + "';";
			exit= sqlite3_exec(DB, sql.c_str(), callback, 0, &messageError);
			 getchar();
			goto message;
			break;
		case 2:
			cout << "\t" << "\t" << "\t" << "Enter the ID(national ID) of the record you want to modify: ";
			cin >> ID;
			sql = "SELECT *FROM ADMINS WHERE ID='" + ID + "';";
			exit = sqlite3_exec(DB, sql.c_str(), callback, 0, &messageError);

			cout << endl << endl << "\t" << "\t" << "\t" << "Enter new details.... ";
			cout << endl << "\t" << "\t" << "\t" << "Enter firstname: ";
			cin >> firstname;//
			cout << "\t" << "\t" << "\t" << "Enter lastname: ";
			cin >> lastname;
			cout << "\t" << "\t" << "\t" << "Enter national ID: ";
			cin >> ID1;
			
				sql = "UPDATE ATTENDANTS SET FIRSTNAME =UPPER('" + firstname + "'),LASTNAME=UPPER('" + lastname + "'),ID='" + ID + "',EMAIL=LOWER('" + lastname + "." + firstname + ".quad.ke') WHERE ADMIN_ID ='" + ID + "'";
				exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);//routine to execute delete query
				sql = "SELECT *FROM ATTENDANTS  WHERE ID='" + ID + "';";
				exit = sqlite3_exec(DB, sql.c_str(), callback, 0, &messageError);//routine to execute delete query


			break;
		}

		break;
	message:
		{
			if (exit != SQLITE_OK)
			{
				cerr << "RECORD NOT FOUND!!" << endl;
				sqlite3_free(messageError);
			}
			else
				cout << "Record modified successfully!!" << endl;
		}
	}

}

void director::login(int auth)
{
	int exit=0,exit1=0,entry=0;
	string table,LOGIN,ADMINS,ATTENDANTS,STUDENTS;
	sqlite3_open("QUAD.db", &DB);
	while (1)
	{
		entry++;
		string cont = to_string(auth);
		const char* data = cont.c_str();

		switch (auth)
		{
		case 1:
			table = LOGIN;
			goto READ;

			break;
		case 2:
			table = ADMINS;
			goto READ;
			break;
		case 3:table =STUDENTS;
			
			goto READ;
			break;
		case 4:table = ATTENDANTS;
			
			goto READ;
			break;
		READ:
			{
			
			cout <<endl<< '\t' << '\t' << '\t' << '\t' << "Email:  ";
			cin >> passn;
			email = passn;
			for (int i = 1; i < 4000; i++)
			{
				if (auth == 1) {
					string sql = "SELECT EMAIL FROM '" + table + "' WHERE PASSWORD='" + to_string(i) + "' ;";
			}
				else {
					string sql = "SELECT EMAIL FROM '" + table + "' WHERE ID='" + to_string(i) + "' ;";
				}
				exit = sqlite3_exec(DB, sql.c_str(), callback, (void*)data, &messageError);

				if (exit == 0)
				{
					break;
				}
			}
			//entry of masked password by user


			passn = "";
			char ch;
			cout << endl << '\t' << '\t' << '\t' << '\t' << "Password:  ";
			ch = _getch();
			while (ch != 13)/*character 13 is enter key
							as long as the user doesn't press enter(enter is ASCII code 13)
							continue reading keystrokes from the screen*/
			{
				passn.push_back(ch);/*the hom.password is a string variable
											the push_back method puts the character specified as a parameter
											at the end of the string*/
				cout << "*";//since nothing has been displayed from the keystroke we display (*) for every key.
				ch = _getch();//reads another key stroke to continue reading keystrokes fro the user.
			}

			for (int i = 1; i < 4000; i++)
			{
				if (auth == 1) {
					string sql = "SELECT PASSWORD FROM '" + table + "' WHERE PASSWORD='" + to_string(i) + "' ;";
				}
				else {
					string sq = "SELECT ID FROM '" + table + "' WHERE ID='" + to_string(i) + "' ;";
				}
				exit1 = sqlite3_exec(DB, sq.c_str(), callback, (void*)data, &messageError);
				if (exit1 == 0)
				{
					if (exit != SQLITE_OK)
					{
						cerr << endl << '\t' << '\t' << '\t' << '\t' << "RECORD NOT FOUND!!" << endl;
						sqlite3_free(messageError);
						if (auth == 1)
						{
							goto CREATE;
						}
						disp_homepage();
					}
					else {
						cout << endl << '\t' << '\t' << '\t' << '\t' << "LOGIN SUCCESSFUL!!" << endl;
						programEntry(auth);
					}
					break;
				}
				sqlite3_close(DB);
			}
			break;
		case 5:
			break;
		default:
			cout << endl << '\t' << '\t' << '\t' << '\t' << "invalid option try again!!";

			}
		CREATE: {
		if (entry > 2)
		{
				cout << endl << '\t' << '\t' << '\t' << '\t' << "CREATE ACCOUNT" << endl;
				cout << endl << '\t' << '\t' << '\t' << '\t' << "Enter your  firstname: ";
				cin >> firstname;
				cout << endl << '\t' << '\t' << '\t' << '\t' << "Enter your  lastname: ";
				cin >> lastname;
				cout << endl << '\t' << '\t' << '\t' << '\t' << "enter your national id: ";
				cin >> ID;
				cout << endl << '\t' << '\t' << '\t' << '\t' << "Enter password: ";
				cin >> pasn;
				sql = "INSERT INTO LOGIN VALUES('" + to_string(ID) + "',UPPER('" + firstname + "." + lastname + "'),'" + pasn + "',LOWER('" + lastname + "." + firstname + ".students.quad.ke')) ;";
				exit = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data, &messageError);

				break;
		}
			
	}
		}
		if (auth == 5)
			break;
		sqlite3_close(DB);
	}
}

void director::programEntry(int choic)
{
getchar();
	getchar();
	if (choic == 1 || choic == 2 || choic == 3 || choic == 4 || choic == 5)/*
																		compares the choice with cases present
																		choice 1=director,
																		choice 2=adminstrator,
																		choice 3=student,
																		choice 4=attedant
																		choice 5=exit
																		*/
	{
		//hom.login(choice);

		switch (choic)
		{
		case 1:
			title = "DIRECTOR";

			message();
			disp_director_options();
			break;

		case 2:
			title = "ADMINSTRATOR";
			message();
			//input of credentials to verify if youre a registered user
			disp_options();//displays options that the admin can choose
			break;

		case 3:
			title = "STUDENT";
			message();
			//cap.disp_student_option();
			break;

		case 4:
			title = "ATTEDANT";
			message();
			disp_attendants_options();
			break;
		case 5:
			//exit(0);
			break;
		}
		
	}

}
  
