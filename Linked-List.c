#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
//Başa ekleme
struct node *addhead(struct node *head, int key){

	struct node *temp= (struct node*)malloc(sizeof(struct node));
	temp->data = key;
	temp->next = head;
	head=temp;
	return head;
}

//Sona ekleme

struct node *addlast(struct node *head, int key){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data = key;
	temp->next = NULL;
	struct node *last=head;
	while(last -> next != NULL)
		last=last->next;
	last->next=temp;
	return head;
}



//Liste elemanlarının bilgileri

void listinfo(struct node* head){
	int i;
	i=1;
	while(head != NULL){
		printf("%d. Dugumunun adresi = %p \n",i,head);
		printf("%d. Dugumunun verisi =  %d \n",i,head->data);
		printf("%d. Dugumunun bagli oldugu dugumun adresi = %p\n\n");
		head=head->next;
		i++;
	}
}
//Yazdır
void print(struct node *head){

	if(head==NULL){

		printf("Liste bos ! ");

		return;

	}
	struct node * temp2=head;
	while(temp2!=NULL){
	printf("%d\n",temp2->data);
	temp2=temp2->next;
	}

	/*
	 * //recursive//
	 *void print_recursive(struct node *head){
	 *	if(head==NULL)
	 *		return;
	 *	print_recursive (head->next);
	 *	printf("%d\t",head->data);
	 *	}
	 * */
}

//Say

int count(struct node *head){
	int counter = 0;
	while(head!=NULL){
		counter++;
		head=head->next;
	}
	return counter;
}
// Arama yapma
struct node* locate(struct node* head, int key){
	struct node* locate = NULL;

	while(head != NULL){
		if(head->data!=key)
			head=head->next;
		else{
			locate=head;
			break;
		}
	}
	return(locate);
}
// Dugumu silme
struct node *del(struct node *head, int key){
	if(head==NULL)
		printf("Liste bos !");
	struct node *temp=head;

	if(head->data==key){
		head=head->next;
		free(temp);
	}
	else if(temp -> next == NULL){

		printf("Veri bulunamadi !\n\n");
		return head;
	}
	else{

		while(temp->next->data!=key){
			if(temp->next->next == NULL){
				printf("Veri bulunamadi !\n\n");
				return head;
			}

		  temp=temp->next;
		}

	 struct node *temp2=temp->next;

	 temp->next=temp->next->next;

	 free(temp2);

	}
	
	return head;

}
//Listeyi Sil
struct node *destroy(struct node *head){
	if(head==NULL)
		printf("Liste zaten bos ! ");
	struct node *temp2;

	while(head!=NULL){
		temp2=head;
		head=head->next;
		free(temp2);
	}
	return head;
}
void print_reverse(struct node *head){
	struct node *head2=NULL;
	struct node *temp=head;

	while(temp!=NULL){
		head2=addhead(head2,temp->data);
		temp=temp->next;
	}
	print(head2);
}

int main(){
	int secim,data;
	struct node *head=NULL;
	while(1){
		printf("1-Listenin başına ekle\n");
		printf("2-Listenin sonuna ekleme\n");
		printf("3-Listeyi Goruntuleme\n");
		printf("4-Listeden verilen bir degere sahip dugumu silmek\n");
		printf("5-Listeyi sil\n");
		printf("6-Listedeki eleman sayisi\n");
		printf("7-Listenin tum eleman bilgileri\n");
		printf("8-Programdan cik\n");
		scanf("%d",&secim);

		switch(secim){

			case 1:

				printf("Eklemek istediginiz degeri girin:");
				scanf("%d",&data);
				head=addhead(head,data);
				break;

			case 2:

				printf("Eklemek istediginiz degeri girin: ");
				scanf("%d",&data);
				head=addlast(head,data);
				break;

			case 3:

				print(head);
				break;
			case 4:

				printf("Silmek istediginiz degerini giriniz: ");
				scanf("%d",&data);
				head=del(head,data);
				break;

			case 5:

				head=destroy(head);
				break;
			case 6:

				printf("Listede %d eleman vardir\n",count(head));
				break;

			case 7:
				listinfo(head);
				break;
			case 8:
				exit(1);
				break;
			default: printf("Yanlis secim\n");
		}
	}
}