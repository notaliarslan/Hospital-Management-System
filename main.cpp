// Muhammad Ali Arslan
// 19F-0348
#include"hospital.h"
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
int main()
{
	int option, option1, option2; string search, username, password,dep;
	Patient P1;	Doctor D1;	appointment C1;	Admin A1, * P;
	system("color F0");
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
	cout << "\t\t\t\t\t\t\t\t\tHOSPITAL MANAGEMENT SYSTEM\n";
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
	do
	{
		option2 = A1.users(); //Login Menu
		switch (option2)
		{
		case 1:
			system("cls");
			A1.header1(); //Admin Login Header
			cout << "    USERNAME: "; 
			cin >> username;
			cout << "    PASSWORD: "; 
			cin >> password;
			cout << "____________________________________" << endl;
			if (A1.login(username, password) != 1) //Login Credentials Check
			{
				cout << "Username or Password Not Matched" << endl; system("pause");
				break;
			}
			do
			{
				P = &A1;
				option = P->userMenu(); //Admin Menu
				switch (option)
				{
				case 1:
					cin >> D1;
					D1.storeDoctor(); // Add a Doctor
					break;
				case 2:
					cin >> P1;
					P1.storePatient(); // Add a Patient
					break;
				case 3:
					option1 = P1.viewMenu(); // Viewing Patients By Different Means
					switch (option1)
					{
					case 1:
						P1.viewAllPatient(); //View All Patients
						system("pause");
						break;
					case 2:
						cout << "Please Enter the Department : "; cin >> dep;
						P1.depPatient(dep); //View Patients By Department
						break;
					case 3:
						cout << "Please Enter the ID: "; cin >> search;
						P1.specificPatient(search); //View a patient By his/her ID
						break;
					}
					break;
				case 4:
					P1.viewAllPatient();
					cout << "Please Enter the Patient's ID: "; cin >> search;
					P1.editPatient(search); //Edit Data of a Patient
					break;
				case 5:
					D1.viewAllDoctor(); //View All Doctors
					break;
				case 6:
					D1.viewAllDoctor();
					cout << "Please Enter the Doctor's Email: "; cin >> search;
					D1.editDoctor(search); //Edit Data of a Doctor
					break;
				case 7:
					cin >> C1;
					C1.storeappointment(); //Add an Appointment
					break;
				case 8:
					C1.viewAllAppointment(); //View All Appointments
					break;
				case 9:
					C1.assignappointment(D1); //Assign an Appointment
					break;
				case 10:
					cout << "Enter Apointment ID: "; cin >> option;
					C1.editappointment(option); //Update an Appointment
					break;
				case 11:
					P1.viewFeeStatus(); //View Fee Status
					break;
				}
			} while (option != 12);
			break;
		case 2:
			system("cls");
			P1.header1(); //Patient Login Header
			cout << "   Patient ID: "; cin >> search;
			cout << "____________________" << endl;
			if (P1.loginPatient(search) != 1) //Patient Login Credentials Check
			{
				cout << "Username or Password Not Matched" << endl; system("pause");
				break;
			}
			else
			{
				do
				{
					P = &P1;
					option = P->userMenu(); //Menu for Patient
					switch (option)
					{
					case 1:
						C1.viewSpecificPatientAppointment(search); //View Appointments
						break;
					case 2:
						P1.viewMyFeeStatus(search); //View Fee Status
						break;

					}
				} while (option != 3);
			}
			break;
		case 3:
			system("cls");
			D1.header1(); //Doctor Login Header
			cout << "    Email: "; cin >> username;
			cout << "    Password: "; cin >> password;
			cout << "____________________" << endl;
			if (D1.loginDoctor(username, password) != 1) //Doctor login credentials check
			{
				cout << "Username or Password Not Matched" << endl; system("pause");
				break;
			}
			do
			{
				P = &D1;
				option = P->userMenu(); //Menu for Doctors
				switch (option)
				{
				case 1:
					C1.viewMyappointments(username, D1, P1); //View Appointments of Doctor
					break;
				case 2:
					cout << "Enter Appointment ID: "; cin >> option;
					C1.updateAppointment(option); //Update Appointments
					break;
				}
			} while (option != 3);
			break;
		}
	} while (option2 != 4); //To exit the program
	return 0;
}


