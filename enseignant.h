#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include "qcm.h"
#include "utilitaire.h"
#include "stockage.h"

int CheckPassword();


void TeacherMenu();


void CreateQcm();


void SetQcmParams(Qcm *q);

void AddQuestion(Qcm *q);

#endif 
