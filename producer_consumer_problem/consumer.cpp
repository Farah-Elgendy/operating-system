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
#include <cstdio> 

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

struct allpr{
       char name[11];

       int ii=0;
       double sum=0.00;
       double price=0.00;
       int flag=0;
       int flagavgprice=0;
    //   vector <double> price (5);
       double avgprice=0.00;
       
};
//vector<struct allpr> allproducts(11);
//vector < vector<double>> prices(11);

//vector<double> allproducts(11);
key_t key4 = ftok("memfile",68);
int shmid=shmget(key4, sizeof(struct pro), 0666 | IPC_CREAT);
struct pro *arr1=(struct pro *) shmat(shmid,0,0);
struct product p[BUFF_SIZE];
vector<struct allpr> allproducts(11);
vector<struct allpr> allproductsV1(11);
vector<struct allpr> allproductsV2(11);
string com;
//strcpy(allproducts[0].name,com.c_str());
	

double pri;
int j=0;
product *pt1=p;
product *pt2=p+1;
char strings[11][13]={"ALUMINUM    ","COPPER      ","COTTON      ","CRUDEOIL    ","GOLD        ","LEAD        ","MENTHAOIL   ","NATURALGAS  ","NICKEL      ","SILVER      ","ZINC        "};
void initialize(){
			
    for(int o=0;o<11;o++)
    {
         allproducts[o].ii=0;
         allproducts[o].sum=0.00;
         allproducts[o].price=0.00;
       //   allproducts[o].flag=0;
        // allproducts[o].flagavgprice=0; 
         allproducts[o].avgprice=0.00;
    }   

}


void take(){
        
	com=arr1->arr[arr1->index].name;
	strcpy(p[j].name,com.c_str());
	p[j].price=arr1->arr[arr1->index].price;
	
	//cout << "index "<< arr1->index<<"\n";
	//cout << "name: "<< p[j].name<< " price: "<<p[j].price<<"\n";
	//if(strcmp(p[j].name,"GOLD")==0)
      // {
       // allproducts[0].price=p[j].price;  cout<<"*******************************"<<allproducts[0].price<<endl;
   // }
	j++;
	//cout << " name "<< p.name<<"price"<<p.price<<"\n"; 
	//cout << " name "<< com <<"\n"<< " price "<<  pri<<"\n";	
	//cout << " the array name "<< arr1->arr[arr1->index].name <<"\n"<< " the array price "<<  arr1->arr[arr1->index].price<<"\n";
	//cout << "hello\n";
	allproductsV1=allproducts;	
       
	initialize();
    cout<<j<<endl;int nn;
    for(int k=j-1;k>=0;k--){
      
      if(strcmp(p[k].name,"ALUMINUM")==0)
       {
         if(k==j-1)    allproducts[0].price=p[k].price;  
         if(allproducts[0].ii<5)
          { nn=allproducts[0].ii;
            allproducts[0].sum=allproducts[0].sum+p[k].price;
           //prices[0][nn]=p[k].price;
           allproducts[0].ii+=1;
          } 
            
       }
        if(strcmp(p[k].name,"COPPER")==0)
       {
         if(k==j-1)    allproducts[1].price=p[k].price;
         
         if(allproducts[1].ii<5)
          { nn=allproducts[1].ii;
            allproducts[1].sum=allproducts[1].sum+p[k].price;
           //prices[0][nn]=p[k].price;
           allproducts[1].ii+=1;
          } 
           
       }
        if(strcmp(p[k].name,"COTTON")==0)
       {
         if(k==j-1)    allproducts[2].price=p[k].price;
         
         if(allproducts[2].ii<5)
          { nn=allproducts[2].ii;
            allproducts[2].sum=allproducts[2].sum+p[k].price;
           //prices[0][nn]=p[k].price;
           allproducts[2].ii+=1;
          } 
           
       }  
     if(strcmp(p[k].name,"CRUDEOIL")==0)
       {
         if(k==j-1)    allproducts[3].price=p[k].price;
         
         if(allproducts[3].ii<5)
          { nn=allproducts[3].ii;
            allproducts[3].sum=allproducts[3].sum+p[k].price;
           //prices[0][nn]=p[k].price;
           allproducts[3].ii+=1;
          } 
            
       }
     if(strcmp(p[k].name,"GOLD")==0)
       {
         if(k==j-1)    allproducts[4].price=p[k].price;
         
         if(allproducts[4].ii<5)
          { nn=allproducts[4].ii;
            allproducts[4].sum=allproducts[4].sum+p[k].price;
            allproducts[4].ii+=1;
          }                   
       }
       
       if(strcmp(p[k].name,"LEAD")==0)
       {
         if(k==j-1)    allproducts[5].price=p[k].price;
         if(allproducts[5].ii<5)
          { nn=allproducts[5].ii;
            allproducts[5].sum=allproducts[5].sum+p[k].price;
            allproducts[5].ii+=1;
          }                   
       }
       if(strcmp(p[k].name,"MENTHAOIL")==0)
       {
         if(k==j-1)    allproducts[6].price=p[k].price;
         
         if(allproducts[6].ii<5)
          { nn=allproducts[6].ii;
            allproducts[6].sum=allproducts[6].sum+p[k].price;
            allproducts[6].ii+=1;
          }                   
       }
       if(strcmp(p[k].name,"NATURALGAS")==0)
       {
         if(k==j-1)    allproducts[7].price=p[k].price;
         
         if(allproducts[7].ii<5)
          { nn=allproducts[7].ii;
            allproducts[7].sum=allproducts[7].sum+p[k].price;
            allproducts[7].ii+=1;
          }                   
       }
       if(strcmp(p[k].name,"NICKEL")==0)
       {
         if(k==j-1)    allproducts[9].price=p[k].price;
         
         if(allproducts[8].ii<5)
          { nn=allproducts[8].ii;
            allproducts[8].sum=allproducts[8].sum+p[k].price;
            allproducts[8].ii+=1;
          }                   
       }
       if(strcmp(p[k].name,"SILVER")==0)
       {
         if(k==j-1)    allproducts[9].price=p[k].price;
         
         if(allproducts[9].ii<5)
          { nn=allproducts[9].ii;
            allproducts[9].sum=allproducts[9].sum+p[k].price;
            allproducts[9].ii+=1;
          }                   
       }
      if(strcmp(p[k].name,"ZINC")==0)
       {
         if(k==j-1)    allproducts[10].price=p[k].price;
         
         if(allproducts[10].ii<5)
          { nn=allproducts[10].ii;
            allproducts[10].sum=allproducts[10].sum+p[k].price;
            allproducts[10].ii+=1;
          }                   
       }  
       
       }
       
       
       
       for(int neww=0;neww<11;neww++)
       {
          if(allproducts[neww].ii!=0)
       allproducts[neww].avgprice= allproducts[neww].sum/allproducts[neww].ii;
       }
	allproductsV2=allproducts;	
   
     (arr1->index)++;
     //arr1->index=((arr1->index)+1)%BUFF_SIZE;
}

void consume(){
    
    cout << "hello\n";
    //Compare V2 with V1	
   // cout<<j<<endl;int nn;
    
       
      
     for(int neww=0;neww<11;neww++)
       {
          // cout<<allproductsV2[neww].price<<"and "<< allproductsV1[neww].price <<endl;
            if( allproductsV2[neww].price > allproductsV1[neww].price )
             { allproducts[neww].flag=1; }
            else if( allproductsV2[neww].price < allproductsV1[neww].price )
             { allproducts[neww].flag=-1;}
          //  else
            //   allproducts[neww].flag=0;  
         
         
            if( allproductsV2[neww].avgprice > allproductsV1[neww].avgprice )
              allproducts[neww].flagavgprice=1;
            else if( allproductsV2[neww].avgprice < allproductsV1[neww].avgprice )
              allproducts[neww].flagavgprice=-1;
        //    else
          //     allproducts[neww].flagavgprice=0;  
       }
       
    // printf("\e[1;1H\e[2J");
     system("clear");
  
       
     cout<<"+---------------------------------------------+"<<endl;
    cout<<"|Currency     |   Price       |   AvgPrice    |"<<endl;   
   cout<<"-----------------------------------------------"<<endl;
   
        for(int neww=0;neww<11;neww++)
    {
       cout<<"| "<< strings[neww] <<"|   ";
        if( allproducts[neww].flag==1 )
       printf("\033[;32m %7.2lf↑ \033[0m  |   ",allproducts[neww].avgprice);
       else if( allproducts[neww].flag==-1 )
        printf("\033[;31m %7.2lf↓ \033[0m  |   ",allproducts[neww].avgprice);
       else
         printf("\033[;34m %7.2lf \033[0m   |   ",allproducts[neww].avgprice);
       if( allproducts[neww].flagavgprice==1 )
       printf("\033[;32m %7.2lf↑ \033[0m  |   ",allproducts[neww].avgprice);
        else if( allproducts[neww].flagavgprice==-1 )
         printf("\033[;31m %7.2lf↓ \033[0m  |   ",allproducts[neww].avgprice);
      
        else
         printf("\033[;34m %7.2lf \033[0m   |   ",allproducts[neww].avgprice);
       cout<<endl;
       if(neww!=10) cout<<"-----------------------------------------------"<<endl;
   
    }
     cout<<"+---------------------------------------------+"<<endl;
    
}

void consumer(){
      // cout << "hello1\n";
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
		//cout<<"hi 1\n";
		sops[0].sem_op=-1;
		semop(semid2,sops,1);
		//cout<<"hi 2\n";
		sops[0].sem_op=-1;
		semop(semid1,sops,1);
		//cout<<"hi 3\n";
                take();
                sops[0].sem_op=1;
		semop(semid1,sops,1);
		//cout<<"hi 4\n";
		sops[0].sem_op=1;
		semop(semid3,sops,1);
		//cout<<"hi 5\n";
		consume();
	}
	shmdt(arr1);
	shmctl(shmid,IPC_RMID,NULL);
        semctl(semid1,0,IPC_RMID);
        semctl(semid2,0,IPC_RMID);
        semctl(semid3,0,IPC_RMID);	
        	

}


int main(int argc, char * argv[]){
    //cout<<"hi farah";
    consumer();
    return 0;
}

