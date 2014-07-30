/*
 * python interface to soundtouch (the open-source audio processing library)
 */

#ifndef __PY_SOUNDTOUCH_H__
#define __PY_SOUNDTOUCH_H__

#include <Python.h>
#include <BPMDetect.h>

#define BUFFER_SIZE 44100

typedef struct {
  PyObject_HEAD
  soundtouch::BPMDetect* bpmdetect;
  int channels; // 1 or 2
  union {
    char chars[BUFFER_SIZE];
    short shorts[BUFFER_SIZE/2];
  } buffer;
} py_bpmdetect; /* Soundtouch */

#define PY_BPMDETECT(x) ((py_bpmdetect *) x)

extern PyTypeObject py_bpmdetect_t;

static void py_bpmdetect_dealloc(PyObject* self, PyObject* args);
static PyObject* py_bpmdetect_put_samples(PyObject* self, PyObject* args);
static PyObject* py_bpmdetect_get_bpm(PyObject* self, PyObject* args);
static PyObject* py_bpmdetect_getattr(PyObject* self, char* name);

#endif
