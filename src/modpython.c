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

#include <libarmadito/armadito.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Python.h>

#include "libpython.h"

struct python_data {
	const char *module_name;
	const char *class_name;
	PyObject *pmth_scan;
};

static enum a6o_mod_status python_init(struct a6o_module *module)
{
	struct python_data *py_data;

	Py_Initialize();

	py_data = calloc(1, sizeof(struct python_data));
	module->data = py_data;

	return A6O_MOD_OK;
}

static enum a6o_mod_status python_conf_set_python_module(struct a6o_module *module, const char *key, struct a6o_conf_value *value)
{
	struct python_data *py_data = (struct python_data *)module->data;

	py_data->module_name = strdup(a6o_conf_value_get_string(value));

	return A6O_MOD_OK;
}

static enum a6o_mod_status python_conf_set_python_class(struct a6o_module *module, const char *key, struct a6o_conf_value *value)
{
	struct python_data *py_data = (struct python_data *)module->data;

	py_data->class_name = strdup(a6o_conf_value_get_string(value));

	return A6O_MOD_OK;
}

static enum a6o_mod_status python_post_init(struct a6o_module *module)
{
	struct python_data *py_data = (struct python_data *)module->data;
	PyObject *pmodule, *pclass, *pobj, *pmth, *pval;

	pmodule = py_module_import(py_data->module_name);
	if (pmodule == NULL) {
		a6o_log(A6O_LOG_MODULE, A6O_LOG_LEVEL_WARNING, "cannot import Python module %s", py_data->module_name);
		return A6O_MOD_INIT_ERROR;
	}

	pclass = py_callable_attr_get(pmodule, py_data->class_name);
	if (pclass == NULL) {
		a6o_log(A6O_LOG_MODULE, A6O_LOG_LEVEL_WARNING, "cannot find Python class %s", py_data->class_name);
		return A6O_MOD_INIT_ERROR;
	}

	pobj = py_class_instantiate(pclass);
	if (pobj == NULL) {
		a6o_log(A6O_LOG_MODULE, A6O_LOG_LEVEL_WARNING, "cannot instantiate Python class %s", py_data->class_name);
		return A6O_MOD_INIT_ERROR;
	}

	py_data->pmth_scan = py_callable_attr_get(pobj, "scan");
	if (py_data->pmth_scan == NULL) {
		a6o_log(A6O_LOG_MODULE, A6O_LOG_LEVEL_WARNING, "cannot find Python method \"scan\"");
		return A6O_MOD_INIT_ERROR;
	}

	a6o_log(A6O_LOG_MODULE, A6O_LOG_LEVEL_INFO, "Python is initialized");

	return A6O_MOD_OK;
}

static int decode_retval(PyObject *pval, enum a6o_file_status *p_status, const char **pmod_report)
{
	if (pval == NULL
		|| !PyTuple_CheckExact(pval)
		|| PyTuple_Size(pval) != 2
		|| !PyLong_Check(PyTuple_GetItem(pval, 0))
		|| !PyUnicode_Check(PyTuple_GetItem(pval, 1)))
		return 1;

	*p_status = (enum a6o_file_status)PyLong_AsLong(PyTuple_GetItem(pval, 0));
	*pmod_report = strdup(PyUnicode_AsUTF8(PyTuple_GetItem(pval, 1)));

	return 0;
}

static enum a6o_file_status python_scan(struct a6o_module *module, int fd, const char *path, const char *mime_type, char **pmod_report)
{
	struct python_data *py_data = (struct python_data *)module->data;
	PyObject *pretval;
	enum a6o_file_status ret_status;

	pretval = py_obj_mth_invoke(py_data->pmth_scan, "iss", fd, path, mime_type);
	if (decode_retval)
		return A6O_FILE_EINVAL;

	return ret_status;
}

static enum a6o_mod_status python_close(struct a6o_module *module)
{
	return A6O_MOD_OK;
}

static struct a6o_conf_entry python_conf_table[] = {
	{ "python_module", CONF_TYPE_STRING, python_conf_set_python_module},
	{ "python_class", CONF_TYPE_STRING, python_conf_set_python_class},
	{ NULL, CONF_TYPE_VOID, NULL},
};

static const char *python_mime_types[] = { "*", NULL, };

struct a6o_module module = {
	.init_fun = python_init,
	.conf_table = python_conf_table,
	.post_init_fun = python_post_init,
	.scan_fun = python_scan,
	.close_fun = python_close,
	.info_fun = NULL,
	.supported_mime_types = python_mime_types,
	.name = "python",
	.size = sizeof(struct python_data),
};
