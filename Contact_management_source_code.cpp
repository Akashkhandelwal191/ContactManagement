//|****************************************************************************************************|
//                                        Header files                                                 |                             |
//|****************************************************************************************************|
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

//*********************************************************************************************************|
//                                        Class declration                                                 |
//*********************************************************************************************************|
class contact
{
private:
    string fname,lname,phone_num;  
     
public:
      bool check_name(string);
      void display();
      void design();
      void addcontact();
      void deletecontact();
      void editcontact();
      void helpcontact();
      void searchcontact();
      void showcontact();
      void deleteallcontact();
      bool check_digit(string);
      bool check_number(string);
      void modify();
    
}c;
//DESIGN OF THE MAIN FUNCTION 
void contact::design()
{
system("color 1F");    
for(int i=0;i<=20;i++)
{
system("cls");    
Sleep(200);
cout<<endl;
cout<<"\n****************************************************************************************************";
cout<<"\n*             \t\t|============================================================================|   *";
cout<<"\n*             \t\t|============================================================================|   *";    
cout<<"\n*             \t\t|****************************************************************************|   *";
cout<<"\n*             \t\t|                         ***CONTACT MANAGEMENT***                           |   *";
cout<<"\n*             \t\t|****************************************************************************|   *";
cout<<"\n*             \t\t|============================================================================|   *";
cout<<"\n*              \t\t============================================================================|   *";
cout<<"\n****************************************************************************************************";
cout<<endl;
Sleep(200);
}
}
//This function add contact in the file:
void contact::addcontact()
{
system("cls");
system("color 2F");
string tempname;
cout<<"\t\t\n     *******************************ADD CONTACT PAGE******************************************";
x:
cout<<"\t\t\n     Enter your first name:";
cin>>fname;
tempname=fname;
if(check_name(fname)==true)
{
    cout<<"\n This name is already present try to use another name:";
    goto x;
}
fname=tempname;
cout<<"\t\t\n     Enter your last name:";
cin>>lname;
cout<<"\t\t\n     Enter your phone number:";
cin>>phone_num;
if(check_digit(phone_num)==true)
{
  if(check_number(phone_num)==true)
  {
      ofstream fout;
      fout.open("phone.dat",ios::app|ios::out|ios::binary);
      fout.write((char*)&c,sizeof(c));  
      cout<<" \n CONTACT SAVED SUCCESSFULLY.................";
      fout.close();
      getch(); 
    
  }
  else
  {
      cout<<"\n You can't type alphabet or special number in a phone no.";
      getch();
  }

}
else
{
    cout<<"\n\t Phone number must contain 10 digits";
    cout<<"\n Press any key to continue:";
    getch();
}


}
//Check digits function:
bool contact::check_digit(string x)
{
if(x.length()==10)
return true;
else
return false;

}
//check number function:
bool contact::check_number(string x)
{
  bool check=true;
  for(int i=0;i< x.length();i++)
  {
      if(!(int(x[i])>= 48 && int(x[i]) <= 57))
      {
         check=false;
         break;

      }

  }
  if(check==true)
  return true;
  if(check==false)
  return false;
}
//this function checks the name
bool contact::check_name(string x)
{
bool check=false;
ifstream fin;
fin.open("phone.dat",ios::in|ios::binary);
if(fin)
{
   while(fin.read(reinterpret_cast<char *> (&c), sizeof(contact)))
   {
    if(x==fname)
    {
       check=true;
       break;
    }

   }
}
if(check==true)
return true;
if(check==false)
return false;
}
//this function delete contact fron the file:
void contact::deletecontact()
{
system("cls");
system("color 1F");
string name;
int flag=0;
cout<<"\n*****************DELETE SECTION********************";
cout<<"\n Enter name you want to delete this contact details:";
cin>>name;
ifstream phone;
ofstream tout;
phone.open("phone.dat",ios::in|ios::binary);
tout.open("temp.dat",ios::app|ios::out|ios::binary);
if(phone)
{
while (phone.read(reinterpret_cast<char *> (&c), sizeof(contact)))
{
    if(name==fname)
    {
      cout<<"\n This contact details now deleted:";  
      Sleep(200);
      display();
      flag++;
      getch();
    }
    else
   {
       tout.write((char*)&c,sizeof(c));
   }
}
phone.close();
tout.close();
remove("phone.dat");
rename("temp.dat","phone.dat");
if(flag==0)
{
    cout<<"\n That name not present in that file";
    cout<<"\n Press any key to continue:";
    getch();
}
}
else
{
    cout<<"\n File doesn't exist";
    cout<<"\n Press any key to continue:";
    getch();
}

}
//this function search contact from the file:
void  contact::searchcontact()
{
system("cls");
system("color 2F");
string name;
int flag=0;
cout<<"\n ******************Search section**************************";
cout<<"\n Enter Name you want to search:";
cin>>name;
ifstream phone;
phone.open("phone.dat",ios::in);
if(phone)
{
while(phone.read(reinterpret_cast<char *> (&c), sizeof(contact)))
{
if(name==fname)
{
  flag++;  
 display();
 
}
}
phone.close();
 cout<<"\n Press any key to continue:";
 getch();
if(flag==0)
{
  system("cls");  
 cout<<"\n That contact details is not present in file";
 cout<<"\n Press any key to continue:";
 getch();   
}
}
else
{
   cout<<"File doesn't exist:";
   cout<<"\n Press any key to continue:";
   getch();
}

}
//this function show contact from the file:
void contact::showcontact()
{
system("cls");
system("color 1F");
cout<<"               \n\t**************************All CONTACT DETAILS***********************************";
ifstream phone;
phone.open("phone.dat",ios::in|ios::binary);
if(phone)
{
while(phone.read(reinterpret_cast<char *> (&c), sizeof(contact)))
{
    display(); 
}
phone.close();
cout<<"\n Press any key to continue>..........";
getch();
}
else
{
    cout<<"\n File doesn't Exist";
    cout<<"\n Press any key to continue.....";
    getch();
}
}
void contact::display()
{
cout<<"\t \n*************************************************************";
cout<<"\n First Name:"<<fname;
cout<<endl;
cout<<"\n Last Name:"<<lname;
cout<<endl;
cout<<"\n Phone number:"<<phone_num;
cout<<"\t \n*************************************************************";
}
//this function delete all contact from the file:
void contact::deleteallcontact()
{
system("cls");
system("color 4F");
char ch;
cout<<"\n Are you sure you want to delete all the contact(y/n):";
cin>>ch;
if(ch=='y' | ch=='Y')
{
ifstream phone;
phone.open("phone.dat",ios::in|ios::binary);
if(phone)
{
   phone.close(); 
   remove("phone.dat");
   cout<<"\n ALL DATA DELETED SUCCESSFULLY";
   cout<<"\n Press any key to continue.....";
   getch();
}
else
{

cout<<"\n file doesn't exist";
cout<<"\n Press any key to continue.. ";
getch();
}
}
}
//This is help section:
void contact::helpcontact()
{
 system("cls");
 system("color 1F");
 cout<<"                                \n\t\t\tTHIS IS HELPS SECTION:";
 cout<<"             \n\t\t\t********************************************************************************";
 cout<<endl;
 cout<<"              \nInstructions";
 cout<<"               \n 1.if You want to add a new contact name should be unique";
 cout<<endl;
 cout<<"                \n 2.Number should be 10 digits";
 cout<<endl;
 cout<<"                 \n 3.You want to search or delete the contact this action perform using name";
 cout<<endl;
 cout<<"                  \n\t\t\t*****************************************************************************";
 cout<<"\n Press any key to continue:..................................";
 getch();
}
//This function edit the contact the details:
void contact::editcontact()
{    
system("cls");
system("color 4F");
string name;
bool flag=false;
cout<<"            \n\t\t\t*************************************Edit Section*********************************************";
cout<<"            \n\t\t\tWhich Contact details you want to modify give name:";
cin>>name;
fstream file;
file.open("phone.dat",ios::in|ios::out|ios::binary);
if(file)
{
  while(file.read((char*)&c,sizeof(c)))
  {
    if(name==fname)
   {
    flag=true;
    c.modify();
    int pos=(-1)*static_cast<int>(sizeof(c));
	file.seekp(pos,ios::cur);
    file.write((char*)&c,sizeof(c));
    cout<<"\n your details are modified:.............";
    Sleep(300);
    getch();
   }
 }
 file.close();
 
 if(flag==false)
 {
     cout<<"\n this name is not present in that file";
     cout<<"\n Press any key to continue:";
    getch();

 }
}
else
{
    cout<<"\n File doesn't exist";
    cout<<"\n Press any key to continue:";
    getch();
}
}
//Modify details section:
void contact::modify()
{
string tempname;
x:
cout<<"\n Enter your new name:";
cin>>fname;
tempname=fname;
if(check_name(fname)==true)
{
    cout<<"\n This name is already present try to use another name:";
    goto x;
}
fname=tempname;
cout<<"\n Enter your last name:";
cin>>lname;
y:
cout<<"\n Enter your 10-digit mobile number:";
cin>>phone_num;
if(check_digit(phone_num)==true)
{
  if(check_number(phone_num)==true)
  {

  }
  else
  {
      cout<<"\n the mobile number must contain number only";
      getch();
      goto y;
  }

}
else
{
    cout<<"\n The mobile number should be 10 digits";
    getch();
    goto y;
}
}

//****************************************************************************************************|
//                                      MAIN FUNCTION DECLRATION                                      |
//****************************************************************************************************|
int main()
{
    
         system("color 1F");
         cout<<"\nPress Any key to start:";
         getch();
         system("cls");   //this is program loading function:
         cout<<"\n\n\n.................................... Program being Loading .......................";
         cout<<"\n\n";
         for(int i=0;i<=50;i++)
         {
           Sleep(80);
           cout<<char(219);
         }
         system("cls");
         c.design();
         int n;
         do
        {
            system("cls");
            cout<<endl;
            cout<<"         \t\t\t\t\t\n**********************WELCOME TO CONTACT MANAGEMENT SYSTEM*************************";
            cout<<endl;
            cout<<"         \t\t\t\t\t\n=====================================================================================";
            cout<<endl;
            cout<<"          \t\t\t\t\t\n1>ADD CONTACT";
            cout<<endl;
            cout<<"           \t\t\t\t\t\n2>DELETE CONTACT";
            cout<<endl;
            cout<<"           \t\t\t\t\t\n3>SEARCH CONTACT";
            cout<<endl;
            cout<<"           \t\t\t\t\t\n4>EDIT CONTACT";
            cout<<endl;
            cout<<"           \t\t\t\t\t\n5>HELP CONTACT";
            cout<<endl;
            cout<<"           \t\t\t\t\t\n6>SHOW CONTACT";
            cout<<endl;
            cout<<"           \t\t\t\t\t\n7>DELETE ALL CONTACT";
            cout<<endl;
            cout<<"           \t\t\t\t\t\n8>EXIT";
            cout<<endl;
            cout<<"         \t\t\t\t\t\n=====================================================================================";
            cout<<"          \t\t\t\t\t\nENTER YOUR CHOICE:";
            cin>>n;
            switch(n)
            {
                        case 1:   c.addcontact();
                                  break;


                        case 2:   c.deletecontact();
                                  break;

                        case 3:   c.searchcontact();
                                  break;

                        case 4:   c.editcontact();
                                  break;

                        case 5:   c.helpcontact();
                                  break;                   

                        case 6:   c.showcontact();
                                  break;

                        case 7:   c.deleteallcontact();
                                  break;

                         case 8:  cout<<"\n Thankx for using this program:)";
                                  getch();
                                  exit(0);

                 default:
                           cout<<"\n WRONG INPUT";
             
            }
        }
               while(1);
    return 0;
}