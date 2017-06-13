#!/usr/bin/python3
# -*- coding: utf-8 -*-
#
# to combine autotools and setuptools, see:
# https://blog.kevin-brown.com/programming/2014/09/24/combining-autotools-and-setuptools.html
# Thank you!

import os
import glob
import shutil
import stat
from setuptools import setup

setup(
    name = "Armadito antivirus Python generic module",
    version = "0.10.0",
    author = "François Déchelle",
    author_email = "fdechelle@teclibzoo.com",
    description = ("POC Python module for the Armadito antivirus"),
    license = "GPLv3",
    keywords = "modudule",
    url = "https://nowhe.re",
    long_description = "POC Python module for the Armadito antivirus",
    classifiers=[
        "Development Status :: 3 - Alpha",
        "Topic :: Utilities",
        "License :: OSI Approved :: GPLv3 License",
    ],
    packages = ['armadito'],
)

#
#
# reminder: for user local installation
# ./setup.py install --user
# ./setup.py install_data --install-dir=/home/fdechelle/.local
#
#
