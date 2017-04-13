#include "AddressVerwaltung_Address.h"


static filename = "addresses.csv";

void saveToFile() {
    FILE *fp;
    fp = fopen(filename,"w+");
 
    fprintf(fp, "Surname\tName\tStreet\tStreet Nr\tZIP\tCity");
 
for(i=0;i<m;i++){
 
    fprintf(fp,"\n%d",i+1);
 
    for(j=0;j<n;j++)
 
        fprintf(fp,",%d ",a[i][j]);
 
    }
 
    fclose(fp);
}

void readFromFile() {
    
}


