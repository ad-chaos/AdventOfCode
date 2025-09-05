#ifndef MYPYC_NATIVE_INTERNAL_H
#define MYPYC_NATIVE_INTERNAL_H
#include <Python.h>
#include <CPy.h>
#include "__native.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[36];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_comp9_internal;
extern CPyModule *CPyModule_comp9;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_bisect;
extern CPyModule *CPyModule_itertools;
extern CPyModule *CPyModule_operator;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_time;
extern PyTypeObject *CPyType_compact_files_env;
extern PyObject *CPyDef_compact_files_env(void);
extern PyTypeObject *CPyType_compact_files_gen;
extern PyObject *CPyDef_compact_files_gen(void);
extern PyObject *CPyDef_compact_files_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
extern PyObject *CPyPy_compact_files_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_compact_files_gen_____next__(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy_compact_files_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_compact_files_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
extern PyObject *CPyPy_compact_files_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_compact_files_gen_____iter__(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy_compact_files_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_compact_files_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
extern PyObject *CPyPy_compact_files_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_compact_files_gen___close(PyObject *cpy_r___mypyc_self__);
extern PyObject *CPyPy_compact_files_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_compact_files(PyObject *cpy_r_string);
extern PyObject *CPyPy_compact_files(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_calc_checksum(PyObject *cpy_r_filesystem);
extern PyObject *CPyPy_calc_checksum(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_run(void);
extern PyObject *CPyPy_run(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
