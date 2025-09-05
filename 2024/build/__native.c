#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "pythonsupport.c"
#include "__native.h"
#include "__native_internal.h"

static PyObject *compact_files_env_setup(PyTypeObject *type);
PyObject *CPyDef_compact_files_env(void);

static PyObject *
compact_files_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_compact_files_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return compact_files_env_setup(type);
}

static int
compact_files_env_traverse(comp9___compact_files_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_string);
    Py_VISIT(self->_type);
    Py_VISIT(self->_value);
    Py_VISIT(self->_traceback);
    Py_VISIT(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_next_label__));
    }
    Py_VISIT(self->_dmap);
    if (CPyTagged_CheckLong(self->_compacted)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_compacted));
    }
    Py_VISIT(self->_compacted_disk);
    Py_VISIT(self->_free_disk);
    Py_VISIT(self->___mypyc_temp__0);
    if (CPyTagged_CheckLong(self->_i)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_i));
    }
    Py_VISIT(self->___mypyc_temp__2);
    if (CPyTagged_CheckLong(self->_e)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_e));
    }
    Py_VISIT(self->_aug_compdisk);
    Py_VISIT(self->___mypyc_temp__4);
    Py_VISIT(self->___mypyc_temp__5);
    Py_VISIT(self->___mypyc_temp__6);
    Py_VISIT(self->_aug_freedisk);
    Py_VISIT(self->___mypyc_temp__7);
    Py_VISIT(self->___mypyc_temp__8);
    Py_VISIT(self->_two_blocks);
    if (CPyTagged_CheckLong(self->_file_block.f0)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_file_block.f0));
    }
    if (CPyTagged_CheckLong(self->_file_block.f1)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_file_block.f1));
    }
    if (CPyTagged_CheckLong(self->_file_id)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_file_id));
    }
    if (CPyTagged_CheckLong(self->_file_count)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_file_count));
    }
    if (CPyTagged_CheckLong(self->_free_block.f0)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_free_block.f0));
    }
    if (CPyTagged_CheckLong(self->_free_block.f1)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_free_block.f1));
    }
    Py_VISIT(self->__);
    if (CPyTagged_CheckLong(self->_free_count)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_free_count));
    }
    if (CPyTagged_CheckLong(self->_fill_id)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_fill_id));
    }
    if (CPyTagged_CheckLong(self->_fill_count)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_fill_count));
    }
    if (CPyTagged_CheckLong(self->_can_fill)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_can_fill));
    }
    Py_VISIT(self->___mypyc_temp__9);
    Py_VISIT(self->___mypyc_temp__10.f0);
    Py_VISIT(self->___mypyc_temp__10.f1);
    Py_VISIT(self->___mypyc_temp__10.f2);
    return 0;
}

static int
compact_files_env_clear(comp9___compact_files_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_string);
    Py_CLEAR(self->_type);
    Py_CLEAR(self->_value);
    Py_CLEAR(self->_traceback);
    Py_CLEAR(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        CPyTagged __tmp = self->___mypyc_next_label__;
        self->___mypyc_next_label__ = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_dmap);
    if (CPyTagged_CheckLong(self->_compacted)) {
        CPyTagged __tmp = self->_compacted;
        self->_compacted = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_compacted_disk);
    Py_CLEAR(self->_free_disk);
    Py_CLEAR(self->___mypyc_temp__0);
    if (CPyTagged_CheckLong(self->_i)) {
        CPyTagged __tmp = self->_i;
        self->_i = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->___mypyc_temp__2);
    if (CPyTagged_CheckLong(self->_e)) {
        CPyTagged __tmp = self->_e;
        self->_e = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_aug_compdisk);
    Py_CLEAR(self->___mypyc_temp__4);
    Py_CLEAR(self->___mypyc_temp__5);
    Py_CLEAR(self->___mypyc_temp__6);
    Py_CLEAR(self->_aug_freedisk);
    Py_CLEAR(self->___mypyc_temp__7);
    Py_CLEAR(self->___mypyc_temp__8);
    Py_CLEAR(self->_two_blocks);
    if (CPyTagged_CheckLong(self->_file_block.f0)) {
        CPyTagged __tmp = self->_file_block.f0;
        self->_file_block.f0 = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_file_block.f1)) {
        CPyTagged __tmp = self->_file_block.f1;
        self->_file_block.f1 = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_file_id)) {
        CPyTagged __tmp = self->_file_id;
        self->_file_id = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_file_count)) {
        CPyTagged __tmp = self->_file_count;
        self->_file_count = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_free_block.f0)) {
        CPyTagged __tmp = self->_free_block.f0;
        self->_free_block.f0 = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_free_block.f1)) {
        CPyTagged __tmp = self->_free_block.f1;
        self->_free_block.f1 = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->__);
    if (CPyTagged_CheckLong(self->_free_count)) {
        CPyTagged __tmp = self->_free_count;
        self->_free_count = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_fill_id)) {
        CPyTagged __tmp = self->_fill_id;
        self->_fill_id = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_fill_count)) {
        CPyTagged __tmp = self->_fill_count;
        self->_fill_count = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_can_fill)) {
        CPyTagged __tmp = self->_can_fill;
        self->_can_fill = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->___mypyc_temp__9);
    Py_CLEAR(self->___mypyc_temp__10.f0);
    Py_CLEAR(self->___mypyc_temp__10.f1);
    Py_CLEAR(self->___mypyc_temp__10.f2);
    return 0;
}

static void
compact_files_env_dealloc(comp9___compact_files_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, compact_files_env_dealloc)
    compact_files_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem compact_files_env_vtable[1];
static bool
CPyDef_compact_files_env_trait_vtable_setup(void)
{
    CPyVTableItem compact_files_env_vtable_scratch[] = {
        NULL
    };
    memcpy(compact_files_env_vtable, compact_files_env_vtable_scratch, sizeof(compact_files_env_vtable));
    return 1;
}

static PyMethodDef compact_files_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_compact_files_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "compact_files_env",
    .tp_new = compact_files_env_new,
    .tp_dealloc = (destructor)compact_files_env_dealloc,
    .tp_traverse = (traverseproc)compact_files_env_traverse,
    .tp_clear = (inquiry)compact_files_env_clear,
    .tp_methods = compact_files_env_methods,
    .tp_basicsize = sizeof(comp9___compact_files_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_compact_files_env_template = &CPyType_compact_files_env_template_;

static PyObject *
compact_files_env_setup(PyTypeObject *type)
{
    comp9___compact_files_envObject *self;
    self = (comp9___compact_files_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = compact_files_env_vtable;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    self->_compacted = CPY_INT_TAG;
    self->___mypyc_temp__1 = CPY_INT_TAG;
    self->_i = CPY_INT_TAG;
    self->___mypyc_temp__3 = CPY_INT_TAG;
    self->_e = CPY_INT_TAG;
    self->_file_block = (tuple_T2II) { CPY_INT_TAG, CPY_INT_TAG };
    self->_file_id = CPY_INT_TAG;
    self->_file_count = CPY_INT_TAG;
    self->_free_block = (tuple_T2II) { CPY_INT_TAG, CPY_INT_TAG };
    self->_free_count = CPY_INT_TAG;
    self->_fill_id = CPY_INT_TAG;
    self->_fill_count = CPY_INT_TAG;
    self->_can_fill = CPY_INT_TAG;
    self->___mypyc_temp__10 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef_compact_files_env(void)
{
    PyObject *self = compact_files_env_setup(CPyType_compact_files_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *compact_files_gen_setup(PyTypeObject *type);
PyObject *CPyDef_compact_files_gen(void);

static PyObject *
compact_files_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_compact_files_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return compact_files_gen_setup(type);
}

static int
compact_files_gen_traverse(comp9___compact_files_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
compact_files_gen_clear(comp9___compact_files_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
compact_files_gen_dealloc(comp9___compact_files_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, compact_files_gen_dealloc)
    compact_files_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem compact_files_gen_vtable[6];
static bool
CPyDef_compact_files_gen_trait_vtable_setup(void)
{
    CPyVTableItem compact_files_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_compact_files_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef_compact_files_gen_____next__,
        (CPyVTableItem)CPyDef_compact_files_gen___send,
        (CPyVTableItem)CPyDef_compact_files_gen_____iter__,
        (CPyVTableItem)CPyDef_compact_files_gen___throw,
        (CPyVTableItem)CPyDef_compact_files_gen___close,
    };
    memcpy(compact_files_gen_vtable, compact_files_gen_vtable_scratch, sizeof(compact_files_gen_vtable));
    return 1;
}

static PyMethodDef compact_files_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy_compact_files_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy_compact_files_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy_compact_files_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy_compact_files_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy_compact_files_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy_compact_files_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_compact_files_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "compact_files_gen",
    .tp_new = compact_files_gen_new,
    .tp_dealloc = (destructor)compact_files_gen_dealloc,
    .tp_traverse = (traverseproc)compact_files_gen_traverse,
    .tp_clear = (inquiry)compact_files_gen_clear,
    .tp_methods = compact_files_gen_methods,
    .tp_iter = CPyDef_compact_files_gen_____iter__,
    .tp_iternext = CPyDef_compact_files_gen_____next__,
    .tp_basicsize = sizeof(comp9___compact_files_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_compact_files_gen_template = &CPyType_compact_files_gen_template_;

static PyObject *
compact_files_gen_setup(PyTypeObject *type)
{
    comp9___compact_files_genObject *self;
    self = (comp9___compact_files_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = compact_files_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_compact_files_gen(void)
{
    PyObject *self = compact_files_gen_setup(CPyType_compact_files_gen);
    if (self == NULL)
        return NULL;
    return self;
}

static PyMethodDef module_methods[] = {
    {"compact_files", (PyCFunction)CPyPy_compact_files, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"calc_checksum", (PyCFunction)CPyPy_calc_checksum, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"run", (PyCFunction)CPyPy_run, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "comp9",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_comp9(void)
{
    PyObject* modname = NULL;
    if (CPyModule_comp9_internal) {
        Py_INCREF(CPyModule_comp9_internal);
        return CPyModule_comp9_internal;
    }
    CPyModule_comp9_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_comp9_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_comp9_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_comp9_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    CPyType_compact_files_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_compact_files_env_template, NULL, modname);
    if (unlikely(!CPyType_compact_files_env))
        goto fail;
    CPyType_compact_files_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_compact_files_gen_template, NULL, modname);
    if (unlikely(!CPyType_compact_files_gen))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_comp9_internal;
    fail:
    Py_CLEAR(CPyModule_comp9_internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_compact_files_env);
    Py_CLEAR(CPyType_compact_files_gen);
    return NULL;
}

PyObject *CPyDef_compact_files_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject **cpy_r_r29;
    PyObject *cpy_r_r30;
    CPyTagged cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject **cpy_r_r43;
    PyObject *cpy_r_r44;
    CPyTagged cpy_r_r45;
    CPyTagged cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject **cpy_r_r52;
    PyObject *cpy_r_r53;
    CPyTagged cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    CPyTagged cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    CPyTagged cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    char cpy_r_r64;
    char cpy_r_r65;
    PyObject *cpy_r_r66;
    char cpy_r_r67;
    char cpy_r_r68;
    char cpy_r_r69;
    PyObject *cpy_r_r70;
    char cpy_r_r71;
    char cpy_r_r72;
    PyObject *cpy_r_r73;
    CPyPtr cpy_r_r74;
    int64_t cpy_r_r75;
    CPyTagged cpy_r_r76;
    CPyTagged cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    CPyTagged cpy_r_r80;
    PyObject *cpy_r_r81;
    CPyTagged cpy_r_r82;
    char cpy_r_r83;
    CPyTagged cpy_r_r84;
    CPyTagged cpy_r_r85;
    CPyTagged cpy_r_r86;
    tuple_T2II cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    int32_t cpy_r_r90;
    char cpy_r_r91;
    CPyTagged cpy_r_r92;
    CPyTagged cpy_r_r93;
    char cpy_r_r94;
    char cpy_r_r95;
    CPyTagged cpy_r_r96;
    CPyTagged cpy_r_r97;
    char cpy_r_r98;
    PyObject *cpy_r_r99;
    char cpy_r_r100;
    PyObject *cpy_r_r101;
    char cpy_r_r102;
    PyObject *cpy_r_r103;
    CPyTagged cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject **cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    char cpy_r_r114;
    char cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    tuple_T2II cpy_r_r118;
    CPyTagged cpy_r_r119;
    char cpy_r_r120;
    CPyTagged cpy_r_r121;
    char cpy_r_r122;
    CPyTagged cpy_r_r123;
    CPyTagged cpy_r_r124;
    CPyTagged cpy_r_r125;
    tuple_T2II cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    int32_t cpy_r_r129;
    char cpy_r_r130;
    char cpy_r_r131;
    PyObject *cpy_r_r132;
    CPyTagged cpy_r_r133;
    CPyTagged cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    char cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject **cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    char cpy_r_r151;
    char cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    char cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    tuple_T2II cpy_r_r159;
    char cpy_r_r160;
    tuple_T2II cpy_r_r161;
    CPyTagged cpy_r_r162;
    CPyTagged cpy_r_r163;
    char cpy_r_r164;
    CPyTagged cpy_r_r165;
    CPyTagged cpy_r_r166;
    char cpy_r_r167;
    CPyTagged cpy_r_r168;
    CPyTagged cpy_r_r169;
    tuple_T2II cpy_r_r170;
    PyObject *cpy_r_r171;
    char cpy_r_r172;
    PyObject *cpy_r_r173;
    char cpy_r_r174;
    PyObject *cpy_r_r175;
    CPyPtr cpy_r_r176;
    int64_t cpy_r_r177;
    CPyTagged cpy_r_r178;
    char cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    tuple_T2II cpy_r_r182;
    char cpy_r_r183;
    tuple_T2II cpy_r_r184;
    CPyTagged cpy_r_r185;
    CPyTagged cpy_r_r186;
    PyObject *cpy_r_r187;
    char cpy_r_r188;
    CPyTagged cpy_r_r189;
    CPyTagged cpy_r_r190;
    char cpy_r_r191;
    CPyTagged cpy_r_r192;
    char cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    tuple_T2II cpy_r_r196;
    CPyTagged cpy_r_r197;
    CPyTagged cpy_r_r198;
    char cpy_r_r199;
    CPyTagged cpy_r_r200;
    CPyTagged cpy_r_r201;
    char cpy_r_r202;
    CPyTagged cpy_r_r203;
    CPyTagged cpy_r_r204;
    int64_t cpy_r_r205;
    char cpy_r_r206;
    int64_t cpy_r_r207;
    char cpy_r_r208;
    char cpy_r_r209;
    char cpy_r_r210;
    CPyTagged cpy_r_r211;
    char cpy_r_r212;
    CPyTagged cpy_r_r213;
    CPyTagged cpy_r_r214;
    tuple_T2II cpy_r_r215;
    PyObject *cpy_r_r216;
    char cpy_r_r217;
    PyObject *cpy_r_r218;
    char cpy_r_r219;
    CPyTagged cpy_r_r220;
    CPyTagged cpy_r_r221;
    CPyTagged cpy_r_r222;
    char cpy_r_r223;
    CPyTagged cpy_r_r224;
    CPyTagged cpy_r_r225;
    int64_t cpy_r_r226;
    char cpy_r_r227;
    int64_t cpy_r_r228;
    char cpy_r_r229;
    char cpy_r_r230;
    char cpy_r_r231;
    char cpy_r_r232;
    PyObject *cpy_r_r233;
    CPyTagged cpy_r_r234;
    CPyTagged cpy_r_r235;
    CPyTagged cpy_r_r236;
    CPyTagged cpy_r_r237;
    tuple_T2II cpy_r_r238;
    PyObject *cpy_r_r239;
    int32_t cpy_r_r240;
    char cpy_r_r241;
    char cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    char cpy_r_r245;
    PyObject *cpy_r_r246;
    PyObject *cpy_r_r247;
    PyObject *cpy_r_r248;
    PyObject *cpy_r_r249;
    PyObject *cpy_r_r250;
    char cpy_r_r251;
    PyObject *cpy_r_r252;
    char cpy_r_r253;
    tuple_T3OOO cpy_r_r254;
    char cpy_r_r255;
    PyObject **cpy_r_r256;
    PyObject *cpy_r_r257;
    char cpy_r_r258;
    char cpy_r_r259;
    tuple_T3OOO cpy_r_r260;
    char cpy_r_r261;
    tuple_T3OOO cpy_r_r262;
    tuple_T3OOO cpy_r_r263;
    char cpy_r_r264;
    PyObject *cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject *cpy_r_r267;
    PyObject *cpy_r_r268;
    char cpy_r_r269;
    char cpy_r_r270;
    char cpy_r_r271;
    char cpy_r_r272;
    char cpy_r_r273;
    char cpy_r_r274;
    PyObject *cpy_r_r275;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((comp9___compact_files_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_gen", "__mypyc_env__", 8, CPyStatic_globals);
        goto CPyL210;
    }
    CPy_INCREF(cpy_r_r2);
CPyL1: ;
    cpy_r_r3 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_next_label__;
    if (unlikely(cpy_r_r3 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_next_label__", 8, CPyStatic_globals);
        goto CPyL211;
    }
    CPyTagged_INCREF(cpy_r_r3);
    goto CPyL203;
CPyL2: ;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = cpy_r_type != cpy_r_r4;
    if (cpy_r_r5) {
        goto CPyL212;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("comp9.py", "compact_files", 8, CPyStatic_globals);
        goto CPyL209;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r6 = (PyObject *)&PyLong_Type;
    cpy_r_r7 = ((comp9___compact_files_envObject *)cpy_r_r2)->_string;
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "string", 9, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r7);
CPyL6: ;
    cpy_r_r8 = CPyModule_builtins;
    cpy_r_r9 = CPyStatics[3]; /* 'map' */
    cpy_r_r10 = CPyObject_GetAttr(cpy_r_r8, cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 9, CPyStatic_globals);
        goto CPyL213;
    }
    PyObject *cpy_r_r11[2] = {cpy_r_r6, cpy_r_r7};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = _PyObject_Vectorcall(cpy_r_r10, cpy_r_r12, 2, 0);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 9, CPyStatic_globals);
        goto CPyL213;
    }
    CPy_DECREF(cpy_r_r7);
    cpy_r_r14 = PySequence_List(cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 9, CPyStatic_globals);
        goto CPyL211;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_dmap != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_dmap);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_dmap = cpy_r_r14;
    cpy_r_r15 = 1;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("comp9.py", "compact_files", 9, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r16 = ((comp9___compact_files_envObject *)cpy_r_r2)->_dmap;
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "dmap", 10, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r16);
CPyL11: ;
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyStatics[4]; /* 'accumulate' */
    cpy_r_r19 = CPyDict_GetItem(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL214;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL214;
    }
    CPy_DECREF(cpy_r_r16);
    cpy_r_r23 = PySequence_List(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r24 = ((comp9___compact_files_envObject *)cpy_r_r2)->_dmap;
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "dmap", 10, CPyStatic_globals);
        goto CPyL215;
    }
    CPy_INCREF(cpy_r_r24);
CPyL15: ;
    cpy_r_r25 = CPyModule_builtins;
    cpy_r_r26 = CPyStatics[5]; /* 'sum' */
    cpy_r_r27 = CPyObject_GetAttr(cpy_r_r25, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL216;
    }
    PyObject *cpy_r_r28[1] = {cpy_r_r24};
    cpy_r_r29 = (PyObject **)&cpy_r_r28;
    cpy_r_r30 = _PyObject_Vectorcall(cpy_r_r27, cpy_r_r29, 1, 0);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL216;
    }
    CPy_DECREF(cpy_r_r24);
    if (likely(PyLong_Check(cpy_r_r30)))
        cpy_r_r31 = CPyTagged_FromObject(cpy_r_r30);
    else {
        CPy_TypeError("int", cpy_r_r30); cpy_r_r31 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r31 == CPY_INT_TAG)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL215;
    }
    cpy_r_r32 = ((comp9___compact_files_envObject *)cpy_r_r2)->_dmap;
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "dmap", 10, CPyStatic_globals);
        goto CPyL217;
    }
    CPy_INCREF(cpy_r_r32);
CPyL19: ;
    cpy_r_r33 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r34 = CPyStatics[28]; /* 1 */
    cpy_r_r35 = CPyStatics[29]; /* 2 */
    cpy_r_r36 = PySlice_New(cpy_r_r34, cpy_r_r33, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL218;
    }
    cpy_r_r37 = PyObject_GetItem(cpy_r_r32, cpy_r_r36);
    CPy_DECREF(cpy_r_r32);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL217;
    }
    if (likely(PyList_Check(cpy_r_r37)))
        cpy_r_r38 = cpy_r_r37;
    else {
        CPy_TypeErrorTraceback("comp9.py", "compact_files", 10, CPyStatic_globals, "list", cpy_r_r37);
        goto CPyL217;
    }
    cpy_r_r39 = CPyModule_builtins;
    cpy_r_r40 = CPyStatics[5]; /* 'sum' */
    cpy_r_r41 = CPyObject_GetAttr(cpy_r_r39, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL219;
    }
    PyObject *cpy_r_r42[1] = {cpy_r_r38};
    cpy_r_r43 = (PyObject **)&cpy_r_r42;
    cpy_r_r44 = _PyObject_Vectorcall(cpy_r_r41, cpy_r_r43, 1, 0);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL219;
    }
    CPy_DECREF(cpy_r_r38);
    if (likely(PyLong_Check(cpy_r_r44)))
        cpy_r_r45 = CPyTagged_FromObject(cpy_r_r44);
    else {
        CPy_TypeError("int", cpy_r_r44); cpy_r_r45 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r45 == CPY_INT_TAG)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL217;
    }
    cpy_r_r46 = CPyTagged_Subtract(cpy_r_r31, cpy_r_r45);
    CPyTagged_DECREF(cpy_r_r31);
    CPyTagged_DECREF(cpy_r_r45);
    cpy_r_r47 = CPyStatic_globals;
    cpy_r_r48 = CPyStatics[6]; /* 'bisect' */
    cpy_r_r49 = CPyDict_GetItem(cpy_r_r47, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL220;
    }
    cpy_r_r50 = CPyTagged_StealAsObject(cpy_r_r46);
    PyObject *cpy_r_r51[2] = {cpy_r_r23, cpy_r_r50};
    cpy_r_r52 = (PyObject **)&cpy_r_r51;
    cpy_r_r53 = _PyObject_Vectorcall(cpy_r_r49, cpy_r_r52, 2, 0);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL221;
    }
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r50);
    if (likely(PyLong_Check(cpy_r_r53)))
        cpy_r_r54 = CPyTagged_FromObject(cpy_r_r53);
    else {
        CPy_TypeError("int", cpy_r_r53); cpy_r_r54 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r53);
    if (unlikely(cpy_r_r54 == CPY_INT_TAG)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL211;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_compacted != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_compacted);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_compacted = cpy_r_r54;
    cpy_r_r55 = 1;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("comp9.py", "compact_files", 10, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r56 = ((comp9___compact_files_envObject *)cpy_r_r2)->_dmap;
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "dmap", 13, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r56);
CPyL30: ;
    cpy_r_r57 = ((comp9___compact_files_envObject *)cpy_r_r2)->_compacted;
    if (unlikely(cpy_r_r57 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "compacted", 13, CPyStatic_globals);
        goto CPyL222;
    }
    CPyTagged_INCREF(cpy_r_r57);
CPyL31: ;
    cpy_r_r58 = CPyList_GetSlice(cpy_r_r56, 0, cpy_r_r57);
    CPy_DECREF(cpy_r_r56);
    CPyTagged_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 13, CPyStatic_globals);
        goto CPyL211;
    }
    if (likely(PyList_Check(cpy_r_r58)))
        cpy_r_r59 = cpy_r_r58;
    else {
        CPy_TypeErrorTraceback("comp9.py", "compact_files", 13, CPyStatic_globals, "list", cpy_r_r58);
        goto CPyL211;
    }
    cpy_r_r60 = ((comp9___compact_files_envObject *)cpy_r_r2)->_dmap;
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "dmap", 14, CPyStatic_globals);
        goto CPyL223;
    }
    CPy_INCREF(cpy_r_r60);
CPyL34: ;
    cpy_r_r61 = ((comp9___compact_files_envObject *)cpy_r_r2)->_compacted;
    if (unlikely(cpy_r_r61 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "compacted", 14, CPyStatic_globals);
        goto CPyL224;
    }
    CPyTagged_INCREF(cpy_r_r61);
CPyL35: ;
    cpy_r_r62 = CPyList_GetSlice(cpy_r_r60, cpy_r_r61, 9223372036854775806LL);
    CPy_DECREF(cpy_r_r60);
    CPyTagged_DECREF(cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 14, CPyStatic_globals);
        goto CPyL223;
    }
    if (likely(PyList_Check(cpy_r_r62)))
        cpy_r_r63 = cpy_r_r62;
    else {
        CPy_TypeErrorTraceback("comp9.py", "compact_files", 14, CPyStatic_globals, "list", cpy_r_r62);
        goto CPyL223;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_compacted_disk != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_compacted_disk);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_compacted_disk = cpy_r_r59;
    cpy_r_r64 = 1;
    if (unlikely(!cpy_r_r64)) {
        CPy_AddTraceback("comp9.py", "compact_files", 12, CPyStatic_globals);
        goto CPyL225;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_free_disk != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_free_disk);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_free_disk = cpy_r_r63;
    cpy_r_r65 = 1;
    if (unlikely(!cpy_r_r65)) {
        CPy_AddTraceback("comp9.py", "compact_files", 12, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r66 = PyList_New(0);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 17, CPyStatic_globals);
        goto CPyL211;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__0 != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__0);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__0 = cpy_r_r66;
    cpy_r_r67 = 1;
    if (unlikely(!cpy_r_r67)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL211;
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__1 = 0;
    cpy_r_r68 = 1;
    if (unlikely(!cpy_r_r68)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL211;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_i != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_i);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_i = 0;
    cpy_r_r69 = 1;
    if (unlikely(!cpy_r_r69)) {
        CPy_AddTraceback("comp9.py", "compact_files", 17, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r70 = ((comp9___compact_files_envObject *)cpy_r_r2)->_compacted_disk;
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "compacted_disk", 17, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r70);
CPyL44: ;
    if (((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__2 != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__2);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__2 = cpy_r_r70;
    cpy_r_r71 = 1;
    if (unlikely(!cpy_r_r71)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL211;
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__3 = 0;
    cpy_r_r72 = 1;
    if (unlikely(!cpy_r_r72)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL211;
    }
CPyL46: ;
    cpy_r_r73 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__2;
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__2", 17, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r73);
CPyL47: ;
    cpy_r_r74 = (CPyPtr)&((PyVarObject *)cpy_r_r73)->ob_size;
    cpy_r_r75 = *(int64_t *)cpy_r_r74;
    CPy_DECREF(cpy_r_r73);
    cpy_r_r76 = cpy_r_r75 << 1;
    cpy_r_r77 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__3;
    if (unlikely(cpy_r_r77 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__3", 17, CPyStatic_globals);
        goto CPyL211;
    }
CPyL48: ;
    cpy_r_r78 = (Py_ssize_t)cpy_r_r77 < (Py_ssize_t)cpy_r_r76;
    if (!cpy_r_r78) goto CPyL63;
    cpy_r_r79 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__2;
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__2", 17, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r79);
CPyL50: ;
    cpy_r_r80 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__3;
    if (unlikely(cpy_r_r80 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__3", 17, CPyStatic_globals);
        goto CPyL226;
    }
CPyL51: ;
    cpy_r_r81 = CPyList_GetItemUnsafe(cpy_r_r79, cpy_r_r80);
    CPy_DECREF(cpy_r_r79);
    if (likely(PyLong_Check(cpy_r_r81)))
        cpy_r_r82 = CPyTagged_FromObject(cpy_r_r81);
    else {
        CPy_TypeError("int", cpy_r_r81); cpy_r_r82 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r81);
    if (unlikely(cpy_r_r82 == CPY_INT_TAG)) {
        CPy_AddTraceback("comp9.py", "compact_files", 17, CPyStatic_globals);
        goto CPyL211;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_e != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_e);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_e = cpy_r_r82;
    cpy_r_r83 = 1;
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("comp9.py", "compact_files", 17, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r84 = ((comp9___compact_files_envObject *)cpy_r_r2)->_i;
    if (unlikely(cpy_r_r84 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "i", 17, CPyStatic_globals);
        goto CPyL211;
    }
    CPyTagged_INCREF(cpy_r_r84);
CPyL54: ;
    cpy_r_r85 = CPyTagged_Rshift(cpy_r_r84, 2);
    CPyTagged_DECREF(cpy_r_r84);
    if (unlikely(cpy_r_r85 == CPY_INT_TAG)) {
        CPy_AddTraceback("comp9.py", "compact_files", 17, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r86 = ((comp9___compact_files_envObject *)cpy_r_r2)->_e;
    if (unlikely(cpy_r_r86 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "e", 17, CPyStatic_globals);
        goto CPyL227;
    }
    CPyTagged_INCREF(cpy_r_r86);
CPyL56: ;
    cpy_r_r87.f0 = cpy_r_r85;
    cpy_r_r87.f1 = cpy_r_r86;
    cpy_r_r88 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__0;
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__0", -1, CPyStatic_globals);
        goto CPyL228;
    }
    CPy_INCREF(cpy_r_r88);
CPyL57: ;
    cpy_r_r89 = PyTuple_New(2);
    if (unlikely(cpy_r_r89 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp1 = CPyTagged_StealAsObject(cpy_r_r87.f0);
    PyTuple_SET_ITEM(cpy_r_r89, 0, __tmp1);
    PyObject *__tmp2 = CPyTagged_StealAsObject(cpy_r_r87.f1);
    PyTuple_SET_ITEM(cpy_r_r89, 1, __tmp2);
    cpy_r_r90 = PyList_Append(cpy_r_r88, cpy_r_r89);
    CPy_DECREF(cpy_r_r88);
    CPy_DECREF(cpy_r_r89);
    cpy_r_r91 = cpy_r_r90 >= 0;
    if (unlikely(!cpy_r_r91)) {
        CPy_AddTraceback("comp9.py", "compact_files", 17, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r92 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__1;
    if (unlikely(cpy_r_r92 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__1", 17, CPyStatic_globals);
        goto CPyL211;
    }
CPyL59: ;
    cpy_r_r93 = cpy_r_r92 + 2;
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__1 = cpy_r_r93;
    cpy_r_r94 = 1;
    if (unlikely(!cpy_r_r94)) {
        CPy_AddTraceback("comp9.py", "compact_files", 17, CPyStatic_globals);
        goto CPyL211;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_i != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_i);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_i = cpy_r_r93;
    cpy_r_r95 = 1;
    if (unlikely(!cpy_r_r95)) {
        CPy_AddTraceback("comp9.py", "compact_files", 17, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r96 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__3;
    if (unlikely(cpy_r_r96 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__3", 17, CPyStatic_globals);
        goto CPyL211;
    }
CPyL62: ;
    cpy_r_r97 = cpy_r_r96 + 2;
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__3 = cpy_r_r97;
    cpy_r_r98 = 1;
    if (unlikely(!cpy_r_r98)) {
        CPy_AddTraceback("comp9.py", "compact_files", 17, CPyStatic_globals);
        goto CPyL211;
    } else
        goto CPyL46;
CPyL63: ;
    cpy_r_r99 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__0;
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__0", -1, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r99);
CPyL64: ;
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_aug_compdisk != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_aug_compdisk);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_aug_compdisk = cpy_r_r99;
    cpy_r_r100 = 1;
    if (unlikely(!cpy_r_r100)) {
        CPy_AddTraceback("comp9.py", "compact_files", 17, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r101 = PyList_New(0);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 19, CPyStatic_globals);
        goto CPyL211;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__4 != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__4);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__4 = cpy_r_r101;
    cpy_r_r102 = 1;
    if (unlikely(!cpy_r_r102)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r103 = ((comp9___compact_files_envObject *)cpy_r_r2)->_free_disk;
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "free_disk", 19, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r103);
CPyL68: ;
    cpy_r_r104 = ((comp9___compact_files_envObject *)cpy_r_r2)->_compacted;
    if (unlikely(cpy_r_r104 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "compacted", 19, CPyStatic_globals);
        goto CPyL229;
    }
    CPyTagged_INCREF(cpy_r_r104);
CPyL69: ;
    cpy_r_r105 = CPyModule_builtins;
    cpy_r_r106 = CPyStatics[7]; /* 'enumerate' */
    cpy_r_r107 = CPyObject_GetAttr(cpy_r_r105, cpy_r_r106);
    if (unlikely(cpy_r_r107 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 19, CPyStatic_globals);
        goto CPyL230;
    }
    cpy_r_r108 = CPyTagged_StealAsObject(cpy_r_r104);
    PyObject *cpy_r_r109[2] = {cpy_r_r103, cpy_r_r108};
    cpy_r_r110 = (PyObject **)&cpy_r_r109;
    cpy_r_r111 = CPyStatics[30]; /* ('start',) */
    cpy_r_r112 = _PyObject_Vectorcall(cpy_r_r107, cpy_r_r110, 1, cpy_r_r111);
    CPy_DECREF(cpy_r_r107);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 19, CPyStatic_globals);
        goto CPyL231;
    }
    CPy_DECREF(cpy_r_r103);
    CPy_DECREF(cpy_r_r108);
    cpy_r_r113 = PyObject_GetIter(cpy_r_r112);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 19, CPyStatic_globals);
        goto CPyL232;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__5 != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__5);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__5 = cpy_r_r112;
    cpy_r_r114 = 1;
    if (unlikely(!cpy_r_r114)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL233;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__6 != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__6);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__6 = cpy_r_r113;
    cpy_r_r115 = 1;
    if (unlikely(!cpy_r_r115)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL211;
    }
CPyL74: ;
    cpy_r_r116 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__6;
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__6", 19, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r116);
CPyL75: ;
    cpy_r_r117 = PyIter_Next(cpy_r_r116);
    CPy_DECREF(cpy_r_r116);
    if (cpy_r_r117 == NULL) goto CPyL84;
    PyObject *__tmp3;
    if (unlikely(!(PyTuple_Check(cpy_r_r117) && PyTuple_GET_SIZE(cpy_r_r117) == 2))) {
        __tmp3 = NULL;
        goto __LL4;
    }
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r117, 0))))
        __tmp3 = PyTuple_GET_ITEM(cpy_r_r117, 0);
    else {
        __tmp3 = NULL;
    }
    if (__tmp3 == NULL) goto __LL4;
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r117, 1))))
        __tmp3 = PyTuple_GET_ITEM(cpy_r_r117, 1);
    else {
        __tmp3 = NULL;
    }
    if (__tmp3 == NULL) goto __LL4;
    __tmp3 = cpy_r_r117;
__LL4: ;
    if (unlikely(__tmp3 == NULL)) {
        CPy_TypeError("tuple[int, int]", cpy_r_r117); cpy_r_r118 = (tuple_T2II) { CPY_INT_TAG, CPY_INT_TAG };
    } else {
        PyObject *__tmp5 = PyTuple_GET_ITEM(cpy_r_r117, 0);
        CPyTagged __tmp6;
        if (likely(PyLong_Check(__tmp5)))
            __tmp6 = CPyTagged_FromObject(__tmp5);
        else {
            CPy_TypeError("int", __tmp5); __tmp6 = CPY_INT_TAG;
        }
        cpy_r_r118.f0 = __tmp6;
        PyObject *__tmp7 = PyTuple_GET_ITEM(cpy_r_r117, 1);
        CPyTagged __tmp8;
        if (likely(PyLong_Check(__tmp7)))
            __tmp8 = CPyTagged_FromObject(__tmp7);
        else {
            CPy_TypeError("int", __tmp7); __tmp8 = CPY_INT_TAG;
        }
        cpy_r_r118.f1 = __tmp8;
    }
    CPy_DECREF(cpy_r_r117);
    if (unlikely(cpy_r_r118.f0 == CPY_INT_TAG)) {
        CPy_AddTraceback("comp9.py", "compact_files", 19, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r119 = cpy_r_r118.f0;
    CPyTagged_INCREF(cpy_r_r119);
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_i != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_i);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_i = cpy_r_r119;
    cpy_r_r120 = 1;
    if (unlikely(!cpy_r_r120)) {
        CPy_AddTraceback("comp9.py", "compact_files", 19, CPyStatic_globals);
        goto CPyL234;
    }
    cpy_r_r121 = cpy_r_r118.f1;
    CPyTagged_INCREF(cpy_r_r121);
    CPyTagged_DECREF(cpy_r_r118.f0);
    CPyTagged_DECREF(cpy_r_r118.f1);
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_e != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_e);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_e = cpy_r_r121;
    cpy_r_r122 = 1;
    if (unlikely(!cpy_r_r122)) {
        CPy_AddTraceback("comp9.py", "compact_files", 19, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r123 = ((comp9___compact_files_envObject *)cpy_r_r2)->_i;
    if (unlikely(cpy_r_r123 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "i", 19, CPyStatic_globals);
        goto CPyL211;
    }
    CPyTagged_INCREF(cpy_r_r123);
CPyL80: ;
    cpy_r_r124 = CPyTagged_Rshift(cpy_r_r123, 2);
    CPyTagged_DECREF(cpy_r_r123);
    if (unlikely(cpy_r_r124 == CPY_INT_TAG)) {
        CPy_AddTraceback("comp9.py", "compact_files", 19, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r125 = ((comp9___compact_files_envObject *)cpy_r_r2)->_e;
    if (unlikely(cpy_r_r125 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "e", 19, CPyStatic_globals);
        goto CPyL235;
    }
    CPyTagged_INCREF(cpy_r_r125);
CPyL82: ;
    cpy_r_r126.f0 = cpy_r_r124;
    cpy_r_r126.f1 = cpy_r_r125;
    cpy_r_r127 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__4;
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__4", -1, CPyStatic_globals);
        goto CPyL236;
    }
    CPy_INCREF(cpy_r_r127);
CPyL83: ;
    cpy_r_r128 = PyTuple_New(2);
    if (unlikely(cpy_r_r128 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp9 = CPyTagged_StealAsObject(cpy_r_r126.f0);
    PyTuple_SET_ITEM(cpy_r_r128, 0, __tmp9);
    PyObject *__tmp10 = CPyTagged_StealAsObject(cpy_r_r126.f1);
    PyTuple_SET_ITEM(cpy_r_r128, 1, __tmp10);
    cpy_r_r129 = PyList_Append(cpy_r_r127, cpy_r_r128);
    CPy_DECREF(cpy_r_r127);
    CPy_DECREF(cpy_r_r128);
    cpy_r_r130 = cpy_r_r129 >= 0;
    if (unlikely(!cpy_r_r130)) {
        CPy_AddTraceback("comp9.py", "compact_files", 19, CPyStatic_globals);
        goto CPyL211;
    } else
        goto CPyL74;
CPyL84: ;
    cpy_r_r131 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r131)) {
        CPy_AddTraceback("comp9.py", "compact_files", 19, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r132 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__4;
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__4", -1, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r132);
CPyL86: ;
    cpy_r_r133 = ((comp9___compact_files_envObject *)cpy_r_r2)->_compacted;
    if (unlikely(cpy_r_r133 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "compacted", 20, CPyStatic_globals);
        goto CPyL237;
    }
    CPyTagged_INCREF(cpy_r_r133);
CPyL87: ;
    cpy_r_r134 = CPyTagged_Remainder(cpy_r_r133, 4);
    CPyTagged_DECREF(cpy_r_r133);
    if (unlikely(cpy_r_r134 == CPY_INT_TAG)) {
        CPy_AddTraceback("comp9.py", "compact_files", 20, CPyStatic_globals);
        goto CPyL237;
    }
    cpy_r_r135 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r136 = CPyTagged_StealAsObject(cpy_r_r134);
    cpy_r_r137 = CPyStatics[29]; /* 2 */
    cpy_r_r138 = PySlice_New(cpy_r_r136, cpy_r_r135, cpy_r_r137);
    CPy_DECREF(cpy_r_r136);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 19, CPyStatic_globals);
        goto CPyL237;
    }
    cpy_r_r139 = PyObject_GetItem(cpy_r_r132, cpy_r_r138);
    CPy_DECREF(cpy_r_r132);
    CPy_DECREF(cpy_r_r138);
    if (unlikely(cpy_r_r139 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 19, CPyStatic_globals);
        goto CPyL211;
    }
    if (likely(PyList_Check(cpy_r_r139)))
        cpy_r_r140 = cpy_r_r139;
    else {
        CPy_TypeErrorTraceback("comp9.py", "compact_files", 19, CPyStatic_globals, "list", cpy_r_r139);
        goto CPyL211;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_aug_freedisk != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_aug_freedisk);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_aug_freedisk = cpy_r_r140;
    cpy_r_r141 = 1;
    if (unlikely(!cpy_r_r141)) {
        CPy_AddTraceback("comp9.py", "compact_files", 19, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r142 = ((comp9___compact_files_envObject *)cpy_r_r2)->_aug_compdisk;
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "aug_compdisk", 23, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r142);
CPyL93: ;
    cpy_r_r143 = CPyStatic_globals;
    cpy_r_r144 = CPyStatics[9]; /* 'batched' */
    cpy_r_r145 = CPyDict_GetItem(cpy_r_r143, cpy_r_r144);
    if (unlikely(cpy_r_r145 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 23, CPyStatic_globals);
        goto CPyL238;
    }
    cpy_r_r146 = CPyStatics[29]; /* 2 */
    PyObject *cpy_r_r147[2] = {cpy_r_r142, cpy_r_r146};
    cpy_r_r148 = (PyObject **)&cpy_r_r147;
    cpy_r_r149 = _PyObject_Vectorcall(cpy_r_r145, cpy_r_r148, 2, 0);
    CPy_DECREF(cpy_r_r145);
    if (unlikely(cpy_r_r149 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 23, CPyStatic_globals);
        goto CPyL238;
    }
    CPy_DECREF(cpy_r_r142);
    cpy_r_r150 = PyObject_GetIter(cpy_r_r149);
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 23, CPyStatic_globals);
        goto CPyL239;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__7 != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__7);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__7 = cpy_r_r149;
    cpy_r_r151 = 1;
    if (unlikely(!cpy_r_r151)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL240;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__8 != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__8);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__8 = cpy_r_r150;
    cpy_r_r152 = 1;
    if (unlikely(!cpy_r_r152)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL211;
    }
CPyL98: ;
    cpy_r_r153 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__8;
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__8", 23, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r153);
CPyL99: ;
    cpy_r_r154 = PyIter_Next(cpy_r_r153);
    CPy_DECREF(cpy_r_r153);
    if (cpy_r_r154 == NULL) {
        goto CPyL163;
    } else
        goto CPyL241;
CPyL100: ;
    if (likely(PyTuple_Check(cpy_r_r154)))
        cpy_r_r155 = cpy_r_r154;
    else {
        CPy_TypeErrorTraceback("comp9.py", "compact_files", 23, CPyStatic_globals, "tuple", cpy_r_r154);
        goto CPyL242;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_two_blocks != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_two_blocks);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_two_blocks = cpy_r_r155;
    cpy_r_r156 = 1;
    if (unlikely(!cpy_r_r156)) {
        CPy_AddTraceback("comp9.py", "compact_files", 23, CPyStatic_globals);
        goto CPyL242;
    }
    cpy_r_r157 = ((comp9___compact_files_envObject *)cpy_r_r2)->_two_blocks;
    if (unlikely(cpy_r_r157 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "two_blocks", 24, CPyStatic_globals);
        goto CPyL242;
    }
    CPy_INCREF(cpy_r_r157);
CPyL103: ;
    cpy_r_r158 = CPySequenceTuple_GetItem(cpy_r_r157, 0);
    CPy_DECREF(cpy_r_r157);
    if (unlikely(cpy_r_r158 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 24, CPyStatic_globals);
        goto CPyL242;
    }
    PyObject *__tmp11;
    if (unlikely(!(PyTuple_Check(cpy_r_r158) && PyTuple_GET_SIZE(cpy_r_r158) == 2))) {
        __tmp11 = NULL;
        goto __LL12;
    }
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r158, 0))))
        __tmp11 = PyTuple_GET_ITEM(cpy_r_r158, 0);
    else {
        __tmp11 = NULL;
    }
    if (__tmp11 == NULL) goto __LL12;
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r158, 1))))
        __tmp11 = PyTuple_GET_ITEM(cpy_r_r158, 1);
    else {
        __tmp11 = NULL;
    }
    if (__tmp11 == NULL) goto __LL12;
    __tmp11 = cpy_r_r158;
__LL12: ;
    if (unlikely(__tmp11 == NULL)) {
        CPy_TypeError("tuple[int, int]", cpy_r_r158); cpy_r_r159 = (tuple_T2II) { CPY_INT_TAG, CPY_INT_TAG };
    } else {
        PyObject *__tmp13 = PyTuple_GET_ITEM(cpy_r_r158, 0);
        CPyTagged __tmp14;
        if (likely(PyLong_Check(__tmp13)))
            __tmp14 = CPyTagged_FromObject(__tmp13);
        else {
            CPy_TypeError("int", __tmp13); __tmp14 = CPY_INT_TAG;
        }
        cpy_r_r159.f0 = __tmp14;
        PyObject *__tmp15 = PyTuple_GET_ITEM(cpy_r_r158, 1);
        CPyTagged __tmp16;
        if (likely(PyLong_Check(__tmp15)))
            __tmp16 = CPyTagged_FromObject(__tmp15);
        else {
            CPy_TypeError("int", __tmp15); __tmp16 = CPY_INT_TAG;
        }
        cpy_r_r159.f1 = __tmp16;
    }
    CPy_DECREF(cpy_r_r158);
    if (unlikely(cpy_r_r159.f0 == CPY_INT_TAG)) {
        CPy_AddTraceback("comp9.py", "compact_files", 24, CPyStatic_globals);
        goto CPyL242;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_file_block.f0 != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_file_block.f0);
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_file_block.f1);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_file_block = cpy_r_r159;
    cpy_r_r160 = 1;
    if (unlikely(!cpy_r_r160)) {
        CPy_AddTraceback("comp9.py", "compact_files", 24, CPyStatic_globals);
        goto CPyL242;
    }
    cpy_r_r161 = ((comp9___compact_files_envObject *)cpy_r_r2)->_file_block;
    if (unlikely(cpy_r_r161.f0 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "file_block", 25, CPyStatic_globals);
        goto CPyL242;
    }
    CPyTagged_INCREF(cpy_r_r161.f0);
    CPyTagged_INCREF(cpy_r_r161.f1);
CPyL107: ;
    cpy_r_r162 = cpy_r_r161.f0;
    cpy_r_r163 = cpy_r_r162;
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_file_id != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_file_id);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_file_id = cpy_r_r163;
    cpy_r_r164 = 1;
    if (unlikely(!cpy_r_r164)) {
        CPy_AddTraceback("comp9.py", "compact_files", 25, CPyStatic_globals);
        goto CPyL243;
    }
    cpy_r_r165 = cpy_r_r161.f1;
    cpy_r_r166 = cpy_r_r165;
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_file_count != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_file_count);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_file_count = cpy_r_r166;
    cpy_r_r167 = 1;
    if (unlikely(!cpy_r_r167)) {
        CPy_AddTraceback("comp9.py", "compact_files", 25, CPyStatic_globals);
        goto CPyL243;
    }
    cpy_r_r168 = ((comp9___compact_files_envObject *)cpy_r_r2)->_file_id;
    if (unlikely(cpy_r_r168 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "file_id", 26, CPyStatic_globals);
        goto CPyL242;
    }
    CPyTagged_INCREF(cpy_r_r168);
CPyL110: ;
    cpy_r_r169 = ((comp9___compact_files_envObject *)cpy_r_r2)->_file_count;
    if (unlikely(cpy_r_r169 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "file_count", 26, CPyStatic_globals);
        goto CPyL244;
    }
    CPyTagged_INCREF(cpy_r_r169);
CPyL111: ;
    cpy_r_r170.f0 = cpy_r_r168;
    cpy_r_r170.f1 = cpy_r_r169;
    cpy_r_r171 = PyTuple_New(2);
    if (unlikely(cpy_r_r171 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp17 = CPyTagged_StealAsObject(cpy_r_r170.f0);
    PyTuple_SET_ITEM(cpy_r_r171, 0, __tmp17);
    PyObject *__tmp18 = CPyTagged_StealAsObject(cpy_r_r170.f1);
    PyTuple_SET_ITEM(cpy_r_r171, 1, __tmp18);
    if (((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_next_label__ = 2;
    cpy_r_r172 = 1;
    CPy_DECREF(cpy_r_r2);
    if (unlikely(!cpy_r_r172)) {
        CPy_AddTraceback("comp9.py", "compact_files", 26, CPyStatic_globals);
        goto CPyL245;
    }
    return cpy_r_r171;
CPyL113: ;
    cpy_r_r173 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r174 = cpy_r_type != cpy_r_r173;
    if (cpy_r_r174) {
        goto CPyL246;
    } else
        goto CPyL116;
CPyL114: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("comp9.py", "compact_files", 26, CPyStatic_globals);
        goto CPyL209;
    }
    CPy_Unreachable();
CPyL116: ;
    cpy_r_r175 = ((comp9___compact_files_envObject *)cpy_r_r2)->_two_blocks;
    if (unlikely(cpy_r_r175 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "two_blocks", 28, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r175);
CPyL117: ;
    cpy_r_r176 = (CPyPtr)&((PyVarObject *)cpy_r_r175)->ob_size;
    cpy_r_r177 = *(int64_t *)cpy_r_r176;
    CPy_DECREF(cpy_r_r175);
    cpy_r_r178 = cpy_r_r177 << 1;
    cpy_r_r179 = (Py_ssize_t)cpy_r_r178 < (Py_ssize_t)4;
    if (cpy_r_r179) goto CPyL98;
    cpy_r_r180 = ((comp9___compact_files_envObject *)cpy_r_r2)->_two_blocks;
    if (unlikely(cpy_r_r180 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "two_blocks", 31, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r180);
CPyL119: ;
    cpy_r_r181 = CPySequenceTuple_GetItem(cpy_r_r180, 2);
    CPy_DECREF(cpy_r_r180);
    if (unlikely(cpy_r_r181 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 31, CPyStatic_globals);
        goto CPyL211;
    }
    PyObject *__tmp19;
    if (unlikely(!(PyTuple_Check(cpy_r_r181) && PyTuple_GET_SIZE(cpy_r_r181) == 2))) {
        __tmp19 = NULL;
        goto __LL20;
    }
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r181, 0))))
        __tmp19 = PyTuple_GET_ITEM(cpy_r_r181, 0);
    else {
        __tmp19 = NULL;
    }
    if (__tmp19 == NULL) goto __LL20;
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r181, 1))))
        __tmp19 = PyTuple_GET_ITEM(cpy_r_r181, 1);
    else {
        __tmp19 = NULL;
    }
    if (__tmp19 == NULL) goto __LL20;
    __tmp19 = cpy_r_r181;
__LL20: ;
    if (unlikely(__tmp19 == NULL)) {
        CPy_TypeError("tuple[int, int]", cpy_r_r181); cpy_r_r182 = (tuple_T2II) { CPY_INT_TAG, CPY_INT_TAG };
    } else {
        PyObject *__tmp21 = PyTuple_GET_ITEM(cpy_r_r181, 0);
        CPyTagged __tmp22;
        if (likely(PyLong_Check(__tmp21)))
            __tmp22 = CPyTagged_FromObject(__tmp21);
        else {
            CPy_TypeError("int", __tmp21); __tmp22 = CPY_INT_TAG;
        }
        cpy_r_r182.f0 = __tmp22;
        PyObject *__tmp23 = PyTuple_GET_ITEM(cpy_r_r181, 1);
        CPyTagged __tmp24;
        if (likely(PyLong_Check(__tmp23)))
            __tmp24 = CPyTagged_FromObject(__tmp23);
        else {
            CPy_TypeError("int", __tmp23); __tmp24 = CPY_INT_TAG;
        }
        cpy_r_r182.f1 = __tmp24;
    }
    CPy_DECREF(cpy_r_r181);
    if (unlikely(cpy_r_r182.f0 == CPY_INT_TAG)) {
        CPy_AddTraceback("comp9.py", "compact_files", 31, CPyStatic_globals);
        goto CPyL211;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_free_block.f0 != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_free_block.f0);
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_free_block.f1);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_free_block = cpy_r_r182;
    cpy_r_r183 = 1;
    if (unlikely(!cpy_r_r183)) {
        CPy_AddTraceback("comp9.py", "compact_files", 31, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r184 = ((comp9___compact_files_envObject *)cpy_r_r2)->_free_block;
    if (unlikely(cpy_r_r184.f0 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "free_block", 33, CPyStatic_globals);
        goto CPyL211;
    }
    CPyTagged_INCREF(cpy_r_r184.f0);
    CPyTagged_INCREF(cpy_r_r184.f1);
CPyL123: ;
    cpy_r_r185 = cpy_r_r184.f0;
    cpy_r_r186 = cpy_r_r185;
    cpy_r_r187 = CPyTagged_StealAsObject(cpy_r_r186);
    if (((comp9___compact_files_envObject *)cpy_r_r2)->__ != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->__);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->__ = cpy_r_r187;
    cpy_r_r188 = 1;
    if (unlikely(!cpy_r_r188)) {
        CPy_AddTraceback("comp9.py", "compact_files", 33, CPyStatic_globals);
        goto CPyL247;
    }
    cpy_r_r189 = cpy_r_r184.f1;
    cpy_r_r190 = cpy_r_r189;
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_free_count != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_free_count);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_free_count = cpy_r_r190;
    cpy_r_r191 = 1;
    if (unlikely(!cpy_r_r191)) {
        CPy_AddTraceback("comp9.py", "compact_files", 33, CPyStatic_globals);
        goto CPyL247;
    }
CPyL125: ;
    cpy_r_r192 = ((comp9___compact_files_envObject *)cpy_r_r2)->_free_count;
    if (unlikely(cpy_r_r192 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "free_count", 34, CPyStatic_globals);
        goto CPyL211;
    }
    CPyTagged_INCREF(cpy_r_r192);
CPyL126: ;
    cpy_r_r193 = cpy_r_r192 != 0;
    CPyTagged_DECREF(cpy_r_r192);
    if (cpy_r_r193) {
        goto CPyL248;
    } else
        goto CPyL98;
CPyL127: ;
    cpy_r_r194 = ((comp9___compact_files_envObject *)cpy_r_r2)->_aug_freedisk;
    if (unlikely(cpy_r_r194 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "aug_freedisk", 35, CPyStatic_globals);
        goto CPyL242;
    }
    CPy_INCREF(cpy_r_r194);
CPyL128: ;
    cpy_r_r195 = CPyList_PopLast(cpy_r_r194);
    CPy_DECREF(cpy_r_r194);
    if (unlikely(cpy_r_r195 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 35, CPyStatic_globals);
        goto CPyL242;
    }
    PyObject *__tmp25;
    if (unlikely(!(PyTuple_Check(cpy_r_r195) && PyTuple_GET_SIZE(cpy_r_r195) == 2))) {
        __tmp25 = NULL;
        goto __LL26;
    }
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r195, 0))))
        __tmp25 = PyTuple_GET_ITEM(cpy_r_r195, 0);
    else {
        __tmp25 = NULL;
    }
    if (__tmp25 == NULL) goto __LL26;
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r195, 1))))
        __tmp25 = PyTuple_GET_ITEM(cpy_r_r195, 1);
    else {
        __tmp25 = NULL;
    }
    if (__tmp25 == NULL) goto __LL26;
    __tmp25 = cpy_r_r195;
__LL26: ;
    if (unlikely(__tmp25 == NULL)) {
        CPy_TypeError("tuple[int, int]", cpy_r_r195); cpy_r_r196 = (tuple_T2II) { CPY_INT_TAG, CPY_INT_TAG };
    } else {
        PyObject *__tmp27 = PyTuple_GET_ITEM(cpy_r_r195, 0);
        CPyTagged __tmp28;
        if (likely(PyLong_Check(__tmp27)))
            __tmp28 = CPyTagged_FromObject(__tmp27);
        else {
            CPy_TypeError("int", __tmp27); __tmp28 = CPY_INT_TAG;
        }
        cpy_r_r196.f0 = __tmp28;
        PyObject *__tmp29 = PyTuple_GET_ITEM(cpy_r_r195, 1);
        CPyTagged __tmp30;
        if (likely(PyLong_Check(__tmp29)))
            __tmp30 = CPyTagged_FromObject(__tmp29);
        else {
            CPy_TypeError("int", __tmp29); __tmp30 = CPY_INT_TAG;
        }
        cpy_r_r196.f1 = __tmp30;
    }
    CPy_DECREF(cpy_r_r195);
    if (unlikely(cpy_r_r196.f0 == CPY_INT_TAG)) {
        CPy_AddTraceback("comp9.py", "compact_files", 35, CPyStatic_globals);
        goto CPyL242;
    }
    cpy_r_r197 = cpy_r_r196.f0;
    cpy_r_r198 = cpy_r_r197;
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_fill_id != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_fill_id);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_fill_id = cpy_r_r198;
    cpy_r_r199 = 1;
    if (unlikely(!cpy_r_r199)) {
        CPy_AddTraceback("comp9.py", "compact_files", 35, CPyStatic_globals);
        goto CPyL249;
    }
    cpy_r_r200 = cpy_r_r196.f1;
    cpy_r_r201 = cpy_r_r200;
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_fill_count != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_fill_count);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_fill_count = cpy_r_r201;
    cpy_r_r202 = 1;
    if (unlikely(!cpy_r_r202)) {
        CPy_AddTraceback("comp9.py", "compact_files", 35, CPyStatic_globals);
        goto CPyL249;
    }
    cpy_r_r203 = ((comp9___compact_files_envObject *)cpy_r_r2)->_fill_count;
    if (unlikely(cpy_r_r203 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "fill_count", 36, CPyStatic_globals);
        goto CPyL242;
    }
    CPyTagged_INCREF(cpy_r_r203);
CPyL133: ;
    cpy_r_r204 = ((comp9___compact_files_envObject *)cpy_r_r2)->_free_count;
    if (unlikely(cpy_r_r204 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "free_count", 36, CPyStatic_globals);
        goto CPyL250;
    }
    CPyTagged_INCREF(cpy_r_r204);
CPyL134: ;
    cpy_r_r205 = cpy_r_r204 & 1;
    cpy_r_r206 = cpy_r_r205 != 0;
    if (cpy_r_r206) goto CPyL136;
    cpy_r_r207 = cpy_r_r203 & 1;
    cpy_r_r208 = cpy_r_r207 != 0;
    if (!cpy_r_r208) goto CPyL137;
CPyL136: ;
    cpy_r_r209 = CPyTagged_IsLt_(cpy_r_r204, cpy_r_r203);
    if (cpy_r_r209) {
        goto CPyL251;
    } else
        goto CPyL252;
CPyL137: ;
    cpy_r_r210 = (Py_ssize_t)cpy_r_r204 < (Py_ssize_t)cpy_r_r203;
    if (cpy_r_r210) {
        goto CPyL251;
    } else
        goto CPyL252;
CPyL138: ;
    cpy_r_r211 = cpy_r_r204;
    goto CPyL140;
CPyL139: ;
    cpy_r_r211 = cpy_r_r203;
CPyL140: ;
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_can_fill != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_can_fill);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_can_fill = cpy_r_r211;
    cpy_r_r212 = 1;
    if (unlikely(!cpy_r_r212)) {
        CPy_AddTraceback("comp9.py", "compact_files", 36, CPyStatic_globals);
        goto CPyL242;
    }
    cpy_r_r213 = ((comp9___compact_files_envObject *)cpy_r_r2)->_fill_id;
    if (unlikely(cpy_r_r213 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "fill_id", 37, CPyStatic_globals);
        goto CPyL242;
    }
    CPyTagged_INCREF(cpy_r_r213);
CPyL142: ;
    cpy_r_r214 = ((comp9___compact_files_envObject *)cpy_r_r2)->_can_fill;
    if (unlikely(cpy_r_r214 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "can_fill", 37, CPyStatic_globals);
        goto CPyL253;
    }
    CPyTagged_INCREF(cpy_r_r214);
CPyL143: ;
    cpy_r_r215.f0 = cpy_r_r213;
    cpy_r_r215.f1 = cpy_r_r214;
    cpy_r_r216 = PyTuple_New(2);
    if (unlikely(cpy_r_r216 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp31 = CPyTagged_StealAsObject(cpy_r_r215.f0);
    PyTuple_SET_ITEM(cpy_r_r216, 0, __tmp31);
    PyObject *__tmp32 = CPyTagged_StealAsObject(cpy_r_r215.f1);
    PyTuple_SET_ITEM(cpy_r_r216, 1, __tmp32);
    if (((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_next_label__ = 4;
    cpy_r_r217 = 1;
    CPy_DECREF(cpy_r_r2);
    if (unlikely(!cpy_r_r217)) {
        CPy_AddTraceback("comp9.py", "compact_files", 37, CPyStatic_globals);
        goto CPyL254;
    }
    return cpy_r_r216;
CPyL145: ;
    cpy_r_r218 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r219 = cpy_r_type != cpy_r_r218;
    if (cpy_r_r219) {
        goto CPyL255;
    } else
        goto CPyL148;
CPyL146: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("comp9.py", "compact_files", 37, CPyStatic_globals);
        goto CPyL209;
    }
    CPy_Unreachable();
CPyL148: ;
    cpy_r_r220 = ((comp9___compact_files_envObject *)cpy_r_r2)->_free_count;
    if (unlikely(cpy_r_r220 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "free_count", 39, CPyStatic_globals);
        goto CPyL211;
    }
    CPyTagged_INCREF(cpy_r_r220);
CPyL149: ;
    cpy_r_r221 = ((comp9___compact_files_envObject *)cpy_r_r2)->_can_fill;
    if (unlikely(cpy_r_r221 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "can_fill", 39, CPyStatic_globals);
        goto CPyL256;
    }
    CPyTagged_INCREF(cpy_r_r221);
CPyL150: ;
    cpy_r_r222 = CPyTagged_Subtract(cpy_r_r220, cpy_r_r221);
    CPyTagged_DECREF(cpy_r_r220);
    CPyTagged_DECREF(cpy_r_r221);
    if (((comp9___compact_files_envObject *)cpy_r_r2)->_free_count != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->_free_count);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->_free_count = cpy_r_r222;
    cpy_r_r223 = 1;
    if (unlikely(!cpy_r_r223)) {
        CPy_AddTraceback("comp9.py", "compact_files", 39, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r224 = ((comp9___compact_files_envObject *)cpy_r_r2)->_fill_count;
    if (unlikely(cpy_r_r224 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "fill_count", 41, CPyStatic_globals);
        goto CPyL211;
    }
    CPyTagged_INCREF(cpy_r_r224);
CPyL152: ;
    cpy_r_r225 = ((comp9___compact_files_envObject *)cpy_r_r2)->_can_fill;
    if (unlikely(cpy_r_r225 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "can_fill", 41, CPyStatic_globals);
        goto CPyL257;
    }
    CPyTagged_INCREF(cpy_r_r225);
CPyL153: ;
    cpy_r_r226 = cpy_r_r224 & 1;
    cpy_r_r227 = cpy_r_r226 != 0;
    if (cpy_r_r227) goto CPyL155;
    cpy_r_r228 = cpy_r_r225 & 1;
    cpy_r_r229 = cpy_r_r228 != 0;
    if (!cpy_r_r229) goto CPyL156;
CPyL155: ;
    cpy_r_r230 = CPyTagged_IsLt_(cpy_r_r225, cpy_r_r224);
    cpy_r_r231 = cpy_r_r230;
    goto CPyL157;
CPyL156: ;
    cpy_r_r232 = (Py_ssize_t)cpy_r_r224 > (Py_ssize_t)cpy_r_r225;
    cpy_r_r231 = cpy_r_r232;
CPyL157: ;
    CPyTagged_DECREF(cpy_r_r224);
    CPyTagged_DECREF(cpy_r_r225);
    if (!cpy_r_r231) goto CPyL125;
    cpy_r_r233 = ((comp9___compact_files_envObject *)cpy_r_r2)->_aug_freedisk;
    if (unlikely(cpy_r_r233 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "aug_freedisk", 42, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r233);
CPyL159: ;
    cpy_r_r234 = ((comp9___compact_files_envObject *)cpy_r_r2)->_fill_id;
    if (unlikely(cpy_r_r234 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "fill_id", 42, CPyStatic_globals);
        goto CPyL258;
    }
    CPyTagged_INCREF(cpy_r_r234);
CPyL160: ;
    cpy_r_r235 = ((comp9___compact_files_envObject *)cpy_r_r2)->_fill_count;
    if (unlikely(cpy_r_r235 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "fill_count", 42, CPyStatic_globals);
        goto CPyL259;
    }
    CPyTagged_INCREF(cpy_r_r235);
CPyL161: ;
    cpy_r_r236 = ((comp9___compact_files_envObject *)cpy_r_r2)->_can_fill;
    if (unlikely(cpy_r_r236 == CPY_INT_TAG)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "can_fill", 42, CPyStatic_globals);
        goto CPyL260;
    }
    CPyTagged_INCREF(cpy_r_r236);
CPyL162: ;
    cpy_r_r237 = CPyTagged_Subtract(cpy_r_r235, cpy_r_r236);
    CPyTagged_DECREF(cpy_r_r235);
    CPyTagged_DECREF(cpy_r_r236);
    cpy_r_r238.f0 = cpy_r_r234;
    cpy_r_r238.f1 = cpy_r_r237;
    cpy_r_r239 = PyTuple_New(2);
    if (unlikely(cpy_r_r239 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp33 = CPyTagged_StealAsObject(cpy_r_r238.f0);
    PyTuple_SET_ITEM(cpy_r_r239, 0, __tmp33);
    PyObject *__tmp34 = CPyTagged_StealAsObject(cpy_r_r238.f1);
    PyTuple_SET_ITEM(cpy_r_r239, 1, __tmp34);
    cpy_r_r240 = PyList_Append(cpy_r_r233, cpy_r_r239);
    CPy_DECREF(cpy_r_r233);
    CPy_DECREF(cpy_r_r239);
    cpy_r_r241 = cpy_r_r240 >= 0;
    if (unlikely(!cpy_r_r241)) {
        CPy_AddTraceback("comp9.py", "compact_files", 42, CPyStatic_globals);
        goto CPyL211;
    } else
        goto CPyL125;
CPyL163: ;
    cpy_r_r242 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r242)) {
        CPy_AddTraceback("comp9.py", "compact_files", 23, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r243 = ((comp9___compact_files_envObject *)cpy_r_r2)->_aug_freedisk;
    if (unlikely(cpy_r_r243 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "aug_freedisk", 44, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r243);
CPyL165: ;
    cpy_r_r244 = PyObject_GetIter(cpy_r_r243);
    CPy_DECREF(cpy_r_r243);
    if (unlikely(cpy_r_r244 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 44, CPyStatic_globals);
        goto CPyL211;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__9 != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__9);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__9 = cpy_r_r244;
    cpy_r_r245 = 1;
    if (unlikely(!cpy_r_r245)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r246 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__9;
    if (unlikely(cpy_r_r246 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_INCREF(cpy_r_r246);
CPyL168: ;
    cpy_r_r247 = CPyIter_Next(cpy_r_r246);
    CPy_DECREF(cpy_r_r246);
    if (cpy_r_r247 == NULL) {
        goto CPyL261;
    } else
        goto CPyL171;
CPyL169: ;
    cpy_r_r248 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r248 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 44, CPyStatic_globals);
        goto CPyL242;
    }
    cpy_r_r249 = cpy_r_r248;
    CPy_DECREF(cpy_r_r249);
    goto CPyL200;
CPyL171: ;
    cpy_r_r250 = cpy_r_r247;
CPyL172: ;
    if (((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_next_label__ = 6;
    cpy_r_r251 = 1;
    if (unlikely(!cpy_r_r251)) {
        CPy_AddTraceback("comp9.py", "compact_files", 44, CPyStatic_globals);
        goto CPyL262;
    } else
        goto CPyL263;
CPyL173: ;
    return cpy_r_r250;
CPyL174: ;
    cpy_r_r252 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r253 = cpy_r_type != cpy_r_r252;
    if (!cpy_r_r253) goto CPyL177;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("comp9.py", "compact_files", 44, CPyStatic_globals);
        goto CPyL178;
    } else
        goto CPyL264;
CPyL176: ;
    CPy_Unreachable();
CPyL177: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL195;
CPyL178: ;
    cpy_r_r254 = CPy_CatchError();
    if (((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__10.f0 != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__10.f0);
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__10.f1);
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__10.f2);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__10 = cpy_r_r254;
    cpy_r_r255 = 1;
    if (unlikely(!cpy_r_r255)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL265;
    }
    cpy_r_r256 = (PyObject **)&cpy_r_r1;
    cpy_r_r257 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__9;
    if (unlikely(cpy_r_r257 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL265;
    }
    CPy_INCREF(cpy_r_r257);
CPyL180: ;
    cpy_r_r258 = CPy_YieldFromErrorHandle(cpy_r_r257, cpy_r_r256);
    CPy_DecRef(cpy_r_r257);
    if (unlikely(cpy_r_r258 == 2)) {
        CPy_AddTraceback("comp9.py", "compact_files", 44, CPyStatic_globals);
        goto CPyL265;
    }
    if (cpy_r_r258) goto CPyL187;
    if (cpy_r_r1 != NULL) goto CPyL185;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r259 = 0;
    if (unlikely(!cpy_r_r259)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL192;
    } else
        goto CPyL266;
CPyL184: ;
    CPy_Unreachable();
CPyL185: ;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r250 = cpy_r_r1;
    cpy_r_r260 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__10;
    if (unlikely(cpy_r_r260.f0 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL267;
    }
    CPy_INCREF(cpy_r_r260.f0);
    CPy_INCREF(cpy_r_r260.f1);
    CPy_INCREF(cpy_r_r260.f2);
CPyL186: ;
    CPy_RestoreExcInfo(cpy_r_r260);
    CPy_DecRef(cpy_r_r260.f0);
    CPy_DecRef(cpy_r_r260.f1);
    CPy_DecRef(cpy_r_r260.f2);
    goto CPyL172;
CPyL187: ;
    if (cpy_r_r1 != NULL) goto CPyL190;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"\" referenced before assignment");
    cpy_r_r261 = 0;
    if (unlikely(!cpy_r_r261)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL192;
    } else
        goto CPyL268;
CPyL189: ;
    CPy_Unreachable();
CPyL190: ;
    cpy_r_r249 = cpy_r_r1;
    CPy_DecRef(cpy_r_r249);
    cpy_r_r262 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__10;
    if (unlikely(cpy_r_r262.f0 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL192;
    }
    CPy_INCREF(cpy_r_r262.f0);
    CPy_INCREF(cpy_r_r262.f1);
    CPy_INCREF(cpy_r_r262.f2);
CPyL191: ;
    CPy_RestoreExcInfo(cpy_r_r262);
    CPy_DecRef(cpy_r_r262.f0);
    CPy_DecRef(cpy_r_r262.f1);
    CPy_DecRef(cpy_r_r262.f2);
    goto CPyL200;
CPyL192: ;
    cpy_r_r263 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__10;
    if (unlikely(cpy_r_r263.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__10' of 'compact_files_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r263.f0);
        CPy_INCREF(cpy_r_r263.f1);
        CPy_INCREF(cpy_r_r263.f2);
    }
    CPy_DecRef(cpy_r_r2);
    if (unlikely(cpy_r_r263.f0 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", -1, CPyStatic_globals);
        goto CPyL209;
    }
CPyL193: ;
    CPy_RestoreExcInfo(cpy_r_r263);
    CPy_DecRef(cpy_r_r263.f0);
    CPy_DecRef(cpy_r_r263.f1);
    CPy_DecRef(cpy_r_r263.f2);
    cpy_r_r264 = CPy_KeepPropagating();
    if (!cpy_r_r264) goto CPyL209;
    CPy_Unreachable();
CPyL195: ;
    cpy_r_r265 = ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_temp__9;
    if (unlikely(cpy_r_r265 == NULL)) {
        CPy_AttributeError("comp9.py", "compact_files", "compact_files_env", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL269;
    }
    CPy_INCREF(cpy_r_r265);
CPyL196: ;
    cpy_r_r266 = CPyIter_Send(cpy_r_r265, cpy_r_arg);
    CPy_DECREF(cpy_r_r265);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r266 == NULL) goto CPyL270;
    cpy_r_r250 = cpy_r_r266;
    goto CPyL172;
CPyL198: ;
    cpy_r_r267 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r267 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 44, CPyStatic_globals);
        goto CPyL242;
    }
    cpy_r_r249 = cpy_r_r267;
    CPy_DECREF(cpy_r_r249);
CPyL200: ;
    cpy_r_r268 = Py_None;
    if (((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((comp9___compact_files_envObject *)cpy_r_r2)->___mypyc_next_label__ = -2;
    cpy_r_r269 = 1;
    CPy_DECREF(cpy_r_r2);
    if (unlikely(!cpy_r_r269)) {
        CPy_AddTraceback("comp9.py", "compact_files", 8, CPyStatic_globals);
        goto CPyL209;
    }
    CPyGen_SetStopIterationValue(cpy_r_r268);
    if (!0) goto CPyL209;
    CPy_Unreachable();
CPyL203: ;
    cpy_r_r270 = cpy_r_r3 == 0;
    if (cpy_r_r270) goto CPyL271;
    cpy_r_r271 = cpy_r_r3 == 2;
    if (cpy_r_r271) goto CPyL272;
    cpy_r_r272 = cpy_r_r3 == 4;
    if (cpy_r_r272) goto CPyL273;
    cpy_r_r273 = cpy_r_r3 == 6;
    CPyTagged_DECREF(cpy_r_r3);
    if (cpy_r_r273) {
        goto CPyL174;
    } else
        goto CPyL274;
CPyL207: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r274 = 0;
    if (unlikely(!cpy_r_r274)) {
        CPy_AddTraceback("comp9.py", "compact_files", 8, CPyStatic_globals);
        goto CPyL209;
    }
    CPy_Unreachable();
CPyL209: ;
    cpy_r_r275 = NULL;
    return cpy_r_r275;
CPyL210: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL209;
CPyL211: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL209;
CPyL212: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL3;
CPyL213: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r7);
    goto CPyL209;
CPyL214: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r16);
    goto CPyL209;
CPyL215: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r23);
    goto CPyL209;
CPyL216: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r24);
    goto CPyL209;
CPyL217: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_r31);
    goto CPyL209;
CPyL218: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_r31);
    CPy_DecRef(cpy_r_r32);
    goto CPyL209;
CPyL219: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_r31);
    CPy_DecRef(cpy_r_r38);
    goto CPyL209;
CPyL220: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_r46);
    goto CPyL209;
CPyL221: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r50);
    goto CPyL209;
CPyL222: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r56);
    goto CPyL209;
CPyL223: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r59);
    goto CPyL209;
CPyL224: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r59);
    CPy_DecRef(cpy_r_r60);
    goto CPyL209;
CPyL225: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r63);
    goto CPyL209;
CPyL226: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r79);
    goto CPyL209;
CPyL227: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r85);
    goto CPyL209;
CPyL228: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r87.f0);
    CPyTagged_DecRef(cpy_r_r87.f1);
    goto CPyL209;
CPyL229: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r103);
    goto CPyL209;
CPyL230: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r103);
    CPyTagged_DecRef(cpy_r_r104);
    goto CPyL209;
CPyL231: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r103);
    CPy_DecRef(cpy_r_r108);
    goto CPyL209;
CPyL232: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r112);
    goto CPyL209;
CPyL233: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r113);
    goto CPyL209;
CPyL234: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r118.f0);
    CPyTagged_DecRef(cpy_r_r118.f1);
    goto CPyL209;
CPyL235: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r124);
    goto CPyL209;
CPyL236: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r126.f0);
    CPyTagged_DecRef(cpy_r_r126.f1);
    goto CPyL209;
CPyL237: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r132);
    goto CPyL209;
CPyL238: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r142);
    goto CPyL209;
CPyL239: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r149);
    goto CPyL209;
CPyL240: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r150);
    goto CPyL209;
CPyL241: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL100;
CPyL242: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL209;
CPyL243: ;
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r161.f0);
    CPyTagged_DecRef(cpy_r_r161.f1);
    goto CPyL209;
CPyL244: ;
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r168);
    goto CPyL209;
CPyL245: ;
    CPy_DecRef(cpy_r_r171);
    goto CPyL209;
CPyL246: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL114;
CPyL247: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r184.f0);
    CPyTagged_DecRef(cpy_r_r184.f1);
    goto CPyL209;
CPyL248: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL127;
CPyL249: ;
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r196.f0);
    CPyTagged_DecRef(cpy_r_r196.f1);
    goto CPyL209;
CPyL250: ;
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r203);
    goto CPyL209;
CPyL251: ;
    CPyTagged_DECREF(cpy_r_r203);
    goto CPyL138;
CPyL252: ;
    CPyTagged_DECREF(cpy_r_r204);
    goto CPyL139;
CPyL253: ;
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r213);
    goto CPyL209;
CPyL254: ;
    CPy_DecRef(cpy_r_r216);
    goto CPyL209;
CPyL255: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL146;
CPyL256: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r220);
    goto CPyL209;
CPyL257: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r224);
    goto CPyL209;
CPyL258: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r233);
    goto CPyL209;
CPyL259: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r233);
    CPyTagged_DecRef(cpy_r_r234);
    goto CPyL209;
CPyL260: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r233);
    CPyTagged_DecRef(cpy_r_r234);
    CPyTagged_DecRef(cpy_r_r235);
    goto CPyL209;
CPyL261: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL169;
CPyL262: ;
    CPy_DecRef(cpy_r_r250);
    goto CPyL178;
CPyL263: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL173;
CPyL264: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL176;
CPyL265: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL192;
CPyL266: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL184;
CPyL267: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r250);
    goto CPyL192;
CPyL268: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL189;
CPyL269: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_arg);
    goto CPyL209;
CPyL270: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL198;
CPyL271: ;
    CPyTagged_DECREF(cpy_r_r3);
    goto CPyL2;
CPyL272: ;
    CPyTagged_DECREF(cpy_r_r3);
    goto CPyL113;
CPyL273: ;
    CPyTagged_DECREF(cpy_r_r3);
    goto CPyL145;
CPyL274: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r2);
    goto CPyL207;
}

PyObject *CPyPy_compact_files_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", "arg", 0};
    static CPyArg_Parser parser = {"OOOO:__mypyc_generator_helper__", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value;
    PyObject *obj_traceback;
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_type = obj_type;
    PyObject *arg_value = obj_value;
    PyObject *arg_traceback = obj_traceback;
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_compact_files_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("comp9.py", "compact_files", 8, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_compact_files_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_compact_files_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_compact_files_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_compact_files_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("comp9.compact_files_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_compact_files_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("comp9.py", "__next__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_compact_files_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_compact_files_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_compact_files_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_compact_files_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("comp9.compact_files_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_compact_files_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("comp9.py", "send", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_compact_files_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_compact_files_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_compact_files_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("comp9.compact_files_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_compact_files_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("comp9.py", "__iter__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_compact_files_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    if (cpy_r_value != NULL) goto CPyL7;
    CPy_INCREF(cpy_r_r0);
    cpy_r_value = cpy_r_r0;
CPyL2: ;
    if (cpy_r_traceback != NULL) goto CPyL8;
    CPy_INCREF(cpy_r_r0);
    cpy_r_traceback = cpy_r_r0;
CPyL4: ;
    cpy_r_r1 = CPyDef_compact_files_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
    CPy_DECREF(cpy_r_value);
    CPy_DECREF(cpy_r_traceback);
    if (cpy_r_r1 == NULL) goto CPyL6;
    return cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
CPyL7: ;
    CPy_INCREF(cpy_r_value);
    goto CPyL2;
CPyL8: ;
    CPy_INCREF(cpy_r_traceback);
    goto CPyL4;
}

PyObject *CPyPy_compact_files_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", 0};
    static CPyArg_Parser parser = {"O|OO:throw", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value = NULL;
    PyObject *obj_traceback = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_compact_files_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("comp9.compact_files_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_type = obj_type;
    PyObject *arg_value;
    if (obj_value == NULL) {
        arg_value = NULL;
    } else {
        arg_value = obj_value; 
    }
    PyObject *arg_traceback;
    if (obj_traceback == NULL) {
        arg_traceback = NULL;
    } else {
        arg_traceback = obj_traceback; 
    }
    PyObject *retval = CPyDef_compact_files_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("comp9.py", "throw", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_compact_files_gen___close(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T2OO cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[10]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef_compact_files_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[11]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp35 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp35);
    PyObject *__tmp36 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp36);
    cpy_r_r12 = CPy_ExceptionMatches(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r12) goto CPyL13;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    CPy_INCREF(cpy_r_r13);
    return cpy_r_r13;
CPyL6: ;
    CPy_Reraise();
    if (!0) goto CPyL10;
    CPy_Unreachable();
CPyL8: ;
    PyErr_SetString(PyExc_RuntimeError, "generator ignored GeneratorExit");
    cpy_r_r14 = 0;
    if (!cpy_r_r14) goto CPyL10;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL6;
}

PyObject *CPyPy_compact_files_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_compact_files_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("comp9.compact_files_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_compact_files_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("comp9.py", "close", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_compact_files(PyObject *cpy_r_string) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    cpy_r_r0 = CPyDef_compact_files_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 8, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_string);
    if (((comp9___compact_files_envObject *)cpy_r_r0)->_string != NULL) {
        CPy_DECREF(((comp9___compact_files_envObject *)cpy_r_r0)->_string);
    }
    ((comp9___compact_files_envObject *)cpy_r_r0)->_string = cpy_r_string;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("comp9.py", "compact_files", 8, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r2 = CPyDef_compact_files_gen();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("comp9.py", "compact_files", 8, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_INCREF(cpy_r_r0);
    if (((comp9___compact_files_genObject *)cpy_r_r2)->___mypyc_env__ != NULL) {
        CPy_DECREF(((comp9___compact_files_genObject *)cpy_r_r2)->___mypyc_env__);
    }
    ((comp9___compact_files_genObject *)cpy_r_r2)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("comp9.py", "compact_files", 8, CPyStatic_globals);
        goto CPyL8;
    }
    if (((comp9___compact_files_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((comp9___compact_files_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((comp9___compact_files_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r4 = 1;
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("comp9.py", "compact_files", 8, CPyStatic_globals);
        goto CPyL9;
    }
    return cpy_r_r2;
CPyL6: ;
    cpy_r_r5 = NULL;
    return cpy_r_r5;
CPyL7: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL6;
CPyL8: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    goto CPyL6;
CPyL9: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL6;
}

PyObject *CPyPy_compact_files(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"string", 0};
    static CPyArg_Parser parser = {"O:compact_files", kwlist, 0};
    PyObject *obj_string;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_string)) {
        return NULL;
    }
    PyObject *arg_string;
    if (likely(PyUnicode_Check(obj_string)))
        arg_string = obj_string;
    else {
        CPy_TypeError("str", obj_string); 
        goto fail;
    }
    PyObject *retval = CPyDef_compact_files(arg_string);
    return retval;
fail: ;
    CPy_AddTraceback("comp9.py", "compact_files", 8, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_calc_checksum(PyObject *cpy_r_filesystem) {
    CPyTagged cpy_r_i;
    CPyTagged cpy_r_chksum;
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    tuple_T2II cpy_r_r2;
    CPyTagged cpy_r_r3;
    CPyTagged cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    CPyTagged cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject **cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject **cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    CPyTagged cpy_r_r37;
    CPyTagged cpy_r_r38;
    char cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    cpy_r_i = 0;
    cpy_r_chksum = 0;
    cpy_r_r0 = PyObject_GetIter(cpy_r_filesystem);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("comp9.py", "calc_checksum", 50, CPyStatic_globals);
        goto CPyL18;
    }
CPyL1: ;
    cpy_r_r1 = PyIter_Next(cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL19;
    PyObject *__tmp37;
    if (unlikely(!(PyTuple_Check(cpy_r_r1) && PyTuple_GET_SIZE(cpy_r_r1) == 2))) {
        __tmp37 = NULL;
        goto __LL38;
    }
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r1, 0))))
        __tmp37 = PyTuple_GET_ITEM(cpy_r_r1, 0);
    else {
        __tmp37 = NULL;
    }
    if (__tmp37 == NULL) goto __LL38;
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r1, 1))))
        __tmp37 = PyTuple_GET_ITEM(cpy_r_r1, 1);
    else {
        __tmp37 = NULL;
    }
    if (__tmp37 == NULL) goto __LL38;
    __tmp37 = cpy_r_r1;
__LL38: ;
    if (unlikely(__tmp37 == NULL)) {
        CPy_TypeError("tuple[int, int]", cpy_r_r1); cpy_r_r2 = (tuple_T2II) { CPY_INT_TAG, CPY_INT_TAG };
    } else {
        PyObject *__tmp39 = PyTuple_GET_ITEM(cpy_r_r1, 0);
        CPyTagged __tmp40;
        if (likely(PyLong_Check(__tmp39)))
            __tmp40 = CPyTagged_FromObject(__tmp39);
        else {
            CPy_TypeError("int", __tmp39); __tmp40 = CPY_INT_TAG;
        }
        cpy_r_r2.f0 = __tmp40;
        PyObject *__tmp41 = PyTuple_GET_ITEM(cpy_r_r1, 1);
        CPyTagged __tmp42;
        if (likely(PyLong_Check(__tmp41)))
            __tmp42 = CPyTagged_FromObject(__tmp41);
        else {
            CPy_TypeError("int", __tmp41); __tmp42 = CPY_INT_TAG;
        }
        cpy_r_r2.f1 = __tmp42;
    }
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2.f0 == CPY_INT_TAG)) {
        CPy_AddTraceback("comp9.py", "calc_checksum", 50, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r3 = cpy_r_r2.f0;
    CPyTagged_INCREF(cpy_r_r3);
    cpy_r_r4 = cpy_r_r2.f1;
    CPyTagged_INCREF(cpy_r_r4);
    CPyTagged_DECREF(cpy_r_r2.f0);
    CPyTagged_DECREF(cpy_r_r2.f1);
    cpy_r_r5 = CPyStatic_globals;
    cpy_r_r6 = CPyStatics[12]; /* 'mul' */
    cpy_r_r7 = CPyDict_GetItem(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("comp9.py", "calc_checksum", 51, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r8 = CPyTagged_Add(cpy_r_r4, cpy_r_i);
    cpy_r_r9 = (PyObject *)&PyRange_Type;
    CPyTagged_INCREF(cpy_r_i);
    cpy_r_r10 = CPyTagged_StealAsObject(cpy_r_i);
    cpy_r_r11 = CPyTagged_StealAsObject(cpy_r_r8);
    PyObject *cpy_r_r12[2] = {cpy_r_r10, cpy_r_r11};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = _PyObject_Vectorcall(cpy_r_r9, cpy_r_r13, 2, 0);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("comp9.py", "calc_checksum", 51, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r11);
    if (likely(PyRange_Check(cpy_r_r14)))
        cpy_r_r15 = cpy_r_r14;
    else {
        CPy_TypeErrorTraceback("comp9.py", "calc_checksum", 51, CPyStatic_globals, "range", cpy_r_r14);
        goto CPyL23;
    }
    cpy_r_r16 = CPyStatic_globals;
    cpy_r_r17 = CPyStatics[13]; /* 'repeat' */
    cpy_r_r18 = CPyDict_GetItem(cpy_r_r16, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("comp9.py", "calc_checksum", 51, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r19 = CPyTagged_StealAsObject(cpy_r_r3);
    PyObject *cpy_r_r20[1] = {cpy_r_r19};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r18, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("comp9.py", "calc_checksum", 51, CPyStatic_globals);
        goto CPyL25;
    }
    CPy_DECREF(cpy_r_r19);
    cpy_r_r23 = CPyModule_builtins;
    cpy_r_r24 = CPyStatics[3]; /* 'map' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("comp9.py", "calc_checksum", 51, CPyStatic_globals);
        goto CPyL26;
    }
    PyObject *cpy_r_r26[3] = {cpy_r_r7, cpy_r_r15, cpy_r_r22};
    cpy_r_r27 = (PyObject **)&cpy_r_r26;
    cpy_r_r28 = _PyObject_Vectorcall(cpy_r_r25, cpy_r_r27, 3, 0);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("comp9.py", "calc_checksum", 51, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r15);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r29 = CPyModule_builtins;
    cpy_r_r30 = CPyStatics[5]; /* 'sum' */
    cpy_r_r31 = CPyObject_GetAttr(cpy_r_r29, cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("comp9.py", "calc_checksum", 51, CPyStatic_globals);
        goto CPyL27;
    }
    PyObject *cpy_r_r32[1] = {cpy_r_r28};
    cpy_r_r33 = (PyObject **)&cpy_r_r32;
    cpy_r_r34 = _PyObject_Vectorcall(cpy_r_r31, cpy_r_r33, 1, 0);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("comp9.py", "calc_checksum", 51, CPyStatic_globals);
        goto CPyL27;
    }
    CPy_DECREF(cpy_r_r28);
    cpy_r_r35 = CPyTagged_StealAsObject(cpy_r_chksum);
    cpy_r_r36 = PyNumber_InPlaceAdd(cpy_r_r35, cpy_r_r34);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("comp9.py", "calc_checksum", 51, CPyStatic_globals);
        goto CPyL28;
    }
    if (likely(PyLong_Check(cpy_r_r36)))
        cpy_r_r37 = CPyTagged_FromObject(cpy_r_r36);
    else {
        CPy_TypeError("int", cpy_r_r36); cpy_r_r37 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r37 == CPY_INT_TAG)) {
        CPy_AddTraceback("comp9.py", "calc_checksum", 51, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_chksum = cpy_r_r37;
    cpy_r_r38 = CPyTagged_Add(cpy_r_i, cpy_r_r4);
    CPyTagged_DECREF(cpy_r_i);
    CPyTagged_DECREF(cpy_r_r4);
    cpy_r_i = cpy_r_r38;
    goto CPyL1;
CPyL15: ;
    cpy_r_r39 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("comp9.py", "calc_checksum", 50, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r40 = CPyTagged_StealAsObject(cpy_r_chksum);
    return cpy_r_r40;
CPyL17: ;
    cpy_r_r41 = NULL;
    return cpy_r_r41;
CPyL18: ;
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_chksum);
    goto CPyL17;
CPyL19: ;
    CPyTagged_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_r0);
    goto CPyL15;
CPyL20: ;
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_chksum);
    CPy_DecRef(cpy_r_r0);
    goto CPyL17;
CPyL21: ;
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_chksum);
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r4);
    goto CPyL17;
CPyL22: ;
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_chksum);
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r11);
    goto CPyL17;
CPyL23: ;
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_chksum);
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r7);
    goto CPyL17;
CPyL24: ;
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_chksum);
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r15);
    goto CPyL17;
CPyL25: ;
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_chksum);
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r19);
    goto CPyL17;
CPyL26: ;
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_chksum);
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r22);
    goto CPyL17;
CPyL27: ;
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_chksum);
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r28);
    goto CPyL17;
CPyL28: ;
    CPyTagged_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r4);
    goto CPyL17;
CPyL29: ;
    CPyTagged_DecRef(cpy_r_chksum);
    goto CPyL17;
}

PyObject *CPyPy_calc_checksum(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"filesystem", 0};
    static CPyArg_Parser parser = {"O:calc_checksum", kwlist, 0};
    PyObject *obj_filesystem;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_filesystem)) {
        return NULL;
    }
    PyObject *arg_filesystem = obj_filesystem;
    PyObject *retval = CPyDef_calc_checksum(arg_filesystem);
    return retval;
fail: ;
    CPy_AddTraceback("comp9.py", "calc_checksum", 47, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_run(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject **cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject **cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject **cpy_r_r46;
    PyObject *cpy_r_r47;
    tuple_T3OOO cpy_r_r48;
    tuple_T3OOO cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    int32_t cpy_r_r56;
    char cpy_r_r57;
    char cpy_r_r58;
    char cpy_r_r59;
    tuple_T3OOO cpy_r_r60;
    tuple_T3OOO cpy_r_r61;
    tuple_T3OOO cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject **cpy_r_r65;
    PyObject *cpy_r_r66;
    char cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    cpy_r_r0 = CPyStatics[14]; /* 'input9.txt' */
    cpy_r_r1 = CPyModule_builtins;
    cpy_r_r2 = CPyStatics[15]; /* 'open' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 57, CPyStatic_globals);
        goto CPyL42;
    }
    PyObject *cpy_r_r4[1] = {cpy_r_r0};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 1, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 57, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r7 = PyObject_Type(cpy_r_r6);
    cpy_r_r8 = CPyStatics[16]; /* '__exit__' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 57, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r10 = CPyStatics[17]; /* '__enter__' */
    cpy_r_r11 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r10);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 57, CPyStatic_globals);
        goto CPyL44;
    }
    PyObject *cpy_r_r12[1] = {cpy_r_r6};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = _PyObject_Vectorcall(cpy_r_r11, cpy_r_r13, 1, 0);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 57, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r15 = 1;
    cpy_r_r16 = CPyStatic_globals;
    cpy_r_r17 = CPyStatics[18]; /* 'time_ns' */
    cpy_r_r18 = CPyDict_GetItem(cpy_r_r16, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 58, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r19 = _PyObject_Vectorcall(cpy_r_r18, 0, 0, 0);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 58, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r20 = CPyStatics[19]; /* 'read' */
    PyObject *cpy_r_r21[1] = {cpy_r_r14};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = PyObject_VectorcallMethod(cpy_r_r20, cpy_r_r22, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 59, CPyStatic_globals);
        goto CPyL46;
    }
    CPy_DECREF(cpy_r_r14);
    cpy_r_r24 = CPyStatics[20]; /* 'strip' */
    PyObject *cpy_r_r25[1] = {cpy_r_r23};
    cpy_r_r26 = (PyObject **)&cpy_r_r25;
    cpy_r_r27 = PyObject_VectorcallMethod(cpy_r_r24, cpy_r_r26, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 59, CPyStatic_globals);
        goto CPyL47;
    }
    CPy_DECREF(cpy_r_r23);
    if (likely(PyUnicode_Check(cpy_r_r27)))
        cpy_r_r28 = cpy_r_r27;
    else {
        CPy_TypeErrorTraceback("comp9.py", "run", 59, CPyStatic_globals, "str", cpy_r_r27);
        goto CPyL48;
    }
    cpy_r_r29 = CPyDef_compact_files(cpy_r_r28);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 59, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r30 = CPyDef_calc_checksum(cpy_r_r29);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 59, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r31 = CPyModule_builtins;
    cpy_r_r32 = CPyStatics[21]; /* 'print' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_r31, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 59, CPyStatic_globals);
        goto CPyL49;
    }
    PyObject *cpy_r_r34[1] = {cpy_r_r30};
    cpy_r_r35 = (PyObject **)&cpy_r_r34;
    cpy_r_r36 = _PyObject_Vectorcall(cpy_r_r33, cpy_r_r35, 1, 0);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 59, CPyStatic_globals);
        goto CPyL49;
    } else
        goto CPyL50;
CPyL15: ;
    CPy_DECREF(cpy_r_r30);
    cpy_r_r37 = CPyStatic_globals;
    cpy_r_r38 = CPyStatics[18]; /* 'time_ns' */
    cpy_r_r39 = CPyDict_GetItem(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 60, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r40 = _PyObject_Vectorcall(cpy_r_r39, 0, 0, 0);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 60, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r41 = PyNumber_Subtract(cpy_r_r40, cpy_r_r19);
    CPy_DECREF(cpy_r_r40);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 60, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r42 = CPyModule_builtins;
    cpy_r_r43 = CPyStatics[21]; /* 'print' */
    cpy_r_r44 = CPyObject_GetAttr(cpy_r_r42, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 60, CPyStatic_globals);
        goto CPyL51;
    }
    PyObject *cpy_r_r45[1] = {cpy_r_r41};
    cpy_r_r46 = (PyObject **)&cpy_r_r45;
    cpy_r_r47 = _PyObject_Vectorcall(cpy_r_r44, cpy_r_r46, 1, 0);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 60, CPyStatic_globals);
        goto CPyL51;
    } else
        goto CPyL52;
CPyL20: ;
    CPy_DECREF(cpy_r_r41);
    goto CPyL29;
CPyL21: ;
    cpy_r_r48 = CPy_CatchError();
    cpy_r_r15 = 0;
    cpy_r_r49 = CPy_GetExcInfo();
    cpy_r_r50 = cpy_r_r49.f0;
    CPy_INCREF(cpy_r_r50);
    cpy_r_r51 = cpy_r_r49.f1;
    CPy_INCREF(cpy_r_r51);
    cpy_r_r52 = cpy_r_r49.f2;
    CPy_INCREF(cpy_r_r52);
    CPy_DecRef(cpy_r_r49.f0);
    CPy_DecRef(cpy_r_r49.f1);
    CPy_DecRef(cpy_r_r49.f2);
    PyObject *cpy_r_r53[4] = {cpy_r_r6, cpy_r_r50, cpy_r_r51, cpy_r_r52};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = _PyObject_Vectorcall(cpy_r_r9, cpy_r_r54, 4, 0);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 57, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_DecRef(cpy_r_r50);
    CPy_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r52);
    cpy_r_r56 = PyObject_IsTrue(cpy_r_r55);
    CPy_DecRef(cpy_r_r55);
    cpy_r_r57 = cpy_r_r56 >= 0;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("comp9.py", "run", 57, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r58 = cpy_r_r56;
    if (cpy_r_r58) goto CPyL26;
    CPy_Reraise();
    if (!0) {
        goto CPyL27;
    } else
        goto CPyL54;
CPyL25: ;
    CPy_Unreachable();
CPyL26: ;
    CPy_RestoreExcInfo(cpy_r_r48);
    CPy_DecRef(cpy_r_r48.f0);
    CPy_DecRef(cpy_r_r48.f1);
    CPy_DecRef(cpy_r_r48.f2);
    goto CPyL29;
CPyL27: ;
    CPy_RestoreExcInfo(cpy_r_r48);
    CPy_DecRef(cpy_r_r48.f0);
    CPy_DecRef(cpy_r_r48.f1);
    CPy_DecRef(cpy_r_r48.f2);
    cpy_r_r59 = CPy_KeepPropagating();
    if (!cpy_r_r59) {
        goto CPyL30;
    } else
        goto CPyL55;
CPyL28: ;
    CPy_Unreachable();
CPyL29: ;
    tuple_T3OOO __tmp43 = { NULL, NULL, NULL };
    cpy_r_r60 = __tmp43;
    cpy_r_r61 = cpy_r_r60;
    goto CPyL31;
CPyL30: ;
    cpy_r_r62 = CPy_CatchError();
    cpy_r_r61 = cpy_r_r62;
CPyL31: ;
    if (!cpy_r_r15) goto CPyL56;
    cpy_r_r63 = (PyObject *)&_Py_NoneStruct;
    PyObject *cpy_r_r64[4] = {cpy_r_r6, cpy_r_r63, cpy_r_r63, cpy_r_r63};
    cpy_r_r65 = (PyObject **)&cpy_r_r64;
    cpy_r_r66 = _PyObject_Vectorcall(cpy_r_r9, cpy_r_r65, 4, 0);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("comp9.py", "run", 57, CPyStatic_globals);
        goto CPyL57;
    } else
        goto CPyL58;
CPyL33: ;
    CPy_DECREF(cpy_r_r6);
CPyL34: ;
    if (cpy_r_r61.f0 == NULL) goto CPyL41;
    CPy_Reraise();
    if (!0) {
        goto CPyL37;
    } else
        goto CPyL59;
CPyL36: ;
    CPy_Unreachable();
CPyL37: ;
    if (cpy_r_r61.f0 == NULL) goto CPyL39;
    CPy_RestoreExcInfo(cpy_r_r61);
    CPy_XDECREF(cpy_r_r61.f0);
    CPy_XDECREF(cpy_r_r61.f1);
    CPy_XDECREF(cpy_r_r61.f2);
CPyL39: ;
    cpy_r_r67 = CPy_KeepPropagating();
    if (!cpy_r_r67) goto CPyL42;
    CPy_Unreachable();
CPyL41: ;
    cpy_r_r68 = Py_None;
    CPy_INCREF(cpy_r_r68);
    return cpy_r_r68;
CPyL42: ;
    cpy_r_r69 = NULL;
    return cpy_r_r69;
CPyL43: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    goto CPyL42;
CPyL44: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r9);
    goto CPyL42;
CPyL45: ;
    CPy_DecRef(cpy_r_r14);
    goto CPyL21;
CPyL46: ;
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r19);
    goto CPyL21;
CPyL47: ;
    CPy_DecRef(cpy_r_r19);
    CPy_DecRef(cpy_r_r23);
    goto CPyL21;
CPyL48: ;
    CPy_DecRef(cpy_r_r19);
    goto CPyL21;
CPyL49: ;
    CPy_DecRef(cpy_r_r19);
    CPy_DecRef(cpy_r_r30);
    goto CPyL21;
CPyL50: ;
    CPy_DECREF(cpy_r_r36);
    goto CPyL15;
CPyL51: ;
    CPy_DecRef(cpy_r_r41);
    goto CPyL21;
CPyL52: ;
    CPy_DECREF(cpy_r_r47);
    goto CPyL20;
CPyL53: ;
    CPy_DecRef(cpy_r_r50);
    CPy_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r52);
    goto CPyL27;
CPyL54: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r48.f0);
    CPy_DecRef(cpy_r_r48.f1);
    CPy_DecRef(cpy_r_r48.f2);
    goto CPyL25;
CPyL55: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r9);
    goto CPyL28;
CPyL56: ;
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r9);
    goto CPyL34;
CPyL57: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL37;
CPyL58: ;
    CPy_DECREF(cpy_r_r66);
    goto CPyL33;
CPyL59: ;
    CPy_XDECREF(cpy_r_r61.f0);
    CPy_XDECREF(cpy_r_r61.f1);
    CPy_XDECREF(cpy_r_r61.f2);
    goto CPyL36;
}

PyObject *CPyPy_run(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":run", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *retval = CPyDef_run();
    return retval;
fail: ;
    CPy_AddTraceback("comp9.py", "run", 56, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    char cpy_r_r25;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[22]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("comp9.py", "<module>", -1, CPyStatic_globals);
        goto CPyL9;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[31]; /* ('bisect',) */
    cpy_r_r6 = CPyStatics[6]; /* 'bisect' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("comp9.py", "<module>", 1, CPyStatic_globals);
        goto CPyL9;
    }
    CPyModule_bisect = cpy_r_r8;
    CPy_INCREF(CPyModule_bisect);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[32]; /* ('accumulate', 'repeat', 'batched') */
    cpy_r_r10 = CPyStatics[23]; /* 'itertools' */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("comp9.py", "<module>", 2, CPyStatic_globals);
        goto CPyL9;
    }
    CPyModule_itertools = cpy_r_r12;
    CPy_INCREF(CPyModule_itertools);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[33]; /* ('mul',) */
    cpy_r_r14 = CPyStatics[24]; /* 'operator' */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("comp9.py", "<module>", 3, CPyStatic_globals);
        goto CPyL9;
    }
    CPyModule_operator = cpy_r_r16;
    CPy_INCREF(CPyModule_operator);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[34]; /* ('Iterable',) */
    cpy_r_r18 = CPyStatics[26]; /* 'typing' */
    cpy_r_r19 = CPyStatic_globals;
    cpy_r_r20 = CPyImport_ImportFromMany(cpy_r_r18, cpy_r_r17, cpy_r_r17, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("comp9.py", "<module>", 4, CPyStatic_globals);
        goto CPyL9;
    }
    CPyModule_typing = cpy_r_r20;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r21 = CPyStatics[35]; /* ('time_ns',) */
    cpy_r_r22 = CPyStatics[27]; /* 'time' */
    cpy_r_r23 = CPyStatic_globals;
    cpy_r_r24 = CPyImport_ImportFromMany(cpy_r_r22, cpy_r_r21, cpy_r_r21, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("comp9.py", "<module>", 5, CPyStatic_globals);
        goto CPyL9;
    }
    CPyModule_time = cpy_r_r24;
    CPy_INCREF(CPyModule_time);
    CPy_DECREF(cpy_r_r24);
    return 1;
CPyL9: ;
    cpy_r_r25 = 2;
    return cpy_r_r25;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_comp9 = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_bisect = Py_None;
    CPyModule_itertools = Py_None;
    CPyModule_operator = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_time = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[36];
const char * const CPyLit_Str[] = {
    "\b\003map\naccumulate\003sum\006bisect\tenumerate\005start\abatched\rGeneratorExit",
    "\b\rStopIteration\003mul\006repeat\ninput9.txt\004open\b__exit__\t__enter__\atime_ns",
    "\t\004read\005strip\005print\bbuiltins\titertools\boperator\bIterable\006typing\004time",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0021\0002",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {6, 1, 8, 1, 6, 3, 4, 13, 9, 1, 12, 1, 25, 1, 18};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_comp9_internal = NULL;
CPyModule *CPyModule_comp9;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_bisect;
CPyModule *CPyModule_itertools;
CPyModule *CPyModule_operator;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_time;
PyTypeObject *CPyType_compact_files_env;
PyObject *CPyDef_compact_files_env(void);
PyTypeObject *CPyType_compact_files_gen;
PyObject *CPyDef_compact_files_gen(void);
PyObject *CPyDef_compact_files_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy_compact_files_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_compact_files_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_compact_files_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_compact_files_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy_compact_files_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_compact_files_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_compact_files_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_compact_files_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy_compact_files_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_compact_files_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_compact_files_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_compact_files(PyObject *cpy_r_string);
PyObject *CPyPy_compact_files(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_calc_checksum(PyObject *cpy_r_filesystem);
PyObject *CPyPy_calc_checksum(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_run(void);
PyObject *CPyPy_run(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
