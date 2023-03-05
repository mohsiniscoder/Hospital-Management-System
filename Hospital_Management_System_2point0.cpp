#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cctype>
#include<fstream> 
#include<algorithm>
using namespace std;
void printHeader();
void print_main_menu();
void print_admin_menu();
void rang(char color1);
const int size=100;
int login_count  = 0;
void edit_inventory_machines(string machine_name,string new_quantity);
bool machine_name_validation(string machine_name);
bool medicine_name_validation(string medicine_name);
void edit_inventory_medicines(string medicine_name,string new_quantity,string new_price);
bool for_admin_login(string username,string password);
void for_doctor_details();
void for_clearing_screen();
void add_inventory();
void add_inventory_medicines();
void print_inventory();
void print_patient_details();
void print_doctor_details();
void add_doctors();
void add_patients();
void edit_patient_details(string patient_id);
bool valid_patient_credentials(string patient_name_to_check,string patient_cnic_to_check);
bool new_cnic_validity(string New_CNIC);
void CNIC_Rules();
bool for_returning_back( char b);
void print_patient_menu();
void print_doctor_menu();
void password_details();
bool check_for_digit(string quantity);
bool name_validation( string doc_name_first);
bool doctor_id_validation(string doc_id);
bool phone_number_validation(string doc_number);
bool doctor_age_validation(string doc_age);
bool doctors_speciality_validation(string doc_speciality);
bool doctor_fee_validation(string doc_fee);
bool doctor_password_validation(string doc_password);
bool machine_name_validation_for_adding(string machine_name_to_add);
string secret_code = "123";
bool is_admin_user_name_valid(string username_for_signup);
bool is_valid_password(string password_for_signup);
bool is_gender_valid(string gender);
bool is_blood_group_valid(string blood_group);
bool is_patient_age_valid(string pat_age);
bool is_disease_name_valid(string pat_diseases );
bool for_patient_login(string id,string CNIC, string number);
bool doctor_availability(string speciality);
string for_retrieving_doctor_id(string speciality);
void for_storing_appointments(string doctor_file_name,string patient_id);
int for_pulling_out_fee_of_doctor(string speciality);
void to_store_earned_money(int amount);
bool for_checking_appointment_validity(string doctor_file_name, string patient_id);
void for_displaying_patient_details(string patient_id);
void for_adding_help_line_numbers(string number,string purpose );
bool is_help_line_number_valid(string number);
void for_displaying_help_line_numbers();
bool lab_test_name_validation(string lab_test);
void for_storing_lab_test(string lab_test,string price,string id);
string for_calculating_bill(string lab_test_id);
void print_lab_tests();
bool lab_test_id_validation(string lab_test_id);
bool lab_test_id_validation_booking(string lab_test_id);
string for_pulling_out_test_name(string lab_test_id);
void print_bill_for_lab_lest(string test,string bill);
void display_medicine_for_buying();
bool medicine_name_validation_for_buying(string medicine_name);
bool medicine_quantity_validation_for_buying(string medicine_name,string medicine_quantity_to_buy);
int for_pulling_out_price(string medicine_name);
int counter_for_printing_bill = 0;
int priceA[100];
string medicineA[100];
int quantityA[100];
void print_bill_for_medicines(string medicineA[],int quantityA[],int priceA[]);
void update_medicine_quantity(int original_quantity,int quantity,string medicine_name);
int for_pulling_out_original_medicine_quantity(string medicine_name);
const int size_of_med_array =1000;
string lines_of_medicines[size_of_med_array];
int count_medicines_lines = 0;
void update_medicine_data_quantity(int quantity,string medicine_name);
bool for_doctor_login(string id,string password);
bool patient_appointment_validation(string id,string doctor_file_name);
bool day_validation(string day);
void for_displaying_doctor_treatment(string remarks,string prescription,string tests,string operation,string day,char needs_special_treatment,char suggest,string cost);
void for_displaying_doctor_appointment(string file_name);
void updating_doctor_password(string id,string password);
void updating_doctor_details(string id);
bool medicine_name_validation_edit(string medicine_name);
// main ---------------------------------------------------------------------
// ==========================================================================
int main(){
  rang(7);
  char option,admin_option;
  string machine_name;
  string madicine_name;
  string new_quantity;
  string new_price;
  char want_to_enter_m_name;
  char want_to_add_inventory='y';
  char medicines_or_machines;
  while(true){
    system("CLS");
    printHeader();
    print_main_menu();
    cin>>option;
    login_count = 0;
    if(option == '1'){
      for_clearing_screen();
      cout<<"\nenter 'S' to sign up"<<endl;
      cout<<"\nEnter L to login "<<endl;
      char signup_or_login;
      cin>>signup_or_login;
      if (signup_or_login == 'S' || signup_or_login == 's'){
        for_clearing_screen();
        string username_for_signup;
        string password_for_signup;
        string secret_code_for_signup;
        while(true){
          cout<<"\n\nEnter Username:";
          cin>>username_for_signup;
          if(is_admin_user_name_valid(username_for_signup)){
            break;
          }
          else{
            cout<<"Invalid Username....";
            getch();
          }
        }
        while(true){
          cout<<"\n\nEnter Password:";
          cin>>password_for_signup;
          if(is_valid_password(password_for_signup)){
            break;
          }
          else{
            cout<<"\nInvalid Password !!";
            cout<<"\n\n>>Password must contain letters both upper and lowercase"; 
            cout<<"\n\n>>Password must contain special characters and numbers";
            cout<<"\n\n>>Password must not contain commas as files are stored in CSV format";
            cout<<"\n\n>>Password must be at least 8 characters long...";
            getch();
          }
        }
        while(true){
          cout<<"\n\nEnter Secret Code:";
          cin>>secret_code_for_signup;
          if(secret_code_for_signup == secret_code){
            break;
          }
          else{
            cout<<"\nInvalid Secret Code...";
            cout<<"\n\nIf you don't have the secret code than you can get it by sending your product code to abc@example.com";
            cout<<"\n\nPress any key to continue....";
            getch();
          }
        }
        fstream file;
        file.open("admin_info.txt",ios::app);
        if (!file.is_open()){
          cout<<"\nAdmin Info file not opened...";
          getch();
        }
        else {
          file <<username_for_signup<< "," << password_for_signup<<","<<endl;
          file.close();
        }
      }
      if (signup_or_login == 'L' || signup_or_login == 'l'){
        while(true){
        if(login_count > 0){
          break;
        } 
        for_clearing_screen();
        string username;
        string password;
        cout<<"\n\nEnter Username:";
        cin>>username;
        cout <<"\n\nEnter Password:";
        cin>>password;
        bool admin_logged_in = for_admin_login(username, password);
        if (admin_logged_in == true){
          login_count++;
          while(true){
          for_clearing_screen();
          print_admin_menu();
          cin>>admin_option;
          if (admin_option == '1'){
            while(true){
              for_clearing_screen();
              rang(3);
              cout<<"\n'M' for editing Machines\n\n'm' for editing Medicines\n\n'e' for exiting:";
              rang(7);
              cin>>medicines_or_machines;
              cin.ignore();
              cin.sync();
              if( medicines_or_machines == 'M'){  
                while(want_to_enter_m_name !='n'){     
                  cout<<"\nEnter Machine name:";
                  getline(cin,machine_name);
                  bool validity_of_name=machine_name_validation(machine_name);
                  if (validity_of_name == true){
                    while(true){
                      cout<<"Enter new Quantity:";
                      getline(cin,new_quantity);
                      if(check_for_digit(new_quantity)){
                        break;
                      }
                      else{
                        cout<<"Invalid Quantity!!!";
                        for_clearing_screen();
                      }
                    }
                    edit_inventory_machines(machine_name,new_quantity);
                    cout<<machine_name<<" quantity "<<"Updated Successfully";
                    cout<<"\nDo you want to update some other machine y/n";
                    cin>>want_to_enter_m_name;
                  }
                  else if(validity_of_name == false){
                    cout<<"The Machine Name you entered is not in the Inventory..."<<endl;
                    getchar();
                    for_clearing_screen();
                  }
                }
              }
              else if ( medicines_or_machines == 'm'){
                int counter_for_editing_1 = 0;
                //code to edit medicines 
                cin.ignore();
                cin.sync();
                while (true){
                  for_clearing_screen();  
                  if (counter_for_editing_1 > 0){
                    break;
                  }
                  string medicine_name;
                  cout<<"Enter the name of The Medicine whose quantity and price you want to change:";
                  getline(cin,medicine_name);
                  bool validity_of_medicine_name = medicine_name_validation_edit(medicine_name);
                  if (validity_of_medicine_name == true){
                    while(true){
                      while(true){
                        cout<<"Enter The New Price of the medicine:";
                        getline(cin,new_price);
                        if(check_for_digit(new_price)){
                          break;
                        }
                        else {
                          rang(4);
                          cout<<"Invalid price!";
                          rang(7);
                          getch();
                          for_clearing_screen();
                        }
                      }
                      while(true){
                        cout<< "\nEnter The New Quantity of the medicine:";
                        cin>> new_quantity;
                        if(check_for_digit(new_quantity)){
                          break;
                        }
                        else {
                          rang(4);
                          cout<<"Invalid Quantity....";
                          rang(7);
                          getch();
                          for_clearing_screen();
                        }
                      }
                    }
                    edit_inventory_medicines(medicine_name,new_quantity,new_price);
                    break;
                  }
                }
              }  
              else if(medicines_or_machines == 'e'){
                break;
              }
              else{
                rang(4);
                cout<<"You have entered wrong wrong options...";
                rang(7);
                getch();
                for_clearing_screen();
              }
            }
          }  
        else if(admin_option == '2'){
          while(true){
            //add something to inventory
            for_clearing_screen();
            char machine_or_medicine;
            cout<<"Do you want to Add Machines or Medicines?\n'M' for Machines\n'm' for medicines\n'B' for back\n";
            cin>>machine_or_medicine;
            char want_to_add_inventory = ' ';
            if (machine_or_medicine == 'M'){
              while(want_to_add_inventory !='n'){
                add_inventory();
                cout<<"\nDo you want to want to add a new Item to the inventory?y/n:";
                cin>>want_to_add_inventory;
              } 
            }
            else if(machine_or_medicine == 'm'){
              while (want_to_add_inventory !='n'){
                add_inventory_medicines();
                cout<<"Do you want to add a new item to the inventory? y/n";
                cin>>want_to_add_inventory;
              }
            }
            else if(machine_or_medicine !='m' && machine_or_medicine!='M' && machine_or_medicine !='B'){
              cout<<"Invalid Option";
              continue;
            }
            if(machine_or_medicine == 'b' || machine_or_medicine == 'B'){
              break;
            }
          }
        }
        else if(admin_option == '3'){
          //add doctor
          char add_more_doctors_choice = 'y';
          while (add_more_doctors_choice !='n'){
            system("CLS");
            printHeader();
            add_doctors();
            cout<<"Do you want to add more Doctors?y/n:";
            cin>>add_more_doctors_choice;
          }
        }
        else if(admin_option == '4'){
          //add patient
          char add_more_patients_choice = 'y';
          while(add_more_patients_choice !='n'){
            system("CLS");
            printHeader();
            add_patients();
            cout<<"Do you want to add more patients? y/n:";
            cin>>add_more_patients_choice;
          }
        }
        else if(admin_option == '5'){
          //edit patient
          for_clearing_screen();
          string patient_id_to_check;
          string patient_cnic_to_check;
          char update_again = 'y';
          cin.ignore();
          cin.sync();
            while(update_again !='n'){
              cout<<"Enter Patient ID of patient whose details you want to edit:";
              getline(cin,patient_id_to_check);
              edit_patient_details(patient_id_to_check);
              cout<<"Do you want to update some other data y/n";
              cin>>update_again;
              if (update_again =='n'){
                break;
              }
          }
        }
        else if(admin_option == '6'){
          cin.ignore();
          cin.sync();
          for_clearing_screen();
          string doc_id;
          while(true){
            cout<<"Enter doc_id:";
            getline(cin,doc_id);
            if(doctor_id_validation(doc_id)){
              break;
            }
            else {
              cout<<"Invalid doc_id!!";
              getch();
            }
          }
          updating_doctor_details(doc_id);
        }
        else if(admin_option == 'h' || admin_option == 'H'){
          // adding helpline numbers
          string help_line_numbers_to_add;
          string whose_number;
          while(true){
            while(true){
              cout<<"\n\nEnter Helpline Number to add:";
              cin>>help_line_numbers_to_add;
              if(is_help_line_number_valid(help_line_numbers_to_add)){
                break;
              }
              else{
                cout<<"Invalid Helpline Number!!!";
                getch();
              }
            }
            while(true){
              cout<<"\n\nWhose number is this?";
              cout<<help_line_numbers_to_add;
              cin >> whose_number;
              if(name_validation(whose_number)){
                break;
              }
              else {
                cout<<"Invalid Name!!!";
                getch();
              }
            }
            for_adding_help_line_numbers(help_line_numbers_to_add,whose_number);
            cout<<"\n\nDo you want to add any more help line numbers?y/n";
            char want_to_add;
            cin >> want_to_add;
            if(want_to_add == 'n'){
              break;
            }
          }  
        }
        else if(admin_option == '7'){
          //Delete Patient Details
          for_clearing_screen();
          rang(4);
          cout<<"This Feature is only available to premium users."<<endl;
          rang(7);
          getch();
        }
        else if(admin_option == '8'){
          //Print Doctor List
          system("CLS");
          printHeader();
          print_doctor_details();
          cout<<"press any key to continue...";
          getch();
        }
        else if(admin_option == '9'){
          //Print Patient's list
          system("CLS");
          printHeader();
          print_patient_details();
          cout<<"press any key to continue...";
          getch();
        }
        else if(admin_option == 'p' ){
          //print inventory
          for_clearing_screen();
          print_inventory();
          cout<<"press any key to continue";
          getch();
          cout<<"\n\n";
        }
        else if(admin_option == 't' || admin_option == 'T'){
          string lab_test_name;
          string lab_test_price;
          string lab_test_id;
          while(true){
            cin.ignore();
            cin.sync();
            while(true){
              cout<<"\n\nEnter Lab Test Name:";
              getline(cin,lab_test_name);
              if(lab_test_name_validation(lab_test_name)){
                break;
              }
              else{
                cout<<"Invalid Lab Test Name!!!";
                getch();
              }
            }
            while(true){
              cout<<"\n\nEnter the price of "<<lab_test_name<<":";
              getline(cin,lab_test_price);
              if(check_for_digit(lab_test_price)){
                break;
              }
              else{
                cout<<"Invalid Lab Test Price!!!";
                getch();
              }
            }
            while(true){
              cout<<"\n\nEnter the ID of "<<lab_test_name<<":";
              getline(cin,lab_test_id);
              if(lab_test_id_validation(lab_test_id)){
                break;
              }
              else{
                cout<<"Invalid Lab Test ID!!!";
                getch();
              }
            }
            for_storing_lab_test(lab_test_name,lab_test_price,lab_test_id);
            cout<<"\n\nDo you want to add any more lab tests?y/n";
            char want_to_add;
            cin >> want_to_add;
            if(want_to_add == 'n'){
              break;
            }
          }
        }
        else if (admin_option == 'B'){
          break;
        } 
      }
      } 
      }
    }
      }
  else if(option == '2'){
    char key_to_menu;
    int login_count_patient = 0 ;
    char option_for_login;
    while(true){
    for_clearing_screen();
      cout<<"\n\nEnter 'L' to login:";
      cout<<"\n\nEnter 'B' to go back:";
      cout<<"\n\nYour Option =";
      cin>>option_for_login;
      if(  option_for_login == 'L' || option_for_login == 'l'){
        string patient_id_for_login;
        string patient_cnic_for_login;
        string patient_number_for_login;
        while(true){
          if (login_count_patient > 0){
            break;
          }
          cout<<"\n\nEnter your patient id:";
          cin>>patient_id_for_login;
          cout<<"\n\nEnter your CNIC number:";
          cin >> patient_cnic_for_login;
          cout<<"\n\nEnter your Phone number:";
          cin >> patient_number_for_login;
          if (for_patient_login(patient_id_for_login,patient_cnic_for_login,patient_number_for_login)){
            login_count_patient++;
            while(true){
              for_clearing_screen();
              print_patient_menu();
              char patient_option;
              cin >> patient_option;
              if(patient_option == '1'){
                //book an appointment
                char appointment_option;
                for_clearing_screen();
                while(true){
                  cout<<"\n\nEnter 'a' to book an appointment:\n\nEnter 'b' to go back:\n\nYour option =";
                  cin>>appointment_option;
                  if (appointment_option == 'a'){
                    string speciality_for_appointment;
                    while(true){
                      cout<<"\n\nEnter the speciality of the Doctor:";
                      cin >> speciality_for_appointment;
                      if (doctors_speciality_validation(speciality_for_appointment)){
                        if (doctor_availability(speciality_for_appointment)){
                          break;
                            // not using break as the loop 
                        }
                        else {
                          cout<<"\nSorry "<<speciality_for_appointment<<" is not available right now \n\nPress any other key to continue....";
                          getch();
                        }
                      }
                      else {
                        cout<<"Invalid speciality!!";
                        getch();
                      } 
                    }  
                    while(true){
                      string doctor_file_name = for_retrieving_doctor_id(speciality_for_appointment) + ".txt";
                      if (for_checking_appointment_validity(doctor_file_name,patient_id_for_login)){
                      for_storing_appointments(doctor_file_name,patient_id_for_login);
                      int doctor_fee = for_pulling_out_fee_of_doctor(speciality_for_appointment);
                      to_store_earned_money(doctor_fee);
                      for_clearing_screen();
                      cout<<"Plz Pay ";
                      rang(2);
                      cout<<doctor_fee;
                      rang(7);
                      cout<<" PKR at the cash counter ";
                      rang(4);
                      cout<<"within 1 hour";
                      rang(7);
                      cout<<" to avoid any inconvenience."<<endl;
                      getch();
                      break;
                      }
                      else {
                        cout<<"You have already booked the appointment...";
                        getch();
                        break;
                      }
                    }
                  }
                  else if (appointment_option == 'b'){
                    break;
                  }
                  else {
                  cout<<"invalid option";
                  getch();
                  } 
                }
              }             
              else if (patient_option == '2'){
                for_displaying_patient_details(patient_id_for_login);
                getch();
              }
              else if (patient_option == '3'){
                print_lab_tests();
                getch();
                string test_id_for_booking;
                while (true){
                  cout<<"Enter the Test ID to book test";
                  cin >> test_id_for_booking;
                  if(lab_test_id_validation_booking(test_id_for_booking)){
                    break;
                  }
                  else {
                    cout<<"Invalid Test ID!!";
                    getch();
                  }
                }
                string test =  for_pulling_out_test_name(test_id_for_booking); 
                string bill =  for_calculating_bill(test_id_for_booking);
                print_bill_for_lab_lest(test, bill);
              }
              else if (patient_option == '4'){
                // to contact support
                for_displaying_help_line_numbers();
              }
              else if (patient_option == '5'){
                //to buy medicine
                string medicine_to_buy;
                string medicine_quantity_to_buy;
                while(true){
                  for_clearing_screen();
                  display_medicine_for_buying();
                  cin.ignore();
                  cin.sync();
                  while(true){
                    cout<<"\n\nEnter the name of medicine you want to buy:";
                    getline(cin,medicine_to_buy);
                    if (medicine_name_validation_for_buying(medicine_to_buy)){
                      break;
                    }
                    else {
                      cout<<"Invalid medicine name!!";
                      getch();
                    }
                  }
                  while(true){
                    cout<<"\n\nEnter the Quantity:";
                    getline(cin,medicine_quantity_to_buy);
                    if (medicine_quantity_validation_for_buying(medicine_to_buy,medicine_quantity_to_buy)){
                      break;
                    }
                    else {
                      cout<<"Invalid medicine quantity!!";
                      getch();
                    }
                  }
                  update_medicine_data_quantity(stoi(medicine_quantity_to_buy),medicine_to_buy);
                  int price = for_pulling_out_price(medicine_to_buy);
                  priceA[counter_for_printing_bill] = price;
                  medicineA[counter_for_printing_bill] = medicine_to_buy;
                  quantityA[counter_for_printing_bill] = stoi(medicine_quantity_to_buy);
                  counter_for_printing_bill++;
                  cout<<"Do you want to purchase more medicines?y/n";
                  char want_to_add;
                  cin >> want_to_add;
                  if(want_to_add == 'n'){
                    break;
                  }
                }
                print_bill_for_medicines(medicineA,quantityA,priceA);
                counter_for_printing_bill = 0;
                  //calculating bill of the medicines
              }
              else if (patient_option == 'B' || patient_option == 'b'){
                break;
              }
              else {
                cout<<"Invalid option....";
                getch();
              }
            }
          }
          else{
            cout<<"\nInvalid CNIC or Phone Number....";
            getch();
          }
        }   
        }      
      else if( option_for_login == 'B' || option_for_login == 'b'){
        break;
      }
      else {
      cout<<"Invalid.....";
      cin.clear(); // clear the input buffer
      cin.ignore(10000, '\n'); // ignore any remaining characters in the buffer
      getch();
      }
    }
  }
  else if(option == '3'){
    char option;
    int login_count = 0;
    string doctor_id_login;
    string doctor_password_login;
    cin.ignore();
    cin.sync();
    while(true){
      for_clearing_screen();
      cout<<"Enter L to login:\n\nEnter B to go back:\n\nYour Option ==";
      cin >> option;
      if(option == 'l' || option == 'L'){
        while(true){
          if(login_count > 0){
            break;
          }
          for_clearing_screen();
          cin.ignore();
          cin.sync();
          cout<<"\n\nEnter Your Doctor ID:";
          getline(cin,doctor_id_login);
          cout<<"\n\nEnter Your Doctor Password:";
          getline(cin,doctor_password_login);
          if (for_doctor_login(doctor_id_login,doctor_password_login)){
            char doctor_option;
            login_count++;
            while(true){
              for_clearing_screen();
              print_doctor_menu();
              cin >> doctor_option;
              if(doctor_option == '1'){
                for_clearing_screen();
                //see patient_details
                string patient_id;
                while(true){
                  cin.ignore();
                  cin.sync();
                  while(true){
                    cout<<"\t\tEnter the Patient ID:";
                    getline(cin,patient_id);
                    if(doctor_id_validation(patient_id)){
                      break;
                    }
                    else {
                      cout<<"Invalid Patient ID!!";
                      getch();
                    }
                  }
                  for_displaying_patient_details(patient_id);
                  cout<<"\nDo you want to see more patient records?y/n";
                  char want_to_add;
                  cin >> want_to_add;
                  if(want_to_add == 'n'){
                    break;
                  }
                }
              }
              else if(doctor_option == '2'){
                for_clearing_screen();
                // suggest treatment
                cin.ignore();
                cin.sync();
                string patient_id;
                char needs_special_treatment = ' ';
                string prescription,tests,remarks,operation,day_of_operation,cost;
                char suggest = ' ';
                while(true){
                  string file_name = doctor_id_login + ".txt";
                  cout<<"\n\nEnter patient ID:";
                  cin >> patient_id;
                  if(doctor_id_validation(patient_id)){
                    if(patient_appointment_validation(patient_id,file_name)){
                    break;
                    }
                    else {
                      cout<<"\nHe/She has no appointment with you :(";
                      getch();
                    }
                  }
                  else {
                    cout<<"Invalid Patient ID!!";
                    getch();
                  }
                }
                cin.ignore();
                cin.sync();
                while(true){
                  cout<<"\n\nEnter Remarks:"<<endl;
                  getline(cin,remarks);
                  cout<<"\n\nDo you suggest any treatment?y/n";
                  cin >> suggest;
                  if(suggest == 'y'){
                    cout<<"\n\nPrescription:\n";
                    getline(cin,prescription);
                    cout<<"\n\nWhat tests do you suggest?"<<endl;
                    getline(cin,tests);
                    cout<<"\n\nDoes the patient need any special treatment?y/n"<<endl;
                    cin >> needs_special_treatment;
                    if(needs_special_treatment == 'y'){
                      cin.ignore();
                      cin.sync();
                      cout<<"Enter the Name of special treatment:";
                      getline(cin,operation);
                      cout<<"Enter the cost of "<<operation<<" =";
                      getline(cin,cost);
                      while(true){
                        cout << "Enter the day on which this special treatment will be performed:";
                        getline(cin,day_of_operation);
                        if(day_validation(day_of_operation)){
                          break;
                        }
                      }
                    }  
                    break;
                  }
                  else if(suggest == 'n'){
                    break;
                  }
                  else {
                    cout<<"Invalid Input!!";
                    getch();
                  }
                }
                for_displaying_doctor_treatment(remarks,prescription,tests,operation,day_of_operation,needs_special_treatment,suggest,cost);
              }
              else if(doctor_option == '3'){
                // to see doctors appointments
                string file_name = doctor_id_login + ".txt";
                for_displaying_doctor_appointment(file_name);
                getch();
              }
              else if(doctor_option == '4'){
                for_clearing_screen();
                string password;
                cin.ignore();
                cin.sync();
                while(true){
                  cout<<"\n\nEnter password: ";
                  getline(cin,password);
                  if(doctor_password_validation(password)){
                    break;
                  }
                  else {
                    cout<<"Invalid Password!!";
                    getch();
                  }
                }
              updating_doctor_password(doctor_id_login, password);
              }
              else if(doctor_option == 'B' || doctor_option == 'b'){
                break;
              }
              else {
                cout<<"Invalid option....";
                getch();
              }
            }                 
          }
          else{
            cout<<"Invalid Doctor ID or Password!!";
            getch();
          }
        }
      }

      else if (option == 'B' || option == 'b'){
        break;
      }
      else {
        cout<<"\n\nInvalid option....";
        getch();
      }
    }  
  }
  else if(option == '4'){
    break;
  }
} 
  return 0;
}

 //-----------------------------Functions--------------------------
 //-----------------------------------------------------------------
bool for_admin_login(string username,string password){
  fstream file;
  file.open("admin_info.txt",ios::in);
  if (file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      string user_name_to_check = line.substr(0,comma_position1);
      string password_to_check = line.substr(comma_position1+1,comma_position2-comma_position1-1);
      if(user_name_to_check == username && password_to_check == password){
        file.close();
        return true;
      }
    }
  }
  else{
    cout<<"Failed to open the file!!!"<<endl;
    getch();
    return false;
  }
  return false; 
}
void printHeader(){
  rang(6);
  cout<<endl<<endl;
  cout<<"  _    _                 _ _        _   __  __                                                   _      _____           _                                          "<<endl; 
  cout<<" | |  | |               (_) |      | | |  \\/  |                                                 | |    / ____|         | |                                        "<<endl;
  cout<<" | |__| | ___  ___ _ __  _| |_ __ _| | | \\  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  | (___  _   _ ___| |_ ___  _ __ ___                         "<<endl;
  cout<<" |  __  |/ _ \\/\\__| '_ \\| | __/ _` | | | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|  \\___ \\| | | / __| __/ _ \\\\'_  `_  \\           "<<endl;
  cout<<" | |  | | (_) \\__ \\ |_) | | || (_| | | | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ____) | |_| \\__ \\ ||  __/ | | | | |                     "<<endl;
  cout<<" |_|  |_|\\___/|___/ .__/|_|\\__\\__,_|_| |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| |_____/ \\__, |___/\\__\\___|_| |_| |_|             "<<endl;
  cout<<"                  | |                                             __/ |                                        __/ |                                               "<<endl;
  cout<<"                  |_|                                            |___/                                        |___/                                                "<<endl;
  cout<<endl<<endl;
  rang(7);
}
void print_main_menu(){
  rang(2);
  cout<<"Enter 1 if You are Admin:\n\nEnter 2 if you are a Patient:\n\nEnter 3 if you are a Doctor:\n\nEnter 4 if you want to close the Program:\n";
  rang(7);
}
void print_admin_menu(){
cout<<"Enter 1 to update quantity of items in inventory\n\nEnter 2 to add items to inventory\n\nEnter 3 add doctor\n\nEnter 4 to add patient details\n\nEnter 5 to edit patient details\n\nEnter 6 to edit Doctor Info:\n\nEnter 7 to delete patient details\n\nEnter 8 Print Doctor's list\n\nEnter 9 to print Patients list\n\nEnter 'p' to print inventory\n\nEnter 'h' to add helpline numbers\n\nEnter 't' to add Lab Tests\n\nEnter 'B' to go back to main menu\n";
}
void edit_inventory_machines(string machine_name,string new_quantity){
  int i = 0;
  const int size = 1000;
  string machine_nameA[size];
  string machine_quantityA[size];
  fstream file;
  file.open("machines_inventory.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      string machine_name_to_check = line.substr(0,comma_position1+1);
      string machine_quantity_to_check = line.substr(comma_position1+1,comma_position2-comma_position1-1);
      if (machine_name_to_check == machine_name){
        machine_quantity_to_check = new_quantity;
      }
      machine_nameA[i] = machine_name_to_check;
      machine_quantityA[i] = machine_quantity_to_check;
      i++;
    }
  }
  file.close(); 
  file.open("machines_inventory.txt",ios::out | ios::trunc);
  if(file.is_open()){
    for(int j=0;j<i;j++){
      file<<machine_nameA[j]<<","<<machine_quantityA[j]<<","<<endl;
    }
  }
  file.close();
}
bool machine_name_validation(string machine_name){
  fstream file;
  file.open("machines_inventory.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      string machine_name_to_check = line.substr(0,comma_position1);
      if (machine_name_to_check == machine_name){
        file.close();
        return true;
      }
    }
    file.close();
  }
  return false;
}
void for_clearing_screen(){
  system("CLS");
  printHeader();
}
void add_inventory(){
  string machine_name_to_add;
  string quantity_of_machines_to_add;
  cin.ignore();
  cin.sync();
  while(true){
    cout<<"\nEnter the Name of the Machine you want to add:";
    getline(cin,machine_name_to_add);
    if(machine_name_validation_for_adding(machine_name_to_add)){
      break;
    }
    else {
      cout<<"You have entered Invalid machine name!....";
      getch();
    }
  }
  cin.ignore();
  cin.sync();
  while(true){
    cout<<"\nEnter The quantity of the Machines you want to add:";
    getline(cin,quantity_of_machines_to_add);
    if(check_for_digit(quantity_of_machines_to_add)){
      break;
    }
    else{
      cout<<"Invalid Quantity !....";
      getch();
    }
  }    
    fstream file;   
    file.open("machines_inventory.txt",ios::app);
    if(file.is_open()){
    file << machine_name_to_add<<","<<quantity_of_machines_to_add<<","<<endl;
    file.close();
    }
}
bool medicine_name_validation(string medicine_name){ 
  int length = medicine_name.length();
  //longest medicine name is 47 characters long. I had the maximum length set to 60 just in case there comes a medicines whose length is bigger than this one, just to be sure, although this is higly unlikely
  if ( length > 60){
    return false;
  }
  if(medicine_name.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_+-/% ") != string::npos){
    return false;
  }
  fstream file;
  file.open("medicine_inventory.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      string medicine_name_to_check = line.substr(0,comma_position1);
      if(medicine_name_to_check == medicine_name){
        return false;
      }
    }
  }
  else {
    cout <<"Unable to open file!!!"<<endl;
    getch(); 
  }
  return true;
}
void edit_inventory_medicines(string medicine_name,string new_quantity,string new_price){
  fstream file;
  string medicine_nameA[size];
  string medicine_priceA[size];
  string medicine_quantityA[size];
  int i = 0;
  file.open("medicine_inventory.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      string medicine_name_to_check = line.substr(0,comma_position1);
      string new_quantity_to_check = line.substr(comma_position1+1,comma_position2-comma_position1-1);
      string new_price_to_check = line.substr(comma_position2+1,comma_position3-comma_position2-1);
      if (medicine_name_to_check == medicine_name){
        new_quantity_to_check = new_quantity;
        new_price_to_check = new_price;
      }
      medicine_nameA[i] = medicine_name_to_check;
      medicine_priceA[i] = new_price_to_check;
      medicine_quantityA[i] = new_quantity_to_check;
      i++;
    }
    file.close();
  }
  else {
    cout <<"Unable to open file!!!"<<endl;
    getch(); 
  }
  file.open("medicine_inventory.txt",ios::out | ios::trunc );
  if(file.is_open()){
    for(int j=0;j<i;j++){
      file<<medicine_nameA[j]<<","<<medicine_priceA[j]<<","<<medicine_quantityA[j]<<","<<endl;
    }
    file.close();
  }
  else {
    cout <<"Unable to open file!!!"<<endl;
    getch(); 
  }
}
void print_inventory(){
  fstream file;
  file.open("medicine_inventory.txt",ios::in);
  if(file.is_open()){
    string line;
    rang(4);
    cout<<"Medicine Name               Price               Quantity       ";
     cout<<"___________________________________________________________________________________"<<endl;
    rang(7);
    while(getline(file,line)){
      size_t comma_position1  = line.find(",");
      size_t comma_position2  = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      string medicine_name = line.substr(0,comma_position1);
      string medicine_price = line.substr(comma_position1+1,comma_position2-comma_position1-1);
      string medicine_quantity = line.substr(comma_position2+1,comma_position3-comma_position2-1);
      rang(2);
      cout<<medicine_name<<"\t\t     "<<medicine_price<<"\t\t   "<<medicine_quantity<<endl;
      rang(4);
      cout<<"___________________________________________________________________________________"<<endl;
      rang(7);
    }
    file.close();
  }
  else {
    cout <<"Unable to open file!!!"<<endl;
    getch();
    }
    file.close();
  }
void add_inventory_medicines(){
  string quantity_of_medicine_to_add;
  string medicine_name_to_add;
  string price_of_medicine_to_add;
  cin.ignore();
  cin.sync();
  while(true){
    cout<<"Enter the Name of the Medicine you want to add:";
    getline(cin,medicine_name_to_add);
    if(medicine_name_validation(medicine_name_to_add)){
      break;
    }
    else{
      cout<<"Invalid Medicine Name!....";
      getch();
    }
  }
  while(true){
    cout<<"Enter the Quantity of the Medicine you want to add:";
    getline(cin,quantity_of_medicine_to_add);
    if(check_for_digit(quantity_of_medicine_to_add)){
      break;
    }
    else{
      cout<<"Invalid Quantity!....";
      getch();
    }
  }
  while(true){
    cout<<"Enter the Price of the Medicine you want to add:";
    getline(cin,price_of_medicine_to_add);
    if(check_for_digit(price_of_medicine_to_add)){
      break;
    }
    else{
      cout<<"Invalid Price!....";
      getch();
    }
  }    
  fstream file;
  file.open("medicine_inventory.txt",ios::app);
  if(file.is_open()){
    file << medicine_name_to_add <<","<< price_of_medicine_to_add << "," << quantity_of_medicine_to_add <<"," <<endl;
    file.close();
  }
}
void print_patient_details(){
  fstream file;
  file.open("patients_info.txt",ios::in);
    if(file.is_open()){
      string line;
      while(getline(file,line)){
        size_t comma_position1 = line.find(",");
        size_t comma_position2 = line.find(",",comma_position1+1);
        size_t comma_position3 = line.find(",",comma_position2+1);
        size_t comma_position4 = line.find(",",comma_position3+1);
        size_t comma_position5 = line.find(",",comma_position4+1);
        size_t comma_position6 = line.find(",",comma_position5+1);
        size_t comma_position7 = line.find(",",comma_position6+1);  
        size_t comma_position8 = line.find(",",comma_position7+1);
        string id_of_patient = line.substr(0,comma_position1);
        string cnic = line.substr(comma_position1+1,comma_position2-comma_position1-1);
        string number = line.substr(comma_position2+1,comma_position3-comma_position2-1);
        string blood_group = line.substr(comma_position3+1,comma_position4-comma_position3-1);
        string age = line.substr(comma_position4+1,comma_position5-comma_position4-1);
        string full_name = line.substr(comma_position5+1,comma_position6 - comma_position5-1);
        string disease = line.substr(comma_position6+1,comma_position7-comma_position6-1);
        string sex = line.substr(comma_position7+1,comma_position8-comma_position7-1);
        rang(6);
        cout << "Name:"<<full_name<<endl<<endl;
        cout << "patient age:"<<age<<endl<<endl;
        cout << "Patient ID:"<<id_of_patient<<endl<<endl;
        cout << "Phone Number:"<<number<<endl<<endl;
        cout << "CNIC:"<<cnic<<endl<<endl;
        cout<< "Sex:"<<sex<<endl<<endl;
        cout<<"Blood Type:"<<blood_group<<endl<<endl;
        rang(7);
        cout<<"______________________________________________________________________"<<endl<<endl;
      }
      file.close();
    }
    else{
      cout<<"Unable to open file!";
      getch();
    }
}
void print_doctor_details(){
  fstream file;
  file.open("doctors_info.txt",ios::in);
    if(file.is_open()){
      string line;
      while(getline(file,line)){
        size_t comma_position1 = line.find(",");
        size_t comma_position2 = line.find(",",comma_position1+1);
        size_t comma_position3 = line.find(",",comma_position2+1);
        size_t comma_position4 = line.find(",",comma_position3+1);
        size_t comma_position5 = line.find(",",comma_position4+1);
        size_t comma_position6 = line.find(",",comma_position5+1);
        size_t comma_position7 = line.find(",",comma_position6+1);
        size_t comma_position8 = line.find(",",comma_position7+1);
        size_t comma_position9 = line.find(",",comma_position8+1);
        string id_of_doctor = line.substr(0,comma_position1);
        string password_of_doctor = line.substr(comma_position1+1,comma_position2-comma_position1-1);
        string speciality_of_doctor = line.substr(comma_position2+1,comma_position3-comma_position2-1);
        string full_name_of_doctor = line.substr(comma_position3+1,comma_position4-comma_position3-1);
        string cnic_of_doctor = line.substr(comma_position4+1,comma_position5-comma_position4-1);
        string phone_number = line.substr(comma_position5+1,comma_position6 - comma_position5-1);
        string age = line.substr(comma_position6+1,comma_position7-comma_position6-1);
        string gender = line.substr(comma_position7+1,comma_position8-comma_position7-1);
        string fee_of_doctor = line.substr(comma_position8+1,comma_position9-comma_position8-1);
        cout << "Doctor Name:"<<full_name_of_doctor<<endl<<endl;
        cout << "Doctor Age:"<<age<<endl<<endl<<endl;
        cout << "Doctor ID:"<<id_of_doctor<<endl<<endl;
        cout << "Fee:"<<fee_of_doctor<<endl<<endl;
        cout << "Speciality:"<<speciality_of_doctor<<endl<<endl;
        cout << "Doctor Phone Number:"<<phone_number<<endl<<endl;
        cout << "Doctor CNIC:"<<cnic_of_doctor<<endl<<endl;
        cout<<"______________________________________________________________________"<<endl;
      }
      file.close();
    }
  }
void add_doctors(){
  string doc_name_first;
  string doc_name_last;
  string doc_full_name;
  string doc_id;
  string doc_number;
  string doc_age;
  string doc_speciality;
  string doc_fee;
  string doc_password;
  string doc_cnic;
  string doc_gender;
  while(true){
    cout<<"\n\nEnter the Name of Doctor:";
    cin.clear();
    cin.ignore();
    getline(cin, doc_name_first);
    if(name_validation(doc_name_first)){
      break;
    }
    else {
      cout<<"Invalid Name...";
      getch();
    }
  }
  while(true){
    cout<<"\n\nEnter the Last name of the Doctor:";
    cin>>doc_name_last;
    if(name_validation(doc_name_last)){
      break;
    }
    else {
      cout<<"Invalid Name...";
      getch();
    }
  }
  doc_full_name = doc_name_first + " " + doc_name_last;
  while(true){
    cout<<"\n\n'M' for Male";
    cout<<"\n\n'F' for Female";
    cout<<"\n\n'C' for custom";
    cout<<"\n\nEnter Gender:";
    cin>>doc_gender;
    if(is_gender_valid(doc_gender)){
      break;
    }
    else {
      cout<<"Invalid Gender...";
      getch();
    }
  }
  while(true){
      cout<<"\n\nEnter the ID of Doctor:";
      cin>>doc_id;
      if (doctor_id_validation(doc_id)){
        break;
      }
      else {
        cout<<"ID Must less than or equal to 8 characters.....";
        getch();
      }
  }
  while(true) {
    CNIC_Rules();
    cout<<"\n\nEnter CNIC of the doctor:";
    cin >> doc_cnic;
    if(new_cnic_validity(doc_cnic)){
      break;
    }
    else {
      cout<<"Invalid CNIC...";
      getch();
    }
  }
  while(true){
    cout<<"\n\nEnter the Phone Number of Doctor:";
    cin>>doc_number;
    if(phone_number_validation(doc_number)){
      break;
    }
    else {
      cout<<"Invalid Number!";
      getch();
    }
  }
  while(true){
    cout<<"\n\nEnter the age of Doctor:";
    cin>>doc_age;
    if(doctor_age_validation(doc_age)){
      break;
    }
    else {
      cout<<"Invalid age!..";
      getch();
    }
  }
  while(true){
    cout<<"\n\nEnter the speciality of the Doctor:";
    cin>>doc_speciality;
    if(doctors_speciality_validation(doc_speciality)){
      break;
    }
    else {
      cout<<"Invalid Speciality.....";
      getch();
    }
  }
  while(true){
    cout<<"\n\nEnter the Fee of the Doctor:";
    cin>>doc_fee;
    if (doctor_fee_validation(doc_fee)){
      break;
    }
    else {
      cout<<"Invalid Fee! .....";
      getch();
    }
  }
  while(true){
    cout<<"\n\nEnter Doctor Password = ";
    cin>>doc_password;
    if(doctor_password_validation(doc_password)){
      break;
    }
    else {
      password_details();
      cout<<"Invalid Password!!!!!....";
      getch();
    }
  }
  // store the information of the doctors
  fstream file;
  file.open("doctors_info.txt", ios::app);
  if (file.is_open()){
    file << doc_id << "," << doc_password << "," << doc_speciality << "," << doc_full_name << "," << doc_cnic << "," << doc_number << "," << doc_age << "," << doc_gender << "," << doc_fee <<","<<endl;
    file.close();
  }
  else {
    cout<<"Unable to open file for storing doctors information....";
    getch();
  }
}
void add_patients(){
  string patient_id;
  string pat_name_first;
  string pat_name_last;
  string pat_number;
  string pat_blood_group;
  string pat_age;
  string pat_cnic;
  string pat_diseases;
  string pat_gender;
  while(true){
    cout<<"\n\nEnter Patient ID:";
    cin>>patient_id;
    if(doctor_id_validation(patient_id)){
      break;
    }
    else {
      cout<<"Invalid Patient ID.....";
      getch();
    }
  }
  while(true){
    cout<<"\n\nEnter Patient First Name:";
    cin>>pat_name_first;
    if(name_validation(pat_name_first)){
      break;
    }
    else {
      cout<<"Invalid Patient Name.....";
      getch();
    }
  }
  while(true){
    cout<<"\n\nEnter Patient Last Name:";
    cin>>pat_name_last;
    if(name_validation(pat_name_last)){
      break;
    }
    else {
      cout<<"Invalid Patient Name.....";
      getch();
    }
  }
  while(true){
    cout<<"\nEnter Patient Gender:";
    cin>>pat_gender;
    if(is_gender_valid(pat_gender)){
      break;
    }
    else {
      cout<<"Invalid Gender.....";
      getch();
    }
  }
  string pat_full_name = pat_name_first + " " + pat_name_last;
  while(true){
    cout<<"\n\nEnter Patient CNIC Number:";
    cin>>pat_cnic;
    if( new_cnic_validity(pat_cnic)){
      break;
    }
    else {
      cout<<"Invalid Patient CNIC Number.....";
      getch();
    }
  }
  while(true){
    cout<<"\n\nEnter Patient Blood Group";
    cin>>pat_blood_group;
    if(is_blood_group_valid(pat_blood_group)){
      break;
    }
    else {
      cout<<"Invalid Patient Blood Group.....";
      getch();
    }
  }
  while(true){
    cout<<"\n\nEnter Patient Age:";
    cin>>pat_age;
    if(is_patient_age_valid(pat_age)){
      break;
    }
    else {
      cout<<"Invalid Patient Age.....";
      getch();
    }
  }
  while(true){
    cout<<"\n\nEnter Phone Number:";
    cin>>pat_number;
    if(phone_number_validation(pat_number)){
      break;
    }
    else {
      cout<<"Invalid Phone Number.....";
      getch();
    }
  }
  while(true){
    cout<<"\n\nEnter the Diseases the patient currently has:";
    cin>>pat_diseases;
    if(is_disease_name_valid(pat_diseases)){
      break;
    }
    else {
      cout<<"Invalid Disease Name.....";
      getch();
    }
  }
  fstream file;
  file.open("patients_info.txt", ios::app);
  if (file.is_open()){
    file << patient_id <<","<< pat_cnic << "," << pat_number << "," << pat_blood_group << "," << pat_age << "," << pat_full_name << "," << pat_diseases << "," << endl;
    file.close();
  }
}
void edit_patient_details(string patient_id){
  int i = 0;
  string phone_number,New_CNIC,disease_of_patient;
  for_clearing_screen();
  cin.ignore();
  cin.sync();
  while(true){
    cout<<"\n\nEnter New CNIC Number:";
    getline(cin, New_CNIC);
    if(new_cnic_validity(New_CNIC)){
      break;
    }
    else {
      rang(4);
      cout<<"Invalid New CNIC Number.....";
      rang(7);
      CNIC_Rules();
      getch();
    }
  }
  while(true){
    cout<<"Enter New Phone Number:";
    getline(cin,phone_number);
    if(phone_number_validation(phone_number)){
      break;
    }
    else {
      cout<<"Invalid Phone Number.....";
      getch();
    }
  }
  while(true){
    cout<<"Enter Disease of the Patient:";
    getline(cin,disease_of_patient);
    if(is_disease_name_valid(disease_of_patient)){
      break;
    }
    else {
      cout<<"Invalid Disease Name.....";
      getch();
    }
  }
  string idA[size];
  string cnicA[size];
  string numberA[size];
  string bloodgroupA[size];
  string ageA[size];
  string fullnameA[size];
  string diseaseA[size];
  string sexA[size];
  fstream file;
  file.open("patients_info.txt", ios::in);
  if (file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      size_t comma_position4 = line.find(",",comma_position3+1);
      size_t comma_position5 = line.find(",",comma_position4+1);
      size_t comma_position6 = line.find(",",comma_position5+1);
      size_t comma_position7 = line.find(",",comma_position6+1);
      size_t comma_position8 = line.find(",",comma_position7+1);
      string id = line.substr(0,comma_position1);
      string cnic = line.substr(comma_position1+1,comma_position2-comma_position1-1);
      string number = line.substr(comma_position2+1,comma_position3-comma_position2-1);
      string blood_group = line.substr(comma_position3+1,comma_position4-comma_position3-1);
      string age = line.substr(comma_position4+1,comma_position5-comma_position4-1);
      string full_name = line.substr(comma_position5+1,comma_position6-comma_position5-1);
      string disease_name = line.substr(comma_position6+1,comma_position7-comma_position6-1);
      string sex = line.substr(comma_position7+1,comma_position8-comma_position7-1);
      if (patient_id == id){
        cnic = New_CNIC;
        disease_name = disease_of_patient;
        number = phone_number;
      }
      idA[i] = id;
      cnicA[i] = cnic;
      numberA[i] = number;
      bloodgroupA[i] = blood_group;
      ageA[i] = age;
      fullnameA[i] = full_name;
      diseaseA[i] = disease_name;
      sexA[i] = sex;
      i++;
    }
    file.close();
  }
  file.open("patients_info.txt",ios::out | ios::trunc );
  if(file.is_open()){
    for(int j=0;j<i;j++){
      file << idA[j] << "," << cnicA[j] << "," << numberA[j] << "," << bloodgroupA[j] << "," << ageA[j] << "," << fullnameA[j] << "," << diseaseA[j] << "," << sexA[j] <<"," << "\n";
    }
    file.close();
  }
}
bool new_cnic_validity(string New_CNIC){
    if(!isdigit(New_CNIC[0]) || !isdigit(New_CNIC[1]) || !isdigit(New_CNIC[2]) || !isdigit(New_CNIC[3]) || !isdigit(New_CNIC[4]) || New_CNIC[5] != '-' || !isdigit(New_CNIC[6]) || !isdigit(New_CNIC[7]) || !isdigit(New_CNIC[8]) || !isdigit(New_CNIC[9]) || !isdigit(New_CNIC[10]) || !isdigit(New_CNIC[11]) || !isdigit(New_CNIC[12]) || New_CNIC[13] != '-' || !isdigit(New_CNIC[14])) {
      return false;
    }
  else{
    return true;
  }
}
void CNIC_Rules(){
  cout<<"There some Rules To Enter The CNIC Numbers"<<endl;
  cout<<"CNIC Number is 13 charactors Long"<<endl;
  cout<<"CNIC Number must be written in correct format.i.e XXXXX-XXXXXXX-X"<<endl;
  cout<<"Here X represents The Number and - represents space"<<endl;
  cout<<"Press any key to continue.....";
  getch();
}
bool for_returning_back( char b){
  cout<<"\nEnter B to get back";
  if ( b == 'B' || b == 'b'){
    return true;
  }
}
void print_patient_menu(){
  cout<<"\n\nEnter 1 to Book an appointment:";
  cout<<"\n\nEnter 2 to see your details:";
  cout<<"\n\nEnter 3 to for a private lab test ";
  cout<<"\n\nEnter 4 to to contact support:";
  cout<<"\n\nEnter 5 to buy medication:";
  cout<<"\n\nEnter 'b' for going back: ";
  cout<<"\n\nYour option =";
}
void print_doctor_menu(){

  cout<<"\n\nEnter 1 to see patient details:";
  cout<<"\n\nEnter 2 to suggest treatment to patient";
  cout<<"\n\nEnter 3 to see patients appointments with you";
  cout<<"\n\nEnter 4 to change your password:";
  cout<<"\n\nEnter B to go Back:";
  cout<<"\n\nYour option = ";
}
bool name_validation( string doc_name_first){
  int length = doc_name_first.length();
  for (int idx = 0 ; idx < length ; idx++){
    if(!isalpha(doc_name_first[idx])){
      return false;
    }
  }
  return true;
}
bool doctor_id_validation(string doc_id){
  int length = doc_id.length();
  if (length != 7){
    return false;
  }
  if(doc_id.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_") != string::npos){
    return false;
  }
  return true;
}
bool phone_number_validation(string doc_number){
  int length = doc_number.length();
  if ( length != 11 ){
    return false;
  }
  for(int idx = 0 ; idx < length ; idx++){
    if (!isdigit(doc_number[idx])){
      return false;
    }
  }
  return true;
}
bool doctor_age_validation(string doc_age){
  int length = doc_age.length();
  if (length !=2){
    return false;
  }
  if (!isdigit(doc_age[0]) || !isdigit(doc_age[1])){
    return false;
  }
  return true;
}
bool doctors_speciality_validation(string doc_speciality){
  bool flag = true;
  int length = doc_speciality.length();
  for (int idx = 0 ; idx < length ; idx++){
    if(!isalpha(doc_speciality[idx])){
      flag = false;
    }
  }
  return flag;
}
bool doctor_fee_validation(string doc_fee){
  int length = doc_fee.length();
  for (int idx = 0 ; idx < length ; idx++){
    if(!isdigit(doc_fee[idx])){
      return false;
    }
  }
  return true;
}
bool doctor_password_validation(string doc_password){
  int length = doc_password.length();
  for (int idx = 0 ; idx < length ; idx++){
    if(doc_password[idx] == ','){
      return false;
    }
  }
  if (length < 8 || length > 14){
    return false;
  }
  return true;
}
void password_details(){
  cout<<"\nPassword Must be atleast 8 characters Long"<<endl;
  cout<<"Password Must not exceed 14 character limit"<<endl;
}
bool check_for_digit(string quantity){
  int length = quantity.length();
  if ( length > 8 ){
    return false;
  }
  for (int idx = 0 ; idx < length ; idx++){
    if(!isdigit(quantity[idx])){
      return false;
    }
  }
  return true;
} 
bool machine_name_validation_for_adding(string machine_name_to_add){
  if(machine_name_to_add.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_/%()- ") != string::npos){
    return false;
  }
  fstream file;
  file.open("machines_inventory.txt");
  if(file.is_open()){
    string line;
    while(getline(file, line)){
      size_t comma_position1 = line.find(",");
      string machine_name = line.substr(0, comma_position1);
      if(machine_name == machine_name_to_add){
        file.close();
        return false;
      }
    }
    file.close();
    }
  file.close();
  return true;
}
bool is_admin_user_name_valid(string username_for_signup){
  fstream file;
  int length = username_for_signup.length();
  /*find_first_not_of() function string::npos return karta hai agar usko koi aaisa character na milay jo
  set of characters ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_") kay ilawa ho ! 
  Dosri taraf jab usay koi bahir ka character mil jaiy (set of characters kay ilawa) to yay us character ki 
  position (string kay andar jo position hoti hai) return kardeta hai.
  Hum chahtain hain kay hum pehlay hi check karlain kay kiya function string::npos kay ilawa koi value return nai
  karrha hai, agar function string::npos kay ilawa koi value return karrha hai to return false; hojana chahyai 
  kyunkay username main sirf wahi characters honain chahyai jo humnain allow kiya hoay hain 👇👇👇 */
  if(username_for_signup.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_") != string::npos ){
    return false;
  }
  file.open("admin_info.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file, line)){
      size_t comma_position1 = line.find(",",0);
      /*substr() divide string into parts, it takes two arguments starting position of the string and the length 
      of the string*/
      string user_name_to_check = line.substr(0,comma_position1);
      if(user_name_to_check == username_for_signup){
        return false;
      }
    }
  }
  file.close();
  return true;
}
bool is_valid_password(string password_for_signup){
  int length = password_for_signup.length();
  if (length < 8){
    return false;
  }
  for (int idx = 0 ; idx < length ; idx++){
    if(password_for_signup[idx] == ','){
      return false;
    }
  }
  if ((password_for_signup.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) && (password_for_signup.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos) && (password_for_signup.find_first_not_of("0123456789") != string::npos) && (password_for_signup.find_first_not_of("!$%&()*+-./:;<=>?@[\\]^_`{|}~") != string::npos)) {
    return true;    
  }
  return false;
}
void rang(char color1){
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color1);
}
bool is_gender_valid(string gender){
  int length = gender.length();
  if (length > 1){
    return false;
  }
  if (gender == "M" || gender == "m" || gender == "F" || gender == "f" || gender == "C" || gender == "c"){
    return true;
  }
  return false;
}
bool is_blood_group_valid(string blood_group){
  int length = blood_group.length();
  if (length > 3){
    return false;
  }
  if (blood_group == "A+" || blood_group == "A-" || blood_group == "B+" || blood_group == "B-" || blood_group == "O+" || blood_group == "O-" || blood_group == "AB+" || blood_group == "AB-"){
    return true;
  }
  return false;
}
bool is_patient_age_valid(string pat_age){
  int length = pat_age.length();
  if (length > 3){
    return false;
  }
  for (int idx = 0; idx < length ; idx++){
    if (!isdigit(pat_age[idx])){
      return false;
    }
  }
  return true;
}
bool is_disease_name_valid(string pat_diseases){
  int length = pat_diseases.length();
  for (int idx = 0; idx < length; idx++){
    if (pat_diseases[idx] ==','){
      return false;
    }
    if (pat_diseases.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_-") == string::npos){
      return true;
    }

  }
  return false;
} 
bool for_patient_login(string id,string cnic, string number){
  fstream file;
  file.open("patients_info.txt",ios::in);
  if (file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      string patient_id = line.substr(0,comma_position1);
      string patient_cnic = line.substr(comma_position1+1,comma_position2-comma_position1-1);
      string patient_number = line.substr(comma_position2+1,comma_position3-comma_position2-1);
      if(patient_cnic == cnic && patient_id == id && patient_number == number){
        file.close();
        return true;
      }
    }
  }
  else{
    cout<<"Failed to open the file!!!"<<endl;
    getch();
    return false;
  }
  return false;
}
string for_retrieving_doctor_id(string speciality){
  fstream file;
  file.open("doctors_info.txt",ios::in);
  if (file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      string id_of_doctor = line.substr(0,comma_position1);
      string speciality_for_appointment = line.substr(comma_position2+1,comma_position3-comma_position2-1);
      if(speciality == speciality_for_appointment){
        file.close();
        return id_of_doctor;
      }
    }
  }
}
bool doctor_availability(string speciality){
  fstream file;
  file.open("doctors_info.txt",ios::in);
  if (file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      string speciality_for_appointment = line.substr(comma_position2+1,comma_position3-comma_position2-1);
      if(speciality_for_appointment == speciality){
        file.close();
        return true;
      }
    }
  }
  file.close();
  return false;
}
void for_storing_appointments(string doctor_file_name,string patient_id){
  fstream file;
  file.open(doctor_file_name,ios::app);
  if(file.is_open()){
    string line = patient_id;
    file <<endl<<patient_id;
    file.close();
  }
  else{
    cout<<"\nFailed to open the file!!!"<<endl;
    getch();
  }
} 
int for_pulling_out_fee_of_doctor(string speciality){
  fstream file;
  file.open("doctors_info.txt",ios::in);
  if (file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      size_t comma_position4 = line.find(",",comma_position3+1);
      size_t comma_position5 = line.find(",",comma_position4+1);
      size_t comma_position6 = line.find(",",comma_position5+1);
      size_t comma_position7 = line.find(",",comma_position6+1);
      size_t comma_position8 = line.find(",",comma_position7+1);
      size_t comma_position9 = line.find(",",comma_position8+1);
      string speciality_for_appointment = line.substr(comma_position2+1,comma_position3-comma_position2-1);
      int fee_of_doctor = stoi(line.substr(comma_position8+1,comma_position9+1-comma_position8-1));
      if(speciality == speciality_for_appointment){
        return fee_of_doctor;
        file.close();
      }
    }
  }
  else {
    cout<<"Failed to open the file!!!"<<endl;
    getch();
  }
}
void to_store_earned_money(int amount){
  fstream file;
  file.open("earned_money.txt",ios::app);
  if(file.is_open()){
    file << amount << endl;
    file.close();
  }
  else{
    cout<<"\nFailed to open the file!!!"<<endl;
    getch();
  }
}
bool for_checking_appointment_validity(string doctor_file_name,string patient_id){
  fstream file;
  file.open(doctor_file_name,ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      if (line == patient_id){
        file.close();
        return false;
      }
    }
    file.close();
  }
  return true;
}
void for_displaying_patient_details(string patient_id){
  fstream file;
  file.open("patients_info.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      size_t comma_position4 = line.find(",",comma_position3+1);
      size_t comma_position5 = line.find(",",comma_position4+1);
      size_t comma_position6 = line.find(",",comma_position5+1);
      size_t comma_position7 = line.find(",",comma_position6+1);
      size_t comma_position8 = line.find(",",comma_position7+1);
      string patient_id_to_print = line.substr(0,comma_position1);
      string patient_cnic_to_print = line.substr(comma_position1 +1,comma_position2  - comma_position1-1);
      string patient_number_to_print = line.substr(comma_position2 +1,comma_position3 - comma_position2-1);
      string patient_blood_group_to_print = line.substr(comma_position3 +1,comma_position4 - comma_position3-1);
      string patient_age_to_print = line.substr(comma_position4 +1,comma_position5 - comma_position4-1);
      string patient_name_to_print = line.substr(comma_position5 +1,comma_position6 - comma_position5-1);
      string patient_disease_to_print = line.substr(comma_position6+1,comma_position7 - comma_position6-1);
      string patient_gender_to_print = line.substr(comma_position7+1,comma_position8 - comma_position7-1);
      if(patient_id == patient_id_to_print){
        cout <<"----------------------------------------------"<<endl;
        cout << "Name: " << patient_name_to_print << endl;
        cout << "CNIC: " << patient_cnic_to_print << endl;
        cout << "Blood Group: " << patient_blood_group_to_print << endl;
        cout << "Phone:" << patient_number_to_print << endl;
        cout << "Age: " << patient_age_to_print << endl;
        cout << "Gender: " << patient_gender_to_print << endl;
        cout << "Disease: " << patient_disease_to_print << endl;
        cout << "----------------------------------------------"<<endl;
        cout << "...";
        file.close();
        getch();
      }
    }
  }
  else {
    cout<<"\nFailed to open the file!!!"<<endl;
    getch();
  }
}
void for_adding_help_line_numbers(string number,string purpose ){
  fstream file;
  file.open("help_line_numbers.txt",ios::app);
  if(file.is_open()){
    file << number << "," << purpose << endl;
    file.close();
  }
  else {
    cout<<"\nFailed to open the file!!!"<<endl;
    getch();
  }
}
bool is_help_line_number_valid(string number){
  int length = number.length();
  if (length > 14 || length < 2){
    return false;
  }
  if(number.find_first_not_of("1234567890-") != string::npos){
    return false;
  }
  fstream file;
  file.open("help_line_numbers.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      if(line == number){
        return false;
      }
    }
  }
  else {
    cout<<"\nFailed to open the file!!!"<<endl;
    getch();
  }
  return true;
}  
void for_displaying_help_line_numbers(){
  fstream file;
  file.open("help_line_numbers.txt",ios::in);
  if(file.is_open()){
    string line;
    cout<<"---------------------------------------------------------------"<<endl;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      string help_line_number_to_display = line.substr(0,comma_position1);
      string purpose_of_number = line.substr(comma_position1+1,comma_position2 - comma_position1-1);
      cout<<purpose_of_number<<  ": " << help_line_number_to_display << endl;
    }
    cout<<"----------------------------------------------------------------"<<endl;
    file.close();
    getch();
  }
}
bool lab_test_name_validation(string lab_test){
  int validation_count = 0;
  int length = lab_test.length();
  if (length > 60  || length < 2){
    return false;
  }
  if(lab_test.find_first_not_of("1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_/()- ")!= string::npos){
    return false;
  }
  return true;
}
void for_storing_lab_test(string lab_test,string price,string id){
  fstream file;
  file.open("lab_tests.txt",ios::app);
  if(file.is_open()){
    file << id << ","<< lab_test << "," << price << "," << endl;
    file.close();
  }
  else {
    cout<<"\nFailed to open the file!!!"<<endl;
    getch();
  }
}
void print_lab_tests(){
  fstream file;
  file.open("lab_tests.txt",ios::in);
  if(file.is_open()){
    string line;
    cout<<"________________________________________________________________________"<<endl;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      string lab_test_id_to_print = line.substr(0,comma_position1);
      string lab_test_name_to_print = line.substr(comma_position1+1,comma_position2 - comma_position1-1);
      string price_to_print = line.substr(comma_position2+1,comma_position3 - comma_position2-1);
      cout<<"\nID:"<< lab_test_id_to_print <<"\nTest Name:"<<lab_test_name_to_print<<"\nPrice:"<<price_to_print;
      cout<<"________________________________________________________________________"<<endl;
      getch();
    }
    cout<<"________________________________________________________________________"<<endl;
    file.close();
  }
  else {
    cout<<"\nFailed to open the file!!!"<<endl;
    getch();
  }
}
bool lab_test_id_validation(string lab_test_id){
  int length = lab_test_id.length();
  if (length > 3){
    return false;
  }
  for(int idx = 0; idx < length; idx++){
    if(!isdigit(lab_test_id[idx])){
      return false;
    }
  }
  return true;
} 
bool lab_test_id_validation_booking(string lab_test_id){
  int length = lab_test_id.length();
    if (length > 3){
    return false;
  }
  for(int idx = 0; idx < length; idx++){
    if(!isdigit(lab_test_id[idx])){
      return false;
    }
  }
  return true;
}
string for_calculating_bill(string lab_test_id){
  fstream file;
  file.open("lab_tests.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      string lab_test_id_to_check = line.substr(0,comma_position1);
      string lab_test_name = line.substr(comma_position1+1,comma_position2 - comma_position1-1);
      string price = line.substr(comma_position2+1,comma_position3 - comma_position2-1);
      if(lab_test_id_to_check == lab_test_id){
        file.close();
        return price;        
      }
    }
  }
  else {
    cout<<"\nFailed to open the file!!!"<<endl;
    getch();
  }  
}
string for_pulling_out_test_name(string lab_test_id){
    fstream file;
  file.open("lab_tests.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      string lab_test_id_to_check = line.substr(0,comma_position1);
      string lab_test_name = line.substr(comma_position1+1,comma_position2 - comma_position1-1);
      if(lab_test_id_to_check == lab_test_id){
        file.close();
        return lab_test_name;        
      }
    }
  }
  else {
    cout<<"\nFailed to open the file!!!"<<endl;
    getch();
  }
}
void print_bill_for_lab_lest(string test,string bill){
  for_clearing_screen();
  cout<<"Your selected Test "<< test << " has been booked successfully :D"<<endl<<endl;
  cout<<"Please Pay "<<bill<<" PKR"<<" at the cash counter :) "<<endl<<endl;
  getch();
}
void display_medicine_for_buying(){
  fstream file;
  file.open("medicine_inventory.txt",ios::in);
  if(file.is_open()){
    string line;
    cout<<"Name of Medicine        Price           Remaining Quantity"<<endl;
     cout<<"_____________________________________________________________________"<<endl;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      string medicine_name_to_print = line.substr(0,comma_position1);
      string medicine_price_to_print = line.substr(comma_position1+1,comma_position2 - comma_position1-1);
      string medicine_quantity_to_print = line.substr(comma_position2+1,comma_position3 - comma_position2-1);
      cout<<medicine_name_to_print<<"\t\t\t"<<medicine_price_to_print<<"\t\t"<<medicine_quantity_to_print<<endl;
      cout<<"_____________________________________________________________________"<<endl;
    }
    cout<<"*********************************************************************"<<endl;
    file.close();
  }
}
bool medicine_name_validation_for_buying(string medicine_name){
  int length = medicine_name.length();
  if ( length > 60){
    return false;
  }
  if(medicine_name.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_+-/% ") != string::npos){
    return false;
  }
  fstream file;
  file.open("medicine_inventory.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      string medicine_name_to_check = line.substr(0,comma_position1);
      if(medicine_name_to_check == medicine_name){
          file.close();
          return true;
        }
      }
      file.close();
    }
  else {
    cout<<"\nFailed to open the file!!!"<<endl;
    getch();
  }
  return false;
}
bool medicine_quantity_validation_for_buying(string medicine_name,string medicine_quantity_to_buy){
  int length = medicine_quantity_to_buy.length();
  if ( length > 9){
    return false;
  }
  if(medicine_quantity_to_buy.find_first_not_of("0123456789") != string::npos){
    return false;
  }
  fstream file;
  file.open("medicine_inventory.txt",ios::in|ios::out);
  if(file.is_open()){
    string line;
    file.seekg(0,ios::beg);
    while(getline(file,line)){
      int medicineq = stoi(medicine_quantity_to_buy);
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      string medicine_name_to_check = line.substr(0,comma_position1);
      string medicine_price = line.substr(comma_position1+1,comma_position2 - comma_position1-1);
      int medicine_quantity_to_check = stoi(line.substr(comma_position2+1,comma_position3 - comma_position2-1));
      if(medicine_name_to_check == medicine_name){
        if(medicine_quantity_to_check >= medicineq){
          file.close();
          return true;
        }
        else{
          file.close();
          return false;
        }

      }
    }
  }
  else {
    cout<<"\nFailed to open the file!!!"<<endl;
    getch();
  }
  return false;
}
int for_pulling_out_price(string medicine_name){
  fstream file;
  file.open("medicine_inventory.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      string medicine_name_to_check = line.substr(0,comma_position1);
      if(medicine_name_to_check == medicine_name){
        file.close();
        return stoi(line.substr(comma_position1+1,comma_position2 - comma_position1-1));
      }
    }
    file.close();
  }
  else {
    cout <<"Unable to open file!!!" <<endl;
    getch();
  }
  return 0;
}
void print_bill_for_medicines(string medicineA[],int quantityA[],int priceA[]){
  int total_bill = 0;
  cout<<"Medicine Name   Quantity        Price           Bill"<<endl;
  for (int idx = 0 ; idx < counter_for_printing_bill ; idx ++){
  cout<<medicineA[idx]<<"\t\t"<<quantityA[idx]<<"\t\t"<<priceA[idx]<<"\t\t"<<quantityA[idx]*priceA[idx]<<"\n";
  total_bill += quantityA[idx]*priceA[idx];
  }
  rang(2); 
  cout<<"\nTOTAL BILL = "<<total_bill<<endl;
  rang(7);
  getch();
}
bool patient_appointment_validation(string id,string doctor_file_name){
  fstream file;
  file.open(doctor_file_name,ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      if(line == id){
        file <<endl<<"                                   ";
        file.close();
        return true;
      }
    }  
     return false;      
  }
  else{
    cout <<"unable to open file!!!"<<endl;
    getch();
    return false;
  }
}
bool day_validation(string day){
  int length = day.length();
  if (length > 7){
    return false;
  }
  for (int idx = 0 ; idx < length ; idx++){
    if(!isalpha(day[idx])){
     return false;
    }
  }
  transform(day.begin(), day.end(), day.begin(), ::tolower);
  if ( day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday" || day == "saturday" || day == "sunday" ){
    return true;
  }
  else {
    rang(4);
    cout<<"\nmake sure the caps lock isnt turned on!!";
    rang(7);
  }
  return false;
}
void for_displaying_doctor_treatment(string remarks,string prescription,string tests,string operation,string day,char needs_special_treatment,char suggest,string cost ){
  for_clearing_screen(); 
  cout<<"\n\n";
  rang(6);
  cout<<"___________________________________________________________________________________________________________\n\n";
  rang(7);
  cout<<"Remarks:\n";
  cout<<remarks<<"\n";
  if(suggest == 'y'){
    rang(2);
    cout<<"\n\nPrescription:\n\n";
    rang(7);
    cout<<prescription<<endl;
    cout<<"\nTests:\n";
    rang(7);
    cout<<tests<<endl;
    if(needs_special_treatment == 'y' ){
      rang(4);
      cout<<operation<<" ";
      rang(7);
      cout<<"Will be performed on ";
      rang(2);
      cout<<day;
      rang(7);
      cout<<"\n\nPlease Pay ";
      rang(3);
      cout<<cost;
      rang(7);
      cout<<" PKR within one hour at the counter to avoid any inconvenience :)"<<endl;
      rang(6);
      cout<<"___________________________________________________________________________________________________________\n";
      rang(7);
      getch();
    }                        
  }
}
void for_displaying_doctor_appointment(string file_name){
  fstream file;
  file.open(file_name,ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      cout<<line<<endl;
    }
  }
  else{
    cout <<"unable to open file!!!"<<endl;
    getch();
  }
}
void updating_doctor_password(string id,string password){
  int i = 0;
  const int size = 200;
  string doc_idA[size];
  string doc_passA[size];
  string doc_specialityA[size];
  string doc_nameA[size];
  string doc_cnicA[size];
  string doc_numberA[size];
  string doc_ageA[size];
  string doc_genderA[size];
  string doc_feeA[size];
  fstream file;
  file.open("doctors_info.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      size_t comma_position4 = line.find(",",comma_position3+1);
      size_t comma_position5 = line.find(",",comma_position4+1);
      size_t comma_position6 = line.find(",",comma_position5+1);
      size_t comma_position7 = line.find(",",comma_position6+1);
      size_t comma_position8 = line.find(",",comma_position7+1);
      size_t comma_position9 = line.find(",",comma_position8+1);
      string id_of_doctor = line.substr(0,comma_position1);
      string password_of_doctor = line.substr(comma_position1+1,comma_position2-comma_position1-1);
      string speciality_of_doctor = line.substr(comma_position2+1,comma_position3-comma_position2-1);
      string full_name_of_doctor = line.substr(comma_position3+1,comma_position4-comma_position3-1);
      string cnic_of_doctor = line.substr(comma_position4+1,comma_position5-comma_position4-1);
      string phone_number = line.substr(comma_position5+1,comma_position6 - comma_position5-1);
      string age = line.substr(comma_position6+1,comma_position7-comma_position6-1);
      string gender = line.substr(comma_position7+1,comma_position8-comma_position7-1);
      string fee_of_doctor = line.substr(comma_position8+1,comma_position9-comma_position8-1);
      if(id_of_doctor == id){
        password_of_doctor = password;
      }
      doc_idA[i] = id_of_doctor;
      doc_passA[i] = password_of_doctor;
      doc_specialityA[i] = speciality_of_doctor;
      doc_nameA[i] = full_name_of_doctor;
      doc_cnicA[i] = cnic_of_doctor;
      doc_numberA[i] = phone_number;
      doc_ageA[i] = age;
      doc_genderA[i] = gender;
      doc_feeA[i] = fee_of_doctor;
      i++;
    }
    file.close();        
  }
  file.open("doctors_info.txt",ios::out | ios::trunc);
  if(file.is_open()){
    for(int j=0;j<i;j++){
      file<<doc_idA[j]<<","<<doc_passA[j]<<","<<doc_specialityA[j]<<","<<doc_nameA[j]<<","<<doc_cnicA[j]<<","<<doc_numberA[j]<<","<<doc_ageA[j]<<","<<doc_genderA[j]<<","<<doc_feeA[j]<<","<<endl;
    }
  }
}
void update_medicine_data_quantity(int quantity,string medicine_name){
  int i = 0;
  const int size = 1000;
  string medicine_nameA[size];
  string medicine_priceA[size];
  string medicine_quantityA[size];
  fstream file;
  file.open("medicine_inventory.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){  
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      string medicine_name_to_check = line.substr(0,comma_position1);
      string price_of_medicine = line.substr(comma_position1+1,comma_position2 - comma_position1-1);
      string quantity_of_medicine = line.substr(comma_position2+1,comma_position3 - comma_position2-1);     
      if(medicine_name_to_check == medicine_name){
        quantity_of_medicine = to_string(stoi(quantity_of_medicine) - quantity);
      }
      medicine_nameA[i] = medicine_name_to_check;
      medicine_priceA[i] = price_of_medicine;
      medicine_quantityA[i] = quantity_of_medicine;
      i++;
    }
    file.close();
  }
  file.seekg(ios::beg);
  file.open("medicine_inventory.txt",ios::out | ios::trunc);
  if(file.is_open()){
    for(int j=0;j<i;j++){
      file<<medicine_nameA[j]<<","<<medicine_priceA[j]<<","<<medicine_quantityA[j]<<endl;
    }
  }
  file.close();
}
bool for_doctor_login(string id,string password){
  fstream file;
  file.open("doctors_info.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      string id_to_check = line.substr(0,comma_position1);
      string password_to_check = line.substr(comma_position1+1,comma_position2 - comma_position1-1);
      if(id_to_check == id && password_to_check == password){
        file.close();
        return true;
      }
    }
    file.close();
  }
  else {
    cout <<"unable to open file!!!"<<endl;
    getch();
    return false;
  }
  return false;
}
void updating_doctor_details(string id){
  cin.ignore();
  cin.sync();
  int i = 0;
  string idA[size];
  string passwordA[size];
  string specialityA[size];
  string nameA[size];
  string cnicA[size];
  string numberA[size];
  string ageA[size];
  string sexA[size];
  string fee_to_addA[size];
  string fee,phone_number;
  while(true){
    cout<<"Enter New Fee of Doctor:";
    getline(cin,fee);
    if(doctor_fee_validation(fee)){
      break;
    }
    else{
      cout<<"Invalid Fee!!";
      getch();
    }
  }
  while(true){
    cout<<"\nEnter New Phone Number:";
    getline(cin,phone_number);
    if(phone_number_validation(phone_number)){
      break;
    }
    else{
      cout<<"Invalid Phone Number!!";
      getch();
    }
  }
  fstream file;
  file.open("doctors_info.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      size_t comma_position2 = line.find(",",comma_position1+1);
      size_t comma_position3 = line.find(",",comma_position2+1);
      size_t comma_position4 = line.find(",",comma_position3+1);
      size_t comma_position5 = line.find(",",comma_position4+1);
      size_t comma_position6 = line.find(",",comma_position5+1);
      size_t comma_position7 = line.find(",",comma_position6+1);
      size_t comma_position8 = line.find(",",comma_position7+1);
      size_t comma_position9 = line.find(",",comma_position8+1);
      string id_to_check = line.substr(0,comma_position1);
      string password = line.substr(comma_position1+1,comma_position2-comma_position1-1);
      string speciality = line.substr(comma_position2+1,comma_position3-comma_position2-1);
      string name = line.substr(comma_position3+1,comma_position4-comma_position3-1);
      string cnic = line.substr(comma_position4+1,comma_position5-comma_position4-1);
      string number = line.substr(comma_position5+1,comma_position6-comma_position5-1);
      string age = line.substr(comma_position6+1,comma_position7 - comma_position6-1);
      string sex = line.substr(comma_position7+1,comma_position8 - comma_position7-1);
      string fee_to_add = line.substr(comma_position8+1,comma_position9 - comma_position8-1);
      if (id_to_check == id){
        number = phone_number;
        fee_to_add = fee;  
      }
      idA[i] = id_to_check;
      passwordA[i] = password;
      specialityA[i] = speciality;
      nameA[i] = name;
      cnicA[i] = cnic;
      numberA[i] = number;
      ageA[i] = age;
      sexA[i] = sex;
      fee_to_addA[i] = fee_to_add;
      i++;     
    }
    file.close();
  }
  else{
    cout<<"Unable to open file";
    getch();
  }
  file.open("doctors_info.txt",ios::out | ios::trunc);
  if(file.is_open()){
    for(int j=0;j<i;j++){
      file<<idA[j]<<","<<passwordA[j]<<","<<specialityA[j]<<","<<nameA[j]<<","<<cnicA[j]<<","<<numberA[j]<<","<<ageA[j]<<","<<sexA[j]<<","<<fee_to_addA[j]<<","<<endl;
    } 
    file.close();
  }
}
bool medicine_name_validation_edit(string medicine_name){
  int length = medicine_name.length();
  //longest medicine name is 47 characters long. I had the maximum length set to 60 just in case there comes a medicines whose length is bigger than this one, just to be sure, although this is higly unlikely
  if ( length > 60){
    return false;
  }
  if(medicine_name.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_+-/% ") != string::npos){
    return false;
  }
  fstream file;
  file.open("medicine_inventory.txt",ios::in);
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      size_t comma_position1 = line.find(",");
      string medicine_name_to_check = line.substr(0,comma_position1);
      if(medicine_name_to_check == medicine_name){
        return true;
      }
    }
  }
  else {
    cout <<"Unable to open file!!!"<<endl;
    getch(); 
  }
  return false;
}
