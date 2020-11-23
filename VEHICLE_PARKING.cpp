# S#include<iostream>
#include<vector>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class vehicle;
class time;
class date;
int compute_Time_Difference(time ,time );

vector <vehicle> veh(100);
int static total_vehicle=0,pos=0,total_car=0,total_bike=0,total_amt=0,total_bus=0,total_rickshaw=0;




class time
{
    public:
    int hh;
    char col1;
    int mm;
    char col2;
    int ss;
};

class date
{
  public:
  int day;
  char sym1;
  int month;
  char sym2;
  int year;
};

class vehicle : public time , public date
{
    string pltno;
    int type;
    date dt;
    time arrive;
    time departure;

public:
    //static int total_vehicle;//total_car,total_bike,total_bus,total_rickshaw,total_amt;




    void add_Vehicle(){

      vehicle *v = new vehicle;
      cout<<endl<<endl<<"          Enter vehicle type(1 for Car / 2 for Bike / 3 for Bus / 4 for Rickshaw) : ";
      cin>>v->type;
      cout<<endl<<"          Enter vehicle number : ";
      cin>>v->pltno;
      cout<<endl<<"          Enter arrival time in hh:mm:ss : ";
      cin>>v->arrive.hh>>v->arrive.col1>>v->arrive.mm>>v->arrive.col2>>v->arrive.ss;
      cout<<endl<<"          Enter date in dd/mm/yyyy : ";
      cin>>v->dt.day>>v->dt.sym1>>v->dt.month>>v->dt.sym2>>v->dt.year;

      veh.at(pos).pltno=v->pltno;
      veh.at(pos).type=v->type;
      veh.at(pos).arrive.hh=v->arrive.hh;
      veh.at(pos).arrive.mm=v->arrive.mm;
      veh.at(pos).arrive.ss=v->arrive.ss;
      veh.at(pos).dt.day=v->dt.day;
      veh.at(pos).dt.month=v->dt.month;
      veh.at(pos).dt.year=v->dt.year;



     bool y=false;
     try{
        // pos++;
      //total_vehicle++;

          if(v->type == 1)
      {
          pos++;
          total_vehicle++;
          y=true;
          total_car++;
          system("COLOR F2");
          cout<<endl<<"          ----------------------------------Car added successfully-------------------------------- "<<endl;
      }
      else if(v->type == 2)
        {
          pos++;
      total_vehicle++;
          y=true;
          total_bike++;
          system("COLOR F2");
          cout<<endl<<"          ----------------------------------Bike added successfully------------------------------- "<<endl;
        }
      else if(v->type == 3)
      {
          pos++;
          total_vehicle++;
          y=true;
          total_bus++;
          system("COLOR F2");
          cout<<endl<<"          ----------------------------------Bus added successfully-------------------------------- "<<endl;
      }
      else if(v->type == 4)
      {
          pos++;
          total_vehicle++;
          y=true;
          total_rickshaw++;
          system("COLOR F2");
          cout<<endl<<"          ----------------------------------Rickshaw added successfully--------------------------- "<<endl;
      }

      else if(y==false)
        throw 10;

    }
    catch(int e){
    cout<<endl<<endl<<"          WRONG ENTRY , PLEASE ENTER AGAIN"<<endl;
    add_Vehicle();
    }

}



    void delete_Vehicle()
  {
      string pno;
      int typ;
      time depart;
      int time_diff;
      int charge=0;

      cout<<endl<<endl<<"          Enter vehicle type(1 for Car / 2 for Bike / 3 for Bus / 4 for Rickshaw) : ";
      cin>>typ;
      cout<<endl<<"          Enter vehicle number : ";
      cin>>pno;
      cout<<endl<<"          Enter departure time in hours minutes and seconds : ";
      cin>>depart.hh>>depart.col1>>depart.mm>>depart.col2>>depart.ss;



      for(int j=0;j<=pos;j++)
      {
          if((veh.at(j).pltno==pno) && (veh.at(j).type==typ))
          {
              veh.at(j).departure.hh=depart.hh;
              veh.at(j).departure.mm=depart.mm;
              veh.at(j).departure.ss=depart.ss;

              time_diff=compute_Time_Difference(veh.at(j).arrive,depart);

              if(veh.at(j).type == 1)
              {
                  total_car--;
                  total_vehicle--;
                  if(time_diff<2)
                  {
                      charge=20;
                      total_amt+=20;
                  }
                  else
                  {
                      if((time_diff>2) && ((time_diff<5))){
                              charge=40;
                              total_amt+=40;
                          }
                          else
                            {
                               charge=80;
                               total_amt+=80;
                            }
                  }

              }
              else if(veh.at(j).type == 2)
              {
                  total_bike--;
                  total_vehicle--;

                      if( time_diff<2)
                      {
                          charge=15;
                          total_amt+=15;
                      }
                      else
                      {
                          if((time_diff>2) && ((time_diff<5)))
                              {
                                  charge=30;
                                  total_amt+=30;
                              }
                              else
                                {
                                   charge=60;
                                    total_amt+=60;
                                }
                      }

              }
              else if(veh.at(j).type == 3)
              {
                  total_bus--;
                   total_vehicle--;

                      if( time_diff<2)
                      {
                          charge=25;
                           total_amt+=25;
                      }
                      else
                      {
                          if((time_diff>2) && ((time_diff<5)))
                              {
                                  charge=50;
                                   total_amt+=50;
                              }
                              else
                                {
                                   charge=100;
                                    total_amt+=100;
                                }
                      }

              }
              else
              {
                  total_rickshaw--;
                   total_vehicle--;

                      if( time_diff<2)
                      {
                          charge=5;
                           total_amt+=5;
                      }
                      else
                      {
                          if((time_diff>2) && ((time_diff<5)))
                              {
                                  charge=10;
                                   total_amt+=10;
                              }
                              else
                                {
                                   charge=20;
                                    total_amt+=20;
                                }
                      }

              }


              system("cls");
              system("COLOR F4");
              cout<<endl<<endl<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
              cout<<endl<<"          Vehicle having vehicle number  : "<<veh.at(j).pltno<<" has left the parking after paying Rs. "<<charge<<endl;
              cout<<endl<<"------------------------------------------------------------------------------------------------------------------------"<<endl;


         if(j==pos)
          {
              cout<<endl<<" Wrong Entry , Try Again "<<endl;
              delete_Vehicle();
          }

      }



  }
}



    void print_vehicle(vehicle v){

    cout<<endl<<"        "<<v.type<<"                "<<v.pltno<<"             "<<v.dt.day<<"/"<<v.dt.month<<"/"<<v.dt.year<<"          "<< v.arrive.hh<<":"<<v.arrive.mm<<":"<<v.arrive.ss<<endl;

    }


    void show_info(){

      cout<<endl<<endl<<"     Vehicle Type     Vehicle Number     Date            Arrival Time"<<endl;
      for(int j=0;j<pos;j++)
      {
          print_vehicle(veh[j]);
      }


    }


};

//int vehicle :: total_vehicle=0;

int compute_Time_Difference(time t1,time t2)
  {

   int sec1, sec2, totalsec;
   time t3;

    sec1 = t1.hh*60*60 + t1.mm*60 + t1.ss;
    sec2 = t2.hh*60*60 + t2.mm*60 + t2.ss;

    totalsec = sec2-sec1;


    t3.mm = totalsec/60;
    t3.hh = t3.mm/60;
    if(t3.hh < 0)
        return t3.hh*(-1);
    else
       return t3.hh;
}

void total_veh()
  {

      cout<<endl<<endl<<"          Total number of car parked      : "<<total_car<<endl;
      cout<<endl<<"          Total number of bike parked     : "<<total_bike<<endl;
      cout<<endl<<"          Total number of Bus parked      : "<<total_bus<<endl;
      cout<<endl<<"          Total number of Rickshaw parked : "<<total_rickshaw<<endl;
      cout<<endl<<"------------------------------------------ ---"<<endl;
      cout<<endl<<"          Total number of vehicle parked  : "<<total_vehicle<<endl;
      cout<<endl<<"------------------------------------------ ---"<<endl;

  }

  void total_amount()
  {
      cout<<endl<<endl<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
      cout<<endl<<"          Total Collection till now is : "<<total_amt<<endl;
       cout<<endl<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  }

//int vehicle :: total_vehicle=0,total_car=0,total_bike=0,total_amt=0,total_bus=0,total_rickshaw=0;


int main()
{
    int choice;
    /*system("cls");
    system("COLOR F0");

     cout<<"****************************************************************************************************"<<endl;
     cout<<"                           WELCOME TO SHERU'S VEHICLE PARKING RESERVATION SYSTEM                 "<<endl;
     cout<<endl<<"                           1. Arrival of a vehicle"<<endl;
     cout<<"                           2. Total number of vehicles parked "<<endl;
     cout<<"                           3. Departure of vehicle"<<endl;
     cout<<"                           4. Total Amount collected "<<endl;
     cout<<"                           5. Display "<<endl;
     cout<<"                           6. Exit"<<endl;
     cout<<endl<<"****************************************************************************************************"<<endl;*/

     do{

        system("cls");
        system("COLOR F0");

        cout<<"****************************************************************************************************"<<endl;
        cout<<"                           WELCOME TO SHERU'S VEHICLE PARKING RESERVATION SYSTEM                 "<<endl;
        cout<<endl<<"                           1. Arrival of a vehicle"<<endl;
        cout<<"                           2. Total number of vehicles parked "<<endl;
        cout<<"                           3. Departure of vehicle"<<endl;
        cout<<"                           4. Total Amount collected "<<endl;
        cout<<"                           5. Display "<<endl;
        cout<<"                           6. Exit"<<endl;
        cout<<endl<<"****************************************************************************************************"<<endl;
        cout<<endl<<"                           Enter your choice :-> ";
        cin>>choice;

        switch(choice){

        case 1 : {
                    cout<<endl;
                    system("cls");
                    veh.at(pos).add_Vehicle();getch();
                     break;
                 }
        case 2 : {
                   cout<<endl;
                   system("cls");
                   total_veh();getch();
                   break;
                 }
        case 3 : {
                   cout<<endl;
                    system("cls");
                    veh.at(pos).delete_Vehicle();getch();
                    break;
                 }
        case 4 : {
                   cout<<endl;
                   system("cls");
                   total_amount();getch();
                   break;
                 }
        case 5 : {
                     system("cls");
                     veh.at(pos).show_info();getch();
                     break;
                 }


        }


     }while(choice!=6);
}
