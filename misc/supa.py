import sys
from itertools import permutations
from tkinter import *

def main():
	print(sys.argv)
	if(len(sys.argv) != 2):
		print("usage: supa.py [0-5]")
		exit(1);
	if(int(sys.argv[1]) > 15):
		print("would take too long, pick n < 5");
		exit(1);
		
	i = int(sys.argv[1])
	print("superpermutation:" + str(i))
	
	# create permutations and substrings
	perms = [list(p) for p in permutations(range(1, i+1))]
	substrings = [[x[:-1]] for x in perms]
	print ("substrings:", perms)
	print ("substrings:", substrings)
	
	for s in substrings:
		for p in perms:
			if s[0] == p[1:] or s[0] == p[:-1]:
				s.append(perms.index(p) + 1)
				
	for row in substrings:
		print (row[0], ":", row[1:])
		
	# create window
	master = Tk()
	w = Canvas(master, width=600, height=600)
	w.pack()
	w.create_line(0, 100, 200, 0, fill="red", dash=(4, 4))
	mainloop()

	
if __name__ == "__main__":
	main()