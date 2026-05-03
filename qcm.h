#ifndef Qcm_h
#define Qcm_h
#include<stdlib.h>
#include<string.h>
#define MaxChoice 4
#define MaxQuestions 100
#define MaxQcm 20
#define Password "-motdepass123-"

typedef struct
{
    char *proposition; 
    int correct;// si=0 faux, si =1 vrai

}Choice;

typedef struct
{
    char QuestionStatement[256];
    
    Choice answers[MaxChoice];// tableau contenant les proposition de reponses de la question 
   
    int AnswersPossible;// nombre de reponses possibles utilise a la fin 

}Question;

typedef struct
{
    char QcmName[64]; 
    
    Question *questions;// tableau qui contient les questions du   qcm
    
    int QuestionPossible
    
    int NegativPoints;// active par lenseignant si =0 retire pas de point en cas de reponse fausse, si =1 retire des points en cas de reponse fausse
    
    int MultipleChoice;// active par lenseignant si =0 reponse unique, si =1 reponse multiple
    
    int sequential;// active par lenseignant si =0 questions dans le désordre, si =1 questions dans l'ordre

}Qcm;

