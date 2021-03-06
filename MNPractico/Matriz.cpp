#include<iostream>
#include<cmath>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

using namespace std;

int EGauss (int n , double a[4][4], double b[4],double x[4]);
int mostrarMatriz(double a[4][4]);
int mostrarVector(double b[4]);

int main(int argc, char* argv[]){
setlocale(LC_ALL, "spanish");
/*double a[4][4]={0,0,0,0,
		0,2,1,1,
	     	0,1,2,1,
	     	0,1,1,2}; 

double b[4]={0,4,4,4};
double x[4];
int n=3;
mostrarMatriz(a);
EGauss(n,a,b,x);
mostrarMatriz(a);
mostrarVector(b);
mostrarVector(x);
*/
double b[4]={0,4,4,4};

FILE *fp;
    char ch;
    fp = fopen("datos.dat","r");
    if ( fp == NULL )
    {
        puts ( "No se puede abrir el archivo");
    }

    //contador de filas
    int filas=0;
    char c;
    int maxValues = 0;
	int columnas;
    
    while((c = fgetc(fp)) != EOF)
    {
        if(c == '\n'){
            filas++;
		}
    }

    printf("numero de filas=%i\n",filas);

    //cerramos y reabrimos el archivo para resetear el puntero
    fclose(fp);
    fp = fopen("datos.dat","r");
    double m[filas][100];


    //Cargo los datos leidos en el array
    int i, j;
	for(i = 0; i < filas; i++) {
		j = 0;
		do {
        fscanf(fp, "%lf", &(m[i][j]));
        j++;
			} while((c = fgetc(fp)) != '\n');
	}

	columnas = j;
	
	printf("numero de columnas= %i\n",columnas);
    //imprimo la matriz para verificar que lo leyo correctamente
    
        for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            printf("%lf ",m[i][j]);
        }
        printf("\n");
    }
}
EGauss(n,m,b,x);

int EGauss(int n, double a[][], double b[4],double x[4])
{

float eps = 1e-3;
int i,j,k;

for(i=1; i<=n-1;i++)
{
//Para comprobar si la matriz es singular.
	if(abs(a[i][i])<eps){
	bool salida = true;
	double aux;
		for(j=i+1;j<=n;j++)
		{
		if(abs(a[i][j]>eps)){
								for( k =i;k<=n;k++)
								{
								
								aux =a[i][k];
								a[i][k]=a[j][k];
								a[j][k]=aux;
								}
						aux=b[i];
						b[i]=b[j];
						b[j]=aux;
						salida = false;
						break;
						}
		}
		if(salida==true){
								cout<<"la matriz es singular"<<endl;
								return 0;
								}
		}
//----------------------------------------------------------------
//Reduccion.
	for(j=i+1;j<=n; j++){
		double f;
		f=-a[j][i]/a[i][i];
		for(k =i;k<=n;k++)
			{
			a[j][k]=a[j][k]+(f*a[i][k]);
			}
		b[j]=b[j]+(f*b[i]);
		}
}


for(i=n;i>=1;i--){
double s=0;
	for(int j=i+1;j<=n;j++){
	s=s+a[i][j]*x[j];
}
x[i]=(b[i]-s)/a[i][i];
}
return 0;
}

//-----------------------------------------------------------------
int mostrarMatriz(double a[4][4]){

	for (int i=1;i<=3;i++)
	{	
		for (int j=1;j<=3;j++)
		{	
			cout<<a[i][j]<<" ";		
 		
		}
 	cout<<"/n"<<endl;	
	}
	
	return 0;
}
//----------------------------------------------------------------------
int mostrarVector(double b[4]){
for(int i=1;i<=3;i++){
cout<<b[i]<<endl;
}
}


