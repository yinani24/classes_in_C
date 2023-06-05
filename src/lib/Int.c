#include "Int.h"
#include <stdint.h>

void *new_Int(char *string){
    Int *self = malloc(sizeof(Int));
    self->impl = malloc(sizeof(GenericTraits));
    self->impl->drop = drop_Int;
    self->impl->dump = dump_Int;
    self->impl->cmp = cmp_Int;
    //printf("string: %s\n", string);
    self->i = strtol(string, NULL, 10);
    //printf("i: %d\n", self->i);
    return self;
}
/// Prints `Int` to the file stream. You should print it a hex values with a
/// "0x" prefix.
void dump_Int(void *self, FILE *fp){
    //printf("0x%d\n", ((Int *)self)->i);
    fprintf(fp, "0x%x\n", ((Int *)self)->i);
}
/// Compares two `Int`.
int cmp_Int(void *self, void *other){
    return ((Int *)self)->i - ((Int *)other)->i;
}
/// Free this struct.
void drop_Int(void *self){
    free(((Int*) self)->impl);
    free(self);
}

void __attribute__((constructor)) register_Int(){
    add_ctor_dtor("Int", new_Int, drop_Int);
}
