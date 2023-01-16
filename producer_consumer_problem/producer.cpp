#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <queue>
#include <deque>
#include <cmath>
#include <random>
#include <cstdlib>
#include <time.h>
#include<cmath>
using namespace std;

#define BUFF_SIZE 500

 

struct product{
   char name[11];
   double price=0.00;
   double avgprice=0.00;
};
struct pro{
	product arr[BUFF_SIZE];
	int idx=0;
	int index=0;
};
key_t key4 = ftok("memfile",68);
int shmid=shmget(key4, sizeof(struct pro), 0666 | IPC_CREAT);
struct pro *arr1=(struct pro *) shmat(shmid,0,0);

double mean;
double dev;int l;
int time_int;
char buf[255];
string n;int NN;
struct product p;
void gettime(){
  struct tm tm;
    char bf[255];
struct timespec tp;
  clockid_t clk_id;
  clk_id = CLOCK_REALTIME;
 clock_gettime(clk_id, &tp);
    int s=tp.tv_sec+60*60*2;
    l=(tp.tv_nsec%100)%60;
    string str= to_string(s);
    //printf("%s\n",str.c_str());
    memset(&tm, 0, sizeof(struct tm));
    strptime(str.c_str(), "%s", &tm);
    strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S ", &tm);
   // puts(buf); 
};


void produce(){
       // cout << "index in produce : "<< arr1->idx;
	default_random_engine generator;
	normal_distribution<double> distribution(mean,dev);
	p.price=distribution(generator);
	string com;
      //  strcpy(p.name,com.c_str());
    // puts(com);
    gettime();
     //cout<<p.name;
   // cout<<com;
   strcpy(arr1->arr[arr1->idx].name,n.c_str());
	
   cout<<arr1->arr[arr1->idx].name;
	fprintf( stderr,"\033[;31m [%s.%d] %s: generating a new value %7.2lf\033[0m\n",buf,l,arr1->arr[arr1->idx].name,p.price);
	fprintf( stderr,"\033[;31m [%s.%d] %s: sleeping for  %d milliseconds\033[0m\n",buf,l,arr1->arr[arr1->idx].name,time_int);
	
	sleep(time_int/1000);
	
	//cout << "price= "<< p.price << " name= "<< p.name <<"\n";
	
}

void append(){
	
	/*if (arr1->idx == BUFF_SIZE-1){
		arr1->idx =0;
	}*/
	arr1->arr[arr1->idx].price=p.price;
	fprintf( stderr,"\033[;31m [%s.%d] %s: placing  %7.2lf on shared buffer \033[0m\n",buf,l,arr1->arr[arr1->idx].name,p.price);
	
	strcpy(arr1->arr[arr1->idx].name,n.c_str());
	//arr1->arr[arr1->idx].name="GAS";
	//cout<<"farah2\n";
	cout<< "index: "<<(arr1->idx)<<"\n";
	cout << "the array name "<< arr1->arr[arr1->idx].name << " the array price "<<  arr1->arr[arr1->idx].price<<"\n";
	(arr1->idx)++;
	//arr1->idx=((arr1->idx)+1)%BUFF_SIZE;
}

void producer(){
int semid1,semid2,semid3;
key_t key1=ftok("file1",65);
if(semid1 >= 0){
   semid1=semget(key1,1,0666 | IPC_CREAT);  
}   
else
{ semid1=semget(key1,1,0); }     
int i1=semctl(semid1,0,SETVAL,1);

key_t key2=ftok("file2",66);
if(semid2 >= 0){
 semid2=semget(key2,1,0666 | IPC_CREAT); 
}
else
{ semid2=semget(key2,1,0); }     
int i2=semctl(semid2,0,SETVAL,0);
key_t key3=ftok("file3",67);
if(semid3 >= 0){
 semid3=semget(key3,1,0666 | IPC_CREAT);
}
else
{ semid3=semget(key3,1,0); }     
int i3=semctl(semid3,0,SETVAL,BUFF_SIZE);
       struct sembuf sops[1];
       sops[0].sem_num=0;
       sops[0].sem_op=0;
       sops[0].sem_flg=0;
	while(true){
	        //cout<<"\n"<<"hello\n";
		produce();
		fprintf( stderr,"\033[;31m [%s.%d] %s: trying to get mutex on shared buffer \033[0m\n",buf,l,arr1->arr[arr1->idx].name);
	
		//cout<< "hello1\n";
		sops[0].sem_op=-1;
		semop(semid3,sops,1);
		//cout<< "hello2\n";
		sops[0].sem_op=-1;
		semop(semid1,sops,1);
                append();
                sops[0].sem_op=1;
		semop(semid1,sops,1);
		sops[0].sem_op=1;
		semop(semid2,sops,1);
		
	}
	

}


int main(int argc,char *argv[]){
	n=argv[1];
	mean=stod(argv[2]);
	dev=stod(argv[3]);
	time_int=atoi(argv[4]);
	NN=atoi(argv[5]);
        producer();
        return 0;
}

