/* 
Programmer: Havish Chowhry 
Desc: Read any CSV file and print total number of rows and columns before displaying its data in a tabular form using , \t and '|'. 
  Assume that first line is the header and when displaying it, it must be followed by a blank line before displaying the data.
Date: 28/11/2023

This the CSV file 
1,"Eldon Base for stackable storage shelf, platinum",Muhammed MacIntyre,3,-213.25,38.94,35,Nunavut,Storage & Organization,0.8
2,"1.7 Cubic Foot Compact ""Cube"" Office Refrigerators",Barry French,293,457.81,208.16,68.02,Nunavut,Appliances,0.58
3,"Cardinal Slant-D® Ring Binder, Heavy Gauge Vinyl",Barry French,293,46.71,8.69,2.99,Nunavut,Binders and Binder Accessories,0.39
4,R380,Clay Rozendal,483,1198.97,195.99,3.99,Nunavut,Telephones and Communication,0.58
5,Holmes HEPA Air Purifier,Carlos Soltero,515,30.94,21.78,5.94,Nunavut,Appliances,0.5
6,G.E. Longer-Life Indoor Recessed Floodlight Bulbs,Carlos Soltero,515,4.43,6.64,4.95,Nunavut,Office Furnishings,0.37
7,"Angle-D Binders with Locking Rings, Label Holders",Carl Jackson,613,-54.04,7.3,7.72,Nunavut,Binders and Binder Accessories,0.38
8,"SAFCO Mobile Desk Side File, Wire Frame",Carl Jackson,613,127.7,42.76,6.22,Nunavut,Storage & Organization,
9,"SAFCO Commercial Wire Shelving, Black",Monica Federle,643,-695.26,138.14,35,Nunavut,Storage & Organization,
10,Xerox 198,Dorothy Badders,678,-226.36,4.98,8.33,Nunavut,Paper,0.38
*/
// this is the code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 100
#define COLUMNS 100

int main()
{
    FILE *filePointer;
    filePointer = fopen("Sample-Spreadsheet-10-rows.csv", "r");
    if (!filePointer)
    {
        printf("Error opening the file");
        return 1;
    }

    int row = 0, col = 0;
    char *mytoken;
    char fileheaders[COLUMNS][MAXLENGTH];
    char myline[MAXLENGTH];

    fgets(myline, MAXLENGTH, filePointer);
    printf("%s\n\n", myline);

    mytoken = strtok(myline, ",");
    while (mytoken != NULL && col < COLUMNS)
    {
        strcpy(fileheaders[col++], mytoken);
        mytoken = strtok(NULL, ",");
    }
	int index;
    for (index = 0; index < col; index++)
    {
        printf("%s\t|", fileheaders[index]);
    }
    printf("\n");

    while (fgets(myline, MAXLENGTH, filePointer) != NULL)
    {
        row++;
        col = 0; // Reset col for each row
        mytoken = strtok(myline, ",");
        while (mytoken != NULL && col < COLUMNS)
        {
            printf("%s\t|", mytoken);
            mytoken = strtok(NULL, ",");
            col++;
        }
        printf("\n");
    }
    printf("Total Rows: %d\nTotal Columns: %d\n", row, col);

    fclose(filePointer);
    return 0;
}
// csv file copied
1,"Eldon Base for stackable storage shelf, platinum",Muhammed MacIntyre,3,-213.25,38.94,35,Nunavut,Storage & Organization,0.8
2,"1.7 Cubic Foot Compact ""Cube"" Office Refrigerators",Barry French,293,457.81,208.16,68.02,Nunavut,Appliances,0.58
3,"Cardinal Slant-D� Ring Binder, Heavy Gauge Vinyl",Barry French,293,46.71,8.69,2.99,Nunavut,Binders and Binder Accessories,0.39
4,R380,Clay Rozendal,483,1198.97,195.99,3.99,Nunavut,Telephones and Communication,0.58
5,Holmes HEPA Air Purifier,Carlos Soltero,515,30.94,21.78,5.94,Nunavut,Appliances,0.5
6,G.E. Longer-Life Indoor Recessed Floodlight Bulbs,Carlos Soltero,515,4.43,6.64,4.95,Nunavut,Office Furnishings,0.37
7,"Angle-D Binders with Locking Rings, Label Holders",Carl Jackson,613,-54.04,7.3,7.72,Nunavut,Binders and Binder Accessories,0.38
8,"SAFCO Mobile Desk Side File, Wire Frame",Carl Jackson,613,127.7,42.76,6.22,Nunavut,Storage & Organization,
9,"SAFCO Commercial Wire Shelving, Black",Monica Federle,643,-695.26,138.14,35,Nunavut,Storage & Organization,
10,Xerox 198,Dorothy Badders,678,-226.36,4.98,8.33,Nunavut,Paper,0.38

