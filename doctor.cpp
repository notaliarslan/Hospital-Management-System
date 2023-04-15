// Muhammad Ali Arslan
// 19F-0348
#include"hospital.h"
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<iomanip>
Doctor::Doctor()
{
	first_name = "";
	last_name = "";
	email = " ";
	joining_date = "";
	pasword = "";
	confirm_pasword = "";
	CNIC = "";
	gender = "";
	qualification = "";
	contact_number = "";
	DOB = "";
	address = "";
	salary = 0;
	department = " ";
}
void Doctor::header()
{
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
	cout << "\t\t\t\t\t\t\t\t\tDOCTOR MENU\n";
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
	cout << endl << endl;
}
void Doctor::header1()
{
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
	cout << "\t\t\t\t\t\t\t\t\tDOCTOR LOGIN\n";
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
	cout << endl << endl;
}
int Doctor::userMenu()
{
	system("cls");
	int o;
	header();
	cout << " (1) View My Appointments   " << endl;
	cout << " (2) Update Appointments    " << endl;
	cout << " (3) Go Back To Login Page  " << endl;
	cout << "____________________________" << endl;
	cout << "Enter your choice: "; 
	cin >> o;
	while (!(o > 0 && o < 4))
	{
		cout << "Invalid Choice! Please Enter Again" << endl;
		cin >> o;
	}
	return o;
}
bool Doctor::loginDoctor(string a, string b)
{
	ifstream fin; int i = 0;
	fin.open("Doctor.txt", ios::in);
	if (!fin)
		cout << "File not Found" << endl;
	else
	{
		fin >> first_name >> last_name >> email >> joining_date >> pasword >> CNIC >> gender >> qualification >> contact_number >> DOB >> address >> salary >> department;
		while (!fin.eof())
		{
			if (a == email && b == pasword)
			{
				return 1;
				i++;
			}
			fin >> first_name >> last_name >> email >> joining_date >> pasword >> CNIC >> gender >> qualification >> contact_number >> DOB >> address >> salary >> department;
		}
	}
	fin.close();
	if (i == 0)
	{
		return 0;
	}
}
void appointment::viewMyappointments(string a1, Doctor& a, Patient& b)
{
	system("cls");
	ifstream fin;
	fin.open("Doctor_appointment.txt", ios::in);
	cout << "________________________________________" << endl;
	cout << "| Appointment ID  |  Time |  Patient ID |" << endl;
	cout << "|_________________|_______|_____________|" << endl;
	if (!fin)
		cout << "File not Found" << endl;
	else
	{
		fin >> a.first_name >> a.last_name >> a.email >> a.pasword >> dep >> app_id >> status >> patient_id >> time;
		while (!fin.eof())
		{
			if (a.email == a1)
				cout << "|  " << setw(12) << left << app_id << " | " << setw(6) << time << "| " << setw(8) << patient_id << "|" << endl;
			fin >> a.first_name >> a.last_name >> a.email >> a.pasword >> dep >> app_id >> status >> patient_id >> time;
		}
	}
	cout << "|______________|_______|_________|" << endl << endl;
	fin.close();
	cout << endl << endl;
	system("pause");
}
void appointment::updateAppointment(int a)
{
	system("cls");
	ifstream fin;
	ofstream fout;
	fin.open("appointment.txt", ios::in);
	fout.open("temp1.txt");
	if (!fin)
		cout << "File not Found" << endl;
	else
	{
		fin >> dep >> app_id >> status >> patient_id >> time;
		while (!fin.eof())
		{
			if (a == app_id)
			{
				cout << "Enter Appointment Status: "; cin >> status;

				fout << dep << "    " << app_id << "    " << status << "    " << patient_id << "    " << time << endl;
				cout << " Updated The Appointment's Status" << endl;
			}
			else
			{
				cout << "NO Appointments Yet!" << endl;
			}
			fin >> dep >> app_id >> status >> patient_id >> time;
		}
	}
	fin.close();
	fout.close();
	remove("appointment.txt");
	rename("temp1.txt", "appointment.txt");
	system("pause");
}