#include<stdio.h>
#include "myheader.h"
int main() {
	srand(time(NULL));
	home();
}
void home() {
	int choice;
	char continueChoice;

	do {
		system("cls");
		printf("1. Election Schedule\n");
		printf("2. Candidate\n");
		printf("3. Vote\n");
		printf("Your choice : ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				electionSchedule();
				break;
			case 2:
				candidateTask();
				break;
			case 3:
				voterTasks();
				break;
			default:
				printf("Wrong Choice\n");
		}

		printf("Do you want to continue? (y/n): ");
		scanf(" %c", &continueChoice);
	} while (continueChoice == 'y' || continueChoice == 'Y');
}

void electionSchedule() {
	system("cls");
	int choice;

	printf("1. See Schedule \n");
	printf("2. Add Schedule \n");
	printf("Your choice : ");
	scanf("%d",&choice);
	switch(choice) {
		case 1:
			viewSchedule();
			break;
		case 2:
			char username[30];
			char password[30];
			printf("\nEnter username : ");
			scanf("%s",username);
			printf("\nEnter Password : ");
			scanf("%s",password);
			if(!strcmp(username,ADMIN_USERNAME)&&!strcmp(password,ADMIN_PASSWORD)) {
				addSchedule();
			} else {
				printf("You are not a admin");
			}
			break;
		default:
			printf("Wrong Choice");
			exit(0);
	}
}
void viewSchedule() {
	system("cls");
	FILE *fp;
	char constituency[30];
	char date[30];
	fp=fopen("schedule.txt","r");
	printf("\nConstituency\tDate of Election (yymmdd)\n\n");
	while(fscanf(fp,"Constituency : %s\nDate : %s\n\n",constituency,date)!=EOF) {
		printf("%s\t\t%s\n",constituency,date);
	}
	fclose(fp);
}
void addSchedule() {
	system("cls");
	FILE *fp;
	struct Schedle s;
	char ch;
	printf("\nEnter constituency : ");
	scanf("%s",s.constituency);
	printf("\nEnter date (yyyymmdd) : ");
	scanf("%s",s.date);

	fp=fopen("schedule.txt","a");
	fprintf(fp,"Constituency : %s\n",s.constituency);
	fprintf(fp,"Date : %s\n\n",s.date);
	fclose(fp);
	printf("\nElection Scheduled Sucessfully .\n");

}
void candidateTask() {
	system("cls");
	int choice;

	printf("1. View Candidate \n");
	printf("2. Register Candidate \n");
	printf("3. Update Candidate \n");
	printf("4. Delete Candidate \n");
	printf("Your choice : ");
	scanf("%d",&choice);
	switch(choice) {
		case 1:
			viewCandidates();
			break;
		case 2:
			char username[30];
			char password[30];
			printf("\nEnter username : ");
			scanf("%s",username);
			printf("\nEnter Password : ");
			scanf("%s",password);
			if(!strcmp(username,ADMIN_USERNAME)&&!strcmp(password,ADMIN_PASSWORD)) {
				addCandidate();
			} else {
				printf("You are not a admin");
			}

			break;
		case 3:
			char admusername[30];
			char admpassword[30];
			printf("\nEnter username : ");
			scanf("%s",admusername);
			printf("\nEnter Password : ");
			scanf("%s",admpassword);
			if(!strcmp(admusername,ADMIN_USERNAME)&&!strcmp(admpassword,ADMIN_PASSWORD)) {
				updateCandidate();
			} else {
				printf("You are not a admin");
			}

			break;

		case 4:
			char username1[30];
			char password1[30];
			printf("\nEnter username : ");
			scanf("%s",username1);
			printf("\nEnter Password : ");
			scanf("%s",password1);
			if(!strcmp(username1,ADMIN_USERNAME)&&!strcmp(password1,ADMIN_PASSWORD)) {
				deleteCandidate();
			} else {
				printf("You are not a admin");
			}

			break;
		default:
			printf("Wrong Choice");
			exit(0);
	}
}
void viewCandidates() {
	system("cls");
	FILE *fp;
	char name[30];
	char party_sym[30];
	char place[30];
	fp=fopen("candidatelist.txt","r");
	printf("\nName\t\t Party\t\t From\n\n");
	while(fscanf(fp,"Name : %s\nParty : %s\nPlace : %s\n\n",name,party_sym,place)!=EOF) {
		printf("%s\t\t%s\t\t%s\n",name,party_sym,place);
	}
	fclose(fp);
}
void addCandidate() {
	system("cls");
	FILE *fp;
	struct Candidate c;
	printf("\nEnter Name of Candidate : ");
	scanf("%s",c.name);
	printf("\nEnter Political Party Symbol : ");
	scanf("%s",c.party_sym);
	printf("\nEnter Candidacy From : ");
	scanf("%s",c.place);

	fp=fopen("candidatelist.txt","a");
	fprintf(fp,"Name : %s\n",c.name);
	fprintf(fp,"Party : %s\n",c.party_sym);
	fprintf(fp,"Place : %s\n\n",c.place);
	fclose(fp);
	printf("Candidate Registered Successful.");
}
void deleteCandidate() {
	system("cls");
	char name[30];
	printf("Enter the name of the candidate you want to delete: ");
	scanf("%s", name);

	FILE *tempFile, *file;
	tempFile = fopen("temp.txt", "w");
	file = fopen("candidatelist.txt", "r");

	char currName[30], party_sym[30], place[30];
	int found = 0;

	while (fscanf(file, "Name : %s\nParty : %s\nPlace : %s\n\n", currName, party_sym, place) != EOF) {
		if (strcmp(currName, name) != 0) {
			fprintf(tempFile, "Name : %s\n", currName);
			fprintf(tempFile, "Party : %s\n", party_sym);
			fprintf(tempFile, "Place : %s\n\n", place);
		} else {
			found = 1;
		}
	}

	fclose(tempFile);
	fclose(file);

	if (found) {
		remove("candidatelist.txt");
		rename("temp.txt", "candidatelist.txt");
		printf("Candidate deleted successfully.\n");
	} else {
		printf("Candidate not found.\n");
	}
}

void updateCandidate() {
	system("cls");
	char name[30];
	printf("Enter the name of the candidate you want to update: ");
	scanf("%s", name);

	FILE *tempFile, *file;
	tempFile = fopen("temp.txt", "w");
	file = fopen("candidatelist.txt", "r");

	char currName[30], party_sym[30], place[30];
	int found = 0;

	while (fscanf(file, "Name : %s\nParty : %s\nPlace : %s\n\n", currName, party_sym, place) != EOF) {
		if (strcmp(currName, name) != 0) {
			fprintf(tempFile, "Name : %s\n", currName);
			fprintf(tempFile, "Party : %s\n", party_sym);
			fprintf(tempFile, "Place : %s\n\n", place);
		} else {
			printf("\nEnter new name: ");
			scanf("%s", currName);
			printf("Enter new party symbol: ");
			scanf("%s", party_sym);
			printf("Enter new candidacy from: ");
			scanf("%s", place);
			fprintf(tempFile, "Name : %s\n", currName);
			fprintf(tempFile, "Party : %s\n", party_sym);
			fprintf(tempFile, "Place : %s\n\n", place);
			found = 1;
		}
	}

	fclose(tempFile);
	fclose(file);

	if (found) {
		remove("candidatelist.txt");
		rename("temp.txt", "candidatelist.txt");
		printf("Candidate updated successfully.\n");
	} else {
		printf("Candidate not found.\n");
	}
}
void voterTasks() {
	system("cls");
	int choice;

	printf("1. Update Voters Details \n");
	printf("2. Cast Vote \n");
	printf("3. Voting Result \n");
	printf("4. Search Voters \n");
	printf("5. Register Voters \n");
	printf("6. See All Voters \n");
	printf("Your choice : ");
	scanf("%d",&choice);
	switch(choice) {
		case 1:
			updateVotersDetails();
			break;
		case 2:
			castVote();
			break;
		case 3:
			voteResult();
			break;
		case 4:
			searchVoters();
			break;
		case 5:
			char username[30];
			char password[30];
			printf("\nEnter username : ");
			scanf("%s",username);
			printf("\nEnter Password : ");
			scanf("%s",password);
			if(!strcmp(username,ADMIN_USERNAME)&&!strcmp(password,ADMIN_PASSWORD)) {
				registerVoters();
			} else {
				printf("You are not a admin");
			}
			break;

		case 6:
			char username2[30];
			char password2[30];
			printf("\nEnter username : ");
			scanf("%s",username2);
			printf("\nEnter Password : ");
			scanf("%s",password2);
			if(!strcmp(username2,ADMIN_USERNAME)&&!strcmp(password2,ADMIN_PASSWORD)) {
				seeAllVoters();
			} else {
				printf("You are not a admin");
			}
			break;
		default:
			printf("Wrong Choice");
			exit(0);
	}
}

void updateVotersDetails() {
    system("cls");
    FILE *fp;
    int id;
    char newName[30], newDob[30], newAddress[30], newPassword[30];
    char enteredPassword[30];
    int found = 0;

    printf("Enter the ID of the voter you want to update: ");
    scanf("%d", &id);
    printf("\nEnter the password : ");
    scanf("%s", enteredPassword);

    fp = fopen("voterlist.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(fp, "Id : %d\nName : %s\nDOB : %s\nAddress : %s\nPassword : %s\n\n", &id, newName, newDob, newAddress, newPassword) != EOF) {
        if (id == id) {
            found = 1;
            if (!strcmp(enteredPassword, newPassword)) {
                printf("\nEnter new name: ");
                scanf("%s", newName);
                printf("Enter new date of birth (yyyy/mm/dd): ");
                scanf("%s", newDob);
                printf("Enter new address: ");
                scanf("%s", newAddress);
                printf("Enter new password: ");
                scanf("%s", newPassword);

                fseek(fp, -(strlen(newName) + strlen(newDob) + strlen(newAddress) + strlen(newPassword) + 29), SEEK_CUR);
                fprintf(fp, "Name : %s\n", newName);
                fprintf(fp, "DOB : %s\n", newDob);
                fprintf(fp, "Address : %s\n", newAddress);
                fprintf(fp, "Password : %s\n\n", newPassword);
                printf("Voter details updated successfully.\n");
            } else {
                printf("Password not matched.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Voter with ID %d not found.\n", id);
    }
    fclose(fp);
}


void seeAllVoters() {
    system("cls");
    FILE *fp;
    int id;
    char name[30], dob[30], address[30], password[30];

    fp = fopen("voterlist.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nSNO\tName\t\tDOB\t\tAddress\t\tPassword\n\n");
    while (fscanf(fp, "Id : %d\nName : %[^\n]\nDOB : %[^\n]\nAddress : %[^\n]\nPassword : %[^\n]\n\n", &id, name, dob, address, password) != EOF) {
        printf("%d\t%s\t\t%s\t\t%s\t\t%s\n", id, name, dob, address, password);
    }
    fclose(fp);
}



void registerVoters() {
	system("cls");
	FILE *fp;
	struct Voter v;
	v.sno = rand() % (99999 - 999 + 1) + 999;
	printf("\nEnter Name of Voter : ");
	scanf("%s", v.name);
	printf("\nEnter Date of birth (yyyy/mm/dd) : ");
	scanf("%s", v.dob);
	printf("\nEnter Address : ");
	scanf("%s", v.address);
	printf("\nEnter Password : ");
	scanf("%s", v.password);

	fp = fopen("voterlist.txt", "a");
	if (fp == NULL) {
		printf("Error opening file.\n");
		return;
	}
	fprintf(fp, "Id : %d\n", v.sno);
	fprintf(fp, "Name : %s\n", v.name);
	fprintf(fp, "DOB : %s\n", v.dob);
	fprintf(fp, "Address : %s\n", v.address);
	fprintf(fp, "Password : %s\n\n", v.password);
	fclose(fp);
	printf("Voter Registered Successfully.\n");
}

void searchVoters() {
	system("cls");
	FILE *fp;
	int searchId;
	int id;
	char name[30], dob[30], address[30], password[30];
	int found = 0;

	printf("Enter ID to search: ");
	scanf("%d", &searchId);

	fp = fopen("voterlist.txt", "r");
	if (fp == NULL) {
		printf("Error opening file.\n");
		return;
	}

	while (fscanf(fp, "Id : %d\nName : %[^\n]\nDOB : %[^\n]\nAddress : %[^\n]\nPassword : %[^\n]\n\n", &id, name, dob, address, password) != EOF) {
		if (searchId == id) {
			printf("\nID\tName\t\tDOB\t\tAddress\t\tPassword\n\n");
			printf("%d\t%s\t\t%s\t\t%s\t\t%s\n", id, name, dob, address, password);
			found = 1;
			break;
		}
	}
	fclose(fp);

	if (!found) {
		printf("Voter with ID %d not found.\n", searchId);
	}
}

void castVote() {
	system("cls");
	VoteCount v1;
	FILE *fp, *fs;
	int id,id1,age;
	char name1[30], password1[30];
	char name[30], dob[30], address[30], password[30], party[30];
	char cdname[30], cdparty[30], cdplace[30];
	int found = 0;
	printf("Enter voter id : ");
	scanf("%d", &id1);
	printf("Enter Password : ");
	scanf("%s", password1);
	printf("Enter Your age : ");
	scanf("%d", &age);
	if(age<=18) {
		printf("You are not allowed to vote .\n");
		home();
	}

	fp = fopen("voterlist.txt", "r");
	if (fp == NULL) {
		printf("Error opening file.\n");
		return;
	}

	while (fscanf(fp, "Id : %d\nName : %[^\n]\nDOB : %[^\n]\nAddress : %[^\n]\nPassword : %[^\n]\n\n", &id, name, dob, address, password) != EOF) {
		if ((id==id1) && !strcmp(password1, password)) {
			printf("Enter candidate party symbol : ");
			scanf("%s", party);

			fs = fopen("candidatelist.txt", "r");
			if (fs == NULL) {
				printf("Error opening file.\n");
				fclose(fp);
				return;
			}

			while (fscanf(fs, "Name : %s\nParty : %s\nPlace : %[^\n]\n\n", cdname, cdparty, cdplace) != EOF) {
				if (!strcmp(party, cdparty)) {
					strcpy(v1.name, name);
					strcpy(v1.party, cdparty);
					fs = fopen("votecount.txt", "a");
					fprintf(fs, "Party : %s\nName : %s\n\n", cdparty, name);
					printf("Casted Successfully ..");
					fclose(fs);
					fclose(fp);
					return;
				}
			}

			fclose(fs);
			break;
		}
	}

	fclose(fp);
}
void voteResult() {
	system("cls");
	FILE *fp;
	char party[30], name[30];
	int count = 0;
	char prevParty[30] = "";

	fp = fopen("votecount.txt", "r");
	if (fp == NULL) {
		printf("Error opening file.\n");
		return;
	}

	while (fscanf(fp, "Party : %[^\n]\nName : %[^\n]\n\n", party, name) != EOF) {
		if (strcmp(party, prevParty) != 0) {

			if (count > 0) {
				printf("Party Symbol: %s, Vote Count: %d\n", prevParty, count);
			}
			strcpy(prevParty, party);
			count = 1;
		} else {
			count++;
		}
	}

	if (count > 0) {
		printf("Party Symbol: %s, Vote Count: %d\n", prevParty, count);
	}

	fclose(fp);
}
