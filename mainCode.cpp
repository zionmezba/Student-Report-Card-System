#include <bits/stdc++.h>
#include <dir.h>
using namespace std;
#define MAX 50

//FUNCTION PROTOTYPE SECTION
void mainMenu();
void viewReport();
void viewIndividual();
void viewGrade();
void modifyData();
void modifyDataAdmin();
void login();
void createAccount();
void studentDatabase();
void welcomeNote();
void insertionSortbyName();
void insertionSortbyScore();
void demoReport();
int binarySearch(int dat);
void editDatabase();
void deleteStuInfo();
void write_on_txt();
void displayListTxt();
void displayList();
//STRUCTURE OF DATABASE

struct Students{
    string stuNames;
    int stuID, cse1, cse2, cse3, total;
    float grade;
} stdnt[MAX];

int sizeSt = 4;
/*============================================
        MAIN METHOD STARTS
============================================*/
int main(){
    // mkdir("studentData");
    // mkdir("userdata");
    demoReport();
    int choice = 1;

    while (choice != 0){
        mainMenu();
        cout << "\t\t\tEnter Choice: ";
        cin >> choice;
        switch (choice){
        case 1: viewReport();
            break;
        case 2: viewIndividual();
            break;
        case 3: viewGrade();
            break;
        case 4: modifyData();
            break;
        case 0: welcomeNote();
            return 0;
            break;
        default:
        {
            cout << "Wrong Input !!\n";
            cout << "\n\nPress Any Key to Continue..";
            cin.get();
            }
        }
    }
    
    string datab = "database1";
    std::ofstream ofs;
    ofs.open("studentData\\" + datab + ".txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    return 0;
}
/*===================================
        MAIN METHOD ENDS
===================================*/

/*================================================
    THIS FUNCTION IS TO VIEW ALL REPORT AND SORTING
==================================================*/
void viewReport(){
    system("cls");
    cout << "\t\t--------------------------------------\n";
    cout << "\t\t|      All Sudents Report Card        |\n";
    cout << "\t\t--------------------------------------\n\n";
    displayList();
    cout << "\n\nSort Report by- \n1. Name (Alphabetic)\n2. Score (Ascending)\n3. Press 0 to Main Menu";
    int key;
    cout << "\nEnter Choice: ";
    cin >> key;
    if (key == 1){
        system("cls");
        cout << "After Sorting By Name: \n\n";
        insertionSortbyName();
        displayList();
        cout << "\n\nPress Any Key to Continue..";
        cin.get();
        cin.get();
    }
    else if (key == 2){
        system("cls");
        cout << "After Sorting By Score: \n\n";
        insertionSortbyScore();
        displayList();
        cout << "\n\nPress Any Key to Continue..";
        cin.get();
        cin.get();
    }
}

void displayList(){
    cout << "===============================================================\n";
    cout << "ID       Name        CSE221   CSE223   CSE224   Total    Grade" << endl;
    cout << "===============================================================\n";
    for(int flag = 0; flag < sizeSt; flag++){
        cout << stdnt[flag].stuID << "   " << left << setw(17)
        << stdnt[flag].stuNames << setw(9) << stdnt[flag].cse1 << setw(9)
        << stdnt[flag].cse2 << setw(9) << stdnt[flag].cse3 << setw(8)
        << stdnt[flag].total << setw(5) << stdnt[flag].grade << endl;
    }
}

void displayListTxt(){
    cout << "===============================================================\n";
    cout << "ID       Name        CSE221   CSE223   CSE224   Total    Grade" << endl;
    cout << "===============================================================\n";
    string datab = "database1";
    ifstream readStudentData("studentData\\" + datab + ".txt", ios::in);
    if (readStudentData.is_open())    {
        string data;
        while (getline(readStudentData, data))
        {
            cout << data << endl;
        }
        readStudentData.close();
    }
    else
        cout << "File Could Not be Openned!" << endl;
}

void insertionSortbyName(){
    Students key;
    int hole;
    for(int i = 1; i < sizeSt; i++){
        key = stdnt[i];
        hole = i-1;
        while(hole >= 0 && stdnt[hole].stuNames < key.stuNames){
            stdnt[hole+1] = stdnt[hole];
            hole--;
        }
        stdnt[hole+1] = key;
    }
}

void insertionSortbyScore(){
    Students key;
    int hole;
    for(int i = 1; i < sizeSt; i++){
        key = stdnt[i];
        hole = i-1;
        while(hole >= 0 && stdnt[hole].total > key.total){
            stdnt[hole+1] = stdnt[hole];
            hole--;
        }
        stdnt[hole+1] = key;
    }
}

/*==============================================
    THIS FUNCTION IS TO VIEW INDIVIDUAL REPORT
==============================================*/
void viewIndividual(){
    system("cls");
    cout << "\t\t--------------------------------------\n";
    cout << "\t\t|      Individual Report Card        |\n";
    cout << "\t\t--------------------------------------\n\n";
    int key;
    cout << "Enter Student ID:\n";
    cin >> key;
    int flag = binarySearch(key);
    if (flag >= 0){
        cout << "===============================================================\n";
        cout << "ID       Name        CSE221   CSE223   CSE224   Total    Grade" << endl;
        cout << "===============================================================\n";
        cout << stdnt[flag].stuID << "   " << left << setw(17)
        << stdnt[flag].stuNames << setw(9) << stdnt[flag].cse1 << setw(9)
        << stdnt[flag].cse2 << setw(9) << stdnt[flag].cse3 << setw(8)
        << stdnt[flag].total << setw(5) << stdnt[flag].grade << endl;
        cout << "\n\nPress Any Key to Continue..";
        cin.get();
        cin.get();
    }
    else{
        cout << "Student Not Found!\n";
        cout << "\n\nPress Any Key to Continue..";
        cin.get();
        cin.get();
    }
}

//BINARY SEARCHING
int binarySearch(int dat){
    int low = 0;
    int high = sizeSt - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (dat == stdnt[mid].stuID)
        {
            return mid;
        }
        if (dat > stdnt[mid].stuID)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
}

/*============================================
        THIS FUNCTION IS TO VIEW ALL GRADE
============================================*/
void viewGrade(){
    system("cls");
    cout << "\t--------------------------------------\n";
    cout << "\t|       All Sudents Grades           |\n";
    cout << "\t--------------------------------------\n\n";
    cout << "============================\n";
    cout << "ID       Name        Grade" << endl;
    cout << "============================\n";
    for (int i = 0; i < sizeSt; i++)
    {
        cout << stdnt[i].stuID << "   " << left << setw(17)
        << stdnt[i].stuNames << setw(5) << stdnt[i].grade << endl;
    }
    cout << "\n\nPress Any Key to Continue..";
    cin.get();
    cin.get();
}

/*============================================
        THIS SECTION IS TO MODIFY DATA
============================================*/
void modifyData(){
    int choice = 1;
    while (choice != 0){
        system("cls");
        cout << "\n\t\t\t\t--------------------------------------\n";
        cout << "\t\t\t\t|       Database Modification        |\n";
        cout << "\t\t\t\t--------------------------------------\n\n";
        cout << "\t\t\tPlease Log In to Access Modification\n";
        cout << "\t\t\t>> Login                       [Press 1]\n";
        cout << "\t\t\t>> Create Account              [Press 2]\n";
        cout << "\t\t\t>> Back to Main Menu           [Press 0]\n";
        cout << "\t\t\tEnter Choice: ";
        cin >> choice;
        switch (choice){
            case 1: login(); //Modify Data Admin
                return;
                break;
            case 2: createAccount();
                break;
            case 0:
                break;
            default:{
                cout << "Wrong input!!\n";
                cout << "Press Any Key to Continue..";
                cin.get();
            }
        }
    }
}

void modifyDataAdmin(){
    int choice = 1;
    while (choice != 0){
        system("cls");
        cout << "\n\t\t\t--------------------------------------\n";
        cout << "\t\t\t|    Database Modification [Admin]    |\n";
        cout << "\t\t\t--------------------------------------\n\n";
        cout << "\t\t\tWhat would you like to do?\n";
        cout << "\t\t\t>> Enter New Student Info          [Press 1]\n";
        cout << "\t\t\t>> Edit Student Info               [Press 2]\n";
        cout << "\t\t\t>> Delete Student Info             [Press 3]\n";
        cout << "\t\t\t>> Logout/Exit Admin               [Press 0]\n";
        cout << "\t\t\tEnter Choice: ";
        cin >> choice;
        switch (choice){
        case 1: studentDatabase();
            break;
        case 2: editDatabase();
            break;
        case 3: deleteStuInfo();
            break;
        case 0:
            break;
        default:
            cout << "Wrong input!!\n";
            cout << "Press Any Key to Continue..";
            cin.get();
        }
    }
}

void studentDatabase(){
    system("cls");
    int n, id, cse1, cse2, cse3, total;
    float grade;
    string stuName;

    cout << "How Many Data: ";
    cin >> n;
    sizeSt += n;
    for (int i = 4; i < (4 + n); i++){
        cout << "Enter ID\n";
        cin >> stdnt[i].stuID;
        cout << "Enter Name\n";
        getchar();
        getline(cin, stdnt[i].stuNames);
        cout << "Enter Mark CSE213\n";
        cin >> stdnt[i].cse1;
        cout << "Enter Mark CSE214\n";
        cin >> stdnt[i].cse2;
        cout << "Enter Mark CSE223\n";
        cin >> stdnt[i].cse3;
        stdnt[i].total = stdnt[i].cse1 + stdnt[i].cse2 + stdnt[i].cse3;
        cout << "Enter Grade\n";
        cin >> stdnt[i].grade;

        ofstream StuDataFile;
        StuDataFile.open("studentData\\database1.txt", ios::app);
        if (StuDataFile.is_open())
        {
            StuDataFile << stdnt[i].stuID << "   " << left << setw(17) << stdnt[i].stuNames 
            << setw(9) << stdnt[i].cse1 << setw(9) << stdnt[i].cse2 << setw(9)
            << stdnt[i].cse3 << setw(8) << stdnt[i].total << setw(5) << stdnt[i].grade << endl;

            StuDataFile.close();
        }
        cout << endl;
    }
    cout << "Success!!\n";
    cout << "Press Any Key to Continue..";
    cin.get();
    cin.get();
}

void editDatabase(){
    system("cls");
    cout << "\n\t\t\t--------------------------------------\n";
    cout << "\t\t\t|         Edit Database [Admin]         |\n";
    cout << "\t\t\t--------------------------------------\n\n";
    int key;
    cout << "Enter Student ID:\n";
    cin >> key;
    int flag = binarySearch(key);
    if (flag >= 0){
        cout << "Enter New ID\n";
        cin >> stdnt[flag].stuID;
        cout << "Enter New Name\n";
        getchar();
        getline(cin, stdnt[flag].stuNames);
        cout << "Enter New Mark CSE213\n";
        cin >> stdnt[flag].cse1;
        cout << "Enter New Mark CSE214\n";
        cin >> stdnt[flag].cse2;
        cout << "Enter New Mark CSE223\n";
        cin >> stdnt[flag].cse3;
        stdnt[flag].total = stdnt[flag].cse1 + stdnt[flag].cse2 + stdnt[flag].cse3;
        cout << "Enter Grade\n";
        cin >> stdnt[flag].grade;
        write_on_txt();
        cout << "Edit Success!\n";
        cout << "\n\nPress Any Key to Continue..";
        cin.get();
        cin.get();
    }
    else{
        cout << "Student Not Found!\n";
        cout << "\n\nPress Any Key to Continue..";
        cin.get();
        cin.get();
    }
}

void write_on_txt(){
    string datab = "database1";
    std::ofstream ofs;
    ofs.open("studentData\\" + datab + ".txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    for (int i = 0; i < sizeSt; i++){
        ofstream StuDataFile;
        StuDataFile.open("studentData\\database1.txt", ios::app);
        if (StuDataFile.is_open()){
            StuDataFile << stdnt[i].stuID << "   " << left << setw(17) << stdnt[i].stuNames 
            << setw(9) << stdnt[i].cse1 << setw(9) << stdnt[i].cse2 << setw(9)
            << stdnt[i].cse3 << setw(8) << stdnt[i].total << setw(5) << stdnt[i].grade << endl;
            StuDataFile.close();
        }
    }
}

void deleteStuInfo(){
    int key;
    cout << "\n\nEnter Student ID:\n";
    cin >> key;
    int flag = binarySearch(key);
    if (flag < sizeSt)    {
        sizeSt = sizeSt - 1;
        for (int j=flag; j<sizeSt; j++)
            stdnt[j] = stdnt[j+1];
        cout << "Deleted Successfully!\n";
        write_on_txt();
        cout << "\n\nPress Any Key to Continue..";
        cin.get();
        cin.get();
    }
    else
        cout << "Student Not Found!\n\n";
}

/*============================================
LOGIN AND CREATE ACCOUNT SECTION
============================================*/
void login(){
    system("cls");
    int i = 0;
    string usrn, psw, username1, password1;
    cout << "Enter Username:\n";
    cin >> username1;
    cout << "Enter Password:\n";
    cin >> password1;

    ifstream read("userdata\\" + username1 + ".txt");
    getline(read, usrn);
    getline(read, psw);

    if (username1 == usrn && password1 == psw){
        cout << "\n\nLogin Success!\n";
        transform(username1.begin(),username1.end(), username1.begin(), ::toupper);
        cout << "\n\n\t\t----------------------------------\n";
        cout << "\t\tHi,\n\t\t\t" << username1 << endl;
        cout << "\t\t----------------------------------\n\n";
        cout << "\n\nPress Any Key to Continue..";
        cin.get();
        cin.get();
        modifyDataAdmin();
    }
    else
        cout << "\nWrong Login Info!\nTry Again.\n\n";
}

void createAccount(){
    system("cls");
    string userName, passWord;

    cout << "\nSet Username: \n";
    getchar();
    getline(cin, userName);
    cout << "Set Password: \n";
    getline(cin, passWord);

    ofstream MyFile;
    MyFile.open("userdata\\" + userName + ".txt");
    if (MyFile.is_open()){
        MyFile << userName << endl << passWord << endl;
        MyFile.close();
        system("cls");
        cout << "Account created successfully!\n\n";
        cout << "Press Any Key to Continue..";
        cin.get();
    }
    else
        cout << "Error! Failed to create account.\n";
}

/*============================================
        WELCOME NOTE AND MENU
============================================*/
void welcomeNote(){
    system("cls");
    cout << "\t\t\t\t--------------------------------------\n";
    cout << "\t\t\t\t|              THANK YOU               |\n";
    cout << "\t\t\t\t--------------------------------------\n\n";
    cout << setw(23) << "\t\t\t\tOUR TEAM" << endl;
    cout << "\n\t\t\t\tMd. Mezbaul Islam Zion\n\t\t\t\tID: 201-15-3496\n";
    cout << "\n\t\t\t\tMd. Rasheduzzaman Elite\n\t\t\t\tID: 201-15-3235\n";
    cout << "\n\t\t\t\tSudipto Paul\n\t\t\t\tID: 201-15-3478\n";
    cout << "\n\t\t\t\tSabria Alam Bishal\n\t\t\t\tID: 201-15-3143\n\n\n";
}

void mainMenu(){
    system("cls");
    cout << "\t\t\t\t--------------------------------------\n";
    cout << "\t\t\t\t|      Sudent Report Card System      |\n";
    cout << "\t\t\t\t--------------------------------------\n\n";
    cout << "\n\t\t\tWhat would you like to do?\n\n";
    cout << "\t\t\t>> View All Students Report                [Press 1]\n";
    cout << "\t\t\t>> View Individual Report                  [Press 2]\n";
    cout << "\t\t\t>> View All Students Grade                 [Press 3]\n";
    cout << "\t\t\t>> Modify Database                         [Press 4]\n";
    cout << "\t\t\t>> Exit                                    [Press 0]\n";
}

//DEMO REPORT
void demoReport(){
    stdnt[0].stuID = 3496;
    stdnt[0].stuNames = "Md. Mezba Zion";
    stdnt[0].cse1 = 87;
    stdnt[0].cse2 = 90;
    stdnt[0].cse3 = 85;
    stdnt[0].total = stdnt[0].cse1 + stdnt[0].cse2 + stdnt[0].cse3;
    stdnt[0].grade = 4.00;

    ofstream StuDataFile;
    StuDataFile.open("studentData\\database1.txt", ios::app);
    if (StuDataFile.is_open()){
        StuDataFile << stdnt[0].stuID << "   " << left << setw(17)
        << stdnt[0].stuNames << setw(9) << stdnt[0].cse1 << setw(9)
        << stdnt[0].cse2 << setw(9) << stdnt[0].cse3 << setw(8)
        << stdnt[0].total << setw(5) << stdnt[0].grade << endl;
        StuDataFile.close();
    }
    stdnt[1].stuID = 3478;
    stdnt[1].stuNames = "Sudipto Paul";
    stdnt[1].cse1 = 88;
    stdnt[1].cse2 = 87;
    stdnt[1].cse3 = 84;
    stdnt[1].total = stdnt[1].cse1 + stdnt[1].cse2 + stdnt[1].cse3;
    stdnt[1].grade = 4.00;
    StuDataFile.open("studentData\\database1.txt", ios::app);
    if (StuDataFile.is_open()){
        StuDataFile << stdnt[1].stuID << "   " << left << setw(17)
        << stdnt[1].stuNames << setw(9) << stdnt[1].cse1 << setw(9)
        << stdnt[1].cse2 << setw(9) << stdnt[1].cse3 << setw(8)
        << stdnt[1].total << setw(5) << stdnt[1].grade << endl;
        StuDataFile.close();
    }
    stdnt[2].stuID = 3143;
    stdnt[2].stuNames = "Sabriar Bishal";
    stdnt[2].cse1 = 85;
    stdnt[2].cse2 = 79;
    stdnt[2].cse3 = 86;
    stdnt[2].total = stdnt[2].cse1 + stdnt[2].cse2 + stdnt[2].cse3;
    stdnt[2].grade = 3.75;
    StuDataFile.open("studentData\\database1.txt", ios::app);
    if (StuDataFile.is_open()){
        StuDataFile << stdnt[2].stuID << "   " << left << setw(17)
        << stdnt[2].stuNames << setw(9) << stdnt[2].cse1 << setw(9)
        << stdnt[2].cse2 << setw(9) << stdnt[2].cse3 << setw(8)
        << stdnt[2].total << setw(5) << stdnt[2].grade << endl;
        StuDataFile.close();
    }
    stdnt[3].stuID = 3235;
    stdnt[3].stuNames = "Rashed Elite";
    stdnt[3].cse1 = 85;
    stdnt[3].cse2 = 76;
    stdnt[3].cse3 = 77;
    stdnt[3].total = stdnt[3].cse1 + stdnt[3].cse2 + stdnt[3].cse3;
    stdnt[3].grade = 3.50;
    StuDataFile.open("studentData\\database1.txt", ios::app);
    if (StuDataFile.is_open()){
        StuDataFile << stdnt[3].stuID << "   " << left << setw(17)
        << stdnt[3].stuNames << setw(9) << stdnt[3].cse1 << setw(9)
        << stdnt[3].cse2 << setw(9) << stdnt[3].cse3 << setw(8)
        << stdnt[3].total << setw(5) << stdnt[3].grade << endl;
        StuDataFile.close();
    }
}
