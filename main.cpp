#include <iostream>
#include <string>
#include <cstring>
#include <limits>
using namespace std;
// multidimentional array for storage
char parentinfo[30][6][30];
char childinfo[30][2][20];
int childinfoextra[30][2];
int attendance [30][4];
char staff[30][4][30];
int staffextra[30][2];
double money[30][3];
int admin_i = 0;
int info = 0;
int strmoney = 0;
class daycare {
	//registering
public: void regester() {


	cout << "<--------- Welcome to our Day care system...   ----------->" << endl;
	cout << "" << endl;
	bool continue_1 = true;
	while(continue_1){

		char Parent_name[20];
		char DOB[10];
		char phonenumber[20];
		char email[30];
		char Id_number[20];
		char child_name[20];
		char childsec_name[20];
		char parentsec_name[20];
		int child_DOB;
		int child_daycare_id;


		cout << "Enter parent information: " << endl;
		cout << "" << endl;
		cout << "ID number: " << endl;
		cout << ": ";
		cin >> Id_number;
		cout << "Full Name: " << endl;
		cout << ": ";
		cin >> Parent_name;
		cin >> parentsec_name;
		cout << "DOB: " << endl;
		cout << ": ";
		cin >> DOB;
		cout << "Phone Number: " << endl;
		cout << ": ";
		cin >> phonenumber;
		cout << "Email: " << endl;
		cout << ": ";
		cin >> email;
		cout << "" << endl;
		cout << "" << endl;
		cout << "Enter child's details: " << endl;
		cout << "Full Name: " << endl;
		cout << ": ";
		cin >> child_name;
		cin >> childsec_name;
		cout << "Day care ID: " << endl;
		cout << ": ";
		cin >> child_daycare_id;
		if (!ciin()) continue; // error handling when cin is entered as a letter instade of a number
		cout << "DOB: " << endl;
		cout << ": ";
		cin >> child_DOB;
		cout << "" << endl;
		if (!ciin()) continue;
		bool continue_10 = true;
		for (int i = 0; i < 30; i++) {
			if (child_daycare_id == childinfoextra[i][1]) {
				cout << "Input another ID, their is an existing same ID " << child_daycare_id << endl;
				cout << "" << endl;
				continue_10 = false;
			}
		}
		if (!continue_10) continue;
		if (2025 - child_DOB >= 5) {
			cout << "CHILD BELLOW THAN 5 YEARS OLD ARE NOT APPLICABLE " << endl;
			cout << "" << endl;
			continue;
		}

		cout << "parent information: " << endl;
		cout << "ID number: " << Id_number << endl;
		cout << "Name: " << Parent_name << " " << parentsec_name << endl;
		cout << "DOB: " << DOB << endl;
		cout << "Phone number: " << phonenumber << endl;
		cout << "Email: " << email << endl;
		cout << "" << endl;
		cout << "child's details: " << endl;
		cout << "Full Name: " << child_name << " " << childsec_name << endl;
		cout << "Day care ID: " << child_daycare_id << endl;
		cout << "DOB: " << child_DOB << endl;
		cout << "" << endl;

		cout << "Are you sure you want to continue" << endl;
		cout << "1: continue" << endl;
		cout << "2: re-enter" << endl;
		cout << ": ";
		int choose;
		cin >> choose;
		if (choose == 2) {
			continue;
		}else if (choose == 1) {
			continue_1 = false;
		}else {
			cout << "Please enter 1 or 2" << endl;
		}

		// converts char array to string so that it can be stored in multidimentional array
		strcpy(parentinfo[info][0], Parent_name);
		strcpy(parentinfo[info][1], DOB);
		strcpy(parentinfo[info][2], Id_number);
		strcpy(parentinfo[info][3], phonenumber);
		strcpy(parentinfo[info][4], email);
		strcpy(parentinfo[info][5], parentsec_name);
		strcpy(childinfo[info][0], child_name);
		strcpy(childinfo[info][1], childsec_name);
		childinfoextra[info][0] = child_DOB;
		childinfoextra[info][1] = child_daycare_id;
		info++;



	}
}
public: void attendances() {

	int child_id;
	int in_hour, in_min;
	int out_hour, out_min;

	bool continue_2 = true;
	bool Correctid = false;
	while (continue_2) {
		int switcher;
		cout << endl;
		cout << "<---------------- Attendance ----------------->" << endl;
		cout << "Choose attendance time" << endl;
		cout << "1. check in"	 << endl;
		cout << "2. check out" << endl;
		cout << "3. Exit" << endl;
		cout << ": ";
		cin >> switcher;
		if (!ciin()) continue;
		switch (switcher) {
			case 1:
				Correctid = false;
				cout << "Enter child's Daycare id: " << endl;
				cout << ": ";
				cin >> child_id;
				if (!ciin()) continue;
				for (int i = 0; i < 30 ; i++) {
					// checks for child id in the multidimentional array
					if (childinfoextra[i][1] == child_id) {
						cout << "child ID: " << child_id << endl;
						cout << "Child name: " << childinfo[i][0] << " "  << childinfo[i][1] << endl;
						cout << "Parent Name: " << parentinfo[i][0] << " " << parentinfo[i][5] << endl;

						cout << "Enter child check in time in 24hrs i.e '13 30':" << endl;
						cout << ": ";
						cin >> in_hour;
						cin >> in_min;
						if (!ciin()) continue;
						attendance[i][0] = child_id;
						attendance[i][1] = in_hour*60 + in_min; //convert time to int
						Correctid = true;
						break;

					}


				}
				if (!Correctid) {
					cout << "Wrong Id Entered: " <<child_id << endl;
					cout << endl;
				}


				break;
			case 2:
				Correctid = false;
				cout << "Enter child's Daycare id: " << endl;
				cout << ": ";
				if (!ciin()) continue;
				cin >> child_id;
				for (int i = 0; i < 30; i++) {
					if (childinfoextra[i][1] == child_id) {
						cout << "child ID: " << childinfoextra[i][0] << endl;
						cout << "Child name: " << childinfo[i][0] << " "  << childinfo[i][1] << endl;
						cout << "Parent Name: " << parentinfo[i][0] << " " << parentinfo[i][5] << endl;
						// converting int to time and storing it
						int total_minutes = attendance[i][1];
						int hours = total_minutes / 60; // scince int takes the numbers before decimal when divided it will give hours
						int minutes = total_minutes % 60; // and the % is used to give the decimals or reminder which will be used as min
						cout << "check in time: " << hours << " " << minutes << endl;
						cout << "Enter child check out time in 24hrs i.e '13 30':" << endl;
						cout << ": ";
						cin >> out_hour;
						cin >> out_min;
						if (!ciin()) continue;
						attendance[i][0] = child_id;
						attendance[i][2] = out_hour*60 + out_min;
						int time_spent = attendance[i][2] - attendance[i][1];
						attendance[i][3] = attendance[i][3] + time_spent;
						Correctid = true;
						break;

					}


				}
				if (!Correctid) {
					cout << "Wrong Id Entered: " <<child_id << endl;
				}
				break;
			case 3: continue_2 = false;

				break;

			default:	cout << "Wrong choice entered" << endl;
		}
	}






};
public:
	int billing() {

	int child_id;
	double paid;
	double cost;
	bool continue_3 = true;
	while (continue_3) {
		int switcher;
		bool Correctid = false;
		cout << "" << endl;
		cout << "<------------- Billing -------------->" << endl;
		cout << "1. Payment" << endl;
		cout << "2. Billing" << endl;
		cout << "3. transaction Log" << endl;
		cout << "4. Exit" << endl;
		cout << ": ";
		cin >> switcher;
		if (!ciin()) continue;
		switch (switcher) {
			case 1:
				cout << "Enter child ID" << endl;
				cout << ": ";
				cin >> child_id;
				if (!ciin()) continue;
				for (int i = 0; i < 30; i++) {
					if (childinfoextra[i][1] == child_id) {
						bool continue_4 = true;
						while (continue_4) {
							cout << "child ID: " << child_id << endl;
							cout << "Child name: " << childinfo[i][0] << " "  << childinfo[i][1] << endl;
							cout << "Parent Name: " << parentinfo[i][0] << " " << parentinfo[i][5] << endl;
							int total_minutes = attendance[i][3];
							int hours = total_minutes / 60;
							int minutes = total_minutes % 60;
							cout << "Time not paid: Hours: " << hours << " Minutes: " << minutes << endl;
							cout << "" << endl;
							cost = attendance[i][3] * 1.16;
							cout << "Total cost: " << cost << endl;
							cout << "" << endl;
							cout << "Payment details: " << endl;
							cout << "Pay bill: 247247"<< endl;
							cout << "Acc: 100194746836 " << endl;
							cout << "" << endl;
							cout << "Enter cost paid: " << endl;
							cout << ": ";
							cin >> paid;
							int verify;
							cout << "1. verify payment of ksh " << paid << endl;
							cout << "2: re-enter Payment" << endl;
							cout << ": ";
							cin >> verify;
							if (!ciin()) continue;
							if (verify == 1) {
								continue_4 = false;
							}else if (verify == 2) {
								continue_4 = true;
							}else {
								cout << "Wrong choice entered" << endl;
							}
						}
						int remaining_cost= cost - paid;
						attendance[i][3] = remaining_cost/1.16;
						money[strmoney][0] = child_id;
						money[strmoney][1] = paid;
						money[strmoney][2] = attendance[i][3];



						cout << endl;
						cout << "<-------------------- DAY CARE SYSTEM -------------->" << endl;
						cout << "<----- RECEIPT ----->"<< endl;
						cout << "payment successful" << endl;
						cout << "child ID				: " << money[strmoney][0] << endl;
						cout << "Child name				: " << childinfo[i][0] << " "  << childinfo[i][1] << endl;
						cout << "Parent Name				: " << parentinfo[i][0] << " " << parentinfo[i][5] << endl;
						cout << "parent ID				: " << parentinfo[i][1] << endl;
						cout << "paid out				: KSH " << paid << " only" << endl;
						cout << "" << endl;
						cout << "<---------------------------------------------------->" << endl;
						cout << endl;

						strmoney++;
						Correctid = true;
						break;
					}


				}

				if (!Correctid) {
					cout << "Wrong Id Entered: " <<child_id << endl;
				}
				break;
			case 2:
				cout << "Enter child ID" << endl;
				cout << ": ";
				cin >> child_id;
				if (!ciin()) continue;
				for (int i = 0; i < 30; i++) {
					if (childinfoextra[i][1] == child_id) {
						cout << endl;
						cout << "<------------------- Billing ------------------->" << endl;
						cout << "child ID				: " << childinfoextra[i][1] << endl;
						cout << "Child name				: " << childinfo[i][0] << " "  << childinfo[i][1] << endl;
						cout << "Child DOB				: " << childinfoextra[i][0] << endl;
						cout << "Parent Name				: " << parentinfo[i][0] << " " << parentinfo[i][5] << endl;
						cout << "parent ID				: " << parentinfo[i][2] << endl;
						cout << endl;
						int total_minutes = attendance[i][3];
						int hours = total_minutes / 60;
						int minutes = total_minutes % 60;
						cout << "Time not paid			: Hours : " << hours << " Minuits : " << minutes << endl;
						cout << "" << endl;
						cout << "<--------------------------------------------->" << endl;
						Correctid = true;
						break;
					}


				}

				if (!Correctid) {
					cout << "Wrong Id Entered: " <<child_id << endl;
				}
				break;
			case 3:
				cout << "1. Search" << endl;
				cout << "2. All" << endl;
				cout << "3. Exit" << endl;
				cout << ": " << endl;
				int choose;
				cin >> choose;
				if (!ciin()) continue;
				if (choose == 1) {
					cout << "Enter child ID" << endl;
					cout << ": ";
					cin >> child_id;
					for (int i = 0; i < 30; i++) {
						if (childinfoextra[i][1] == child_id) {
							cout << endl;
							cout << "<------------------------- Payment Log ---------------------------->" << endl;
							cout << "Child ID				: " << childinfoextra[i][1] << endl;
							cout << "Child name				: " << childinfo[i][0] << " "  << childinfo[i][1] << endl;
							cout << "parent ID				: " << parentinfo[i][2] << endl;
							cout << "Parent Name				: " << parentinfo[i][0] << " " << parentinfo[i][5] << endl;
							cout << " " << endl;
							for (int i = 0; i < 30; i++) {
								if (money[i][0] == child_id) {
									cout << "Amount paid			: " << money[i][1] << endl;
									int paid = money[i][1];
									int total_minutes = paid/1.16;
									int hours = total_minutes / 60;
									int minutes = total_minutes % 60;
									cout << "Time paid for			: Hours : " << hours << " Minuits : " << minutes << endl;
									int time = money[i][2];
									int hour = time / 60;
									int minute = time % 60;
									cout << "Time not paid			: Hours : " << hour << " Minuits : " << minute << endl;
									cout << "" << endl;
								}
							}
							cout << "<------------------------------------------->" << endl;
							cout << "" << endl;
							Correctid = true;
							break;
						}


					}

					if (!Correctid) {
						cout << "Wrong Id Entered: " <<child_id << endl;
					}
				}else if (choose == 2) {
					for (int i = 0; i < 30; i++) {
						for (int j = 0; j < 30; j++) {
							if (money[i][0] == childinfoextra[j][1] && money[i][0] != 0 ) {
								cout << "<------------------- Payment log --------------------->" << endl;
								cout << "Child ID			: " << childinfoextra[j][1] << endl;
								cout << "Child name			: " << childinfo[i][0] << " "  << childinfo[i][1] << endl;
								cout << "parent ID			: " << parentinfo[j][2] << endl;
								cout << "Parent Name			: " << parentinfo[i][0] << " " << parentinfo[i][5] << endl;
								cout << "Amount paid			: " << money[i][1] << endl;
								int paid = money[i][1];
								int total_minutes = paid/1.16;
								int hours = total_minutes / 60;
								int minutes = total_minutes % 60;
								cout << "Time paid for			: Hours : " << hours << " Minuits : " << minutes << endl;
								int time = money[i][2];
								int hour = time / 60;
								int minute = time % 60;
								cout << "Time not paid			: Hours: " << hour << " Minuits: " << minute << endl;
								cout << "" << endl;
								cout << "<------------------------------------------------->" << endl;
							}
						}




					}
				}else if (choose == 3) {
					break;
				}else {
					cout << "Wrong choice " << endl;
				}
				break;
			case 4: continue_3 = false;
				break;
			default: cout << "Wrong choice entered" << endl;
		}
	}
}
public: void administrator() {
	cout << "<<<<<<<<<  YOU ARE IN ADMINISTRATOR >>>>>>>>>>" << endl;

	int staff_id;
	char staff_name[20];
	char staff_dob[10];
	char staff_id_number[10];
	char staffsec_name[10];
	int staff_password;
	int admin;
	bool continue_5 = true;
	bool correctid = false;
	while (continue_5) {
		cout << "1. ADD staff" << endl;
		cout << "2. View staff" << endl;
		cout << "3. View child" << endl;
		cout << "4. Exit" << endl;
		cout << ": ";
		int switcher;
		cin >> switcher;
		if (!ciin()) continue;
		switch (switcher) {
			case 1:

				cout << "Enter ADMIN password" << endl;
				cout << ": ";
				cin >> admin;
				if (admin == 4321) {
					cout << "Add staff information" << endl;
					cout << "Staff ID: " << endl;
					cin >> staff_id;
					cout << "Staff Full name: "<< endl;
					cin >> staff_name;
					cin >> staffsec_name;
					cout << "Staff DOB: " << endl;
					cin >> staff_dob;
					cout << "Staff National ID: "<< endl;
					cin >> staff_id_number;
					cout << "Staff Password: " << endl;
					cin >> staff_password;
					cout << "" << endl;

					cout << "Staff ID: " << staff_id << endl;
					cout << "Staff Full name: " << staff_name << " " << staffsec_name << endl;
					cout << "Staff DOB: " << staff_dob << endl;
					cout << "Staff National ID: " << staff_id_number << endl;
					cout << "Staff Password: " << staff_password << endl;
					cout << "" << endl;

					cout << "Are you sure you want to continue" << endl;
					cout << "1. continue" << endl;
					cout << "2. re-enter" << endl;
					cout << ": ";
					int choose;
					cin >> choose;
					if (!ciin()) continue;
					if (choose == 1) {
						continue_5 = false;
					}else if (choose == 2) {
						continue;
					}else {
						cout << "Wrong choice entered" << endl;
					}

					strcpy(staff[admin_i][0], staff_name);
					strcpy(staff[admin_i][1], staff_dob);
					strcpy(staff[admin_i][2], staff_id_number);
					strcpy(staff[admin_i][3], staffsec_name);
					staffextra[admin_i][0] = staff_id;
					staffextra[admin_i][1] = staff_password;
					admin_i++;


				}else {
					cout << "Wrong passowrd" << endl;
				}


				break;
			case 2:
				cout << "Staff ID:" << endl;
				int staffid;
				cin >> staffid;
				if (!ciin()) continue;
				for (int i = 0; i < admin_i; i++) {
					if (staffid == staffextra[i][0]) {
						cout << "Staff ID: " << staff_id << endl;
						cout << "Staff Full name: " << staff_name << " " << staffsec_name << endl;
						cout << "Staff DOB: " << staff_dob << endl;
						cout << "Staff National ID: " << staff_id_number << endl;
						cout << "Staff Password: *****" << endl;
						cout << "" << endl;
						correctid = true;
					}
				}
				if (!correctid) {
					cout << "Wrong staff ID " << endl;
				}
				break;
			case 3:
				cout << "Enter child ID" << endl;
				cout << ": ";
				int child_id;
				cin >> child_id;
				if (!ciin()) continue;
				for (int i = 0; i < 30; i++) {
					if (childinfoextra[i][1] == child_id) {
						cout << "parent information " << endl;
						cout << "ID number: " << parentinfo[i][2]<< endl;
						cout << "Name: " << parentinfo[i][0] << " " << parentinfo[i][5] << endl;
						cout << "DOB: " << parentinfo[i][1] << endl;
						cout << "Phone number: " << parentinfo[i][3] << endl;
						cout << "Email: " << parentinfo[info][4] << endl;
						cout << "" << endl;
						cout << "child's details " << endl;
						cout << "Full Name: " << childinfo[i][0] << " " << childinfo[i][1]<< endl;
						cout << "Day care ID: " << childinfoextra[i][1] << endl;
						cout << "DOB: " << childinfoextra[i][0] << endl;
						cout << "" << endl;
						correctid = true;
					}
				}
				if (!correctid) {
					cout << "Wrong ID " << child_id << endl;
				}
				break;

			case 4:
				continue_5 = false;
				break;
			default:
				cout << "Wrong choice entered" << endl;


		}
	}
}
	// for error handling when cin is entered as letter instade of number
	bool ciin(){
	if (cin.fail()) {
		cin.clear();
		// cin.ignore();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please enter a number." << endl;
		cout << endl;
		return false;
	}
		return true;
}
};



int main() {
	daycare d;
	bool continue_6 = true;
	while (continue_6) {
		cout << "" << endl;
		cout << "<------------------- DAY CARE MANAGEMENT SYSTEM ------------------------>" << endl;
		cout << "1. Registration"<< endl;
		cout << "2. staff" << endl;
		cout << "3. Admin" << endl;
		cout << "4. EXIT" << endl;
		cout << ": " ;
		int choice;
		cin >> choice;
		if (!d.ciin()) continue;
		switch (choice) {
			case 1: {
				d.regester();
				break;
			}
			case 2: {
				cout  << endl;
				cout << "Enter your staff ID:" << endl;
				cout << ": ";
				int staff_id;
				cin >> staff_id;
				cout << "Enter your password:" << endl;
				cout << ": ";
				int password;
				cin >> password;

				bool continue_5 = true;
				while (continue_5) {
					bool authenticated = false;
					for (int i = 0; i < 30; i++) {
						if (staff_id == staffextra[i][0] && password == staffextra[i][1]) {
							authenticated = true;
							cout << "<----------- HOME ------------->" << endl;
							cout << "1. Attendance" << endl;
							cout << "2. Billing" << endl;
							cout << "3. Exit" << endl;
							cout << ": ";
							cin >> choice;
							if (!d.ciin()) continue;
							if (choice == 1) {
								d.attendances();
							} else if (choice == 2) {
								d.billing();
							} else if (choice == 3) {
								continue_5 = false;
							} else {
								cout << "Wrong choice entered" << endl;
							}
						}
					}

					if (!authenticated) {
						cout << " Wrong ID or Password entered." << endl;
					}
				}


				break;
			}
			case 3: {
				bool continue_9 = true;
				cout << "Enter Administrator user name" << endl;
				cout << ": ";
				string name;
				cin >> name;
				cout << "Enter Administrator password" << endl;
				cout << ": ";
				int password;
				cin >> password;
				if (name == "Admin" && password == 4321) {
					while (continue_9) {
						cout << endl;
						cout << "<<<<<<<<<  YOU ARE IN ADMINISTRATOR >>>>>>>>>>" << endl;
						cout << "1. Attendance " << endl;
						cout << "2. billing " << endl;
						cout << "3. Administrator " << endl;
						cout << "4. Exit" << endl;
						cout << ": ";
						cin >> choice;
						if (!d.ciin()) continue;
						if (choice == 1) {
							d.attendances();
						} else if (choice == 2) {
							d.billing();
						} else if (choice == 3) {
							d.administrator();
						} else if (choice == 4) {
							break;
						} else {
							cout << "Wrong choice entered" << endl;
						}
					}
				}else {
						cout << "Wrong ADMIN username or Password entered" << endl;

					}

					break;
				}
			case 4: {
				continue_6 = false;
				break;
			}
			default: {
				cout << "Wrong choice entered" << endl;
				break;
			}
		}
	}
		return 0;

}

// Testing Report:
//
// During testing, several issues were identified and resolved to improve the program
//
// One major issue occurred when we entered letters instead of numbers, causing the program to loop endlessly.
// This was fixed by putting input error handling using cin.fail(), cin.clear(), and cin.ignore() to reset and clean the input error.
//
// We also encountered a problem with names containing spaces and only the first part of the name was captured.
// To fix this, we added another input field using another line of cin to properly read full names.
//
// Another issue involved navigation, after exiting a section, the program returned to the main menu instead of the previous page.
// We corrected this by placing a loop in the previous page logic, making sure we stayed there unless we choose to return.
//
// While printing array data, we ran into a logic error where not all elements were displayed correctly.
// This was resolved by changing the code using nested for loops.
//
// In summary, all major bugs were fixed, and the program now handles input more reliably, improves navigation.
//
//
// Transaction logs:
//
// <-------------------- DAY CARE SYSTEM -------------->
// <----- RECEIPT ----->
// payment successful
// child ID                                : 321
// Child name                              : Kelvin onyango
// Parent Name                             : Brian Octa
// parent ID                               : 2004
// paid out                                : KSH 300 only
//
// <---------------------------------------------------->
//
// <------------------- Billing ------------------->
// child ID                                : 321
// Child name                              : Kelvin onyango
// Child DOB                               : 2022
// Parent Name                             : Brian Octa
// parent ID                               : 429839485
//
// Time not paid                   : Hours : 1 Minuits : 7
//
// <--------------------------------------------->
//
// <------------------------- Payment Log ---------------------------->
// Child ID                                : 321
// Child name                              : Kelvin onyango
// parent ID                               : 429839485
// Parent Name                             : Brian Octa
//
// Amount paid                     : 300
// Time paid for                   : Hours : 4 Minuits : 18
// Time not paid                   : Hours : 1 Minuits : 7
//
// Amount paid                     : 50
// Time paid for                   : Hours : 0 Minuits : 43
// Time not paid                   : Hours : 0 Minuits : 23
//
// <------------------------------------------->