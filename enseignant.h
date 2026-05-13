#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include "qcm.h"
#include "utilitaire.h"
#include "stockage.h"

/* =====================================================
ENSEIGNANT.H
Contains declarations of all teacher mode functions
===================================================== */

/* checks the teacher password, 3 attempts max */
int CheckPassword();

/* displays the teacher main menu */
void TeacherMenu();

/* guides the teacher through the QCM creation process */
void CreateQcm();

/* sets the 3 parameters of the QCM */
void SetQcmParams(Qcm *q);

/* adds a new question to the QCM */
void AddQuestion(Qcm *q);

#endif /* ENSEIGNANT_H */
