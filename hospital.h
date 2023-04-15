// Muhammad Ali Arslan
// 19F-0348
#include<string>
#include<iostream>
using namespace std;
class Admin
{
private:
	string id;
	string pass;
public:
	Admin();
	bool login(string, string);
	int users();
	int virtual userMenu();
	void header();
	void header1();
};
class Patient :public Admin
{
protected:
	string first_name;
	string last_name;
	string department;
	string id;
	string registration_date;
	string gender;
	string contact_number;

	string fee_Status;
	string blood_group;
	string address;
	static int i;
public:
	Patient();
	void header();
	void header1();
	friend istream& operator>>(istream&, Patient&);
	void showPatientDetail();
	void storePatient();
	void viewAllPatient();
	void viewFeeStatus();
	void viewMyFeeStatus(string a);
	void depPatient(string a);
	void specificPatient(string a);
	void editPatient(string a);
	friend class appointment;
	bool loginPatient(string a);
	int userMenu();
	int viewMenu();
};

class Doctor :public Admin
{
protected:
	string first_name;
	string last_name;
	string email;
	string joining_date;
	string pasword;
	string confirm_pasword;
	string CNIC;
	string gender;
	string qualification;
	string contact_number;
	string DOB;
	string address;
	int salary;
	string department;
public:
	void header();
	void header1();
	Doctor();
	friend istream& operator>>(istream&, Doctor&);
	void showDoctorDetail();
	void storeDoctor();
	void viewAllDoctor();
	void specificDoctor(string a);
	void editDoctor(string a);
	friend class appointment;
	bool loginDoctor(string a, string b);
	int userMenu();
};
class appointment
{
protected:
	string dep;
	string status;
	string patient_id;
	string time;
	int app_id;
public:
	appointment();
	friend istream& operator>>(istream&, appointment&);
	void showAppointmentDetail();
	void storeappointment();
	void editappointment(int a);
	void viewAllAppointment();
	void viewMyappointments(string a1, Doctor& a, Patient& b);
	void assignappointment(Doctor& a);
	void viewSpecificPatientAppointment(string a);
	void updateAppointment(int a);
};