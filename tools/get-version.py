import sys

space = True

try:
    if (sys.argv[1] == "nospace"):
        space = not space
except:
    pass

with open(".meta/version","r") as ver:
    print("Game%s%s" % ((" " if space else ""), ver.read()), end="")