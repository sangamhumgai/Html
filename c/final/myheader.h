#include<conio.h>
#include<windows.h>
#include<time.h>

#define ADMIN_PASSWORD "admin"
#define ADMIN_USERNAME "admin"

struct Schedle {
	char constituency[30];
	char date[30];
};
struct VoteCount {
	char party[30];
	char name[30];
};

struct Candidate {
	char name[30];
	char party_sym[30];
	char place[30];
};
struct Voter {
	int sno;
	char name[30];
	char dob[30];
	char address[30];
	char password[30];
};

void electionSchedule();
void viewSchedule();
void addSchedule();
void candidateTask();
void viewCandidates();
void addCandidate();
void deleteCandidate();
void updateCandidate();
void voterTasks();
void castVote();
void updateVotersDetails();
void voteResult();
void registerVoters();
void seeAllVoters();
void searchVoters();
void home();