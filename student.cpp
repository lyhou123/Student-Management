#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class Student{
    private:
    int id;
    char name[20];
    char gender[20];
    float average;
    char grade;
    public:
    Student(){}
    Student(int id,char *name,char *gender,float average)
    {
        this->id=id;
        strcpy(this->name,name);
        strcpy(this->gender,gender);
        this->average=average;
    }
    public:
    int getId(){return id;}
    char *getName(){return name;}
    char *getGender(){return gender;}
    float getAverage(){return average;}
    float Getaverage()const;
    void input();
    void output();
    void finav(Student std[],int &n);
    void search(Student std[],int &n);
    void update(Student std[],int &n);
    void Delete(Student std[],int &n);
    void insert(Student std[],int &n);
    void sortac(Student std[],int &n);
    void sortdc(Student std[],int &n);
    
};
float Student::Getaverage()const
{
    return average;
}
void Student::input()
{
    cout<<"Enter Your id=";
    while(!(cin>>id))
    {
        cout<<"Erorr: Enter Number=";
       
        cin.clear();
        cin.ignore(123,'\n');
    }
 cin.sync();
    cout<<"Enter Your Name=";cin.getline(name,20);
    cout<<"Enter Your Gender=";cin.getline(gender,20);
    cout<<"Enter Your Average=";cin>>average;
}
void Student:: output()
{
    cout<<string(100,'-')<<endl;
    cout<<id<<setw(20)<<name<<setw(20)<<gender<<setw(20)<<average<<endl;
}
void Student::finav(Student std[],int &n)
{
   float av=std[0].getAverage();
   for(int i=0;i<n;i++)
   {
    if(av<std[i].getAverage())
    {
        av=std[i].getAverage();
    }
   }
   cout<<"Student Hight average is="<<av<<endl;
}
void Student::search(Student std[],int &n)
{
    int sr,b=0;
    cout<<"Enter ID for search=";
      while(!(cin>>sr))
    {
        cout<<"Erorr: Enter Number ID=";
        cin.clear();
        cin.ignore(123,'\n');
    }
    for(int i=0;i<n;i++)
    {
        if(sr==std[i].getId())
        {
            b=1;
            cout<<"Search Successfull"<<endl;
            std[i].output();
        }
    }if(b==false)
    {
        cout<<"Invalid info!!"<<endl;
    }
}
void Student::update(Student std[],int &n)
{
    int sr,b=0;
    cout<<"Enter ID Student for Update=";
      while(!(cin>>sr))
    {
        cout<<"Erorr: Enter Number ID";
        cin.clear();
        cin.ignore(123,'\n');
    }
    for(int i=0;i<n;i++)
    {
        if(sr==std[i].getId())
        {
            b=true;
            std[i].input();
        }
    }if(b==false)
    {
        cout<<"Sorry Invalid ID="<<sr<<endl;
    }
}
void Student::Delete(Student std[],int &n)
{
    int sr,b=0;
    cout<<"Enter ID For search=";
      while(!(cin>>sr))
    {
        cout<<"Erorr: Enter Number of ID";
        cin.clear();
        cin.ignore(123,'\n');
    }
    for(int i=0;i<n;i++)
    {
        if(sr==std[i].getId())
        {
            for(int j=i;j<n;j++)
            {
                std[j]=std[j+1];
            }
            n--;
            b=true;
            cout<<"Was Deleted"<<endl;
        }
    }if(b==false)
    {
        cout<<"Invalid ID="<<sr<<endl;
    }
}
void Student::insert(Student std[],int &n)
{
    int sr,b=0;
    cout<<"Enter Index You want insert=";
      while(!(cin>>sr))
    {
        cout<<"Erorr: Enter Number of Index=";
        cin.clear();
        cin.ignore(123,'\n');
    }
    if(sr>n)
    {
        cout<<"Invalid"<<sr<<"Bigger than index of array"<<n<<endl;
    }else{
        for(int i=n;i>sr;i--)
        {
            std[i]=std[i-1];
        }
        n++;
         b=true;
        std[sr].input();
        cout<<"Insert Successfully"<<endl; 
    }
}
void menu()
{
    cout<<string(100,'-')<<endl;
    cout<<"[1].Input Student"<<endl;
    cout<<"[2].Output Student"<<endl;
    cout<<"[3].Find Hight Average Student"<<endl;
    cout<<"[4].Search Student"<<endl;
    cout<<"[5].Update Student"<<endl;
    cout<<"[6].Delete Student"<<endl;
    cout<<"[7].Insert Student"<<endl;
    cout<<"[8].Add Student "<<endl;
    cout<<"[9].Exit System"<<endl;
}

int main()
{
    int n,op;
    cout<<"Enter Number of Student=";cin>>n;
    Student std[20];
    do{
       menu();
       cout<<"Please chhoes one option in system=";cin>>op;
       switch(op)
       {
        case 1:{
            cout<<"Please Enter Data of student here"<<endl;
            for(int i=0;i<n;i++)
            {
                std[i].input();
            }
            break;
        }
        case 2:{
            for(int i=0;i<n;i++)
            {
                std[i].output();
            }
            break;
        }
        case 3:{
           std->finav(std,n);
           break;
            break;
        }
        case 4:{
            std->search(std,n);
           break;
        }
        case 5:{
            cout<<"Please Update Info Student"<<endl;
            std->update(std,n);
            break;
        }
        case 6:{
            std->Delete(std,n);
            break;
        }
        case 7:{
            std->insert(std,n);
            break;
        }
        case 8:{
              int nu;
            cout<<"Enter Number number of student you want add more=";cin>>nu;
            for(int i=n;i<n+nu;i++)
            {
                std[i].input();
            }
              n+=nu;
            break;
        }
       }
    }while(op!=9);
    cout<<"Bye Bye "<<endl;
    return 0;
}