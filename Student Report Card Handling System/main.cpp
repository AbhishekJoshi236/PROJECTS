#include<iostream>
#include<iomanip>
#include<conio.h>
#include<fstream>
using namespace std;

class Student
{
    public:
    int roll_no;
    int m_mark,e_mark,ds_mark,l_mark,o_mark,c_mark;
    string name;
    float per;

    void Calculate()
    {
        per=(m_mark+e_mark+ds_mark+o_mark+l_mark+c_mark)/6.0;
    }

    void getdetails()
    {
        cin.ignore();
        cout<<"\n\nEnter Name of Student:: ";
        getline(cin,name);
        cout<<"\n\nEnter Roll Number of Student:: ";
        cin>>roll_no;
        cout<<"\nEnter marks out of 100\n\n";
        cout<<"Enter Discrete Mathematics marks: ";
        cin>>m_mark;
        cout<<"Enter English marks: ";
        cin>>e_mark;
        cout<<"Enter Data structure marks: ";
        cin>>ds_mark;
        cout<<"Enter Logic Design marks: ";
        cin>>l_mark;
        cout<<"Enter OOPS marks: ";
        cin>>o_mark;
        cout<<"Enter Cybersecurity marks: ";
        cin>>c_mark;
        Calculate();
    }

    void display()
    {
        cout<<"\n============================\n" <<endl;
        cout<<"\nName of Student:: "<<name<<endl;
        cout<<"\nRoll Number is :: "<<roll_no<<endl<<endl;
        cout<<"\nDiscrete Mathematics marks:: "<<m_mark<<endl;
        cout<<"\nEnglish marks:: "<<e_mark<<endl;
        cout<<"\nData Structure marks:: "<<ds_mark<<endl;
        cout<<"\nLogic Design marks:: "<<l_mark<<endl;
        cout<<"\nOOPS marks:: "<<o_mark<<endl;
        cout<<"\nCybersecurity marks:: "<<c_mark<<endl<<endl;
        cout<<"\nPercentage of Student:: "<<setprecision(4)<<per<<endl;
        cout<<"\n============================\n" <<endl;
    }

};


void createStudent()
{
    Student s;
    ofstream StudentFile;
    StudentFile.open("A:\\student.txt",ios::binary|ios::app);
    s.getdetails();
    StudentFile.write((char *)(&s), sizeof(Student));
    StudentFile.close();
    cout << "\n\n----------------------------------"  << endl;
    cout << "Student Details Have Been Recorded "<<endl;
    cout << "----------------------------------\n\n"  << endl;
    cout<<"\nPress any key to continue........ ";
    getch();
}

void PrintAllRecords()
{
    int i=0;
    Student s;
    ifstream StudentFile;
    StudentFile.open("A:\\student.txt",ios::binary);

    if (!StudentFile)
    {
        cout<<"File error!! Press any Key to exit";
        getch();
        return;
    }

    cout<<"\n\t\t\tDISPLAYING ALL RECORDS:\n\n";
    while (StudentFile.read((char *)(&s), sizeof(Student)))
    {
        i++;
        cout<<endl;
        s.display();
    }

    if(i==0)
    {
        cout<<"NO RECORDS FILE EMPTY!!!";
    }
    StudentFile.close();
    cout<<"\n\nPress any key to continue........ ";
    getch();
}

void PrintParticular(int a)
{
    Student s;
    ifstream StudentFile;
    StudentFile.open("A:\\student.txt",ios::binary);

    if(!StudentFile)
    {
        cout<<"File error!! Press any key to exit";
        getch();
        return ;
    }

    while (StudentFile.read((char *)(&s), sizeof(Student)))
    {
        if(s.roll_no==a)
        {
            cout<<"\n\n\tDISPLAYING RECORD OF ROLL_NO:-> "<<a<<endl;
            s.display();
            StudentFile.close();
            cout<<"\n\n\nPress any key to continue........ ";
            getch();
            return;
        }
    }

    cout<<"\n\nRecord Not Found!!\n\n";
    StudentFile.close();
    cout<<"\n\n\nPress any key to continue........ ";
    getch();
}

void DeleteRecord(int a)
{
    int p=0;
    Student s;
    ifstream f;
    ofstream t;
    f.open("A:\\student.txt",ios::binary);

    if(!f){
        cout<<"File error!! Press any key to exit";
        getch();
        return ;
    }
    else
    {    t.open("A:\\Temp.txt",ios::binary);
         while(f.read((char *)(&s), sizeof(Student)))
         {
            if(s.roll_no!=a)
            {
                t.write((char *)(&s), sizeof(Student));
            }
            else
            {
                p=1;
                cout<<"\n\n\t--*-*RECORD DELETED*-*--"<<endl;
            }

        }
        f.close();
        t.close();

        if(p==0)
        {
            cout<<"\n\n\t--*-*RECORD NOT FOUND*-*--"<<endl;
            remove("A:\\Temp.txt");
        }
        else
        {
           remove("A:\\student.txt");
           rename("A:\\Temp.txt","A:\\student.txt");
        }
    }

    cout<<"\nPress any key to continue........ ";
    getch();
}

void ModifyRecord(int a)
{
    int p=0;
    Student s;
    ifstream f;
    ofstream t;

    f.open("A:\\student.txt",ios::binary);
    if(!f)
    {
        cout<<"File error!! Press any key to exit";
        getch();
        return ;
    }

    else
    {    t.open("A:\\Temp.txt",ios::binary);
         while(f.read((char *)(&s), sizeof(Student)))
         {
            if(s.roll_no!=a)
            {
                t.write((char *)(&s), sizeof(Student));
            }
            else
            {
                p=1;
                cout<<"\n\n\t--*-*Enter new data::*-*--"<<endl;
                s.getdetails();
                t.write((char *)(&s), sizeof(Student));

                cout << "\n\n----------------------------------"  << endl;
                cout << "Student Details Have Been Modified "<<endl;
                cout << "----------------------------------\n\n"  << endl;
            }
        }
        f.close();
        t.close();

        if(p==0)
        {
            cout<<"\n\n\t-----RECORD NOT FOUND-----"<<endl;
            remove("A:\\Temp.txt");
        }
        else
        {
           remove("A:\\student.txt");
           rename("A:\\Temp.txt","A:\\student.txt");
        }
    }

    cout<<"\n\nPress any key to continue........ ";
    getch();
}

int main()
{

    int i=0;
    cout<<"\n\n\t\t****************************************************";
    cout<<"\n\n\t\t\tSTUDENT REPORT CARD HANDLING SYSTEM\n";
    cout<<"\n\t\t****************************************************";

    while(1)
    {
        if(i>0)
                 system("cls");
        i++;

        cout<<"\n\n\n\t\tStudents Information\n\n\n";
        cout<<"\t\t1. Create Student\n\n";
        cout<<"\t\t2. All Students Details\n\n";
        cout<<"\t\t3. Particular Student Details\n\n";
        cout<<"\t\t4. Delete a Record\n\n";
        cout<<"\t\t5. Modify a Record\n\n";
        cout<<"\t\t6. Exit\n\n";

        int choice,b;
        cout<<"\n\n\n\t\tEnter your choice:: ";

        cin>>choice;

        system("cls");
        switch(choice)
        {
            case 1: createStudent();
                    break;
            case 2: PrintAllRecords();
                    break;
            case 3: cout<<"\nEnter the particular roll no:: ";
                    cin>>b;
                    PrintParticular(b);
                    break;
            case 4: cout<<"\nEnter the roll no.:: ";
                    cin>>b;
                    DeleteRecord(b);
                    break;
            case 5: cout<<"\nEnter the particular roll no:: ";
                    cin>>b;
                    ModifyRecord(b);
                    break;
            case 6: exit(0);
            default: cout<<"\nINVAID CHOICE\n\n";
        }
    }
    return 0;
}
