#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <Windows.h>


//Structs of restrunt
struct Stooks
{
	int itemID;
	char name[80];
	int stock_amount;
	int min_amount;
	int max_amount;
}typedef Stook;
struct MenuFood{
	int itemID;
	char item_name[81];
	float price;

}typedef Food;
struct Employee
{
	int username, id, tel,Sum_Order;
	char name[81], lastname[81], pass[81], poss[81], add[81], Parmi;
	float salary;
}typedef Emp;
struct Table
{
	int table_number, seats_amonut, availability;
	//bool availability;
}typedef Tab;
struct Ordr{
	int orderID;
	int table_number;
	char order_time[81];
	int employeeID;
	int *itemID,sizeItems;
	float total_price;
}typedef Order;
struct Delivery
{
	int cellNumber;
	int deliveryID;
	char address[81];
	char DateTime[81];
	int employeeID;
	int *itemID,sizeIItems;
	float total_price;

}typedef Delivery;

//הרשאות
Emp* Manger(Emp* employee, int size,int id);

//functions

//employee
int checkID(Emp* employee,int size,int id);
Emp* ReadEmp(int *size);
void Manu();
Emp* NewEmplo(Emp* employee, int *size);
void writeEmp(Emp* employee, int size);
Emp* DeleteEmp(Emp* employee, int *size);
char checkPass(Emp* employee, int size,int *flag,int *IDemp);
//table
Tab* ReadTable(int* size);
void writeTab(Tab* tab, int size);
Tab* AddTable(Tab* tab, int *sizeTab);
Tab* DeleteTable(Tab* table, int *sizeTab);
Tab* AvailabilityTable(Tab* table, int *sizeTab);
int checkTable(Tab* table,int size,int number);

//menu
Food* Readfood(int *size);
Food* DeleteFood(Food* food ,int * size);
Food* addFood(Food * food , int * size);
int checkFood(Food* food,int size,int id);
void writeFood(Food* food, int size);
//stook
void writeStook(Stook* stook,int size);
int checkStook(Stook* stook,int size,int id);
Stook* ReadStook(int *size);
Stook* AddStook(Stook *stook,int *size);
Stook* UpdataStook(Stook *stook,int size);
Stook* DeleteStook(Stook *stook,int* size);
Stook* printStook(Stook *stook,int size);
//Delivery
Delivery* ReadDelivery(int *size);
void FreeDate(Delivery* delivery,int size);
void PrintDeliver(Delivery* delivery,int size,Food*food,int sizefood);
int cheackNumOfDelivery(Delivery* delivery,int size,int number);
void writeDelivert(Delivery* delivery,int size);
Delivery* AddDelivery(Delivery* delivery,int *size,int sizeFood,Food *food,int idEmp);
//Order
Order* ReadOrder(int *size);
void PrintOrder(Order* order,int size,Food *food,int SizeFood);
void FreeOrderDate(Order* order,int size);
void writeOrder(Order* order,int size);
Order* AddOrder(Order* order,int *size,Tab* tables,int sizeTab,int idEmp,Food* food, int SizeFood ,int *flagTab);
Tab* abilTab(Tab* tab,int size,int number);
Order* AddItems(Order* order,int size,Tab* tables,int sizeTab,Food* food, int SizeFood);
int checkNameItems(int Code,Food *food,int sizeFood);
//function of time
char* ReturnTimeCu();
void printMalzarim(Order *order,int sizeOr,Emp *emp,int sizeEmp);
int SumOrderOfEmployee(Order* order,int sizeOr,int idEmployee);


void main(){
	
	Manu();
	system("pause");
	system("cls");

	printf("Good Bey ,See you !!\n");
	
}
void Manu(){
	
	int flag = 0, size = 0,IDemp=NULL;
	Emp* employee = NULL;
	char ch;
	employee=ReadEmp(&size);

	do{
		ch = checkPass(employee, size, &flag,&IDemp);
		switch (ch)
		{
		case 'A':
		case 'a':
			system("pause");
			system("cls");
			employee=Manger(employee,size,IDemp);
			system("pause");
			system("cls");
			break;
		case 'B':
		case 'b':
			system("pause");
			system("cls");
			//Chef(employee,size);
			system("pause");
			system("cls");
			break;
		case 'C':
		case 'c':
			system("pause");
			system("cls");
			//Malzer(employee,size);
			system("pause");
			system("cls");
			break;
		}
	} while (flag);
	free(employee);
}

Emp* Manger(Emp* employee, int size,int id){
	 int flag = 1, sizeTab = NULL,SizeFood=NULL,sizeSto=NULL,sizedel=NULL,sizeOr=NULL,i,flagTab=0;
	 char ch;
	 Tab *table = NULL;
	 Food *food=NULL;
	 Stook* stook;
	 Delivery *delivery=NULL;
	 Order * order=NULL;
	 table= ReadTable(&sizeTab);
	 food=Readfood(&SizeFood);
	 stook = ReadStook(&sizeSto);
	 delivery =ReadDelivery(&sizedel);
	 order=ReadOrder(&sizeOr);
	 do
	 {
		 printf("A) Add Employee \nB) Delete Employee \nC) Save \nD) Add Table \nE) Delete Table\n");
		 printf("F) Availability Table\nG) Delete in Menu \nH) Add To Menu \n");
		 printf("I) Add Stook \nJ) Update Stooks \nK) Delete Stook \nL) Print Stook \n");
		 printf("M) Add Delivery \nN) Print Delivery \nO) Add Order \nP) Print Order \nQ) Update Order\nR) Print Malzarim \n0)Back\n");
		 _flushall();
		 scanf("%c",&ch);
		 switch (ch)
		 {
		 case 'A':
		 case 'a':
			 system("pause");
			 system("cls"); 
			 employee = NewEmplo(employee, &size);
			 system("pause");
			 system("cls");
			 break;
		 case 'B':
		 case 'b':
			 system("pause");
			 system("cls");
			 employee = DeleteEmp(employee, &size);
			 system("pause");
			 system("cls");
			 break;
		 case 'C':
		 case 'c':
			 system("pause");
			 system("cls");
			 writeEmp(employee, size);
			 writeTab(table, sizeTab);
			 writeFood(food,SizeFood);
			 writeStook(stook,sizeSto);
			 writeDelivert(delivery,sizedel);
			 writeOrder(order,sizeOr);
			 system("pause");
			 system("cls");
			 break;
		 case 'D':
		 case 'd':
			 system("pause");
			 system("cls");
			 table=AddTable(table,&sizeTab);
			 system("pause");
			 system("cls");
			 break;
		 case 'e':
		 case 'E':
			 system("pause");
			 system("cls");
			 table=DeleteTable(table, &sizeTab);
			 system("pause");
			 system("cls");
			 break;
		 case 'F':
		 case 'f':
			 system("pause");
			 system("cls");
			 table=AvailabilityTable(table, &sizeTab);
			 system("pause");
			 system("cls");
			 break;
		 case 'G':
		 case 'g':
			 system("pause");
			 system("cls");
			 food=DeleteFood(food,&SizeFood);
			 system("pause");
			 system("cls");
			 break;
		 case 'h':
		 case 'H':
			 system("pause");
			 system("cls");
			 food=addFood(food,&SizeFood);
			 system("pause");
			 system("cls");
			 break;
		 case 'I':
		 case 'i':
			 system("pause");
			 system("cls");
			 stook=AddStook(stook, &sizeSto);
			 system("pause");
			 system("cls");
			 break;
		 case 'j':
		 case 'J':
			 system("pause");
			 system("cls");
			 stook=UpdataStook(stook,sizeSto);
			 system("pause");
			 system("cls");
			 break;
		 case 'K':
		 case 'k':
			 system("pause");
			 system("cls");
			 stook=DeleteStook(stook,&sizeSto);
			 system("pause");
			 system("cls");
			 break;
		 case 'L':
		 case 'l':
			 system("pause");
			 system("cls");
			 stook=printStook(stook,sizeSto);
			 system("pause");
			 system("cls");
			 break;
		 case 'M':
		 case 'm':
			 system("pause");
			 system("cls");
			 delivery=AddDelivery(delivery,&sizedel,SizeFood,food,id);
			 system("pause");
			 system("cls");
			 break;
		 case 'N':
		 case 'n':
			 system("pause");
			 system("cls");
			 PrintDeliver(delivery,sizedel,food,SizeFood);
			 system("pause");
			 system("cls");
			 break;
		 case 'o':
		 case 'O':
			 system("pause");
			 system("cls");
			 order=AddOrder(order,&sizeOr,table,sizeTab,id,food,SizeFood,&flagTab);
			 if(flagTab)
				 table=abilTab(table,sizeTab,order[sizeOr-1].table_number);
			 system("pause");
			 system("cls");
			 break;
		 case 'P':
		 case 'p':
			 system("pause");
			 system("cls");
			 PrintOrder(order,sizeOr,food,SizeFood);
			 system("pause");
			 system("cls");
			 break;
		 case 'q':
		 case 'Q':
			 system("pause");
			 system("cls");
			 order=AddItems(order,sizeOr,table,sizeTab,food,SizeFood);
			 system("pause");
			 system("cls");
			 break;
		 case 'R':
		 case 'r':
			 system("pause");
			 system("cls");
			 printMalzarim(order,sizeOr,employee,size);
			 system("pause");
			 system("cls");
			 break;
		 case '0':
			 flag = 0;
			 free(table);
			 free(food);
			 free(stook);
			 for(i=0;i<sizeOr;i++){
				 free(order[i].itemID);
			 }
			 free(order);
			 for(i=0;i<sizedel;i++){
				 free(delivery[i].itemID);
			 }
			 free(delivery);
			 return employee;
			 break;
		 }
	 } while (flag);
 }

Emp* ReadEmp(int *size){
	Emp *employee = NULL;
	int sizeEM,i,flag=1;
	char help[80];
	FILE *f = fopen("Staff.txt", "r");
	if (f == NULL){
		printf("Error , no cant open the File");
		exit(1);
	}
	fscanf(f, "%d\n",&sizeEM);
	*size = sizeEM;
	if (sizeEM){
		employee = (Emp*)calloc(sizeEM,sizeof(Emp));
		if (!employee){
			printf("Error Dont have Location in computer !!");
			exit(1);
		}
		for (i = 0; i < sizeEM; i++){
			fscanf(f,"%d ",&employee[i].username);
			fscanf(f,"%s ",employee[i].pass);
			fscanf(f,"%c ",&employee[i].Parmi);
			fscanf(f,"%d ",&employee[i].id);
			fscanf(f,"%s ",employee[i].name);
			fscanf(f,"%s ",employee[i].lastname);
			fscanf(f,"%s ",employee[i].poss);
			fscanf(f,"%s ",employee[i].add);
			while(flag){
				fscanf(f,"%s ",help);
				if (help[0]=='#')
					break;
				strcat(employee[i].add," ");
				strcat(employee[i].add,help);
			}
			fscanf(f,"%d ",&employee[i].tel);
			fscanf(f,"%f\n",&employee[i].salary);

		}
	}
	fclose(f);
	return employee;
}
Emp* NewEmplo(Emp* employee, int *size){
	Emp temp;
	int flag=0;
	
	printf("Please enter new User : ");
	scanf("%d",&temp.username);
	printf("\nPlease enter PassWord : ");
	scanf("%s",temp.pass);
	printf("\nPlease enter Permission : ");
	_flushall();
	scanf("%c",&temp.Parmi);

	do
	{	
		printf("\nPlease enter ID (0 To back) : ");
		_flushall();
		scanf("%d", &temp.id);
		if(temp.id==0){
			printf("Not Add Employee \n");
			return employee;
		}
		flag=checkID(employee,*size,temp.id);
		if(flag)
			printf("Sory There is an employee with an ID try Again  \n");

	} while (flag);
	
	printf("\nPlease enter your Name : ");
	_flushall();
	scanf("%s",temp.name);
	printf("\nPlease enter Lastname : ");
	_flushall();
	gets(temp.lastname);
	printf("\nPlease enter Position : ");
	_flushall();
	scanf("%s",temp.poss);
	printf("\nPlease enter Address : ");
	_flushall();
	gets(temp.add);
	printf("\nPlease enter Telephone : ");
	_flushall();
	scanf("%d", &temp.tel);
	printf("\nPlease enter Salary : ");
	_flushall();
	scanf("%f", &temp.salary);
	*size += 1;

	printf("\n");
	printf("Okey\n");

	employee = (Emp*)realloc(employee,(*size+1)*sizeof(Emp));
	if (!employee){
		printf("Error Dont have Location in computer !!");
		exit(1);
	}

	employee[*size-1]=temp;
	return employee;
}
void writeEmp(Emp* employee, int size){
	int i;
	FILE *f ;
	f= fopen("Staff.txt","w");
	if (f == NULL){
		printf("Error , no cant open the File");
		exit(1);
	}
	fprintf(f, "%d\n",size);
	for (i = 0; i < size; i++){
		fprintf(f,"%d %s %c %d %s %s %s %s # %d %0.2f\n", employee[i].username, 
			employee[i].pass, employee[i].Parmi
			, employee[i].id, employee[i].name, employee[i].lastname,
			employee[i].poss, employee[i].add, employee[i].tel, employee[i].salary);
	}
	printf("Okey\n");
	fclose(f);
}
Emp* DeleteEmp(Emp* employee, int *size){
	
	int i,flag=1,j;
	int row;
	Emp *temp=NULL;

	printf("Please enter the Row you want to Delete or Back:\n");
	for(i=0; i<*size ;i++){
		printf("%d ) name : %s %s  ID : %d\n",i+1,employee[i].name,employee[i].lastname,employee[i].id);
	}
	printf("0) Back\n",i+1);

	do
	{
		scanf("%d",&row);
		if(row==0)
			flag=0;
		else if(row<=*size){
			temp=(Emp*)malloc(sizeof(Emp)*(*size-1));
			if (!temp){
			printf("Error Dont have Location in computer !!");
			exit(1);
			}
			for(i=0,j=0;i<*size;i++){
				if(i!=row-1){
					temp[j]=employee[i];
					j++;
				}
			}
			free(employee);

			employee=(Emp*)malloc(sizeof(Emp)*(*size-1));
			if (!temp){
			printf("Error Dont have Location in computer !!");
			exit(1);
			}
			*size-=1;
			for(i=0,j=0;i<*size;i++){
				employee[i]=temp[i];
			}
			free(temp);
			flag=0;
			printf("Okey\n");
		}
		else
			printf("Sory !! Try Again\n");

	} while (flag);
	return employee;
}
char checkPass(Emp* employee, int size,int *flag,int * IDemp){
	int fla=1,id,i=0;
	char pass[81];
	do
	{
		printf("Please enter UserName (0 to Exit) : ");
		scanf("%d",&id);
		if(id==0){
			*flag=0;
			return '0';
		}
		printf("Please enter Password : ");
		scanf("%s",pass);
		for(i=0;i<size;i++){
			if (id == employee[i].username && strcmp(employee[i].pass, pass) == 0){
				*flag = 1;
				printf("Okey\n");
				*IDemp=employee[i].id;
				return employee[i].Parmi;
			}
		}
		printf("Sory !! Try Again\n");
	} while (fla);
}
int checkID(Emp* employee,int size,int id){
	int i;
	for(i=0;i<size ; i++){
		if(employee[i].id == id )
			return 1;
	}
	return 0;

}

Tab* ReadTable(int* size){

	Tab* table = NULL;
	int sizeTab, i = 0;

	FILE *f = fopen("Table.txt", "r");
	if (f == NULL){
		printf("Error , no cant open the File");
		exit(1);
	}
	fscanf(f,"%d\n", &sizeTab);
	if (sizeTab){
		table = (Tab*)malloc(sizeof(Tab)*sizeTab);
		if (!table){
			printf("Error, Dont have location in comuter !\n");
			exit(1);
		}
		for (i = 0; i < sizeTab; i++){
			fscanf(f,"%d %d %d\n", &table[i].table_number, &table[i].seats_amonut, &table[i].availability);
		}
	}

	*size = sizeTab;
	return table;

 }
void writeTab(Tab* tab, int size){

	int i;
	FILE *f;
	f = fopen("Table.txt", "w");
	if (f == NULL){
		printf("Error , no cant open the File");
		exit(1);
	}
	fprintf(f, "%d\n", size);
	for (i = 0; i < size; i++){
		fprintf(f, "%d %d %d\n", tab[i].table_number, tab[i].seats_amonut, tab[i].availability);
	}
	fclose(f);

}
Tab* AddTable(Tab* tab, int *sizeTab){
	Tab temp;
	int flag=0;
	do
	{
		printf("Please enter Number of Table (0 to back) : ");
		scanf("%d", &temp.table_number);
		if(temp.table_number ==0 ){
			printf("Not add a new Table \n");
			return tab;
		}
		flag=checkTable(tab,*sizeTab,temp.table_number);
		if(flag)
			printf("\nSory There is an table with an number try Again \n");
		
	} while (flag);
	printf("\nPlease enter Number of Seat in Table : ");
	scanf("%d", &temp.seats_amonut);
	printf("\nPlease enter availability (0 or 1) : ");
	scanf("%d", &temp.availability);
	printf("\n");

	tab = (Tab*)realloc(tab,(*sizeTab + 1)*sizeof(Tab));
	if (!tab){
		printf("Error Dont have Location in computer !!");
		exit(1);
	}
	*sizeTab += 1;
	tab[*sizeTab - 1] = temp;
	printf("Okey\n");
	return tab;
	
}
Tab* DeleteTable(Tab* table, int *sizeTab){

	int i, flag = 1, j;
	int row;
	Tab *temp = NULL;

	printf("Please enter the Row you want to Delete or Back:\n");
	for (i = 0; i<*sizeTab; i++){
		printf("%d ) Number of Table : %d \n", i + 1, table[i].table_number);
	}
	printf("0) Back\n", i + 1);
	do
	{
		scanf("%d", &row);
		if (row == 0)
			flag = 0;
		else if (row <= *sizeTab){
			temp = (Tab*)malloc(sizeof(Tab)*(*sizeTab - 1));
			if (!temp){
				printf("Error Dont have Location in computer !!");
				exit(1);
			}
			for (i = 0, j = 0; i<*sizeTab; i++){
				if (i != row - 1){
					temp[j] = table[i];
					j++;
				}
			}
			free(table);

			table = (Tab*)malloc(sizeof(Tab)*(*sizeTab - 1));
			if (!table){
				printf("Error Dont have Location in computer !!");
				exit(1);
			}
			*sizeTab -= 1;
			for (i = 0, j = 0; i<*sizeTab; i++){
				table[i] = temp[i];
			}
			free(temp);
			flag = 0;
			printf("Okey\n");
		}
		else
			printf("Sory !! Try Again\n");

	} while (flag);
	return table;

}
Tab* AvailabilityTable(Tab* table, int *sizeTab){

	int i,row,flag=1;


	printf("Please enter the Row you want to Change or Back:\n");
	for (i = 0; i<*sizeTab; i++){
		printf("%d ) Number of Table : %d  Availability Table : %d\n", i + 1, table[i].table_number,table[i].availability);
	}
	printf("0) Back\n", i + 1);
	do
	{
		scanf("%d", &row);
		if(row==0){
			flag=0;
		}
		else if(row<=*sizeTab){
			for(i=0;i<*sizeTab;i++){
				if(row-1==i){
					table[i].availability=!table[i].availability;
					flag=0;
					printf("Okey\n");
				}
			}
		}
		else
			printf("Sory !! Try Again\n");

	} while (flag);
	return table;
}
int checkTable(Tab* table,int size,int number){
	int i;
	for(i=0;i<size ; i++){
		if(table[i].table_number == number )
			return 1;
	}
	return 0;

}

Food* Readfood(int *size){
	Food* food = NULL;
	char help[81];
	int sizeFo, i = 0,flag=1;

	FILE *f = fopen("MenuFood.txt", "r");
	if (f == NULL){
		printf("Error , no cant open the File");
		exit(1);
	}
	fscanf(f,"%d\n", &sizeFo);
	if (sizeFo){
		food = (Food*)malloc(sizeof(Food)*sizeFo);
		if (!food){
			printf("Error, Dont have location in comuter !\n");
			exit(1);
		}
		for (i = 0; i < sizeFo; i++){
			fscanf(f,"%d ", &food[i].itemID);
			fscanf(f,"%s ", food[i].item_name);
			while(flag){
				fscanf(f,"%s ",help);
				if (help[0]=='#')
					break;
				strcat(food[i].item_name," ");
				strcat(food[i].item_name,help);
			}
			fscanf(f,"%f\n", &food[i].price);
		}
	}

	*size = sizeFo;
	return food;
}
Food* DeleteFood(Food* food ,int * size){
	int i, flag = 1, j;
	int row;
	Food *temp = NULL;

	printf("Please enter the Row you want to Delete or Back:\n");
	for (i = 0; i<*size; i++){
		printf("%d ) Name of Menu : %s    ID Item: %d \n", i + 1, food[i].item_name,food[i].itemID);
	}
	printf("0) Back\n", i + 1);
	do
	{
		scanf("%d", &row);
		if (row == 0)
			flag = 0;
		else if (row <= *size){
			temp = (Food*)malloc(sizeof(Food)*(*size - 1));
			if (!temp){
				printf("Error Dont have Location in computer !!");
				exit(1);
			}
			for (i = 0, j = 0; i<*size; i++){
				if (i != row - 1){
					temp[j] = food[i];
					j++;
				}
			}
			free(food);

			food = (Food*)malloc(sizeof(Food)*(*size - 1));
			if (!food){
				printf("Error Dont have Location in computer !!");
				exit(1);
			}
			*size -= 1;
			for (i = 0, j = 0; i<*size; i++){
				food[i] = temp[i];
			}
			free(temp);
			flag = 0;
			printf("Okey\n");
		}
		else
			printf("Sory !! Try Again\n");

	} while (flag);
	return food;

}
Food* addFood(Food * food, int * size){
	
	Food temp;
	int flag=0;
	do
	{
		printf("Please enter Number of ID item (0 to back) : ");
		scanf("%d", &temp.itemID);
		if(temp.itemID ==0 ){
			printf("Not add a new Food\n ");
			return food;
		}
		flag=checkFood(food,*size,temp.itemID);
		if(flag)
			printf("\nSory There is an ID with an number try Again \n");
		
	} while (flag);
	printf("\nPlease enter Name of Food : ");
	_flushall();
	gets(temp.item_name);
	printf("\nPlease enter Price of Food : ");
	scanf("%f", &temp.price);
	printf("\n");

	food = (Food*)realloc(food,(*size + 1)*sizeof(Food));
	if (!food){
		printf("Error Dont have Location in computer !!");
		exit(1);
	}
	*size += 1;
	food[*size - 1] = temp;
	printf("Okey\n");
	return food;

}
int checkFood(Food* food,int size,int id){
	
	int i;
	for(i=0;i<size ; i++){
		if(food[i].itemID == id )
			return 1;
	}
	return 0;

}
void writeFood(Food* food, int size)
{
	int i;
	FILE *f;
	f = fopen("MenuFood.txt", "w");
	if (f == NULL){
		printf("Error , no cant open the File");
		exit(1);
	}
	fprintf(f, "%d\n", size);
	for (i = 0; i < size; i++)
		fprintf(f,"%d %s # %0.2f\n",food[i].itemID,food[i].item_name,food[i].price);
	fclose(f);

}

void writeStook(Stook* stook,int size){

	int i;
	FILE *f;
	f = fopen("Stook.txt", "w");
	if (f == NULL){
		printf("Error , no cant open the File");
		exit(1);
	}
	fprintf(f, "%d\n", size);
	for (i = 0; i < size; i++)
		fprintf(f,"%d %s # %d %d %d\n",stook[i].itemID, stook[i].name, stook[i].stock_amount, stook[i].min_amount, stook[i].max_amount);
	fclose(f);


}
int checkStook(Stook* stook,int size,int id){
		
	int i;
	for(i=0;i<size ; i++){
		if(stook[i].itemID == id )
			return 1;
	}
	return 0;

}
Stook* ReadStook(int *size){
	Stook* stook = NULL;
	char help[81];
	int sizeStook, i = 0,flag=1;

	FILE *f = fopen("Stook.txt", "r");
	if (f == NULL){
		printf("Error , no cant open the File");
		exit(1);
	}
	fscanf(f,"%d\n", &sizeStook);
	if (sizeStook){
		stook = (Stook*)malloc(sizeof(Stook)*sizeStook);
		if (!stook){
			printf("Error, Dont have location in comuter !\n");
			exit(1);
		}
		for (i = 0; i < sizeStook; i++){
			fscanf(f,"%d ", &stook[i].itemID);
			fscanf(f,"%s ", stook[i].name);
			while(flag){
				fscanf(f,"%s ",help);
				if (help[0]=='#')
					break;
				strcat(stook[i].name," ");
				strcat(stook[i].name,help);
			}
			fscanf(f,"%d %d %d\n", &stook[i].stock_amount,&stook[i].min_amount,&stook[i].max_amount);
		}
	}

	*size = sizeStook;
	return stook;
}
Stook* AddStook(Stook *stook,int *size){
	
	Stook temp;
	int flag=0;
	do
	{
		printf("Please enter Number of ID item (0 to back) : ");
		scanf("%d", &temp.itemID);
		if(temp.itemID ==0 ){
			printf("Not add a new Stook\n ");
			return stook;
		}
		flag=checkStook(stook,*size,temp.itemID);
		if(flag)
			printf("\nSory There is an ID with an number try Again \n");
		
	} while (flag);
	printf("\nPlease enter Name of Stook (item) : ");
	_flushall();
	gets(temp.name);
	printf("\nPlease enter amount of Stook: ");
	scanf("%d", &temp.stock_amount);
	printf("\nPlease enter amount of Min Stook You have : ");
	scanf("%d", &temp.min_amount);
	printf("\nPlease enter amount of Max Stook You have : ");
	scanf("%d", &temp.max_amount);
	printf("\n");

	stook = (Stook*)realloc(stook,(*size + 1)*sizeof(Stook));
	if (!stook){
		printf("Error Dont have Location in computer !!");
		exit(1);
	}
	*size += 1;
	stook[*size - 1] = temp;
	printf("Okey\n");
	return stook;

}
Stook* UpdataStook(Stook *stook,int size){
	
	int i,ch,flag=1,id,temp;
	char choise;
	
	printf("Please enter the Row you want to Change or Back:\n");
	for (i = 0; i<size; i++){
		printf("%d ) Name of Stook : %s ID Item: %d \n", i + 1, stook[i].name,stook[i].itemID);
	}
	printf("0) Back\n", i + 1);
	_flushall();
	scanf("%d",&ch);
	if(ch==0){
		printf("You not change \n");
		return stook;
	}
	printf("Please enter the Row you want to Change : \n");

	printf("1) Name : %s \n",stook[ch-1].name);
	printf("2) ID : %d \n",stook[ch-1].itemID);
	printf("3) Amount : %d \n",stook[ch-1].stock_amount);
	printf("4) Min Amount : %d \n",stook[ch-1].min_amount);
	printf("5) Min Amount : %d \n",stook[ch-1].max_amount);
	_flushall();
	do
	{
		scanf("%c",&choise);
		switch (choise)
		{
		case '1':
			_flushall();
			printf("Enter name : ");
			gets(stook[ch-1].name);
			printf("\nOkey\n");
			flag=0;
			break;
		case '2':
			_flushall();
			printf("Enter Item ID : ");
			scanf("%d",&id);
			temp=checkStook(stook,size,id);
			if(temp)
				printf("Sory Not Change,Becouse have ID alredy \n");
			else{
				stook[ch-1].itemID=id;
				printf("\nOkey\n");
			}
			flag=0;
			break;
		case '3':
			_flushall();
			printf("Enter Amount : ");
			scanf("%d",&stook[ch-1].stock_amount);
			printf("\nOkey\n");
			flag=0;
			break;
		case '4':
			_flushall();
			printf("Enter Min Amount : ");
			scanf("%d",&stook[ch-1].min_amount);
			printf("\nOkey\n");
			flag=0;
			break;
		case '5':
			_flushall();
			printf("Enter Max Amount : ");
			scanf("%d",&stook[ch-1].max_amount);
			printf("\nOkey\n");
			flag=0;
			break;
		default:
			printf("Try Again!!\n");
			break;
		}

	} while (flag);
	
	return stook;

}
Stook* DeleteStook(Stook *stook,int* size){
	
	int i, flag = 1, j;
	int row;
	Stook *temp = NULL;

	printf("Please enter the Row you want to Delete or Back:\n");
	for (i = 0; i<*size; i++){
		printf("%d ) Name of Stook : %s   ID Item: %d \n", i + 1, stook[i].name,stook[i].itemID);
	}
	printf("0) Back\n", i + 1);
	do
	{
		scanf("%d", &row);
		if (row == 0)
			flag = 0;
		else if (row <= *size){
			temp = (Stook*)malloc(sizeof(Stook)*(*size - 1));
			if (!temp){
				printf("Error Dont have Location in computer !!");
				exit(1);
			}
			for (i = 0, j = 0; i<*size; i++){
				if (i != row - 1){
					temp[j] = stook[i];
					j++;
				}
			}
			free(stook);

			stook = (Stook*)malloc(sizeof(Stook)*(*size - 1));
			if (!stook){
				printf("Error Dont have Location in computer !!");
				exit(1);
			}
			*size -= 1;
			for (i = 0, j = 0; i<*size; i++){
				stook[i] = temp[i];
			}
			free(temp);
			flag = 0;
			printf("Okey\n");
		}
		else
			printf("Sory !! Try Again\n");

	} while (flag);
	return stook;

}
Stook* printStook(Stook *stook,int size){
	int i,j;
	Stook temp;

	for (i=size-1 ; i>0 ; i--){
		for(j=0;j<i;j++){
			if(stook[j].stock_amount >stook[j+1].stock_amount ){
				temp=stook[j];
				stook[j]=stook[j+1];
				stook[j+1]=temp;
			}
		}
	}
	for(i=0;i<size;i++){
		printf("%d) Name : %s\nItem-ID : %d\nStook Amount : %d\nStook Max : %d\nStook Mix : %d\n\n",i+1,stook[i].name,stook[i].itemID,stook[i].stock_amount,stook[i].max_amount,stook[i].min_amount);
	}
	return stook;
}

char* ReturnTimeCu(){
	time_t current_time;
	char *c_time_string;
 
    
    current_time = time(NULL);
 
    if (current_time == ((time_t)-1))
    {
        fprintf(stderr, "Failure to compute the current time.");
    }
 
    c_time_string = ctime(&current_time);
 
    if (c_time_string == NULL)
    {
        fprintf(stderr, "Failure to convert the current time.");
    }
	
	return c_time_string;
}
Order* ReadOrder(int *size){
	Order* order = NULL;
	char help[81],ch=NULL;
	int j,sizeorder, i = 0,flag=1,startFile,FindFile;

	FILE *f = fopen("Order.txt", "r");
	if (f == NULL){
		printf("Error , no cant open the File");
		exit(1);
	}
	fscanf(f,"%d\n", &sizeorder);
	if (sizeorder){
		order = (Order*)calloc(sizeorder,sizeof(Order));
		if (!order){
			printf("Error, Dont have location in comuter !\n");
			exit(1);
		}
		for (i = 0; i < sizeorder; i++){
			fscanf(f,"%d ", &order[i].orderID);
			fscanf(f,"%d ", &order[i].table_number);
			fscanf(f,"%s ",order[i].order_time);
			while(flag){
				fscanf(f,"%s ",help);
				if (help[0]=='#')
					break;
				strcat(order[i].order_time," ");
				strcat(order[i].order_time,help);
			}
			
			fscanf(f,"%d ",&order[i].employeeID);
			fscanf(f,"%d ",&order[i].sizeItems);
			order[i].itemID=(int*)malloc(sizeof(int)*order[i].sizeItems);
			if(!order[i].itemID)
			{
				printf("Dont have Mamory");
				exit(1);
			}
			for(j=0;j<order[i].sizeItems;j++){
				fscanf(f,"%d ",&order[i].itemID[j]);
			}
			fscanf(f,"%f\n",&order[i].total_price);
		}
	}
	fclose(f);
	*size = sizeorder;
	return order;
}
void PrintOrder(Order* order,int size,Food *food,int sizeFood){
	int i,j,code,flag=0,flag1=1,index=0;

	if(size!=0){
		printf("Please Enter A number Code Order (0 to back) : ");
		do
		{
			scanf("%d",&code);
			if(code==0)
				break;
			for(i=0; i<size ; i++){
				if(order[i].orderID==code){
					flag=1;
					break;
				}
			}
			if(flag){
				printf("Number of Order : %d\n",order[i].orderID);
				printf("Number of Table : %d\n",order[i].table_number);
				printf("Time : %s \n",order[i].order_time);
				printf("ID Employee : %d\n",order[i].employeeID);
				printf("Order is : \n");
				for(j=0;j<order[i].sizeItems ; j++){
					index=checkNameItems(order[i].itemID[j],food,sizeFood);
					printf("%d) Name : %s\t Price : %0.2f\n",j+1,food[index].item_name,food[index].price);
				}
				printf("\nSum of Items : %d\n",order[i].sizeItems);
				printf("Total Price : %0.2f \n",order[i].total_price);
				flag1=0;
			}
			else
			{
				printf("Code is Not courret !\n");
			}
		
		} while (flag1);
	}
	else
		printf("Dont have Order in Hstory \n");
	

}
void writeOrder(Order* order,int size){
	int i,j;
	FILE *f;
	f = fopen("Order.txt", "w");
	if (f == NULL){
		printf("Error , no cant open the File");
		exit(1);
	}
	fprintf(f,"%d\n", size);
	for (i = 0; i < size; i++){
		fprintf(f,"%d %d %s # %d ",order[i].orderID,order[i].table_number,order[i].order_time,order[i].employeeID);
		fprintf(f,"%d ",order[i].sizeItems);
		for(j=0;j<order[i].sizeItems;j++)
			fprintf(f,"%d ",order[i].itemID[j]);
		fprintf(f,"%0.2f\n",order[i].total_price);
	}	
	fclose(f);
}
Order* AddOrder(Order* order,int *size,Tab* tables,int sizeTab,int idEmp,Food* food, int SizeFood ,int *flagTab){

	int flag=1,i,flag1=1,count=0,si,checkT=0;
	int ch,ch1;
	char *data;

	for(i=0;i<sizeTab;i++)
	{
		if(tables[i].availability==0)
		{
			checkT++;
		}
	}
	if(checkT){
		order=(Order*)realloc(order,sizeof(Order)*(*size+1));
		if(!order){
			printf("Dont have mamory");
			exit(1);
		}
		*size+=1;
		order[*size-1].total_price=0;
		order[*size-1].orderID=*size;
		data=ReturnTimeCu();
		si=strlen(data);
		data[si-1]='\0';
		strcpy(order[*size-1].order_time,data);
		order[*size-1].employeeID=idEmp;
		printf("Which table:\n\n");
		order[*size-1].itemID=NULL;
	
		for(i=0;i<sizeTab ; i++){
			if(tables[i].availability!=1)
				printf("%d) Number Of Table : %d\tAvailability : %d\n",i+1,tables[i].table_number,tables[i].availability);
		}

		do
		{
			scanf("%d",&ch);
			if(ch>0 && ch<=sizeTab)
			{
				order[*size-1].table_number=tables[ch-1].table_number;
				printf("What they want to order (0 to stop) :\n\n");
				for(i=0;i<SizeFood ; i++)
				{
					printf("%d) Name : %s   IdCode : %d\n",i+1,food[i].item_name,food[i].itemID);
				}
				do
				{
					scanf("%d",&ch1);
					if(ch1==0)
					{
						order[*size-1].sizeItems=count;
						flag=0;
						flag1=0;
					}
					else if(ch1>0 && ch1<=SizeFood)
					{
						count++;
						order[*size-1].itemID=(int*)realloc(order[*size-1].itemID,sizeof(int)*(count));
						if(!order[*size-1].itemID){
							printf("Dont have mamory");
							exit(1);
						}
						order[*size-1].itemID[count-1]=food[ch1-1].itemID;
						order[*size-1].total_price+=food[ch1-1].price;
					}
					else
						printf("Try Again!!\n");
				} while (flag1);
			}
			else
				printf("Try Again !!\n");
		} while (flag);
		printf("Number of Order is  : %d \n",order[*size-1].orderID);
		*flagTab=1;
	}
	else{
		printf("There is no free tables\n");
		*flagTab=0;
	}

	
	return order;
}
Tab* abilTab(Tab* tab,int size,int number){
	int i=0;
	for(i=0;i<size;i++){
		if(tab[i].table_number==number){
			tab[i].availability=!tab[i].availability;
		}
	}
	return tab;
}
Order* AddItems(Order* order,int size,Tab* tables,int sizeTab,Food* food, int SizeFood){
	
	int i, numOrder,flag=1,TrueNum=0,flag1=1,ch1,index,count;

	printf("Please Enter Number of Order : ");
	do
	{
		scanf("%d",&numOrder);
		for(i=0;i<size;i++){
			if(order[i].orderID==numOrder){
				TrueNum=1;
				index=i;
				break;
			}
		}
		count=order[index].sizeItems;
		if(TrueNum){
			printf("What they want to order (0 to stop) :\n\n");
			for(i=0;i<SizeFood ; i++)
			{
				printf("%d) Name : %s   IdCode : %d\n",i+1,food[i].item_name,food[i].itemID);
			}
			do
			{
				scanf("%d",&ch1);
				if(ch1==0)
				{
					order[index].sizeItems=count;
					flag=0;
					flag1=0;
				}
				else if(ch1>0 && ch1<=SizeFood)
				{
					count++;
					order[index].itemID=(int*)realloc(order[index].itemID,sizeof(int)*(count));
					if(!order[index].itemID){
						printf("Dont have mamory");
						exit(1);
					}
					order[index].itemID[count-1]=food[ch1-1].itemID;
					order[index].total_price+=food[ch1-1].price;
				}
				else
					printf("Try Again!!\n");
			} while (flag1);
			flag=0;
		}
		else{
			printf("Try Again !!\n");
		}
		
	} while (flag);
	
	return order;
}
int checkNameItems(int Code,Food *food,int sizeFood){
	int i=0;

	for (i=0;i<sizeFood;i++){
		if(Code==food[i].itemID)
			return i;
	}
}

Delivery* ReadDelivery(int *size){

	Delivery* delivery = NULL;
	char help[81],ch=NULL;
	int j,sizedelivery, i = 0,flag=1,startFile,FindFile;

	FILE *f = fopen("Delivery.txt", "r");
	if (f == NULL){
		printf("Error , no cant open the File");
		exit(1);
	}
	fscanf(f,"%d\n", &sizedelivery);
	
	if (sizedelivery){
		delivery = (Delivery*)calloc(sizedelivery,sizeof(Delivery));
		if (!delivery){
			printf("Error, Dont have location in comuter !\n");
			exit(1);
		}
		for (i = 0; i < sizedelivery; i++){
			fscanf(f,"%d ", &delivery[i].deliveryID);
			fscanf(f,"%s ", delivery[i].address);
			while(flag){
				fscanf(f,"%s ",help);
				if (help[0]=='#')
					break;
				strcat(delivery[i].address," ");
				strcat(delivery[i].address,help);
			}


			fscanf(f,"%s ",delivery[i].DateTime);
			while(flag){
				fscanf(f,"%s ",help);
				if (help[0]=='#')
					break;
				strcat(delivery[i].DateTime," ");
				strcat(delivery[i].DateTime,help);
			}
			
			fscanf(f,"%d ",&delivery[i].employeeID);
			fscanf(f,"%d ",&delivery[i].cellNumber);
			fscanf(f,"%d ",&delivery[i].sizeIItems);
			delivery[i].itemID=(int*)malloc(sizeof(int)*delivery[i].sizeIItems);
			if(!delivery[i].itemID)
			{
				printf("Dont have Mamory");
				exit(1);
			}
			for(j=0;j<delivery[i].sizeIItems;j++){
				fscanf(f,"%d ",&delivery[i].itemID[j]);
			}
			fscanf(f,"%f\n",&delivery[i].total_price);
		}
	}
	fclose(f);
	*size = sizedelivery;

	return delivery;
}
void PrintDeliver(Delivery* delivery,int size,Food*food,int sizefood){
	int i,j,code,flag=0,flag1=1,index=0;

	if(size!=0){
		printf("Please Enter A number Code Order (0 to back) : ");
		do
		{
			scanf("%d",&code);
			if(code==0)
				break;
			for(i=0; i<size ; i++){
				if(delivery[i].deliveryID==code){
					flag=1;
					break;
				}
			}
			if(flag){
				printf("Number of Order : %d\n",delivery[i].deliveryID);
				printf("Addres : %s\n",delivery[i].address);
				printf("Cell Number : %d\n",delivery[i].cellNumber);
				printf("Time : %s \n",delivery[i].DateTime);
				printf("ID Employee : %d\n",delivery[i].employeeID);
				printf("Order is : \n");
				for(j=0;j<delivery[i].sizeIItems ; j++){
					index=checkNameItems(delivery[i].itemID[j],food,sizefood);
					printf("%d) Name : %s\t Price : %0.2f\n",j+1,food[index].item_name,food[index].price);
				}
				printf("\nSum of Items : %d\n",delivery[i].sizeIItems);
				printf("Total Price : %0.2f \n",delivery[i].total_price);
				flag1=0;
			}
			else
			{
				printf("Code is Not courret !\n");
			}
		
		} while (flag1);
	}
	else
		printf("Dont have Delivery in Hstory \n");
}
int cheackNumOfDelivery(Delivery* delivery,int size,int number){

	int i;

	for(i=0; i<size ; i++){
		if(number==delivery[i].deliveryID)
			return i;
	}
	return -1;
}
void writeDelivert(Delivery* delivery,int size){
	int i,j;
	FILE *f;
	f = fopen("Delivery.txt", "w");
	if (f == NULL){
		printf("Error , no cant open the File");
		exit(1);
	}
	fprintf(f, "%d\n", size);
	for (i = 0; i < size; i++){
		fprintf(f,"%d %s # %s # %d ",delivery[i].deliveryID,delivery[i].address,delivery[i].DateTime,delivery[i].employeeID);
		fprintf(f,"%d ",delivery[i].cellNumber);
		fprintf(f,"%d ",delivery[i].sizeIItems);
		for(j=0;j<delivery[i].sizeIItems;j++)
			fprintf(f,"%d ",delivery[i].itemID[j]);
		fprintf(f,"%f\n",delivery[i].total_price);
	}	
	fclose(f);

}
Delivery* AddDelivery(Delivery* delivery,int *size,int sizeFood,Food *food,int idEmp){
	int i,si,ch1,flag=1,flag1=1,count=0;
	char *data;

	delivery=(Delivery*)realloc(delivery,(*size+1)*sizeof(Delivery));
	if(!delivery){
		printf("Dont have mamory \n");
		exit(1);
	}

	*size+=1;
	delivery[*size-1].deliveryID=*size;
	delivery[*size-1].employeeID=idEmp;
	delivery[*size-1].total_price=0;
	data=ReturnTimeCu();
	si=strlen(data);
	data[si-1]='\0';
	strcpy(delivery[*size-1].DateTime,data);
	printf("Please enter Address : ");
	_flushall();
	gets(delivery[*size-1].address);
	printf("Please enter Cell Number : ");
	scanf("%d",&delivery[*size-1].cellNumber);
	delivery[*size-1].itemID=NULL;
	do
	{
		printf("\nWhat they want to order (0 to stop) :\n\n");
		for(i=0;i<sizeFood ; i++)
		{
			printf("%d) Name : %s   IdCode : %d\n",i+1,food[i].item_name,food[i].itemID);
		}
		do
		{
			scanf("%d",&ch1);
			if(ch1==0)
			{
				delivery[*size-1].sizeIItems=count;
				flag=0;
				flag1=0;
			}
			else if(ch1>0 && ch1<=sizeFood)
			{
				count++;
				delivery[*size-1].itemID=(int*)realloc(delivery[*size-1].itemID,sizeof(int)*(count));
				if(!delivery[*size-1].itemID){
					printf("Dont have mamory");
					exit(1);
				}
				delivery[*size-1].itemID[count-1]=food[ch1-1].itemID;
				delivery[*size-1].total_price+=food[ch1-1].price;
			}
			else
				printf("Try Again!!\n");
		
		} while (flag1);
	

	} while (flag);
	
	printf("The number Delivery is : %d\n",delivery[*size-1].deliveryID);
	return delivery;
}
void printMalzarim(Order *order,int sizeOr,Emp *emp,int sizeEmp){
	
	int i,j;
	Emp temp;

	for(i=0;i<sizeEmp ; i++){
		if(emp[i].Parmi=='C'){
			emp[i].Sum_Order=SumOrderOfEmployee(order,sizeOr,emp[i].id);
		}
		else
			emp[i].Sum_Order=-1;
	}

	for (i=sizeEmp-1 ; i>0 ; i--){
		for(j=0;j<i;j++){
			if(emp[j].Sum_Order <emp[j+1].Sum_Order ){
				temp=emp[j];
				emp[j]=emp[j+1];
				emp[j+1]=temp;
			}
		}
	}
	for(i=0;i<sizeEmp ; i++){
		if(emp[i].Sum_Order!=-1){
			printf("Name : %s\tID : %d\tSum Order : %d\n",emp[i].name,emp[i].id,emp[i].Sum_Order);
		}
	}

}
int SumOrderOfEmployee(Order* order,int sizeOr,int idEmployee){

	int i,sum=0;

	for(i=0;i<sizeOr;i++){
		if(order[i].employeeID==idEmployee)
			sum++;
	}
	return sum;
}