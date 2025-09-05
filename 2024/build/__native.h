#ifndef MYPYC_NATIVE_H
#define MYPYC_NATIVE_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T2II
#define MYPYC_DECLARED_tuple_T2II
typedef struct tuple_T2II {
    CPyTagged f0;
    CPyTagged f1;
} tuple_T2II;
#endif

#ifndef MYPYC_DECLARED_tuple_T3OOO
#define MYPYC_DECLARED_tuple_T3OOO
typedef struct tuple_T3OOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
} tuple_T3OOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T2OO
#define MYPYC_DECLARED_tuple_T2OO
typedef struct tuple_T2OO {
    PyObject *f0;
    PyObject *f1;
} tuple_T2OO;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_string;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
    PyObject *_dmap;
    CPyTagged _compacted;
    PyObject *_compacted_disk;
    PyObject *_free_disk;
    PyObject *___mypyc_temp__0;
    CPyTagged ___mypyc_temp__1;
    CPyTagged _i;
    PyObject *___mypyc_temp__2;
    CPyTagged ___mypyc_temp__3;
    CPyTagged _e;
    PyObject *_aug_compdisk;
    PyObject *___mypyc_temp__4;
    PyObject *___mypyc_temp__5;
    PyObject *___mypyc_temp__6;
    PyObject *_aug_freedisk;
    PyObject *___mypyc_temp__7;
    PyObject *___mypyc_temp__8;
    PyObject *_two_blocks;
    tuple_T2II _file_block;
    CPyTagged _file_id;
    CPyTagged _file_count;
    tuple_T2II _free_block;
    PyObject *__;
    CPyTagged _free_count;
    CPyTagged _fill_id;
    CPyTagged _fill_count;
    CPyTagged _can_fill;
    PyObject *___mypyc_temp__9;
    tuple_T3OOO ___mypyc_temp__10;
} comp9___compact_files_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} comp9___compact_files_genObject;

#endif
