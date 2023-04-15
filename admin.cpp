// Muhammad Ali Arslan
// 19F-0348
#include"hospital.h"
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<iomanip>
using namespace std;
int Admin::users()
{
	int o;
	cout << endl << endl;
	cout << "(1) Admin Login   " << endl;
	cout << "(2) Patient Login " << endl;
	cout << "(3) Doctor Login  " << endl;
	cout << "(4) Exit          " << endl;
	cout << "__________________" << endl;
	cout << "Enter your choice: "; cin >> o;
	while (!(o > 0 && o < 5))
	{
		cout << "Invalid Choice! Please Enter Again" << endl;
		cin >> o;
	}
	return o;
}
Admin::Admin()
{
	id = "admin";
	pass = "admin";
}
bool Admin::login(string a, string b)
{
	if (id == a && pass == b)
		return 1;
	else
		return 0;
}
void Admin::header1()
{
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
	cout << "\t\t\t\t\t\t\t\t\tADMIN LOGIN\n";
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
}
void Admin::header()
{
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
	cout << "\t\t\t\t\t\t\t\t\tADMIN MENU\n";
	for (int i = 0; i < 168; i++)
	{
		cout << "*";
	}
	cout << endl << endl;
}
int Admin::userMenu()
{
	system("cls");
	int o;
	header();
	cout << " (1) Add New Doctor              " << endl;
	cout << " (2) Add New Patient             " << endl;
	cout << " (3) View Patients               " << endl;
	cout << " (4) Edit Patient Data           " << endl;
	cout << " (5) View All Doctor             " << endl;
	cout << " (6) Edit Doctor Data            " << endl;
	cout << " (7) Add New appointment         " << endl;
	cout << " (8) View All appointment        " << endl;
	cout << " (9) Assign appointment          " << endl;
	cout << "(10) Update Appointment Status   " << endl;
	cout << "(11) View Fee Status             " << endl;
	cout << "(12) Go Back To Login Page       " << endl;
	cout << "_________________________________" << endl;
	cout << "Enter your choice: "; 
	cin >> o;
	while (!(o > 0 && o < 13))
	{
		cout << "Invalid Choice! Please Enter Again" << endl;
		cin >> o;
	}
	return o;
}
istream& operator>>(istream& in, Doctor& o)
{
	system("cls");
	cout << " _________________________________________________" << endl;
	cout << "|                ENTER DOCTOR DATA                |" << endl;
	cout << "|_________________________________________________|" << endl;
	cout << "Enter the First Name: "; in >> o.first_name;
	cout << "Enter the Second Name: "; in >> o.last_name;
	cout << "Enter th Email: "; in >> o.email;
	cout << "Enter the Joining date: "; in >> o.joining_date;
	do
	{
		cout << "Enter the Pasword: "; in >> o.pasword;
		cout << "Enter the Confirm pasword: "; in >> o.confirm_pasword;
		if (o.pasword != o.confirm_pasword)
			cout << "Enter the Password Again(Error)" << endl;
	} while (o.pasword != o.confirm_pasword);
	cout << "Enter the CNIC: "; in >> o.CNIC;
	cout << "Enter the Gender: "; in >> o.gender;
	cout << "Enter the Qualification: "; in >> o.qualification;
	cout << "Enter the Contact Number: "; in >> o.contact_number;
	cout << "Enter the Date of Birth: "; in >> o.DOB;
	cout << "Enter the Address: "; in >> o.address;
	cout << "Enter the Salary: "; in >> o.salary;
	cout << "Enter Department: "; in >> o.department;
	cout << " _________________________________________________" << endl;
	return in;
}
void Doctor::storeDoctor()
{
	ofstream fout;
	fout.open("Doctor.txt", ios::app);
	fout << " " << first_name << "    " << last_name << "    " << email << "    " << joining_date << "    " << pasword << "    " << CNIC << "    " << gender << "    " << qualification << "    " << contact_number << "    " << DOB << "    " << address << "    " << salary << "    " << department << endl;
	fout.close();
	cout << "Doctor record is recorded" << endl << endl;
	system("pause");
}
istream& operator>>(istream& in, Patient& o)
{
	system("cls");
	cout << " _________________________________________________" << endl;
	cout << "|                ENTER PATIENT DATA               |" << endl;
	cout << "|_________________________________________________|" << endl;
	cout << "Enter the First Name: "; in >> o.first_name;
	cout << "Enter the Last Name: "; in >> o.last_name;
	cout << "Enter the registration date: "; in >> o.registration_date;
	cout << "Enter ID: "; in >> o.id;
	cout << "Enter Department: "; in >> o.department;
	cout << "Enter the Gender: "; in >> o.gender;
	cout << "Enter the Contact Number:  "; in >> o.contact_number;
	cout << "Enter the Fee Status: "; in >> o.fee_Status;
	cout << "Enter the Blood Group: "; in >> o.blood_group;
	cout << "Enter the Address: "; in >> o.address;
	cout << "___________________________________________________" << endl;
	return in;
}
void Patient::storePatient()
{
	ofstream fout;
	fout.open("Patient.txt", ios::app);
	fout << " " << first_name << "    " << last_name << "    " << registration_date << "    " << id << "    " << department << "    " << gender << "    " << contact_number << "    " << fee_Status << "    " << blood_group << "    " << address << endl;
	fout.close();
	cout << "Patient Data is recorded" << endl << endl;
	system("pause");
}
int Patient::viewMenu()
{
	system("cls");
	int o;
	cout << " __________________________________" << endl;
	cout << "|          VIEW PATIENTS           |" << endl;
	cout << "|__________________________________|" << endl << endl;
	cout << "(1) All Patients           " << endl;
	cout << "(2) Patients of Department " << endl;
	cout << "(3) Specific Patient       " << endl;
	cout << "___________________________" << endl;
	cout << "Enter your choice: ";
	cin >> o;
	while (!(o > 0 && o < 4))
	{
		cout << "Invalid Number!  Please Enter Again" << endl;
		cin >> o;
	}
	return o;
}
void Patient::viewAllPatient()
{
	system("cls");
	ifstream fin;
	fin.open("Patient.txt", ios::in);
	cout << "____________________________________________________________________________________________________________________________________________" << endl;
	cout << "|     Patient Name     | Registration Date  |  ID  |    Department    | Gender | Contact Number | Fee Status | Blood Group | Address (city) |" << endl;
	cout << "|______________________|____________________|______|__________________|________|________________|____________|_____________|________________|" << endl;
	fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
	while (!fin.eof())
	{
		showPatientDetail();
		fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
	}
	fin.close();
}
void Patient::depPatient(string a)
{
	system("cls");
	ifstream fin;
	fin.open("Patient.txt", ios::in);
	cout << "____________________________________________________________________________________________________________________________________" << endl;
	cout << "|     Patient Name     | Department  | ID  | Registration Date| Gender | Contact Number | Fee Status | Blood Group | Address (city) |" << endl;
	cout << "|______________________|_____________|_____|__________________|________|________________|____________|_____________|________________|" << endl;
	fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
	while (!fin.eof())
	{
		if (a == department)
			showPatientDetail();
		fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
	}

	fin.close();
	system("pause");
}
void Patient::showPatientDetail()
{
	cout << "|  " << setw(20) << left << first_name + " " + last_name << "|      " << setw(15) << department << "| " << setw(10) << id << "| " << setw(7) << registration_date << "| " << setw(6) << gender << "| " << setw(17) << contact_number << "| " << setw(12) << fee_Status << "| " <<setw(5) << blood_group << "| " << setw(15) << address << "|" << endl;
}
void Patient::specificPatient(string a)
{
	system("cls");
	ifstream fin;
	fin.open("Patient.txt", ios::in);
	cout << "____________________________________________________________________________________________________________________________________" << endl;
	cout << "|     Patient Name     | Department  | ID  | Registration Date| Gender | Contact Number | Fee Status | Blood Group | Address (city) |" << endl;
	cout << "|______________________|_____________|_____|__________________|________|________________|____________|_____________|________________|" << endl;
	fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
	while (!fin.eof())
	{
		if (a == id)
			showPatientDetail();
		fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
	}

	fin.close();
	system("pause");
}
void Patient::editPatient(string a)
{
	system("cls");
	ifstream fin;
	ofstream fout;
	fin.open("Patient.txt", ios::in);
	fout.open("temp.txt");
	if (!fin)
		cout << "File not Found" << endl;
	else
	{
		fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
		while (!fin.eof())
		{
			if (a == id)
			{
				cout << " _________________________________________________" << endl;
				cout << "|                ENTER PATIENT DATA               |" << endl;
				cout << "|_________________________________________________|" << endl;
				cout << " Enter the First Name: "; cin >> first_name;
				cout << " Enter the Second Name: "; cin >> last_name;
				cout << " Enter the Contact No: "; cin >> contact_number;
				cout << " Enter the Fee Status: "; cin >> fee_Status;
				cout << " Enter the Address: "; cin >> address;
				cout << "_________________________ " << endl;

				fout << first_name << "    " << last_name << "    " << department << "    " << id << "    " << registration_date << "    " << gender << "    " << contact_number << "    " << fee_Status << "    " << blood_group << "    " << address << endl;
				cout << " Updated The Patient's Data" << endl;
			}
			else
			{
				fout << first_name << "    " << last_name << "    " << department << "    " << id << "    " << registration_date << "    " << gender << "    " << contact_number << "    " << fee_Status << "    " << blood_group << "    " << address << endl;
			}
			fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
		}
	}
	fin.close();
	fout.close();
	remove("Patient.txt");
	rename("temp.txt", "Patient.txt");
	specificPatient(a);
}
void Doctor::showDoctorDetail()
{
	cout << "|  " << setw(20) << left << first_name + " " + last_name << "| " << setw(18) << email << "| " << setw(8) << gender << "| " << setw(12) << contact_number << "| " << setw(15) << department << "| " << setw(10) << salary << "| " << setw(15) << qualification << "|" << endl;
}
void Doctor::viewAllDoctor()
{
	system("cls");
	ifstream fin;
	fin.open("Doctor.txt", ios::in);
	cout << "______________________________________________________________________________________________________________________" << endl;
	cout << "|     Doctor Name      |      Email ID     | Gender  |  Contact Number  |   Department   |   Salary  | Qualification  |" << endl;
	cout << "|______________________|___________________|_________|__________________|________________|___________|________________|" << endl;
	fin >> first_name >> last_name >> email >> joining_date >> pasword >> CNIC >> gender >> qualification >> contact_number >> DOB >> address >> salary >> department;
	while (!fin.eof())
	{
		showDoctorDetail();
		fin >> first_name >> last_name >> email >> joining_date >> pasword >> CNIC >> gender >> qualification >> contact_number >> DOB >> address >> salary >> department;
	}

	fin.close();
	system("pause");
}
void Doctor::specificDoctor(string a)
{
	system("cls");
	ifstream fin;
	fin.open("Doctor.txt", ios::in);
	cout << "_______________________________________________________________________________________________________________________" << endl;
	cout << "|     Doctor Name     |      Email ID     | Gender  |  Contact Number  |     Degree     |   Salary  | Qualification  |" << endl;
	cout << "|_____________________|___________________|_________|__________________|________________|___________|________________|" << endl;
	if (!fin)
		cout << "File not Found" << endl;
	else
	{
		fin >> first_name >> last_name >> email >> joining_date >> pasword >> CNIC >> gender >> qualification >> contact_number >> DOB >> address >> salary >> department;
		while (!fin.eof())
		{
			if (a == first_name)
			{
				showDoctorDetail();
			}
			fin >> first_name >> last_name >> email >> joining_date >> pasword >> CNIC >> gender >> qualification >> contact_number >> DOB >> address >> salary >> department;
		}
	}
	fin.close();
	system("pause");
}
void Doctor::editDoctor(string a)
{
	system("cls");
	ifstream fin;
	ofstream fout;
	fin.open("Doctor.txt", ios::in);
	fout.open("temp.txt");
	if (!fin)
		cout << "File not Found" << endl;
	else
	{
		fin >> first_name >> last_name >> email >> joining_date >> pasword >> CNIC >> gender >> qualification >> contact_number >> DOB >> address >> salary >> department;
		while (!fin.eof())
		{
			if (a == email)
			{
				cout << " _________________________________________________" << endl;
				cout << "|                ENTER DOCTOR's DATA              |" << endl;
				cout << "|_________________________________________________|" << endl;
				cout << "Enter the First Name: "; cin >> first_name;
				cout << "Enter the Last Name: "; cin >> last_name;
				cout << "Enter th Email: "; cin >> email;
				cout << "Enter the Gender: "; cin >> gender;
				cout << "Enter the Contact No: "; cin >> contact_number;
				cout << "Enter the Salary: "; cin >> salary;
				cout << "Enter the Department: "; cin >> department;
				cout << " ______________________" << endl;
				fout << first_name << "    " << last_name << "    " << email << "    " << joining_date << "    " << pasword << "    " << CNIC << "    " << gender << "    " << qualification << "    " << contact_number << "    " << DOB << "    " << address << "    " << salary << "    " << department << endl;
				cout << " Updated The Doctors's Data" << endl;
			}
			else
			{
				fout << first_name << "    " << last_name << "    " << email << "    " << joining_date << "    " << pasword << "    " << CNIC << "    " << gender << "    " << qualification << "    " << contact_number << "    " << DOB << "    " << address << "    " << salary << "    " << department << endl;
			}
			fin >> first_name >> last_name >> email >> joining_date >> pasword >> CNIC >> gender >> qualification >> contact_number >> DOB >> address >> salary >> department;
		}
	}
	fin.close();
	fout.close();
	remove("Doctor.txt");
	rename("temp.txt", "Doctor.txt");
	specificDoctor(a);
}
istream& operator>>(istream& in, appointment& o)
{
	system("cls");
	cout << " _______________________________________________" << endl;
	cout << "|            Enter New Appointment              |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << " Enter the Department Name: "; in >> o.dep;
	cout << " Enter the Appointment ID: "; in >> o.app_id;
	cout << " Enter the Status: "; in >> o.status;
	cout << " Enter the Patient ID: "; in >> o.patient_id;
	cout << " Enter the Appointment Time: "; in >> o.time;
	cout << "__________________________________________________" << endl;
	return in;
}
void appointment::storeappointment()
{
	ofstream fout;
	fout.open("appointment.txt", ios::app);
	fout << dep << "    " << app_id << "    " << status << "    " << patient_id << "    "  << time << endl;
	fout.close();
	cout << "Appointment has been added" << endl << endl;
	system("pause");
}
void appointment::showAppointmentDetail()
{
	cout << "|  " << setw(15) << left << dep << "| " << setw(8) << app_id << "| " << setw(6) << status << "| " << setw(12) << patient_id << "| "<< setw(7) << time << "|" << endl;
}
void appointment::viewAllAppointment()
{
	system("cls");
	ifstream fin;
	fin.open("appointment.txt", ios::in);
	cout << " __________________________________________________" << endl;
	cout << "|   Department |  ID  | Status | Patient ID | Time |" << endl;
	cout << "|______________|______|________|____________|______|" << endl;
	if (!fin)
		cout << "File not Found" << endl;
	else
	{
		fin >> dep >> app_id >> status >> patient_id >> time;
		while (!fin.eof())
		{
			showAppointmentDetail();
			fin >> dep >> app_id >> status >> patient_id >> time;
		}
	}
	fin.close();
	system("pause");
}
void appointment::assignappointment(Doctor &a)
{
	string search; int p;
	a.viewAllDoctor();
	cout << "Enter the Doctor's Email: ";
	cin >> search;
	ifstream fin1;
	ifstream fin2;
	ofstream fout;
	fin1.open("appointment.txt", ios::in);
	fin2.open("Doctor.txt", ios::in);
	fout.open("Doctor_appointment.txt", ios::app);
	if (!fin2)
		cout << "File not Found" << endl;
	else
	{
		fin2 >> a.first_name >> a.last_name >> a.email >> a.joining_date >> a.pasword >> a.CNIC >> a.gender >> a.qualification >> a.contact_number >> a.DOB >> a.address >> a.salary >> a.department;
		while (!fin2.eof())
		{
			if (search == a.email)
			{
				cout << "Enter the ID : "; cin >> p;
				fin1 >> dep >> app_id >> status >> patient_id >> time;
				while (!fin1.eof())
				{
					if (p == app_id)
					{
						fout << a.first_name << "   " << a.last_name << "   " << a.email << "   " << a.pasword << "   " << dep << "   " << app_id << "   " << status << "   " << patient_id << "   " << time << endl;
					}
					fin1 >> dep >> app_id >> status >> patient_id >> time;
				}
				
			}
			fin2 >> a.first_name >> a.last_name >> a.email >> a.joining_date >> a.pasword >> a.CNIC >> a.gender >> a.qualification >> a.contact_number >> a.DOB >> a.address >> a.salary >> a.department;
		}
	}
}
void Patient::viewFeeStatus()
{
	system("cls");
	ifstream fin;
	fin.open("Patient.txt", ios::in);
	cout << "______________________________________________" << endl;
	cout << "|     Patient Name     |  ID   |Fee Submitted|" << endl;
	cout << "|______________________|_______|_____________|" << endl;
	if (!fin)
		cout << "File not Found" << endl;
	else
	{
		fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
		while (!fin.eof())
		{
			cout << "|  " << setw(20) << left << first_name + " " + last_name << "| " << setw(10) << id << "| " << setw(12) << fee_Status << "|" << endl;
			fin >> first_name >> last_name >> department >> id >> registration_date >> gender >> contact_number >> fee_Status >> blood_group >> address;
		}
	}
	fin.close();
	system("pause");

}
void appointment::editappointment(int a)
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
				fout << dep << "    " << app_id << "    " << status << "    " << patient_id << "    " << time << endl;
			}
			fin >> dep >> app_id >> status >> patient_id >> time;
		}
	}
	fin.close();
	fout.close();
	remove("appointment.txt");
	rename("temp1.txt", "appointment.txt");
}
