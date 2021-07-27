import sys

space = True
caps = True

try:
    for i in range(len(sys.argv) - 1):
        if (sys.argv[i+1] == "nospace"):
            space = not space
        if (sys.argv[i+1] == "nocaps"):
            caps = not caps
except:
    pass

with open(".meta/version","r") as ver:
    print("%s%s%s" % (("Game" if caps else "game"), (" " if space else ""), ver.read()), end="")