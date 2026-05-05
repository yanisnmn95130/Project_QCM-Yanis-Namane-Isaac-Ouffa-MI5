
#include "qcm.h"

void InitQcm(Qcm *q) {

    q->name[0]      = '\0'; 
    q->questions    = NULL; 
    q->nbQuestions  = 0;    
    q->negativePoints = 0;  
    q->multipleChoice = 0;  
    q->sequential     = 0;  
}

int AllocQcm(Qcm *q) {

    q->questions = malloc(MAX_QUESTIONS * sizeof(Question));

    if (q->questions == NULL) {
        printf("Error : allocation error \n");
        return 0;
    }

    return 1;
}

void InitQuestion(Question *q) {

    q->statement[0] = '\0';
    q->nbAnswers    = 0;  

    for (int i = 0; i < MAX_CHOICES; i++) {
        q->answers[i].proposition = NULL; 
        q->answers[i].correct     = 0;  
    }
}

int AllocChoice(Choice *c, char *text) {

    c->proposition = malloc(strlen(text) + 1);

    if (c->proposition == NULL) {
        printf("Error : memory allocation failed for proposition\n");
        return 0; 
    }

    strcpy(c->proposition, text); 
    return 1;
}


void FreeQuestion(Question *q) {

    for (int i = 0; i < MAX_CHOICES; i++) {
        if (q->answers[i].proposition != NULL) {
            free(q->answers[i].proposition);   
            q->answers[i].proposition = NULL;  
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
}
