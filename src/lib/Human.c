#include "Human.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void *new_Human(char * name){
    Human *human = (Human *)malloc(sizeof(Human));
    human->impl = (GenericTraits *)malloc(sizeof(GenericTraits));
    human->impl->cmp = cmp_Human;
    human->impl->dump = dump_Human;
    human->impl->drop = drop_Human;
    human->name = (char *)malloc(strlen(name) + 1);
    // printf("name: %s\n", name);
    strcpy(human->name, name);
    return human;
}

void dump_Human(void *self, FILE *fp){
    fprintf(fp, "%s\n", ((Human *)self)->name);
}

int cmp_Human(void *self, void *other){
    // printf("cmp_Human self %s\n", ((Human *)self)->name);
    // printf("cmp_Human other %s\n", ((Human *)other)->name);
    return strcmp(((Human *)self)->name, ((Human *)other)->name);
}

void drop_Human(void *self){
    free(((Human *)self)->impl);
    free(((Human *)self)->name);
    free(self);
}

void __attribute__((constructor)) register_Human(){
    add_ctor_dtor("Human", new_Human, drop_Human);
}
