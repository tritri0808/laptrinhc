#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct items{
	char item[20];
	int qty;
	float price;
};
struct orders{
	char customer[50];
	char date[50];
	int numOfItems;
	struct items itm[50];
};

//generate bill
void generateBillHeader(char name[50], char date[50]){
	printf("\n\n");
		printf("\t ADV Restaurant");
		printf("\n\t ------------");
		printf("\nDate:%s",date);
		printf("\nInvoice To:%s",name);
		printf("\n");
		printf("--------------------------\n");
		printf("Item\t\t");
		printf("Qty\t\t");
		printf("Total\t\t");
		printf("\n--------------------------");
		printf("\n\n");
}
void generateBillBody(char item[30],int qty, float price){
	printf("%s\t\t",item);
		printf("%d\t\t",qty);
		printf("%.2f\t\t",qty*price);
		printf("\n");
}

void generateBillFooter(float total){
	printf("\n");
	float dis=0.1*total;
	float netTotal=total-dis;
	float cgst=0.09*netTotal, grandTotal=netTotal+2*cgst;
	printf("-----------------------------------\n");
	printf("Sub total\t\t\t%.2f",total);
	printf("\nDiscout @10%s\t\t\t%.2f","%",dis);
	printf("\n\t\t\t\t----");
	printf("\nNet Total\t\t\t%.2f",netTotal);
	printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
	printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
	printf("\n-------------------------------");
	printf("\nGrand total\t\t\t%.2f",grandTotal);
	printf("\n-------------------------------\n");
}

int main(){
	float total;
	int opt,n;
	struct orders ord;
	//dashboard
	printf("\t==============ADV Restaurant==========");
	printf("\n\nPlease select your prefered operation:");
	printf("\n1.Generate Invoice");
	printf("\n2.Show all Invoice");
	printf("\n3.Search Invoice");
	printf("\n4.Exit");

	printf("\nYou choice:\t");
	scanf("%d",&opt);
	fgetc(stdin);
	switch (opt)
	{
	case 1:
		printf("\nPlease enter the name of customer:");
		fgets(ord.customer,50,stdin);
		ord.customer[strlen(ord.customer)-1]=0;
		strcpy(ord.date,__DATE__);
		printf("\nPlease enter number item:");
		scanf("%d",&n);
		ord.numOfItems=n;
		for(int i=0;i<n;i++)
		{
			fgetc(stdin);
			printf("\n\n");
			printf("Please enter item %d:\t",i+1);
			fgets(ord.itm[i].item,20,stdin);
			ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
			printf("Please enter qty: ");
			scanf("%d",&ord.itm[i].qty);
			printf("Please enter unit price: ");
			scanf("%f",&ord.itm[i].price);
			total += ord.itm[i].qty*ord.itm[i].price;
		}

		generateBillHeader(ord.customer,ord.date);
		for (int i = 0; i < ord.numOfItems; i++)
		{
			generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
		}
		generateBillFooter(total);
		
		printf("\nDo you want to save the invoice?");
	
	}

	printf("\n\n");
	return 0;
}