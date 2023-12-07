#include<iostream>
#include<fstream>

using namespace std;

class Shopping{
    
    int pcode; //product code
    float price;
    float dis; // discount
    string pname ;// product name
    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void Shopping::menu(){
    m:
    int choice;
    string email;
    string password;
    cout<<"\t\t\t\t\t--------------------------------\n";
    cout<<"\t\t\t\t\t--------------------------------\n";
    cout<<"\t\t\t\t\t--------------------------------\n";
    cout<<"\t\t\t\t\t       Supermarket main menu    \n";
    cout<<"\t\t\t\t\t--------------------------------\n";
    cout<<"\t\t\t\t\t--------------------------------\n";
    cout<<"\t\t\t\t\t--------------------------------\n";
    cout<<"\t\t\t\t\t                                \n";
    cout<<"\t\t\t\t\t|  1) Administrator            |\n";
    cout<<"\t\t\t\t\t|                              |\n";
    cout<<"\t\t\t\t\t|  2) Buyer                    |\n";
    cout<<"\t\t\t\t\t|                              |\n";
    cout<<"\t\t\t\t\t|  3) Exit                     |\n";
    cout<<"\n\t\t\t\t|   Please select !";
    cin>>choice;


    switch (choice)
    {
    case 1: 
        cout<<"\t\t\t\t  Please login \n";
        cout<<"\t\t\t    Enter email  \n";
        cin>>email;
        cout<<"\t\t\t    Enter password \n";
        cin>>password;

        if(email=="astrosabcd@gmail.com" && password=="robins"){
            administrator();
        }
        else{
            cout<<"Invalid email/password";
        }
        break;
    case 2:
        buyer();
    case 3:
        exit(0);

    default:
        cout<<"Please select from the given options";
        break;
    }

    goto m; 
}

void Shopping:: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t Administrator menu";
    cout<<"\n\t\t\t|------1) Add the product-------|";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t|------2) Modify the product ---|";
     cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|------3) Delete the product ---|";
     cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|------1) Add the product------ |";

    cout<<"\n\t\t Please enter your choice";
    cin>>choice;

    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            menu();
            break;
        default:
                          cout<<"Invalid choice";
    }
goto m;

}

void Shopping:: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t   Buyer   \n";
    cout<<"\n";
    cout<<"\t\t\t   1: Buy product \n";
    cout<<"\n";
    cout<<"\t\t\t   2: Go Back     \n";
    cout<<"\t\t\t Enter your choice : ";

    cin>>choice;

    switch(choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();
        default:
            cout<<"Invalid choice";
    }
    goto m;
}

void Shopping:: add(){
    m:
    fstream data;
    int c;
    int token =0;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t\t  Add new product";
    cout<<"\n\n\t\t\t  Product code of the product ";
    cin>>pcode;
    cout<<"\n\n\t\t\t Name of the product ";
    cin>>pname;
    cout<<"\n\n\t\t\t Price of the product ";
    cin>>price;
    cout<<"\n\n\t Discout on product ";
    cin>>dis;

    data.open("database.txt", ios::in);

    if(data){
        data.open("database.txt", ios::app|ios::in|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
        data.close();
    }
    else{
        cout<<"Enter code , name, price, discount"<<endl;
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c == pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

    if(token==1)
    goto m;
    else{
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    }

    cout<<"\n\n\t\t  Record inserted ! ";
}

void Shopping:: edit(){
    fstream data, data1;
    int pkey, token =0, c;
    float p, d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;

    data.open("database.txt", ios::in);
    if(!data){
        cout<<"\n\n File doesn't exist! ";
    }else{
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey == pcode){
                cout<<"\n\t\t Product new code: ";
                cin>>c;
                cout<<"\n\t\t Price";
                cin>>p;
                cout<<"\n\t\t Discount: ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited ";
            }else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0){
            cout<<"\n\n Record not found";
        }
    }
}

void Shopping::rem(){
    fstream data, data1;
    int pkey, token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code: ";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File does not exist";
    }
    else{
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

    }
}



void Shopping::list(){
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n|___________________________________________\n";
    cout<<"Profile\t\t Name \t\t Price\n";
    cout<<"\n\n|___________________________________________\n";
    data>>pcode>>pname>>price>>dis;

    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<endl;
        data>>pcode>>pname>>price>>dis;
        
    }
    data.close();

}

void Shopping::receipt(){
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c= 0;
    float amount =0, dis = 0, total = 0;

    cout<<"\n\n\t\t\t Receipt";
    data.open("database.txt", ios::in);
    if(!data){
        cout<<"\n\n Empty database";
    }
    else{
        data.close();

        list();
        cout<<"\n___________________________________________\n";
        cout<<"\n                                           \n";
        cout<<"\n            Please Place your order        \n"; 
        cout<<"\n                                           \n";
        cout<<"\n___________________________________________\n";
        do{
            cout<<"\n\n Enter product code : ";
            cin>>arrc[c];
            cout<<"\n\n Enter the product quantity : ";
            cin>>arrq[c];
            for(int i =0; i<c; i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n Duplicate product code , Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product ? If yes then pres y else no";
            cin>>choice;

        }
        while(choice == 'y');
        cout<<"\n\n\t\t\t_________________RECEIPT_____________________\n";
        cout<<"\nProduct No \t Product Name\tProduct Quantity\t Price\t Amount with discount\n";

        for(int i =0; i<c; i++){
            data.open("database.txt", ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode == arrc[i])
                amount = price*arrq[i];
                dis = amount - (amount*dis/100);
                total = total -dis;
                cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
            }
        }
        data.close();
    }
    cout<<"\n\n________________________________________";
    cout<<"\n Total Amount : "<<total;
}

int main(){
    Shopping s;
    s.menu();
}