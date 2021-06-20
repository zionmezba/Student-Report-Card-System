#include <bits/stdc++.h>
using namespace std;
#define MAX 50
string static username = "teacher1", password = "test"; 

//FUNCTION PROTOTYPE SECTION
void mainMenu();
void viewReport();
void viewIndividual();
void viewGrade();
void modifyData();
void welcomeNote();
void login();
//FUNCTION PROTOTYPE SECTION ENDS

/*============================================
        THIS FUNCTION IS FOR MENU
============================================*/
void mainMenu(){
    cout << "\nWhat would you like to do?\n\n";
    cout << ">> View All Students Report                [Press 1]\n";
    cout << ">> View Individual Report                  [Press 2]\n";
    cout << ">> View All Students Grade                 [Press 3]\n";
    cout << ">> Modify Database                         [Press 4]\n";
    cout << ">> Exit                                    [Press 0]\n";
}

/*=============================================
    THIS FUNCTION IS TO VIEW ALL REPORT
==============================================*/
void viewReport(){
    cout << "--------------------------------------\n";
    cout << "|      All Sudents Report Card        |\n";
    cout << "--------------------------------------\n\n";
}


/*==============================================
    THIS FUNCTION IS TO VIEW INDIVIDUAL REPORT
==============================================*/
void viewIndividual(){
    cout << "--------------------------------------\n";
    cout << "|      Individual Report Card        |\n";
    cout << "--------------------------------------\n\n";
}


/*============================================
        THIS FUNCTION IS TO VIEW ALL GRADE
============================================*/
void viewGrade(){
    cout << "--------------------------------------\n";
    cout << "|       All Sudents Grades           |\n";
    cout << "--------------------------------------\n\n";
}


/*============================================
        THIS FUNCTION IS TO MODIFY DATA
============================================*/
void modifyData(){
    cout << "--------------------------------------\n";
    cout << "|       Database Modification        |\n";
    cout << "--------------------------------------\n\n";
    cout << "Please Log In to Access Modification\n";
    login();
}


/*============================================
        THIS FUNCTION IS FOR LOGIN
============================================*/
void login(){
    int i=0;
    string chr, username1, password1;
again:
    cout << "Enter Username:\n";
    cin >> username1;
    cout << "Enter Password:\n";
    cin >> password1;
    if(username1 == username && password1 == password)
    {
        cout << "\n\n----------------------------------\n";
        cout << "Hi,\n" << username << endl;
        cout << "----------------------------------\n\n";
    }
    else
    {
        cout << "\nWrong Login Info!\nTry Again.\n\n";
        goto again;
    }
}

/*============================================
        WELCOME NOTE
============================================*/
void welcomeNote(){
    cout << "--------------------------------------\n";
    cout << "|              THANK YOU               |\n";
    cout << "--------------------------------------\n\n";
    cout << setw(23) << "OUR TEAM" << endl;
    cout << "\nMd. Mezbaul Islam Zion\nID: 201-15-3496\n";
    cout << "\nMd. Rasheduzzaman Elite\nID: 201-15-3235\n";
    cout << "\nSudipto Paul\nID: 201-15-3478\n";
    cout << "\nSabria Alam Bishal\nID: 201-15-3xxx\n";
}

/*============================================
        MAIN METHOD STARTS
============================================*/
int main(){
    int choice, val2, val3, val4, val5,i=0;

    cout << "--------------------------------------\n";
    cout << "|      Sudent Report Card System      |\n";
    cout << "--------------------------------------\n\n";
    while(choice != 0)
    {
main1:
        mainMenu();
take1:
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                viewReport();
                break;
            case 2:
                viewIndividual();
                break;
            case 3:
                viewGrade();
                break;
            case 4:
                modifyData();
                break;
            case 0:
                welcomeNote();
                return 0;
                break;
            default:
            {
                cout << "Wrong Input !!\n";
                goto take1;
            }
        }
    }
}
/*===================================
        MAIN METHOD ENDS
===================================*/
