#!/usr/bin/env python
# -*- coding: utf-8 -*-
import pyseqan

score, alignment = pyseqan.align("banana", "ananas")

print "Score:", score
print "Alignment:"
print alignment