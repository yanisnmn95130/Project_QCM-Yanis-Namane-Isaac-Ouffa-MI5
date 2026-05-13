#ifndef QCM_H
#define QCM_H

#include <stdlib.h> /* malloc, free */
#include <string.h> /* strlen, strcpy */
#include <stdio.h> /* printf */

/* ----- Constants ----- */

#define MAX_CHOICES 5
#define MAX_QUESTIONS 20
#define MAX_QCM 50
#define PASSWORD "prof1234"

/* ----- Structure Choice ----- */

typedef struct {
char *proposition;
int correct;
} Choice;

/* ----- Structure Question ----- */

typedef struct {
char statement[512];
Choice answers[MAX_CHOICES];
int nbAnswers;
} Question;

/* ----- Structure Qcm ----- */

typedef struct {
char name[64];
Question *questions;
int nbQuestions;
int negativePoints;
int multipleChoice;
int sequential;
} Qcm;

/* ----- Function declarations ----- */

void InitQcm(Qcm *q);
int AllocQcm(Qcm *q);
void InitQuestion(Question *q);
int AllocChoice(Choice *c, char *text);
void FreeQuestion(Question *q);
void FreeQcm(Qcm *q);

#endif /* QCM_H */
