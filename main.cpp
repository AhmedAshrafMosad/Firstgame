#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

using namespace std;

int main()
{

    int m_trial, n_trial;
    int score, g_timeout;
    int width, length;
    int area , user_area;
    int table_size;
    time_t user_stime, user_timeout;


    g_timeout   = 5;
    table_size  = 5;
    m_trial     = 5;
    n_trial     = 0;
    score       = 0;

    srand(time(0));


    cout << "\t\t***Welcome to my first Game :)****\n";
    cout << "\tVision the Shape and Calculate its Area in "<<g_timeout<<" seconds. \n";
    cout << "\n\nPress Enter to start playing ...";
    cin.get();

    do{

        width       = 2+rand()%table_size;
        length      = 2+rand()%table_size;
        area        = width * length;
        n_trial++;


        cout<<"\n\n\n";


        for(int i=0;i<length;i++){

            cout << "\t\t";
            for(int j=0; j<width; j++){
                cout<<"# ";
            }
            cout<<"\n";
        }

        user_stime = time(0);
        cout<<"Area = ";
        cin >>user_area;

        user_timeout = time(0) - user_stime;
        cout<<"You take " << user_timeout <<"s to answer!....\n";


        if(user_area==area && user_timeout <= g_timeout){
            score++;
            cout<< "\tCorrect :)\n";
        }else if(user_area!= area){
            cout<< "\tWrong :( \n";
        }else {
            cout<< "\tTimeout :|, try fast\n";
        }

        sleep(3);
        system("cls");
        for(int i=3; i>0; i--){
            cout<< "\n\t\tStart Next in "<< i << "s...\n";
            sleep(1);
            system("cls");
        }

    }

    while(n_trial<m_trial);


    cout<<"\t\tGAME OVER\n";
    cout<<"\t\tYour Score is :" <<(score*1.0/m_trial)*100.0 <<"%\n";

    return 0;
}
