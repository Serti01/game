#! /bin/python

with open(".meta/depends", "r") as depends:
    lines = depends.readlines()
    
    for line in lines:
        print("-l%s" % line.replace("\n",""),end=" ")