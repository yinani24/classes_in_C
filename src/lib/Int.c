#include "Int.h"
#include <stdint.h>

void *new_Int(char *string){
    Int *self = malloc(sizeof(Int));
    self->impl = malloc(sizeof(GenericTraits));
    self->impl->drop = drop_Int;
    self->impl->dump = dump_Int;
    self->impl->cmp = cmp_Int;
    // printf("string: %s\n", string);
    // uint32_t temp;
    // self->i = sscanf(string, "%d", &temp) == 1 ? temp : 0;
    self->i = strtol(string, NULL, 10);
    // printf("i: %x\n", self->i);
    // printf("i: %d\n", self->i);
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
    // printf("cmp_Int self %ld\n", ((Int *)self)->i);
    // printf("cmp_Int other %ld\n", ((Int *)other)->i);
    //printf("cmp_Int diff %d\n", ((Int *)self)->i - ((Int *)other)->i);
    int64_t temp = (int64_t)((Int *)self)->i - (int64_t)((Int *)other)->i;
    if(temp > 0){
        return 1;
    }
    else if(temp < 0){
        return -1;
    }
    else{
        return 0;
    } 
    
}
/// Free this struct.
void drop_Int(void *self){
    free(((Int*) self)->impl);
    free(self);
}

void __attribute__((constructor)) register_Int(){
    add_ctor_dtor("Int", new_Int, drop_Int);
}
