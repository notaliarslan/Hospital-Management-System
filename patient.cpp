// Muhammad Ali Arslan
// 19F-0348
#include"hospital.h"
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<iomanip>
Patient::Patient()
{
	first_name = "";
	last_name = "";
	department = " ";
	id = "0";
	registration_date = "";
	gender = "";
	contact_number = "";
	fee_Status = "Unpaid";
	blood_group = "";
	address = "";
}
bool Patient::loginPatient(string a)
{
	ifstream fin; int i = 0;
	fin.open("Patient.txt", ios::in);
	if (!fin)
		cout << "File not Found" << endl;
	else
	{
		fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
		while (!fin.eof())
		{
			if (a == id)
			{
				return 1;
				i++;
			}
			fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
		}
	}
	fin.close();
	if (i == 0)
	{
		return 0;
	}
}
void Patient::header()
{
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
	cout << "\t\t\t\t\t\t\t\t\tPATIENT MENU\n";
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
	cout << endl << endl;
}
void Patient::header1()
{
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
	cout << "\t\t\t\t\t\t\t\t\tPATIENT LOGIN\n";
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
	cout << endl << endl;
}
int Patient::userMenu()
{
	system("cls");
	int o;
	header();
	cout << "(1) Appointment Status    " << endl;
	cout << "(2) View Fee Status       " << endl;
	cout << "(3) Go Back To Login Page " << endl;
	cout << "__________________________" << endl;
	cout << "Enter your choice: "; 
	cin >> o;
	while (!(o > 0 && o < 4))
	{
		cout << "Invalid Number!  Please Enter Again" << endl;
		cin >> o;
	}
	return o;
}
void Patient::viewMyFeeStatus(string a)
{
	system("cls");
	ifstream fin;
	fin.open("Patient.txt", ios::in);
	cout << "________________________ ____________________" << endl;
	cout << "|     Patient Name     |  ID  |  Fee Status |" << endl;
	cout << "|______________________|______|_____________|" << endl;
	if (!fin)
		cout << "File not Found" << endl;
	else
	{
		fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
		while (!fin.eof())
		{
			if (a == id)
				cout << "|  " << setw(20) << left << first_name + " " + last_name << "| " << setw(10) << id << "| " << setw(12) << fee_Status << "|" << endl;
			fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
		}
	}
	fin.close();
	cout << "|______________________|___________|_____________|" << endl << endl << endl;
	system("pause");

}
appointment::appointment()
{
	dep = "";
	patient_id = "0";
	app_id = 0;
	time = "0";
	status = "Unchecked";
}
void appointment::viewSpecificPatientAppointment(string a)
{
		system("cls");
		ifstream fin;
		ofstream fout;
		fin.open("appointment.txt", ios::in);
		if (!fin)
			cout << "File not Found" << endl;
		else
		{
			fin >> dep >> app_id >> status >> patient_id >> time;
			while (!fin.eof())
			{
				if (a == patient_id)
				{
					cout << "__________________________________________________________" << endl;
					cout << "|     Department    |  Appointment ID  | Appointment Satus| " << endl;
					cout << "|___________________|__________________|__________________|" << endl;
					cout << dep << "  \t\t  " << app_id << " \t\t   " << status << endl;
				}
				else
				{
					fout << dep << "    \t\t" << app_id << "    \t\t" << status << endl;
				}
				fin >> dep >> app_id >> status >> patient_id >> time;
			}
		}
		fin.close();
		system("pause");
}