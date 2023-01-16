#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>

#define Item(X, I, J, NCOL)      X[((J) + (I) * (NCOL))]
#define NTHREAD  l * n
/*
 * matrix multiplication
 *     C = A*B
 *     A has l rows and m cols
 *     B has m rows and n cols
 *     C has l rows and n cols
 */
void matmult(int* A, int* B, int* C, int l, int m, int n)
{
    for(int i=0; i<l; i++)
        for(int j=0; j<n; j++)
        {
            int sum = 0;
            for(int k=0; k<m; k++)
                sum += Item(A, i, k, m) * Item(B, k, j, n);
            Item(C, i, j, n) = sum;
        }
}



/*
 * matrix multiplication
 *     C = A*B
 *     A has l rows and m cols
 *     B has m rows and n cols
 *     C has l rows and n cols
 */
 //the struct that will be send in the fourth argument in pthread_create
struct parameter{
    	int *a,*b,*c;
    	int x,y,z;
    	int rowidx;
    	int colidx;
};
//the function that calculates the multiplication for each element  
void *element(void *arg)
{       
	struct parameter *para = (struct parameter*) arg; 
	int sum1=0;
	for(int k=0;  k<para->y ; k++){
		sum1+= Item(para->a, para->rowidx, k, para->y) * Item(para->b, k, para->colidx, para->z);
		Item(para->c, para->rowidx, para->colidx, para->z) = sum1;
	}

}

void matmult_v1(int* A, int* B, int* C, int l, int m, int n)
{  
   
    struct parameter p[l][n];
    for(int v=0;v<l;v++){
    	for(int w=0;w<n;w++){
    		p[v][w].a=A;
    		p[v][w].b=B;
    		p[v][w].c=C;
    		p[v][w].x=l;
    		p[v][w].y=m;
    		p[v][w].z=n;
    	}
    }
    
    pthread_t threads[l][n];
    for(int i=0;i<l;i++){
		for(int j=0; j<n ; j++){
			p[i][j].rowidx=i;
			p[i][j].colidx=j;
			pthread_create(&threads[i][j],NULL,element,(void*) &p[i][j]);
		}
		
	}
	
	for(int s=0;s<l;s++){
		for(int e=0; e<n ; e++){
			pthread_join(threads[s][e],NULL);
		}
	}
   
}



/*
 * matrix multiplication
 *     C = A*B
 *     A has l rows and m cols
 *     B has m rows and n cols
 *     C has l rows and n cols
 */
 //the function that calculates the multiplication for each row  
void *row(void *arg2)
{
	struct parameter *par = (struct parameter*) arg2; 
	
	for(int j=0; j<par->z ; j++){
		int sum2=0;
		for(int k=0;  k<par->y ; k++){
			sum2+= Item(par->a, par->rowidx, k, par->y) * Item(par->b, k, j, par->z);
			Item(par->c, par->rowidx, j, par->z) = sum2;
		}
	}
}

void matmult_v2(int* A, int* B, int* C, int l, int m, int n)
{
	struct parameter p2[l];
	for(int w=0;w<l;w++){
    		p2[w].a=A;
    		p2[w].b=B;
    		p2[w].c=C;
    		p2[w].x=l;
    		p2[w].y=m;
    		p2[w].z=n;
    		p2[w].rowidx=w;
    	}
	pthread_t threads2[l];
        for(int i=0;i<l;i++){
		pthread_create(&threads2[i],NULL,row,(void*) &p2[i]);
        }
        for(int s=0;s<l;s++){
		pthread_join(threads2[s],NULL);
	}

}
