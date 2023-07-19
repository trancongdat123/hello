//Viet chuong trinh cho phep nhan vien nhap vao thong tin san pham cua n mat hang trong cua hang quan ao:
//Thong tin bao gom:
//Ten mat hang: khong qua 16 ky tu
//Ma mat hang: Cho phep chon tu 1 den 4 de chon ma cho tung mat hang(001->005)
//Kich co san pham: Cho phep chon tu 1 den 5 de chon kich co cho tung mat hang(L->XXL)
//So luong san pham: So nguyen
//Gia thanh: So thuc duong
//Tinh tong so tien khach phai thanh toan
//In toan bo thong tin ra man hinh
//Hoi nguoi dung co muon thu lai khong(y = co, n = khong)
#include <stdio.h>
#include <string.h>
typedef struct{
	char name[17];
	char itemcode[5];
	char size[6];
	int quantity;
	float price;
}clothes;
char *option(int i){
	switch(i){
		case(1): return"001";
		case(2): return"002";
		case(3): return"003";
		case(4): return"004";
		case(5): return"005";
		
	}
}
char *get_size(int b){
	switch(b){
		case(1): return"S";
		case(2): return"M";
		case(3): return"L";
		case(4): return"XL";
		case(5): return"XXL";
	}
}
void input(clothes s[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("Nhap ten san pham:");
		fflush(stdin);
		gets(s[i].name);
		while(strlen(s[i].name) > 16){
			printf("Nhap qua so ky tu!Nhap lai:");
			fflush(stdin);
			gets(s[i].name);
		}
		int c;
		printf("\tHay chon ma san pham:\n");
		printf("Nhan 1 de chon ma 001\nNhan 2 de chon ma 002\nNhan 3 de chon ma 003\nNhan 4 de chon ma 004\nNhan 5 de chon ma 005\n");
		printf("Chon ma:");
		scanf("%d",&c);
		while(c!=1&&c!=2&&c!=3&&c!=4&&c!=5){
			printf("Nhap sai! Nhap lai:");
			scanf("%d",&c);
		}
		strcpy(s[i].itemcode,option(c));
		int a;
		printf("\tHay chon size cho san pham:\n");
		printf("Nhan 1 de chon size S\nNhan 2 de chon size M\nNhan 3 de chon size L\nNhan 4 de chon size XL\nNhan 5 de chon size XXL\n");
		printf("Chon size:");
		scanf("%d",&a);
		while(a!=1&&a!=2&&a!=3&&a!=4&&a!=5){
			printf("Nhap sai!Nhap lai:");
			scanf("%d",&a);
		}
		strcpy(s[i].size,get_size(a));
		printf("Nhap so luong:");
		scanf("%d",&s[i].quantity);
		printf("Nhap vao gia:");
		scanf("%f",&s[i].price);
		while(s[i].price <= 0){
			printf("Nhap sai!Nhap lai:");
			scanf("%f",&s[i].price);
		}
	}
}
void sort_ten(clothes s[],int n){
	int i;
	for (i=0;i<n-1;i++){
		for(i=0;i<n-1-i;i++){
			if(s[i].name,s[i+1].name > 0){
				clothes t = s[i];
				s[i] = s[i+1];
				s[i+1] = t;
			}
		}
	}
}
void display(clothes s[],int n){
	printf("|%3s|%13s|%3s|%7s|%8s|%9s|%9s|\n","STT","Ten san pham","Ma","Kich co","So luong","Gia tien","Tong Tien");
	int i;
	for(i=0;i<n;i++){
		printf("|%d|%14s|%5s|%6s|%7d|%5.2f|%5.2f\n",i+1,s[i].name,s[i].itemcode,s[i].size,s[i].quantity,s[i].price,s[i].price*s[i].quantity);
	}
}
int main(){
	char c;
	do{
	int n;
	printf("Nhap so luong mat hang:");
	scanf("%d",&n);
	clothes s[1000];
	input(s,n);
	sort_ten(s,n);
	display(s,n);
printf("Ban co muon thu lai khong(y/n)?");
fflush(stdin);
scanf("%c",&c);
}while(c == 'y');
}
