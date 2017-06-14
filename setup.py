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
    author_email = "fdechelle@teclib.com",
    description = ("POC Python module for the Armadito antivirus"),
    license = "GPLv3",
    keywords = "antivirus",
    url = "https://github.com/armadito/armadito-mod-python",
    long_description = "POC Python module for the Armadito antivirus",
    classifiers=[
        "Development Status :: 3 - Alpha",
        "Topic :: Utilities",
        "License :: OSI Approved :: GPLv3 License",
    ],
    packages = ['armadito'],
)
