

#include "enseignant.h"

int CheckPassword() {

char input[64];
int attempts = 0;

while (attempts < 3) {

printf("Enter password : ");
GetStringInput(input, 64);

/* compare input with the password constant */
if (strcmp(input, PASSWORD) == 0) {
printf("Access granted.\n");
return 1; /* correct password */
}

attempts++;
printf("Wrong password. %d attempt(s) remaining.\n", 3 - attempts);
}

printf("Access denied.\n");
return 0; /* 3 failed attempts */
}

void TeacherMenu() {

int choice;

/* menu options array */
char *options[] = {
"Create a QCM",
"Quit teacher mode"
};

do {
DisplayMenu("Teacher Mode", options, 2);
choice = GetIntInput(1, 2);

switch (choice) {
case 1:
CreateQcm();
break;
case 2:
printf("Leaving teacher mode...\n");
break;
}

} while (choice != 2);
}


void CreateQcm() {

Qcm q;
int continuer = 1;

/* step 1 : initialize the Qcm structure */
InitQcm(&q);

/* step 2 : allocate memory for questions array */
if (AllocQcm(&q) == 0) {
printf("Error : could not allocate memory.\n");
return;
}

/* step 3 : ask for the QCM name */
printf("Enter QCM name (no spaces or special characters) : ");
GetStringInput(q.name, 64);

/* step 4 : set the QCM parameters */
SetQcmParams(&q);

/* step 5 : add questions in a loop */
while (continuer && q.nbQuestions < MAX_QUESTIONS) {

ClearScreen();
printf("--- Question %d ---\n", q.nbQuestions + 1);
AddQuestion(&q);

/* ask if the teacher wants to add another */
printf("Add another question ? (1=yes / 0=no) : ");
continuer = GetIntInput(0, 1);
}

/* step 6 : check that at least 1 question exists */
if (q.nbQuestions == 0) {
printf("Error : a QCM must have at least one question.\n");
FreeQcm(&q);
return;
}

/* step 7 : save the QCM to a file */
if (SaveQcm(&q, "qcm/") == 0) {
printf("QCM saved successfully !\n");
} else {
printf("Error : could not save the QCM.\n");
}

/* step 8 : free allocated memory */
FreeQcm(&q);
}


void SetQcmParams(Qcm *q) {

ClearScreen();
printf("--- QCM Parameters ---\n\n");

/* parameter 1 : negative points */
printf("Negative points for wrong answer ? (0=no / 1=yes) : ");
q->negativePoints = GetIntInput(0, 1);

/* parameter 2 : multiple choice */
printf("Multiple answers allowed per question ? (0=no / 1=yes) : ");
q->multipleChoice = GetIntInput(0, 1);

/* parameter 3 : sequential mode */
printf("Sequential mode (must answer before moving on) ? (0=no / 1=yes) : ");
q->sequential = GetIntInput(0, 1);

printf("\nParameters saved.\n");
}

void AddQuestion(Qcm *q) {

/* get a pointer to the next available question */
Question *quest = &q->questions[q->nbQuestions];

/* initialize the question before filling it */
InitQuestion(quest);

/* step 1 : ask for the question statement */
printf("Question statement : ");
GetStringInput(quest->statement, 512);

/* step 2 : ask for the number of propositions */
printf("Number of propositions (2 to %d) : ", MAX_CHOICES);
quest->nbAnswers = GetIntInput(2, MAX_CHOICES);

/* step 3 : fill each proposition */
for (int i = 0; i < quest->nbAnswers; i++) {

char buffer[256];

printf("Proposition %d : ", i + 1);
GetStringInput(buffer, 256);

/* allocate memory and copy the text */
if (AllocChoice(&quest->answers[i], buffer) == 0) {
printf("Error : could not allocate memory for proposition.\n");
return;
}

/* ask if this proposition is correct */
printf("Is this proposition correct ? (0=no / 1=yes) : ");
quest->answers[i].correct = GetIntInput(0, 1);
}

/* step 4 : increment the question counter */
q->nbQuestions++;

printf("Question %d added successfully.\n", q->nbQuestions);
}
