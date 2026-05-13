

#include "qcm.h"

/

void InitQcm(Qcm *q) {

q->name[0] = '\0'; /* empty string */
q->questions = NULL; /* pointer set to NULL before malloc */
q->nbQuestions = 0; /* no questions yet */
q->negativePoints = 0; /* no penalty by default */
q->multipleChoice = 0; /* single answer by default */
q->sequential = 0; /* can skip questions by default */
}


int AllocQcm(Qcm *q) {

q->questions = malloc(MAX_QUESTIONS * sizeof(Question));

if (q->questions == NULL) {
printf("Error : memory allocation failed for questions\n");
return 0; /* malloc failed */
}

return 1; /* malloc succeeded */
}


void InitQuestion(Question *q) {

q->statement[0] = '\0'; /* empty string */
q->nbAnswers = 0; /* no answers yet */

/* initialize each Choice in the answers array */
for (int i = 0; i < MAX_CHOICES; i++) {
q->answers[i].proposition = NULL; /* pointer set to NULL before malloc */
q->answers[i].correct = 0; /* wrong answer by default */
}
}



int AllocChoice(Choice *c, char *text) {

c->proposition = malloc(strlen(text) + 1); /* +1 for the \0 */

if (c->proposition == NULL) {
printf("Error : memory allocation failed for proposition\n");
return 0; /* malloc failed */
}

strcpy(c->proposition, text); /* copy the text into allocated memory */
return 1; /* malloc succeeded */


void FreeQuestion(Question *q) {

for (int i = 0; i < MAX_CHOICES; i++) {
if (q->answers[i].proposition != NULL) {
free(q->answers[i].proposition); 
q->answers[i].proposition = NULL; /
}
}
}



void FreeQcm(Qcm *q) {

if (q->questions != NULL) {


for (int i = 0; i < q->nbQuestions; i++) {
FreeQuestion(&q->questions[i]);
}

free(q->questions); 
q->questions = NULL; 
}