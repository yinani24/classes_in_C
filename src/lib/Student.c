#include "Student.h"
#include "Human.h"
#include "stdint.h"
#include "string.h"



// void *new_Student(char * name){
//     Student *student = (Student *)malloc(sizeof(Student));
//     //student->human = (Human*)malloc(sizeof(Human));
//     //student->human = *(Human *)new_Human(name);
//     // student->impl = (GenericTraits *)malloc(sizeof(GenericTraits));
//     // student->impl->cmp = cmp_Student;
//     // student->impl->dump = dump_Student;
//     // student->impl->drop = drop_Student;
//     if(strcspn(name, "\n")){
//         name[strcspn(name, "\n")] = '\0';
//     }
    
//     char * token = strtok(name, " ");
//     //printf("token: %s\n", token);
    
//     //strcpy(student->human->name, token);
//     int i = 0;
//     while(token != NULL){
//         if(i == 0){
//             student->human = (Human *)new_Human(token);
//         }
//         else if(i == 1){
//             student->grade = strtol(token, NULL, 10);
//         }
//         token = strtok(NULL, " ");
//         i++;
//         //printf("token: %s\n", token);
//         // student->grade = strtol(token, NULL, 10);
//     }

//     student->human->impl->cmp = cmp_Student;
//     student->human->impl->dump = dump_Student;
//     student->human->impl->drop = drop_Student;
//     // printf("name: %s\n", student->human->name);
//     // printf("grade: %d\n", student->grade);
    
//     return student;
// }
// void dump_Student(void *self, FILE *fp){
//     fprintf(fp, "%s %d\n", ((Student*) self)->human->name, ((Student*) self)->grade);
// }
// int cmp_Student(void *self, void *other){
//     printf("cmp_Student\n");
//     if ((((Student*) self)->grade - ((Student*) other)->grade) == 0){
//         printf("cmp_Human\n");
//         return cmp_Human(((Student*) self)->human, ((Student*) other)->human);
//     }
//     else{
//         return ((Student*) self)->grade - ((Student*) other)->grade;
//     }
// }
// void drop_Student(void *self){
//     drop_Human(((Student*) self)->human);
//     free(self);
// }

// void __attribute__((constructor)) register_Student(){
//     add_ctor_dtor("Student", new_Student, drop_Student);
// }
/* Your code here to define the struct */