#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
void printHeader();
void print_main_menu();
void print_admin_menu();
char for_selecting_options();
void print_admin_menu1();
const int size=100;
int login_count  = 0;
string admin[size]={"m","d","a","t","r"};
string passwordA[size]={"123","345","456","789","1011"};
int inventory_count = 5;
string inventory[size] = {"MRI-Machine","X-ray","Ultrasound-Machine","Massagers","Ventilaters"};
int inventory_items[size]={3,4,10,40,2};
int medicine_inventory_count = 5;
string inventory_medicines[size]={"Aspirin","Insulin","Penicillin","Tamiflu","Lipitor"};
int inventory_medicines_quantity[size]={1000,90,0,19,300};
int inventory_medicines_price[size]={10,45,1,100,4};
int doctor_count = 5;
string doctors_name[size] = {"Mohsin","Ali","Ayesha","Sadia","Mujeeb"};
string doctor_id[size] = {"mohsin123","ali123","ayeshass","sadia123","Mujeeb14"};
string doctor_password[size]= {"mohsin1","ali10","ayeshass2","sadia123","@mujeeb" };
string doctors_speciality[size] = {"Phychologist","Urologist","Child-Specialist","Dermatologist","Neurologist"};
int doctor_fee[size]= {100,50,55,70,90};
int doctor_age[size]= {47,50,29,45,78};
string doctor_number[size] = {"000","001","002","003","004"};
int patient_count = 5;
string patient_name[size] = {"ali","altaf","usman","usama","ayesha"};
string patient_cnic[size] = {"100","101","102","103","104"};
string patient_blood_group[size] = {"B+","A-","O+","AB+","AB-"};
string patient_phone_number[size] = {"00","01","02","03","04"};
int patient_age[size] = {18,30,10,19,19};
string patient_diseases[size] = {"Nill","Nill","Nill","Nill","Nill"};
void edit_inventory_machines(string machine_name,int new_quantity);
bool machine_name_validation(string machine_name);
bool medicine_name_validation(string medicine_name);
void edit_inventory_medicines(string medicine_name,int new_quantity,int new_price,char quantity_or_price);
bool for_admin_login();
void for_doctor_details();
void for_clearing_screen();
void add_inventory();
void add_inventory_medicines();
void print_inventory();
void print_patient_details();
void print_doctor_details();
void add_doctors();
void add_patients();
bool edit_patient_details(string patient_id_to_check,string patient_cnic_to_check);
bool valid_patient_credentials(string patient_name_to_check,string patient_cnic_to_check);
// main ---------------------------------------------------------------------
// ==========================================================================
 int main(){
  char option,admin_option;
  string machine_name;
  string madicine_name;
  int new_quantity;
  int new_price;
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
      //if user is an Admin
      while(true){
       if(login_count > 0){
        break;
       } 
      printHeader();
      bool admin_logged_in = for_admin_login();
      if (admin_logged_in == true){
        login_count++;
        while(true){

        printHeader();
        print_admin_menu();
        cin>>admin_option;
        if (admin_option == '1'){
          while(want_to_enter_m_name!='n'){//while
          system("CLS");
          printHeader();
          cout<<"Do you want to edit the number of Machines or medicines\n'M' for Machines and 'm' for Medicines\n'e' for exiting ";
          cin>>medicines_or_machines;
          if( medicines_or_machines == 'M'){  
            while(want_to_enter_m_name !='n'){     
            cout<<"\nEnter Machine name:";
            cin>>machine_name;
            bool validity_of_name=machine_name_validation(machine_name);
            if (validity_of_name == true){
              cout<<"Enter new Quantity:";
              cin>>new_quantity;
              edit_inventory_machines(machine_name,new_quantity);
              cout<<machine_name<<" quantity "<<"Updated Successfully";
              cout<<"\nDo you want to update some other machine y/n";
              cin>>want_to_enter_m_name;
              }
            else if(validity_of_name == false){
              cout<<"The Machine Name you entered is not in the Inventory"<<endl;
              for_clearing_screen();
            }
            }
          }
          else if ( medicines_or_machines == 'm'){
            //code to edit medicines 
            while (true){
            for_clearing_screen();  
            string medicine_name;
            cout<<"Enter the name of The Medicine whose quantity and price you want to change:";
            cin>>medicine_name;
            bool validity_of_medicine_name =  medicine_name_validation(medicine_name);
            if (validity_of_medicine_name == true){
              //code for editing medicine inventory
              char quantity_or_price;
              cout<< "Enter The New Price of the medicine:";
              cin>> new_price;
              cout<<"Enter the new Quantity of the medicine:";
              cin>> new_quantity;
              cout<< "Enter 'p' to change to change price \nEnter 'q' to change quantity and enter 'b' to change both: ";
              cin>> quantity_or_price;
              edit_inventory_medicines(medicine_name,new_quantity,new_price,quantity_or_price);
              break;
            }
          }
          }
          else if(medicines_or_machines == 'e'){
            break;
          }
          else 
          cout<<"You have entered wrong wrong options";
          for_clearing_screen();
          continue;
          }
        }
      else if(admin_option == '2'){
        while(true){
        //add something to inventory
        printHeader();
        char machine_or_medicine;
        cout<<"Do you want to Add Machines or Medicines?\n'M' for Machines\n'm' for medicines\n'B' for back\n";
        cin>>machine_or_medicine;
        want_to_add_inventory = ' ';
        if (machine_or_medicine == 'M'){
        while(want_to_add_inventory !='n'){
        add_inventory();
        cout<<"\nDo you want to want to add a new Item to the inventory?y/n ";
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
        else if(machine_or_medicine == 'B'){
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
        string patient_name_to_check;
        string patient_cnic_to_check;
        char update_again = 'y';
        while(update_again !='n'){
          system("CLS");
          printHeader();
          cout<<"Enter Patient Name whose details you want to edit:";
          cin>>patient_name_to_check;
          cout<<"Enter CNIC Number of"<<patient_name_to_check<<" :";
          cin>>patient_cnic_to_check;
          bool validity_of_patient_details = edit_patient_details(patient_name_to_check,patient_cnic_to_check);
          if(validity_of_patient_details == true  ){
            cout<<patient_name_to_check<<" data updated successfully\n";
            cout<<"Do you want to update some other data y/n";
            cin>>update_again;
            if (update_again !='n'){
              continue;
            }
          }
          else if(validity_of_patient_details == false){
            cout<<"You have entered incorrect Patient Name or Password\nPress any key to continue....";
            getch();
            continue;
          }
      }
      }
      else if(admin_option == '6'){
        //edit doctors info
        cout<<"We are currently working on it Right Now";
      }
      else if(admin_option == '7'){
        //Delete Patient Details
        cout<<"We are currently working on it Right Now";
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
      else if(admin_option == '0' ){
        //print inventory
      for_clearing_screen();
      print_inventory();
      cout<<"press any key to continue";
      getch();
      cout<<"\n\n";
       }
      else if (admin_option == 'B'){
        break;
      } 
     }
    } 
}
  }
  else if(option == '2'){
    // If user is a patient
    cout<<"We are currently working on it Right Now";
  }
  else if(option == '3'){
    // IF user is a doctor 
    cout<<"We are currently working on it Right Now";
  }
  else if(option == '4'){
    break;
  }
} 
  return 0;
 }

 //-----------------------------Functions--------------------------
 //-----------------------------------------------------------------
bool for_admin_login(){
    string username,password;
    cout<<"Enter Username:";
    cin>>username;
    cout<<"Enter Your Password:";
    cin>>password;
  for (int idx =0;idx<2;idx++){
    if ( password == passwordA[idx] &&  username == admin[idx] ){
      return true;
    }
  }
  return false;
  
}
void printHeader(){
  cout<<"\n\n";
  cout<<"*****************************************************"<<endl;
  cout<<"*          HOSPITAL MANAGEMENT SYSTEM               *"<<endl;
  cout<<"*****************************************************"<<"\n\n"<<endl;
}
void print_main_menu(){
  cout<<"Enter 1 if You are Admin:\nEnter 2 if you are a Patient\nEnter 3 if you are a Doctor\nEnter 4 if you want to close the Program\n";
}
void print_admin_menu(){
cout<<"Enter 1 to update quantity of items in inventory:\nEnter 2 to add items to inventory\nEnter 3 add doctor\nEnter 4 to add patient details\nEnter 5 to edit patient details\nEnter 6 to edit Doctor Info:\nEnter 7 to delete patient details\nEnter 8 Print Doctor's list\nEnter 9 to print Patients list\nEnter 0 to print inventory...";
}
 void edit_inventory_machines(string machine_name,int new_quantity){
  int count_for_edit_inventory=0;
 for (int idx =0;idx<size;idx++){
  if (machine_name == inventory[idx]){
    inventory_items[idx] = new_quantity;
    count_for_edit_inventory =-1;
  }
 }
 if (count_for_edit_inventory !=-1 ){
  cout<<"You have entered wrong machine name!"<<endl;
  cout<<"Press any key to enter machine name again";
}
 }
 char for_selecting_options(){
  char option;
  cin>>option;
  return option;
 }
 bool machine_name_validation(string machine_name){
  for (int idx =0;idx<size;idx++){
  if (machine_name == inventory[idx]){
    return true;
  }
 }
 return false;
}
void for_clearing_screen(){
  cout<<"press any key to continue......";
  getch();
  system("CLS");
  printHeader();
}
void add_inventory(){
  cout<<"Enter the Name of the Machine you want to add:";
  string machine_name_to_add;
  int quantity_of_machines_to_add;
  cin>>machine_name_to_add;
  cout<<"Enter The quantity of the Machines you want to add:";
  cin>>quantity_of_machines_to_add;
  for (int idx = inventory_count; idx<=inventory_count;idx++){
    if(inventory_count > size ){
      cout<<"Storage size full";
      break;
    }
    inventory[inventory_count]= machine_name_to_add;
    inventory_items[inventory_count]=quantity_of_machines_to_add;
    inventory_count++;
    break;
    
  }
}
bool medicine_name_validation(string medicine_name){
  for (int idx =0;idx<size;idx++){
  if (medicine_name == inventory_medicines[idx]){
    return true;
  }
 }
 return false;
}
void edit_inventory_medicines(string medicine_name,int new_quantity,int new_price, char quantity_or_price ){
 int count_for_edit_inventory=0;
 for (int idx =0;idx<size;idx++){
  if (medicine_name == inventory_medicines[idx]){
    if (quantity_or_price == 'b' || quantity_or_price == 'q'){
      inventory_medicines_quantity[idx] = new_quantity;
      count_for_edit_inventory = -1;
    }
    if (quantity_or_price == 'b' || quantity_or_price == 'p'){
      inventory_medicines_price[idx] = new_price;
      count_for_edit_inventory =-1;
  }
  }
  }
  if(quantity_or_price !='p' && quantity_or_price !='q' && quantity_or_price !='b'){
  cout <<"Wrong Option selected sir!";
 }
 if (count_for_edit_inventory !=-1 ){
  cout<<"You have entered wrong Medicine name!"<<endl;
}
}
void print_inventory(){
  cout<<"\t\t\t\tMACHINES"<<endl;
  for (int idx = 0;idx <inventory_count;idx++){
    cout<<"Machine Name:"<<inventory[idx]<<"\n"<<"Quantity:"<<inventory_items[idx]<<endl<<"-------------------------------------------------------------------------------------"<<endl;
  }
  cout<<"\t\t\t\tMEDICINES"<<endl;
  for (int idx = 0; idx <medicine_inventory_count;idx++){
    cout<<"Medicine Name:"<<inventory_medicines[idx]<<"\n"<<"Price:$"<<inventory_medicines_price[idx]<<"\n"<<"Quantity:"<<inventory_medicines_quantity[idx]<<endl<<"-------------------------------------------------------------------------------------"<<endl;
  }
}
void add_inventory_medicines(){
  cout<<"Enter the Name of the Medicine you want to add:";
  string medicine_name_to_add;
  int quantity_of_medicine_to_add;
  int price_of_medicine_to_add;
  cin>>medicine_name_to_add;
  cout<<"Enter The quantity of "<<medicine_name_to_add<<":";
  cin>>quantity_of_medicine_to_add;
  cout<<"Enter the price of "<<medicine_name_to_add<<":";
  cin>>price_of_medicine_to_add;
  for (int idx = medicine_inventory_count; idx <= medicine_inventory_count;idx++){
    if(medicine_inventory_count > size ){
      cout<<"Storage size full";
      break;
    }
    inventory_medicines[medicine_inventory_count]= medicine_name_to_add;
    inventory_medicines_quantity[medicine_inventory_count]=quantity_of_medicine_to_add;
    inventory_medicines_price[medicine_inventory_count]=price_of_medicine_to_add;
    medicine_inventory_count ++ ;
    break;    
  }
}
void print_patient_details(){
  for (int idx = 0 ;idx< patient_count ; idx++){
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"Name:"<<patient_name[idx]<<endl;
    cout<<"Age:"<<patient_age[idx]<<endl;
    cout<<"Blood Group:"<<patient_blood_group[idx]<<endl;
    cout<<"Diseases:"<<patient_diseases[idx]<<endl;
    cout<<"Phone Number:"<<patient_phone_number[idx]<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
  }
}
void print_doctor_details(){
  for (int idx = 0 ;idx <doctor_count;idx ++){
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"Name:Dr."<<doctors_name[idx]<<endl;
    cout<<"Age:"<<doctor_age[idx]<<endl;
    cout<<"Speciality:"<<doctors_speciality[idx]<<endl;
    cout<<"Doctor ID:"<<doctor_id[idx]<<endl;
    cout<<"Phone Number:"<<doctor_number[idx]<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
  }
  }
void add_doctors(){
  cout<<"Enter the Name of Doctor:";
  string doc_name;
  cin>>doc_name;
  cout<<"Enter the ID of Doctor:";
  string doc_id;
  cin>>doc_id;
  cout<<"Enter the Phone Number of Doctor:";
  string doc_number;
  cin>>doc_number;
  cout<<"Enter the age of Doctor:";
  int doc_age;
  cin>>doc_age;
  cout<<"Enter the speciality of the Doctor:";
  string doc_speciality;
  cin>>doc_speciality;
  cout<<"Enter the Fee of the Doctor:";
  int doc_fee;
  cin>>doc_fee;
  cout<<"Enter Doctor's password:\nDoctor may change it afterward\nFor now enter 0000 ";
  string doc_password;
  cin>>doc_password;
  for (int idx = doctor_count;idx <= doctor_count;idx++){
    if (doctor_count < size){
    doctors_name[idx]=doc_name;
    doctors_speciality[idx] = doc_speciality;
    doctor_id[idx] = doc_id;
    doctor_age[idx] = doc_age;
    doctor_number[idx] = doc_name;
    doctor_fee[idx] = doc_fee;
    doctor_password[idx] = doc_password;
    doctor_count++;
  }
  }
}
void add_patients(){
  string pat_name;
  string pat_number;
  string pat_blood_group;
  int pat_age;
  string pat_cnic;
  string pat_diseases;
  cout<<"Enter Patient Name:";
  cin>>pat_name;
  cout<<"Enter Patient CNIC Number:";
  cin>>pat_cnic;
  cout<<"Enter Patient Blood Group";
  cin>>pat_blood_group;
  cout<<"Enter Patient Age:";
  cin>>pat_age;
  cout<<"Enter Phone Number:";
  cin>>pat_number;
  cout<<"Enter the Diseases the patient currently has:";
  cin>>pat_diseases;
  if(size > patient_count){
  for ( int idx = patient_count ; idx <=patient_count ;idx++){
        patient_age[idx]=pat_age;
        patient_blood_group[idx]=pat_blood_group;
        patient_diseases[idx] = pat_diseases;
        patient_name[idx] = pat_name;
        patient_phone_number[idx] = pat_number;
      }
      patient_count++;
      }
  }
bool edit_patient_details(string patient_name_to_check,string patient_cnic_to_check){
  for(int idx =0;idx < patient_count ;idx++){ 
    if((patient_cnic[idx] == patient_cnic_to_check) && ( patient_name[idx] == patient_name_to_check)){
      cout<<"Enter New CNIC Number";
      string New_CNIC;
      cin>>New_CNIC;
      cout<<"Enter New Phone Number:";
      string phone_number;
      cin>>phone_number;
      patient_phone_number[idx] = phone_number;
      cout<<"Enter Disease of the Patient:";
      string disease_of_patient;
      cin>>disease_of_patient;
      patient_diseases[idx] = disease_of_patient;
      patient_cnic[idx] = New_CNIC;
      return true;
    }
  }
  return false;
}
  