#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# to combine autotools and setuptools, see:
# https://blog.kevin-brown.com/programming/2014/09/24/combining-autotools-and-setuptools.html
# Thank you!

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
    packages = ['armadito', 'aespython', 'jsbeautifier', ''],
    package_dir = {'armadito':'python/armadito', 'aespython':'python/peepdf/aespython', 'jsbeautifier':'python/peepdf/jsbeautifier', '':'python/peepdf'}
)
