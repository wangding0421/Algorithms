import sys

if len(sys.argv) < 4:
    print "Please provide the 3 file names (synonyms, file1, file2)!"
    exit()

f_synonym = sys.argv[1]
f_file_1 = sys.argv[2]
f_file_2 = sys.argv[3]
kNTuple = 3 if len(sys.argv) == 4 else sys.argv[4]

with open(f_synonym) as f:
    l_synonym = map(lambda x: map(str, x.split()), f.readlines())


