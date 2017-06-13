/***

Copyright (C) 2017 Teclib'

This file is part of Armadito module Python.

Armadito module Python is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Armadito module Python is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Armadito module python.  If not, see <http://www.gnu.org/licenses/>.

***/

#include <stdlib.h>
#include <stdarg.h>
#include <Python.h>

PyObject *py_module_import(const char *module_name)
{
	PyObject *pname, *pmodule;

	Py_Initialize();

	pname = PyUnicode_DecodeFSDefault(module_name);
	if (pname == NULL) {
		if (PyErr_Occurred())
			PyErr_Print();
		return NULL;
        }

	pmodule = PyImport_Import(pname);
	Py_DECREF(pname);

	return pmodule;
}

PyObject *py_callable_attr_get(PyObject *pmodule, const char *attr_name)
{
	PyObject *pattr;

	pattr = PyObject_GetAttrString(pmodule, attr_name);

	if (pattr == NULL || !PyCallable_Check(pattr)) {
		if (PyErr_Occurred())
			PyErr_Print();
        }
	return pattr;
}

PyObject *py_class_instantiate(PyObject *pclass)
{
	PyObject *pobj, *pargs;

	pargs = PyTuple_New(0);
	pobj = PyObject_CallObject(pclass, pargs);
	Py_DECREF(pargs);

	if (pobj == NULL)
                PyErr_Print();

	return pobj;
}

PyObject *py_obj_mth_invoke(PyObject *pmth, const char *format, ...)
{
	PyObject *pargs, *pretval;
	va_list vargs;

	va_start(vargs, format);
	pargs = Py_VaBuildValue(format, vargs);
	va_end(vargs);

	pretval = PyObject_CallObject(pmth, pargs);
	Py_DECREF(pargs);

	if (pretval == NULL)
                PyErr_Print();

	return pretval;
}

