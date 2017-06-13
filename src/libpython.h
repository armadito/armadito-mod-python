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

#ifndef ARMADITO_LIBPYTHON_H
#define ARMADITO_LIBPYTHON_H

#include <Python.h>

PyObject *py_module_import(const char *module_name);

PyObject *py_callable_attr_get(PyObject *pmodule, const char *attr_name);

PyObject *py_class_instantiate(PyObject *pclass);

PyObject *py_obj_mth_invoke(PyObject *pmth, const char *format, ...);

#endif
